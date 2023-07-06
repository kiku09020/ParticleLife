#include "Field.h"

Field::Field(Camera* camera) :GameObject(transform)
{
	transform.position.x = 960 / 2;
	transform.position.y = 540 / 2;

	transform.scale = VGet(1, 1, 1);

	renderer = new ImageRenderer(camera, this, new Image("GameObject/Templates/Dark UI/32.png"));
}

void Field::Init()
{

}

void Field::Update()
{
	renderer->Draw();

	transform.rotation.z += 0.01f;
}