#include<iostream>
#include"hanshu.h"
#include"tree.h"
#include<time.h>
using namespace std;


int main()
{
  clock_t start, end;
  start = clock();
  DTI_alg();
  end = clock();
  cout<<endl;
  cout<<"Programme execute time："<<(double)(end - start)/CLOCKS_PER_SEC<<endl<<endl;

  return 0;
}
