class Solution {
    private:
    int sm(int n)
    {
        int rev=0;
        int k=n;
        while(n>0)
        {
            rev=rev*10+n%10;
            n/=10;
        }
        return k+rev;
    }
public:
    bool sumOfNumberAndReverse(int num) {
         
        for(int i=0;i<=num;i++)
        {
            if(sm(i)==num)
                return true;
        }
        return false;
    }
};