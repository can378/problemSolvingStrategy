#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;


#define MAX 100
int n, k;
int subset[MAX] = { 0, };
bool visited[MAX] = { 0, };


void dfs2() 
{
	for (int i = 1; i <= n; i++) 
	{
		if (!visited[i]) 
		{ 
			if (subset[0] > i) 
			{ 
				printf("%02d", i);
				for (int j = 0; j < k; j++)
				{	printf("%02d", subset[j]);	}
			}
			else if (subset[k - 1] < i) 
			{
				for (int j = 0; j < k; j++)
				{	printf("%02d", subset[j]);	}
				printf("%02d", i);
			}
			else 
			{
				bool finish = false;
				for (int j = 0; j < k; j++)
				{
					printf("%02d", subset[j]);
					if (subset[j] < i&&finish==false) 
					{
						printf("%02d", i); 
						finish = true; 
					}
				}
			}
			printf(" ");
		}
	}
}

void dfs(int num, int cnt)
{
	if (cnt == k)
	{
		if (k == 0) { printf("00"); }
		for (int i = 0; i < k; i++) 
		{ printf("%02d", subset[i]); }
		printf(" ");

		dfs2();
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			subset[cnt] = i;
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}


int main() 
{
	cin >> n >> k;
	dfs(1, 0);
}