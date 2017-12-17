
#include <iostream>
#include <string>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include<cctype>
#include<fstream>
#include<iomanip>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()

void gotoxy(short x, short y);
void adminMenu();
void customerMenu();
void login();

using namespace std;


class user
{
public:

	char name[50];

};


class account : public user
{
	int acno=0; //account number
	int password;
	int deposit; // balance
	char type;

public:
	void create_account();  //function to get data from user
	void modify();  //function to add new data
	void show_account();
	int balance(); //function to return balance amount
	int retacno(); //function to return account number
	void report();
	char rettype();
	void login_user(int, int);
	void adep(int);
	void draw(int);
};

string getpass(const char *prompt, bool show_asterisk = true)
{
	const char BACKSPACE = 8;
	const char RETURN = 13;
	string password;

	unsigned char ch = 0;
	cout << prompt;
	DWORD con_mode;
	DWORD dwRead;
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hIn, &con_mode);
	SetConsoleMode(hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
	while (ReadConsoleA(hIn, &ch, 1, &dwRead, NULL) && ch != RETURN)
	{
		if (ch == BACKSPACE)
		{
			if (password.length() != 0)
			{
				if (show_asterisk)
					cout << "\b \b";
				password.resize(password.length() - 1);
			}
		}
		else
		{
			password += ch;
			if (show_asterisk)
				cout << '*';
		}
	}
	cout << endl;
	return password;
}


void account::login_user(int acno, int pass)
{

	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);

	string password = getpass("Please enter the password: ", true); // Show asterisks
	
	while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if (acno == 9999 && pass == ac.password)
		{
			cout << "\n Login sucessful !" << endl;
			flag = true;
			adminMenu();
			break;
		}
		else if (acno == ac.retacno() && acno != 9999 && pass == ac.password)
		{
			cout << "\n Login sucessful !" << endl;
			flag = true;
			customerMenu();
			break;
		}

	}
	inFile.close();

	if (flag == false)
	{

		system("cls");
		cout << "\n\nUser name & Passcode Not matched !" << endl << endl;
		login();
	}


}




void account::create_account()
{

	cout << "\n\t Enter The account No. :";
	cin >> acno;
	cin.ignore();
	cout << "\n\t Enter 4 digit Passcode ::";
	cin >> password;
	cin.ignore(); // It means ignoring of new line.
	cout << "\n\t Enter The Name of The account Holder : ";
	cin.getline(name, 50);

	cout << "\n\tEnter Type of The account (C/S) : ";
	cin >> type;
	type = toupper(type); // It changes upper letter when some letter was inputted lower letter. 

	cout << "\n\tEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin >> deposit;
	cin.ignore();
	cout << "\n\tAccount Created..";


}

void account::modify()
{
	cout << endl << "Account No. : " << acno << endl;
	cout << endl << "Modify Account Holder Name : " << endl;
	cin.ignore();
	cin.getline(name, 50);
	cout << endl << "Modify Type of Account : " << endl;
	cin >> type;
	type = toupper(type);
	cout << endl << "Modify Balance amount : " << endl;
	cin >> deposit;
}
void account::show_account()
{
	cout << "\n\t Account No. : " << acno;
	cout << "\n\t Account Holder Name : ";
	cout << name;
	cout << "\n\t Type of Account : " << type;
	cout << "\n\t Balance amount : " << deposit << endl;
}
void account::adep(int x)
{
	deposit += x;
}

void account::draw(int x)
{
	deposit -= x;
}
int account::balance()
{
	return deposit;
}
int account::retacno()
{
	return acno;
}
char account::rettype()
{
	return type;
}
void account::report()
{
	cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}

void write_account();
void modify_account(int);
void display_all();
void display_sp(int);
void customerMenu();
void adminMenu();
void delete_account(int);
void dep_withdraw(int, int);
void display_sp();

