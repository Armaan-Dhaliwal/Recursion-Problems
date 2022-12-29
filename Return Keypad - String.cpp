#include <iostream>
#include <math.h>
using namespace std;

int Key(string input, string output[])
{
    string two = "abc";
    string three = "def";
    string four = "ghi";
    string five = "jkl";
    string six = "mno";
    string seven = "pqrs";
    string eight = "tuv";
    string nine = "wxyz";

    if (input.empty() || input[0] == '1' || input[0] == '0')
    {
        return 1;
    }

    string sus = input.substr(1);
    int count = Key(sus, output);

    cout << "Count is:" << count << endl;
    if (input[0] == '9' || input[0] == '7')
    {

        for (int i = 1; i < 4; i++)
        {
            int j = 0;
            while (j < count)
            {
                output[count * i + j] = output[j];
                j++;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int j = 0;

            while (j < count)
            {
                if (input[0] == '9')
                {
                    output[j + i * count] = nine[i] + output[i * count + j];
                }

                if (input[0] == '7')
                {
                    output[j + i * count] = seven[i] + output[i * count + j];
                    cout << output[j + i * count] << endl;
                }
                j++;
            }
        }
        return (4 * count);
    }

    if (input[0] != '9' && input[0] != '7')
    {

        for (int i = 1; i < 3; i++)
        {
            int j = 0;
            while (j < count)
            {
                output[count * i + j] = output[j];
                j++;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int j = 0;

            while (j < count)
            {
                switch (input[0])
                {
                case '2':
                {
                    output[j + i * count] = two[i] + output[i * count + j];

                    break;
                }
                case '3':
                {
                    output[j + i * count] = three[i] + output[i * count + j];

                    break;
                }
                case '4':
                {
                    output[j + i * count] = four[i] + output[i * count + j];

                    break;
                }
                case '5':
                {
                    output[j + i * count] = five[i] + output[i * count + j];

                    break;
                }
                case '6':
                {
                    output[j + i * count] = six[i] + output[i * count + j];

                    break;
                }
                case '8':
                {
                    output[j + i * count] = eight[i] + output[i * count + j];

                    break;
                }

                default:
                    break;
                }
                j++;
            }
        }
        return (3 * count);
    }
}

int main()
{
    string input;
    cout << "Enter input string: " << endl;
    cin >> input;
    int n = input.length();
    int size = pow(4, n);
    string *output = new string[size];

    int loop = Key(input, output);
    cout << "Your Subseqences: " << endl;
    for (int i = 0; i < loop; i++)
    {
        cout << i + 1 << ": " << output[i] << endl;
    }
}