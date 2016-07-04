/**
 * 
 * my solution takes 0.9s.
 */
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>


bool is_pandigital(uint64_t N);
bool check_property(std::vector<uint8_t> & digits);
std::vector<uint8_t> break2Digits(uint64_t n);
uint64_t formNum(std::vector<uint8_t> & digits);

void sol_from_forum() {
  // this solution doesn't calculate the sum
  char ca[]="0123456789";
  int i, j, err, checker, check[7]={2,3,5,7,11,13,17};

  uint64_t sum = 0;
  for(i=0;i<3628800;i++)
  {
    std::next_permutation(ca,ca+10);

    for(err=0,j=0;j<7;j++)
    {
      checker=100*(ca[j+1]-48)+10*(ca[j+2]-48)+(ca[j+3]-48);
      if(checker%check[j]!=0)
      {err=1;break;}
    }
    if(err==0)
      std::cout << ca << std::endl;
    // sum is simply printed out as a string.
  }
}

int main() 
{
  //assert(check_property(1406357289) == true);
  //sol_from_forum();

  uint64_t sum = 0;
  /* this is too slow...
  uint32_t i;
  for (i = 123456789; i <= 9876543210; i++) {
    if (is_pandigital(i) && check_property(i)) {
      sum += i;
    }
  }
  printf("sum=%llu\n", sum);
  //*/
  //*
  std::vector<uint8_t> digits = break2Digits(1234567890);
  while (std::next_permutation(digits.begin(), digits.end())) {
    if (check_property(digits)) { // don't need to check is pandigital 
      sum += formNum(digits);
    }
  }
  printf("sum=%llu\n", sum); // need to print as long long unsigned.
  //*/

  return 0;
}

bool check_property(std::vector<uint8_t> & digits)
{
  static const int divisors[] = {17, 13, 11, 7, 5, 3, 2};
  int i = 0; 
  for (std::vector<uint8_t>::iterator it = digits.begin();
       it != digits.end() && i < 7; it++, i++) {
    if (((*(it+2) * 100 + *(it+1) * 10 + *it) % divisors[i]) != 0) {
      return false;
    }
  }
  return true;
}

/**
 * check if it's 0 to 9 pandigital number.
 */
bool is_pandigital(uint64_t N) 
{
  /*
  if (N > 9876543210 || N < 123456789) { // largest and smallest 0-to-9 digit pandigital
    return false;
  }
  //*/
  uint16_t has_digit = 0; 
  while (N > 0) {
    has_digit |= 1u << (N % 10);
    N /= 10;
  }
  return has_digit == 0x03FF;
}

/**
 * turn a number to a vector of digits.
 * NOTE:the least significant digit is at the front of the vector.
 */
std::vector<uint8_t> break2Digits(uint64_t n) {
  std::vector<uint8_t> digits;
  while (n > 0) {
    digits.push_back(n % 10);
    n /= 10;
  }
  return digits;
}
/**
 * turn a vector of digits to a number.
 * NOTE:the least significant digit is at the front of the vector.
 */
uint64_t formNum(std::vector<uint8_t> & digits) {
  uint64_t num = 0;
  uint64_t multiplier = 1;
  for (std::vector<uint8_t>::iterator it = digits.begin();
       it != digits.end(); it++) {
    num += *(it) * multiplier; 
    multiplier *= 10;
  }
  return num;
}
