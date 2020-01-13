#ifndef HANSHU_H
#define HANSHU_H
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include"tree.h"
using namespace std;

struct ffind
{
  int j = 0;
  int k = 0;
  int l = 0;
};

struct attr_gain
{
  int attribute = 0;
  float gain = 0;
  float mid = 0;
};

struct split_vec
{
  vector<float> smvec;
  vector<float> bevec;
};

vector<string> to_number(vector<string> &vec2);
void Print(vector<float> &vec);
void Print(vector<string> &vec);
void Print(vector<int> &vec);
vector<float> convert_int(vector<string> &vec2);
vector<int> Rand105();
vector<string> readfile(string &a);
void write(vector<int> &vec, vector<float> &vec1, string &a);
vector<float> pre_process();
vector<float> read_test(string &a);
float operator / (ffind &fin, int all);
float info1 (int &m, int &n, int all, ffind fin1, ffind fin2);
float info (int all, ffind &fin);
attr_gain *Split_attr(vector<float> &vec22, ffind &fin1, vector<int> &attr_list);
split_vec *Split_vec(vector<float> &vec22, float &mid, int &attr);
//void traverse (Node *node);
void test(Node *node, vector<float> &vec);
void pre_test(Node *node, vector<float> &vec);
void DTI_alg();

#endif
