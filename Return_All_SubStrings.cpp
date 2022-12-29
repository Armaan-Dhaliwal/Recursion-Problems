/*Problem Statement: Return all possible substrings of an input string using Dynamic Memory Allocation*/
#include <iostream>
#include <math.h>
using namespace std;

int Subs(string input, string output[])
{
    if (input.empty())
    {
        return 1;
    }

    string sus = input.substr(1);
    int count = Subs(sus, output);
    for (int i = 0; i < count; i++)
    {
        output[i + count] = input[0] + output[i];
    }

    return (2 * count);
}

int main()
{
    string input;
    cout << "Enter input string: " << endl;
    cin >> input;
    int n = input.length();
    int size = pow(2, n);
    string *output = new string[size];

    Subs(input, output);
    cout << "Your Subseqences: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ": " << output[i] << endl;
    }
}