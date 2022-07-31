class Solution {
public:
    int maxArea(vector<int>& a) {
    int lmax=0;
	int i=0,j=a.size()-1;
	while(i<j)
	{
		if(a[i]<=a[j])
		{
			int k=a[i]*(j-i);
			if(lmax<k)
			lmax=k;
			i++;
		}
		else
		{
			int k=a[j]*(j-i);
			if(lmax<k)
			lmax=k;
			j--;
		}
	}
	return lmax;
        
    }
};