#include <iostream>
#define SIZE (10)
using namespace std;

int main()
{
    int a[SIZE] = {500,31,515,156,16,1,512,27,362,61};
    int result = 0;
    int step = 0;
    for(int *i = a; i < a + SIZE; ++i) {
        step++;
        if (result >= SIZE - step) break;
        int maxDistance = 0;
        int currDistance = 0;
            for(int *j = i+1; j < a + SIZE; ++j) {
                currDistance++;
                if (*i < *j) {
                    maxDistance = currDistance;
                }
            }
        if (result < maxDistance) {
            result = maxDistance;
        }
    }
    cout << result;
    return 0;
}