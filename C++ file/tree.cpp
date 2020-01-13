#include<iostream>
#include<vector>
#include<algorithm>
#include"tree.h"
#include"hanshu.h"
using namespace std;

Tree::Tree(vector<float> &vec)
{
  root = new Node;
  root->vec = vec;
}




Node* Tree::genTree(Node *node, vector<int> &attr_list)
{
  int majority = 0;
  ffind fin1;
  int i;
  // 判断多数类别
  for(i = 4; i < node->vec.size(); i = i + 5)
  {
    if (node->vec[i] == 0)
      fin1.j++;
    else if (node->vec[i] == 1)
      fin1.k++;
    else if (node->vec[i] == 2)
      fin1.l++;
  }
  //cout<<"j k l:"<<fin1.j<<" "<<fin1.k<<" "<<fin1.l<<" "<<endl;
  majority = max<int>(fin1.j, fin1.k);
  majority = max<int>(majority, fin1.l);
  if (majority == fin1.j)
    majority = 0;
  else if (majority == fin1.k)
    majority = 1;
  else if (majority == fin1.l)
    majority = 2;

  //cout<<"多数 "<<majority<<endl;
  // 判断是否属于同一类别
  if ((fin1.l == 0 && fin1.j == 0) || (fin1.k == 0 && fin1.j == 0) || (fin1.k == 0 && fin1.l == 0))
  {
    node->leaf = 1;
    node->leibie = majority;
    //cout<<"1 leibie "<<majority<<endl;
    return node;
  }
  // 判断attr_list是否为空
  if (attr_list.size() == 0)
  {
    node->leaf = 1;
    node->leibie = majority;
    //cout<<"2 leibie "<<majority<<endl;
    return node;
  }

  attr_gain *a;
  a = Split_attr(node->vec, fin1, attr_list);
  //cout<<"mid "<<a->mid<<endl;
  //cout<<"分类属性 "<<a->attribute<<endl;
  // 除去这个attribute
  for(i = 0; i < attr_list.size(); i++)
  {
    if (a->attribute == attr_list[i])
    {
      attr_list.erase(attr_list.begin()+i);
    }
  }
  //Print(attr_list);

  // 生成Dj
  split_vec *b;
  b = Split_vec(node->vec, a->mid, a->attribute);
  Node *Left = new Node;
  Node *Right = new Node;
  Left->vec = b->smvec;
  Right->vec = b->bevec;
  if (Left->vec.size() == 0)
  {
    Left->leaf = 1;
    Left->leibie = majority;
    //cout<<"3 leibie "<<majority<<endl;
  }
  if (Right->vec.size() == 0)
  {
    Right->leaf = 1;
    Right->leibie = majority;
    //cout<<"4 leibie "<<majority<<endl;
  }
  node->left = Left;
  node->right = Right;
  node->split_attri = a->attribute;
  node->split_value = a->mid;
  //cout<<"<<<<<"<<endl;
  //Print(Left->vec);
  Left = genTree(Left, attr_list);
  Right = genTree(Right, attr_list);
  //Left = ggenTree(Left, attr_list);

  //cout<<endl;
  delete b;
  b = NULL;
  return node;
}
