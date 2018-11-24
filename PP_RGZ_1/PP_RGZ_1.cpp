#include "pch.h"
#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std;

int input[100000000];
int output[sizeof(input) / sizeof(int)];

bool Prime(long long n)
{
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i == 0)
			return false;
	return true;
}

void Calc()
{
	int j = 0;
	int size = sizeof(input) / sizeof(int);
#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		if (Prime(input[i]) == true) { output[j] = input[i]; j++; }
		else continue;
	}
}

int main()
{	

#pragma omp parallel
	{
		printf("Hello World\n");
	}
	/*
	for (int c = 1; c < 99999999; c++)
	{
		input[c - 1] = c;
	}

	auto begin = chrono::high_resolution_clock::now();
	Calc();
	auto end = chrono::high_resolution_clock::now();

	int i = 0;
	/*while (output[i] != 0)
	{
		cout << output[i] << endl;
		i++;
	}

	cout << "Work time: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;*/
}