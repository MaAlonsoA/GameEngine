#include "Game.h"
#include "Ball.h"

void Game::update()
{
	for (auto& elem : scenes)
		elem->update();
	checkCollision();
	if (std::dynamic_pointer_cast<Ball>(scenes.at(0)->getEntities().at(0))->getPosition().y == 0) {
		std::dynamic_pointer_cast<Ball>(scenes.at(0)->getEntities().at(0))->setPosition(glm::vec2(300.0f, 70.0f));
		std::dynamic_pointer_cast<Ball>(scenes.at(0)->getEntities().at(0))->setVelocity(1, 1);
		player->livesMinus();
	}
}


void Game::processImput(GLFWwindow* window)
{
	if (status == GameStatus::GAME_ACTIVE)
	{
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			if (player->getPosition().x >= 0.0f)
				player->setPositionX(-player->getVelocity());
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			if (player->getPosition().x <= 650.0f)
				player->setPositionX(player->getVelocity());
		}
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
			player->setLives(-1);
		}
	}
}


void Game::setPlayer(std::shared_ptr<Player> p)
{
	player = p;
}

std::shared_ptr<Player> Game::getPlayer() const
{
	return player;
}

void Game::checkCollision()
{
	bool x{ false };
	bool y{ false };
	float dirX{ 0 };
	float dirY{ 0 };
	std::shared_ptr<Ball>auxBall{ std::dynamic_pointer_cast<Ball>(scenes.at(0)->getEntities().at(0)) };
	for (int i{ 1 }; i < scenes.at(0)->getEntities().size(); i++) {
		std::shared_ptr<GameObject> auxObject{ scenes.at(0)->getEntities().at(i) };

		if (auxBall->getPosition().x + auxBall->getSize().x >= auxObject->getPosition().x
			&& auxObject->getPosition().x + auxObject->getSize().x >= auxBall->getPosition().x + auxBall->getSize().x) {
			 x = true ;

			 float center{ (auxObject->getPosition().x) + (auxObject->getSize().x /2.0f) };
			 float ballPos{ auxBall->getPosition().x };
			 if (ballPos <= center )
				 dirX = DIR_LEFT;
			 else dirX = DIR_RIGTH;
		}
		else {
			 x = false;
		}

		if (auxBall->getVelocity().y == -1) {
			if (auxBall->getPosition().y + auxBall->getSize().y >= auxObject->getPosition().y && x
				&& auxObject->getPosition().y + auxObject->getSize().y >= auxBall->getPosition().y) {
				y = true;
				if (auxBall->getPosition().y + auxBall->getSize().y <= (auxObject->getPosition().y + (auxObject->getSize().y / 2.0f)))
					dirY = DIR_DOWN;
				else dirY = DIR_UP;
			}
			else {
				y = false;
			}
		}
		else if (auxBall->getVelocity().y == 1) {
			if (auxBall->getPosition().y + auxBall->getSize().y == (auxObject->getPosition().y - auxObject->getSize().y /2) && x
				&& auxObject->getPosition().y + auxObject->getSize().y >= auxBall->getPosition().y) {
				y = true;
				dirY = DIR_DOWN;
			}
			else y = false;
		
		}
		if ((x && y) && !auxObject->isSolid() && auxObject->getExist()) {
			auxObject->setExist(false);
			auxBall->setVelocity(dirX, dirY);
		}
		else if ((x && y) && auxObject->isSolid()) {
			auxBall->setVelocity(dirX, dirY);
		}
	}
}

void Game::pushScene(std::shared_ptr<Scene> scene)
{
	scenes.push_back(scene);
}

std::vector<std::shared_ptr<Scene>> Game::getScenes()
{
	return scenes;
}

Game::Game() {
	status = GameStatus::GAME_ACTIVE;
}

Game::~Game()
{

}


