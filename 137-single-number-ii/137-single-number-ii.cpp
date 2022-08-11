class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int ans = 0, k = 3;
        for(int i=0;i<32;i++){
            
            int count = 0;
            int mask = (1<<i);
            for(auto n:arr){
                if((n&mask)!=0) count++;
            }
            if(count%k!=0){
                ans |= (1<<i);
            }
        }
        return ans;
    }
};