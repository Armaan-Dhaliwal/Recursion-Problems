#include <iostream>
using namespace std;

int fibo(int num)
{
    if (num == 0)
    {

        return 0;
    }
    if (num == 1)
    {

        return 1;
    }

    return fibo(num - 1) + fibo(num - 2);
}

int main()
{
    int num, ans;
    cout << "Enter number of terms you want: " << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        ans = fibo(i);
        cout << ans << " ";
    }
}