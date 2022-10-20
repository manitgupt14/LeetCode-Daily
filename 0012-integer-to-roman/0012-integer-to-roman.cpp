class Solution {
public:
    string intToRoman(int num) {
     map<int,string> mp;
     mp[1]="I";
     mp[5]="V";
     mp[10]="X";
     mp[50]="L";
     mp[100]="C";
     mp[500]="D";
     mp[1000]="M";
     mp[10000]='Q';
     int vl=1;
     while(vl<10000)
     {
        for(int i=vl;i<vl*10;i+=vl)
        {
            if(i==vl*5)
                continue;
            if(i<vl*4)
            {
                mp[i]=mp[i-vl]+mp[vl];
            }
            else if(i==vl*4)
            {
                mp[i]=mp[i/4]+mp[vl*5];
            }
            else if(i<vl*9)
            {
                mp[i]=mp[i-vl]+mp[vl];
            }
            else
                mp[i]=mp[vl]+mp[vl*10];
        }
        vl*=10;
     }
        
     int val=1;
     vector<int> vll;
     while(num>0)
     {
         int tmp=(num%10)*val;
         vll.push_back(tmp);
         num/=10;
         val*=10;
     }
        
        
    string ans="";
     for(auto it:vll)
     {
         ans=mp[it]+ans;
     }
        return ans;
    
    }
};