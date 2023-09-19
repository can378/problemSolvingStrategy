#include <iostream>
#include <string> //string::find
using namespace std;

char* eXchange(char* obj)
{
    char tmp;
    for (int i = 0; i < 4; i++)
    {
        tmp = obj[i + 4];
        obj[i + 4] = obj[i];
        obj[i] = tmp;
    }
    return obj;
}

char* Shift(char* obj)
{
    char tmp1;
    char tmp2;
    tmp1 = obj[0];
    obj[0] = obj[3];
    obj[3] = obj[2];
    obj[2] = obj[1];
    obj[1] = tmp1;

    tmp2 = obj[4];
    obj[4] = obj[7];
    obj[7] = obj[6];
    obj[6] = obj[5];
    obj[5] = tmp2;
    return obj;
}

char* Rotation(char* obj)
{
    char tmp1;
    char tmp2;
    tmp2 = obj[6];
    obj[6] = obj[2];
    obj[2] = obj[1];
    obj[1] = obj[5];
    obj[5] = tmp2;
    return obj;
}

int isInRightRow(char* obj)
{
    if (obj[0] >= 'A' && obj[0] <= 'D')
    {
        for (int i = 1; i < 4; i++)
            if (!(obj[i] >= 65 && obj[i] <= 68)) return 0;
    }
    else if (obj[0] >= 'E' && obj[0] <= 'H')
    {
        for (int i = 1; i < 4; i++)
            if (!(obj[i] >= 69 && obj[i] <= 72)) return 0;
    }
    return 1;
}

int isAInRightPosition(char* obj)
{
    if (obj[0] == 'A' || obj[4] == 'A')
        return 1;
    else
        return 0;
}

int isAInRightRow(char* obj)
{
    if (obj[0] == 'A')
        return 1;
    else
        return 0;
}

int puzzle(char* obj)
{
    int cnt = 0;
    cout << cnt << "번째 연산:" << obj << endl;
    cout << "Rotation" << endl;
    while (!isInRightRow(obj))
    {
        obj = Rotation(obj);
        cnt++;
        cout << cnt << "번째 연산:" << obj << endl;
    }
    cout << "Shift" << endl;
    while (!isAInRightPosition(obj))
    {
        Shift(obj);
        cnt++;
        cout << cnt << "번째 연산:" << obj << endl;
    }
    cout << "eXchange" << endl;
    if (!isAInRightRow(obj))
    {
        eXchange(obj);
        cnt++;
        cout << cnt << "번째 연산:" << obj << endl;
    }
    string a = "ABCDEFGH";
    if (a.compare(obj) == 0)
        return cnt;
    else
        return -1;
}

int main()
{
    char obj[9];
    cin >> obj;
    cout << puzzle(obj);
}