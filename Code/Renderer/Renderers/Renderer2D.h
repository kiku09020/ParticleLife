#pragma once

#include "Renderer.h"

// 2D�����_���[

template <typename T>
concept RendObj2D = std::is_base_of<IRenderedObject2D, T>::value;

template<RendObj2D T>
class Renderer2D :public Renderer {
protected:			
	T* renderedObj;

	//--------------------------------------------------
	Renderer2D(Camera* camera, GameObject* gameObject, T* renderedObj)
		:Renderer(camera,gameObject)

	{
		this->renderedObj = renderedObj;
	}

public:
	void Draw() override { renderedObj->Drawn(camera,gameObject); }
};

// �摜�`��p�����_���[
class ImageRenderer : public Renderer2D<Image>{
public:
	ImageRenderer(Camera* camera, GameObject* gameObject, Image* image) :
		Renderer2D<Image>(camera, gameObject, image) {}
};

// ���ʐ}�`�`��p�����_���[
class ShapeRednerer2D :public Renderer2D<Shape2D>{
public:
	ShapeRednerer2D(Camera* camera, GameObject* gameObject, Shape2D* shape) :
		Renderer2D<Shape2D>(camera, gameObject, shape) {}
};