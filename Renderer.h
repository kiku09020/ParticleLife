#pragma once
#include <string>

#include "Camera.h"
#include "Graph.h"

class Renderer
{
protected:
	Renderer(Camera* camera, GameObject* gameObject)
	{
		this->camera = camera;
		this->gameObject = gameObject;
	}

	Camera* camera;
	GameObject* gameObject;

public:
	virtual void Draw() = 0;
};

/// <summary>
/// �t�@�C���Ȃǂ̃f�[�^����ɕ`�悷�郌���_���[
/// </summary>
class Renderer_BasedData : public Renderer
{
protected:
	// �R���X�g���N�^
	Renderer_BasedData(Camera* camera, GameObject* gameObject):Renderer(camera,gameObject)
	{
		drawHandle = 0;
		handleDirectoryPath = "";
		handleFilePath = "";
	}

	const char* handleDirectoryPath;		// �`��t�@�C���̋��ʃf�B���N�g���p�X
	const char* handleFilePath;				// �`��t�@�C���p�X(�t�H���_��+�t�@�C����)
	int drawHandle;							// �`��n���h��

	// ���S�ȃt�@�C���p�X���擾
	std::string GetFilePath(const char* dirPath, const char* filePath);
};

// �}�`�`��p�N���X
class GraphRenderer :public Renderer
{
private:
	Graph* graph;

protected:

public:
	GraphRenderer(Camera* camera, GameObject* gameObject,Graph* graph) :Renderer(camera, gameObject),graph(graph)
	{}
	void Draw() override
	{
		graph->Draw(camera, gameObject);
	}
};

// 2D�`�揈���p�N���X
class Renderer2D : public Renderer_BasedData
{
private:
	bool isFlipX = false;			// ���E���]���邩
	bool isFlipY = false;			// �㉺���]���邩

	VECTOR textureSize;

public:
	// �R���X�g���N�^
	Renderer2D(Camera* camera, GameObject* gameObject, const char* textureFilePath) :Renderer_BasedData(camera,gameObject)
	{
		// �t�@�C���p�X�擾��ɓǂݍ���
		std::string path = GetFilePath("Assets/Textures/GameObject/", textureFilePath);
		drawHandle = LoadGraph(path.c_str());

		// �T�C�Y�擾
		GetGraphSizeF(drawHandle, &textureSize.x, &textureSize.y);
	}

	void Draw() override;
};