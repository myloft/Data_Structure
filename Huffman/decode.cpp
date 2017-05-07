#include "node.h"
#include <string>
#include <iostream>

using namespace std;

string decode_huff(node * root,string s) {
    if (!root) return "";
    node * n = root;
    string res = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            n = n->left;
        } else if (s[i] == '1') {
            n = n->right;
        }
        
        if (n->is_leaf()) {
            res += n->data;
            n = root;
        }
    }
    return res;
}

// will rewrite this with bimaps probably
