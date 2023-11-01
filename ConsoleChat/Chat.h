#pragma once
#include <iostream>
#include <time.h> //необходимо для работы со временем

class Chat
{
public:
	Chat(); //Конструктор базы сообщений
	~Chat(); //Деструктор базы сообщений
	void showMain(); //Функция выводящая общий чат
	void showPersonal(std::string user1, std::string user2); //Функция выводящая личные сообщения
	void sendMsg(std::string msgTo, std::string msgFrom, std::string msg); //Функция отправки сообщения
	std::string getTime(); //Функция возвращающая строку с текущей датой и временем
	void erase(); //функция очистки базы сообщений
	void resize(int newSize); //Функция увеличивающая двумерный динамический массив базы сообщений
private:
	std::string** msgArr; //Двумерный динамический массив базы сообщений
	int msgCount; //Счётчик сообщений
	const int msgParams{ 4 }; //Количество параметров на одно сообщение
	const int msgToInd{ 0 }; //Индекс по которому находится получатель (кому) сообщения
	const int msgFromInd{ 1 }; //Индекс по которому находится адресат (от кого) сообщения
	const int msgDateInd{ 2 }; //Индекс по которому хранится дата и время отвправки сообщения
	const int msgInd{ 3 }; //Индекс по которому хранится сам текст сообщения
};