#include "GameScenes.h"

using namespace Input;

MainScene::MainScene()
{
	camera = new Camera();
	field = new Field(camera);

	camera->Init();
	field->Init();
}

void MainScene::OnSceneLoaded()
{

}

void MainScene::OnSceneUpdate()
{
	camera->Update();
	field->Update();

	DrawString(0, 0, "main", Color::Black());

	VECTOR mousePos = Mouse::GetMousePosition();

	if (Mouse::GetMouseButton(MOUSE_INPUT_LEFT)) {
		DrawCircleAA(mousePos.x, mousePos.y, 10, 32, Color::White());
	}

	DrawCircleAA(mousePos.x, mousePos.y, 5, 32, Color::White());

	if (Keyboard::GetKeyDown(KEY_INPUT_ESCAPE)) {
		OnSceneDestroied();
	}

	DrawFormatString(0, 100, GetColor(0, 0, 0), "%.3f", camera->transform.position.z);
}

void MainScene::OnSceneDestroied()
{
	delete camera;
	delete field;

	DxLib_End();
}