class Solution {
public:
    char findpar(vector<char> &hash,char vl)
    {
        while(hash[vl-'a']!=vl)
        {
            vl=hash[vl-'a'];
        }
        return vl;
    }
    static bool cmp(string a,string b)
    {
       if((a[1]==b[1]))
           return a[0]<b[0];
       return a[1]!='!';
    }
    bool equationsPossible(vector<string>& es) {
        vector<char> hash(26);
        for(int i=0;i<26;i++)
        {
            hash[i]=i+'a';
        }
        for(int i=0;i<es.size();i++)
        {
            if(es[i][0]>es[i][3])
                swap(es[i][0],es[i][3]);
        }
        sort(es.begin(),es.end(),cmp);
        // for(auto it:es)
        //     cout<<it<<" ";
        for(int i=0;i<es.size();i++)
        {
            char sf=es[i][0];
            char fs=es[i][3];
            if(sf==fs and es[i][1]=='=')
                continue;
            else if(sf==fs and es[i][1]=='!')
                return false;
            char par_sf=findpar(hash,sf);
            char par_fs=findpar(hash,fs);
            if(es[i][1]=='!')
            {
                if(par_sf==par_fs)
                    return false;
            }
            else if(es[i][1]=='=')
            {
                if(par_sf==par_fs)
                    continue;
                else 
                {
                    hash[par_sf-'a']=par_fs;
                }
            }
        }
        
        
        return true;
    }
};