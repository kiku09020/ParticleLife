#pragma once

#include "DxLib.h"

#include <string>
#include <vector>
#include <unordered_map>

// �t�H���g�N���X
class Font
{
private:
	std::string fontName;			// �t�H���g��
	std::string fontFileName;		// �t�H���g�t�@�C����(�g���q����)
	std::string fontDirPath;		// �t�H���g�̃f�B���N�g���p�X

	int fontHandle;					// �t�H���g�n���h��

public:
	enum FontType
	{
		Normal,
		WithEdge,
		WithAA,
	};

	Font(const std::string& fileName,const std::string& fontName,int size,int thick,FontType type);

	// �t�H���g�폜
	void OnDeleted();

	/* Getters */
	// �t�H���g�����擾
	const char* GetFontName()		{ return fontName.c_str(); }
	std::string GetFontName_str()	{ return fontName; }

	// �t�H���g�n���h�����擾
	int GetFontHandle()				{ return fontHandle; }
};

//--------------------------------------------------
// �t�H���g�Ǘ��N���X
class FontManager
{
private:
	static const inline int DEFAULT_FONT_SIZE_ = 20;		// �f�t�H���g�̃t�H���g�T�C�Y
	static const inline int DEFAULT_FONT_THICK_ = 0;		// �f�t�H���g�̃t�H���g�̑���

	//--------------------------------------------------
	static const inline std::string fontDirPath = "Assets/Fonts/";					// �t�H���g���ʃf�B���N�g��

	// �t�H���g�g���q���X�g
	static const inline std::vector<std::string> fontFileExtensions
		= { ".ttf",".otf" };

	static inline std::unordered_map<std::string, Font*> fontMap;		// �t�H���g���X�g

	//--------------------------------------------------

	// �w��f�B���N�g�����̃t�H���g�����X�g�ɒǉ�����
	static void GetFonts();

public:
	static void Init();

	// �w�肵���t�H���g���̃n���h�����擾����
	static int GetFontHandle(const std::string& fontName) { 
		if (fontMap.find(fontName) != fontMap.end()) {
			return fontMap[fontName]->GetFontHandle();
		}

		throw std::exception("��O");
	}

	// �w�肵���t�H���g���̃n���h�����폜����
	static void DeleteFontData(const std::string& fontName) { fontMap[fontName]->OnDeleted(); }

	// ���ׂẴt�H���g�f�[�^���폜����
	static void DeeteAllFontData() { InitFontToHandle(); }
};