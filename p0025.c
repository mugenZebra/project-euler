/**
 * find the first 1000-digit fibonacci number.
 *
 * learned using GMP library to calculate big number.
 * compilation flag: -lgmp
 *
 * this solution takes about 0.31s on my computer.
 */
#include <gmp.h>
#include <stdio.h>
#include <stdint.h>

#define SIZE 10000
static mpz_t fibs[SIZE];

// recursive implementation with table
// cannot return mpz_t because mpz_t is an array as told by compiler 
mpz_t* fib(uint32_t n) {
  if (n > 0 && mpz_cmp_ui(fibs[n], 0) == 0) { // if equal, cmp_ui() return 0
    mpz_add(fibs[n], *fib(n - 1), *fib(n - 2)); 
  }
  return &fibs[n]; 
}

int main() {
  int i;
  for (i = 0; i < SIZE; i++) {
    mpz_init(fibs[i]); // init all values to 0 for using the table
  }
  mpz_set_ui(fibs[1], 1);
  mpz_set_ui(fibs[2], 1);
  i = 10;
  uint32_t digitNum = 0;
  //* brute force method
  while (digitNum != 1000) {
    digitNum = mpz_sizeinbase(*fib(i), 10);
    //printf("%d at %d\n", digitNum, i); // not sure why 4781th has 1000 digit
    i++;
  }
  //*/

  /* tried binary search, but fibonacci function I have is
  //  recursive function, which calculate all numbers.
  //  so it doesn't make a difference from brute force method.
  int left_bound = 1, right_bound = 5000;
  while (digitNum != 1000) {
    i = (left_bound + right_bound) / 2;
    digitNum = mpz_sizeinbase(*fib(i), 10);
    if (digitNum < 1000) {
      left_bound = i + 1;
    } else if (digitNum > 1000) {
      right_bound = i - 1;
    } else {
      break;
    }
    printf("%d at %d\n", digitNum, i);
  }
  printf("found a 1000-digit number\n");
  while (digitNum >= 1000) {
    digitNum = mpz_sizeinbase(*fib(i), 10);
    printf("%d at %d\n", digitNum, i);
    i--;
  }
  //*/

  //gmp_printf("%Zd\n", *fib(i)); // %Zd is to print mpz_t
  printf("the first 1000-digit Fibonacci number is "\
         "the %dth Fibonacci number.\n", i);
  return 0;
}
