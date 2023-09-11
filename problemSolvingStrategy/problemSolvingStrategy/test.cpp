#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{

    int n=100000;
    //cin >> n;

    vector<int> X(n);
    vector<int> Y(n);

    /*
    for (int i = 0; i < n; i++) { cin >> X[i]; }
    for (int i = 0; i < n; i++) { cin >> Y[i]; }
    */

    for (int i = 0; i < n; i++) { X[i]=i; }
    for (int i = 0; i < n; i++) { Y[i]=i; }


    // y ��ǥ�� �������� x ��ǥ�� �������� ����
    vector<pair<int, int>> sortedXY;
    for (int i = 0; i < n; i++) {
        sortedXY.push_back({ X[i], Y[i] });
    }


    //�� �� Ȯ��
    sort
    (sortedXY.begin(), sortedXY.end(),
        [](const pair<int, int>& a, const pair<int, int>& b)
        {    return a.second > b.second || (a.second == b.second && a.first > b.first);    }
    );


    //x��ǥ���� ����
    vector<int> sorted_x;
    for (const pair<int, int>& XY : sortedXY)
    {
        sorted_x.push_back(XY.first);
    }


    long result = 0;


    for (int i = 0; i < sorted_x.size() - 1; i++)
    {
        int startX = sorted_x[i];
        int maxLeng = 0;

        for (int k = i + 1; k < n; k++)
        {
            if (maxLeng < abs(sorted_x[i] - sorted_x[k]))
            {
                maxLeng = abs(sorted_x[i] - sorted_x[k]);
            }

        }

        cout << "maxLeng=" << maxLeng << " ";
        result += maxLeng;

    }

    cout << result;



    return 0;
}
