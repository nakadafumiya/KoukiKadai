#pragma once
#include"DxLib.h"

class KeyManager
{
private:
	static int oldKey;    //�O��̓��̓L�[
	static int nowKey;    //����̓��̓L�[
private:
	KeyManager() = default;
	

public:
	static void Update()
	{
		oldKey = nowKey;
		nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}
	//�{�^�����������u��
	static bool OnClick(int inputKey)
	{
		int KeyFlag = (nowKey & ~oldKey);
		bool ret = (KeyFlag &inputKey);
		return ret;
	}
	//�{�^���������Ă��
	static bool OnPressed(int inputKey)
	{
		bool ret = (nowKey & inputKey);
		return ret;
	}
	//�{�^���𗣂����u��
	static bool OnRelease(int inputKey)
	{
		int KeyFlag = (oldKey & ~nowKey);
		bool ret = (KeyFlag & inputKey);
		return ret;
	}
};

