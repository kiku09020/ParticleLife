#pragma once
#include"GameObject.h"
#include "Renderer.h"

// 画面のフィールド
class Field : public GameObject
{
private:
	const float width = 500;
	const float height = 500;

	Renderer2D* renderer;

public:
	Field();

	void Init() override;
	void Update() override;

};
