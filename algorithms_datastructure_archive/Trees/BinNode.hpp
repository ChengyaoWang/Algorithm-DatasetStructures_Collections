# ifndef BINNODE_HPP
# define BINNODE_HPP

/*
    Node Definitions
*/

// Binary Node
template<typename K, typename V>
class BinNode{

public:
    K key;
    V val;
    BinNode<K, V>* left, *right, *parent;

    // Constructors & Destructors
    BinNode(K key, V val, BinNode* parent = nullptr, BinNode* left = nullptr, BinNode* right = nullptr){
        this -> key = key;
        this -> val = val;
        this -> left = left;
        this -> right = right;        
        this -> parent = parent;
    }
    ~BinNode(){}

    // Helper Functions

    bool isLeaf(void){
        return left == nullptr && right == nullptr;
    }

    int numChild(void){
        return (left != nullptr) + (right != nullptr);
    }
    // Functions for Retrieving Families
    BinNode<K, V>* get_grandparent(void){
        return (parent == nullptr) ? nullptr: parent -> parent;
    }

    BinNode<K, V>* get_sibling(void){
        if(parent == nullptr)   return nullptr;
        return (this == parent -> left) ? parent -> right: parent -> left;
    }


    BinNode<K, V>* get_uncle(void){
        if(parent == nullptr)   return nullptr;
        return parent -> get_sibling();
    }

    BinNode<K, V>* get_successor(void){
        BinNode<K, V>* p = this;
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

    BinNode<K, V>* get_predecessor(void){
        BinNode* p = this;
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

};

# endif