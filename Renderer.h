#pragma once
#include <string>

#include "Camera.h"

class Renderer
{
private:

protected:
	// �R���X�g���N�^
	Renderer(GameObject* gameObject)
	{
		drawHandle = 0;
		handleDirectoryPath = "";
		handleFilePath = "";

		this->gameObject = gameObject;
	}

	const char* handleDirectoryPath;		// �`��t�@�C���̋��ʃf�B���N�g���p�X
	const char* handleFilePath;				// �`��t�@�C���p�X(�t�H���_��+�t�@�C����)
	int drawHandle;							// �`��n���h��

	GameObject* gameObject;					// �`��Ώۂ̃Q�[���I�u�W�F�N�g

	// ���S�ȃt�@�C���p�X���擾
	std::string GetFilePath(const char* dirPath, const char* filePath);

public:
	// �`�揈��
	virtual void Draw() = 0;
};

// 2D�`�揈���p�N���X
class Renderer2D : public Renderer
{
private:
	bool isFlipX = false;			// ���E���]���邩
	bool isFlipY = false;			// �㉺���]���邩

	VECTOR textureSize;

public:
	// �R���X�g���N�^
	Renderer2D(GameObject* gameObject, const char* textureFilePath) :Renderer(gameObject)
	{
		// �t�@�C���p�X�擾��ɓǂݍ���
		std::string path = GetFilePath("Assets/Textures/GameObject/", textureFilePath);
		drawHandle = LoadGraph(path.c_str());

		// �T�C�Y�擾
		GetGraphSizeF(drawHandle, &textureSize.x, &textureSize.y);

		// �I�u�W�F�N�g�w��
		this->gameObject = gameObject;
	}

	void Draw() override;
};