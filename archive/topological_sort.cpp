/*
    Topological Sort Using DFS
    LeetCode No. 269 Alien Dictionary
        https://leetcode.com/problems/alien-dictionary/

    Note: This solution is not optimized for best neatness & speed
*/
# include <vector>
# include <string>
# include <algorithm>

using namespace std;

// Node definition for Graph
class Node{
public:
    char alpha;
    vector<Node*> next;
    Node(char c){
        alpha = c;
        next = {};
    }
    ~Node();
};

// Solution Class
class Solution {
public:
    // Solution method
    string alienOrder(vector<string>& words) {
        vector<Node*> pool(26, nullptr);
        string prevWord = "";
        bool isDone;
        
        // Graph Construction
        for(auto &word: words){
            if(prevWord.find(word, 0) == 0 && prevWord.size() > word.size())
                return "";
            isDone = false;
            for(int p = 0; p < word.size(); ++p){
                if(pool[word[p] - 'a'] == nullptr)
                    pool[word[p] - 'a'] = new Node(word[p]);
                if(p < prevWord.size() && word[p] != prevWord[p] && !isDone){
                    pool[prevWord[p] - 'a'] -> next.push_back(pool[word[p] - 'a']);
                    isDone = true;
                }
            }
            prevWord = word;
        }
        // Topological Sort
        string retStr = "";
        vector<int> seen(26, 0);
        bool hasCycle = false;
        
        for(int i = 0; i < 26; ++i){
            if(seen[i] == 0 && pool[i] != nullptr)
                topological_sort_util(pool[i], seen, retStr, hasCycle);
        }
        if(hasCycle)
            return "";
        reverse(retStr.begin(), retStr.end());
        return retStr;

    }
    
    void topological_sort_util(Node* p, vector<int>& seen, string& str, bool& hasCycle){
        seen[p -> alpha - 'a'] = 1;
        for(auto &i: p -> next){
            if(seen[i -> alpha - 'a'] == 1)
                hasCycle = true;
            if(seen[i -> alpha - 'a'] == 0)
                topological_sort_util(i, seen, str, hasCycle);
        }
        str.push_back(p -> alpha);
        seen[p -> alpha - 'a'] = 2;
    }
    
};