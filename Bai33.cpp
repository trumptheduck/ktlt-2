#include <iostream>

using namespace std;

typedef struct ResultStruct {
    int value;
    int index;
} Result;


int main() {
    int arr[] = {1,3,5,1,62,41,64,2,34,22,12,56,5,23,16,81,25,8,2,5,16};
    Result min = {arr[0],0};
    Result max = {arr[0],0};
    int size = sizeof(arr)/sizeof(int);
    for (int i = 1; i < size; i++) {
        if (min.value > arr[i]) {
            min.value = arr[i];
            min.index = i;
        }
        if (max.value < arr[i]) {
            max.value = arr[i];
            max.index = i;
        }
    }
    cout << "Min: " << min.value << " at index: " << min.index << endl;
    cout << "Max: " << max.value << " at index: " << max.index << endl;
}