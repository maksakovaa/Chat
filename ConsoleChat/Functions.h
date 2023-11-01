#pragma once
#include <iostream>
#include <string>
#include "users.h"
#include "Chat.h"
#include "Exceptions.h"

//���������� ������� ����������
extern UserBase* Users;
extern Chat* mainChat;
extern bool auth;
extern int userId, choice;

void menu(); //������� ����
void menuRegUser(); //���� �����������
void menuLogin(); //���� �����������
void logOut(); //������� ������ �� ������� ������
void menuUserList(); //���� �� ������� �������������. �������������� ������������ ����� ������������� � ���������� ������ ���������
void menuUserMgmt(); //������ ��� �������������� ����. ���� ���������� ����� �������������
void menuDelUser(); //������� ���������� ������� menuUserMgmt(), ������ ��� �������� �������������
void chkUsersAv(); //������� ����������� ����������� ��������� ���� ������������� (��� ������� ����� ������ � �������� ������������)
void menuChgPwd(); //������� ���������� ������� menuUserMgmt(), ������ ��� ����� ������ ������������
void menuAuth(); //���� ��������������� ������������
void menuPrivateSendMsg(); //������� ���������� ������� menuUserList(), ������ ��� �������� ������ ���������
void menuMainChat(); //���� ������ ����
void inputCleaner();
void incorrect(); //������� ��������� ������������� �����
bool regLoginChk(std::string &_login); //�������. �������� ������ ��� �����������
bool regPwdChk(std::string& _pwd); //�������. �������� ������ ��� �����������
bool authPwdChk(std::string &_login, std::string &_pwd); //�������. �������� ������ ��� �����������
bool exit(); //���������� ���������