class Solution {
public:
    int minPartitions(string n) {
        int r;
        char mas=n[0];
        for(int i=0;i<n.size();i++)
        {
            if(mas<n[i])
                mas=n[i];
            if(mas=='9')
                break;
        }
        return mas-'0';
    }
};