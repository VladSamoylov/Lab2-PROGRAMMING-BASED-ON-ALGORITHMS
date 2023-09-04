#include "iostream"
#include "windows.h"
#include "conio.h"

using namespace std;

/**
 * @brief Перевіряє коректне значення, яке ввів користувач до системи
 * @param i Значення введене з клавіатури
 * @return Повертає коректне значення для подальшої роботи системи
*/
int CheckIntValue(int i) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cout << "You enter wrong data! Please enter correct data: \n";
			cin >> i;
		}
		else {
			return i;
		}
	}
}

/**
 * @brief Перевіряє коректне значення символа, яке ввів користувач
 * @param symbol Символ введений з клавіатури
 * @return Повертає коректний символ до системи
*/
char CheckCharValue(char symbol) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cout << "You enter wrong data! Please enter correct data: \n";
			cin >> symbol;
		}
		else {
			return symbol;
		}
	}
}

/**
 * @brief Виводить у відповідь на введений користувачем символ його код
 * @param symbol Символ який необхідно обробити
*/
void OutputResponseUserCodeOfCharacter(char symbol) {

	int code;

	while (true) {
		code = int(symbol);
		cout << "Code of character is: " << code << endl;
		Sleep(1000);
		if (_kbhit()) {
			if (_getch() == 13) {
				break;
			}
		}
	}
}

/**
 * @brief Інтерфейс який дає змогу користувачу працювати з додатком
 * @param q Вибір виконуваного завдання, яке задається користувачем з клавіатури
 * @return Повертає саме себе для продовження роботи користувача з додатком
*/
int MenuOfSolution(int q) {

	switch (q) {
	case 1:
		
		break;
	case 2:
		char symbol;

		cout << "Enter symbol to get the code of character" << endl;
		cin >> symbol;
		symbol = CheckCharValue(symbol);
		OutputResponseUserCodeOfCharacter(symbol);
		break;
	case 3:
		
		break;
	case 4:
		
		break;
	default:
		cout << "You don't enter any task for execution\n";
		return 0;
	}
	return MenuOfSolution(q);
}

int main() {

	int q;
	cout << "\nCreated by Vladislav Samoilov / KNT - 223\n";

	cout << "--------Select task:--------\n";
	cout << "Task A) Calculate The Expressions Of M And P - Enter 1\n";
	cout << "Task B) Calculate Func For Real Number - Enter 2\n";
	cout << "Task C) Calculate Angle Of Minutes And Time - Enter 3\n";
	cout << "Task G) Natural Number Is Multiple Of Three Or Four - Enter 4\n";
	cout << "------------------------------------------------------------\n";
	cin >> q;
	q = CheckIntValue(q);
	MenuOfSolution(q);

	return main();
}