#pragma once
#include <iomanip> //включает в себя setw, используемый для выравнивания вывода списка пользователей
#include <iostream>
#include "Exceptions.h"

class UserBase
{
public:
	UserBase(); //Конструктор базы пользователей
	~UserBase(); //Деструктор базы пользователей
	void showUsers(); //Функция выводящая список пользователей
	void addUsers(std::string name, std::string login, std::string pwd); //Функия добавления пользователя
	bool loginCheck(std::string login); //Функция проверки существования в базе пользователя с данным логином
	int getUserId(std::string login); //Функция возвращающая ID пользователя по логину
	void chgPwd(int userId, std::string pwd); //Функция изменяющая пароль
	bool pwdCheck(int userId, std::string pwd); //Функция проверки введенного пароля с хранящимя в базе
	std::string getUserName(int userId); //Функция возвращающая имя пользователя по ID
	int getUserCount(); //Функция возвращающая количество пользователей в базе
	void resize(int newSize); //Функция расширения двумерного динамического массива базы пользователей. Данные сохраняются.
	void delUser(int userId); //Функция удаления пользователя
	void erase(); //Функция очистки двумерного динамического массива
private:
	std::string** usersArr; //Двумерный динамический массив
	int usercount; //Счётчик пользователей
	const int usParams{ 3 }; //Количество аттрибутов пользователя
	const int usName{ 0 }; //Индекс по которому хранится имя пользователя
	const int usLogin{ 1 }; //Индекс по которому хранится лоогин
	const int usPwd{ 2 }; //Индекс по которому хранится пароль
};