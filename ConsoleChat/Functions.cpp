#include "Functions.h"

using std::cout;
using std::string;
using std::cin;
using std::endl;

void menu()
{
	system("cls");
	cout << "����� ���������� � ���������� ���!\n��� ��������� � �������� ��������� ���������� ����� ��� ������������������. " << endl;
	cout << "�������� ��������:\n 1 - ����������� ������������ \n 2 - ����������� \n 3 - ������ ������������� \n 4 - ����� �� ���������" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice !=3 && choice !=4)
	{
		incorrect();
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		menuRegUser();
		break;
	}
	case 2:
	{
		menuLogin();
		break;
	}
	case 3:
	{
		menuUserList();
		break;
	}
	case 4:
	{
		exit();
		break;
	}
	default:
		break;
	}
}

void menuRegUser()
{
	string name, login, pwd;
	system("cls");
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "������� ��� ���:" << endl;
	getline(cin, name);
	cout << "������� �������� �����:" << endl;
	getline(cin, login);
	regLoginChk(login);
	cout << "������� �������� ������:" << endl;
	getline(cin, pwd);
	while (!regPwdChk(pwd))
	{
		getline(cin, pwd);
	}
	Users->addUsers(name, login, pwd);
	cout << "������������ " << name << " ������� ���������������. \n 1 - ������� ���� 2 - �����������" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		incorrect();
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		if (auth && userId == 0)
		{
			menuAuth();
			break;
		}
		else
		{
			menu();
			break;
		}
	}
	case 2:
	{
		menuLogin();
		break;
	}
	default:
		break;
	}
}

void menuLogin()
{
	string name, login, pwd;
	system("cls");
	cout << "���� ��� ������������������ �������������" << endl;
	cout << "������� �����:" << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, login);
	if (Users->loginCheck(login))
	{
		cout << "������� ������:" << endl;
		getline(cin, pwd);
		while (!authPwdChk(login, pwd))
		{
			cout << "�������� ������, ���������:" << endl;
			getline(cin, pwd);
		}
		if (authPwdChk(login, pwd))
		{
			auth = true;
			userId = Users->getUserId(login);
			menuAuth();
		}
	}
	else
	{
		cout << "�������� ��� ������������" << endl;
		cout << "1 - ��������� � ������� ����, 2 - ����� �� ���������, 3 - ���������" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3)
		{
			incorrect();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			menu();
			break;
		}
		case 2:
		{
			exit();
			break;
		}
		case 3:
		{
			menuLogin();
			break;
		}
		default:
			break;
		}
	}
}

void logOut()
{
	auth = false;
	userId = -1;
	menu();
}

void menuUserList()
{
	system("cls");
	Users->showUsers();
	cout << "1 - ��������� � ������� ����, 2 - ����� �� ���������";
	if (auth && userId >= 0)
		cout << " 3 - ��������� ���������";
	cout << endl;

	cin >> choice;
	if (auth)
	{
		while (choice != 1 && choice != 2 && choice != 3)
		{
			incorrect();
			cin >> choice;
		}
	}
	else
	{
		while (choice != 1 && choice != 2)
		{
			incorrect();
			cin >> choice;
		}
	}
	switch (choice)
	{
	case 1:
	{
		if (auth)
		{
			menuAuth();
		}
		else
		{
			menu();
		}
		break;
	}
	case 2:
	{
		exit();
		break;
	}
	case 3:
	{
		menuPrivateSendMsg();
		break;
	}
	default:
		break;
	}
}

void menuUserMgmt()
{
	system("cls");
	cout << "���������� ��������������. \n";
	Users->showUsers();
	cout << "\n �������� ��������: \n 1 - �������� ������������ \n 2 - ������� ������������ \n 3 - ������� ������ ������������ \n 4 - ������� ����" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		incorrect();
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		menuRegUser();
		break;
	}
	case 2:
	{
		menuDelUser();
		break;
	}
	case 3:
	{
		menuChgPwd();
		break;
	}
	case 4:
	{
		menuAuth();
		break;
	}
	default:
		break;
	}
}

void chkUsersAv()
{
	if (Users->getUserCount() <= 1)
	{
		cout << "��� ��������� ��� ���������� �������������. ����������? \n 1 - �� 2 - ���" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			incorrect();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			menuUserMgmt();
			break;
		}
		case 2:
		{
			menuAuth();
			break;
		}
		default:
			break;
		}
	}
}

void menuDelUser()
{
	if (Users->getUserCount() > 1)
	{
		cout << "������� ������ \"�������������\" ������� ������. ��� �������� ������������ ������� ��� ID : " << endl;
		cin >> choice;
		while (choice <= 0 || choice >= Users->getUserCount())
		{
			incorrect();
			cin >> choice;
		}
		cout << "�� ������� ��� ������ ������� " << Users->getUserName(choice) << "? \n 1 - ��, 2 - ���" << endl;
		int temp;
		cin >> temp;
		while (temp != 1 && temp != 2)
		{
			incorrect();
			cin >> temp;
		}
		switch (temp)
		{
		case 1:
		{
			try
			{
				Users->delUser(choice);
			}
			catch (std::exception& e)
			{
				cout << e.what() << endl;
			}
			menuUserMgmt();
			break;
		}
		case 2:
		{
			menuUserMgmt();
			break;
		}
		default:
			break;
		}
	}
	else
	{
		chkUsersAv();
	}
}

