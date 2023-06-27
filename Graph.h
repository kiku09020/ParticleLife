#pragma once
#include "DxLib.h"

#include "Camera.h"

#include <type_traits>
#include <vector>

// 図形基底クラス
class Graph
{
protected:
	int color;							// 色
	bool isFilled;						// 内側満たすか
	float lineThickness = 1.0f;			// 外枠の太さ

	static const inline float graphRenderSize = 32.0f;		// 図形共通の描画サイズ

public:
	// コンストラクタ
	Graph(int color = Color::White(), bool isFilled = true, float thickness = 1)
		:color(color), isFilled(isFilled), lineThickness(thickness){}

	virtual void Draw(Camera*, GameObject*) = 0;
};

class IRotatable
{
protected:
	#define VECTOR_X = VGet(1, 0, 0)
	#define VECTOR_Y = VGet(0, 1, 0)
	#define VECTOR_Z = VGet(0, 0, 1)

	// 行列を考慮した頂点座標を取得する
	void GetMatrixedVertices(VECTOR axis, float rotate, std::vector<VECTOR>* vertices, Camera* camera, GameObject* gameObject);

	void GetMatrixedVertices(std::vector<VECTOR>*, Camera*, GameObject*);
};

//--------------------------------------------------

// 円
class CircleGraph : public Graph
{
private:
	int pointCount;			// 円の頂点の数

public:
	// コンストラクタ
	CircleGraph(int ptCount = 32, int color = Color::White(), bool isFilled = true, float thickness = 1)
		: Graph(color, isFilled, thickness), pointCount(ptCount){}

	void Draw(Camera*, GameObject*) override;
};

// 矩形
class RectangleGraph : public Graph, IRotatable
{
public:
	// コンストラクタ
	RectangleGraph(int color = Color::White(), bool isFilled = true, float thickness = 1)
		:Graph(color, isFilled, thickness){}

	void Draw(Camera*, GameObject*) override;
};

// 三角形
class TriangleGraph :public Graph
{
public:
	TriangleGraph(int color = Color::White(), bool isFilled = true, float thickness = 1)
		:Graph(color, isFilled, thickness){}

	void Draw(Camera*, GameObject*) override;
};