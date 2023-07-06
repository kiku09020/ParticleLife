#pragma once

#include "Camera.h"
#include <vector>

class RenderedObject {
protected:
	// 各オブジェクトの描画処理本体
	virtual void DrawingProcess(Camera*camera,GameObject* gameObject) = 0;

public:
	// 描画準備 + 描画処理
	virtual void Drawn(Camera* camera, GameObject* gameObject) 
	{
		DrawingProcess(camera, gameObject);
	};
};

// 2D描画されるオブジェクトインターフェースクラス
class IRenderedObject2D:public RenderedObject
{
protected:
	float pixelsPerUnit = 1;			// 描画サイズ。(Unityのフィールド名パクっただけ。
	VECTOR graphicSize;					// 描画されるサイズ
	std::vector<VECTOR> vertices;		// 頂点リスト

	//--------------------------------------------------

	IRenderedObject2D(float ppu);

	// グラフサイズ指定
	virtual void SetGraphSize(VECTOR, Camera*);

	// 頂点追加
	virtual void AddVertices();

	// 頂点位置の更新
	virtual void SetVertices();

	// 行列を考慮した頂点座標を取得する
	void SetMatrixedVertices(Camera*, GameObject*);

	virtual void Drawn(Camera*, GameObject*) override;

	//--------------------------------------------------
	/* setter */
	// pixelPerUnitの変更
	void SetPPU(float ppu) { pixelsPerUnit = ppu; }
};

// 3D描画されるオブジェクトインターフェースクラス
class IRenderedObject3D:public RenderedObject
{

};