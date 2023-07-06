#pragma once
#include"Renderer.h"
#include "RenderedGraphic.h"

template<class T>
concept RenderedObj3D = std::is_base_of<IRenderedObject3D, T>::value;

// 3D�����_���[

template<RenderedObj3D T>
class Renderer3D : public Renderer {
protected:
	T* renderedObj;

	Renderer3D(Camera* camera, GameObject* gameObject, T* renderedObj)
		:Renderer(camera, gameObject)
	{
		this->renderedObj = renderedObj;
	}

	void Draw() override{}
};

// ���f���`��p�����_���[
class ModelRenderer : public Renderer3D<Model>{
public:
	ModelRenderer(Camera* camera, GameObject* gameObject, Model* model) :
		Renderer3D<Model>(camera, gameObject,model) { }
};

// ���̐}�`�`��p�����_���[
class ShapeRenderer3D :public Renderer3D<Shape3D> {
public:
	ShapeRenderer3D(Camera* camera,GameObject* gameObject,Shape3D* shape):
		Renderer3D<Shape3D>(camera, gameObject,shape) { }
};