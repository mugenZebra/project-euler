/**
 * need to compile with flag  -std=c++11
 * find all possible factorions
 * http://mathworld.wolfram.com/Factorion.html
 */
#include <iostream>
#include <vector> 
#include <functional>
#include <cassert>
#include <limits>
#include <algorithm>
#include <windows.h>
double get_time()
{
  LARGE_INTEGER t, f;
  QueryPerformanceCounter(&t);
  QueryPerformanceFrequency(&f);
  return (double)t.QuadPart/(double)f.QuadPart;
}


int main() {
  // build a factorial table of single digits
  std::vector<int> facTable; 
  facTable.push_back(1);
  for (int i = 1; i < 10; i++) {
    int fac = 1;
    for (int j = i; j > 1; j--) {
      fac *= j;
    }
    facTable.push_back(fac);
  }
  assert(facTable[0] == 1);
  assert(facTable[1] == 1);
  assert(facTable[2] == 2);
  assert(facTable[5] == 120);

  auto calcSumFacDigit = [&facTable] (int num) -> int {
    int sum = 0; 
    while (num > 0) {
      sum += facTable[num % 10];
      num /= 10;
    }
    return sum;
  };
  assert(calcSumFacDigit(145) == 145);
 
  auto isCuriousNum = [&] (int num) -> bool {
   return calcSumFacDigit(num) == num;
  };
  assert(isCuriousNum(145) == true);


  // find max possible curious number
  // property 1: single digit number are not curious numbers, because curious numbers are SUM of factorial of digits.
  // property 2: within same # of digits, the larger the number, the larger the curious number, and vice versa. largest will be 99..99, a number with all digit nine.  
  // property 3: for all natural number n of d number of digits, n satisfies [ 10^(d-1) <= n < 10^(d) ]  --[1]
  //             and if x is sum of factorial of all its digits, [ x < d*9! ] from -- [2] 
  //             and for all x, x should satisfy [ 10^(d-1) <= x < d*9! ] from [1] and [2], think of venn diagramm where [1] and [2] should be satisfied at the same time.

  int max = 99; // largest curious number in two digits
  while (calcSumFacDigit(max) >= max) {// get largest digit
    (max *= 10) += 9; 
  } 
  max = calcSumFacDigit(max);  // calculate d*9!
  std::cout << "max is " << max << std::endl;

  // find all curious number by brute force to max number

  // method 1
  int sum = 0;
  double t0, tf;
  std::vector<int> allCuriousNums;
  t0 = get_time();
  for (int i = 10; i < max; i++) {
    if (isCuriousNum(i)) {
      sum += i;
      allCuriousNums.push_back(i);
    }
  }
  tf = get_time();
  std::cout << "all curious numbers:";
  for_each(allCuriousNums.begin(), allCuriousNums.end(), [](int &n) {
      std::cout << n << ",";
  });
  std::cout << "\nsum of all curious numbers = " << sum << std::endl;
  std::cout << "it takes " << tf-t0 << "s" << std::endl;

  return 0;
}
