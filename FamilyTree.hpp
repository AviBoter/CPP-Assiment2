#include <string>
#include <iostream>
#include <stdexcept>

#ifndef FamilyTree
#define FamilyTree

using namespace std;

namespace family
{

struct node
{
private:
  int height;
  string name;
  node *left;
  node *right;

public:
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
    root = new node();
    this->root.name=name;
    this->root.height=0;

  }
  ~Tree()
  {

    if (this->left != null)
    {
      delete (this->left);
    }
    if (this->right != null)
    {
      delete (this->right);
    }
    delete (this);
  }

  void addFather(string son, string father);
  void addMother(string son, string mother);
  string find(int key, node *leaf);
  string relation(string name, node *leaf);
  void delete (string name, node *leaf);
  void display(node *leaf);

  node *root;

}; //Tree
}; // namespace family
#endif