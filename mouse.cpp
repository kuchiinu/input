#include "mouse.h"
#include "DrawManager.h"

bool MOUSE::left;//左ボタンの状態
bool MOUSE::right;//右ボタンの状態

COORD MOUSE::position;//マウスポインタ―の位置

bool MOUSE::left_isTrigger;//左ボタンがクリック
bool MOUSE::left_isPressed;//左ボタンの押下状態
bool MOUSE::left_isUp;//左ボタンの解放

bool MOUSE::right_isTrigger;//右ボタンのクリック
bool MOUSE::right_isPressed;//右ボタンの押下状態
bool MOUSE::right_isUp;//右ボタンの解放

MOUSE mouse;

void MOUSE::Update()//アップデート
{	
	//マウスボタンが押され続けているか
	left_isPressed = left;
	right_isPressed = right;

	//マウスの位置
	POINT MousePos;
	GetCursorPos(&MousePos);
	position.X = MousePos.x;
	position.Y = MousePos.y;

	//マウスボタンの状態
	left = GetAsyncKeyState(VK_LBUTTON);
	right = GetAsyncKeyState(VK_RBUTTON);
	
	//クリックされた瞬間のみの判定
	if (!left_isPressed)//左
	{
		left_isTrigger = left;
	}
	else
	{
		left_isTrigger = false;
	}

	if (!right_isPressed)//右
	{
		right_isTrigger = right;
	}
	else
	{
		right_isTrigger = false;
	}

	//マウスボタンが離された瞬間を判定
	if (left_isPressed)//左
	{
		left_isUp = !GetAsyncKeyState(VK_LBUTTON);
	}
	else
	{
		left_isUp = false;
	}

	if (right_isPressed)//右
	{
		right_isUp = !GetAsyncKeyState(VK_RBUTTON);
	}
	else
	{
		right_isUp = false;
	}
}

bool MOUSE::GetLeftisTrigger(void)//マウスが左クリックされた瞬間を取得
{
	return left_isTrigger;
}

bool MOUSE::GetRightisTrigger(void)//マウスが右クリックされた瞬間を取得
{
	return right_isTrigger;
}

bool MOUSE::GetLeftisPressed(void)//マウスが左クリックされ続けている状態を取得
{
	return left_isPressed;
}

bool MOUSE::GetRightisPressed(void)//マウスが右クリックされ続けている状態を取得
{
	return right_isPressed;
}

bool MOUSE::GetLeftisUp(void)//クリックされていたマウスの左ボタンが離された瞬間を取得
{
	return left_isUp;
}

bool MOUSE::GetRightisUp(void)//クリックされていたマウスの右ボタンが離された瞬間を取得
{
	return right_isUp;
}

COORD MOUSE::GetPosition(void)//マウスポインタの位置を取得
{
	return position;
}

MOUSE* GetMouse(void)
{
	return &mouse;
}