#pragma once
#include "DxLib.h"

#include "Camera.h"

#include <type_traits>
#include <vector>

#include "RendereredObject.h"

class ShapeBase:RenderedObject {
protected:
	int color;

};

// 平面図形基底クラス
class Shape2D:public ShapeBase,public IRenderedObject2D
{
protected:
	bool isFilled;						// 内側満たすか
	float lineThickness = 1.0f;			// 外枠の太さ

public:
	// コンストラクタ
	Shape2D(int, bool, float, float);

	virtual void Drawn(Camera*, GameObject*) override;
};

class Shape3D :public ShapeBase, public IRenderedObject3D {

};

//--------------------------------------------------

// 円
class CircleShape : public Shape2D
{
private:
	int pointCount;			// 円の頂点の数

public:
	// コンストラクタ
	CircleShape(int ptCount = 32, int color = Color::White(), bool isFilled = true, float thickness = 1)
		: Shape2D(color, isFilled, thickness,4), pointCount(ptCount){}

	void Drawn(Camera*, GameObject*) override;
};

// 矩形
class RectangleShape : public Shape2D
{
public:
	// コンストラクタ
	RectangleShape(int color = Color::White(), bool isFilled = true, float thickness = 1)
		:Shape2D(color, isFilled, thickness,4){}

	void Drawn(Camera*, GameObject*) override;
};

// 三角形
class TriangleShape :public Shape2D
{
public:
	TriangleShape(int color = Color::White(), bool isFilled = true, float thickness = 1)
		:Shape2D(color, isFilled, thickness,4){}

	void Drawn(Camera*, GameObject*) override;
};