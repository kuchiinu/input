#ifndef MOUSE_H
#define MOUSE_H

#include "windows.h"

class MOUSE
{
public:
	static void Update();//�A�b�v�f�[�g
	static bool GetLeftisTrigger(void);//�}�E�X�����N���b�N���ꂽ�u�Ԃ��擾
    static bool GetRightisTrigger(void);//�}�E�X���E�N���b�N���ꂽ�u�Ԃ��擾
	static bool GetLeftisPressed(void);//�}�E�X�����N���b�N���ꑱ���Ă����Ԃ��擾
	static bool GetRightisPressed(void);//�}�E�X���E�N���b�N���ꑱ���Ă����Ԃ��擾
	static bool GetLeftisUp(void);//�N���b�N����Ă����}�E�X�̍��{�^���������ꂽ�u�Ԃ��擾
	static bool GetRightisUp(void);//�N���b�N����Ă����}�E�X�̉E�{�^���������ꂽ�u�Ԃ��擾
	static COORD GetPosition(void);//�}�E�X�|�C���^�̈ʒu���擾

private:
	static bool left;//���{�^���̏��
	static bool right;//�E�{�^���̏��

	static COORD position;//�}�E�X�|�C���^�\�̈ʒu

	static bool left_isTrigger;//���{�^�����N���b�N
	static bool left_isPressed;//���{�^���̉������
	static bool left_isUp;//���{�^���̉��

	static bool right_isTrigger;//�E�{�^���̃N���b�N
	static bool right_isPressed;//�E�{�^���̉������
	static bool right_isUp;//�E�{�^���̉��
};

MOUSE* GetMouse(void);

#endif