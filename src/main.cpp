#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
using namespace std;

void sumArray(array<int, 10> anArray, int& theSum);
int main() {
    int theSum = 0;
    array<int, 10> myArray = {1,2,1,1,1,1,1,1,1,1};
    
    sumArray(myArray, theSum);
    cout << theSum << endl;
    return 0;
}

void sumArray(array<int, 10> anArray, int& theSum) {
    
    for(int number : anArray) {
        theSum += number;
    }
}