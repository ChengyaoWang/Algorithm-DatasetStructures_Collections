# ifndef AVLTREE_HPP
# define AVLTREE_HPP

# include "TreeBase.hpp"
# include <assert.h>

template<typename K, typename V>
class AVL_Node: BinNode<K, V>{
private:
    int leftH = 0, rightH = 0;

public:
    AVL_Node(
        K key, V val, BinNode* parent = nullptr, BinNode* left = nullptr, BinNode* right = nullptr
    ): BinNode(key, val, parent, left, right){}
    ~AVL_Node(){}

    bool left_rotation(void){
        // Must Have a Left Child
        assert(right != nullptr);

    }

    bool right_rotation(void){

    }


};




# endif