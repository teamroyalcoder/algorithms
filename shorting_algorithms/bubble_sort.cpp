#include <iostream>
#include <string>
#include "../utilities/utility.h"
using namespace std;

void bubbleSort(int arr[], int arrSz, string order = "Ascending")
{
    int rounds = 0;
    int swaps = 0;
    for (int i = 0; i < arrSz; i++)
    {
        rounds++;
        for (int j = 0; j < (arrSz - i - 1); j++)
        {
            if ((order == "Descending") ? arr[j] < arr[j + 1] : arr[j] > arr[j + 1])
            {
                swaps++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Rounds needed - " << rounds << endl;
    cout << "Swaps happened - " << swaps << endl;
}

int main()
{
    string algo = "Bubble sort";
    string order = "Ascending";
    // string order = "Descending";

    cout << "Unordered:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << short_array_int[i] << "\t";
    }

    cout << endl;

    return 0;
}
