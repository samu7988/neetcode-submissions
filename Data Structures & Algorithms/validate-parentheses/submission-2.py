class Solution:
    def isValid(self, s: str) -> bool:
        
        st = []                                          # stack<char> st (use list as stack)
        
        if len(s) % 2 != 0:                              # if(s.size() % 2 != 0)
            return False
        
        for i in range(len(s)):                          # for(int i = 0; i < s.size(); i++)
            
            if s[i] == '(' or s[i] == '[' or s[i] == '{':   # opening bracket
                st.append(s[i])                          # st.push(s[i])
            
            elif s[i] == ')' or s[i] == ']' or s[i] == '}': # closing bracket
                
                if not st:                               # if(st.empty())
                    return False
                
                res = st[-1]                             # char res = st.top()
                st.pop()                                  # st.pop()
                
                if s[i] == ')' and res != '(':           
                    return False
                if s[i] == ']' and res != '[':           
                    return False
                if s[i] == '}' and res != '{':           
                    return False
        
        if not st:                                       # if(st.empty())
            return True
        return False