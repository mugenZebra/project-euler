#include <iostream>

using namespace std;

int translateWordToNum(int);
int evaluateWord(int n);
int evaluateWordTY(int);
int evaluateWordTenth(int);
int main()
{
    int i;
    int count = 0;
    int limit = 9999;

    for(i = 1; i <= limit; i++){
        //cout << i << " -- " << translateWordToNum(i) << endl;
        //cin.ignore();
        count += translateWordToNum(i);
    }
    cout << endl;
    cout << count << endl;
    return 0;
}

int translateWordToNum(int n){

    int count = 0;
    int hundredth = n / 100;

    if(n % 1000 == 0){ // 1000, 2000, ... ,
        count += 8; // thousand
        count += evaluateWord(n / 1000);
    } else if(n % 100 == 0 && n < 1000){ // 900, 800, ... , 100
        count += 7; // hundred
        count += evaluateWord(n / 100);
    } else if(n > 100 ){ // 999 - 101
        count += 10; // and, hundred
        count += evaluateWord(hundredth);
        // recursive call to get tenth
        count += translateWordToNum(n - hundredth * 100);
    } else if (n % 10 == 0 && n < 100 && n >= 10){ // 10, 20, 30,..
        count += evaluateWordTY(n / 10);
    } else if(n < 100 && n > 20){ // 99, 98, ... , 21, 20
        count += evaluateWordTY(n / 10);
        count += evaluateWord(n % 10);
    } else if(n < 20 && n > 10){
        count += evaluateWordTenth(n);
    } else if(n < 10) {
        count += evaluateWord(n);
    }

    return count;
}

int evaluateWordTenth(int n){
    int count;
    switch(n){
        case 11: count = 6;// eleven
                 break;
        case 12: count = 6;//twelve
                 break;
        case 13: count = 8;//thirteen
                 break;
        case 14: count = 8; //fourteen
                 break;
        case 15: count = 7; // fifteen
                 break;
        case 16: count = 7; // sixteen
                 break;
        case 17: count = 9; // seventeen
                 break;
        case 18: count = 8; // eighteen
                 break;
        case 19: count = 8; // nineteen
                 break;
    }
    return count;
}

int evaluateWordTY(int n){
    int count;
    switch(n){
        case 1: count = 3; // ten
                break;
        case 2: count = 6; // twenty
                break;
        case 3: count = 6; // thirty
                break;
        case 4: count = 5; // forty
                break;
        case 5: count = 5; // fifty
                break;
        case 6: count = 5; // sixty
                break;
        case 7: count = 7; // seventy
                break;
        case 8: count = 6; // eighty
                break;
        case 9: count = 6; // ninety
                break;
    }
    return count;
}

int evaluateWord(int n){
    int count;
    switch(n){
        case 1: count = 3; // one
                break;
        case 2: count = 3; // two
                break;
        case 3: count = 5; // three
                break;
        case 4: count = 4; // four
                break;
        case 5: count = 4; // five
                break;
        case 6: count = 3; // six
                break;
        case 7: count = 5; // seven
                break;
        case 8: count = 5; // eight
                break;
        case 9: count = 4; // nine
                break;
    }
    return count;
}
