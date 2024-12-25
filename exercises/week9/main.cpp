#include <iostream> 

using namespace std;

int arrMax(int *arr, int size);
int arrMin(int *arr, int size);
int arrSum(int *arr, int size);

int main(){

    int size = 10;

    int ray[10] = {0};

    for(int i = 0; i< 10; i++){
        cin>> ray[i];
    }

    cout << arrMax(ray, size) << endl;
    cout << arrMin(ray, size) << endl;
    cout << arrSum(ray, size) << endl;


}