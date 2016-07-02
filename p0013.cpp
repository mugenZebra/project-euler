#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int SIZE = 53;

void displayArr(int[]);

int main()
{
    ifstream fin;
    fin.open("numbers");
    char ch;
    unsigned short digit;
    int num[SIZE] = {0};
    char stop;

    while(fin){
        for (int i = 49; i >= 0; i--){
            fin >> ch;
            num[i] += ch - 48;
        }
    }
    displayArr(num);
    cout << endl << endl;
    //cin.ignore();

    for(int i = 0; i < SIZE; i++){
        while(num[i] >= 10){
            num[i] -= 10;
            num[i + 1]++;
        }
    }
    displayArr(num);

    fin.close();
    return 0;
}

void displayArr(int arr[]){
    for(int i = 0; i < SIZE; i++){
        cout << arr[SIZE - i - 1] << " ";
    }
}
