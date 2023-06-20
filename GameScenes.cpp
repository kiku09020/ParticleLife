#include "GameScenes.h"

using namespace Input;

void MainScene::OnSceneLoaded()
{
	field = new Field(VGet(0, 0, 0));

	field->Init();
}

void MainScene::OnSceneUpdate()
{
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
}

void MainScene::OnSceneDestroied()
{
	DxLib_End();
}