#include <iostream>
#include <vector>

using namespace std;
vector<int> elements;
vector<int> currentSubset;

// 부분집합
void generateSubsets(int startIndex, int k) 
{
    if (k == 0) {
        // k-부분집합 출력
        for (size_t i = 0; i < currentSubset.size(); ++i) 
        {   printf("%02d", currentSubset[i]);   }
        cout << " ";
        return;
    }

    // k-부분집합을 포함한 k+1 부분집합 생성
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
