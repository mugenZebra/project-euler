#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(long long num){
    if (num == 1){
        return false;
    } else if (num < 4){ // for 2, 3
        return false;
    } else if (num % 2 == 0){
        return false;
    } else if (num < 9){ // already excluded 2, 4, 6, 8, all other aren't primes
        return false;
    } else if (num % 3 == 0){
        return false;
    } else {
        for(int i = 5; i <= pow(num, 0.5) ; i += 6){
            if(num % i == 0){
                return false;
            } else if (num % (i + 2) == 0){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    long long i;
    int count = 2; // 2 is 1st, 3 is 2nd, ....
    int nthPrime = 10001;

    cout << is

    for(i = 3; count < nthPrime; i+=2){
        if(is_prime(i)){
            //cout << "the " << count << "th prime: " << i << endl;
            count++;
        }
    }

    cout << "the " << count << "th prime: " << i << endl;
    return 0;
}
