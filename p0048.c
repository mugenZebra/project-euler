#include <stdio.h>
#include <stdint.h>

void sol_online(void) {
  int i,j,r[2]={0},d[2]={0};
  for(i=1;i<=1000;i++)
  {
    d[0]=i;
    d[1]=0;
    for(j=1;j<i;j++)
    {
      d[0]*=i;
      d[1]*=i;
      if(d[0]>100000)
      {
        d[1]+=d[0]/100000;
        d[0]%=100000;
      }
      d[1]%=100000;
    }
    r[0]+=d[0];
    r[1]+=d[1];
    if(r[0]>100000)
    {
      r[1]+=r[0]/100000;
      r[0]%=100000;
    }
    r[1]%=100000;
  }
  printf("%05d,%05d\n",r[1],r[0]);
  return;
}

void sol_my(void) {
  uint64_t sum = 0; 

  for (int i = 1; i <= 1000; i++) {
    uint64_t tmp = i;
    for (int j = 0; j < i-1; j++) { // tmp has one already
      tmp *= i;
      //* method 1
      if (tmp >= 10000000000) { // no need more than 10 digit
        tmp %= 10000000000; // truncate digit higher than 10th digit
      }
      //*/

      /* method 2
      if (tmp & 0x00400000000) { // no need more than 10 digit
        tmp &= 0x003FFFFFFFF;
      }
      //*/
    }
    sum += tmp; 
    if (sum >= 10000000000) { // no need more than 10 digit
      sum %= 10000000000; // truncate digit higher than 10th digit
    }
  }

  printf("%llu\n", sum); // ans = 9110846700
  return;
}

int main() {

  sol_my();
  //sol_online();
  return 0;
}
