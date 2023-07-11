#pragma once

#include "DxLib.h"

#include <string>
#include <vector>
#include <unordered_map>

// フォントクラス
class Font
{
private:
	std::string fontName;			// フォント名
	std::string fontFileName;		// フォントファイル名(拡張子込み)
	std::string fontDirPath;		// フォントのディレクトリパス

	int fontHandle;					// フォントハンドル

public:
	enum FontType
	{
		Normal,
		WithEdge,
		WithAA,
	};

	Font(const std::string& fileName,const std::string& fontName,int size,int thick,FontType type);

	// フォント削除
	void OnDeleted();

	/* Getters */
	// フォント名を取得
	const char* GetFontName()		{ return fontName.c_str(); }
	std::string GetFontName_str()	{ return fontName; }

	// フォントハンドルを取得
	int GetFontHandle()				{ return fontHandle; }
};

//--------------------------------------------------
// フォント管理クラス
class FontManager
{
private:
	static const inline int DEFAULT_FONT_SIZE_ = 20;		// デフォルトのフォントサイズ
	static const inline int DEFAULT_FONT_THICK_ = 0;		// デフォルトのフォントの太さ

	//--------------------------------------------------
	static const inline std::string fontDirPath = "Assets/Fonts/";					// フォント共通ディレクトリ

	// フォント拡張子リスト
	static const inline std::vector<std::string> fontFileExtensions
		= { ".ttf",".otf" };

	static inline std::unordered_map<std::string, Font*> fontMap;		// フォントリスト

	//--------------------------------------------------

	// 指定ディレクトリ内のフォントをリストに追加する
	static void GetFonts();

public:
	static void Init();

	// 指定したフォント名のハンドルを取得する
	static int GetFontHandle(const std::string& fontName) { 
		if (fontMap.find(fontName) != fontMap.end()) {
			return fontMap[fontName]->GetFontHandle();
		}

		throw std::exception("例外");
	}

	// 指定したフォント名のハンドルを削除する
	static void DeleteFontData(const std::string& fontName) { fontMap[fontName]->OnDeleted(); }

	// すべてのフォントデータを削除する
	static void DeeteAllFontData() { InitFontToHandle(); }
};