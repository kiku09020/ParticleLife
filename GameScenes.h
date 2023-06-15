#pragma once
#include "SceneController.h"
#include "DxLib.h"
#include "Input.h"
#include "Color.h"

class MainScene : public GameSceneBase
{
private:


public:
	void OnSceneLoaded() override;
	void OnSceneUpdate() override;
	void OnSceneDestroied() override;
};