#pragma once
#include"AbstractScene.h"	

//デフォルトの抽象シーンクラス
//ユーザーはこれを継承してシーンを実装すると楽
class GameMainScene : public AbstractScene {
public:
	//デストラクタ
	virtual ~GameMainScene() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update()override;

	//描画に関する事を実装する
	virtual void Draw() const override;
};

