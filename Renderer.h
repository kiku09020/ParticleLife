#pragma once
#include <string>

#include "Camera.h"

class Renderer
{
private:

protected:
	// コンストラクタ
	Renderer(GameObject* gameObject)
	{
		drawHandle = 0;
		handleDirectoryPath = "";
		handleFilePath = "";

		this->gameObject = gameObject;
	}

	const char* handleDirectoryPath;		// 描画ファイルの共通ディレクトリパス
	const char* handleFilePath;				// 描画ファイルパス(フォルダ名+ファイル名)
	int drawHandle;							// 描画ハンドル

	GameObject* gameObject;					// 描画対象のゲームオブジェクト

	// 完全なファイルパスを取得
	std::string GetFilePath(const char* dirPath, const char* filePath);

public:
	// 描画処理
	virtual void Draw() = 0;
};

// 2D描画処理用クラス
class Renderer2D : public Renderer
{
private:
	bool isFlipX = false;			// 左右反転するか
	bool isFlipY = false;			// 上下反転するか

	VECTOR textureSize;

public:
	// コンストラクタ
	Renderer2D(GameObject* gameObject, const char* textureFilePath) :Renderer(gameObject)
	{
		// ファイルパス取得後に読み込み
		std::string path = GetFilePath("Assets/Textures/GameObject/", textureFilePath);
		drawHandle = LoadGraph(path.c_str());

		// サイズ取得
		GetGraphSizeF(drawHandle, &textureSize.x, &textureSize.y);

		// オブジェクト指定
		this->gameObject = gameObject;
	}

	void Draw() override;
};