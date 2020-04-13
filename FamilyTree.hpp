#ifndef FamilyTree
#define FamilyTree

namespace Familia{

struct node
{
  int height;  
  string name;
  node *left;
  node *right;
}; //node

class FamilyTree
{
    public:
        FamilyTree();
        ~FamilyTree();
 
    private:
        void destroy_tree(node *leaf);
        void addFather(string name, node *leaf);
        void addMother(string name, node *leaf);
        node *find(int key, node *leaf);
        node *relation(string name, node *leaf);
        void delete(string name, node *leaf);
        void display(node *leaf);

        node *head;

 }; //FamilyTree
}; //Familia
#endif