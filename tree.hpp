#include "iterator.hpp"
#include <initializer_list>

namespace BSTree {

    template <typename T>
    class Tree {
    public:
        Tree();
        
        Tree(std::initializer_list<T> list);

        auto push_back(const T&) -> void;

         pre_iterator<T> begin();
         pre_iterator<T> end();
         
        post_iterator<T> rbegin();
        post_iterator<T> rend();
        
        auto remove(Node<T>*&) -> void;
        ~Tree();
    private:
        Node<T>* root;
    };
    
//Tree_methods{

template <typename T>
Tree<T>::Tree() : root{nullptr} {
  
};

template <typename T>
Tree<T>::Tree(std::initializer_list<T> list){
  root = nullptr;
  for (auto& x:list) {
      push_back(x);
    }
}

template <typename T>
auto add(Node<T>*& curr,Node<T>*& parent_, T value) -> void {
  if (curr == nullptr){
    curr = new Node<T>{value, nullptr, nullptr, nullptr};
    curr->parent = parent_;
  }
  else {
    if (curr->data < value) add(curr->right, curr, value);
    if (curr->data > value) add(curr->left, curr, value);
  }
}

template <typename T>
auto Tree<T>::push_back(const T& value) -> void{
  Node<T>* curr = new Node<T>;
  curr = nullptr;
  add(root, curr, value);
  delete curr;
  curr = nullptr;
  return;
}
//}

//pre_iterator{
template <typename T>
pre_iterator<T> Tree<T>::begin() {
  Node<T>* curr = root;
  while(1){
    if(curr->left != nullptr){
      curr = curr->left;
    } 
    else break;
  }
  pre_iterator<T> it(curr);
  return it;
}

template <typename T>
pre_iterator<T> Tree<T>::end(){
  return {};
}
 //}
 
//post_iterator{
template <typename T>
post_iterator<T> Tree<T>::rbegin() {
  Node<T>* curr = root;
  while(1){
    if(curr->right != nullptr){
      curr = curr->right;
    } 
    else break;
  }
  post_iterator<T> it(curr);
  return it;
}

template <typename T>
post_iterator<T> Tree<T>::rend(){
  return {};
}
 //}
 
//~Tree{

template <typename T>
auto Tree<T>::remove(Node<T>*& curr) -> void{
      if (curr->parent != nullptr)
        curr->parent = nullptr;
      if (curr->right != nullptr)
        remove(curr->right);
      if (curr->left != nullptr)
        remove(curr->left);
      delete curr;
      curr = nullptr;
}

template <typename T>
Tree<T>::~Tree(){
  if(root != nullptr)
  remove(root);
};
//}
}
