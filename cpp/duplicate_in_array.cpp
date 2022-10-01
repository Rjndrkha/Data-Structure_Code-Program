#include <bits/stdc++.h>
using namespace std;

int findDuplicate(int *ar, int size)
{
	sort(ar,ar+size);
	for (int i = 0; i < size; i++)
	{
		if (ar[i]==ar[i+1])
		{
			return ar[i];
		}
	}
	return ;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cout << findDuplicate(input, size) << endl;
	}
	return 0;
}