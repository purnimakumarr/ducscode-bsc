//Diagonal Matrix using one-dimensional array.

#include<iostream>
#include<stdlib.h>

using namespace std;

void print()
{
	cout << endl;
	for (int i = 0; i <= 119; i++)
		cout << "-";
	cout << endl;
}

class diagonal_matrix
{
	int *d;

public:
	diagonal_matrix(int);
	void insert(int, int, int);
	int retrieval(int, int);
	void show(int, int);
	~diagonal_matrix();
};

//constructor
diagonal_matrix::diagonal_matrix(int size=10)
{
	if (size != 0)
		d = new int[size];
	else
		d = 0;
}
void diagonal_matrix::insert(int data, int m , int n)
{
	d[m] = data;
}

void diagonal_matrix::show(int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				cout << d[i] << "\t";
			else
				cout << "0" << "\t";
		}

		cout << endl;
	}
}

int diagonal_matrix::retrieval(int m, int n)
{
	if (m == n)
		return d[m];
	else
		return 0;
}

//destructor
diagonal_matrix::~diagonal_matrix()
{
	delete []d;
}
int main()
{
	char ch; int m, n, data, x, y;

	cout << "Enter size of matrix :-\n";
	cout << "m : ";
	cin >> m;
	cout << "n : ";
	cin >> n;

	if (m != n)
	{
		cout << "Invalid size.";
		exit(0);
	}

	diagonal_matrix obj(m);

	do
	{
		system("cls");
		print();
		cout << "\t\t\t\t\t\t\tDIAGONAL MATRIX";
		print();
		cout << "\n1. Enter Matrix";
		cout << "\n2. Print Matrix";
		cout << "\n3. Retrieve A Value";
		cout << "\n\nEnter choice : ";
		cin >> ch;

		cout << endl;

		switch(ch)
		{
		case'1': if (m!= 0)
				{
					cout << "Enter diagonal elements :-\n";
					for (int i = 0; i < m; i++)
					{
						cout << "Enter data : ";
						cin >> data;
						obj.insert(data, i, i);
					}
				}
			   else
			   {
					cout << "\nMatrix size entered is zero.";
					exit(0);
			   }
			break;

		case '2': cout << "Diagonal Matrix :-\n";
			obj.show(m ,n);
			break;

		case '3': cout << "Enter index whose value you want to retrieve :-\n";
			cout << "x : ";
			cin >> x;
			cout << "y : ";
			cin >> y;
			if (x<0 || y<0 ||x>m || y>n)
				cout << "Index out of range.";
			else
				cout << "\nRetrieved Value : " << obj.retrieval(x, y);
			break;
			
		default: cout << "Invalid Input.";
		}
		cout << "\nDo you want to continue? : ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	return 0;
}
