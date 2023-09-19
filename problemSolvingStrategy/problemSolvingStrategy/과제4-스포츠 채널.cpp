#include<iostream>
#include<vector>
using namespace std;

int n, M;
vector<int>days;



int price(int from, int to) 
{
	if (from<0 || to >=n || from>=n || to<0 || from>to) { return 0; }
	return days[to] - days[from] + 1 + M;
}

int main() {

	cin >> n >> M;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		days.push_back(num);
	}

	int result = 0;






	//SEARCH
	int i = n - 1;//뒤에서 첫번째꺼
	int cutIndex = i;

	int case1 = 0;
	int case2 = 0;

	

	while (i >= 0)
	{
		//cout << "result=" << result<<"\n";
		//cout << "i=" << i << " cutIndex=" << cutIndex << "\n";
		case1 = price(0, cutIndex) + price(cutIndex + 1, i);
		case2 = price(0, cutIndex - 1) + price(cutIndex, i);

		//cout << "case1=" << case1 << " case2=" << case2 << "\n";

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
		//cout << "result="<<result << "\n\n";

	}

	
	cout << "\n" << result << "\n";
	
}