#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;


int findIndex(vector<int>y, int value) {
	for (int i = 0; i < y.size(); i++)
	{
		if (y[i] == value) { return i; }
	}
	return -1;
}


int main()
{
	//input===============
	int n;
	cin >> n;


	vector<int> x(n);
	vector<int> y(n);


	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}




	//check===============

	int result = 0;
	int max = 0;
	int selectY = -1;


	for (int i = 0; i < n; i++)
	{
		cout << "i=" << i << " ";
		max = 0;

		selectY = -1;

		//right===========
		for (int j = i + 1; j < n; j++)
		{

			if (y[j] < y[i])
			{
				selectY = j;
			}
			else { break; }
		}




		//stack에 남아있는 2개의 수의 차를 구하면 max이다.
		if (selectY != -1)
		{

			//stack.pop()에 해당하는 값의 Y에서 인덱스 값을 구한다.
			int firstIndex = selectY;
			int secondIndex = i;
			max = abs(x[firstIndex] - x[secondIndex]);

		}


		selectY = -1;
		//left===========
		for (int k = i - 1; k > 0; k--)
		{
			if (y[k] < y[i])
			{
				selectY = k;
			}
			else { break; }
		}


		//stack에 남아있는 2개의 수의 차를 구하면 max이다.
		if (selectY != -1)
		{
			//stack.pop()에 해당하는 값의 Y에서 인덱스 값을 구한다.
			int firstIndex = selectY;
			int secondIndex = i;

			if (abs(x[firstIndex] - x[secondIndex]) > max)
			{
				max = abs(x[firstIndex] - x[secondIndex]);
			}
		}



		cout << "max=" << max << " \n";
		result += max;

	}



	cout << "\nresult=" << result;


}