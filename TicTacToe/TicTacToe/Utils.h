#pragma once
#include <iostream>

using namespace std;

template<class T>
T AskInput(string msg, string errMsg)
{
	T result;

	do
	{
		if (cin.fail())
		{
			cout << errMsg << endl;
			cin.clear();
			cin.ignore(1i64, '\n');
		}

		cout << msg << endl;
		cin >> result;
	} while (cin.fail());

	cin.ignore(INT_MAX, '\n');
	return result;
}

PlayerTeam GetOppositeTeam(PlayerTeam team);