void menuChgPwd()
{
	if (Users->getUserCount() > 1)
	{
		cout << "�������� ������ ������� ������ \"�������������\" ������. ��� ��������� ������ ������������ ������� ��� ID : ";
		cin >> choice;
		while (choice <= 0 || choice >= Users->getUserCount())
		{
			incorrect();
			cin >> choice;
		}
		string pwd;
		cout << "������� ����� ������:" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, pwd);
		while (!regPwdChk(pwd))
		{
			getline(cin, pwd);
		}
		try
		{
			Users->chgPwd(choice, pwd);
		}
		catch (std::exception& e)
		{
			cout << e.what() << endl;
		}
		cout << "������ ������������ " << Users->getUserName(choice) << " ������� �������. ����������? \n 1 - ��, 2 - ���" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			incorrect();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			menuUserMgmt();
			break;
		}
		case 2:
		{
			menuAuth();
			break;
		}
		default:
			break;
		}
	}
	else 
	{
		chkUsersAv();
	}
}

void menuAuth()
{
	system("cls");
	cout << Users->getUserName(userId) << " ����� ���������� � ���������� ���!" << endl;
	cout << "�������� ��������:\n 1 - ����� �� ��������� \n 2 - ����� �� ������� ������ \n 3 - ����� ��� \n 4 - ������ ���������" << endl;
	if (userId == 0)
	{
		cout << " 5 - ���������� ��������������" << endl;
	}
	cin >> choice;
	if (userId == 0)
	{
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
		{
			incorrect();
			cin >> choice;
		}
	}
	else
	{
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			incorrect();
			cin >> choice;
		}
	}

	switch (choice)
	{
	case 1:
	{
		exit();
		break;
	}
	case 2:
	{
		logOut();
		break;
	}
	case 3:
	{
		menuMainChat();
		break;
	}
	case 4:
	{
		menuUserList();
		break;
	}
	if (userId == 0)
	{
		case 5:
		{
			menuUserMgmt();
			break;
		}
	}
	default:
		break;
	}
}

void menuPrivateSendMsg()
{
	int temp;
	cout << "������� ID ������������:" << endl;
	cin >> temp;
	while (cin.fail() || temp < 0 || temp >= Users->getUserCount())
	{
		incorrect();
		cin >> temp;
	}
	while (choice == 3)
	{
		system("cls");
		mainChat->showPersonal(Users->getUserName(userId), Users->getUserName(temp));
		cout << "1 - ��������� � ������� ����, 2 - ����� �� ��������� 3 - ��������� ��������� 4 - ��������� � ������ �������������" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			incorrect();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			menuAuth();
			break;
		}
		case 2:
		{
			exit();
			break;
		}
		case 3:
		{
			cout << "������� ���������:" << endl;
			string msgText;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, msgText);
			mainChat->sendMsg(Users->getUserName(temp), Users->getUserName(userId), msgText);
			break;
		}
		case 4:
		{
			menuUserList();
			break;
		}
		default:
			break;
		}	
	}
}

void menuMainChat()
{
	while (choice == 3)
	{
		system("cls");
		mainChat->showMain();
		cout << "1 - ��������� � ������� ����, 2 - ����� �� ��������� 3 - ��������� ���������" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3)
		{
			incorrect();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			menuAuth();
			break;
		}
		case 2:
		{
			exit();
			break;
		}
		case 3:
		{
			cout << "������� ���������:" << endl;
			string msgText;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, msgText);
			mainChat->sendMsg("ALL", Users->getUserName(userId), msgText);
			break;
		}
		default:
			break;
		}
	}
}

void incorrect()
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "������������ ����, ���������:" << endl;
}

void regLoginChk(string &_login)
{
	string letters = "�������������������������������������Ũ��������������������������";
	if (_login.find_first_of(letters) != string::npos)
	{
		cout << "ERROR: ������������ ����. ����������� ���������. " << endl;
	}
	if (_login.find_first_of(" ") != string::npos)
	{
		cout << "ERROR: ������������ ����. �� ����������� ������. " << endl;
	}
	if (Users->loginCheck(_login))
	{
		cout << "ERROR: ��� ������������ ��� ������ " << endl;
	}
	if (Users->loginCheck(_login) || _login.find_first_of(" ") != string::npos || _login.find_first_of(letters) != string::npos)
	{
		cout << "\n 1 - ��������� \n 2 - � ������� ����" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			incorrect();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			menuRegUser();
			break;
		}
		case 2:
		{
			menu();
			break;
		}
		default:
			break;
		}
	}
}

bool regPwdChk(string& _pwd)
{
	string letters = "�������������������������������������Ũ��������������������������";
	if (_pwd.find_first_of(letters) != string::npos)
	{
		cout << "ERROR: ������������ ����. ����������� ���������. " << endl;
	}
	if (_pwd.find_first_of(" ") != string::npos)
	{
		cout << "ERROR: ������������ ����. �� ����������� ������. " << endl;
	}
	if (_pwd.find_first_of(letters) == string::npos && _pwd.find_first_of(" ") == string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool authPwdChk(string &_login, string &_pwd)
{
	return Users->pwdCheck(Users->getUserId(_login), _pwd);
}

bool exit()
{
	return 0;
}