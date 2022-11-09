#include"SphereCollider.h"
#include<math.h>

SphereCollider::SphereCollider(T_Location location, float radius)
{
	this->location.x = location.x;
	this->location.y = location.y;
	this->radius = radius;
}

bool SphereCollider::HitSphere(SphereCollider*s)
{
	//円と円の当たり判定
	//自分のベクトルー相手のベクトルが
	T_Location location = s->GetLocation();  //お互いの位置を引き算して出てくる数字が距離の倍
	float x = this->location.x -location.x;  //が自分と相手の半径より小さければ当たっていて大きければ当たっていない
	float y = this->location.y -location.y;

	//絶対値に変換
	x = fabsf(x);
	y = fabsf(y);
	
	//ベクトルの大きさを取得
	float xy =(x*x)+(y*y);
	double vectorSize = sqrt(xy);

	//自分の半径＋相手の半径 を取得
	float radius = this->radius + s->GetRadius();

	//ベクトルの大きさ<=の時
	bool ret = (vectorSize <= radius);
	return ret;
}
float SphereCollider::GetRadius()
{
	return radius;
}

T_Location SphereCollider::GetLocation()
{
	return location;
}

void SphereCollider::SetLocation(T_Location value)
{
	location.x = value.x;
	location.y = value.y;
}