void main()
{
	char ch;
	system("cls");

	gotoxy(11, 1);
	SetConsoleTextAttribute(console, 14);
	cout << char(219) << char(219);
	gotoxy(11, 2);
	cout << char(219) << char(219);
	gotoxy(11, 3);
	cout << char(219) << char(219);
	gotoxy(11, 4);
	cout << char(219) << char(219);
	gotoxy(11, 5);
	cout << char(1) << char(6);
	gotoxy(11, 6);
	cout << char(219) << char(219);
	gotoxy(11, 7);
	cout << char(219) << char(219);
	gotoxy(12, 6);
	cout << char(1) << char(219);
	gotoxy(14, 5);
	cout << char(1) << char(6);
	gotoxy(16, 6);
	cout << char(1) << char(6);
	gotoxy(17, 7);
	cout << char(1) << char(6);
	gotoxy(17, 6);
	cout << char(1) << char(6);
	gotoxy(17, 5);
	cout << char(1) << char(6);
	gotoxy(17, 4);
	cout << char(1) << char(6);
	gotoxy(17, 3);
	cout << char(1) << char(6);
	gotoxy(17, 2);
	cout << char(1) << char(6);
	gotoxy(17, 1);
	cout << char(1) << char(6);
	gotoxy(22, 1);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);
	gotoxy(22, 2);
	cout << char(1) << char(6);
	gotoxy(22, 3);
	cout << char(1) << char(6);
	gotoxy(22, 4);
	cout << char(1) << char(6) << char(6) << char(6);
	gotoxy(22, 5);
	cout << char(1) << char(6);
	gotoxy(22, 6);
	cout << char(1) << char(6);
	gotoxy(22, 7);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);
	gotoxy(30, 1);
	cout << char(1) << char(6);
	gotoxy(30, 2);
	cout << char(1) << char(6);
	gotoxy(30, 3);
	cout << char(1) << char(6);
	gotoxy(30, 4);
	cout << char(1) << char(6);
	gotoxy(30, 5);
	cout << char(1) << char(6);
	gotoxy(30, 6);
	cout << char(1) << char(6);
	gotoxy(30, 7);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);
	gotoxy(38, 1);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);
	gotoxy(38, 2);
	cout << char(1) << char(6);
	gotoxy(38, 3);
	cout << char(1) << char(6);
	gotoxy(38, 4);
	cout << char(1) << char(6);
	gotoxy(38, 5);
	cout << char(1) << char(6);
	gotoxy(38, 6);
	cout << char(1) << char(6);
	gotoxy(38, 7);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);
	gotoxy(46, 1);
	cout << char(1) << char(6) << char(6) << char(6) << char(6) << char(6);
	gotoxy(46, 2);
	cout << char(1) << char(6);
	gotoxy(46, 3);
	cout << char(1) << char(6);
	gotoxy(46, 4);
	cout << char(1) << char(6);
	gotoxy(46, 5);
	cout << char(1) << char(6);
	gotoxy(46, 6);
	cout << char(1) << char(6);
	gotoxy(46, 7);
	cout << char(1) << char(6) << char(6) << char(6) << char(6) << char(6);

	gotoxy(52, 7);
	cout << char(1) << char(6);
	gotoxy(52, 6);
	cout << char(1) << char(6);
	gotoxy(52, 5);
	cout << char(1) << char(6);
	gotoxy(52, 4);
	cout << char(1) << char(6);
	gotoxy(52, 3);
	cout << char(1) << char(6);
	gotoxy(52, 2);
	cout << char(1) << char(6);
	gotoxy(52, 1);
	cout << char(1) << char(6);
	gotoxy(57, 1);
	cout << char(1) << char(6);
	gotoxy(57, 2);
	cout << char(1) << char(6);
	gotoxy(57, 3);
	cout << char(1) << char(6);
	gotoxy(57, 4);
	cout << char(1) << char(6);
	gotoxy(57, 5);
	cout << char(1) << char(6);
	gotoxy(57, 6);
	cout << char(1) << char(6);
	gotoxy(57, 7);
	cout << char(1) << char(6);

	gotoxy(59, 2);
	cout << char(1);
	gotoxy(60, 3);
	cout << char(1) << char(6);
	gotoxy(62, 2);
	cout << char(1);

	gotoxy(63, 7);
	cout << char(1) << char(6);
	gotoxy(63, 6);
	cout << char(1) << char(6);
	gotoxy(63, 5);
	cout << char(1) << char(6);
	gotoxy(63, 4);
	cout << char(1) << char(6);
	gotoxy(63, 3);
	cout << char(1) << char(6);
	gotoxy(63, 2);
	cout << char(1) << char(6);
	gotoxy(63, 1);
	cout << char(1) << char(6);
	gotoxy(68, 1);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);
	gotoxy(68, 2);
	cout << char(1) << char(6);
	gotoxy(68, 3);
	cout << char(1) << char(6);
	gotoxy(68, 4);
	cout << char(1) << char(6) << char(6) << char(6);
	gotoxy(68, 5);
	cout << char(1) << char(6);
	gotoxy(68, 6);
	cout << char(1) << char(6);
	gotoxy(68, 7);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);
	gotoxy(33, 10);
	cout << char(1) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6);
	gotoxy(36, 11);
	cout << char(1) << char(6);
	gotoxy(36, 12);
	cout << char(1) << char(6);
	gotoxy(36, 13);
	cout << char(1) << char(6);
	gotoxy(36, 14);
	cout << char(1) << char(6);
	gotoxy(36, 15);
	cout << char(1) << char(6);
	gotoxy(36, 16);
	cout << char(1) << char(6);
	gotoxy(44, 10);
	cout << char(1) << char(6) << char(6) << char(6) << char(6) << char(6);
	gotoxy(44, 11);
	cout << char(1) << char(6);
	gotoxy(44, 12);
	cout << char(1) << char(6);
	gotoxy(44, 13);
	cout << char(1) << char(6);
	gotoxy(44, 14);
	cout << char(1) << char(6);
	gotoxy(44, 15);
	cout << char(1) << char(6);
	gotoxy(44, 16);
	cout << char(1) << char(6) << char(6) << char(6) << char(6) << char(6);
	gotoxy(50, 16);
	cout << char(1) << char(6);
	gotoxy(50, 15);
	cout << char(1) << char(6);
	gotoxy(50, 14);
	cout << char(1) << char(6);
	gotoxy(50, 13);
	cout << char(1) << char(6);
	gotoxy(50, 12);
	cout << char(1) << char(6);
	gotoxy(50, 11);
	cout << char(1) << char(6);
	gotoxy(50, 10);
	cout << char(1) << char(6);
	gotoxy(26, 19);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);
	gotoxy(26, 20);
	cout << char(1) << char(6);
	gotoxy(26, 21);
	cout << char(1) << char(6);
	gotoxy(26, 22);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);
	gotoxy(26, 23);
	cout << char(1) << char(6);
	gotoxy(26, 24);
	cout << char(1) << char(6);
	gotoxy(26, 25);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);

	gotoxy(31, 25);
	cout << char(6);
	gotoxy(31, 24);
	cout << char(1) << char(6);
	gotoxy(31, 23);
	cout << char(1) << char(6);
	gotoxy(31, 22);
	cout << char(6);
	gotoxy(31, 21);
	cout << char(1) << char(6);
	gotoxy(31, 20);
	cout << char(1) << char(6);
	gotoxy(31, 19);
	cout << char(6);
	gotoxy(37, 19);
	cout << char(1) << char(6) << char(6);
	gotoxy(35, 20);
	cout << char(1) << char(6);
	gotoxy(35, 21);
	cout << char(1) << char(6);
	gotoxy(35, 22);
	cout << char(1) << char(6) << char(6) << char(6) << char(6);
	gotoxy(35, 23);
	cout << char(1) << char(6);
	gotoxy(35, 24);
	cout << char(1) << char(6);
	gotoxy(35, 25);
	cout << char(1) << char(6);
	gotoxy(40, 25);
	cout << char(1) << char(6);
	gotoxy(40, 24);
	cout << char(1) << char(6);
	gotoxy(40, 23);
	cout << char(1) << char(6);
	gotoxy(40, 22);
	cout << char(1) << char(6);
	gotoxy(40, 21);
	cout << char(1) << char(6);
	gotoxy(40, 20);
	cout << char(1) << char(6);
	gotoxy(44, 19);
	cout << char(1) << char(6);
	gotoxy(44, 20);
	cout << char(1) << char(6);
	gotoxy(44, 21);
	cout << char(1) << char(6);
	gotoxy(44, 22);
	cout << char(1) << char(6);
	gotoxy(44, 23);
	cout << char(1) << char(6);
	gotoxy(44, 24);
	cout << char(1) << char(6);
	gotoxy(44, 25);
	cout << char(1) << char(6);
	gotoxy(45, 19);
	cout << char(1);
	gotoxy(46, 20);
	cout << char(1);
	gotoxy(47, 21);
	cout << char(1);
	gotoxy(48, 22);
	cout << char(1);
	gotoxy(49, 23);
	cout << char(1);
	gotoxy(50, 24);
	cout << char(1);
	gotoxy(51, 25);
	cout << char(1);
	gotoxy(51, 19);
	cout << char(1) << char(6);
	gotoxy(51, 20);
	cout << char(1) << char(6);
	gotoxy(51, 21);
	cout << char(1) << char(6);
	gotoxy(51, 22);
	cout << char(1) << char(6);
	gotoxy(51, 23);
	cout << char(1) << char(6);
	gotoxy(51, 24);
	cout << char(1) << char(6);
	gotoxy(51, 25);
	cout << char(1) << char(6);
	gotoxy(55, 19);
	cout << char(1) << char(6);
	gotoxy(55, 20);
	cout << char(1) << char(6);
	gotoxy(55, 21);
	cout << char(1) << char(6);
	gotoxy(55, 22);
	cout << char(1) << char(6);
	gotoxy(55, 23);
	cout << char(1) << char(6);
	gotoxy(55, 24);
	cout << char(1) << char(6);
	gotoxy(55, 25);
	cout << char(1) << char(6);
	gotoxy(59, 19);
	cout << char(1) << char(6);
	gotoxy(58, 20);
	cout << char(1);
	gotoxy(57, 21);
	cout << char(1);
	gotoxy(57, 23);
	cout << char(1);
	gotoxy(58, 24);
	cout << char(1);
	gotoxy(59, 25);
	cout << char(1) << char(6);
	cout << "\n\n\n\n";
	system("pause");
	system("cls");
	gotoxy(44, 10);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14)
		<< char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14);
	gotoxy(44, 11);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(87, 11);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(44, 12);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14)
		<< char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14);
	gotoxy(44, 13);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(44, 14);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(44, 15);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(44, 16);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(44, 17);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(44, 18);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(44, 19);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(44, 20);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(44, 21);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(44, 22);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14)
		<< char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14);
	gotoxy(87, 13);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(87, 14);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(87, 15);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(87, 16);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(87, 17);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(87, 18);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(87, 19);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(87, 20);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(87, 21);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(87, 22);
	SetConsoleTextAttribute(console, 10);
	cout << char(14) << char(14);
	gotoxy(52, 11);
	SetConsoleTextAttribute(console, 9);
	cout << "SELECT AN OPTION FROM THE MENU " << endl << endl;
	gotoxy(48, 15);
	SetConsoleTextAttribute(console, 2);
	cout << "1. USER LOGIN" << endl;
	gotoxy(48, 17);
	cout << "2. NEW ACCOUNT" << endl;
	gotoxy(48, 19);
	cout << "3. EXIT" << endl;
	gotoxy(48, 21);
	SetConsoleTextAttribute(console, 6);
	cout << "Your Choice is ";
	cin >> ch;
	system("cls");
	switch (ch)
	{
	case '1':
		login();
		break;
	case '2':
		write_account();
		main();
		break;
	case '3':
		gotoxy(40, 6);
		SetConsoleTextAttribute(console, 13);
		cout << char(1) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << endl;
		gotoxy(40, 7);
		cout << char(1) << char(6);
		gotoxy(40, 8);
		cout << char(1) << char(6);
		gotoxy(50, 8);
		SetConsoleTextAttribute(console, 9);
		cout << "THANK YOU FOR BANKING WITH US" << endl;
		gotoxy(85, 7);
		SetConsoleTextAttribute(console, 12);
		cout << char(1) << char(6);
		gotoxy(85, 8);
		cout << char(1) << char(6);
		gotoxy(85, 9);
		cout << char(1) << char(6);
		gotoxy(40, 9);
		cout << char(1) << char(6);
		gotoxy(40, 10);
		cout << char(1) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << endl;
		break;
	default:
		cout << "a";
	}

}
void adminMenu()
{
	char ch;
	int num;

	do {

		system("cls");
		gotoxy(48, 7);
		cout << char(1) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6)
			<< char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(2);
		gotoxy(48, 8);
		cout << char(5);
		gotoxy(48, 9);
		cout << char(3) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6)
			<< char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(4);
		gotoxy(64, 8);
		cout << char(5);
		gotoxy(50, 8);

		//textbackground(YELLOW);
		SetConsoleTextAttribute(console, 7);
		cout << "A  D  M  I  N" << endl;
		gotoxy(49, 10);
		SetConsoleTextAttribute(console, 10);
		cout << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14)
			<< char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14);
		gotoxy(49, 11);
		SetConsoleTextAttribute(console, 10);
		cout << char(14) << char(14);
		gotoxy(63, 11);
		SetConsoleTextAttribute(console, 10);
		cout << char(14) << char(14);
		gotoxy(49, 12);
		SetConsoleTextAttribute(console, 10);
		cout << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14)
			<< char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14);
		gotoxy(54, 11);
		SetConsoleTextAttribute(console, 4);
		cout << "OPTIONS" << endl << endl << endl;
		gotoxy(48, 15);
		SetConsoleTextAttribute(console, 9);
		cout << "1. MODIFY AN ACCOUNT" << endl;
		gotoxy(48, 17);
		cout << "2. CLOSE AN ACCOUNT" << endl;
		gotoxy(48, 19);
		cout << "3. ACCOUNT INFORM OF CUSTOMER" << endl;
		gotoxy(48, 21);
		cout << "4. COMPLETE ACCOUNT HOLDERS LIST" << endl;
		gotoxy(48, 23);
		cout << "5. GO BACK FIRST MENU" << endl;
		gotoxy(48, 25);
		cout << "6. EXIT" << endl;

		gotoxy(54, 27);
		cin >> ch;
		system("cls");

		switch (ch)
		{
		case '1':
			cout << "\n\n\t Enter The account No. : "; cin >> num;
			modify_account(num);
			system("pause");
			break;
		case '2':
			cout << "\n\n\t Enter The account No. : "; cin >> num;
			delete_account(num);
			system("pause");
			break;
		case '3':
			cout << "\n\n\t Enter The account No. : "; cin >> num;
			display_sp(num);
			system("pause");
			break;
		case '4':
			display_all();
			system("pause");
			break;
		case '5':
			main();
			break;
		case '6':
			cout << "THANK YOU FOR USE. " << endl;
			break;
		default:
			cout << "a";
		}
		cin.ignore();

	} while (ch != '6');

}

