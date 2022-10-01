// A template class for Matrix program

#include<iostream>
using namespace std;
template<class T>
class matrix
{
	int row, col;
	T **mat;
	public:
	matrix(int, int, int);
	matrix(const matrix<T> &);
    matrix<T> operator *(matrix<T> obj2);
	void display();
	~matrix();
};
template<class T>
matrix<T>::matrix(int a, int b, int flag):row(a), col(b)
{
		if(flag)
		{
			cout << endl << "Enter values for the matrix: " << endl;
			mat = new T *[row];
			for(int i = 0; i < row; i++)
			{
				mat[i] = new T [col];
				for(int j = 0; j < col; j++)
				{
					cout << "\nEnter value ( " << i+1 << ", " << j+1 << " )\n";
					cin >> mat[i][j];
				}
			}
		}
		else
		{
			mat = new T *[row];
			for(int i = 0; i < row; i++)
			{
				mat[i] = new T [col];
			}
		}
};
template<class T>
matrix<T>::matrix(const matrix<T> &obj)
{
	row = obj.row;
	col = obj.col;
	mat = new T*[row];
	for(int i = 0; i < row; i++)
	{
		mat[i] = new T [col];
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			mat[i][j] = obj.mat[i][j];
		}
	}
};
template<class T>
matrix<T> matrix<T>::operator *(matrix<T> matB)
{
	matrix<T> multi(row, matB.col, 0);
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < matB.col; j++)
		{
			multi.mat[i][j] = 0;
		}
	}
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < matB.col; j++)
		{
			for(int k = 0; k < col; k++)
			{
				multi.mat[i][j] += mat[i][k] * matB.mat[k][j];
			}
		}
	}
	return multi;
};
template<class T>
void matrix<T>::display()
{
	for(int i = 0; i < row; i++)
	{
		cout << endl;
		for(int j = 0; j < col; j++)
		{
			cout << mat[i][j] << " ";
		}
	}
	cout << endl;
};
template<class T>
matrix<T>::~matrix()
{
	cout << "dest" << endl;
	for(int i = 0; i  < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
};
int main()
{
    int row1, col1, row2, col2, choice = 0, isCompatible = 0;
	while (isCompatible != 1)
	{
		cout << "\nEnter dimensions for matrix 1: ";
		cin >> row1 >> col1;
		cout << "\nEnter dimensions for matrix 2: ";
		cin >> row2 >> col2;
		if (col1 == row2)	isCompatible = 1;
	}
	while (choice != 4)
	{
		cout << "\nUse\n1 -> Integer Matrix\n2 -> Float Matrix\n3 -> Enter new dimensions\n4 -> Exit\nEnter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			matrix<int> intMatA(row1, col1, 1);
			matrix<int> intMatB(row2, col2, 1);
			matrix<int> intMatC = intMatA * intMatB;
			cout << "\nMatrix 1:\n";
			intMatA.display();
			cout << "\nMatrix 2:\n";
			intMatB.display();
			cout << "\nResultant Matrix:\n";
			intMatC.display();
			break;
		}
		case 2:
		{
			matrix<float> intMatA(row1, col1, 1);
			matrix<float> intMatB(row2, col2, 1);
			matrix<float> intMatC = intMatA * intMatB;
			cout << "\nMatrix 1:\n";
			intMatA.display();
			cout << "\nMatrix 2:\n";
			intMatB.display();
			cout << "\nResultant Matrix:\n";
			intMatC.display();
			break;
		}
		case 3:
		{
			isCompatible = 0;
			while (isCompatible != 1)
			{
				cout << "\nEnter dimensions for matrix 1: ";
				cin >> row1 >> col1;
				cout << "\nEnter dimensions for matrix 2: ";
				cin >> row2 >> col2;
				if (col1 == row2)	isCompatible = 1;
				else	cout << "\nInvalid dimensions.\nPlease input dimensions again.\n";

			}
			break;
		}
		case 4:
		{
            return 0;
			break;
		}
		default:
			cout << "\nInvalid Choice.\n";
			break;
		}
	}
}
