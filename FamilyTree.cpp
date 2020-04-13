
#include <string>
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
#include <stdbool.h>

using namespace std;

namespace family
{

void node::setname(string NewName){
   name=NewName;
}

void node::setheight(int h){
   height=h+1;;
}

string node::getname(){
   return name;
}

int node::getheight(){
  return height;
}

void node::setright(string name, int height)
{
  this->right=new node();
  this->right.setname(name);
  this->right.setheight(this.height);
}

void node::setleft(string name, int height)
{
  this->left=new node();
  this->left.setname(name);
  this->left.setheight(this.height);
}

node* node::getleft(){
  return this->left;
}
node* node::getright(){
  return this->right;
}

node* node::search(string name){
if(node::search(this->left,name)!=null){
    return node::search(this->left,name);
}
else if(node::search(this->right,name)!=null){
  return search(this->right,name);
}
else
{
  return null;
}
}




Tree::addFather(string son, string father)
{
  if(root->name.compare(son)!=0){
  setright(name, this->height + 1);
  }

  else if(node::search(son)==null){
    //throw
  }
  else{
    node temp=new node();

  }
}
Tree::addMoter(string name)
{
  setleft(name, this->height + 1);
}
Tree::relation(string name, node *leaf)
{
  cout < "de" < endl;
  return
}
Tree::find(string name, node *leaf)
{
  cout < "dam" < endl;
}
}; // namespace MyTree