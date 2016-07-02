#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void quicksort(vector<string>& names);
void bubblesort(vector<string>& names);
int charValue(string word);


int main()
{
  ifstream fin;
  string name;
  ofstream fout;
  int sum = 0;

  fin.open("names.txt");
  fout.open("output.txt");
  if (fin.is_open())
  {

    std::cout << "Operation successfully performed\n";

  } else
  {
    cout << "couldn't open file" << endl;
    return 0;
  }

    string test;

  vector<string> stringVec;

  int i = 0;
  while (!fin.eof())
  {
    getline(fin, name,',');
    name.erase(0,1);
    name.erase(name.length() - 1, 1);
    stringVec.push_back(name);
//    cout << endl << stringVec[i];
    i++;
  }

  //bubblesort(stringVec);
  sort(stringVec.begin(), stringVec.end());
  for (i=0;i < stringVec.size();i++)
  {
    //cout << endl << stringVec[i];
    sum = sum + charValue(stringVec[i])*(i+1);
    //fout << stringVec[i] << ' ' << charValue(stringVec[i]) << endl;
  }


  cout << "THE SUM IS: " << sum ;

    return 0;
}


void bubblesort(vector<string>& names)
{
   unsigned int i;
   unsigned int j;
   string temp;

  for( i=0; i < names.size(); i++)
  {
    for (j=0; j< names.size() - 1; j++)
    {
       if (names[j] > names[j+1])
       {
          temp = names[j];
          names[j] = names[j+1];
          names[j+1] = temp;
       }
    }
  }

}

void quicksort(vector<string>& names, short fp, short bp)
{

}



int charValue(string word)
{
  int i;
  int sum = 0;

  for(i=0; i < word.length(); i++)
    sum = sum + word[i] - 'A' + 1;

  return sum;
}
