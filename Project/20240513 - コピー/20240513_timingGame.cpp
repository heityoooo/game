#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

//�萔
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS 10
#define CIRCLE_RADIUS_MAX 100

#define SCREEN_X 800
#define SCREEN_Y 600

//�ϐ�
typedef struct circle
{
    int X;
    int Y;
    int radius;
    double area;
}circle;

//�Q�[���t���O
bool enterPressedLastFrame = false; //�G���^�[�L�[�������ꂽ���ǂ����̃t���O
bool gameStartFlag = false;         //�Q�[���J�n�t���O
bool circleGenerationFlag = true;   //�~�̐����t���O
bool gameEndFlag = true;            //�Q�[���I���t���O

//�Q�[���J�E���g
int enterPressCount;
//�\���̂�ϐ��ɂ���
circle Circle;
//�~�̍ő�ʐ�
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;

//���C���֐�
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{

    //----------------------//
    // ��{�ݒ�
    //----------------------//
    ChangeWindowMode(TRUE); //Windowed/Fullscreen�̐ݒ�AWindowed�ɂ���
    DxLib_Init(); //DxLib�̏�����
    SetDrawScreen(DX_SCREEN_BACK); //����ʂɕ`�悷��
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);//��ʂ̑傫��

    Circle.X = CIRCLE_POS_X;
    Circle.Y = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS;




    //----------------------//
    //�Q�[�����[�v
    //----------------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClearDrawScreen();

        if (CheckHitKey(KEY_INPUT_RETURN) && !enterPressedLastFrame)
        {
            gameStartFlag = !gameStartFlag;
        }
        enterPressedLastFrame = CheckHitKey(KEY_INPUT_RETURN);
        if (gameStartFlag)
        {
            Circle.radius += 5;
            if (Circle.radius)
        }

        DrawCircle(Circle.X, Circle.Y, Circle.radius, GetColor(128, 128, 128));
        ScreenFlip();



    }
    //Dxlib�I������
    DxLib_End();
    return 0;
}
