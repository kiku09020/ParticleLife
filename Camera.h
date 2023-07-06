#pragma once
#include "GameObject.h"

class Camera : public GameObject
{
private:
	const float zoomableRegion = 100;
	float zoomDistance = zoomableRegion / 7.5f;			// ズーム距離
	
	// ズーム
	void Zoom();

	// 移動
	void Move();

public:
	// コンストラクタ
	Camera();

	// 指定されたズーム量に応じてズーム
	void Zoom(int zoomDistance);

	void Init() override;
	void Update() override;
};
