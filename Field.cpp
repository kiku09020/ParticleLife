#include "Field.h"

Field::Field() :GameObject(transform)
{
	transform.position.x = 960 / 2;
	transform.position.y = 540 / 2;

	transform.scale = VGet(1, 1, 1);

	renderer = new Renderer2D(this, "Templates/Dark UI/32.png");
}

void Field::Init()
{

}

void Field::Update()
{
	renderer->Draw();
}