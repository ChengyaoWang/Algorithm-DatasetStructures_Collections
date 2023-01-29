# ifndef SUFFIXTREE_HPP
# define SUFFIXTREE_HPP

# include "TreeBase.hpp"
# include <assert.h>

/*
    cpp version of suffix tree is an modification from python version
*/

template<typename K, typename V>
class Suffix_Tree: Tree<K, V>{
private:

public:
    AVL_Node<K, V>* root = nullptr;
    int nodeNum = 0, nodeCount;
    bool FLAG_valid;

    AVL_Tree(void){}
    ~AVL_Tree(void){}

    

};



# endif