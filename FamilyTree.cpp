
#include <string>
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
#include <stdbool.h>
#include <stdio.h>
#include "FamilyTree.hpp"

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
  this->right->setname(name);
  this->right->setheight(this->height);
}

void node::setleft(string name, int height)
{
  this->left=new node();
  this->left->setname(name);
  this->left->setheight(this->height);
}

node* node::getleft(){
  return this->left;
}
node* node::getright(){
  return this->right;
}

node* node::search(string name){
// if(node::search(this->left,name)!=NULL){
//     return node::search(this->left,name);
// }
// else if(node::search(this->right,name)!=NULL){
//   return search(this->right,name);
// }
// else
{
  return NULL;
}
}




Tree& Tree::addFather(string son, string father)
{
  // if(root->name.compare(son)!=0){
    this->root->setright(father, this->root->height + 1);
  // }

  // else if(node::search(son)==null){
  //   //throw
  // }
  // else{
  //   node temp=new node();

  // }
  cout << "somewhere" << endl;
  return *this;
}
Tree& Tree::addMother(string son,string mother)
{
  this->root->setleft(mother, this->root->height + 1);
  cout << "over" << endl;
  return *this;
}

string Tree::relation(string name)
{
  cout << "the" << endl;
  return name;
}
string Tree::find(string name)
{
  cout << "rainbow" << endl;
  return name;
}
void Tree::remove(string name){
  cout << "removed" << endl;
  return;
}

void Tree::display(){
  cout << "look! a tree!" << endl;
}
}; // namespace MyTree