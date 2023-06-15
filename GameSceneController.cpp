#include "SceneController.h"
#include "GameScenes.h"

GameSceneBase* SceneController::activeScene;
std::vector<GameSceneBase*> SceneController::sceneList;
int SceneController::sceneCount;

void SceneController::Init()
{
	// ここにシーンを追加
	AddScene(new MainScene());

	sceneCount = sceneList.size();

	// 初期シーンをロード
	activeScene = sceneList[0];
	LoadScene(activeScene, false);
}

void SceneController::Update()
{
	activeScene->OnSceneUpdate();
}

//--------------------------------------------------

void SceneController::AddScene(GameSceneBase* state)
{
	sceneList.push_back(state);
}

//--------------------------------------------------

void SceneController::LoadScene(GameSceneBase* nextScene, bool doPrevSceneDestroy = false)
{
	// シーンが存在するか確認して、シーンを切り替える
	if (CheckScene(nextScene)) {
		if (doPrevSceneDestroy) {
			activeScene->OnSceneDestroied();
		}

		activeScene = nextScene;
		activeScene->OnSceneLoaded();
	}
}

void SceneController::LoadScene(int nextSceneIndex, bool doPrevScenedestroy = false)
{
	if (CheckScene(nextSceneIndex)) {
		if (doPrevScenedestroy) {
			activeScene->OnSceneDestroied();
		}
		activeScene = sceneList[nextSceneIndex];
		activeScene->OnSceneLoaded();
	}
}

//--------------------------------------------------

bool SceneController::CheckScene(GameSceneBase* nextScene)
{
	for (const auto& scene : sceneList) {
		if (scene == nextScene) {
			return true;
		}
	}

	return false;
}

bool SceneController::CheckScene(int nextSceneIndex)
{
	for (const auto& scene : sceneList) {
		if (scene == sceneList[nextSceneIndex]) {
			return true;
		}
	}

	return false;
}