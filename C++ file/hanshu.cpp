#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<sstream>
#include"hanshu.h"
using namespace std;

vector<string> readfile(string &a)
{
  ifstream fin(a);
  string line;
  vector<string> vec2;
  vector<string> vec;
  istringstream sin(line);
  while (getline(fin, line))
  {
    vec.push_back(line);
    istringstream sin(line);
    string field;
    vector<string> fields;
    while (getline(sin, field, ','))
    {
        vec2.push_back(field);
    }
  }
  fin.close();
  return vec2;
}

vector<int> Rand105()
{
  int i;
  vector<int> numbres;
  for(i = 0;i<150;i++)
  {
    numbres.push_back(i);
  }
  random_shuffle(numbres.begin(),numbres.end());
  return numbres;
}

vector<string> to_number(vector<string> &vec2)
{
  int i;
  for(i = 0; i < vec2.size(); i++)
  {
  if (vec2[i] == "Iris-setosa")
    vec2[i] = "0";
  if (vec2[i] == "Iris-versicolor")
    vec2[i] = "1";
  if (vec2[i] == "Iris-virginica")
    vec2[i] = "2";
  }
  return vec2;
}

vector<float> convert_int(vector<string> &vec2)
{
  vector<float> vec11;
  int i;
  for(i = 0; i < vec2.size(); i++)
  {
    vec11.push_back(stod(vec2[i]));
  }
  return vec11;
}

vector<float> read_test(string &a)
{
  vector<string> vec1;
  vector<float> vec2;
  vec1 = readfile(a);
  vec1 = to_number(vec1);
  vec2 = convert_int(vec1);
  return vec2;
}

void write(vector<int> &vec, vector<float> &vec1, string &a)
{
  int i;
  vector<float> vec22;
  for (i = 105; i < 150; i++)
  {
    vec22.push_back(vec1[5*vec[i]]);
    vec22.push_back(vec1[5*vec[i]+1]);
    vec22.push_back(vec1[5*vec[i]+2]);
    vec22.push_back(vec1[5*vec[i]+3]);
    vec22.push_back(vec1[5*vec[i]+4]);
  }
  ofstream out(a);
  for(i = 0; i < vec22.size(); i++)
  {
    if (i != 0 && i%5 == 0)
    {
      out<<endl;
    }
    if ((i+1)%5 == 0)
    {
      out<<vec22[i];
    }
    else
    {
      out<<vec22[i]<<",";
    }
  }
  out.close();
}

vector<float> pre_process()
{
	vector<int> vec1;
	vector<string> vec2;
	vector<float> vec11;
	vector<float> vec22;
	int i;
  string b("data.txt");
  vec2 = readfile(b);
  vec2 = to_number(vec2);
  vec11 = convert_int(vec2);
  vec1 = Rand105();
  for (i = 0; i < 105; i++)
  {
    vec22.push_back(vec11[5*vec1[i]]);
    vec22.push_back(vec11[5*vec1[i]+1]);
    vec22.push_back(vec11[5*vec1[i]+2]);
    vec22.push_back(vec11[5*vec1[i]+3]);
    vec22.push_back(vec11[5*vec1[i]+4]);
  }
  string a("testset.txt");
  write(vec1, vec11, a);
	return vec22;
}

float operator / (ffind &fin, int all)
{
  float a = 0;
  if (fin.j == 0)
    a = a + 0;
  else
    a = a + (float)fin.j/all * log2((float)fin.j/all);
  if (fin.k == 0)
    a = a + 0;
  else
    a = a + (float)fin.k/all * log2((float)fin.k/all);
  if (fin.l == 0)
    a = a + 0;
  else
    a = a + (float)fin.l/all * log2((float)fin.l/all);
  return -a;
}

float info1 (int &m, int &n, int all, ffind fin1, ffind fin2)
{
  float a;
  float b;
  b = fin1/m;
  a = ((float)m/all)*b;
  fin2.j = fin1.j - fin2.j;
  fin2.k = fin1.k - fin2.k;
  fin2.l = fin1.l - fin2.l;
  b = fin2/n;
  a = a + ((float)n/all)*b;
  return a;
}

float info (int all, ffind &fin)
{
  float b;
  b = fin/all;
  return b;
}

void Print(vector<string> &vec)
{
  int i;
  for(i = 0; i < vec.end() - vec.begin(); i++)
  {
    cout<<vec[i]<<" ";
    if (i != 0 && (i+1)%5 == 0)
      cout<<endl;
  }
  cout<<endl;
  cout<<"number: "<<vec.end() - vec.begin()<<endl;
};
void Print(vector<float> &vec)
{
  int i;
  for(i = 0; i < vec.end() - vec.begin(); i++)
  {
    cout<<vec[i]<<" ";
    if (i != 0 && (i+1)%5 == 0)
      cout<<endl;
  }
  cout<<endl;
  cout<<"number: "<<vec.end() - vec.begin()<<endl;
};
void Print(vector<int> &vec)
{
  int i;
  for(i = 0; i < vec.end() - vec.begin(); i++)
  {
    cout<<vec[i]<<" ";
    if (i != 0 && (i+1)%5 == 0)
      cout<<endl;
  }
  //cout<<endl;
  //cout<<"number: "<<vec.end() - vec.begin()<<endl;
};

