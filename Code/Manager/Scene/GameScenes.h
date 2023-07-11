#pragma once
#include "SceneController.h"
#include "DxLib.h"
#include "Input/Input.h"
#include "Extensions/Color.h"

#include "GameObjects/MainScene/Field.h"

class MainScene : public GameSceneBase
{
private:
	Camera* camera;
	Field* field;


public:
	// �R���X�g���N�^
	MainScene();

	void OnSceneLoaded() override;
	void OnSceneUpdate() override;
	void OnSceneDestroied() override;
};