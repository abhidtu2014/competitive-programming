class TrieNode {
    public:
    int shared;
    TrieNode *children[26];
    bool isLeaf;
    TrieNode () {
        isLeaf = false;
        shared = 0;
        for (int i=0;i<26;i++) {
            children[i] = NULL;
        }
    }
    ~TrieNode () {
        for (int i=0;i<26;i++) {
            delete children[i];
        }
    }
};

class Trie {
    TrieNode *root;
    public:
    Trie() {
        root = new TrieNode ();
    }
    ~Trie() {
        delete root;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for (int i=0;i<word.size();i++) {
            char ch = word[i]-'a';
            node->shared++;
            if (!node->children[ch]) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isLeaf = true;
    }
    
     string uniquePrefix (string word) {
        TrieNode *node = root;
        string ans="";
        for (int i=0;i<word.size();i++) {
            char ch = word[i]-'a';
            ans+=word[i];
            node = node->children[ch];
            if (node->shared == 1) {
                return ans;
            }
        }
        return word;
    }
    
};
vector<string> Solution::prefix(vector<string> &A) {
    Trie *T = new Trie();
    for (auto it:A) T->insert(it);
    vector<string> res;
    for (auto it: A) {
        res.push_back(T->uniquePrefix(it));
    }
    return res;
}
