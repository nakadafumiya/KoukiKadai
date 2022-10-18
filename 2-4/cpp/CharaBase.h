#pragma once
#include "SphereCollider.h"
#include "BulletsBase.h"

class CharaBase
{
protected:
    T_Location speed; //移動速度
    int* image=nullptr; //描画する画像
    BulletsBase** bullets;//発射する弾

public:
    virtual ~CharaBase();

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Hit() = 0;

    T_Location GetSpeed();
    void SetSpeed(T_Location speed);
    BulletsBase** GetBullets();
};

