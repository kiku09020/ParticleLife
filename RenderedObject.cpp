#include "RendereredObject.h"

IRenderedObject2D::IRenderedObject2D(float ppu)
{
	pixelsPerUnit = ppu;

	AddVertices();
}

void IRenderedObject2D::Drawn(Camera* camera, GameObject* gameObject)
{
	SetVertices();
	SetMatrixedVertices(camera, gameObject);

	RenderedObject::Drawn(camera, gameObject);
}

void IRenderedObject2D::SetGraphSize(VECTOR size, Camera* camera)
{
	graphicSize.x = size.x * pixelsPerUnit + camera->transform.position.z;
	graphicSize.y = size.y * pixelsPerUnit + camera->transform.position.z;
}

void IRenderedObject2D::AddVertices()
{
	vertices.push_back(VGet(graphicSize.x, graphicSize.y, 0));
	vertices.push_back(VGet(-graphicSize.x, graphicSize.y, 0));
	vertices.push_back(VGet(-graphicSize.x, -graphicSize.y, 0));
	vertices.push_back(VGet(graphicSize.x, -graphicSize.y, 0));
}

void IRenderedObject2D::SetVertices()
{
	vertices[0] = VGet(graphicSize.x, graphicSize.y, 0);
	vertices[1] = VGet(-graphicSize.x, graphicSize.y, 0);
	vertices[2] = VGet(-graphicSize.x, -graphicSize.y, 0);
	vertices[3] = VGet(graphicSize.x, -graphicSize.y, 0);
}

void IRenderedObject2D::SetMatrixedVertices(Camera* camera, GameObject* gameObject)
{
	// ‰ñ“]s—ñ
	MATRIX matrix = MGetRotAxis(VGet(0, 0, 1), gameObject->transform.rotation.z);

	for (int i = 0; i < vertices.size(); i++) {
		vertices[i] = VTransform(vertices[i], matrix);
	}

	// ’†SÀ•W‚ÉˆÚ“®
	VECTOR center = VAdd(camera->transform.position, gameObject->transform.position);

	for (int i = 0; i < vertices.size(); i++) {
		vertices[i] = VAdd(vertices[i], center);
	}
}