void customerMenu()
{
	char ch;
	int num;
	

	do
	{
		system("cls");
		gotoxy(48, 7);
		cout << char(1) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6)
			<< char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(2);
		gotoxy(48, 8);
		cout << char(5);
		gotoxy(48, 9);
		cout << char(3) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6)
			<< char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(6) << char(4);
		gotoxy(64, 8);
		cout << char(5);
		gotoxy(50, 8);

		//textbackground(YELLOW);
		SetConsoleTextAttribute(console, 7);
		cout << "C U S T O M E R" << endl;
		gotoxy(49, 10);
		SetConsoleTextAttribute(console, 10);
		cout << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14)
			<< char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14);
		gotoxy(49, 11);
		SetConsoleTextAttribute(console, 10);
		cout << char(14) << char(14);
		gotoxy(63, 11);
		SetConsoleTextAttribute(console, 10);
		cout << char(14) << char(14);
		gotoxy(49, 12);
		SetConsoleTextAttribute(console, 10);
		cout << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14)
			<< char(14) << char(14) << char(14) << char(14) << char(14) << char(14) << char(14);
		gotoxy(54, 11);
		SetConsoleTextAttribute(console, 7);
		cout << "OPTIONS" << endl << endl << endl;
		gotoxy(48, 15);
		SetConsoleTextAttribute(console, 3);
		cout << "1. BALANCE ENQUIRY" << endl;
		gotoxy(48, 17);
		cout << "2. DEPOSIT" << endl;
		gotoxy(48, 19);
		cout << "3. WITHRAW" << endl;
		gotoxy(48, 21);
		cout << "4. GO BACK FIRST MENU" << endl;
		gotoxy(48, 23);
		cout << "5. EXIT" << endl;

		gotoxy(54, 25);
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			cout << "\n\n\t Enter The account No. : "; cin >> num;
			display_sp(num);
			system("pause");
			break;
		case '2':
			cout << "\n\n\t Enter The account No. : "; cin >> num;
			dep_withdraw(num, 1);
			system("pause");
			break;
		case '3':
			cout << "\n\n\t Enter The account No. : "; cin >> num;
			dep_withdraw(num, 2);
			system("pause");
			break;
		case '4':
			main();
			break;
		case '5':
			cout << "THANK YOU FOR USE" << endl;
			break;
		default:cout << "a";
		}

	} while (ch != '5');

}
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


