#include "Chat.h"

Chat::Chat()
{
	msgCount = 0;
	msgArr = new std::string * [1];
}

Chat::~Chat()
{
	erase();
}

void Chat::showMain()
{
	int msgToAll = 0;
	for (int i = 0; i < msgCount; i++)
	{
		if (msgArr[i][msgToInd] == "ALL")
		{
			msgToAll++;
		}
	}
	if (msgToAll == 0)
	{
		std::cout << "Пока здесь еще никто ничего не писал" << std::endl;
	}
	else
	{
		for (int i = 0; i < msgCount; i++)
		{
			if (msgArr[i][msgToInd] == "ALL")
			{
				std::cout << msgArr[i][msgFromInd] << "\t" << msgArr[i][msgDateInd] << msgArr[i][msgInd] << "\n" << std::endl;
			}
		}
	}
}

void Chat::showPersonal(std::string user1, std::string user2)
{
	int msgPerCount = 0;
	for (int i = 0; i < msgCount; i++)
	{
		if ((msgArr[i][msgToInd] == user2 && msgArr[i][msgFromInd] == user1) || (msgArr[i][msgToInd] == user1 && msgArr[i][msgFromInd] == user2))
		{
			msgPerCount++;
		}
	}
	if (msgPerCount == 0) { std::cout << "Пока здесь еще никто ничего не писал" << std::endl; }
	else if (msgPerCount > 0)
	{
		for (int i = 0; i < msgCount; i++)
		{
			if ((msgArr[i][msgToInd] == user2 && msgArr[i][msgFromInd] == user1) || (msgArr[i][msgToInd] == user1 && msgArr[i][msgFromInd] == user2))
			{
				std::cout << msgArr[i][msgFromInd] << "\t" << msgArr[i][msgDateInd] << msgArr[i][msgInd] << "\n" << std::endl;
			}
		}
	}
}

void Chat::sendMsg(std::string msgTo, std::string msgFrom, std::string msg)
{
	resize(msgCount + 1);
	msgArr[msgCount] = new std::string[msgParams];
	msgArr[msgCount][msgToInd] = msgTo;
	msgArr[msgCount][msgFromInd] = msgFrom;
	msgArr[msgCount][msgDateInd] = this->getTime();
	msgArr[msgCount][msgInd] = msg;
	msgCount++;
}

std::string Chat::getTime()
{
	time_t now = time(NULL);
	char str[26];
	ctime_s(str, 26, &now);
	return str;
}

void Chat::erase()
{
	for (int i = 0; i < msgCount; i++) 
	{
		delete[] msgArr[i];
	}
	delete[] msgArr;
}


void Chat::resize(int newSize)
{
	if (newSize == msgCount)
		return;
	if (newSize <= 0)
	{
		erase();
		return;
	}


	if (msgCount > 0)
	{
		std::string** msgdata = new std::string * [newSize];
		for (int i = 0; i < newSize - 1; i++)
		{
			msgdata[i] = new std::string[msgParams];
			for (int j = 0; j < msgParams; j++)
			{
				msgdata[i][j] = msgArr[i][j];
			}
		}
		erase();
		msgArr = new std::string * [newSize];
		for (int i = 0; i < newSize - 1; i++)
		{
			msgArr[i] = new std::string[msgParams];
			for (int j = 0; j < msgParams; j++)
			{
				msgArr[i][j] = msgdata[i][j];
			}
		}
		for (int i = 0; i < newSize - 1; i++)
		{
			delete[] msgdata[i];
		}
		delete[] msgdata;
	}
	
}