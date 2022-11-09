#pragma once
#include"AbstractScene.h"	
#include"Player.h"
#include"Enemy.h"
#include"HPPotion.h"
#include"ItemBase.h"

//�f�t�H���g�̒��ۃV�[���N���X
//���[�U�[�͂�����p�����ăV�[������������Ɗy
class GameMainScene : public AbstractScene {
private:
	Player*player;
	Enemy** enemy;
	ItemBase** items;
public:
	
    GameMainScene() 
	{
		T_Location location;
		location.x = 10;
		location.y = 100;

		float radius = 10.f;

		player = new Player(location, radius);

		enemy = new Enemy*[10];
		for (int i = 0; i < 10; i++)
		{
				enemy[i] = nullptr;
		}
		enemy[0] = new Enemy(T_Location{ 300,0 }, 20);

		items = new ItemBase * [10];
		for (int i = 0; i < 10; i++)
		{
			items[i] = nullptr;
		}
	}

	//�f�X�g���N�^
	virtual ~GameMainScene()
	{
		delete player;  //new���������delete�����
	};
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��鎖����������
	virtual void Draw() const override;
};

