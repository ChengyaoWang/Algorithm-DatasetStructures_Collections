#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

# include "TreeBase.hpp"
# include "BinNode.hpp"

template<typename K, typename V>
class BinaryTree: Tree<K, V>{

private:
    /*
        Differences Between:
            _add_helper -> Returns the Insertion Location 
            _find_helper -> Returns the exact node
    */
    BinNode<K, V>* _add_helper(BinNode<K, V>* root, K key){
        if(root == nullptr || root -> key == key){
            return root;
        }
        BinNode<K, V>* retNode = _add_helper((root -> key < key) ? root -> right: root -> left, key);
        return (retNode == nullptr) ? root: retNode;
    }

    BinNode<K, V>* _find_helper(BinNode<K, V>* root, K key){
        if(root == nullptr || root -> key == key){
            return root;
        }
        return _find_helper((root -> key < key) ? root -> right: root -> left, key);
    }
    
    template<typename Lambda>
    void _inorder_traverse(BinNode<K, V>* root, Lambda&& func){
        if (root == nullptr)     return;
        _inorder_traverse(root -> left, func);
        func(root);
        _inorder_traverse(root -> right, func);
        return;
    }

public:
    BinNode<K, V>* root = nullptr;
    int nodeNum = 0;

    BinaryTree(void){}
    ~BinaryTree(void){}
    
    template<typename Lambda>
    void InorderTraverse(Lambda&& func){
        _inorder_traverse(root, func);
    }

    V operator[](K key){    
        BinNode<K, V>* foundNode = _find_helper(root, key);
        return (foundNode == nullptr) ? -1: foundNode -> val;
    }

    bool insert(K key, V val){
        if (!root){
            root = new BinNode<K, V>(key, val);
        }else {
            BinNode<K, V>* insertLoc = _add_helper(root, key);
            if (!insertLoc || insertLoc -> key == key){
                return false;
            }
            if (insertLoc -> key > key){
                insertLoc -> left = new BinNode<K, V>(key, val, insertLoc);
            }else{
                insertLoc -> right = new BinNode<K, V>(key, val, insertLoc);
            }
        }
        ++nodeNum;
        return true;
    }

    bool remove(K key){
        BinNode<K, V>* removeLoc = _find_helper(root, key);
        if (!removeLoc){
            return false;
        }else {
            if (removeLoc -> numChild() == 2){
                BinNode<K, V>* succNode = removeLoc -> get_successor();
                removeLoc -> key = succNode -> key;
                removeLoc -> val = succNode -> val;
                removeLoc = succNode;
            }

            BinNode<K, V>* childNode = (removeLoc -> left == nullptr) ? removeLoc -> right: removeLoc -> left;

            if (childNode){
                childNode -> parent = removeLoc -> parent;
            }

            if (removeLoc -> parent){
                if (removeLoc -> parent -> left == removeLoc){
                    removeLoc -> parent -> left = childNode;
                }else {
                    removeLoc -> parent -> right = childNode;
                }
            }else {
                root = childNode;
            }
        }
        --nodeNum;
        delete removeLoc;
        return true;
    }
};
#endif