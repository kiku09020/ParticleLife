#pragma once
#include "DxLib.h"
#include "Color.h"

class Transform
{
public:
	VECTOR position;
	VECTOR rotation;
	VECTOR scale = VGet(1, 1, 1);
};

class GameObject
{
private:
	bool activate = true;

protected:
	// 描画処理
	virtual void Draw() = 0;

public:
	Transform transform;

	GameObject(VECTOR);

	//--------------------------------------------------
	// 初期化
	virtual void Init() = 0;

	// 更新処理
	virtual void Update() = 0;

	//--------------------------------------------------

	// オブジェクトのアクティブ化
	void SetActive(bool);
};
