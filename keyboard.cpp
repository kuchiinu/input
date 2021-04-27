#include "keyboard.h"

BYTE KEYBOARD::KeyState[NUM_KEY_MAX];
BYTE KEYBOARD::KeyState_isTriggered[NUM_KEY_MAX];
BYTE KEYBOARD::KeyState_isReleased[NUM_KEY_MAX];

KEYBOARD keyboard;

void KEYBOARD::Update(void)
{
	BYTE key_buf[NUM_KEY_MAX];
	GetKeyboardState(key_buf);

	for (int i = 0; i < NUM_KEY_MAX; i++)
	{
		//Triggered
		KeyState_isTriggered[i] = (KeyState[i] ^ key_buf[i]) & key_buf[i];

		//Released
		KeyState_isReleased[i] = (KeyState[i] ^ key_buf[i]) & KeyState[i];

		//Pressed
		KeyState[i] = key_buf[i];
	}

	//理由は一切わからんがこれをいれないとキーボード入力できない
	if (GetKeyState(VK_SHIFT) & 0x80) 
	{
		int x = 0;
	}
	
}

bool KEYBOARD::GetKeyboardStateisTriggered(int key)
{
	return (KeyState_isTriggered[key] & 0x80) ? true : false;
}

bool KEYBOARD::GetKeyboardStateisReleased(int key)
{
	return (KeyState_isReleased[key] & 0x80) ? true : false;
}

bool KEYBOARD::GetKeyboardStateisPressed(int key)
{
	return (KeyState[key] & 0x80) ? true : false;
}

KEYBOARD* GetKeyboard(void)
{
	return &keyboard;
}
