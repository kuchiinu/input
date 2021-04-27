#ifndef MOUSE_H
#define MOUSE_H

#include "windows.h"

class MOUSE
{
public:
	static void Update();//アップデート
	static bool GetLeftisTrigger(void);//マウスが左クリックされた瞬間を取得
    static bool GetRightisTrigger(void);//マウスが右クリックされた瞬間を取得
	static bool GetLeftisPressed(void);//マウスが左クリックされ続けている状態を取得
	static bool GetRightisPressed(void);//マウスが右クリックされ続けている状態を取得
	static bool GetLeftisUp(void);//クリックされていたマウスの左ボタンが離された瞬間を取得
	static bool GetRightisUp(void);//クリックされていたマウスの右ボタンが離された瞬間を取得
	static COORD GetPosition(void);//マウスポインタの位置を取得

private:
	static bool left;//左ボタンの状態
	static bool right;//右ボタンの状態

	static COORD position;//マウスポインタ―の位置

	static bool left_isTrigger;//左ボタンがクリック
	static bool left_isPressed;//左ボタンの押下状態
	static bool left_isUp;//左ボタンの解放

	static bool right_isTrigger;//右ボタンのクリック
	static bool right_isPressed;//右ボタンの押下状態
	static bool right_isUp;//右ボタンの解放
};

MOUSE* GetMouse(void);

#endif