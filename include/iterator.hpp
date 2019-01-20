#include "node.hpp"
#include <iostream>
#include <iterator>

namespace BSTree {

template <typename T>
class pre_iterator : std::iterator<std::forward_iterator_tag, T> {
public:
  pre_iterator();
  pre_iterator(Node<T>* ptr);
  pre_iterator(const pre_iterator &);
  auto operator=(pre_iterator &)-> pre_iterator&;
  auto operator++()-> pre_iterator&;
  auto operator--()-> pre_iterator&;
  auto operator++(int)-> pre_iterator;
  auto operator*()-> T&;
  auto operator->()-> T*;
  template <typename T1>
  friend auto operator!=(const pre_iterator<T1>&, const pre_iterator<T1>&)-> bool;
  template <typename T2>
  friend bool operator==(const pre_iterator<T2>&, const pre_iterator<T2>&);
  template <typename T3>
  friend void swap(pre_iterator<T3>& lhs, pre_iterator<T3>& rhs);
  ~pre_iterator();
private:
  Node<T>* ptr;
};

template <typename T>
class post_iterator {
public:
  post_iterator();
  post_iterator(Node<T>* ptr);
  post_iterator(const post_iterator &);
  auto operator=(post_iterator &)-> post_iterator&;
  auto operator++()-> post_iterator&;
  auto operator--()-> post_iterator&;
  auto operator++(int)-> post_iterator;
  auto operator*()-> T&;
  template <typename T1>
  friend auto operator!=(const post_iterator<T1>&, const post_iterator<T1>&)-> bool;
  template <typename T2>
  friend bool operator==(const post_iterator<T2>&, const post_iterator<T2>&);
  template <typename T3>
  friend void swap(post_iterator<T3>& lhs, post_iterator<T3>& rhs);
  ~post_iterator();
private:
  Node<T>* ptr;
};

//pre_iterator_methods{

template <typename T>
pre_iterator<T>::pre_iterator() {
  ptr = nullptr;
}

template <typename T>
pre_iterator<T>::~pre_iterator() {
}

template <typename T>
pre_iterator<T>::pre_iterator(Node<T>* ptr) {
  this->ptr = ptr;
}

template <typename T>
auto pre_iterator<T>::operator->()-> T* {
  return &(ptr->data);
}

template <typename T>
pre_iterator<T>::pre_iterator(const pre_iterator & it) {
  ptr = it.ptr;
};

template <typename T>
auto pre_iterator<T>::operator=( pre_iterator & curr) -> pre_iterator& {
  this->ptr = curr.ptr;
  return *this;
}

template <typename T>
auto pre_iterator<T>::operator++() -> pre_iterator& {
  if ((ptr->parent == nullptr)&&(ptr->right == nullptr)) {
    ptr = nullptr;
    return *this;
  }
  if (ptr->right != nullptr) {
    ptr=ptr->right;
    while(1) {
      if(ptr->left != nullptr)
        ptr=ptr->left;
        else return *this;
    }
  }
  if (ptr == ptr->parent->left) {
    ptr = ptr->parent;
    return *this;
  }
  ptr = ptr->parent;
  while(1) {
    if (ptr->parent == nullptr) {
      ptr = nullptr;
      return *this;
    }
    if (ptr->parent->right != nullptr) {
      if (ptr->parent->right==ptr) {
        ptr=ptr->parent;
      }
      else {
        ptr=ptr->parent;
        return *this;
      }
    }
    else {
      ptr=ptr->parent;
      return *this;
    }
  }
}

template <typename T>
auto pre_iterator<T>::operator--() -> pre_iterator& {
  if ((ptr->parent == nullptr)&&(ptr->left == nullptr)) {
    ptr = nullptr;
    return *this;
  }
  if (ptr->left != nullptr) {
    ptr=ptr->left;
    while(1) {
      if(ptr->right != nullptr)
        ptr=ptr->right;
      else return *this;
    }
  }
  if (ptr == ptr->parent->right) {
    ptr = ptr->parent;
    return *this;
  }
  ptr = ptr->parent;
  while(1) {
    if (ptr->parent == nullptr) {
      ptr = nullptr;
      return *this;
    }
    if (ptr->parent->left != nullptr) {
      if (ptr->parent->left==ptr) {
        ptr=ptr->parent;
      }
      else {
        ptr=ptr->parent;
        return *this;
      }
    }
    else {
      ptr=ptr->parent;
      return *this;
    }
  }
}

template <typename T>
auto pre_iterator<T>::operator++(int value) -> pre_iterator {
  pre_iterator it = *this;
  for(; value > 0; --value)
    ++(*this);
  return it;
}

template <typename T>
auto pre_iterator<T>::operator*() -> T& {
  return ptr->data;
}

template <typename T1>
auto operator!=(const pre_iterator<T1>& it, const pre_iterator<T1>& it1)-> bool {
  if (it.ptr != it1.ptr) return true;
  return false;
}

template <typename T2>
bool operator==(const pre_iterator<T2>& it1, const pre_iterator<T2>& it2) {
  if (it1.ptr == it2.ptr)
    return true;
  return false;
}

template <typename T3>
void swap(pre_iterator<T3>& lhs, pre_iterator<T3>& rhs) {
  std::swap(lhs.ptr, rhs.ptr);
}
//}

//post_iterator_methods{

template <typename T>
post_iterator<T>::post_iterator() {
  ptr = nullptr;
}

template <typename T>
post_iterator<T>::~post_iterator() {
}

template <typename T>
post_iterator<T>::post_iterator(Node<T>* ptr) {
  this->ptr = ptr;
}

template <typename T>
post_iterator<T>::post_iterator(const post_iterator & it) {
  ptr = it.ptr;
};

template <typename T>
auto post_iterator<T>::operator=( post_iterator & curr) -> post_iterator& {
  this->ptr = curr.ptr;
  return *this;
}

template <typename T>
auto post_iterator<T>::operator++() -> post_iterator& {
  if ((ptr->parent == nullptr)&&(ptr->left == nullptr)) {
    ptr = nullptr;
    return *this;
  }
  if (ptr->left != nullptr) {
    ptr=ptr->left;
    while(1) {
      if(ptr->right != nullptr)
        ptr=ptr->right;
      else return *this;
    }
  }
  if (ptr == ptr->parent->right) {
    ptr = ptr->parent;
    return *this;
  }
  ptr = ptr->parent;
  while(1) {
    if (ptr->parent == nullptr) {
      ptr = nullptr;
      return *this;
    }
    if (ptr->parent->left != nullptr) {
      if (ptr->parent->left==ptr) {
        ptr=ptr->parent;
      }
      else {
        ptr=ptr->parent;
        return *this;
      }
    }
    else {
      ptr=ptr->parent;
      return *this;
    }
  }
}

template <typename T>
auto post_iterator<T>::operator--() -> post_iterator& {
  if ((ptr->parent == nullptr)&&(ptr->right == nullptr)) {
    ptr = nullptr;
    return *this;
  }
  if (ptr->right != nullptr) {
    ptr=ptr->right;
    while(1) {
      if(ptr->left != nullptr)
        ptr=ptr->left;
      else return *this;
    }
  }
  if (ptr == ptr->parent->left) {
    ptr = ptr->parent;
    return *this;
  }
  ptr = ptr->parent;
  while(1) {
    if (ptr->parent == nullptr) {
      ptr = nullptr;
      return *this;
    }
    if (ptr->parent->right != nullptr) {
      if (ptr->parent->right==ptr) {
        ptr=ptr->parent;
      }
      else {
        ptr=ptr->parent;
        return *this;
      }
    }
    else {
      ptr=ptr->parent;
      return *this;
    }
  }
}

template <typename T>
auto post_iterator<T>::operator++(int value) -> post_iterator {
  post_iterator it = *this;
  for(; value > 0; --value)
    ++(*this);
  return it;
}

template <typename T>
auto post_iterator<T>::operator*() -> T & {
  return ptr->data;
}

template <typename T1>
auto operator!=(const post_iterator<T1>& it, const post_iterator<T1>& it1)-> bool {
  if (it.ptr != it1.ptr) return true;
  return false;
}

template <typename T2>
bool operator==(const post_iterator<T2>& it1, const post_iterator<T2>& it2) {
  if (it1.ptr == it2.ptr)
    return true;
  return false;
}

template <typename T3>
void swap(post_iterator<T3>& lhs, post_iterator<T3>& rhs) {
  std::swap(lhs.ptr, rhs.ptr);
}
//}
}
