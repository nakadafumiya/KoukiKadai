#include"SceneManager.h"
#include"KeyManager.h"

AbstractScene* SceneManager::Update() {

    //キー入力の更新
    KeyManager::Update();

    //現在シーンのアップデートを実行
    AbstractScene* NextScene = mScene->Update();

    //次のシーンが現在のシーンと違う場合切り替える
    if (NextScene != mScene) {
        delete mScene;
        mScene = NextScene;
    }
    return NextScene;
}
    void SceneManager::Draw()const {
        mScene->Draw();
    }

