/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/
#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(long long num){
    bool prime = true;
    if (num % 2 == 0){
        prime = false;
        return prime;
    }

    for(int i = 3; i <= pow(num, 0.5); i+=2){
        if(num % i != 0){
            prime = true;
        }
        else{
            return prime = false;
        }
    }
    return prime;
}

int largestPrimeFactor(long long testNum){
    bool primeCheck;
    int prime;
    int i;

    while(testNum % 2 == 0){ // loop if testNum is divisible by the prime, i
        testNum = testNum / 2;
        prime = 2;
    }

    for(i = 3; i <= testNum; i += 2){
        primeCheck = is_prime(i);
        while(primeCheck && testNum % i == 0){ // loop if testNum is divisible by the prime, i
            cout << testNum << "/" << i << endl;
            testNum = testNum / i;
            prime = i;
            cout << i << endl;
        }
    }// for

    cout << "prime is " << prime << endl;

    return testNum;
}

int main()
{
    long long testNum = 600851475143;

    cout << largestPrimeFactor(testNum) << endl;

    return 0;
}
