// Use a stack to store indices of days we haven't found a warmer day for yet.
// When we find a warmer day → pop and calculate the difference in indices.




class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> result(n, 0);       // default 0 (no warmer day found)
        stack<int> st;                  // stores indices

        for (int i = 0; i < n; i++)
        {
            // current temp is warmer than temp at stack top
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int idx = st.top();         // day waiting for warmer temp
                st.pop();
                result[idx] = i - idx;      // days waited = current - that day
            }
            st.push(i);                     // push current day index
        }

        return result;
    }
};
