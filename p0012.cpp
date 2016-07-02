// best time 0.058s

#include <iostream>
using namespace std;

long long findTriangleNumber(const int&);
int findDivisorNumberComb(long long); //
bool div(const long long&, const long long &);

int main()
{
    // start at three because the third and fourth, seventh and eighth
    // triangle numbers are even, even numbers have more divisors
    int i = 3;
    int divNum;
    long long triNum = 3; // 1 + 2

    // checking two triangle number at once
    do{
        triNum = findTriangleNumber(i);
        divNum = findDivisorNumberComb(triNum);
        if (divNum > 500){
            cout << "bang!" << endl;
            break;
        }
        triNum = triNum + ++i;
        divNum = findDivisorNumberComb(triNum);
        i--;
        i += 4;
    } while(divNum < 500);


    cout << --i << ": " << triNum << " -- " << divNum <<  endl;

    return 0;
}
int findDivisorNumberComb(long long tri){
    int comb = 1;
    long long tri_copy = tri;
    while(tri / 2.0 == tri / 2){
        tri /= 2;
        comb++;
    }

    for(long long i = 3; i * i <= tri; i += 2){
        int oddPrimeDivisor = 1;
        while(div(tri, i)){
            oddPrimeDivisor++;
            tri /= i;
        }
        (oddPrimeDivisor > 1) ? (comb *= oddPrimeDivisor) : 0;
    }
    if(tri != 1){
        comb *= 2;
    }

    return comb;
}


long long findTriangleNumber(const int &n){
    return n * (n + 1) / 2;
}

bool div(const long long &dividend, const long long &divisor){
    bool flag;
    //cout << ((double) dividend / (double) divisor) <<endl;
    //cout << ((double) (dividend / divisor)) << endl;
    if (((double) dividend / (double) divisor) ==
        ((double) (dividend / divisor))){
        flag = true;
    } else {
        flag = false;
    }

    return flag;
}
