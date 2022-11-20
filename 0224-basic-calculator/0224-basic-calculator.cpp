class Solution {
public:
    int calculate(string s) {
        // https://youtu.be/-SmH1UavSaE
        int sum=0,sign=1;
        stack<int> st;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0' and s[i]<='9')
            {
                int num=0;
                while(s.size()>i and s[i]>='0' and s[i]<='9')
                {
                    num=num*10+(s[i]-'0');
                    i++;
                }
                num*=sign;
                sum+=num;
                // i--;
            }
            if(s[i]=='+')
                sign=1;
            if(s[i]=='-')
                sign=-1;
            if(s[i]=='(')
            {
                st.push(sum);
                st.push(sign);
                sum=0;
                sign=1;
            }
            if(s[i]==')')
            {
                sign=st.top();
                st.pop();
                int temp=st.top();
                st.pop();
                sum*=sign;
                sum+=temp;
            }
        }
        return sum;
    }
};