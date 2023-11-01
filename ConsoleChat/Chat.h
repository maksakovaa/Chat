#pragma once
#include <iostream>
#include <time.h> //���������� ��� ������ �� ��������

class Chat
{
public:
	Chat(); //����������� ���� ���������
	~Chat(); //���������� ���� ���������
	void showMain(); //������� ��������� ����� ���
	void showPersonal(std::string user1, std::string user2); //������� ��������� ������ ���������
	void sendMsg(std::string msgTo, std::string msgFrom, std::string msg); //������� �������� ���������
	std::string getTime(); //������� ������������ ������ � ������� ����� � ��������
	void erase(); //������� ������� ���� ���������
	void resize(int newSize); //������� ������������� ��������� ������������ ������ ���� ���������
private:
	std::string** msgArr; //��������� ������������ ������ ���� ���������
	int msgCount; //������� ���������
	const int msgParams{ 4 }; //���������� ���������� �� ���� ���������
	const int msgToInd{ 0 }; //������ �� �������� ��������� ���������� (����) ���������
	const int msgFromInd{ 1 }; //������ �� �������� ��������� ������� (�� ����) ���������
	const int msgDateInd{ 2 }; //������ �� �������� �������� ���� � ����� ��������� ���������
	const int msgInd{ 3 }; //������ �� �������� �������� ��� ����� ���������
};