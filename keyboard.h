#pragma once

#include "windows.h"

#define NUM_KEY_MAX (256)

class KEYBOARD
{
public:
	static void Update(void);//アップデート

	//状態
	static bool GetKeyboardStateisTriggered(int key);
	static bool GetKeyboardStateisPressed(int key);
	static bool GetKeyboardStateisReleased(int key);
	

private:
	static BYTE KeyState[NUM_KEY_MAX];
	static BYTE KeyState_isTriggered[NUM_KEY_MAX];
	static BYTE KeyState_isReleased[NUM_KEY_MAX];
};

KEYBOARD* GetKeyboard(void);
