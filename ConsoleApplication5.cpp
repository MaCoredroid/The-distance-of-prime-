// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <math.h>
int main()
{
	int64_t M = 0;
	int64_t N = 0;
	std::cin >> M;
	std::cin >> N;
	int distance = 0;
	int64_t a1 = 0;
	bool flag1 = 0;
	bool flag2 = 0;
	int64_t a2 = 0;
	a2 = sqrt(N);
	
	if (M < 2)
	{
		M = 2;
	}
	if (N - M < 1)
	{
		std::cout << 0;
		return 0;
	}
	if (M == 2 && N == 3)
	{
		std::cout << 1;
		return 0;
	}
	std::vector<int64_t>prime;
	int primesize = 0;
	std::vector<bool>num(a2+ 2, 0);
	std::vector<bool>num1(N - M + 1, 0);
	num[0] = 1;
	num[1] = 1;

	for (int n = 2; n < sqrt(a2)+1; n++)
	{
			if (num[n] == 0)
			{
				prime.push_back(n);
				primesize++;
			}
			for (int i = 0; i < primesize && n*prime[i] <= a2+1; i++)
			{
				num[n*prime[i]] = 1;
				if (n%prime[i] == 0)
				{
					break;
				}

			}
			


	}
	for (int64_t n = 2; n <= a2+1; n++)
	{
		if (num[n] == 0)
		{
			for (int64_t i = M / n - 1; i <= N / n + 1; i++)

			{

				if (n*i >= M && n*i <= N)
				{
					num1[n*i - M] = 1;
				}

			}
		}

	}
	
	for (int64_t q = M; q <= N; q++)
	{
	            if (num1[q-M]==1)
		        {
					
					flag2 = 1;
				}

				if (q >= 2 && flag2 == 0)
				{
					if (flag1 == 0)
					{
						flag1 = 1;
						a1 = q;
					}
					if (flag1 == 1 && (q - a1) > distance)
					{
						distance = q - a1;
					}
					a1 = q;
				}
				flag2 = 0;
	}
	std::cout << distance;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
