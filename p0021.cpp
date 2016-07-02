#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Factor{
    unsigned fac;
    unsigned exp;
};
const int LIMIT = 10000;

int getAmicableSum(vector<Factor>, int);
vector<Factor> findPrimeFactors(int);

int main()
{
  /*
    vector<int> amicableSums;
    int sum = 0, temp;
    for (int i = 1; i <= LIMIT; i++) {
        amicableSums.push_back(getAmicableSum(findPrimeFactors(i), i));
    }

    for (int i = 1; i < LIMIT + 1; i++) {
        temp = amicableSums[i];
        for (int j = i + 1; j < LIMIT; j++) {
            if (temp == amicableSums[j]) {
                sum += i;
                sum += j;

                amicableSums[i] = 0;
                amicableSums[j] = 0;
            }
        }
    }
    cout << sum << endl;
*/
    return 0;
}




int getAmicableSum(vector<Factor> factors, int num) {
    int permutations = 1, sum = 1, product, expon, tempExpon;
    int facNum = factors.size(), layer = facNum - 1;
    int i, j, decrExpon;
    vector<unsigned> exponArr, divisors;

    for (i = 0; i < factors.size(); i++) {
        permutations *= factors[i].exp + 1;
        exponArr.push_back(factors[i].exp);
    }

    for (i = 0; i < permutations; i++) {
      product = 1;

      for (j = 0; j < facNum; j++) {
        product *= pow(factors[j].fac, factors[j].exp);
      }

      if (factors[layer].exp > 0) {
        factors[layer].exp--;
      } else {
        factors[layer].exp = exponArr[layer]; // restore
        layer--;
      }




      for (decrExpon = 1; decrExpon < facNum - 1; decrExpon++) {
        ;
      }

    }

}

// function to find all the prime factors
vector<Factor> findPrimeFactors(int num) {
    int prevFactor;
    vector<Factor> factors;
    Factor temp;

    for (int i = 2; i <= num; i++) {
        temp.exp = 0;
        while (num % i == 0) {
            temp.fac = i;
            temp.exp++;
            if (prevFactor == i && factors.empty() == false) {
                factors.pop_back();
            }
            factors.push_back(temp);
            num /= i;
            prevFactor = i;
        }
        if (i >= 3) {
            i++;
        }
    }

    return factors;
}
