#pragma once
#include <iomanip> //�������� � ���� setw, ������������ ��� ������������ ������ ������ �������������
#include <iostream>
#include "Exceptions.h"

class UserBase
{
public:
	UserBase(); //����������� ���� �������������
	~UserBase(); //���������� ���� �������������
	void showUsers(); //������� ��������� ������ �������������
	void addUsers(std::string name, std::string login, std::string pwd); //������ ���������� ������������
	bool loginCheck(std::string login); //������� �������� ������������� � ���� ������������ � ������ �������
	int getUserId(std::string login); //������� ������������ ID ������������ �� ������
	void chgPwd(int userId, std::string pwd); //������� ���������� ������
	bool pwdCheck(int userId, std::string pwd); //������� �������� ���������� ������ � ��������� � ����
	std::string getUserName(int userId); //������� ������������ ��� ������������ �� ID
	int getUserCount(); //������� ������������ ���������� ������������� � ����
	void resize(int newSize); //������� ���������� ���������� ������������� ������� ���� �������������. ������ �����������.
	void delUser(int userId); //������� �������� ������������
	void erase(); //������� ������� ���������� ������������� �������
private:
	std::string** usersArr; //��������� ������������ ������
	int usercount; //������� �������������
	const int usParams{ 3 }; //���������� ���������� ������������
	const int usName{ 0 }; //������ �� �������� �������� ��� ������������
	const int usLogin{ 1 }; //������ �� �������� �������� ������
	const int usPwd{ 2 }; //������ �� �������� �������� ������
};