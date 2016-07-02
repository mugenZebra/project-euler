#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int gridSize = 20;

    vector<long long> horizontal(gridSize, 1);
    vector<long long> vertical(gridSize);
    vertical[0] = 1;
    int i;
    int j;
    for(j = 0; j < gridSize; j++){
        for(i = 1; i < gridSize; i++){
            vertical[i] = vertical[i - 1] + horizontal[i-1];
        }
        for(i = 0; i < gridSize; i++){
            horizontal[i] += vertical[i];
        }
/*
        for(i = 0; i < gridSize; i++){
            cout << vertical[i] << " ";
        }
        cout << endl;
        for(i = 0; i < gridSize; i++){
            cout << horizontal[i] << " ";
        }
        cout << endl << endl;
*/
    }

    cout << vertical[gridSize-1] * 2 << endl;

    return 0;
}
