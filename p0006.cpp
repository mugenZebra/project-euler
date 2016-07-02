#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int sumSquares = 0;
    int squareSum = 0;
    int i;
    int j;
    for(i = 1; i <= 100; i++){
        squareSum += i;
    }
    squareSum = pow(squareSum, 2);

    cout << squareSum << endl;

    for(i = 1; i <= 100; i++){
        sumSquares += pow(i, 2);
    }

    cout << sumSquares << endl;


    cout << squareSum - sumSquares << endl;

    return 0;
}
