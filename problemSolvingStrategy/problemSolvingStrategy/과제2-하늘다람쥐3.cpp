#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

vector<int> x;
vector<int> y;

int findIndex(int value) {
	for (int i = 0; i < y.size(); i++)
	{
		if (y[i] == value) { return i; }
	}
	return -1;
}


int main()
{
	//input
	int n;
	cin >> n;


	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		x.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		y.push_back(num);
	}




	//check
	stack<int>stack;

	int result = 0;
	int max = 0;


	for (int i = 0; i < n; i++)
	{
		stack.push(y[i]);

		//right===========
		for (int j = i + 1; j < n; j++)
		{

			if (y[j] < y[i])
			{
				if (stack.size() != 1) {
					stack.pop();
				}
				stack.push(y[j]);
			}
			else { break; }


		}

		//stack에 남아있는 2개의 수의 차를 구하면 max이다.
		if (stack.size() ==2) 
		{
			//stack.pop()에 해당하는 값의 Y에서 인덱스 값을 구한다.
			int firstIndex=findIndex(stack.top());
			stack.pop();
			int secondIndex=findIndex(stack.top());
			stack.pop();
			max = abs(x[firstIndex]-x[secondIndex]);

		}
		else { max = 0; }



		while (stack.size() != 0) { stack.pop(); }

		//left===========
		for (int k = 0; k < i; k++)
		{
			if (y[k] < y[i])
			{
				if (stack.size() != 1) {
					stack.pop();
				}
				stack.push(y[k]);
			}
			else { break; }

		}
		//stack에 남아있는 2개의 수의 차를 구하면 max이다.
		if (stack.size() == 2)
		{
			//stack.pop()에 해당하는 값의 Y에서 인덱스 값을 구한다.
			int firstIndex = findIndex(stack.top());
			stack.pop();
			int secondIndex = findIndex(stack.top());
			stack.pop();

			if (abs(x[firstIndex] - x[secondIndex]) > max) 
			{ max = abs(x[firstIndex] - x[secondIndex]); }
			

		}
		else { max = 0; }


		cout << "max=" << max << " ";
		result += max;

		while (stack.size() != 0) { stack.pop(); }
	}

	cout <<"\nresult="<< result;


}
