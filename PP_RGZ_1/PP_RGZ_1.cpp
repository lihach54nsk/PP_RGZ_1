#include "pch.h"
#include <iostream>
#include <omp.h>
#include <chrono>
#include <Windows.h>

using namespace std; 

bool Prime(long long n)
{
	bool flag = true;
	const int koren = sqrt(n);

#pragma omp parallel for reduction(&&: flag)
	for (int i = 2; i <= koren; i++)
	{
		if (n % i == 0) flag = flag && false;		
	}
	Sleep(1);
	return flag;
}

int main()
{
	long long value;

	cout << "Write value: "; cin >> value;

	auto begin = chrono::high_resolution_clock::now();
	bool check = Prime(value);
	auto end = chrono::high_resolution_clock::now();

	if (check == true) cout << "Chislo " << value << " prostoe" << endl;
	else cout << "Chislo " << value << " ne prostoe" << endl;

	cout << "Work time: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;
}