#include "matrix_multiplication.h"
#include <Windows.h>
#include <smmintrin.h>
#include <iostream>
using namespace std;

int main()
{
	_int64 ctr1 = 0, ctr2 = 0, freq = 0;

	static float A[size][size], B[size][size], S[size][size];
	
	// initialize arrays
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			A[i][j] = 0.0;
			B[i][j] = 0.0;
			S[i][j] = 0.0;
		}
	}

	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0)
	{
		matrix_multiplication(A, B, S);		// call function
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);

		cout << "Start Value:" << ctr1 << endl;
		cout << "End Value:" << ctr2 << endl;

		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

		cout << "QueryPerformanceCounter minimum resolution: 1/" << freq << "Seconds," << endl;
		cout << size << "x" << size << " Maxtrix Multiplication: " << ((ctr2 - ctr1)* 1.0 / freq) * 1000000 << "Microseconds." << endl;
	}
	else
	{
		DWORD dwError = GetLastError();
		cout << "Error value" << dwError << endl;
	}
	system("PAUSE");
	
	return 0;
}

