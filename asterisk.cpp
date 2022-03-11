#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	int input; 			
	int a, b, c;		

	cout << "input Number : ";
	cin >> input;		

	cout << endl << "Prob 02" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = input - a; b > 0; b--)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << endl << "Prob 03" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = 0; b < input - (a + 1); b++)
		{
			cout << " ";
		}
		for (c = 0; c <= a; c++)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << endl << "Prob 04" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = 0; b < a; b++)
		{
			cout << " ";
		}
		for (c = 0; c < input - a; c++)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << endl << "Prob 05" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = 0; b < input - (a + 1); b++)
		{
			cout << " ";
		}
		for (c = 0; c < (2 * a) + 1; c++)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << endl << "Prob 06" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = 0; b < a; b++)
		{
			cout << " ";
		}
		for (c = 0; c < (input - (a + 1)) * 2 + 1; c++)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << endl << "Prob 07" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = 0; b <= a; b++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (a = 0; a < input - 1; a++)
	{
		for (b = input - (a + 1); b > 0; b--)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << endl << "Prob 08" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = 0; b < input - (a + 1); b++)
		{
			cout << " ";
		}
		for (c = 0; c <= a; c++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (a = 0; a < input - 1; a++)
	{
		for (b = 0; b < a + 1; b++)
		{
			cout << " ";
		}
		for (c = 0; c < input - (a + 1); c++)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << endl << "Prob 09" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = 0; b < input - (a + 1); b++)
		{
			cout << " ";
		}
		for (c = 0; c < (2 * a) + 1; c++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (a = 0; a < input - 1; a++)
	{
		for (b = 0; b < a + 1; b++)
		{
			cout << " ";
		}
		for (c = 0; c < (input - (a + 2)) * 2 + 1; c++)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << endl << "Prob 10" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = 0; b < a; b++)
		{
			cout << " ";
		}
		for (c = 0; c < (input - (a + 1)) * 2 + 1; c++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (a = 0; a < input - 1; a++)
	{
		for (b = 0; b < input - (a + 2); b++)
		{
			cout << " ";
		}
		for (c = 0; c < (2 * (a + 1)) + 1; c++)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << endl << "Prob 11" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = 0; b < a; b++)
		{
			cout << " ";
		}
		for (b = 0; b < input - a; b++)
		{
			cout << "*";
		}
		for (c = 0; c < input - (a + 1); c++)
		{
			cout << " ";
		}
		for (c = 0; c <= a; c++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (a = 0; a < input; a++)
	{
		for (b = input - a; b > 0; b--)
		{
			cout << "*";
		}

		for (b = 0; b < a; b++)
		{
			cout << " ";
		}
		for (b = 0; b <= a; b++)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << endl << "Prob 12" << endl;

	for (a = 0; a < input; a++)
	{
		for (b = 0; b <= a; b++)
		{
			cout << "*";
		}

		for (b = 0; b < input - (a + 1); b++)
		{
			cout << " ";
		}

		for (b = input - a; b > 0; b--)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (a = 0; a < input; a++)
	{
		for (b = 0; b < input - (a + 1); b++)
		{
			cout << " ";
		}
		for (b = 0; b <= a; b++)
		{
			cout << "*";
		}

		for (c = 0; c < a; c++)
		{
			cout << " ";
		}
		for (c = 0; c < input - a; c++)
		{
			cout << "*";
		}
		cout << endl;
	}
}