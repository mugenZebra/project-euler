#include <iostream>

using namespace std;

bool checkPalindrome(int);
int* extractDigit(int, int);
int getNumDigit(int);
int findLargestPalindrom(void);

int main()
{
    cout << "largest palindrome of two 3-digits product is: "
         << findLargestPalindrom() << endl;

    return 0;
}

bool checkPalindrome(int num){
    bool palindrome = false;
    int i;
    int size = getNumDigit(num);
    int *digitArr = extractDigit(num, size);
    // check even number of digits case
    if (num % 2 == 0){
        for(i = 0; i < size / 2; i++){
            if(digitArr[i] == digitArr[size - i - 1]){
                palindrome = true;
            } else {
                palindrome = false;
                return palindrome;
            } // end if
        }// for
    } else { // check odd number of digits case
        for(i = 0; i <= size / 2; i++){
            if(digitArr[i] == digitArr[size - i - 1]){
                palindrome = true;
            } else {
                palindrome = false;
                return palindrome;
            } // end if
        } // for
    } // end if

    return palindrome;
};

int findLargestPalindrom(){
    int i;
    int j;
    int product;
    int largestPalindrom = 0;

    for (i = 999; i >= 200; i--)
    {
        for (j = i; j >= 500; j--){
            product = i * j;

            if (product <= largestPalindrom){
                break;
            }
            if (checkPalindrome(product) == true && largestPalindrom < product){
                largestPalindrom = product;
            }
        //if (product == 906609) break;
        }
        //if (product == 906609) break;
    }

    //cout << i  << " times " << j << endl;
    return largestPalindrom;
}

// The function will take a number and put all of its digit into an int array
// and it will return a pointer to int
int* extractDigit(int num, int size){

    int *nArr = new int[size]; // an array for storing digits

    if(num < 0)
        num *= -1;

    // every loop executed, mod will extract the least sig digit.
    for(int i = 1; num > 0; i++){
        *(nArr + size - i) = (num % 10); //store digits from the end of array.
        num /= 10;
    }

    return nArr;
}

int getNumDigit(int num){
	int digits = 0;

	if(num < 0)
		num = -num;
	else if(num == 0)
		return 1;
	while(num > 0){
		num /= 10;
		digits++;
	}

	return digits;
}
