#include <string>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdbool.h>
#include<bits/stdc++.h> 
using namespace std;

#define COUNT 10 
#ifndef FamilyTree
#define FamilyTree

namespace family{



class Tree{

public:

class node{

public:

  char G;
  int height;
  string name;
  node *left;
  node *right;

   node(){
   this->name=nullptr;
   this->left=NULL;
   this->right=NULL;
   this->height=0;
   this->G='m';
  }
  
  node(string n){
   this->name=n;
   this->left=NULL;
   this->right=NULL;
   this->height=0;
   this->G='m';
  }

  void setname(string name);
  string getname();
  void setheight(int height);
  int getheight();
  void setleft(string name, int height);
  node *getleft();
  void setright(string name, int height);
  node *getright();
  node *search(string name);
  void setGender(char g);
  char getGender();
  string find(int height,char gender);
  void print2D(node *root);
  void print2DUtil(node *root, int space);
  void Remove(node *leaf);
}; //node



  node *root;

  Tree(string n)
  {
    this->root = new node();
    this->root->name=n;
  }
  ~Tree()
  {
    remove(this->root->name);
    delete(this);
  }

  Tree& addFather(string son, string father);
  Tree& addMother(string son, string mother);
  string find(string relation);
  string relation(string name);
  void remove(string name);
  void display();

  }; //Tree

}; // namespace family
#endif