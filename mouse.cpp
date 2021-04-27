#include "mouse.h"
#include "DrawManager.h"

bool MOUSE::left;//���{�^���̏��
bool MOUSE::right;//�E�{�^���̏��

COORD MOUSE::position;//�}�E�X�|�C���^�\�̈ʒu

bool MOUSE::left_isTrigger;//���{�^�����N���b�N
bool MOUSE::left_isPressed;//���{�^���̉������
bool MOUSE::left_isUp;//���{�^���̉��

bool MOUSE::right_isTrigger;//�E�{�^���̃N���b�N
bool MOUSE::right_isPressed;//�E�{�^���̉������
bool MOUSE::right_isUp;//�E�{�^���̉��

MOUSE mouse;

void MOUSE::Update()//�A�b�v�f�[�g
{	
	//�}�E�X�{�^���������ꑱ���Ă��邩
	left_isPressed = left;
	right_isPressed = right;

	//�}�E�X�̈ʒu
	POINT MousePos;
	GetCursorPos(&MousePos);
	position.X = MousePos.x;
	position.Y = MousePos.y;

	//�}�E�X�{�^���̏��
	left = GetAsyncKeyState(VK_LBUTTON);
	right = GetAsyncKeyState(VK_RBUTTON);
	
	//�N���b�N���ꂽ�u�Ԃ݂̂̔���
	if (!left_isPressed)//��
	{
		left_isTrigger = left;
	}
	else
	{
		left_isTrigger = false;
	}

	if (!right_isPressed)//�E
	{
		right_isTrigger = right;
	}
	else
	{
		right_isTrigger = false;
	}

	//�}�E�X�{�^���������ꂽ�u�Ԃ𔻒�
	if (left_isPressed)//��
	{
		left_isUp = !GetAsyncKeyState(VK_LBUTTON);
	}
	else
	{
		left_isUp = false;
	}

	if (right_isPressed)//�E
	{
		right_isUp = !GetAsyncKeyState(VK_RBUTTON);
	}
	else
	{
		right_isUp = false;
	}
}

bool MOUSE::GetLeftisTrigger(void)//�}�E�X�����N���b�N���ꂽ�u�Ԃ��擾
{
	return left_isTrigger;
}

bool MOUSE::GetRightisTrigger(void)//�}�E�X���E�N���b�N���ꂽ�u�Ԃ��擾
{
	return right_isTrigger;
}

bool MOUSE::GetLeftisPressed(void)//�}�E�X�����N���b�N���ꑱ���Ă����Ԃ��擾
{
	return left_isPressed;
}

bool MOUSE::GetRightisPressed(void)//�}�E�X���E�N���b�N���ꑱ���Ă����Ԃ��擾
{
	return right_isPressed;
}

bool MOUSE::GetLeftisUp(void)//�N���b�N����Ă����}�E�X�̍��{�^���������ꂽ�u�Ԃ��擾
{
	return left_isUp;
}

bool MOUSE::GetRightisUp(void)//�N���b�N����Ă����}�E�X�̉E�{�^���������ꂽ�u�Ԃ��擾
{
	return right_isUp;
}

COORD MOUSE::GetPosition(void)//�}�E�X�|�C���^�̈ʒu���擾
{
	return position;
}

MOUSE* GetMouse(void)
{
	return &mouse;
}