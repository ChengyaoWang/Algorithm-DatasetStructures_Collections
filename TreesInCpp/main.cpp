/*
    Main Entrance Used to Testing
*/

# include "BinarySearchTree.hpp"
# include "AVLTree.hpp"
# include "TreeBase.hpp"

# include <vector>
# include <unordered_set>
# include <random>
# include <assert.h>
# include <iostream>

template<typename T>
void insertion_test_(T* tree, int repetition = 1000){

    std::unordered_set<int> seen = {};
    int numGen;
    bool FLAG_CORRECT, FLAG;

    for (int i = 0; i < repetition; ++i){
        std::cout << "Test Round: " << i + 1 << std::endl;
        FLAG = true;
        
        // Value Random Insertion & Removal
        for (int j = 0; j < 2000; ++j){
            numGen = std::rand() % 10000;
            if (j < 1000){
                tree -> insert(numGen, numGen + 1);
                seen.insert(numGen);
            }else {
                tree -> remove(numGen);
                seen.erase(numGen);
            }
        }

        // Validate the Result
        for (int j = 0; j < 10000; ++j){
            FLAG_CORRECT = ((seen.find(j) == seen.end()) && ((*tree)[j] == -1)) || 
                           ((seen.find(j) != seen.end()) && ((*tree)[j] == j + 1));
            FLAG &= FLAG_CORRECT;
        }
        std::cout << FLAG << " || Tree Size: " << tree -> nodeNum;
        std::cout << " || Set Size: " << seen.size() << std::endl;
    }

    std::cout << "Inorder Traversal: Should be Monotonically Increasing" << std::endl;
    tree -> InorderTraverse([](auto p){std::cout << p -> key << " ";});

    std::cout << std::endl << "Erasing All Elements:" << std::endl;
    for(int j = 0; j < 10000; ++j){
        std::cout << j << std::endl;
        tree -> remove(j);
        seen.erase(j);
    }
    std::cout << std::endl << "Inorder Traversal: Should be Empty" << std::endl;
    tree -> InorderTraverse([](auto p){std::cout << p -> key << " ";});

}




int main(int argc, char* argv[]){
    
    BinaryTree<int, int>* tree = new BinaryTree<int, int>();

    insertion_test_<BinaryTree<int, int>>(tree, 1000);

    return 0;
}