#include<iostream>
#include<vector>
using namespace std;

#define SIZE 200000


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//input===============
	long n;
	cin >> n;


	vector<long long> x(SIZE);
	vector<long long> y(SIZE);


	for (long i = 0; i < n; i++)
	{	cin>>x[i];	}
	for (long i = 0; i < n; i++)
	{	cin>>y[i];	}




	//check===============

	long long result = 0;
	long long max = 0;
	long selectY = -1;


	for (long i = 0; i < n; i++)
	{
		max = 0;

		selectY = -1;

		//right===========
		for (long j = i + 1; j < n; j++)
		{
			if (y[j] < y[i])
			{	selectY = j;	}
			else { break; }
		}

		if (selectY!=-1)
		{	max = abs(x[selectY] - x[i]);		}

		selectY = -1;


		//left===========
		for (long k = i-1; k >0; k--)
		{
			if (y[k] < y[i])
			{	selectY = k;	}
			else { break; }
		}


		//stack에 남아있는 2개의 수의 차를 구하면 max이다.
		if (selectY!=-1)
		{
			if (abs(x[selectY] - x[i]) > max)
			{	max = abs(x[selectY] - x[i]);		}
		}

		result += max;

	}



	cout << result<<"\n";


}