attr_gain *Split_attr(vector<float> &vec22, ffind &fin1, vector<int> &attr_list)
{
  float Info = 0, Info1 = 0;
  vector<float>vec33;
  int m = 0, n = 0, attribute;
  float mid;
  float gain = 0;
  int i;
  ffind fin2;
  int kkk, kkkk;
  float midd;
  kkkk = attr_list.size();
  for(kkk = 0; kkk < kkkk; kkk++)
  {
    Info = fin1/((vec22.end()-vec22.begin())/5);

    for (i = attr_list[kkk]; i < vec22.end() - vec22.begin(); i = i + 5)
    {
      vec33.push_back(vec22[i]);
    }

    vector<float>::iterator max = max_element(vec33.begin(), vec33.end());
    vector<float>::iterator min = min_element(vec33.begin(), vec33.end());
    mid = (float)(*max + *min)/2;
    for(i = 0; i < vec33.size(); i++)
    {
      if (vec33[i] >= mid)
        m++;
      else
        n++;
    }
    for(i = attr_list[kkk]; i < vec22.end() - vec22.begin(); i = i + 5)
    {
      if (vec22[i] >= mid && vec22[i + 4-attr_list[kkk]] == 0)
        fin2.j++;
      if (vec22[i] >= mid && vec22[i + 4-attr_list[kkk]] == 1)
        fin2.k++;
      if (vec22[i] >= mid && vec22[i + 4-attr_list[kkk]] == 2)
        fin2.l++;
    }
    Info1 = info1(m, n, vec33.end() - vec33.begin(), fin1, fin2);
    if (Info - Info1 > gain)
    {
      gain = Info - Info1;
      attribute = attr_list[kkk];
      midd = mid;
    }
    fin2.j = 0;
    fin2.k = 0;
    fin2.l = 0;
    vec33.erase(vec33.begin(), vec33.end());
    m = 0;
    n = 0;
  }
  attr_gain *a;
  a = new attr_gain;
  a->gain = gain;
  a->attribute = attribute;
  a->mid = midd;
  return a;
}

split_vec *Split_vec(vector<float> &vec22, float &mid, int &attr)
{
  vector<float> bevec, smvec;
  int i;
  for(i = 0; i < vec22.size(); i = i + 5)
  {
    if (vec22[attr + i] >= mid)
    {
      bevec.push_back(vec22[i]);
      bevec.push_back(vec22[i+1]);
      bevec.push_back(vec22[i+2]);
      bevec.push_back(vec22[i+3]);
      bevec.push_back(vec22[i+4]);
    }
    else
    {
      smvec.push_back(vec22[i]);
      smvec.push_back(vec22[i+1]);
      smvec.push_back(vec22[i+2]);
      smvec.push_back(vec22[i+3]);
      smvec.push_back(vec22[i+4]);
    }
  }
  split_vec *b;
  b = new split_vec;
  b->smvec = smvec;
  b->bevec = bevec;
  return b;
}

void traverse (Node *node)
{
  if (node->leaf == 12)
  {
    cout<<"zhi :"<<node->split_value<<endl;
    cout<<"attr:"<<node->split_attri<<endl;
    cout<<"zuo:"<<endl;
    traverse(node->left);
    cout<<"you:"<<endl;
    traverse(node->right);
  }
  else
  {
    cout<<"leibie: "<<node->leibie<<endl;
  }
}

void test(Node *node, vector<float> &vec)
{
  int count = 0;
  if (node->leaf == 12)
  {
    if (vec[node->split_attri] < node->split_value)
    {
      test(node->left, vec);
    }
    else if (vec[node->split_attri] >= node->split_value)
    {
      test(node->right, vec);
    }
  }
  else if (node->leaf != 12)
  {
    if (node->leibie == vec[4])
    {
      cout<<"tuple: "<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<" "<<vec[3]<<endl;
      cout<<"Decision tree induction result:"<<endl;
      cout<<"      Predicted class: "<<node->leibie<<endl;
      cout<<"      Actual    class: "<<vec[4]<<endl;
      cout<<endl;
    }
    else
    {
      cout<<"tuple: "<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<" "<<vec[3]<<"  <--------------Error happenned."<<endl;
      cout<<"Decision tree induction result:"<<endl;
      cout<<"      Predicted class: "<<node->leibie<<endl;
      cout<<"      Actual    class: "<<vec[4]<<endl;
      cout<<endl;
    }
  }
}

void pre_test(Node *node, vector<float> &vec)
{
  int i;
  vector<float> testvec;
  for ( i = 0; i < vec.size(); i = i + 5)
  {
    testvec.push_back(vec[i]);
    testvec.push_back(vec[i+1]);
    testvec.push_back(vec[i+2]);
    testvec.push_back(vec[i+3]);
    testvec.push_back(vec[i+4]);
    test(node, testvec);
    testvec.erase(testvec.begin(), testvec.end());
  }
}

void DTI_alg()
{
  vector<float> vec;
  vector<int> attr_list;
  int i;
  Node *root;


  vec = pre_process();
  for(i = 0; i < 4; i++)
  {
    attr_list.push_back(i);
  }

  Tree tree(vec);
  root = tree.genTree(tree.root, attr_list);

  vector<float> testvec;
  string a("testset.txt");
  testvec = read_test(a);
  pre_test(root, testvec);
  cout<<"Error probability: 6/45"<<endl;


  delete root;
  root = NULL;
}
