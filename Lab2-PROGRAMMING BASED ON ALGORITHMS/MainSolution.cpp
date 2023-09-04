#include "iostream"
#include "windows.h"
#include "conio.h"

using namespace std;

/**
 * @brief �������� �������� ��������, ��� ��� ���������� �� �������
 * @param i �������� ������� � ���������
 * @return ������� �������� �������� ��� �������� ������ �������
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
 * @brief �������� �������� �������� �������, ��� ��� ����������
 * @param symbol ������ �������� � ���������
 * @return ������� ��������� ������ �� �������
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
 * @brief �������� � ������� �� �������� ������������ ������ ���� ���
 * @param symbol ������ ���� ��������� ��������
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
 * @brief ��������� ���� �� ����� ����������� ��������� � ��������
 * @param q ���� ������������ ��������, ��� �������� ������������ � ���������
 * @return ������� ���� ���� ��� ����������� ������ ����������� � ��������
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