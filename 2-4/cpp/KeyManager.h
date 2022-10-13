#pragma once
#include"DxLib.h"

class KeyManager
{
private:
	static int oldKey;    //前回の入力キー
	static int nowKey;    //今回の入力キー
private:
	KeyManager() = default;
	

public:
	static void Update()
	{
		oldKey = nowKey;
		nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}
	//ボタンを押した瞬間
	static bool OnClick(int inputKey)
	{
		int KeyFlag = (nowKey & ~oldKey);
		bool ret = (KeyFlag &inputKey);
		return ret;
	}
	//ボタンを押してる間
	static bool OnPressed(int inputKey)
	{
		bool ret = (nowKey & inputKey);
		return ret;
	}
	//ボタンを離した瞬間
	static bool OnRelease(int inputKey)
	{
		int KeyFlag = (oldKey & ~nowKey);
		bool ret = (KeyFlag & inputKey);
		return ret;
	}
};

