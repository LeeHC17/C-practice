#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

void Main_menu();

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
};
void user::main_display() {
	system("cls");
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
		system("cls");
		cout << "\n\t\t\t --------------------------" << endl;
		cout << "\t\t\t|        Good Bye!!        |" << endl;
		cout << "\t\t\t --------------------------" << endl;
		exit(0);
	}
}
void user::create_account() {
	system("cls");
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
	system("cls");
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
	system("cls");
	cout << "\n\t\t\t --------------------------------" << endl;
	cout << "\t\t\t|          Hello, " << id << "         |" << endl;
	cout << "\t\t\t|    Press any key to go Main    |" << endl;
	cout << "\t\t\t --------------------------------" << endl;
	_getch();
	Main_menu();
}

class sort_page {
	int menu = 0;
	int num = 0;
	char buf = '\0';
	vector<int> a;
	vector<int> d;
public:
	void display();
	void Ascending(int array[], int n);
	void Descending(int array[], int n);
};
void sort_page::display() {
	cout << "\t\t\t ---------------------------------" << endl;
	cout << "\t\t\t|            Sort_page            |" << endl;
	cout << "\t\t\t|    Menu 1. Ascending            |" << endl;
	cout << "\t\t\t|    Menu 2. Descending           |" << endl;
	cout << "\t\t\t|    Menu 3. Back to main menu    |" << endl;
	cout << "\t\t\t ---------------------------------" << endl;

	do {
		cout << "\n\nEnter the menu (1 ~ 3): ";
		cin >> menu;
		if (menu < 1 || menu>3) {
			cout << "\nPlease choose the correct menu 1 ~ 3!!" << endl;
		}
	} while (menu < 1 || menu>3);

	if (menu == 3) { Main_menu(); }

	do {
		cout << "\nHow many numbers?: ";
		cin >> num;
		if (num < 0) {
			cout << "Please input the correct number!!!(more than '0')\n" << endl;
		}
	} while (num < 0);

	int* arr = new int[num];

	cout << "Input the array: ";
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	cout << "\nInput array is ";
	for (int i = 0; i < num; i++) { cout << arr[i] << " "; }

	if (menu == 1) {
		cout << "\n[ Ascending mode ]\n" << endl;
		Ascending(arr, num);
	}
	else if (menu == 2) {
		cout << "\n[ Descending mode ]\n" << endl;
		Descending(arr, num);
	}
	delete[]arr;
}
void sort_page::Ascending(int array[], int n) {
	a.clear();
	for (int i = 0; i < num; i++) { a.push_back(array[i]); }
	sort(a.begin(), a.end());
	cout << "Ascending array: ";
	for (int i = 0; i < num; i++) { cout << a[i] << " "; }
	cout << "\n\nGo back to Sort page with press any key" << endl;
	_getch();
	display();
}
void sort_page::Descending(int array[], int n) {
	d.clear();
	for (int i = 0; i < num; i++) { d.push_back(array[i]); }
	sort(d.begin(), d.end(), greater<int>());
	cout << "Descending array: ";
	for (int i = 0; i < num; i++) { cout << d[i] << " "; }
	cout << "\n\n Go back to Sort page with press any key" << endl;
	_getch();
	display();
}

class calculator_page {
	double d_num1 = 0.0, d_num2 = 0.0, d_res = 0.0;
	int type = 0, i_num1 = 0, i_num2 = 0, i_res = 0;
	char op = '\0';
	char key = '\0';
public:
	void display();
	double calculation(double n1, double n2, char op);
	int calculation(int n1, int n2, char op);
};
void calculator_page::display() {
	system("cls");
	cout << "\t\t\t ------------------------" << endl;
	cout << "\t\t\t|     Calculator page    |" << endl;
	cout << "\t\t\t|     Can use +,-,*,/    |" << endl;
	cout << "\t\t\t ------------------------" << endl;

	cout << "\nInput two number and operator(number1 operator number2)" << endl;

	while (true) {
		cout << "Choice the type. (1. Integer 2. Decimal): ";
		cin >> type;
		if (type == 1) {
			for (int i = 0; i < 3; i++) {
				cin >> i_num1 >> op >> i_num2;
				i_res = calculation(i_num1, i_num2, op);
				cout << "Result: " << i_res << endl;
			}
		}
		else if (type == 2) {
			for (int i = 0; i < 3; i++) {
				cin >> d_num1 >> op >> d_num2;
				d_res = calculation(d_num1, d_num2, op);
				cout << "Result: " << d_res << endl;
			}
		}
		else {
			cout << "Please choose the correct type!!!\n" << endl;
			continue;
		}
		cout << "Press any key without 'n' to continue calculation." << endl;
		cout << "Press 'n' to go Main menu." << endl;
		cout << "key: ";
		cin >> key;
		if (key == 'n') { break; }
		else if (key == 'n') { continue; }
	}
	Main_menu();
}
double calculator_page::calculation(double n1, double n2, char op) {
	switch (op) {
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '*':
		return n1 * n2;
	case '/':
		return n1 / n2;
	}
}
int calculator_page::calculation(int n1, int n2, char op) {
	switch (op) {
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '*':
		return n1 * n2;
	case '/':
		return n1 / n2;
	}
}


