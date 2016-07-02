#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int c;
    int b;
    int a;
    int endEntireLoop = false;
    int executions = 0;
    for(c = 1; c < 998; c++){
        for(b = 1; b < c; b++){
            for(a = 1; a < b; a++){
                executions++;
                if(c + b + a == 1000 && (pow(a, 2) + pow(b, 2) == pow(c, 2))){
                    endEntireLoop = true;
                    cout << a << ", " << b << ", " << c << endl;
                    cout << a * b * c << endl;
                    break;
                }
            }
            if(endEntireLoop) break;
        }
        if(endEntireLoop) break;
    }

    cout << executions << endl;

    return 0;
}
