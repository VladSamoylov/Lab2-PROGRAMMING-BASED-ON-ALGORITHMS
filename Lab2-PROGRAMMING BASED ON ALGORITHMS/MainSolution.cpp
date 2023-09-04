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

float CheckFloatValue(float i) {

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
 * @brief Перевіряє чи є число простим
 * @param n Число, яке потрібно перевірити
 * @return Повертає true або false перевіренного числа
*/
bool CheckSimpleNumber(int n) {
	
	if (n <= 1) {
		return false;
	}
	if (n <= 3 && n > 1) {
		return true;
	}
	if (n % 2 == 0 || n % 3 == 0) {
		return false;
	}
	for (int i = n-1; i > 1; i--) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

/**
 * @brief Виводить 5 простих чисел, які більші за те число, яке ввів користувач
 * @param n Число яке ввів користувач
*/
void OutputFiveSimpleBigestNumbers(int n) {

	int simple_number = 1;

	n = n + 1;
	do {
		if (CheckSimpleNumber(n)) {
			cout << "Simple number #" << simple_number << ": " << n << endl;
			simple_number++; 
		}
		n++;
	} while (simple_number != 5);	
}

void CalculateMinOfOddOnesMaxPairs(int n) {
	float min = 10000000, max = -100000000, number;

	for (int i = 1; i < n+1; i++) {
		cout << "Enter #" << i << " sequence member: ";
		cin >> number;
		if (i % 2 == 0) {
			if (max < number) {
				max = number;
			}
		}
		else {
			if (min > number) {
				min = number;
			}
		}
	}
	cout << "Amount min and max value: " << min + max << endl;
}

/**
 * @brief Інтерфейс який дає змогу користувачу працювати з додатком
 * @param q Вибір виконуваного завдання, яке задається користувачем з клавіатури
 * @return Повертає саме себе для продовження роботи користувача з додатком
*/
int MenuOfSolution(int q) {

	switch (q) {
	case 1:
		int k;
		
		cout << "\nEnter amount sequence members: ";
		cin >> k;
		k = CheckIntValue(k);
		while (true) {
			if (k <= 0) {
				cout << "Enter correct amount sequence members (must be > 0): ";
				cin >> k;
				k = CheckIntValue(k);
			}
			else {
				break;
			}
		}
		CalculateMinOfOddOnesMaxPairs(k);
		break;
	case 2:
		char symbol;

		cout << "Enter symbol to get the code of character: " << endl;
		cin >> symbol;
		symbol = CheckCharValue(symbol);
		OutputResponseUserCodeOfCharacter(symbol);
		break;
	case 3:
		int n;

		cout << "Enter N: ";
		cin >> n;
		n = CheckIntValue(n);
		OutputFiveSimpleBigestNumbers(n);
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
	cout << "Task B) Output response cod of symbol - Enter 2\n";
	cout << "Task C) Output 5 simple numbers bigger then user enter - Enter 3\n";
	cout << "Task G) Natural Number Is Multiple Of Three Or Four - Enter 4\n";
	cout << "------------------------------------------------------------\n";
	cin >> q;
	q = CheckIntValue(q);
	MenuOfSolution(q);	
	
	return main();
}