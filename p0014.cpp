#include <iostream>

using namespace std;

/*
n → n/2 (n is even)
n → 3n + 1 (n is odd)
*/

int main()
{
    int chainNum = 1;
    int largestChainNum = 0;
    int largestStart;
    long long n;
    int limit = 1000000;
    int i = 1;

    while (i <= limit){ // loop for 1 to 1 mil
        n = i;
        //cout << "i: " << i << endl;
             //<< " -- n: " << n << endl;
        //cout << "chains: ";
        while (n != 1){ // loop for chainning
            (n % 2 == 0) ? n /= 2 : n += (n<<1) + 1; // n = 3 * n + 1
            chainNum++;
            //cout << n << " " << endl;
        }
        //cout << endl << "chain number: " << chainNum << endl;
        //cout << endl;
        if (chainNum > largestChainNum){
            largestStart = i;
            largestChainNum = chainNum;
        }

        /*if (i == 13){
            break;
        }
        */
        chainNum = 1;
        i++;
    }

    cout << "longest chain : " << largestChainNum
         << " is produced by " << largestStart << endl;

    return 0;
}
