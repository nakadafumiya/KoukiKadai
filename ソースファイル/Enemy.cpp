#include "Enemy.h"
#include "StraightBullets.h"
#include "Dxlib.h"

Enemy::Enemy(T_Location location, float radius):SphereCollider(location, radius)
{
    hp = 10; //HP
    point = 10;
    
    speed = T_Location{ 0,1};

    bullets = new BulletsBase * [10];
    for (int i = 0; i < 10; i++)
    {
        bullets[i] = nullptr;
    }
}
void Enemy::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);
}
void Enemy::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 0, 255));
}
void Enemy::Hit()
{

}

void Enemy::Hit(int damage)
{
    if (0<damage)
    {
        hp -= damage;
        if (hp > 0)
        {
            hp = 0;
        }
    }
}
bool Enemy::HpCheck()
{
	bool ret = (hp < 0);
	return ret;
}
int Enemy::GetPoint()
{
	return point;
}