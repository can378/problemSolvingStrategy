#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n, M;
    vector<int> v;
    long long int answer = 0;

    cin >> n >> M;
    for (int i = 0; i < n; i++)
    {
        int date;
        cin >> date;
        v.push_back(date);
    }
    answer = min(v[1] - v[0] + 1 + M, 2 * (M + 1));
    for (int i = 1; i < n - 1; i++)
    {
        answer += min(v[i + 1] - v[i], M + 1);
    }
    cout << answer;
}