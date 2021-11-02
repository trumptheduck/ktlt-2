#include <iostream>
#define SIZE1 (10)
#define SIZE2 (15)
using namespace std;

int main()
{
    int a1[SIZE1] = {100,87,67,66,55,44,12,11,10,1};
    int a2[SIZE2] = {300,178,160,80,78,76,74,64,53,51,41,37,21,11,7};
    int result[SIZE1 + SIZE2];
    int *i1 = a1;
    int *i2 = a2;
    int isAcs = 1;
    cout << "Merged array: "<<endl;
    if (SIZE1 > SIZE2) {
        if(SIZE1 > 1&&a1[0] > a1[1]) {
            isAcs = -1;
        }
    } else {
        if(SIZE2 > 1&&a2[0] > a2[1]) {
            isAcs = -1;
        }
    }
    for (int *p = result; p < result + SIZE1 + SIZE2; p++)
    {
        if (isAcs*(*i1) <= isAcs*(*i2) && i1 < a1 + SIZE1) {
            *p = *i1;
            i1++; 
        } else if (i2 < a2 + SIZE2) {
            *p = *i2;
            i2++; 
        }
    cout << *p;
    if (p != result + SIZE1 + SIZE2 - 1)
    cout << ",";
    }
    cout << endl;
    return 0;
}