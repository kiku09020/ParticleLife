#pragma once
#include "SceneController.h"
#include "DxLib.h"
#include "Input.h"
#include "Color.h"

#include "Field.h"

class MainScene : public GameSceneBase
{
private:
	Field* field;

public:
	void OnSceneLoaded() override;
	void OnSceneUpdate() override;
	void OnSceneDestroied() override;
};