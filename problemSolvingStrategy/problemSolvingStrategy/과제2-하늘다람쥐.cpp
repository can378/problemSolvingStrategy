#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define SIZE 200001

long main() 
{
	long n;
	cin >> n;
	
	vector<long>X(SIZE);
	vector<long>H(SIZE);

	
	vector <vector<long>> position(n+1,vector<long>(n+1,-1));
	vector<long>pos;
	position.push_back(pos);



	//get child�� ã�� ���� ������ ���� 

	
	
	for (long i = 1; i <= n; i++)
	{
		cin >> X[i];
	}
	for (long i = 1; i <= n; i++)
	{
		cin >> H[i];
	}


	
	long result = 0;
	long max = 0;
	for (long i = 1; i <= n; i++)
	{
		max = 0;
		for (long j = 1; j <= n; j++)
		{
			if (position[i][j] == -1)//ó�� Ž���ϴ°Ÿ�
			{
				if (H[i] > H[j])//���̰� �� ������ = Xi���� Xj��.
				{
					position[i][j] = abs(X[i] - X[j]);


					//���̿� �� ������ �ִ�
					if (i > j)
					{
						for (long k = j + 1; k < i; k++)
						{
							
							if (H[k] > H[i]) {
								position[i][j] = 0;
								break;
							}
						}
					}
					//���Ⱑ �����ε���
					else if (i < j)
					{
						for (long k = i + 1; k < j; k++)
						{
							if (H[k] > H[i]) {
								position[i][j] = 0;
								break;
							}
						}

					}

					//max��
					if (max < position[i][j])
					{
						max = position[i][j];
					}

					position[j][i] = 0; //Xj -> Xi�� �ȵ�

				}
				else
				{
					position[i][j] = 0;

				}
			}
		}
		result += max;
	}

	/*
	for (long i = 1; i<= n; i++)
	{
		for (long j = 1; j <= n; j++)
		{
			cout << position[i][j]<<" ";
		}
		cout << "\n";
	}
	*/
	cout << result;


}