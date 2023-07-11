#pragma once

#include <vector>

// �V�[���̊��N���X
class GameSceneBase
{
private:
	int sceneIndex = 0;			// �V�[���ԍ�

public:
	// �V�[�������[�h�����Ƃ��̏���
	virtual void OnSceneLoaded() = 0;

	// �V�[���X�V����
	virtual void OnSceneUpdate() = 0;

	// �V�[���j�������Ƃ��̏���
	virtual void OnSceneDestroied() = 0;
};

//--------------------------------------------------
// �V�[���Ǘ��N���X
class SceneController
{
private:
	static inline GameSceneBase* activeScene;

	static inline std::vector<GameSceneBase*> sceneList;

	static inline int sceneCount;		// �V�[���̍��v��

	// �V�[�������X�g�ɒǉ�
	static void AddScene(GameSceneBase* scene);

	// �V�[�������݂��邩���m�F����
	static bool CheckScene(int sceneIndex);
	static bool CheckScene(GameSceneBase* scene);

public:
	static void Init();
	static void Update();



	// �V�[���ǂݍ���
	static void LoadScene(int nextSceneIndex, bool doPrevSceneDest);
	static void LoadScene(GameSceneBase* nextScene, bool doPrevSceneDest);

};

