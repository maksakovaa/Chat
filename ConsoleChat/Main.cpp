//�������������� ��� ������ ������ ������
/*
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
*/

#include <iostream>
#include "Functions.h"
#include "users.h"
#include "Chat.h"
#include <string>

using namespace std;

//���������� � ����������� ���������� ����������
UserBase* Users = new UserBase();
Chat* mainChat = new Chat();
int choice { 0 }, userId{-1};
bool auth{ false };


int main()
{
	setlocale(LC_ALL, "");
	system("chcp 1251");

	menu();

	//�������� �������� �������. �������� ����������� � ������� ������� ������������ ���������� ������������ ������
	delete mainChat;
	delete Users;

//	_CrtDumpMemoryLeaks(); //�������������� ��� ������ ������ ������
	return 0;
}