class game_page {
	int PlayerHP = 1000, PlayerAttack = 50, PlayerDefense = 10, Playerskillnum = 1;
	int MonsterHP = 1000, MonsterAttack = 25, MonsterDefense = 30, Monsterskillnum = 1;
	int PlayerAttackNum = 0, MonsterAttackNum = 0;
	char skilluse = '\0';
public:
	void display();
	void Player_skill(int* MonsHP, int* PlayHP);
};
void game_page::display() {
	system("cls");
	srand(time(NULL));
	cout << "\t\t\t ------------------------------------" << endl;
	cout << "\t\t\t|            Mini Game!!!            |" << endl;
	cout << "\t\t\t|         Player vs Monster          |" << endl;
	cout << "\t\t\t|      **Press any key to start**    |" << endl;
	cout << "\t\t\t ------------------------------------" << endl;
	_getch();
	system("cls");
	cout << "================ Player & Monster status ==============" << endl;
	cout << "= Player status: HP = " << PlayerHP << ", Attack = " << PlayerAttack << ", Defense = " << PlayerDefense << " =" << endl;
	cout << "= Monster status: HP = " << MonsterHP << ", Attack = " << MonsterAttack << ", Defense = " << MonsterDefense << "=" << endl;
	cout << "=======================================================" << endl;

	while (true) {
		PlayerAttackNum = rand() % 11 + 10;
		MonsterAttackNum = rand() % 11 + 10;

		if (PlayerHP > 0 || MonsterHP > 0) {
			_getch();
			cout << "\n\nPlayer Attck Number is " << PlayerAttackNum;
			for (int i = 0; i < PlayerAttackNum; i++) {
				MonsterHP -= (PlayerAttack - MonsterDefense);
				if (MonsterHP <= 0) { MonsterHP = 0; }
			}
			cout << "\nMonster HP is " << MonsterHP << endl;
			cout << "Player turn is over." << endl;

			_getch();

			cout << "\nMonster Attack Number is " << MonsterAttackNum;
			for (int i = 0; i < MonsterAttackNum; i++) {
				PlayerHP -= (MonsterAttack - PlayerDefense);
				if (PlayerHP <= 0) { PlayerHP = 0; }
			}
			cout << "\nPlayer HP is " << PlayerHP << endl;
			cout << "Monster turn is over." << endl;
		}
		if (PlayerHP < 300 && Playerskillnum == 1 && MonsterHP > 0) {
			cout << "\nPlayer HP is low!!" << endl;
			cout << "Player can use 'HP swap' skill !!" << endl;
			cout << "Use(y or n)? ";
			cin >> skilluse;
			if (skilluse == 'y') {
				Player_skill(&MonsterHP, &PlayerHP);
				Playerskillnum = 0;
			}
			cout << "Monster HP = " << MonsterHP << ", Player HP = " << PlayerHP << endl;
		}
		if (MonsterHP < 400 && Monsterskillnum == 1) {
			Monsterskillnum = 0;
			cout << "\nMonster HP is low!!" << endl;
			cout << "Monster can use 'Defense plus skill !!" << endl;
			cout << "Monster Defense increases randomly(5~10)" << endl;
			MonsterDefense += rand() % 6 + 5;
			cout << "Monster Defense is " << MonsterDefense << endl;
		}
		if (PlayerHP <= 0 || MonsterHP <= 0) {
			cout << "\nThe battle is over!" << endl;
			if (PlayerHP < MonsterHP) { cout << "\nMonster WIN !!!!!!!"; }
			else if (PlayerHP > MonsterHP) { cout << "\nPlayer WIN !!!!!!"; }
			break;
		}
	}
	cout << "\n\t\t\t -------------------------------" << endl;
	cout << "\t\t\t|           Game End            |" << endl;
	cout << "\t\t\t| Press any key to go Main menu |" << endl;
	cout << "\t\t\t -------------------------------" << endl;
	_getch();
	Main_menu();
}
void game_page::Player_skill(int* MonsHP, int* PlayHP) {
	int tmp = *MonsHP;
	*MonsHP = *PlayHP;
	*PlayHP = tmp;
}

int main() {
	user User;
	User.main_display();
	return 0;
}

void Main_menu() {
	system("cls");
	int menu = 0;

	cout << "\t\t\t ---------------------" << endl;
	cout << "\t\t\t|      Main menu      |" << endl;
	cout << "\t\t\t|   Menu 1. Sort      |" << endl;
	cout << "\t\t\t|   Menu 2. Calculator|" << endl;
	cout << "\t\t\t|   Menu 3. Mini game |" << endl;
	cout << "\t\t\t|   Menu 4. Logout    |" << endl;
	cout << "\t\t\t ---------------------" << endl;

	cout << "\nChoice the menu: ";
	cin >> menu;

	if (menu == 1) { 
		sort_page sort;
		sort.display(); 
	}
	else if (menu == 2) { 
		calculator_page calc;
		calc.display(); 
	}
	else if (menu == 3) { 
		game_page game;
		game.display(); 
	}
	else if (menu == 4) {
		user user;
		system("cls");
		cout << "\t\t\t ---------------" << endl;
		cout << "\t\t\t|    Logout!!   |" << endl;
		cout << "\t\t\t| Press any key |" << endl;
		cout << "\t\t\t ---------------" << endl;
		_getch();
		user.main_display();
	}
}
