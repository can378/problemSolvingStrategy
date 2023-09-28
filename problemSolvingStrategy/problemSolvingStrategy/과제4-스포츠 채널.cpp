#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;



long long M;
int n;
vector< long long>days;



long long price(int from, int to) 
{
	if (from<0 || to >=n || from>=n || to<0 || from>to) { return 0; }
	return days[to] - days[from] + 1 + M;
}

int main() {

	freopen("input.txt", "r", stdin);
	

	cin >> n >> M;

	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;
		days.push_back(num);
	}


	long long result = 0;






	//SEARCH
	int i = n - 1;//뒤에서 첫번째꺼
	int cutIndex = i;

	long long case1 = 0;
	long long case2 = 0;

	

	while (i >= 0)
	{

		case1 = price(0, cutIndex) + price(cutIndex + 1, i);
		case2 = price(0, cutIndex - 1) + price(cutIndex, i);

		if (i<= 1) 
		{
			case1 <= case2 ? result += case1 : result += case2;
			break;
		}


		if (case1>case2)
		{
			result += price(cutIndex,i);

			//next
			cutIndex--;
			i = cutIndex;

		}
		else 
		{
			cutIndex--;
		}

	}

	
	cout <<"\nresult="<< result << "\n";
	
}