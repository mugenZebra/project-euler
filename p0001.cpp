/*
   If we list all the natural numbers below 10 that are multiples of 3 or 5,
   we get 3, 5, 6 and 9. The sum of these multiples is 23.

   Find the sum of all the multiples of 3 or 5 below 1000.

*/

#include <iostream>
using namespace std;

int sumDivisibleBy(int factor, int upperLimit){
  int sum = 0;
  int numberOfFactors = upperLimit / factor;
  sum = factor * numberOfFactors * (numberOfFactors + 1) / 2;

  return sum;
}

int main()
{

  // my solution
  int sum = 0;
  int num;
  int i;
  for (i = 1; ;i++){
    if (num = 3 * i < 1000){
      sum += 3 * i;
    }else{
      break;
    }
    if (num = 5 * i < 1000){
      sum += 5 * i;
    }
    if (num = 15 * i < 1000){
      sum -= 15 * i;
    } // if
  }// for
  cout << "sum: " << sum << endl;


  // suggested solution
  cout << (sumDivisibleBy(3, 1000) + sumDivisibleBy(5, 1000) - sumDivisibleBy(15, 1000)) << endl;

  return 0;
}
