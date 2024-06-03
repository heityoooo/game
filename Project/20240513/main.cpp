#include "DxLib.h"//Dx���C�u�����[���C���N���[�h�i�ǂݍ��݁j

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{

    //��{�݌v
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
    SetGraphMode(800, 600, 32);//��ʂ̑傫��
    //DxLib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }
    //�~�̏����ʒu
    int circleX = 320;
    int circleY = 240;
    int stringX = 10;
    int strinhY = 15;
    int StringColor = GetColor(255, 255, 255);
    

    //�Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();
        //�����̑傫���̎w��
        SetFontSize(32);
        //��ʂɕ����\��
        //DrawString(10,15,"HelloWould",StringColor);
        DrawFormatString(stringX, strinhY, StringColor, "X:%d Y:%d", circleX, circleY);
        //��ʂɉ~��`�悳����
        DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);
        //�~��X���W�ɓ���������
        if (CheckHitKey(KEY_INPUT_W))
        {
            if (circleY <= 40)
            {
                circleY += 3;
            }
            else
            {
                circleY -= 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_S))
        {
            if (circleY >= 560)
            {
                circleY -= 3;
            }
            else
            {
                circleY += 3;
            }
         
        }
        if (CheckHitKey(KEY_INPUT_A))
        {
            if (circleX <= 40)
            {
                circleX += 3;
            }
            else
            {
                circleX -= 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_D))
        {
            if (circleX >= 740)
            {
                circleX -= 3;
            }
            else
            {
                circleX += 3;
            }

        }
        if (CheckHitKey(KEY_INPUT_W) && CheckHitKey(KEY_INPUT_LSHIFT))
        {
            circleY -= 10;
        }
        if (CheckHitKey(KEY_INPUT_S) && CheckHitKey(KEY_INPUT_LSHIFT))
        {
            circleY += 10;
        }
        if (CheckHitKey(KEY_INPUT_A) && CheckHitKey(KEY_INPUT_LSHIFT))
        {
            circleX -= 10;
        }
        if (CheckHitKey(KEY_INPUT_D) && CheckHitKey(KEY_INPUT_LSHIFT))
        {
            circleX += 10;
        }
        //����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();

    }

    //��ʂɓ_��`�悳���ĂˁiX���W�A�x���W�A�_�̐F�w��j
    DrawPixel(320, 240, GetColor(255, 0, 0));
    //Dxlib�g�p�̏I������
    DxLib_End();
    //�\�[�X�̏I��
    return 0;
}
