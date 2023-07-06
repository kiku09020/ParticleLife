#pragma once
#include"GameObjects/Base/GameObject.h"
#include "Renderer/Renderers/Renderer2D.h"

// 画面のフィールド
class Field : public GameObject
{
private:
	const float width = 500;
	const float height = 500;

	ImageRenderer* renderer;

public:
	Field(Camera*);

	void Init() override;
	void Update() override;

};
