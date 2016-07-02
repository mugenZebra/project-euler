/**
 * Tn=Pn=Hn
 * n(n+1)/2 = n(3n-1)/2 = n(2n-1)
 * (nT=285, nP=165, nH=143) => 40755
 * find the next Tn
 * so nT > 285, nP > 165, nH > 143
 *
 * assume n's are equal, find out how they compare:
 * n^2+n [?] 3n^2-n [?] 4n^2-2n
 * let n approach inf, 1st order term drops,
 * n^2 [?] 3n^2 [?] 4n^2 
 *      <        <
 *
 * algorithm
 * 1. calculate the next Hn, b/c Hn has the largest intervals
 * 2. calculate next Pn up to Hn
 *    a. if Pn and Hn are not equal then back to (1) 
 *    b. if equal then calculate next Tn and do the same check as in (a)
 * **worm crawling algorithm
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
/*
uint32_t Tn(uint32_t n)
{
  return (n*n + n)/2;
}

uint32_t Pn(uint32_t n)
{
  return (3*n*n - n)/2;
}

uint32_t Hn(uint32_t n)
{
  return (2*n*n - n);
}
//*/

//* tablize squares
static uint32_t nSqrt[70000];

uint32_t Tn(uint32_t n)
{ 
  if (nSqrt[n] == 0) {
    nSqrt[n] = n*n;
  }
  return (nSqrt[n] + n)/2;
}

uint32_t Pn(uint32_t n)
{
  if (nSqrt[n] == 0) {
    nSqrt[n] = n*n;
  }
  return (3*nSqrt[n] - n)/2;
}

uint32_t Hn(uint32_t n)
{
  if (nSqrt[n] == 0) {
    nSqrt[n] = n*n;
  }
  return (2*nSqrt[n] - n);
}
//*/


uint32_t main() 
{
  uint32_t nH = 144, nP = 166, nT = 286;
  bool notEqual = true;
  uint32_t next_Tn = 1,next_Pn = 2,next_Hn = 3;
  while (notEqual) { 
    // 1. calculate the next Hn, Hn has the largest intervals
    next_Hn = Hn(nH++);  
    /* 
    if (next_Hn == next_Pn) {
      while ((next_Tn = Tn(nT++)) < next_Hn);
      if (next_Tn == next_Hn) {
        notEqual = false;
        break;
      }
    }
    //*/
    
    // 2. calculate next Pn up to Hn
    while ((next_Pn = Pn(nP++)) < next_Hn);
    //    a. if Pn and Hn are not equal then back to (1) 
    if (next_Pn == next_Hn) {
      //b. if equal then calculate next Tn and do the same check as in (a)
      while ((next_Tn = Tn(nT++)) < next_Hn);
      if (next_Tn == next_Hn) {
        notEqual = false;
      }
    }
    //printf("%d,%d,%d\n", next_Hn, next_Pn, next_Tn);
  }  

  printf("the next Tn is %d\nnT=%d, nP=%d,nH=%d\n", next_Tn,nT,nP,nH);
  return 0;
}
