#include "RenderedGraphic.h"

Image::Image(const std::string& filePath)
	:GraphicDataBase(std::string( "Assets/Textures/")),IRenderedObject2D(.25f) {

	 graphicHandle = LoadGraph(GetFilePath(filePath));

	GetGraphSizeF(graphicHandle, &textureSize.x, &textureSize.y);		// ‰æ‘œƒTƒCƒYŽæ“¾
}

void Image::DrawingProcess(Camera* camera,GameObject* gameObject)
{
	DrawModiGraphF(vertices[0].x, vertices[0].y,
		vertices[1].x, vertices[1].y,
		vertices[2].x, vertices[2].y,
		vertices[3].x, vertices[3].y,
		graphicHandle, true);
}

void Image::Drawn(Camera* camera,GameObject* gameObject) {
	SetGraphSize(textureSize, camera);
	IRenderedObject2D::Drawn(camera, gameObject);
}

//--------------------------------------------------

 Model::Model(const char* filePath) :GraphicDataBase("Assets/Models/") {


}

 void Model::Drawn(Camera* camera, GameObject* gameObject) {

 }