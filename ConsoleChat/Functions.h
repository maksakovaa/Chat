#pragma once
#include <iostream>
#include <string>
#include "users.h"
#include "Chat.h"
#include "Exceptions.h"

//объявление внешних переменных
extern UserBase* Users;
extern Chat* mainChat;
extern bool auth;
extern int userId, choice;

void menu(); //Главное меню
void menuRegUser(); //Меню регистрации
void menuLogin(); //Меню авторизации
void logOut(); //Функция выхода из учетной записи
void menuUserList(); //Меню со списком пользователей. Авторизованный пользователь может просматривать и отправлять личные сообщения
void menuUserMgmt(); //Только для администратора чата. Меню управления базой пользователей
void menuDelUser(); //Функция являющаяся подменю menuUserMgmt(), служит для удаления пользователей
void chkUsersAv(); //Функция проверяющая возможность изменения базы пользователей (для функции смены пароля и удаления пользователя)
void menuChgPwd(); //Функция являющаяся подменю menuUserMgmt(), служит для смены пароля пользователя
void menuAuth(); //Меню авторизованного пользователя
void menuPrivateSendMsg(); //Функция являющаяся подменю menuUserList(), служит для отправки личных сообщений
void menuMainChat(); //Меню общего чата
void inputCleaner();
void incorrect(); //Функция обработки некорректного ввода
bool regLoginChk(std::string &_login); //Функция. Проверка логина при регистрации
bool regPwdChk(std::string& _pwd); //Функция. Проверка пароля при регистрации
bool authPwdChk(std::string &_login, std::string &_pwd); //Функция. Проверка пароля при авторизации
bool exit(); //Завершение программы