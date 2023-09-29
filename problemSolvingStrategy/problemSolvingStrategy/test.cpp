#include <iostream>
#include <vector>

using namespace std;
vector<int> elements;
vector<int> currentSubset;

// �κ�����
void generateSubsets(int startIndex, int k) 
{
    if (k == 0) {
        // k-�κ����� ���
        for (size_t i = 0; i < currentSubset.size(); ++i) 
        {   printf("%02d", currentSubset[i]);   }
        cout << " ";
        return;
    }

    // k-�κ������� ������ k+1 �κ����� ����
    for (int i = startIndex; i < elements.size(); ++i) 
    {
        currentSubset.push_back(elements[i]);
        generateSubsets(i + 1, k - 1);
        currentSubset.pop_back();
    }
}

int main() 
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; ++i) 
    {  elements.push_back(i);}

    generateSubsets(1, k);
}
