# Chat
Итоговое решение по модулю "основные конструкции C++"

# Команда
Александр Максаков

# Классы
**class UserBase**\
//Функция выводящая список пользователей\
void showUsers()\
//Функия добавления пользователя\
void addUsers(std::string name, std::string login, std::string pwd)\
//Функция проверки существования в базе пользователя с данным логином\
bool loginCheck(std::string login)\
//Функция возвращающая ID пользователя по логину\
int getUserId(std::string login);
//Функция изменяющая пароль\
void chgPwd(int userId, std::string pwd)\
//Функция проверки введенного пароля с хранящимя в базе\
bool pwdCheck(int userId, std::string pwd)\
//Функция возвращающая имя пользователя по ID\
std::string getUserName(int userId)\
//Функция возвращающая количество пользователей в базе\
int getUserCount()\
//Функция расширения двумерного динамического массива базы пользователей. Данные сохраняются.\
void resize(int newSize)
//Функция удаления пользователя\
void delUser(int userId)\
//Функция очистки двумерного динамического массива\
void erase()

**class Chat** \
//Функция выводящая общий чат
void showMain() \
//Функция выводящая личные сообщения
void showPersonal(std::string user1, std::string user2) \
//Функция отправки сообщения
void sendMsg(std::string msgTo, std::string msgFrom, std::string msg) \
//Функция возвращающая строку с текущей датой и временем
std::string getTime() \
//функция очистки базы сообщений
void erase() \
//Функция увеличивающая двумерный динамический массив базы сообщений
void resize(int newSize) \

**class bad_range** \
Дочерний класс для exception. Служит для обработки исключения выход за пределы массива

**class bad_lenght** \
Дочерний класс для exception. Служит для обработки исключения некорректного размера массива

# Функции
//Главное меню \
**void menu()** \
//Меню регистрации\
**void menuRegUser()** \
//Меню авторизации \
**void menuLogin()** \
//Функция выхода из учетной записи \
**void logOut()** \
//Меню со списком пользователей. Авторизованный пользователь может просматривать и отправлять личные сообщения\
**void menuUserList()** \
//Только для администратора чата. Меню управления базой пользователей \
**void menuUserMgmt()** \
//Функция являющаяся подменю menuUserMgmt(), служит для удаления пользователей \
**void menuDelUser()** \
//Функция проверяющая возможность изменения базы пользователей (для функции смены пароля и удаления пользователя) \
**void chkUsersAv()** \
//Функция являющаяся подменю menuUserMgmt(), служит для смены пароля пользователя \
**void menuChgPwd()** \
//Меню авторизованного пользователя \
**void menuAuth()** \
//Функция являющаяся подменю menuUserList(), служит для отправки личных сообщений \
**void menuPrivateSendMsg()** \
//Меню общего чата \
**void menuMainChat()** \
//Функции обработки некорректного ввода \
**void inputCleaner()** \
**void incorrect()** \
//Функция. Проверка логина при регистрации \
**bool regLoginChk(std::string &_login)** \
//Функция. Проверка пароля при регистрации \
**bool regPwdChk(std::string& _pwd)** \
//Функция. Проверка пароля при авторизации \
**bool authPwdChk(std::string &_login, std::string &_pwd)** \
//Завершение программы \
**bool exit()**

# Блок-схема работы программы
![alt text](https://github.com/maksakovaa/Chat/blob/main/%D0%B1%D0%BB%D0%BE%D0%BA-%D1%81%D1%85%D0%B5%D0%BC%D0%B0.png)
