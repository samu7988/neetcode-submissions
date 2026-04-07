class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>st;
        int res3 = 0;

        for(int i = 0 ; i < tokens.size(); i++)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*" )
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                  int res1 = st.top();
                  st.pop();
                  int res2 = st.top();
                  st.pop();
                  if (tokens[i] == "+")
                  {
                        res3 = res1 + res2;
                  }
                  else if (tokens[i] == "-")
                  {
                         res3 = res2 - res1;

                  }
                  else if (tokens[i] == "*")
                  {
                         res3 = res1 * res2;

                  }
                  else if (tokens[i] == "/")
                  {
                         res3 = res2 / res1;

                  }
                  st.push(res3);
            }
        }
        if(st.empty())
        {
            return 0;
        }
        res3 = st.top();
        st.pop();
        return res3;

    }
};
