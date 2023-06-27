#pragma once
#include "GameObject.h"

class Camera : public GameObject
{
private:
	float zoomDistance = 3.0f;			// ズーム距離
	const float zoomableMin = -30;		// ズームアウトできる最小値
	const float zoomableMax = 30;		// ズームインできる最大値
	
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
