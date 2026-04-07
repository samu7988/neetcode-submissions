class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        

        if(s.size() % 2 != 0)
        {
            return false;
        }
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {   
                if(st.empty())
                {
                    return false;      //if stack is empty 
                }
                char res = st.top();
                st.pop();
                if(s[i] == ')' &&  res != '(') return false;
                if(s[i] == ']' &&  res != '[') return false;
                if(s[i] == '}' &&  res != '{') return false;

            }
        }
        if(st.empty())
        {
            return true;
        }
        return false;
    }
};