void login()
{
	int acno;
	int pass;
	account ac;

	cout << "please enter your account number: ";
	cin.ignore();
	cin >> acno;

	cout << "please enter your passcord number: ";
	cin.ignore();
	cin >> pass;
	

	ac.login_user(acno, pass);
}

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void display_sp()      //function to retrive a record from file stored
{
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be opened!! Press any Key to exit...";
		return;
	}
	cout << "\n\t BALANCE DETAILS\n";

	while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if (ac.retacno())
		{
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nAccount number does not exist";
}
void display_sp(int n)      //function to retrive a record from file stored
{
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be opened!! Press any Key to exit...";
		return;
	}
	cout << "\n\t BALANCE DETAILS\n";

	while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		
		
		if (ac.retacno() == n)
		{

			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nAccount number does not exist";
}
void display_all()
{
	account ac;
	ifstream infile;
	infile.open("account.txt", ios::binary);
	if (!infile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\t ACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";
	while (infile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	infile.close();
}

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.txt", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
	outFile.close();
}

void modify_account(int n)
{
	bool found = false;
	account ac;
	fstream File;
	File.open("account.txt", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			cout << "\n\n Enter The New Details of account" << endl;
			ac.modify();
			int pos = (-1)*static_cast<int>(sizeof(account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}
void delete_account(int n)
{
	account ac;
	ifstream x;
	ofstream y;
	x.open("account.txt", ios::binary);
	if (!x)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	y.open("temp.txt", ios::binary);
	x.seekg(0, ios::beg);
	while (x.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if (ac.retacno() != n)
		{
			y.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	x.close();
	y.close();
	remove("account.txt");
	rename("temp.txt", "account.txt");
	cout << "\n\n\tRecord Deleted ..";
}// function to display account details from the stored file
void dep_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	account ac;
	fstream x;
	x.open("account.txt", ios::binary | ios::in | ios::out);
	if (!x)
	{
		cout << "File could not be open !! Press any Key..." << endl;
		return;
	}
	while (!x.eof() && found == false)
	{
		x.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << "\n\n\tTO DEPOSITE AMOUNT ";
				cout << "\n\nEnter The amount to be deposited";
				cin >> amt;
				ac.adep(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\tTO WITHDRAW AMOUNT ";
				cout << "\n\nEnter The amount to be withdraw";
				cin >> amt;
				int bal = ac.balance() - amt;
				if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
					cout << "Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos = (-1)*static_cast<int>(sizeof(ac));
			x.seekp(pos, ios::cur);
			x.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	x.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}


