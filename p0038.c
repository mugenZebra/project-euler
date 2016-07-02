#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

/**
 * What is the largest_sum 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer, N,  with (1,2, ... , n) where n > 1?
 *
 * 1 to 9 pandigital is a number that contain all the digits 1 to 9.
 *
 * so a 9 digit number that contains digits 1 to 9, and n > 1.
 *
 * largest number of digit of N is 4, as it cannot be 5. 
 * smallest n is 2, largest_sum n is 9 when N is 1 -> 123456789.
 * 2 <= n <= 9
 * 1 <= N <= 9999
 *
 */

bool is_9_digit_1_to_9_pandigital(int N);
int get_num_of_digit(int N);

int main() {
  /* unit testing for functions
  assert(is_9_digit_1_to_9_pandigital(123456789) == true);
  assert(is_9_digit_1_to_9_pandigital(192384576) == true);
  assert(is_9_digit_1_to_9_pandigital(111111111) == false);
  assert(is_9_digit_1_to_9_pandigital(19238457) == false);
  assert(is_9_digit_1_to_9_pandigital(1234567890) == false);
  assert(get_num_of_digit(0) == 1);
  assert(get_num_of_digit(1) == 1);
  assert(get_num_of_digit(123456789) == 9);
  //*/

  uint32_t largest_sum = 0, largest_sum_N = 1, largest_sum_n = 2;
  int num = 0;
  //for (int n = 2; n <= 2; n++) {
  for (int n = 2; n <= 9; n++) {
    //for (int N = 9000; N <= 9999; N++) {
    for (int N = 1; N <= 9999; N++) {
      // check if a concatenated product has 9 digits
      int total_num_of_digit = get_num_of_digit(N); // exclude n=1
      bool has_more_than_9_digits= false;
      uint64_t sum = N; // exclude N*1
      for (int i = 2; i <= n; i++) {
        int product = N*i;
        int num_digit = get_num_of_digit(product); 
        total_num_of_digit += num_digit; 
        if (total_num_of_digit > 9) {
          has_more_than_9_digits = true; 
          break; 
        }
        sum *= pow(10, num_digit); // make space for concatenating value
        sum += product;
        //printf("N=%d, n=%d, sum = %llu\n", N, n, sum);
      }
      if (total_num_of_digit < 9 || has_more_than_9_digits == true ) {
        continue;
      }
      if (is_9_digit_1_to_9_pandigital(sum)) {
        num++;
        if (sum > largest_sum) {
          largest_sum = sum;
          largest_sum_N = N;
          largest_sum_n = n;
        }
      }
    }
  }

  printf("N=%d, n=%d, largest_sum = %llu\n", largest_sum_N, largest_sum_n, largest_sum);
  printf("There are %d 9-digit 1 to 9 pandigital\n", num);
  return 0;
}

bool is_9_digit_1_to_9_pandigital(int N) {
  if (N > 987654321 || N < 123456789) { // largest and smallest 9 digit pandigital
    return false;
  }
  uint16_t has_digit = 0; 
  while (N > 0) {
    has_digit |= 1u << (N % 10);
    N /= 10;
  }
  return has_digit == 0x03FE;
}

int get_num_of_digit(int N) {
  /* traditional method
  if (N == 0) {
    return 1;
  }
  int num = 0;
  while (N > 0) {
    num++;
    N /= 10;
  }
  return num;
  //*/

  //* optimized
  int n = 1; 
  if (N >= 100000000){N /= 100000000; n += 8;}
  if (N >= 10000){N /= 10000; n += 4;}
  if (N >= 100){N /= 100; n += 2;}
  if (N >= 10){N /= 10; n += 1;}
  return n;
  //*/
}
