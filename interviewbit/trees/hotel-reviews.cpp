class TrieNode {
    public:
    TrieNode *children[26];
    bool isLeaf;
    TrieNode () {
        isLeaf = false;
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
    
    TrieNode* searchPrefix (string word) {
        TrieNode *node = root;
        for (int i=0;i<word.size();i++) {
            char ch = word[i]-'a';
            if (!node->children[ch]) return NULL;
            node= node->children[ch];
        }
        return node;
    }
    public:
    /** Initialize your data structure here. */
    
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
            if (!node->children[ch]) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = searchPrefix(word);
        return node != NULL && node->isLeaf;
    }
};

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first == b.first) 
        return a.second < b.second;
    
    return a.first > b.first;    
}

vector<int> Solution::solve(string A, vector<string> &B) {
    Trie *t = new Trie();
    string temp="";
    A+='_';
    for (int i=0;i<A.size();i++) {
        if (A[i]=='_') {
            t->insert(temp);
            temp="";
            continue;
        }
        temp+=A[i];
    }
    vector<pair<int, int>> v;
    int cnt=0;
    for (int i=0;i<B.size();i++) {
        temp="";
        cnt=0;
        B[i]+='_';
        for (int j=0;j<B[i].size();j++) {
            if (B[i][j]=='_') {
                if (t->search(temp)) {
                    cnt++;
                }
                temp="";
                continue;
            }
            temp+=B[i][j];
        }
        v.push_back({cnt, i});
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> ans;
    for (int i=0;i<B.size();i++) {
        ans.push_back(v[i].second);
    }
    return ans;
}
