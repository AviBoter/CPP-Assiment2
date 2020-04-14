#include <string>
#include <iostream>
#include <stdexcept>
#include <stdio.h>

#ifndef FamilyTree
#define FamilyTree
using namespace std;

namespace family
{

struct node
{
public:
  int height;
  string name;
  node *left;
  node *right;

  void setname(string name);
  string getname();
  void setheight(int height);
  int getheight();
  void setleft(string name, int height);
  node *getleft();
  void setright(string name, int height);
  node *getright();
  node *search(string name);

}; //node

class Tree
{
public:

  Tree(string name)
  {
    this->root = new node();
    this->root->name=name;
    this->root->height=0;

  }
  ~Tree()
  {

    if (this->root->left != NULL)
    {
      remove(this->root->left->name);
    }
    if(this->root->right != NULL)
    {
      remove(this->root->right->name);
    }
    else{
    delete(this);
    }
  }

  Tree& addFather(string son, string father);
  Tree& addMother(string son, string mother);
  string find(string relation);
  string relation(string name);
  void remove(string name);
  void display();

  node *root;

}; //Tree
}; // namespace family
#endif