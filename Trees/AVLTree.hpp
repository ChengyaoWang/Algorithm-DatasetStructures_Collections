# ifndef AVLTREE_HPP
# define AVLTREE_HPP

# include "TreeBase.hpp"
# include <assert.h>

template<typename K, typename V>
class AVL_Node: BinNode<K, V>{
private:
    // Height of Left / Right Subtree
    int leftH = 0, rightH = 0;

public:
    AVL_Node(
        K key,
        V val,
        BinNode<K, V>* parent = nullptr,
        BinNode<K, V>* left = nullptr,
        BinNode<K, V>* right = nullptr
    ): BinNode<K, V>(key, val, parent, left, right){}
    ~AVL_Node(){}

    AVL_Node<K, V>* left_rotation(void){
        
        AVL_Node<K, V>* rightChild = this -> right;
        if (rightChild == nullptr)
            return nullptr;
        // Step 1
        this -> right = rightChild -> left;
        if (this -> right)  this -> right -> parent = this;
        // Step 2
        rightChild -> parent = this -> parent;
        if (this -> parent){
            if (this -> parent -> left == this){
                this -> parent -> left = rightChild;
            }else {
                this -> parent -> right = rightChild;
            }
        }
        // Step 3
        rightChild -> left = this;
        this -> parent = rightChild;

        // Adjust Subtree Height
        this -> rightH = rightChild -> leftH;
        rightChild -> leftH = max(this -> rightH, this -> leftH) + 1;

        return rightChild;
    }

    AVL_Node<K, V>* right_rotation(void){

        AVL_Node<K, V>* leftChild = this -> left;
        if (leftChild == nullptr)
            return nullptr;
        // Step 1
        this -> left = leftChild -> right;
        if (this -> left)   this -> left -> parent = this;
        // Step 2
        leftChild -> parent = this -> parent;
        if (this -> parent){
            if (this -> parent -> left == this){
                this -> parent -> left = leftChild;
            }else {
                this -> parent -> right = leftChild;
            }
        }
        // Step 3
        leftChild -> right = this;
        this -> parent = leftChild;

        // Adjust Subtree Height
        this -> leftH = leftChild -> rightH;
        leftChild -> rightH = max(this -> rightH, this -> leftH) + 1;

        return leftChild;
    }
};

template<typename K, typename V>
class AVL_Tree: Tree<K, V>{

private:

    AVL_Node<K, V>* root = nullptr;

    
    AVL_Node<K, V>* _insertion_helper(AVL_Node<K, V>* root, K key, V val){
        if (root == nullptr){
            return new AVL_Node(key, val);
        }else if (root -> key == key){
            return root;
        }else {
            AVL_Node<K, V>* p = nullptr;
            if (root -> key > key){
                root -> left = _insertion_helper(root -> left, key, val);
            }else {
                root -> right = _insertion_helper(root -> right, key, val);
            }
        }
        return 
    }



public:
    int nodeNum = 0;

    AVL_Tree(void){}
    ~AVL_Tree(void){}

    V operator[](K key){

    }

    bool insert(K key, V val){

    }

    bool remove(K key){

    }



};



# endif