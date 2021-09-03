#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <string>
#include "Functions.h"


int FillArray(int*arr, unsigned sz) {
	for (size_t i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
	return 0;
}
int Sum(int a, int b, unsigned n) {
	int sum = a + b;
	return sum % n;
}
int Diffrence(int a, int b, unsigned n) {
	int diff = a - b;
	//return diff;
	if (diff > 0) return diff % n;
	else return (diff+n) % n;
}
int Mult(int a, int b, unsigned n) {//zad 4
	int mult = a * b;
	return mult % n;
}
int confLog(int a, int b, int n) {
	unsigned m = -1;
	for (unsigned i = 0; i < n; i++) {
		if ((int)pow(a, i) % n == b) {
			m = i;
		}
	}
	return m;
}
int Double(int ** arr1, unsigned sz) {//zad5
	int cnt = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if ((i * j) % sz == 1)
			{

				cnt++;
			}
		}
	}
	arr1 = new int*[cnt];
	for (size_t i = 0; i < cnt; i++)
	{
		arr1[i] = new int[2];
	}
	cnt = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if ((i * j) % sz == 1)
			{
				arr1[cnt][0] = i;
				arr1[cnt][1] = j;
				cnt++;
			}
		}
	}
	for (size_t i = 0; i < cnt; i++)
	{
		//std::cout << arr1[i][0] << "*" << arr1[i][1] << "=1" << std::endl;
		std::cout << arr1[i][0] << "\t";

	}
	std::cout << "\n";
	for (size_t i = 0; i < cnt; i++)
	{
		std::cout << arr1[i][1] << "\t";
	}
	std::cout << "\n";

		return 0;
}
int Recip(int** arr1, unsigned sz) {
	int cnt = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if ((i * j) % sz == 1)
			{

				cnt++;
			}
		}
	}
	arr1 = new int*[cnt];
	for (size_t i = 0; i < cnt; i++)
	{
		arr1[i] = new int[2];
	}
	cnt = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if ((i * j) % sz == 1)
			{
				arr1[cnt][0] = i;
				arr1[cnt][1] = j;
				cnt++;
			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		std::cout << "1/" << arr1[i][0] << " " << arr1[i][1] << "\n";

	}
	return 0;
}
int Evklid(int a, int b) {//zad7 

	unsigned br = 0;
	int result = -1;
	unsigned x = (abs(a) > abs(b)) ? abs(a) : abs(b);
	unsigned y = (abs(a) < abs(b)) ? abs(a) : abs(b);

	unsigned r = x % y;

	while (r != 0) {
		br++;
		x = y;
		y = r;
		r = x % y;
	}
	if (br > 0) {
		br += 2;
		int ** arr = nullptr;
		arr = new int *[4];
		for (size_t i = 0; i < 4; i++) {
			arr[i] = new int[br];
		}

		x = (abs(a) > abs(b)) ? abs(a) : abs(b);
		y = (abs(a) < abs(b)) ? abs(a) : abs(b);
		arr[0][0] = x;
		arr[0][1] = y;
		arr[1][0] = 0;
		arr[2][0] = 1;
		arr[2][1] = 0;
		arr[3][0] = 0;
		arr[3][1] = 1;

		r = x % y;
		unsigned i = 2;
		while (r != 0) {
			arr[1][i - 1] = x / y;
			arr[0][i++] = r;
			x = y;
			y = r;
			r = x % y;
		}

		arr[1][i - 1] = x / y;
		for (size_t j = 2; j < br; j++) {
			arr[2][j] = arr[1][j - 1] * arr[2][j - 1] + arr[2][j - 2];
			arr[3][j] = arr[1][j - 1] * arr[3][j - 1] + arr[3][j - 2];
		}

		result = pow(-1, br) * arr[3][br - 1];
		if (result < 0)
			result = result + b;
		

		for (size_t i = 0; i < 4; i++) {
			delete[]arr[i];
		}
		delete[]arr;
		arr = nullptr;
	}

	return result;
}


