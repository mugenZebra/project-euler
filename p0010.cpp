#include <iostream>
#include <fstream>
using namespace std;

bool is_prime(const long long num);

int main(){
    ofstream fout;
    fout.open("prime.txt", ios::app | ios::out);
    int i = 2;
    long long sum = 0;
    while (i < 2000000){
        if(is_prime(i)){
            sum += i;
            fout << i << endl;
            cout << i << endl;
        }
        i++;
    }

    cout << "sum: " << sum <<endl; //142913828922
    fout.close();
}

bool is_prime(const long long num){
    if (num == 1){
        return false;
    } else if (num < 4){ // for 2, 3
        return true;
    } else if (num % 2 == 0){
        return false;
    } else if (num < 9){ // already excluded 2, 4, 6, 8, all other are primes
        return true;
    } else if (num % 3 == 0){
        return false;
    } else {
        for(int i = 5; i * i <= num ; i += 6){
            if(num % i == 0){
                return false;
            } else if (num % (i + 2) == 0){
                return false;
            }
        }
    }
    return true;
}
