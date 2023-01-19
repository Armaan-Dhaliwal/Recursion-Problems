#include <iostream>
using namespace std;

int fac(int num)
{

    if (num == 0)
    {
        return 1;
    }

    else
    {
        cout << num << endl;
        return num * fac(num - 1);
    }
}

int main()
{
    int num;
    cout << "Enter your number:" << endl;
    cin >> num;

    int factorial = fac(num);
    cout << "Factorial is: " << factorial << endl;
    return 0;
}