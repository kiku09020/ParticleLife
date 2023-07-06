#pragma once
#include <string>

#include "Camera.h"
#include "RenderedShape.h"
#include "RenderedGraphic.h"

// レンダラー基底クラス
class Renderer
{
protected:
	Renderer(Camera* camera, GameObject* gameObject) :
		camera(camera), gameObject(gameObject){}

	Camera* camera;
	GameObject* gameObject;

public:
	// 描画
	virtual void Draw() = 0;
};

//--------------------------------------------------
///* Concepts */
//template <typename T>
//concept GraphicData = std::is_base_of<GraphicDataBase, T>::value;
//template <typename T>
//concept Shape = std::is_base_of<ShapeBase, T>::value;
//
//template<typename T>
//concept Renderer_ = std::is_base_of<Renderer, T>::value;
//
////--------------------------------------------------
//
//// グラフィックデータ描画用レンダラー
//template <GraphicData Data,Renderer_ Rend>
//class BasedFileDataRenderer : public Rend {
//protected:
//	Data* data;
//
//	BasedFileDataRenderer(Camera* camera,GameObject* gameObject):
//		Rend(camera,gameObject) {}
//
//public:
//	virtual void Draw() override { data->Drawn(Rend::camera, Rend::gameObject); }
//};
//
//
//// 図形描画用レンダラー
//template<Shape Shape,Renderer_ Rend>
//class BasedShapeRenderer :public Rend
//{
//protected:
//	Shape* shape;
//
//	BasedShapeRenderer(Camera* camera, GameObject* gameObject) :
//		Rend(camera, gameObject) {}
//
//public:
//	virtual void Draw() override { shape->Drawn(Rend::camera, Rend::gameObject); }
//};

//--------------------------------------------------