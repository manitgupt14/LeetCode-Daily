/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *node,unordered_map<int,Node *> &mp)
    {
        for(auto it:node->neighbors)
        {
            if(mp.find(it->val)==mp.end())
            {
                mp[it->val]=it;
                dfs(it,mp);
            }
        }
        return ;
    }
    void merge(Node *node,unordered_map<Node *,Node *> &mpp,unordered_set<Node *> &us)
    {
        us.insert(node);
        for(auto it:node->neighbors)
        {
            mpp[node]->neighbors.push_back(mpp[it]);
            if(us.find(it)==us.end())
            merge(it,mpp,us);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<int,Node *> mp;
        mp[node->val]=node;
        dfs(node,mp);
        
        unordered_map<Node *,Node *> mpp;
        for(auto it:mp)
        {
            mpp[it.second]=new Node(it.first);
        }
        unordered_set<Node *> us;
        merge(node,mpp,us);
        return mpp[mp[1]];
    }
};