#include <iostream>

using namespace std;

const int size = 200;

int main()
{
    int factoSum[size] = {0};
    int sum = 0;
    factoSum[0] = 1;

    for(int i = 2;i <= 100; i++){// loop for 1 x 2 x ... x 99 x 100
        for(int j = 0; j < size; j++){// loop for multiplying each
            factoSum[j] *= i;         // digit by i
        }
        for(int j = 0; j < size; j++){ // loop for carry
            while(factoSum[j] >= 10){
                factoSum[j] -= 10;
                factoSum[j + 1]++;
            }
        }
    }
    for(int i = 0; i < size; i++){
        cout << factoSum[i];
        sum += factoSum[i];
    }
    cout << endl << sum << endl;
    return sum;
}
