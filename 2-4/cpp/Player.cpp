#include "Dxlib.h"
#include "Player.h"
#include"KeyManager.h"
#include"StraightBullets.h"

T_Location getNewLocation(T_Location newLocation);

Player::Player(T_Location location, float radius):SphereCollider(location, radius)
{
	score = 0; //現在スコア
	life = 10; //HP
	//imageの初期化
	//speedの初期化

	bullets = new BulletsBase * [30];
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}
void Player::Update()
{
	//WASDで動く操作のプログラム
		//newLocation.x = GetLocation().x;
		//newLocation.y = GetLocation().y;
		T_Location newLocation = getNewLocation(GetLocation());
		SetLocation(newLocation);

		int bulletsCount;
		for (bulletsCount = 0; bulletsCount < 30; bulletsCount++)
		{
			if (bullets[bulletsCount] == nullptr)
			{
				break;
			}
			bullets[bulletsCount]->Update();
		}

		if (KeyManager::OnClick(KEY_INPUT_P))
		{
			int i{};
			for (int i = 0; i < 30; i++)
			{
				if (bullets[i] == nullptr)
				{
					break;
				}
			}
			bullets[i] = new StraightBullets(GetLocation());
		}

}

void Player::Draw()
{
	DrawCircle(GetLocation().x,GetLocation().y, GetRadius(), GetColor(0, 255, 0));

	int bulletsCount;
	for (bulletsCount = 0; bulletsCount < 30; bulletsCount++)
	{
		if (bullets[bulletsCount] == nullptr)
		{
			break;
		}
		bullets[bulletsCount]->Draw();
	}
}
void Player::Hit()
{
}
bool Player::LifeCheck() 
{
	bool ret = (life <= 0);
	return ret;
}
int Player::GetScore()
{
	return score;
}



T_Location getNewLocation(T_Location newLocation)
{		
if (KeyManager::OnPressed(KEY_INPUT_W))
{
	newLocation.y -= 2;
}
if (KeyManager::OnPressed(KEY_INPUT_S))
{
	newLocation.y += 2;
}
if (KeyManager::OnPressed(KEY_INPUT_A))
{
	newLocation.x -= 2;
}
if (KeyManager::OnPressed(KEY_INPUT_D))
{
	newLocation.x += 2;
}
return newLocation;

}