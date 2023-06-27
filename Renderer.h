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
/// ファイルなどのデータを基に描画するレンダラー
/// </summary>
class Renderer_BasedData : public Renderer
{
protected:
	// コンストラクタ
	Renderer_BasedData(Camera* camera, GameObject* gameObject):Renderer(camera,gameObject)
	{
		drawHandle = 0;
		handleDirectoryPath = "";
		handleFilePath = "";
	}

	const char* handleDirectoryPath;		// 描画ファイルの共通ディレクトリパス
	const char* handleFilePath;				// 描画ファイルパス(フォルダ名+ファイル名)
	int drawHandle;							// 描画ハンドル

	// 完全なファイルパスを取得
	std::string GetFilePath(const char* dirPath, const char* filePath);
};

// 図形描画用クラス
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

// 2D描画処理用クラス
class Renderer2D : public Renderer_BasedData
{
private:
	bool isFlipX = false;			// 左右反転するか
	bool isFlipY = false;			// 上下反転するか

	VECTOR textureSize;

public:
	// コンストラクタ
	Renderer2D(Camera* camera, GameObject* gameObject, const char* textureFilePath) :Renderer_BasedData(camera,gameObject)
	{
		// ファイルパス取得後に読み込み
		std::string path = GetFilePath("Assets/Textures/GameObject/", textureFilePath);
		drawHandle = LoadGraph(path.c_str());

		// サイズ取得
		GetGraphSizeF(drawHandle, &textureSize.x, &textureSize.y);
	}

	void Draw() override;
};