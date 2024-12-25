#include <iostream> 
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
int linearSearch(vector<char> arr, int size, char find){
    int count =0;
    for (int i=0; i< size; i++){
        if(arr[i]==find){
            count++;
        }
    }
    return count;
}

int sortedSearch(vector<char> arr, int size, char find){
    int count = 0;
    sort(arr.begin(), arr.end());
    for(int i= 0; i<size; i++){
        cout << arr[i];
    }
    cout<<endl;

    for(int i =0; i<size; i++){
        if (arr[i]==find){
            count++;
        }
        else if(arr[i]>find){
            break;
        }
    }
    return count;
}


int main(){
    int size = 125000
    vector <char> arr [size];
    srand(44);

    for(int i =0; i< size; i++){
        arr[i] rand() %26 +65;
    }
    char find = K;

    cout << "liner unsorted:" << linearSearch(arr, size, find)<< endl;

    cout << "liner sorted:" << sortedSearch(arr, size, find)<< endl;
    
    return 0;

}