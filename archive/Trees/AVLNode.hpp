# ifndef AVLNODE_HPP
# define AVLNODE_HPP

# include <algorithm>
# include <iostream>

template<typename K, typename V>
class AVL_Node{

public:
    K key;
    V val;
    AVL_Node<K, V>* left, *right, *parent;
    int leftH = 0, rightH = 0;

    // Constructors & Destructors
    AVL_Node(K key, V val, AVL_Node* parent = nullptr, AVL_Node* left = nullptr, AVL_Node* right = nullptr){
        this -> key = key;
        this -> val = val;
        this -> left = left;
        this -> right = right;        
        this -> parent = parent;
    }
    ~AVL_Node(){}

    // Helper Functions
    bool isLeaf(void){return left == nullptr && right == nullptr;}
    int numChild(void){return (left != nullptr) + (right != nullptr);}
    int balance(void){return leftH - rightH;}


    // Functions for Retrieving Families
    AVL_Node<K, V>* get_grandparent(void){return (parent == nullptr) ? nullptr: parent -> parent;}
    AVL_Node<K, V>* get_sibling(void){
        if(parent == nullptr)   return nullptr;
        return (this == parent -> left) ? parent -> right: parent -> left;
    }
    AVL_Node<K, V>* get_uncle(void){
        if(parent == nullptr)   return nullptr;
        return parent -> get_sibling();
    }
    AVL_Node<K, V>* get_successor(void){
        AVL_Node<K, V>* p = this;
        if(p -> right){
            p = p -> right;
            while(p -> left){
                p = p -> left;
            }
        }else{
            while(p -> parent){
                if(p != p -> parent -> right){
                    break;
                }
                p = p -> parent;
            }
            p = p -> parent;
        }
        return p;
    }
    AVL_Node<K, V>* get_predecessor(void){
        AVL_Node* p = this;
        if(p -> left){
            p = p -> left;
            while(p -> right){
                p = p -> right;
            }
        }else{
            while(p -> parent){
                if(p != p -> parent -> left){
                    break;
                }
                p = p -> parent;
            }
            p = p -> parent;
        }
        return p;
    }

    AVL_Node<K, V>* left_rotation_(void){
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
        rightChild -> leftH = std::max(this -> rightH, this -> leftH) + 1;

        return rightChild;
    }

    AVL_Node<K, V>* right_rotation_(void){

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
        leftChild -> rightH = std::max(this -> rightH, this -> leftH) + 1;

        return leftChild;
    }

};
# endif