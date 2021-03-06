#include<iostream>  
#include <time.h>

using namespace std;

int c[33][33] = { 0 };
int bin[35];  //十进制n的二进制数  

void combinations()
{
	for (int i = 0; i <= 32; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (!j || i == j)
			{
				c[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
	}
	return;
}

void dec_to_bin(int n)
{
	bin[0] = 0;
	while (n)
	{
		bin[++bin[0]] = n % 2;
		n /= 2;
	}
	return;
}

int round(int n)
{
	int i, j;
	int sum = 0;
	dec_to_bin(n);

	/*计算长度小于bin[0]的所有二进制数中RN的个数*/

	for (i = 1; i < bin[0] - 1; i++)
	{
		for (j = i / 2 + 1; j <= i; j++)
		{
			sum += c[i][j];
		}
	}

	/*计算长度等于bin[0]的所有二进制数中RN的个数*/

	int zero = 0;  //从高位向低位搜索过程中出现0的位的个数  
	for (i = bin[0] - 1; i >= 1; i--)
	{
		if (bin[i])
		{
			for (j = (bin[0] + 1) / 2 - (zero + 1); j <= i - 1; j++)
			{
				sum += c[i - 1][j];
			}
		}
		else zero++;
	}
	return sum;
}

int test()
{
	/*
	clock_t start, finish;
	double totaltime;
	start = clock();
	*/

	combinations();
	int a, b;
	while (cin >> a >> b)
	{
		cout << round(b + 1) - round(a) << endl;

		/*
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;


		return 0;
		*/
		return 0;
	}




}

