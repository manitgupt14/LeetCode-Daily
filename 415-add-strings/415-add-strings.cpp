class Solution {
public:
    // num1 has always greater length
    string addStrings(string num1, string num2) {
          if(num2.size()>num1.size())
              return addStrings(num2,num1);
        
        int i=num1.size()-1;
        int j=num2.size()-1;
        
        int carry=0;
        
        while(i>=0 and j>=0)
        {
            int a=num1[i]-'0';
            int b=num2[j]-'0';
            
            num1[i]=num2[j]=((a+b+carry)%10) + '0';
            carry= (a+b+carry)/10;
            i--;
            j--;
        }
        
        while(i>=0)
        {
            int a=num1[i]-'0';
            num1[i]= ((a+carry)%10) + '0';
            carry= (a+carry)/10;
            
            i--;
        }
        
        if(carry!=0)
        {
            char tmp=carry+'0';
            num1= tmp + num1;
        }
    
        
        return num1;
        
    }
};