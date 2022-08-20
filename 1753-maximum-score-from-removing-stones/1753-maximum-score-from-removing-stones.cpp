class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if(a>b+c)
            return b+c;
        else if(b>c+a)
            return c+a;
        else if(c>a+b)
            return a+b;
        return (a+b+c)/2;
    }
};

