#include "Field.h"

Field::Field(VECTOR position) :GameObject(position)
{
	transform.position = position;
}

void Field::Init()
{

}

void Field::Update()
{
	Draw();
}

void Field::Draw()
{
	float x1 = transform.position.x - (width / 2);
	float x2 = transform.position.x + (width / 2);

	float y1 = transform.position.y - (height / 2);
	float y2 = transform.position.y + (height / 2);
	

	DrawBoxAA(x1, y1, x2, y2, Color::White(), true);
}