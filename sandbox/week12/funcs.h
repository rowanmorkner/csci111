#ifndef FUNCS_H
#define FUNCS_H
#include <string> 

using namespace std;

int add(int a, int b);
bool isPrime(int number);
void sortArray(int *arr, int size);
long long factorial(int n);
double fahrenheitToCelsius(double fahrenheit);
int findMax(int *arr, int size);
void mergeSortedArrays(int *arr1, int size1, int *arr2, int size2, int *mergedArr);
void reverseString(string str);
int fibonacci(int n);
bool isPalindrome(string str);

#endif