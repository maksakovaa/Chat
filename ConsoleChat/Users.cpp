#include "users.h"

UserBase::UserBase()
{
	usercount = 0;
	std::string name = "Administartor";
	std::string login = "admin";
	std::string pwd = "admin2023";
	usersArr = new std::string * [1];
	usersArr[usercount] = new std::string[usParams];
	usersArr[usercount][usName] = name;
	usersArr[usercount][usLogin] = login;
	usersArr[usercount][usPwd] = pwd;
	usercount++;
}

UserBase::~UserBase()
{
	erase();
}

void UserBase::showUsers()
{
	std::cout << std::setw(20) << "ID пользователя" << std::setw(20) << "Имя пользователя" << std::setw(20) << "Логин" << std::endl;

	for (int i = 0; i < usercount; i++)
	{
		std::cout << std::setw(20) << i << std::setw(20) << usersArr[i][0] << std::setw(20) << usersArr[i][1] << std::endl;
	}
}

void UserBase::addUsers(std::string name, std::string login, std::string pwd)
{
	try
	{
		resize(usercount + 1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	usersArr[usercount] = new std::string[usParams];
	usersArr[usercount][usName] = name;
	usersArr[usercount][usLogin] = login;
	usersArr[usercount][usPwd] = pwd;
	usercount++;
}

bool UserBase::loginCheck(std::string login)
{
	for (int i = 0; i < usercount; i++)
	{
		if (usersArr[i][usLogin] == login) { return true; }
	}
	return false;
}

int UserBase::getUserId(std::string login)
{
	for (int i = 0; i < usercount; i++)
	{
		if (usersArr[i][usLogin] == login) { return i; }
	}
	return false;
}

void UserBase::chgPwd(int userId, std::string pwd)
{
	if (userId < 1 || userId >= usercount)
	{
		throw bad_range();
	}

	usersArr[userId][usPwd] = pwd;
}

bool UserBase::pwdCheck(int userId, std::string pwd)
{
	if (usersArr[userId][usPwd] == pwd) { return true; }
	else { return false; }
}

std::string UserBase::getUserName(int userId)
{
	return usersArr[userId][usName];
}

int UserBase::getUserCount()
{
	return usercount;
}

void UserBase::resize(int newSize)
{
	if (newSize == usercount)
		return;

	if (newSize <= 0)
	{
		throw bad_lenght();
	}
	

	if (usercount > 0)
	{
		std::string** data = new std::string * [newSize];
		for (int i = 0; i < newSize-1; i++)
		{
			data[i] = new std::string[usParams];
			for (int j = 0; j < usParams; j++)
			{
				data[i][j] = usersArr[i][j];
			}
		}
		erase();
		usersArr = new std::string * [newSize];
		for (int i = 0; i < newSize-1; i++)
		{
			usersArr[i] = new std::string[usParams];
			for (int j = 0; j < usParams; j++)
			{
				usersArr[i][j] = data[i][j];
			}
		}
		for (int i = 0; i < newSize - 1; i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}
}

void UserBase::delUser(int userId)
{
	if (userId < 0 || userId >= usercount)
	{
		throw bad_range();
	}

	if (usercount == 1)
	{
		erase();
		return;
	}

	std::string** data = new std::string * [usercount - 1];
	for (int before = 0; before < userId; before++)
	{
		data[before] = new std::string[usParams];
		for (int j = 0; j < usParams; j++)
		{
			data[before][j] = usersArr[before][j];
		}
	}
	if (userId < usercount-1)
	{
		for (int after{ userId + 1 }; after < usercount; ++after)
		{
			data[after - 1] = new std::string[usParams];
			for (int j = 0; j < usParams; j++)
			{
				data[after-1][j] = usersArr[after][j];
			}
		}
	}
	erase();
	usersArr = new std::string * [usercount-1];
	for (int i = 0; i < usercount - 1; i++)
	{
		usersArr[i] = new std::string[usParams];
		for (int j = 0; j < usParams; j++)
		{
			usersArr[i][j] = data[i][j];
		}
	}
	for (int i = 0; i < usercount - 1; i++)
	{
		delete[] data[i];
	}
	delete[] data;
	--usercount;
}

void UserBase::erase()
{
	for (int i = 0; i < usercount; i++)
	{
		delete[] usersArr[i];
	}
	delete[] usersArr;
}