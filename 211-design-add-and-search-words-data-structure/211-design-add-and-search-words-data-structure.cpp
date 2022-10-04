class TrieNode{
    public:
    TrieNode * child[26];
    bool isEnd=false;
    TrieNode()
    {
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};

class WordDictionary {
public:
    TrieNode *root;
    
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->child[word[i]-'a']==NULL)
                temp->child[word[i]-'a']=new TrieNode();
            temp=temp->child[word[i]-'a'];
        }
        temp->isEnd=true;
    }
    bool check(string &word,TrieNode *root,int i)
    {   
        if(root==NULL) return false;
        
        if(i>=word.size())
            return root->isEnd;
        if(word[i]=='.')
        {
            for(int j=0;j<26;j++)
            {
                if(root->child[j]!=NULL and check(word,root->child[j],i+1))
                {
                    return true;
                }
            }
            return false;
        }
        
        if(root->child[word[i]-'a']!=NULL)
            return check(word,root->child[word[i]-'a'],i+1);
        
        return false;
        
    }
    bool search(string word) {
        TrieNode *temp=root;
        for(int i=0;i<word.size();i++)
        {
           if(word[i]=='.')
           {
               return check(word,temp,i);
           }
           else if(temp->child[word[i]-'a']==NULL)
               return false;
            temp=temp->child[word[i]-'a'];
        }
        return temp->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */