#ifndef account_H
#define account_H 1
#include <string>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include<cctype>
#include<fstream>
#include<iomanip>
#include <stdlib.h>
#include <dos.h>
#include <process.h>

class user
{
public:

	char name[50];

};

class account : public user
{
	int acno; //account number
	char password[20];
	float deposit; // balance
	char type;
	int dd;
	int mm;
	int yy;
	char ttype;
	float amount;

public:
	void create_account();  //function to get data from user
	void modify();  //function to add new data
	void show_account();
	float balance(); //function to return balance amount
	int retacno(); //function to return account number
	void report();
	char rettype();
	void login_user(int, char);
	void adep(int);
	void draw(int);
	void write_account();
	void modify_account(int);
	void display_all();
	void display_sp(int);
	void delete_account(int);
	void dep_withdraw(int, int);
	void login();
	void display_sp();
	int countLetters(char *);
	int countDigits(char *);
	int speLetters(char *);
	bool testPassWord(char[]);
	void transaction(void);
	float give_balance(int);
	void update_balance(int, float);
	int recordno(int);
	void add_to_file(int, int, int, int, char, char[10], float, float);
	void create_Aaccount();
};
#endif