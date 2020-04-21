#include "FamilyTree.hpp"

using namespace std;

namespace family{

 void family::node::print2DUtil(node *root, int space){
   //print2DUtil copied from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions//
    if (root == NULL)  
        return;  

    space += COUNT;  
    family::node::print2DUtil(root->right, space);   
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->name<<"\n";  
  
    family::node::print2DUtil(root->left, space);  
}  
    
void family::node::print2D(node *root){  
    print2DUtil(root, 0);  
}   
void family::node::setname(){
  this->name="";
}
void family::node::setname(string NewName){
   this->name=NewName;
}

void family::node::setheight(int h){
   height=h+1;;
}

string family::node::getname(){
   return name;
}

int family::node::getheight(){
  return height;
}
void family::node::setGender(char g){
   this->G=g;
}

void family::node::setright(string name, int height){
  this->right=new node(name);
  this->right->setheight(this->height);
  this->right->setGender('m');
}

void family::node::setleft(string name, int height){
  this->left=new node(name);
  this->left->setheight(this->height);
  this->left->setGender('f');
}

family::node* family::node::getleft(){
  return this->left;
}
family::node* family::node::getright(){
  return this->right;
}
char family::node::getGender(){
  return this->G;
}

  family::node* family::node::search(node *leaf,string name){
    node *temp;
  if(leaf->getname().compare(name)==0 || leaf==nullptr){
    return leaf;
  }
  
  else

  if(leaf->left){
  temp=leaf->search(leaf->left,name);
  if(temp){
    return temp;
  }
  }

  if(leaf->right){
  temp=leaf->search(leaf->right,name);
  if(temp){
    return temp;
  }
  }
    return nullptr;
}

void family::node::Remove(node *leaf,string name){
    
      // if(leaf->getleft()!=nullptr)
      // leaf->Remove(leaf->left,name);
      // if(leaf->getright()!=nullptr)
      // leaf->Remove(leaf->right,name);
      // else
      // cout<<"b"<<endl;
      // delete leaf;
      cout<<"a"<<endl;
      }


Tree& family::Tree::addFather(string son, string father){
  
  if(!(*root).search(root,son))
   {
    throw logic_error{"Match not found"};
   }
   else if(root->getname().compare(son)==0)
   {
    this->root->setright(father, this->root->getheight() + 1);
   }
  else
   {
    node *temp;
    temp=this->root->search(root,son);
     temp->setright(father,temp->getheight() + 1);
    }

  return *this;
}

Tree& family::Tree::addMother(string son,string mother){

   if(!this->root->search(root,son))
   {
    throw logic_error{"Match not found"};
   }

   if(root->getname().compare(son)==0)
   {
    this->root->setleft(mother, this->root->getheight() + 1);
   }

  else
   {
    node *temp;
    temp=this->root->search(root,son);
     temp->setleft(mother, temp->getheight() + 1);
   }
  return *this;
}

string family::Tree::relation(string name){
  string ans;
  node *temp=this->root->search(root,name);

  if(!temp)
  {
    return "unrealated";
  }

  else
  {
  int height=this->root->getheight();
  int r_height=temp->getheight()-height;

    if(r_height==0)
     return "me";

    if(r_height==1){
       if(this->root->getleft()->getname().compare(name)==0)
          return "mother";
          return "father";
     }
    else if(r_height==2){
        if(temp->getGender()=='m')
        return "grandfather";
        return "grandmother";
     }
    else{

       while(r_height>2)
       {
         ans=ans+"great-";
         r_height--;
       }

       if(temp->getGender()=='m')
        ans=ans+"grandfather";
       else
         ans=ans+"grandmother";
    }
  }
  return ans;
}

string family::Tree::find(string relation){
  int h=1;
  char gender='m';
  string ans;
  if(relation.substr(0,6)==string("great-"))
  {
  while(relation.substr(0,6)==string("great-")){
    relation=relation.substr(6);
   if(h==1)
     h=3;
   else
     h=h+1;
   }
  }

    if(relation.length()==11)
  {
    if(relation.substr(0,11)==string("grandfather"))
        gender='m';
    else
      gender='f';
    
    if(h==1)
    h=2;
   }

  else if(relation.length()==6)
  {
    if(relation.at(0)=='m')
      gender='f';
  }

  else
  {
    throw logic_error{"The tree cannot handle the " +relation+ " relation"};
  }

  return this->root->find(h,gender);
}

string family::node::find(int height,char gender){
  string ans;
  if(height==1){
    if(gender=='m'){
      node *temp=this->getright();
      if(temp){
       ans=this->right->getname();
      }
    }

    if(gender=='f'){
      node *temp=this->getleft();
      if(temp){
     ans=this->left->getname();
      }
    }
     return ans;
   }
   
   if(height>1){
     if(this->left!=nullptr)
    ans=this->left->find(height-1,gender);
    if(!ans.empty())
      return ans;
    if(this->right!=nullptr)  
    ans=this->right->find(height-1,gender);
    if(!ans.empty())
      return ans;
   }
   return ans;
}

void family::Tree::remove(string name){
  node *temp=this->root->search(root,name);
  if(temp){
    delete temp;
  }
}

//  family::node* family::node::searchParent(node *leaf,string name){
//     node *temp;
//   if(leaf->left->getname().compare(name)==0 || leaf->right->getname().compare(name)==0){
//     return leaf;
//   }
  
//   else

//   if(leaf->left){
//   temp=leaf->searchParent(leaf->left,name);
//   if(temp){
//     return temp;
//   }
//   }

//   if(leaf->right){
//   temp=leaf->searchParent(leaf->right,name);
//   if(temp){
//     return temp;
//   }
//   }
//     return nullptr;
// }

void family::Tree::display(){
  root->print2D(this->root);
}

}; // namespace MyTree