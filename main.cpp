#include "tree.hpp"

int main() {
  
    using BSTree::Tree;
    Tree<std::string> tree = {"5", "3", "4", "2", "7", "9", "6"};//, 2, 7, 9, 6, 8};
    
    std::cout << "Pre_iterator:" << std::endl;
   
    for (auto& x: tree) {
        std::cout << x << ' ';
    }
    
    std::cout << std::endl;
    
    auto it1 = tree.begin();
    
    it1.operator++(1);
    std::cout << it1->size() << ' ';
     //std::advance(it1, 5);
     
     std::cout << *it1 << std::endl;
 
    auto it2 = tree.begin();
    ++it2; ++it2; ++it2; ++it2;
    auto end2 = tree.end();
    
    for (; it2 != end2; --it2) {
        std::cout << *it2 << ' ';
    }
    std::cout << std::endl;
    
    std::cout << "Post_iterator:" << std::endl;
    for (auto& x: tree) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
     
     auto rit1 = tree.rbegin();
    
    rit1.operator++(2);
     
     std::cout << *rit1 << std::endl;
     
     auto rit2 = tree.rbegin();
    ++rit2; ++rit2; ++rit2; ++rit2;
    auto rend2 = tree.rend();
    
    for (; rit2 != rend2; --rit2) {
        std::cout << *rit2 << ' ';
    }
    std::cout << std::endl;
}
