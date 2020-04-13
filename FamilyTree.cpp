
#include <string>
#include <iostream>
#include <stdexcept>
#include<bits/stdc++.h> 
#include <stdbool.h>

using namespace std;

namespace MyTree{

    FamilyTree::Tree(string name)
    {
      root=new node();
      setname(name);
    }
    FamilyTree::~Tree()
    {
      if(this->left!=null){
        delete(this->left);
      }
      if(this->right!=null){
        delete(this->right);
      }
        delete(this);
    }
 
    FamilyTree::addFather(string name)
    {
      setright(name,this->height+1);
    }
    FamilyTree::addMoter(string name)
    {
       setleft(name,this->height+1);
    }
    FamilyTree::relation(string name,node* leaf)
    {
      cout<"de"<endl;
      return 
    }
    FamilyTree::find(string name,node* leaf)
    {
      cout<"dam"<endl;
    }
};