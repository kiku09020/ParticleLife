#pragma once
#include "DxLib.h"
#include <string>
#include <tchar.h>

#include "RendereredObject.h"

// データを利用したグラフィックの基底クラス
class GraphicDataBase {
protected:
    std::string commonDataDirPath;      // 共通ディレクトリパス
    std::string dataFileDirPath;        // データのパス

    int graphicHandle;                  // 描画ハンドル

    GraphicDataBase(const std::string& commonPath) {
        commonDataDirPath = commonPath;
    }

    //--------------------------------------------------
    // ファイルパス取得
    const char* GetFilePath(const std::string& fileDirPath)
    { 
        dataFileDirPath = fileDirPath;

        const std::string& fileDir = commonDataDirPath + fileDirPath; 

        const int size = fileDir.size() + 1;
        char* filePath = new char[size];
        std::char_traits<char>::copy(filePath, fileDir.c_str(), size);

        return filePath;
    }

public:
    // 描画ハンドル取得
    int GetGraphicHandle() { return graphicHandle; }
};

//--------------------------------------------------

// 画像クラス
class Image :public GraphicDataBase,IRenderedObject2D{
protected:
    VECTOR textureSize;     // テクスチャサイズ

    bool isFlipedX;         // 左右反転されているか
    bool isFlipedY;         // 上下反転されているか

    void DrawingProcess(Camera*,GameObject*) override;

public:
    Image(const std::string &filePath);
    //--------------------------------------------------

    void Drawn(Camera*, GameObject*) override;

    /* Getters */
    VECTOR GetTextureSize() { return textureSize; }
};

// モデルクラス
class Model :public GraphicDataBase,IRenderedObject3D {
protected:

public:
    Model(const char* filePath);
    //--------------------------------------------------

    void Drawn(Camera*, GameObject*) override;
};

