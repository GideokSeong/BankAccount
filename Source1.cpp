/*
©kartik
------------------Notes-----------------
You are allowed to use/edit this file.
Give me some credit if posting it.
------------------------------------------
A very simple C++ program for Bank Management.

_____________FEATURES______________

1. Login / Register using File_System
2. Auto Generating Account Number
3. Password input in * characters.(You wont see the pass).
4. Transfer Money to any other account.
5. Deposit/Withdraw Money
6. Search entire account database.(Search using Name, Address , Address!!!!)
7. Ability to Edit your account details.
8. Ability to Delete an Account.
9. Search Transactions made.(Using date)
10. Inputs Date automatically
11. Ability to store 100 transactions,(Can be increased/decreased).
12. View Last 10 Transactions.
13. Date Entry in Fancy Style

And More....
*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <process.h>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <dos.h>
#include <ctype.h>

using namespace std;


class bank
{
	long pAcc;//Account Number
	char pass[32];//Password
	char pName[30];
	char pAddr[200];
	unsigned long long pMobile;
	int balance;
	char ltran[100][100];
public:

	void NewAccount();
	void Login();
	void Transact();
	void Transfer();
	void Remove();
	void Show();
	void Search();
	void edit(long);
	void task(long);
	void pre(long);
	void vfull(long);
};

void bank::vfull(long Acc)
{
	cout << "\n\n1. Search by Date\n2. View All Data \n\n...";
	int a;
	cin >> a;
	if (a == 2)
	{
		ifstream file;
		file.open("Bank.dat", ios::binary);
		while (file.read((char *)this, sizeof(bank)))
			if (pAcc == Acc) break;
		for (int i = 0; i<100 && ltran[i][0] != '\0'; ++i)
		{
			cout << "\n" << ltran[i];
			if (i % 10 == 0 && i != 0) _getch();
		}
		_getch();
		file.close();
	}
	if (a == 1)
	{
		cout << "Enter Date (DD/MM/YYYY) :  __/__/____\b\b\b\b\b\b\b\b\b\b";
		char a;
		char sDate[8];
		int i = 0;
		for (i;;)
		{
			a = _getch();
			if (a >= '0'&&a <= '9'&&i<8)
			{
				cout << a;
				sDate[i] = a;
				++i;
				if (i == 2 || i == 4)   cout << "/";
			}
			else if (a == '\b'&&i>0 && i<9)
			{
				if (i == 2 || i == 4)
				{
					cout << "\b\b_\b";
				}
				else
					cout << "\b_\b";
				--i;

			}
			else if (a == 13)
			{
				if (i == 8)
				{
					sDate[8] = '\0';
					break;
				}
			}

		}
		ifstream file;
		file.open("Bank.dat", ios::binary);
		while (file.read((char *)this, sizeof(bank)))
			if (pAcc == Acc) break;
		int j, k;
		int ffound = 0;
		for (i = 0; ltran[i][0] != '\0'; ++i)
		{
			int found = 0;
			for (j = 0, k = 0; ltran[i][j] != '\0'&& sDate[k] != '\0';)
			{
				if (toupper(ltran[i][j]) == toupper(sDate[k]))
				{
					++k;
					++j;
					found = 1;
					ffound = 1;
				}
				else
				{
					found = 0;
					++j;
				}
			}
			if (found == 1)
			{
				cout << "\n";
				cout << "\n" << ltran[i];
			}
		}
		if (ffound == 0) cout << "\n\nNo Data found for " << sDate;
		_getch();

	}
}

void bank::pre(long Acc)
{
	ifstream file;
	file.open("Bank.dat", ios::binary);
	file.seekg(0);
	while (file.read((char*)this, sizeof(bank)))
	{
		if (Acc == pAcc) break;
	}
	cout << "\n\n--------------------------Account Summary-----------------------------";
	cout << "\nName : " << pName << "\nAddress : " << pAddr << "\nPhone Number : " << pMobile << "\nBalance : " << balance;
	cout << "\n\nDo you wish to view last 10 transaction ? : ";
}
void bank::edit(long Acc)
{
	int c = 3;
	fstream log;
	log.open("Bank.dat", ios::binary | ios::in | ios::out);
	log.seekg(0);
	while (log.read((char*)this, sizeof(bank)))
	{
		if (Acc == pAcc)
			break;
	}
PASSINPUT:
	cout << "\nEnter Current Password to continue (" << c << " chances remaining ): ";
	char npass[32];
	int i;
	char a;
	for (i = 0;;)
	{
		char a = _getch();
		if ((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z') || (a >= '0'&&a <= '9'))
		{
			npass[i] = a;
			cout << "*";
			++i;
		}
		if (a == '\b'&&i >= 1)
		{
			--i;
			cout << "\b \b";
		}
		if (a == '\r')
		{
			npass[i] = '\0';
			break;
		}
	}
	if (i <= 5)
	{
		cout << "\n\nMinimum 6 digits needed.";
		_getch();
		goto PASSINPUT;
	}
	int check = 0;
	int j;
	for (i = 0, j = 0; npass[i] != '\0'&&pass[j] != '\0'; ++i, ++j)
	{
		if (pass[j] != npass[i])
		{
			check = 0;
			break;
		}
		else check = 1;
	}
	if (check == 0)
	{
		--c;
		if (c >= 1)
		{
			cout << "\nWrong Password.";
			cout << "\nTry Again.\n\n";
			_getch();
			goto PASSINPUT;
		}
		else
		{
			cout << "\nYou entered wrong password 3 times. Terminating the program.";
			_getch();
			exit(0);
		}
	}
	system("cls");
	cout << "Enter New Data";
	cout << "\n\nName (enter dot(.) to keep same) : ";
	char nname[32];
	fflush(stdin);
	cin >> nname;
	cout << "\nAddress (enter dot(.) to keep same) : ";
	fflush(stdin);
	char nAddr[200];
	cin >> nAddr;
	cout << "\nMobile (enter 0 to keep same) : ";
	unsigned long long nMobile;
	cin >> nMobile;
PASS:
	system("cls");
	cout << "Enter New Data" << "\n\nName (enter dot(.) to keep same) : " << nname << "\n\nAddress (enter dot(.) to keep same) : " << nAddr << "\n\nMobile (enter 0 to keep same) : " << nMobile;
	cout << "\n\nPassword : ";
	for (i = 0;;)
	{
		char a = _getch();
		if ((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z') || (a >= '0'&&a <= '9'))
		{
			npass[i] = a;
			cout << "*";
			++i;
		}
		if (a == '\b'&&i >= 1)
		{
			--i;
			cout << "\b \b";
		}
		if (a == '\r')
		{
			npass[i] = '\0';
			break;
		}
	}
	if (i <= 5)
	{
		cout << "\n\nMinimum 6 digits needed.";
		_getch();
		goto PASS;
	}
	if (nname[0] != '.') strcpy_s(pName, nname);
	if (nAddr[0] != '.') strcpy_s(pAddr, nAddr);
	if (nMobile != 0) pMobile = nMobile;
	strcpy_s(pass, npass);
	int pos = (-1) *static_cast<int>( sizeof(bank));
	log.seekp(pos, ios::cur);
	log.write((char*)this, sizeof(bank));
	cout << "\n\nNew Data is : ";
	cout << "\nName : " << pName << "\nAddress : " << pAddr << "\nMobile : " << pMobile << "\nPassword : " << pass;
	_getch();
	log.close();
}
void bank::task(long Acc)
{
START:
	system("cls");
	cout << "Welcome " << pName << "\n";
	cout << "\nChoose an operation : \n1. Edit Profile\n2. Delete Account\n3. Transfer Money\n4. Withdraw/Deposit Money\n5. Account Summary\n6. Last 10 Transactions\n7. View Full Record\n8. Log Out\n\n...";
	int a;
	cin >> a;
	if (a == 7)
	{
		vfull(Acc);
		goto START;
	}
	if (a == 1)
	{
		edit(Acc);
		goto START;
	}
	if (a == 3)
	{
		cout << "\nEnter the amount you want to Transfer : ";
		long amt;
		cin >> amt;
		if (amt>balance)
		{
			cout << "\nAmount must be less than or equal to " << balance;
			_getch();
			goto START;

		}
		else if (amt <= 0)
		{
			cout << "\nAmount cant be negative or zero.";
			_getch();
			goto START;
		}
		else
		{
			time_t rawtime;
			struct tm * timeinfo;
			time(&rawtime);
			//timeinfo = localtime_s(&rawtime);
			cout << "\n\nDestination Account Number : ";
			long dAcc;
			cin >> dAcc;
			int found = 1;
			char dName[32];
			char mName[32];
			fstream file;
			file.open("Bank.dat", ios::in | ios::out | ios::binary);
			file.seekg(0);
			while (file.read((char*)this, sizeof(bank)))
			{
				if (pAcc == dAcc)
				{
					found = 1;
					break;
				}
				else found = 0;

			}
			if (found == 0)
			{
				cout << "\n\nAccount not found.";
				_getch();
				goto START;
			}
			strcpy_s(dName, pName);
			file.seekg(0);
			while (file.read((char*)this, sizeof(bank)))
			{
				if (pAcc == Acc) break;
			}
			strcpy_s(mName, pName);
			int pos = (-1)*static_cast<int>(sizeof(bank));
	
			balance -= amt;
			file.seekp(pos, ios::cur);
			int i;
			for (i = 99; i>0; --i)
			{
				strcpy_s(ltran[i], ltran[i - 1]);
			}
			char str[200];
			char str1[200];
			//strftime(str1, 100, "[%d/%m/%Y : %X]", timeinfo);
			sprintf_s(str, "[TRANSFER] Rs %d to %s(%d) << %s", amt, dName, dAcc, str1);
			strcpy_s(ltran[0], str);
			file.write((char*)this, sizeof(bank));
			file.seekg(0);
			while (file.read((char*)this, sizeof(bank)))
			{
				if (pAcc == dAcc) break;
			}
			balance += amt;
			file.seekp(pos, ios::cur);
			for (i = 99; i>0; --i)
			{
				strcpy_s(ltran[i], ltran[i - 1]);
			}
			//strftime(str1, 100, "[%d/%m/%Y : %X]", timeinfo);
			sprintf_s(str, "[RECEIVED] Rs %d from %s(%d) << %s", amt, mName, Acc, str1);
			strcpy_s(ltran[0], str);
			file.write((char*)this, sizeof(bank));
			file.close();
			sprintf_s(str, "[TRANSFER] Rs %d to %s(%d) << %s", amt, dName, dAcc, str1);
			cout << "\n\n" << str;
			_getch();
			goto START;
		}
	}
	if (a == 5)
	{
		pre(Acc);
		char y;
		cin >> y;
		if (y == 'y' || y == 'Y')
			a = 6;
		else  goto START;
	}
	if (a == 6)
	{
		cout << "\n\n========================LAST 10 TRANSACTIONS=========================";
		ifstream file;
		file.open("Bank.dat", ios::binary);
		file.seekg(0);
		while (file.read((char*)this, sizeof(bank)))
		{
			if (pAcc == Acc) break;
		}
		for (int i = 0; i<10; ++i)
			cout << "\n" << ltran[i];
		_getch();
		goto START;
	}
	if (a == 2)
	{
		cout << "Are you sure you want to delete this account. : ";
		char ans;
		cin >> ans;
		if (ans == 'Y' || ans == 'y')
		{
			cout << "\n\nDeleting your account";
			ifstream file;
			file.open("Bank.dat", ios::binary);
			ofstream temp;
			temp.open("Temp.dat", ios::binary);
			while (file.read((char*)this, sizeof(bank)))
			{
				if (Acc != pAcc) temp.write((char*)this, sizeof(bank));
			}
			file.close();
			temp.close();
			remove("Bank.dat");
			rename("Temp.dat", "Bank.dat");
			cout << "\n\nYour account was successfully deleted.";
			_getch();
			goto START;
		}
		else goto START;
	}
	if (a == 4)
	{
		cout << "\n\n1. Withdraw\n2. Deposit\n\n...";
		int am;
		int amo;
		cin >> am;
		fstream file;
		file.open("Bank.dat", ios::in | ios::out | ios::binary);
		file.seekp(0);
		while (file.read((char*)this, sizeof(bank)))
		{
			if (Acc == pAcc) break;
		}
		if (am == 1)
		{
			cout << "\nEnter amount : ";
			cin >> amo;
			if (balance < amo)
			{
				cout << "\nInsufficient Balace .";
				cout << "\nYou can withdraw max " << balance << " Rs.";
				_getch();
				goto START;
			}
			else
			{
				amo = -1 * amo;
				goto TASK;
			}

		}
		else if (am == 2) {
			cout << "\nEnter amount : ";
			cin >> amo;
			amo = +1 * amo;
			goto TASK;
		}
		else
		{
			cout << "\n\nWrong Choice.";
			_getch();
			goto START;
		}
	TASK:
		time_t rawtime;
		struct tm * timeinfo;
		time(&rawtime);
		//timeinfo = localtime(&rawtime);
		cout << "\nTransaction was successful.";
		int pos = -1 * static_cast<int>( sizeof(bank));
		file.seekp(pos, ios::cur);
		balance += amo;
		int i;
		for (i = 99; i>0; --i)
		{
			strcpy_s(ltran[i], ltran[i - 1]);
		}
		char str1[200];
		char str[200];
		if (am == 1)
		{
			amo = -1 * amo;
			//strftime(str1, 100, "[%d/%m/%Y : %X]", timeinfo);
			sprintf_s(str, "[[Withdraw] Rs %d  << %s", amo, str1);
		}
		else if (am == 2)
		{
			//strftime(str1, 100, "[%d/%m/%Y : %X]", timeinfo);
			sprintf_s(str, "[Deposit] Rs %d  << %s", amo, str1);
		}
		strcpy_s(ltran[0], str);
		file.write((char*)this, sizeof(bank));
		cout << "\n\n" << str;
		_getch();
		goto START;
	}
}
void bank::Login()
{
	int c = 3;
PASSINPUT:
	system("cls");
	cout << "--------------------------LOGIN-----------------------------";
	cout << "\n\n" << c << " chances remaining.\n\nAccount Number << ";
	long Acc;
	cin >> Acc;
	cout << "\nPassword << ";
	int i;
	char npass[32];
	char a;
	for (i = 0;;)
	{
		char a = _getch();
		if ((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z') || (a >= '0'&&a <= '9'))
		{
			npass[i] = a;
			cout << "*";
			++i;
		}
		if (a == '\b'&&i >= 1)
		{
			--i;
			cout << "\b \b";
		}
		if (a == '\r')
		{
			npass[i] = '\0';
			break;
		}
	}
	if (i <= 5)
	{
		cout << "\n\nMinimum 6 digits needed.";
		_getch();
		goto PASSINPUT;
	}
	ifstream log;
	log.open("Bank.dat", ios::binary);
	log.seekg(0);
	int check = 0;
	while (log.read((char *)this, sizeof(bank)))
	{
		check = 0;
		if (Acc != pAcc) continue;
		else
		{
			int i, j;
			for (i = 0, j = 0; npass[i] != '\0' || pass[j] != '\0'; ++i, ++j)
			{
				if (pass[j] != npass[i])
				{
					check = 0;
					break;
				}
				else check = 1;
			}
		}
		if (check == 1)
		{
			break;
		}
	}
	log.close();
	if (check == 1)
	{
		cout << "\n\nLogin Successful.";
		_getch();

		task(Acc);
	}
	else
	{
		--c;
		if (c>0)
		{
			cout << "\nWrong Password. Try again";
			_getch();
			goto PASSINPUT;
		}
		else
		{
			cout << "\nYou entered wrong pass 3 times.";
			_getch();
		}
	}
}
void bank::Search()
{
START:
	system("cls");
	cout << "Search : \n\n1. Account Number\n\n2. Name\n\n3. Address\n\n4. Go Back\n\n\n...";
	int a;
	cin >> a;
	if (a == 1)
	{
		ifstream file;
		file.open("Bank.dat", ios::binary);
		cout << "\n\nEnter Account Number : ";
		long Acc;
		cin >> Acc;
		file.seekg(0);
		int found = 0;
		while (file.read((char*)this, sizeof(bank)))
		{
			found = 0;
			if (pAcc == Acc)
			{
				Show();
				found = 1;
				_getch();
				break;
			}
		}
		if (found == 0)
		{
			cout << "\n\nNo data found.";
			_getch();
		}
		file.close();
		goto START;
	}
	if (a == 2)
	{
		ifstream file;
		file.open("Bank.dat", ios::binary);
		cout << "\nEnter Name : ";
		char Name[30];
		fflush(stdin);
		cin >> Name;
		int i, j;
		int found = 0;
		int ffound = 0;
		file.seekg(0);
		while (file.read((char *)this, sizeof(bank)))
		{
			found = 0;
			for (i = 0, j = 0; Name[i] != '\0'&& pName[j] != '\0';)
			{
				if (toupper(Name[i]) == toupper(pName[j]))
				{
					++i;
					++j;
					found = 1;
					ffound = 1;
				}
				else
				{
					found = 0;
					++j;
				}
			}
			if (found == 1)
			{
				Show();
				_getch();
			}
		}
		if (ffound == 0)
		{
			cout << "\nNo data found.";
			_getch();
		}
		file.close();
		goto START;

	}
	if (a == 3)
	{
		ifstream file;
		file.open("Bank.dat", ios::binary);
		cout << "\nEnter Address : ";
		char Addr[30];
		fflush(stdin);
		cin >> Addr;
		int i, j;
		int found = 0;
		int ffound = 0;
		file.seekg(0);
		while (file.read((char *)this, sizeof(bank)))
		{
			found = 0;
			for (i = 0, j = 0; Addr[i] != '\0'&& pAddr[j] != '\0';)
			{
				if (toupper(Addr[i]) == toupper(pAddr[j]))
				{
					++i;
					++j;
					found = 1;
					ffound = 1;
				}
				else
				{
					found = 0;
					++j;
				}
			}
			if (found == 1)
			{
				Show();
				_getch();
			}
		}
		if (ffound == 0)
		{
			cout << "\nNo data found.";
			_getch();
		}
		file.close();
		goto START;
	}

}
void bank::Show()
{
	cout << "\n------------------------------------------------------------------\n";
	cout << "\nAccount Number : " << pAcc;
	cout << "\nName : " << pName;
	cout << "\nAddress : " << pAddr;
	cout << "\nMobile : " << pMobile;
}
void bank::NewAccount()
{
	char Name[30];
	unsigned long long Mobile;
	long Acc;
	char Add[200];
	system("cls");
	cout << "\nEnter Name : ";
	fflush(stdin);
	cin >> Name;
	cout << "\nAddress : ";
	fflush(stdin);
	cin >> Add;
	cout << "\nMobile Number : ";
	cin >> Mobile;
	srand(time(NULL));
	ifstream temp;
	temp.open("Bank.dat", ios::binary);
ACCNO:
	temp.seekg(0);
	Acc = rand() % 11999 + 900000;
	int f = 0;
	while (temp.read((char *)this, sizeof(bank)))
	{
		if (Acc == pAcc)
		{
			f = 1;
			break;
		}
	}
	if (f == 1)
	{
		goto ACCNO;
	}
	temp.close();
	cout << "\nYour Account Number is (Remember it): " << pAcc;
start:
	system("cls");
	cout << "\nEnter Name : " << Name << "\n\nAddress : " << Add << "\n\nMobile Number : " << Mobile << "\n\nYour Account Number is (Remember it): " << Acc;
	cout << "\n\nEnter Password : ";
	char a;
	int i = 0;
	for (i;;)
	{
		a = _getch();
		if ((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z') || (a >= '0'&&a <= '9'))
			//check if a is numeric or alphabet
		{
			pass[i] = a;//stores a in pass
			++i;
			cout << "*";
		}
		if (a == '\b'&&i >= 1)//if user typed backspace
							  //i should be greater than 1.
		{
			cout << "\b \b";//rub the character behind the cursor.
			--i;
		}
		if (a == '\r')//if enter is pressed
		{
			pass[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}
	if (i <= 5)
	{
		cout << "\nMinimum 6 digits needed.";
		_getch();
		goto start;
	}

	ofstream file;
	file.open("Bank.dat", ios::binary | ios::app);
	strcpy_s(pName, Name);
	strcpy_s(pAddr, Add);
	pAcc = Acc;
	pMobile = Mobile;
	balance = 5000;
	for (i = 0; i<100; ++i)
		ltran[i][0] = '\0';
	file.write((char *)this, sizeof(bank));
	file.close();
	cout << "\n\nAccount Successfully Created.";
	_getch();
}

int main()
{
START:
	system("cls");
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=MAIN_MENU=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	cout << "\n1. Login\n\n2. Open New Account\n\n3. View All Data\n\n4. Search\n\n5. Exit\n\n...";
	int a;
	cin >> a;
	if (a == 5)
	{
		exit(0);
	}
	bank b;
	if (a == 4)
	{
		b.Search();
		goto START;
	}
	if (a == 3)
	{
		ifstream f;
		f.open("Bank.dat", ios::binary);
		f.seekg(0);
		int found = 0;
		while (f.read((char*)&b, sizeof(b)))
		{
			b.Show();
			_getch();
			found = 1;
		}
		if (found == 0)
		{
			cout << "\nNo data found.";
			_getch();
		}
		f.close();
		goto START;
	}
	if (a == 2)
	{
		b.NewAccount();
		a = 1;
	}
	if (a == 1)
	{
		b.Login();
		goto START;
	}
	return 1;
}