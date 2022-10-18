#pragma once
#include "SphereCollider.h"
#include "BulletsBase.h"

class CharaBase
{
protected:
    T_Location speed; //ˆÚ“®‘¬“x
    int* image=nullptr; //•`‰æ‚·‚é‰æ‘œ
    BulletsBase** bullets;//”­ŽË‚·‚é’e

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

