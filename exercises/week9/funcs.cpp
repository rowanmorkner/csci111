#include <iostream> 
using namespace std;

int arrMax(int *arr, int size){

    int Max = arr[0], pos = 0;

    for (int i = 0; i < size; i++){

        if (Max < arr[i]){
            Max = arr[i];
            pos = i;
        }
    }
    
    return pos;

};

int arrMin(int *arr, int size){
    int Min = arr[0];

    for(int i = 0; i < size; i++){
        if (Min > arr[i]){
            Min = arr[i];
        }
    }
    return Min;
};

int arrSum(int *arr, int size){

    int sum = 0;

    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

return sum;
};