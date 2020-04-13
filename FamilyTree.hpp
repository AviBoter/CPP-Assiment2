#ifndef FamilyTree
#define FamilyTree

namespace MyTree{

struct node
{
  private:
  int height;  
  string name;
  node* left;
  node* right;

public:
 void setname(string name);
 string getname();
 void setheight(int height);
 int getheight();
 void setleft(string name,int height);
 node* getleft();
 void setright(string name,int height);
 node* getright();
}; //node

class FamilyTree
{
    public:
        Tree();
        ~Tree();
 
    private:
        void addFather(string name, node *leaf);
        void addMother(string name, node *leaf);
        string find(int key, node *leaf);
        string relation(string name, node *leaf);
        void delete(string name, node *leaf);
        void display(node *leaf);

        node* root;

 }; //FamilyTree
}; //Familia
#endif