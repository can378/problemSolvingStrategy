#include<iostream>
#include<vector>
using namespace std;
int n, m;
long long result = 0;


void explore(vector<int>A, vector<int>B, int Aindex, int Bindex)
{

	for (int i = Aindex; i < n; i++)
	{
		if (Bindex >= m) { Bindex = 0; }

		if (A.at(i) == B[Bindex])
		{
			if (Bindex == m - 1)
			{
				if (result == 20221022) { result = 0; }
				result++;
			}
			else
			{
				explore(A, B, i + 1, Bindex + 1);
			}
		}
	}

}


int main() {


	cin >> n >> m;

	vector<int>A(n);
	vector<int>B(m);

	//input
	for (int i = 0; i < n; i++)
	{
		cin >> A.at(i);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> B.at(i);
	}


	//check
	explore(A, B, 0, 0);

	//output
	cout << "\n" << result % 20221022 << "\n";

}