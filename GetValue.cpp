#include "GetValue.h"

int GetValue(string s)
{
	int a;
	string temp;

	while (true)
	{
		while (true)
		{
			cout << s << endl;
			cout << "����: ";
			getline(cin, temp);
			try
			{
				a = stoi(temp);
			}
			catch (const std::exception&)
			{
				cout << "������: \"���� ������������ ��������\", ���������� �����" << endl;
				break;
			}
			return a;
		}
	}
}

int GetValue()
{
	int a;
	string temp;

	while (true)
	{
		while (true)
		{
			getline(cin, temp);
			try
			{
				a = stoi(temp);
			}
			catch (const std::exception&)
			{
				cout << "������: \"���� ������������ ��������\", ���������� �����" << endl;
				break;
			}
			return a;
		}

	}
}

string GetString(string message)
{
	string s;

	cout << message << endl;
	cout << "����: ";
	getline(cin, s);

	return s;
}

string GetString()
{
	string s;

	getline(cin, s);

	return s;
}

bool AskToRepeatFunction(string s)
{
	string choice;
	bool exitFunction = false;

	do
	{
		cout << s << endl;
		cout << "Y)��\nN)���\n" << endl;
		cout << "����: ";
		getline(cin, choice);
		if (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N")) {
			cout << "��� ������ ��������, ���������� ������ �������� �����!" << endl;
		}

	} while (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N"));

	if (choice == "n" || choice == "N") {
		exitFunction = true;
	}

	return exitFunction;
}
