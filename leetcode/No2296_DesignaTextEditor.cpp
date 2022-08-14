# include <vector>
# include <string>
# include <algorithm>

using namespace std;

struct Node {
    char c;
    Node *left, *right;
    Node(): c(0), left(nullptr), right(nullptr) {};
    Node(char c_inp): c(c_inp), left(nullptr), right(nullptr) {};
    Node(char c_inp, Node *l_inp, Node *r_inp): c(c_inp), left(l_inp), right(r_inp) {};
};

class TextEditor {
    Node *head, *tail;
    Node *ptr;
public:
    TextEditor() {
        this -> head = new Node();
        this -> tail = new Node();
        this -> head -> right = this -> tail;
        this -> tail -> left = this -> head;
        this -> ptr = this -> head;
    }
    
    void addText(string text) {
        
        Node *tmp_p;
        
        for (auto &i: text) {
            tmp_p = new Node(i, this -> ptr, this -> ptr -> right);
            this -> ptr -> right = tmp_p;
            tmp_p -> right -> left = tmp_p;   

            this -> ptr = this -> ptr -> right;         
        }
        
    }
    
    int deleteText(int k) {
        
        Node *tmp_p;
        int del_cnter = 0;
        for (int i = 0; i < k; ++i) {
            if (this -> ptr == this -> head) {
                return del_cnter;
            }
            this -> ptr -> left -> right = this -> ptr -> right;
            this -> ptr -> right -> left = this -> ptr -> left;

            tmp_p = this -> ptr -> left;
            delete this -> ptr;
            this -> ptr = tmp_p;
            ++del_cnter;
        }
        return del_cnter;
    }
    
    string cursorLeft(int k) {
        
        int i = k;
        while (i > 0 && this -> ptr != this -> head) {
            this -> ptr = this -> ptr -> left;
            --i;
        }

        string res;
        Node *tmp_p = this -> ptr;
        while (i < 10 && tmp_p != this -> head) {
            res.push_back(tmp_p -> c);
            tmp_p = tmp_p -> left;
            ++i;
        }

        reverse(res.begin(), res.end());
        return res;
    }
    
    string cursorRight(int k) {
        
        int i = k;
        while (i > 0 && this -> ptr -> right != this -> tail) {
            this -> ptr = this -> ptr -> right;
            --i;
        }

        string res;
        Node *tmp_p = this -> ptr;
        i = 0;
        while (i < 10 && tmp_p != this -> head) {
            res.push_back(tmp_p -> c);
            tmp_p = tmp_p -> left;
            ++i;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */