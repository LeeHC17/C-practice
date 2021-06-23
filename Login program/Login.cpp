#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

class user {
	int menu = 0;
	string new_id, new_password;
	string id, password, idNpass;
	string account;
	char buf = '\0';
	bool valid = false;
public:
	void main_display();
	void create_account();
	void login();
	bool check_account(string idNpass);
	void account_page(string id);
	void clear();
};
void user::main_display() {
	clear();
	cout << "\n\t\t\t ---------------------------------------" << endl;
	cout << "\t\t\t|                Welcome!!!             |" << endl;
	cout << "\t\t\t|            Menu 1. Login              |" << endl;
	cout << "\t\t\t|            Menu 2. Create account     |" << endl;
	cout << "\t\t\t|            Menu 3. Terminate          |" << endl;
	cout << "\t\t\t ---------------------------------------" << endl;

	do {
		cout << "\nChoice the menu(1 ~ 3): ";
		cin >> menu;
		if (menu < 0 || menu>3) {
			cout << "\nPlease choose correct menu 1 ~ 3!!" << endl;
		}
	} while (menu < 0 || menu>3);

	if (menu == 1) {
		login();
	}
	else if (menu == 2) {
		create_account();
	}
	else if (menu == 3) {
		clear();
		cout << "\n\t\t\t --------------------------" << endl;
		cout << "\t\t\t|        Good Bye!!        |" << endl;
		cout << "\t\t\t --------------------------" << endl;
		exit(0);
	}
}
void user::create_account() {
	clear();
	cout << "\n\t\t\t --------------------------" << endl;
	cout << "\t\t\t|    Create Account Page   |" << endl;
	cout << "\t\t\t --------------------------" << endl;

	cout << "Enter the new ID: ";
	cin >> new_id;
	cout << "\nEnter the new password: ";
	cin >> new_password;

	ofstream Account("account.txt");

	Account << new_id << " " << new_password << endl;
	Account.close();

	cout << "\nCreate account success!!!(Press any key to go main page)" << endl;
	_getch();

	main_display();
}
void user::login() {
	clear();
	cout << "\n\t\t\t -------------------------" << endl;
	cout << "\t\t\t|        Login Page       |" << endl;
	cout << "\t\t\t -------------------------" << endl;
	do {
		cout << "ID: ";
		cin >> id;
		cout << "Password: ";
		cin >> password;
		idNpass = id + " " + password;

		valid = check_account(idNpass);

		if (valid) {
			cout << "Login Success!!!(press any key to go " << id << "'s page)" << endl;
			_getch();
			account_page(id);
		}
		else {
			cout << "\t\t -----------------------------------------------------------" << endl;
			cout << "\t\t|        Invalid. Enter the correct ID & Password.          |" << endl;
			cout << "\t\t|  If you don't have ID, press 'y'. And create new account. |" << endl;
			cout << "\t\t|           You have ID, press any key without 'y'.         |" << endl;
			cout << "\t\t -----------------------------------------------------------" << endl;
			cout << "\nkey: ";
			cin >> buf;
			if (buf == 'y') {
				main_display();
			}
		}
	} while (!valid);
}
bool user::check_account(string idNpass) {
	ifstream AccountData;
	AccountData.open("account.txt");

	if (AccountData.is_open()) {
		while (getline(AccountData, account) && !valid) {
			if (account.compare(idNpass) == 0) {
				valid = true;
			}
		}
	}
	AccountData.close();

	if (valid) {
		return true;
	}
	else {
		return false;
	}
}
void user::account_page(string id) {
	clear();
	cout << "\n\t\t\t -------------------------" << endl;
	cout << "\t\t\t|        Hello, " << id << "        |" << endl;
	cout << "\t\t\t -------------------------" << endl;

	// Add mini game, sort function, calculation
}
void user::clear() {
	system("cls");
}

int main() {
	user *User = new user;
	User->main_display();
	delete User;
	return 0;
}