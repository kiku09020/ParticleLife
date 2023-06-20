#include "Renderer.h"

std::string Renderer::GetFilePath(const char* dirPath, const char* filePath)
{
	// �p�X�ۑ�
	handleDirectoryPath = dirPath;
	handleFilePath = filePath;

	// ���S�ȃp�X�ɂ���
	std::string path = std::string(dirPath) + std::string(filePath);

	return path;
}

void Renderer2D::Draw()
{
	// �e�N�X�`���̃T�C�Y�����ɁA���S���I�u�W�F�N�g�̐^�񒆂ɗ���悤�ɂ���
	float x = gameObject->transform.position.x - (textureSize.x / 2);
	float y = gameObject->transform.position.y - (textureSize.y / 2);

	float cx = .5f;
	float cy = .5f;

	float magRateX = gameObject->transform.scale.x;
	float magRateY = gameObject->transform.scale.y;

	float angle = gameObject->transform.rotation.z;

	// �`��
	DrawRotaGraph3F(x, y, cx, cy, magRateX, magRateY, angle, 
					drawHandle, true, isFlipX, isFlipY);
}