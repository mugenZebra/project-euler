#include <stdio.h>
#include <math.h>

/*
 * Q: Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 * 
 * Analysis:
 * There should be an upper bound. 
 * The maximum value of sum of digits of a N digit number is N*9^5 -- (1)
 * The maximum value of a N digit number is sum of 9*10^k , -- (2)
 * where 0 <= k <= N-1. 
 *
 * Question 1: can (1) be smaller than (2)? 
 * yes, when N = 1, (1)=1*9^5 = 9^5 = 59049
 * (2) = 9
 * when N = 2, (1) = 2*9^5,
 * (2) = 99
 *
 * Question 2: Is (1) always larger than (2)? 
 *   (1) < (2)
 * N*9^5 < 9*10^0 + 9*10^1 + ... + 9*10^(N-1)
 * N*9^4 < 10^0 + 10^1 + ... + 10^(N-1)
 * N*9^4 < (1 - 10^N) / (1 - 10)           (geometric series)
 * N*9^4*-9 > 1 - 10^N 
 * N*9^4*-9 - 1 > -10^N 
 * -N*9^5 - 1 > -10^N 
 * N*9^5 + 1 < 10^N 
 *
 * if for some N that (1) < (2), then we don't need to try to find within the range beyond N digit number, because (1) is always smaller than (2). 
 *
 * so N is found to be 6.
 *
 * The upper limit can be further induced from the fact that,
 * for a 6 digit number 6*9^5 < 
 */

int main() {
  // fine largest N
  uint32_t tmp1 = pow(9, 5);
  int N = 1;
  for (N = 1; N < 100000; N++) {
    if (N*tmp1 + 1 < pow(10, N)) {
      break;
    }
  }
  printf("N=%d\n", N);

  // make a table to fifth power of digit one to 9
  uint32_t table_fifth_pow[10] = {0};
  for (int i = 1; i < 10; i++) {
    table_fifth_pow[i] = pow(i, 5);
  }

  uint32_t sum = 0;
  uint32_t upper_bound = N*pow(9, 5);
  printf("upper bound= %d\n", upper_bound);
  for (int i = 2; i < upper_bound ; i++) { // i goes up to 6 digit number, and disregard 1.
    uint32_t sum_fifth_power = 0;
    uint32_t num = i;
    // extract digit and sum their fifth power
    while (num > 0) {
      sum_fifth_power += table_fifth_pow[num % 10];
      num /= 10;
    }

    if (sum_fifth_power == i) {
      sum += i;
    }
  }

  printf("%u\n", sum);

  return 0;
}


