# Chat
Итоговое решение по модулю "основные конструкции с++"

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


# Функции
//Главное меню \
**void menu()** \ 
//Меню регистрации\
**void menuRegUser()** \
//Меню авторизации
**void menuLogin()** \
void logOut(); //Функция выхода из учетной записи
void menuUserList(); //Меню со списком пользователей. Авторизованный пользователь может просматривать и отправлять личные сообщения
void menuUserMgmt(); //Только для администратора чата. Меню управления базой пользователей
void menuDelUser(); //Функция являющаяся подменю menuUserMgmt(), служит для удаления пользователей
void chkUsersAv(); //Функция проверяющая возможность изменения базы пользователей (для функции смены пароля и удаления пользователя)
void menuChgPwd(); //Функция являющаяся подменю menuUserMgmt(), служит для смены пароля пользователя
void menuAuth(); //Меню авторизованного пользователя
void menuPrivateSendMsg(); //Функция являющаяся подменю menuUserList(), служит для отправки личных сообщений
void menuMainChat(); //Меню общего чата
void incorrect(); //Функция обработки некорректного ввода
void regLoginChk(std::string &_login); //Функция. Проверка логина при регистрации
bool regPwdChk(std::string& _pwd); //Функция. Проверка пароля при регистрации
bool authPwdChk(std::string &_login, std::string &_pwd); //Функция. Проверка пароля при авторизации
bool exit(); //Завершение программы
