#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int split_attri = 10;
	float split_value = 10;
	Node *left = NULL;
	Node *right = NULL;
  vector<float> vec;

  int leaf = 12;
  int leibie = 13;
	int yuanben_leibie = 14;
};

class Tree{
  public:
    Tree(vector<float> &vec);
  	Node* genTree(Node *node, vector<int> &attr_list);
  public:
    Node *root;
};


#endif
