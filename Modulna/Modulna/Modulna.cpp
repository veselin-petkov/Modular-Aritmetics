#include <iostream>
#include "Functions.h"

using namespace std;


int main() {

	int *arr = nullptr;
	unsigned n,r;
	int **arr1 = NULL;
	int a, b;
	cout << "Vuvedete razmera na Zn: ";
	cin >> n;
	arr = new int[n];
	do
	{
		cout << "Izberete zadacha ili vuvedete 0 za izhod:";
		cin >> r;
		switch (r)
		{
		case 1:
			FillArray(arr, n);
			cout << "Purva:";
			for (size_t i = 0; i < n; i++)
			{
				cout << arr[i];
			}
			cout << endl;
			break;
		case 2:
			cout << "Vtora:\n";
			cout << "Vuvedete purvoto chislo:";
			cin >> a;
			cout << "Vuvedete vtoroto chislo:";
			cin >> b;
			cout << "Otgovor:" << Sum(a, b, n) << endl;
			break;
		case 3:
			cout << "Treta:\n";
			
			cout << "Vuvedete purvoto chislo:";
			cin >> a;
			cout << "Vuvedete vtoroto chislo:";
			cin >> b;
			cout << Diffrence(a, b, n) << endl;
			break;
		case 4:
			cout << "Chetvurta:\n";
			cout << "Vuvedete purvoto chislo:";
			cin >> a;
			cout << "Vuvedete vtoroto chislo:";
			cin >> b;
			cout << Mult(2, 5, n) << endl;
			break;
		case 5:
			cout << "Peta:" << endl;
			Double(arr1, n);
			break;
		case 6:
			cout << "Shesta:\n";
			Recip(arr1, n);
			break;
		case 7:
			cout << "Sedma:\n";
			cout << "Vuvedete chislo:";
			cin >> a;
			cout << Evklid(a, n) << endl;
			break;
		case 8:
			cout << "Osma:\n";
			cout << "Vuvedete purvoto chislo:";
			cin >> a;
			cout << "Vuvedete vtoroto chislo:";
			cin >> b;
			cout<< Divide(a, b, n) << endl;
			break;
		case 9:
			cout << "Deveta: \n";
			cout << "Vuvedete a:";
			cin >> a;
			cout << "Vuvedete m:";
			cin >> b;
			cout << Pow(a, b, n) << endl;

			break;
		case 10:

			cout << "Deseta:\n"; 
			cout << "Vuvedete a:";
			cin >> a;
			cout << "Vuvedete m:";
			cin >> b;
			cout << fast_power(3, 100, n) << endl;
			break;
		case 11:
			cout << "11-ta:";
			if (Pole(n)) {
				cout << "Tova e ostatuchno pole." << endl;
			}
			else cout << "Tova ne e ostatuchno pole." << endl;
			break;
		case 12:
			cout << "12-ta:\n";
			if (Pole(n)) {
				cout << "Vuvedete chislo:";
				cin >> a;
				(rootInFN(a, n));
			}
			else {
				cout << "Tova ne e ostatuchen pole!\n";
			}
			break;
		case 13:
			Koreni(arr1, n);
			break;
		case 14:
			cout << "Vuvedete osnova:\n";
			cin >> a;
			cout << "Vuvedete element ot Fn:\n";
			cin >> b;
			runLogOperation(a, b, n);
			cout << endl;
			break;
		}
	} while (r!=0 ||(r>0 && r<15));
	
	delete[] arr;
	delete[] arr1;
	return 0;
}