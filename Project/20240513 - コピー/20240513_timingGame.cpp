#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

//定数
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS 10
#define CIRCLE_RADIUS_MAX 100

#define SCREEN_X 800
#define SCREEN_Y 600

//変数
typedef struct circle
{
    int X;
    int Y;
    int radius;
    double area;
}circle;

//ゲームフラグ
bool enterPressedLastFrame = false; //エンターキーが押されたかどうかのフラグ
bool gameStartFlag = false;         //ゲーム開始フラグ
bool circleGenerationFlag = true;   //円の生成フラグ
bool gameEndFlag = true;            //ゲーム終了フラグ

//ゲームカウント
int enterPressCount;
//構造体を変数にする
circle Circle;
//円の最大面積
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;

//メイン関数
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{

    //----------------------//
    // 基本設定
    //----------------------//
    ChangeWindowMode(TRUE); //Windowed/Fullscreenの設定、Windowedにする
    DxLib_Init(); //DxLibの初期化
    SetDrawScreen(DX_SCREEN_BACK); //裏画面に描画する
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);//画面の大きさ

    Circle.X = CIRCLE_POS_X;
    Circle.Y = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS;




    //----------------------//
    //ゲームループ
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
    //Dxlib終了処理
    DxLib_End();
    return 0;
}
