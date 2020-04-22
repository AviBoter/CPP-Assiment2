family::node* family::node::search(node *leaf,string name){

  if(leaf->getname().compare(name)==0 || leaf==NULL){
    return leaf;
  }
  
  else

  if(leaf->getleft()){
  if(leaf->search(leaf->getleft(),name)){
    return leaf->search(leaf->getleft(),name);
  }
  }
  //getright()
  //getleft()
  if(leaf->getright()){
  if(leaf->search(leaf->getright(),name))
  return leaf->search(leaf->getleft(),name);
  }
    return NULL;
}

family::node* family::node::search(node *leaf,string name){
    node *temp;
  if(leaf->getname().compare(name)==0 || leaf==nullptr){
    return leaf;
  }
  
  else

  if(leaf->getleft()){
  temp=leaf->search(leaf->getleft(),name);
  if(temp){
    return temp;
  }
  }
  //getright()
  //getleft()
  if(leaf->getright()){
  temp=leaf->search(leaf->getright(),name);
  if(temp){
    return temp;
  }
  }
    return nullptr;
}