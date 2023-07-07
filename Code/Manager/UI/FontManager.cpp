
#include "FontManager.h"

#include <Windows.h>

Font::Font(const std::string& fileName, const std::string& fontName, int size = -1, int thick = -1, FontType fontType = Normal)
{
	this->fontFileName = fileName;
	this->fontName = fontName;

	AddFontResourceEx(fontName.c_str(), FR_PRIVATE, NULL);		// ���\�[�X�ɒǉ�
	fontHandle = CreateFontToHandle(fontName.c_str(), size, thick, fontType);	// �t�H���g�n���h���쐬
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

// �w��f�B���N�g�����̃t�H���g�������ŃZ�b�g����
// ���t�H���g���̓t�@�C�����ƈ�v���Ă���K�v������
void FontManager::GetFonts()
{
	WIN32_FIND_DATA findData;

	std::string searchedPath = fontDirPath + "*";									// �����Ώۂ̃t�@�C���p�X

	HANDLE checkedFileHandle = FindFirstFile(searchedPath.c_str(), &findData);		// �`�F�b�N�Ώۂ̃t�@�C���n���h��

	if (checkedFileHandle != INVALID_HANDLE_VALUE) {								// �n���h���L���`�F�b�N

		// �t�@�C������o�^
		do {
			// �t�@�C���̂ݏ���
			if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				std::string fileName = findData.cFileName;											// �t�@�C����
				std::string fileExtension = fileName.substr(fileName.find_last_of(".") );		// �t�@�C��������t�@�C���g���q�𔲂��o���Ď擾

				// �g���q�`�F�b�N
				if (std::find(fontFileExtensions.begin(), fontFileExtensions.end(), fileExtension) != fontFileExtensions.end()) {
					std::string fontName = fileName.substr(0, fileName.length() - fileExtension.length());		// �g���q�����������̂��t�H���g���Ƃ���(��)

					// �t�H���g�o�^
					Font* font = new Font(fileName, fontName, DEFAULT_FONT_SIZE_, DEFAULT_FONT_THICK_, Font::WithAA);
					fontMap[fontName] = font;
				}
			}

		} while (FindNextFile(checkedFileHandle, &findData) != 0);		// ���̃t�@�C��������΁A���̃t�@�C����o�^

		FindClose(checkedFileHandle);
	}
}