int Divide(int a, int b, unsigned n) {//zad8
	int number = Evklid(b, n);
	if (number == -1) return -1;
	return Mult(a, number, n);
}

	long long int Pow(int a, int b, unsigned n) { //zad 9
	int k=1, j = 1;
	do 
	{
		j++;
		k = a * (int)pow(a, j - 1) % n;

	} while (k!=1);
	int s = b % j;
	int m = (int)pow(a, s) % n;
	return m;
}

	int PowBinary(int a, int b, unsigned n) { //zad 10
		int  arr[64];
		long long int  j = 1, k = 0, sum = 0, t = 0;

		int i = 0, r;
		while (b != 0)
		{
			r = b % 2;
			arr[i++] = r;
			b /= 2;
		}
		for (int l = i - 1 ; l >= 0; l--){
			//std::cout << arr[l];
	//	std::string t = std::bitset<8>(b).to_string();

		for (size_t r = 2; r < 65; r *= 2)
		{
			if (arr[l] == 1)
			{
				int i = r / 2;
				//std::cout << i << " r/2 ";
				k = (unsigned long long int)pow(a, i);
				//std::cout << k << " ";
				if (i >= 2)
				{
					sum = ((unsigned long long int)pow(k, 1)) % n;
					t = ((unsigned long long int)pow(sum, 2)) % n;
					//std::cout << t << " ";
					j *= (unsigned long long int)pow(t, 2);
				}
			}
			}
		}
		return j % n;
	}
	
	int stepen2(int n, int a, int m) {
		long long int  j = 1, k = 0, sum = 0, t = 0;

		if (m != 0) {
			long long int q = 0;
			while (m > 0) {
				q = 0;
				while (pow(2, q) <= m) {
					q++;
				}
				q--;
				//for (size_t r = 2; r < 65; r *= 2)
				//{
					int i = q / 2;
					//std::cout << i << " r/2 ";
					k = (unsigned long long int)pow(a, q);
					//std::cout << k << " ";
						sum = ((unsigned long long int)pow(k, 1)) % n;
						t = ((unsigned long long int)pow(sum, 2)) % n;
						//std::cout << t << " ";

						j *= (unsigned long long int)pow(t, 2);
					//}
			}
			return j;
		}
		else {
			return 1;
		}
	}
	long long fast_power(long long base, long long power,unsigned n) {
		long long result = 1;
		while (power > 0) {

			if (power % 2 == 1) {
				result = (result*base) % n;
			}
			base = (base * base) % n;
			power = power / 2; 
		}
		return result;
	}


	bool Pole(int n) {//zad11
		for (int i = 2; i <= n / 2; ++i)
		{
			if (n % i == 0) return false;
			else return true;
		}

	}

	int rootInFN(int a,unsigned n) {//zad12
			int*arr = new int[n - 1];
			int cnt = 0;
			for (size_t i = 1; i < n; i++)
			{
				arr[cnt] = pow(a, i);
				arr[cnt] = arr[cnt] % n;
				cnt++;
			}
			//std::sort(arr, arr + n - 1);
			bool f = true;
			for (size_t i = 1; i < n; i++)
			{
				if (arr[i - 1] != i)
				{
					f = false;
					break;
				}
			}
			if (f)
			{
				std::cout << a << " e primitiven koren vuv F(n)\n";
			}
			else
			{
				std::cout << a << " ne e primitiven koren vuv F(n)\n";
			}
			return 0;	
	}
	void Koreni(int** roots, int n) {//zad13
		int res;
		roots = new int*[n];
		for (unsigned i = 0; i < n; i++)
			roots[i] = new int[n];
		if (Pole(n)) {
			std::cout << "Primitivni koreni v ostatuchnoto pole Fn(" << n << ")\n" ;
			for (unsigned i = 1; i < n; i++) {
				std::cout << "\t";
				for (unsigned j = 1; j < n; j++) {
					res = (int)pow(i, j) % n;
					roots[i][j] = res;
					std::cout << "  " << res;
				}
				std::cout << std::endl;
			}
		}
		else {
			std::cout << "stoinosta na n ne e prosto chislo. Zn ne e ostatuchno pole.";
		}
	}
	void runLogOperation(unsigned a,unsigned b,unsigned n) {
	
		int c;
	

		if (a > n - 1) {
			std::cout << "stoinosta na 'a' " << a << " ne e chast ot prustena\n";
			runLogOperation(a, b, n);
			return;
		}


		if (b > n - 1) {
			std::cout << "stoinosta na 'b' " << a << " ne e chast ot prustena\n";
			runLogOperation(a, b, n);
			return;
		}
		c = confLog(a, b, n);
		if (c > -1) {
			std::cout << c;
		}
		else {
			std::cout << c;
		}
	}
