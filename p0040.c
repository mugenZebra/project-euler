#include <stdio.h>
#include <stdint.h>

int main() {
  int n = 1; // for counting n-th digit, exclude d_1
  uint32_t sum = 1; // calculating the sum, exclude d_1
  int i = 2; // exclude 1 
  char buf[100] = "";
  while (n <= 1000000) {
    int tmp = i;
    int k = 0; // for selecting the k th digit starting from left
    while (tmp > 0) {
      n += 1;
      if (n == 10 || n == 100 || n == 1000 || n == 10000 || n == 100000 || n == 1000000) {
        sprintf(buf, "%d", i); // to get the k-th digit
        sum *= buf[k] - '0'; 
      }
      k += 1;
      tmp /= 10;
    }
    i++;
  }

  printf("sum = %d, d_1000000 = %d\n", sum, i);

  return 0;
}
