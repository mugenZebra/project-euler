#include <iostream>
#include <vector>
#include <cassert>
#include <set>
#include <cmath>
using namespace std;

/* input: an integer, n
 * output: the sum of all proper divisors of n
 * example: sumOfProperDivisor(12) == 16
 */
int sumOfProperDivisor(int n);

/* input: int, n
 * output: true if sumOfProperDivisor(n) > n, otherwise false.
 * example: isAundantNum(12) == true
 */
bool isAbundantNum(int n);

// others' functions
int isAbundant(int x);
int sum_of_divisors(int);
bool is_abundant(int j);

int main()
{
    vector<int> allAbundantNum;
    set<int> allSumOfTwoAbundantNumber;
    unsigned sum = 0;

    assert(sumOfProperDivisor(12) == 16);
    assert(sumOfProperDivisor(28) == 28);
    //assert(sum_of_divisors(12) == 16);
    //assert(sum_of_divisors(28) == 28);
    assert(isAbundantNum(12) == true);
    assert(isAbundantNum(28) == false);

    /** find all abundant numbers given that the largest abundant number does not exceed 28123 */
    for (int i = 1; i < 28123; i++) {
      if (is_abundant(i)) {
        allAbundantNum.push_back(i);
      }
    }

    /** insert all possible combinations of sum of two abundant numbers to a set */
    for (vector<int>::iterator i = allAbundantNum.begin(); i != allAbundantNum.end(); ++i) {
      for (vector<int>::iterator j = i; j != allAbundantNum.end(); ++j) {
        allSumOfTwoAbundantNumber.insert(*i + *j);
      }
    }

    /** if a number smaller than 28123 does not exist in the set of allSumOfTwoAbundantNumber, sum it up */
    for (int i = 1; i <= 28123; i++) {
      if (allSumOfTwoAbundantNumber.find(i) == allSumOfTwoAbundantNumber.end()) {
        sum += i;
      }
    }
    cout << "Sum of all number that cannot be written as sum of two abundant number is " << sum << endl;
    return 0;
}

int sumOfProperDivisor(int n) {
  int sum = 1;
  for (unsigned i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }
  return sum;
}

// other's code
int sum_of_divisors(int n){
  int prod=1;
  for(int k=2;k*k<=n;++k){
    int p=1;
    while(n%k==0){
      p=p*k+1;
      n/=k;
    }
    prod*=p;
  }
  if(n>1)
    prod*=1+n;
  return prod;
}


bool isAbundantNum(int n) {
  return sumOfProperDivisor(n) > n;
  //return sum_of_divisors(n) > n;
}

// others code
int isAbundant(int x){
    int i,sum=1,l;
    l=sqrt(x);
    for(i=2;i<=l;i++){
        if(x%i==0){
            sum+=i+(x/i);
    }
   }
   sum=(l*l==x)?(sum-l):sum;
    if(sum>x)return 1;
}

// other's code
bool is_abundant(int j)
{
     int divisors = 0;
     for (int n = 2; n * n <= j; n++)
     {
         if (!(j % n))
         {
            divisors += n;
            if (n < j / n)
               divisors += j / n;
            if (j <= divisors)
               return true;
         }
     }
     return j <= divisors;
}
