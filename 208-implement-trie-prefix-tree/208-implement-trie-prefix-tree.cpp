class TrieNode{
    public:
    TrieNode* child[26];
    bool isendWord=false;
    TrieNode()
    {
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};
class Trie {
public:
     TrieNode *root=new TrieNode();
    Trie() {
        
    }
    
    void insert(string word) {
         TrieNode *tmp=root;
        for(int i=0;i<word.size();i++)
        {
            if(tmp->child[word[i]-'a']==NULL)
            {
                tmp->child[word[i]-'a']=new TrieNode();
            }
            tmp=tmp->child[word[i]-'a'];
        }
        tmp->isendWord=true;
    }
    
    bool search(string word) {
        TrieNode *tmp=root;
        for(int i=0;i<word.size();i++)
        {
            if(tmp->child[word[i]-'a']==NULL)
            {
              return false;
            }
            tmp=tmp->child[word[i]-'a'];
        }
        return tmp->isendWord;
    }
    
    bool startsWith(string word) {
        TrieNode *tmp=root;
        for(int i=0;i<word.size();i++)
        {
            if(tmp->child[word[i]-'a']==NULL)
            {
              return false;
            }
            tmp=tmp->child[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */