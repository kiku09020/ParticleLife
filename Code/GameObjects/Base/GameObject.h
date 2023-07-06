#pragma once
#include "DxLib.h"
#include "Extensions/Color.h"

class Transform
{
public:
	// コンストラクタ
	Transform(VECTOR pos, VECTOR rot, VECTOR scl) :position(pos), rotation(rot), scale(scl) {}

	VECTOR position = VGet(0, 0, 0);
	VECTOR rotation = VGet(0, 0, 0);
	VECTOR scale	= VGet(1, 1, 1);
};

class GameObject
{
private:
	bool activate = true;

public:
	Transform transform;

	// コンストラクタ
	GameObject(Transform tf) :transform(tf) {}

	//--------------------------------------------------
	// 初期化
	virtual void Init() = 0;

	// 更新処理
	virtual void Update() = 0;

	//--------------------------------------------------

	// オブジェクトのアクティブ化
	void SetActive(bool);
};
