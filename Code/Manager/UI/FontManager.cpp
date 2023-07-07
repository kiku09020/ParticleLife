
#include "FontManager.h"

#include <Windows.h>

Font::Font(const std::string& fileName, const std::string& fontName, int size = -1, int thick = -1, FontType fontType = Normal)
{
	this->fontFileName = fileName;
	this->fontName = fontName;

	AddFontResourceEx(fontName.c_str(), FR_PRIVATE, NULL);		// リソースに追加
	fontHandle = CreateFontToHandle(fontName.c_str(), size, thick, fontType);	// フォントハンドル作成
}

void Font::OnDeleted()
{
	DeleteFontToHandle(fontHandle);
}

//--------------------------------------------------

void FontManager::Init()
{
	GetFonts();
}

// 指定ディレクトリ内のフォントを自動でセットする
// ※フォント名はファイル名と一致している必要がある
void FontManager::GetFonts()
{
	WIN32_FIND_DATA findData;

	std::string searchedPath = fontDirPath + "*";									// 検索対象のファイルパス

	HANDLE checkedFileHandle = FindFirstFile(searchedPath.c_str(), &findData);		// チェック対象のファイルハンドル

	if (checkedFileHandle != INVALID_HANDLE_VALUE) {								// ハンドル有効チェック

		// ファイル情報を登録
		do {
			// ファイルのみ処理
			if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				std::string fileName = findData.cFileName;											// ファイル名
				std::string fileExtension = fileName.substr(fileName.find_last_of(".") );		// ファイル名からファイル拡張子を抜き出して取得

				// 拡張子チェック
				if (std::find(fontFileExtensions.begin(), fontFileExtensions.end(), fileExtension) != fontFileExtensions.end()) {
					std::string fontName = fileName.substr(0, fileName.length() - fileExtension.length());		// 拡張子を除いたものをフォント名とする(仮)

					// フォント登録
					Font* font = new Font(fileName, fontName, DEFAULT_FONT_SIZE_, DEFAULT_FONT_THICK_, Font::WithAA);
					fontMap[fontName] = font;
				}
			}

		} while (FindNextFile(checkedFileHandle, &findData) != 0);		// 次のファイルがあれば、次のファイルを登録

		FindClose(checkedFileHandle);
	}
}