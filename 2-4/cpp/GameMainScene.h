#pragma once
#include"AbstractScene.h"	
#include"Player.h"

//デフォルトの抽象シーンクラス
//ユーザーはこれを継承してシーンを実装すると楽
class GameMainScene : public AbstractScene {
private:
	Player*player;
public:
	
    GameMainScene() 
	{
		T_Location location;
		location.x = 10;
		location.y = 100;

		float radius = 10.f;

		player = new Player(location, radius);
	};

	//デストラクタ
	virtual ~GameMainScene()
	{
		delete player;  //newを作ったらdeleteを作る
	};
	//描画以外の更新を実装する
	virtual AbstractScene* Update() override;

	//描画に関する事を実装する
	virtual void Draw() const override;
};

