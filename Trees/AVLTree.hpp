# ifndef AVLTREE_HPP
# define AVLTREE_HPP

# include "TreeBase.hpp"
# include "AVLNode.hpp"

# include <assert.h>

template<typename K, typename V>
class AVL_Tree: Tree<K, V>{

private:

    AVL_Node<K, V>* _find_helper(AVL_Node<K, V>* root, K key){
        if (root == nullptr || root -> key == key){
            return root;
        }
        return _find_helper((root -> key < key) ? root -> right: root -> left, key);
    }

    AVL_Node<K, V>* _insertion_helper(AVL_Node<K, V>* root, K key, V val){

        // Standard BST Insertion Process
        if (root == nullptr){
            ++nodeNum;
            return new AVL_Node<K, V> (key, val);
        }else if (root -> key > key) {
            root -> left = _insertion_helper(root -> left, key, val);
            root -> left -> parent = root;
            root -> leftH = 1 + std::max(root -> left -> leftH, root -> left -> rightH);
        }else if (root -> key < key) {
            root -> right = _insertion_helper(root -> right, key, val);
            root -> right -> parent = root;
            root -> rightH = 1 + std::max(root -> right -> leftH, root -> right -> rightH);
        }else {
            return root;
        }

        // Adjust The Height if Tree is Unbalanced
        //      A total of 4 cases: LeftLeft / LeftRight / RightLeft / RightRight 
        int diffH = root -> balance();

        if (diffH > 1) {
            if (root -> left -> key < key){
                root -> left = root -> left -> left_rotation_();   
            }    
            return root -> right_rotation_();
        }else if (diffH < -1){
            if (root -> right -> key > key){
                root -> right = root -> right -> right_rotation_();
            }
            return root -> left_rotation_();
        }else {
            return root;
        }
    }

    AVL_Node<K, V>* _removal_helper(AVL_Node<K, V>* root, K key){
        if (root == nullptr){
            return nullptr;
        } else if (root -> key > key) {
            root -> left = _removal_helper(root -> left, key);
            if (root -> left)
                root -> left -> parent = root;
            root -> leftH = (root -> left) ? 1 + std::max(root -> left -> leftH, root -> left -> rightH): 0;
        } else if (root -> key < key) {
            root -> right = _removal_helper(root -> right, key);
            if (root -> right)
                root -> right -> parent = root;
            root -> rightH = (root -> right) ? 1 + std::max(root -> right -> leftH, root -> right -> rightH): 0;
        } else {
            AVL_Node<K, V>* p = nullptr;
            if (root -> numChild() == 2) {
                p = root -> get_successor();
                root -> key = p -> key;
                root -> val = p -> val;
                root -> right = _removal_helper(root -> right, p -> key);
                if (root -> right)
                    root -> right -> parent = root;
                root -> rightH = (root -> right) ? 1 + std::max(root -> right -> leftH, root -> right -> rightH): 0;
            } else {
                p = (root -> left == nullptr) ? root -> right: root -> left;
                --nodeNum;
                delete root;
                return p;
            }
        }
        // Adjust The Height if Tree is Unbalanced
        //      A total of 4 cases: LeftLeft / LeftRight / RightLeft / RightRight 
        int diffH = root -> balance();

        if (diffH > 1) {
            if (root -> left && root -> left -> balance() < 0){
                root -> left = root -> left -> left_rotation_();   
            }    
            return root -> right_rotation_();
        }else if (diffH < -1) {
            if (root -> right && root -> right -> balance() > 0){
                root -> right = root -> right -> right_rotation_();
            }
            return root -> left_rotation_();
        }else {
            return root;
        }
    }

    /*
        Utility Functions
    */
    template<typename Lambda>
    void _inorder_traverse(AVL_Node<K, V>* root, Lambda&& func){
        if (root == nullptr)     return;
        _inorder_traverse(root -> left, func);
        func(root);
        _inorder_traverse(root -> right, func);
        return;
    }
    
    int _check_validity_helper(AVL_Node<K, V>* root){
        if (root == nullptr) {
            return 0;
        }
        int leftH = _check_validity_helper(root -> left);
        int rightH = _check_validity_helper(root -> right);
        if (leftH != root -> leftH && rightH != root -> rightH){
            std::cout << "Wrong H" << std::endl;
            FLAG_valid &= false;
        } else if (abs(leftH - rightH) > 1) {
            std::cout << "Unbalanced" << std::endl;
            FLAG_valid &= false;
        }
        ++nodeCount;
        return 1 + std::max(leftH, rightH);
    }

public:
    AVL_Node<K, V>* root = nullptr;
    int nodeNum = 0, nodeCount;
    bool FLAG_valid;

    AVL_Tree(void){}
    ~AVL_Tree(void){}

    template<typename Lambda>
    void InorderTraverse(Lambda&& func){
        _inorder_traverse(root, func);
    }

    V operator[](K key){    
        AVL_Node<K, V>* foundNode = _find_helper(root, key);
        return (foundNode == nullptr) ? -1: foundNode -> val;
    }

    bool insert(K key, V val){
        root = _insertion_helper(root, key, val);
        return true;
    }

    bool remove(K key){
        root = _removal_helper(root, key);
        return true;
    }

    bool check_validity(void){
        FLAG_valid = true;
        nodeCount = 0;
        _check_validity_helper(root);
        return FLAG_valid & (nodeCount == nodeNum);
    }

};



# endif