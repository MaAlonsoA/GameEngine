#include "Component.h"

void Component::setFather(std::weak_ptr<GameObject> father)
{
	father = father;
}
