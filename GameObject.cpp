#include "GameObject.h"

GameObject::GameObject(VECTOR position)
{
	this->transform.position = position;
}

void GameObject::Init()
{

}

void GameObject::Update()
{
	
}

void GameObject::Draw()
{

}

//--------------------------------------------------

void GameObject::SetActive(bool activate)
{
	this->activate = activate;
}