#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<conio.h>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
using namespace std;

void Main_menu();

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
	friend void Main_menu();
};

void sort_page::display() {
	system("cls");
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
	double num1 = 0.0, num2 = 0.0, res = 0.0;
	char op = '\0';
	char key = '\0';
public:
	friend void Main_menu();
	void display();
	double calculation(double n1, double n2, char op);
};

void calculator_page::display() {
	system("cls");
	cout << "\t\t\t ------------------------" << endl;
	cout << "\t\t\t|     Calculator page    |" << endl;
	cout << "\t\t\t|     Can use +,-,*,/    |" << endl;
	cout << "\t\t\t ------------------------" << endl;
	
	cout << "\nInput two number and operator(number1 operator number2)" << endl;
	
	while (true) {
		for (int i = 0; i < 3; i++) {
			cin >> num1 >> op >> num2;
			res = calculation(num1, num2, op);
			cout << "Result: " << res << endl;
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
	switch(op){
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
	int MonsterHP = 1000, MonsterAttack = 20, MonsterDefense = 30, Monsterskillnum = 1;
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
			}
			cout << "\nMonster HP is " << MonsterHP << endl;
			cout << "Player turn is over." << endl;

			_getch();

			cout << "\nMonster Attack Number is " << MonsterAttackNum;
			for (int i = 0; i < MonsterAttackNum; i++) {
				PlayerHP -= (MonsterAttack - PlayerDefense);
			}
			cout << "\nPlayer HP is " << PlayerHP << endl;
			cout << "Monster turn is over." << endl;
		}
		if (PlayerHP < 300 && Playerskillnum ==1) {
			cout << "\nPlayer HP is low!!" << endl;
			cout << "Player can use 'HP swap' skill !!" << endl;
			cout << "Use(y or n)? ";
			cin >> skilluse;
			if(skilluse == 'y'){ 
				Player_skill(&MonsterHP, &PlayerHP);
				Playerskillnum = 0;
			}
			cout << "Monster HP = " << MonsterHP << ", Player HP = " << PlayerHP << endl;
		}
		if (MonsterHP < 300 && Monsterskillnum == 1) {
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

void Main_menu() {
	system("cls");
	int menu = 0;
	sort_page sort;
	calculator_page calc;
	game_page game;

	cout << "\t\t\t ---------------------" << endl;
	cout << "\t\t\t|      Main menu      |" << endl;
	cout << "\t\t\t|   Menu 1. Sort      |" << endl;
	cout << "\t\t\t|   Menu 2. Calculator|" << endl;
	cout << "\t\t\t|   Menu 3. Mini game |" << endl;
	cout << "\t\t\t|   Menu 4. Logout    |" << endl;
	cout << "\t\t\t ---------------------" << endl;

	cout << "\nChoice the menu: ";
	cin >> menu;

	if (menu == 1) { sort.display(); }
	else if (menu == 2) { calc.display(); }
	else if (menu == 3) { game.display(); }
	else if (menu == 4) {
		system("cls");
		cout << "\t\t\t ---------------" << endl;
		cout << "\t\t\t|    Logout!!   |" << endl;
		cout << "\t\t\t ---------------" << endl;
		exit(0);
	}
}

int main() {
	Main_menu();
}