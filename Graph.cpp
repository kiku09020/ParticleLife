#include "Graph.h"

void IRotatable::GetMatrixedVertices(VECTOR axis, float rotate, std::vector<VECTOR>* vertices, Camera* camera, GameObject* gameObject)
{
	// 回転行列
	MATRIX matrix = MGetRotAxis(axis, rotate);

	for (int i = 0; i < vertices->size(); i++) {
		(*vertices)[i] = VTransform((*vertices)[i], matrix);
	}

	// 中心座標に移動
	VECTOR center = VAdd(camera->transform.position, gameObject->transform.position);		

	for (int i = 0; i < vertices->size(); i++) {
		(*vertices)[i] = VAdd((*vertices)[i], center);
	}
}

void IRotatable::GetMatrixedVertices(std::vector<VECTOR>* vertices, Camera* camera, GameObject* gameObject)
{
	GetMatrixedVertices(VGet(0,0,1), gameObject->transform.rotation.z, vertices, camera, gameObject);
}

//--------------------------------------------------

void CircleGraph::Draw(Camera* camera,GameObject* gameObject)
{
	float x = gameObject->transform.position.x + camera->transform.position.x;
	float y = gameObject->transform.position.y + camera->transform.position.y;

	float r = gameObject->transform.scale.x * graphRenderSize + camera->transform.position.z;

	DrawCircleAA(x, y, r, pointCount, 
		color, isFilled, lineThickness);
}

void RectangleGraph::Draw(Camera* camera, GameObject* gameObject)
{
	float cameraOfst = camera->transform.position.z;

	// 描画サイズ指定
	float width  = (gameObject->transform.scale.x * graphRenderSize + cameraOfst) / 2.0f;
	float height = (gameObject->transform.scale.y * graphRenderSize + cameraOfst) / 2.0f;							

	// 頂点配列の初期化
	std::vector<VECTOR> vertices(4);		
	vertices[0] = VGet( width,  height, 0);
	vertices[1] = VGet(-width,  height, 0);
	vertices[2] = VGet(-width, -height, 0);
	vertices[3] = VGet( width, -height, 0);

	GetMatrixedVertices(&vertices, camera, gameObject);

	// 描画
	DrawQuadrangleAA(	vertices[0].x, vertices[0].y,
						vertices[1].x, vertices[1].y,
						vertices[2].x, vertices[2].y,
						vertices[3].x, vertices[3].y,
						color, isFilled,lineThickness);
}

void TriangleGraph::Draw(Camera* camera, GameObject* gameObject)
{

}