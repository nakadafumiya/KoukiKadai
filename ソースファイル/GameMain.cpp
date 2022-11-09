#include"Dxlib.h"
#include"AbstractScene.h"
#include"SceneManager.h"
#include"GameMainScene.h"


/***
 * �v���O�����̊J�n
 **/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{


    SetMainWindowText("�V���[�e�B���O�Q�[��");

    ChangeWindowMode(TRUE);        // �E�B���h�E���[�h�ŋN��

    if (DxLib_Init() == -1) return -1;    // DX���C�u�����̏���������


    SetDrawScreen(DX_SCREEN_BACK);    // �`����ʂ𗠂ɂ���

    SetFontSize(20);        // �����T�C�Y��ݒ�

    SceneManager sceneMng((AbstractScene*)new GameMainScene());
    // �Q�[�����[�v
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr) {

        ClearDrawScreen();  //��ʂ̏�����
        sceneMng.Draw();
        ScreenFlip();            // ����ʂ̓��e��\��ʂɔ��f

    }

    DxLib_End();    // DX���C�u�����g�p�̏I������

    return 0;    // �\�t�g�̏I��
}