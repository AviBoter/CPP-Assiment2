
#include <string>
#include <iostream>
#include <stdexcept>
#include<bits/stdc++.h> 
#include <stdbool.h>

using namespace std;

namespace Familia{
    FamilyTree::FamilyTree(){
      head=new node;
    }
    FamilyTree::~FamilyTree(){
      FamilyTree::delete(&head);
    }
 
    FamilyTree::addFather()

};