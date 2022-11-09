#include "Player.h"
#include "DxLib.h"
#include"KeyManager.h"
#include"StraightBullets.h"
#include "HPPotion.h"


T_Location getNewLocation(T_Location newLocation);

Player::Player(T_Location location, float radius)
    :SphereCollider(location, radius)
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


void  Player::Update()
{
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

        if (bullets[bulletsCount]->isDeath())
        {
            
                delete bullets[bulletsCount];
                bullets[bulletsCount] = nullptr;

                for (int i = (bulletsCount + 1); i < 30; i++)
                {
                    if (bullets[i] == nullptr)
                    {
                        break;
                    }
                    bullets[i - 1] = bullets[i];
                    bullets[i] = nullptr;
                }
                bulletsCount--;
            
        }
    }

    if (KeyManager::OnClick(KEY_INPUT_P))
    {
        if (bulletsCount < 30 && bullets[bulletsCount] == nullptr)
        {
            bullets[bulletsCount] = new StraightBullets(GetLocation());
        }
    }
}

void Player::Draw()
{
//#define _DEBUG_MODE_
//
//#ifdef _DEBUG_MODE_
//    DrawFormatString(10, 10, GetColor(255, 255, 255),"Life=%d",this->life);
//#endif
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 255));

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

void Player::Hit(int bulletsCount)
{
    delete bullets[bulletsCount];
    bullets[bulletsCount] = nullptr;

    for (int i = (bulletsCount + 1); i < 30; i++)
    {
        if (bullets[i] == nullptr)
        {
            break;
        }
        bullets[i - 1] = bullets[i];
        bullets[i] = nullptr;
    }
}

void Player::Hit(ItemBase* item)
{
   E_ITEM_TYPE type = item->GetType();
   switch (type)
   {
   case E_ITEM_TYPE::HP_POTION:
   {
       HpPotion* potion = dynamic_cast<HpPotion*>(item);
       if (potion == nullptr)
       {
           throw - 1;
       }
       this->life += potion->GetHealPower();
       break;
    }
   default:
       break;
   }
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

void Player::addScore(int point)
{
    if (0 < point)
    {
        score += point;
    }

}

T_Location getNewLocation(T_Location newLocation)
{
    if (KeyManager::OnPressed(KEY_INPUT_W)) // Wを押している間上に進む
    {
        newLocation.y -= 2;
    }
    if (KeyManager::OnPressed(KEY_INPUT_A)) // Aをを押している間左に進む
    {
        newLocation.x -= 2;
    }
    if (KeyManager::OnPressed(KEY_INPUT_S)) // Sを押している間下に進む
    {
        newLocation.y += 2;
    }
    if (KeyManager::OnPressed(KEY_INPUT_D)) // Dを押している間→に進む
    {
        newLocation.x += 2;
    }
    return newLocation;
}