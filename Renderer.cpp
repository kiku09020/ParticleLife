#include "Renderer.h"

std::string Renderer::GetFilePath(const char* dirPath, const char* filePath)
{
	// パス保存
	handleDirectoryPath = dirPath;
	handleFilePath = filePath;

	// 完全なパスにする
	std::string path = std::string(dirPath) + std::string(filePath);

	return path;
}

void Renderer2D::Draw()
{
	// テクスチャのサイズを元に、中心がオブジェクトの真ん中に来るようにする
	float x = gameObject->transform.position.x - (textureSize.x / 2);
	float y = gameObject->transform.position.y - (textureSize.y / 2);

	float cx = .5f;
	float cy = .5f;

	float magRateX = gameObject->transform.scale.x;
	float magRateY = gameObject->transform.scale.y;

	float angle = gameObject->transform.rotation.z;

	// 描画
	DrawRotaGraph3F(x, y, cx, cy, magRateX, magRateY, angle, 
					drawHandle, true, isFlipX, isFlipY);
}