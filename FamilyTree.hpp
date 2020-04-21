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

class node{

private:

  char G;
  int height;
  string name;
  node *left;
  node *right;

public:

   node(){
   name=nullptr;
   left=NULL;
   right=NULL;
   height=0;
   G='m';
  }
  
  node(string n){
   name=n;
   left=NULL;
   right=NULL;
   height=0;
   G='m';
  }

  ~node(){
   this->setname();
   delete this->left;
   delete this->right;
  }
  
  void setname();
  void setname(string name);
  string getname();
  void setheight(int height);
  int getheight();
  void setleft(string name, int height);
  node *getleft();
  void setright(string name, int height);
  node *getright();
  node *search(node *leaf,string name);
  void setGender(char g);
  char getGender();
  string find(int height,char gender);
  void print2D(node *root);
  void print2DUtil(node *root, int space);
  void Remove(node *leaf,string name);
  node *searchParent(node *leaf,string name);
}; //node

class Tree{

private:

node *root;  

public:

  Tree(string n){
    this->root=new node(n);
  }

  ~Tree(){
    remove(this->root->getname());
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