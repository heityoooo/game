#include "DxLib.h"//Dxライブラリーをインクルード（読み込み）

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{

    //基本設計
    ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
    DxLib_Init();//DxLibの初期化
    SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
    SetGraphMode(800, 600, 32);//画面の大きさ
    //DxLibの初期化処理
    if (DxLib_Init() == -1)
    {
        //エラーが起きたら直ちに終了
        return -1;
    }
    //円の初期位置
    int circleX = 320;
    int circleY = 240;
    int stringX = 10;
    int strinhY = 15;
    int StringColor = GetColor(255, 255, 255);
    

    //ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面の初期化
        ClearDrawScreen();
        //文字の大きさの指定
        SetFontSize(32);
        //画面に文字表示
        //DrawString(10,15,"HelloWould",StringColor);
        DrawFormatString(stringX, strinhY, StringColor, "X:%d Y:%d", circleX, circleY);
        //画面に円を描画させる
        DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);
        //円のX座標に動きをつける
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
        //裏画面の内容を表画面に反映させる
        ScreenFlip();

    }

    //画面に点を描画させてね（X座標、Ｙ座標、点の色指定）
    DrawPixel(320, 240, GetColor(255, 0, 0));
    //Dxlib使用の終了処理
    DxLib_End();
    //ソースの終了
    return 0;
}
