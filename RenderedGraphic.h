#pragma once
#include "DxLib.h"
#include <string>
#include <tchar.h>

#include "RendereredObject.h"

// �f�[�^�𗘗p�����O���t�B�b�N�̊��N���X
class GraphicDataBase {
protected:
    std::string commonDataDirPath;      // ���ʃf�B���N�g���p�X
    std::string dataFileDirPath;        // �f�[�^�̃p�X

    int graphicHandle;                  // �`��n���h��

    GraphicDataBase(const std::string& commonPath) {
        commonDataDirPath = commonPath;
    }

    //--------------------------------------------------
    // �t�@�C���p�X�擾
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
    // �`��n���h���擾
    int GetGraphicHandle() { return graphicHandle; }
};

//--------------------------------------------------

// �摜�N���X
class Image :public GraphicDataBase,IRenderedObject2D{
protected:
    VECTOR textureSize;     // �e�N�X�`���T�C�Y

    bool isFlipedX;         // ���E���]����Ă��邩
    bool isFlipedY;         // �㉺���]����Ă��邩

    void DrawingProcess(Camera*,GameObject*) override;

public:
    Image(const std::string &filePath);
    //--------------------------------------------------

    void Drawn(Camera*, GameObject*) override;

    /* Getters */
    VECTOR GetTextureSize() { return textureSize; }
};

// ���f���N���X
class Model :public GraphicDataBase,IRenderedObject3D {
protected:

public:
    Model(const char* filePath);
    //--------------------------------------------------

    void Drawn(Camera*, GameObject*) override;
};

