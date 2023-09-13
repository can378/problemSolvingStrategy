#include<iostream>
#include<string>
#include<queue>
#include<map>

using namespace std;



string X(string str)
{
	string str1 = str.substr(0, 4);
	string str2 = str.substr(4, 4);

	return str2.append(str1);
}

string S(string str)
{
	string str1 = str.substr(0, 3);
	str1 = (str.substr(3, 1)).append(str1);

	string str2 = str.substr(4, 3);
	str2 = (str.substr(7, 1)).append(str2);

	return str1.append(str2);
}

string R(string str)
{
	swap(str[1], str[2]);
	swap(str[1], str[6]);
	swap(str[1], str[5]);

	return str;
}


struct Condition
{
	string str;
	int count;

	Condition(string str, int count) : str(str), count(count) {}
};


int main()
{
	string goal;
	cin >> goal;

	int result = 0;

	queue<Condition> Q;
	map<string, bool> visited;


	//ORIGIN
	string origin = "ABCDEFGH";
	Q.push(Condition(origin, 0));
	visited[origin] = true;


	//검사 시작
	while (!Q.empty())
	{

		Condition current = Q.front();
		Q.pop();


		//현재 문자열이 목표에 도달했으면 탈출
		if (current.str == goal) { result = current.count; break; }


		//NEXT=================================
		string nextstr;
		string nowstr = current.str;


		//Exchange
		nextstr = X(nowstr);
		if (!visited[nextstr])
		{
			visited[nextstr] = true;
			Q.push(Condition(nextstr, current.count + 1));
		}

		//Shift
		nextstr = S(nowstr);
		if (!visited[nextstr])
		{
			visited[nextstr] = true;
			Q.push(Condition(nextstr, current.count + 1));
		}

		//Rotation
		nextstr = R(nowstr);
		if (!visited[nextstr])
		{
			visited[nextstr] = true;
			Q.push(Condition(nextstr, current.count + 1));
		}

	}


	cout << "\n" << result << "\n";
}