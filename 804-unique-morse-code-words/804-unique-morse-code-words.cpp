class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string s[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> mp;
        for(auto it:words)
        {
            string tmp="";
            for(auto i:it)
            {
                tmp+=(s[i-'a']);
            }
            mp.insert(tmp);
        }
        return mp.size();
    }
};