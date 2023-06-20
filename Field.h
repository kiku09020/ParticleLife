#pragma once
#include"GameObject.h"

// 画面のフィールド
class Field : public GameObject
{
private:
	const float width = 500;
	const float height = 500;

protected:
	void Draw() override;

public:
	Field(VECTOR);
	Field(VECTOR, float,float);

	void Init() override;
	void Update() override;

};
