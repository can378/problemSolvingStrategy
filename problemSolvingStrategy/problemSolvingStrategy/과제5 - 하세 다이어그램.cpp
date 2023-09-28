#include<iostream>
#include<vector>
using namespace std;


#define MAX 9
int n, k;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void dfs(int num, int cnt)
{
	if (cnt == k)
	{
		for (int i = 0; i < k; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int Combination(int n, int r)
{

	int result = 1;

	for (int i = n; i > n - r; i--)
	{
		result *= i;
	}

	int mod = 1;
	for (int i = 1; i <= r; i++)
	{
		mod *= i;
	}

	return result/mod;

}

int main() {

	cin >> n >> k;
	dfs(1, 0);

	
	k++;
	dfs(1, 0);
	/*
	int n, k;
	cin >> n >> k;

	int caseNum = Combination(n,k);


	vector<vector<int>>arr(caseNum,vector<int>(n,-1));

	arr.push_back(vector<int>(n,-1));

	//caseNum X n개의 -1배열이 만들어졌다



	for (int i = 0; i < caseNum; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
	*/

}