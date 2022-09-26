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
    bool equationsPossible(vector<string>& es) {
        vector<char> hash(26);
        for(int i=0;i<26;i++)
        {
            hash[i]=i+'a';
        }
        for(int i=0;i<es.size();i++)
        {
            if(es[i][1]=='!')
                continue;
            char sf=es[i][0];
            char fs=es[i][3];
            char par_sf=findpar(hash,sf);
            char par_fs=findpar(hash,fs);
                if(par_sf==par_fs)
                    continue;
                else 
                {
                    hash[par_sf-'a']=par_fs;
                }
        }
        for(int i=0;i<es.size();i++)
        {
            if(es[i][1]=='=')
            continue;
            char sf=es[i][0];
            char fs=es[i][3];
            char par_sf=findpar(hash,sf);
            char par_fs=findpar(hash,fs);
            if(par_sf==par_fs)
                return false;
        }
        
        
        return true;
    }
};