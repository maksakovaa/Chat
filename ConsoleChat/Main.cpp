//Использовалось для поиска утечек памяти
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

//Объявление и определение глобальных переменных
UserBase* Users = new UserBase();
Chat* mainChat = new Chat();
int choice { 0 }, userId{-1};
bool auth{ false };


int main()
{
	setlocale(LC_ALL, "");
	system("chcp 1251");

	menu();

	//Удаление объектов классов. Вызывает деструкторы в которых описано освобождение выделенной динамической памяти
	delete mainChat;
	delete Users;

//	_CrtDumpMemoryLeaks(); //Использовалось для поиска утечек памяти
	return 0;
}