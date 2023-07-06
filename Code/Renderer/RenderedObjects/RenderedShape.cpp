#include "RenderedShape.h"

Shape2D::Shape2D(int color = Color::White(), bool isFilled = true, float thickness = 1,float size = 4)
	:isFilled(isFilled), lineThickness(thickness)
	, IRenderedObject2D(size)
{
	this->color = color;
}

void Shape2D::Drawn(Camera* camera,GameObject* gameObject)
{
	SetGraphSize(gameObject->transform.scale, camera);
	SetVertices();
	SetMatrixedVertices(camera, gameObject);


}

//--------------------------------------------------

void CircleShape::Drawn(Camera* camera,GameObject* gameObject)
{
	float x = gameObject->transform.position.x + camera->transform.position.x;
	float y = gameObject->transform.position.y + camera->transform.position.y;

	float r = gameObject->transform.scale.x * pixelsPerUnit + camera->transform.position.z;

	DrawCircleAA(x, y, r, pointCount, 
		color, isFilled, lineThickness);
}

void RectangleShape::Drawn(Camera* camera, GameObject* gameObject)
{
	float cameraOfst = camera->transform.position.z;

	// 描画サイズ指定
	float width  = (gameObject->transform.scale.x * pixelsPerUnit + cameraOfst) / 2.0f;
	float height = (gameObject->transform.scale.y * pixelsPerUnit + cameraOfst) / 2.0f;							

	// 頂点配列の初期化
	std::vector<VECTOR> vertices(4);		
	vertices[0] = VGet( width,  height, 0);
	vertices[1] = VGet(-width,  height, 0);
	vertices[2] = VGet(-width, -height, 0);
	vertices[3] = VGet( width, -height, 0);

	SetMatrixedVertices(camera, gameObject);

	// 描画
	DrawQuadrangleAA(	vertices[0].x, vertices[0].y,
						vertices[1].x, vertices[1].y,
						vertices[2].x, vertices[2].y,
						vertices[3].x, vertices[3].y,
						color, isFilled,lineThickness);
}

void TriangleShape::Drawn(Camera* camera, GameObject* gameObject)
{

}