
#include <string>
#include <iostream>
#include <stdexcept>
#include <stdbool.h>
#include <stdio.h>
#include "FamilyTree.hpp"

using namespace std;

namespace family{

 void family::Tree::node::print2DUtil(node *root, int space){
   //print2DUtil copied from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions//
    if (root == NULL)  
        return;  

    space += COUNT;  
    family::Tree::node::print2DUtil(root->right, space);   
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->name<<"\n";  
  
    family::Tree::node::print2DUtil(root->left, space);  
}  
    
void family::Tree::node::print2D(node *root){  
    print2DUtil(root, 0);  
}   

void family::Tree::node::setname(string NewName){
   this->name=NewName;
}

void family::Tree::node::setheight(int h){
   height=h+1;;
}

string family::Tree::node::getname(){
   return name;
}

int family::Tree::node::getheight(){
  return height;
}
void family::Tree::node::setGender(char g){
   this->G=g;
}

void family::Tree::node::setright(string name, int height){
  this->right=new node(name);
  this->right->setheight(this->height);
  this->right->setGender('m');
}

void family::Tree::node::setleft(string name, int height){
  this->left=new node(name);
  this->left->setheight(this->height);
  this->left->setGender('f');
}

family::Tree::node* family::Tree::node::getleft(){
  return this->left;
}
family::Tree::node* family::Tree::node::getright(){
  return this->right;
}

string family::Tree::node::find(int height,char gender){
  string ans;

  if(height==1){
    if(gender=='m' && this->right!=nullptr)
       ans=this->right->name;
    if(gender=='f' && this->left!=nullptr)
     ans=this->left->name;
  
     return ans;
   }
   if(height>1){
    ans=this->left->find(height-1,gender);
    if(ans!="")
      return ans;
    ans=this->right->find(height-1,gender);
    if(ans!="")
      return ans;
   }
   return ans;
}

  node* family::Tree::search(string name){
  if(this->root){
    return NULL;
  }
  else if(this->name==name){
    return this;
  }
  else
  {
  node *temp;
  temp=this->left->search(name);
  if(temp!=nullptr)
    return temp;
  temp=this->right->search(name);
  if(temp!=nullptr)
    return temp;
 }
    return nullptr;
}

void family::Tree::node::Remove(node *leaf){
  if (leaf->left != nullptr)
    {
      family::Tree::node::Remove(leaf->left);
    }
    if(leaf->right != nullptr)
    {
      family::Tree::node::Remove(leaf->right);
    }
    delete(leaf);
}

Tree& family::Tree::addFather(string son, string father){
   if(this->root->search(son)==NULL)
   {
    throw logic_error{"Match not found"};
   }

   else if(root->name.compare(son)==0)
   {
    this->root->setright(father, this->root->height + 1);
   }

  else
   {
    node *temp=new node();
    temp=this->root->search(son);
     temp->setright(father,temp->height + 1);
   }
  return *this;
}

Tree& family::Tree::addMother(string son,string mother){
   if(this->root->search(son)==NULL)
   {
    throw logic_error{"Match not found"};
   }

   else if(root->name.compare(son)==0)
   {
    this->root->setright(mother, this->root->height + 1);
   }

  else
   {
    node *temp=new node();
    temp=this->root->search(son);
     temp->setright(mother, temp->height + 1);
   }
  return *this;
}

string family::Tree::relation(string name){
  string ans;
  if(this->root->search(name)==NULL){
    return "unrealated";
  }
  else {
  int height=this->root->height;
  node *temp=this->root->search(name);
  int r_height=temp->height-height;

    if(r_height==0)
     return "me";

    if(r_height==1){
       if(this->root->left->name.compare(name)==0)
          return "mother";
          return "father";
     }
    else if(r_height==2){
        if(temp->G=='m')
        return "grandfather";
        return "grandmother";
     }
    else{

       while(r_height>2)
       {
         ans=ans+"great-";
       }

       if(temp->G=='m')
        ans=ans+"grandfather";
       else
         ans=ans+"grandmother";
    }
  return ans;
}
}

string family::Tree::find(string relation){
  int h=0;
  char gender;
  string ans;
  if(relation.substr(0,6).compare("great-"))
  {
  while(relation.substr(0,6).compare("great-")==0){
    relation=relation.substr(7);
   if(h==0)
     h=3;
   else
     h=h+1;
   }
  }

  else if(relation.length()==11)
  {
    if(relation.compare("grandfather")==0)
        gender='m';
    else
      gender='f';
    
    if(h==0)
    h=2;
   }

  else if(relation.length()==6)
  {
    if(relation.compare("father")==0)
      gender='m';
    else
      gender='f';

    if(h==0)
      h=1;
  }

  else
  {
    throw logic_error{"String not valid!"};
  }
  return this->root->find(h,gender);
}

void family::Tree::remove(string name){
  node *temp=this->root->search(name);
      this->root->Remove(temp);
}

void family::Tree::display(){
  this->root->print2D(this->root);
}

}; // namespace MyTree