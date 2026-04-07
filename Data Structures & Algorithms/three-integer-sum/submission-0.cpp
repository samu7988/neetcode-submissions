class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int>v;
        set<vector<int>>st;

        for(int i = 0; i < nums.size(); i++)
        {
            map<int,int>mp;

            for(int j = i+1; j < nums.size(); j++)
            {
                int third = -(nums[i] + nums[j]);

                if(mp.find(third) != mp.end())
                {
                    v = {nums[i], nums[j], third};
                    sort(v.begin(),v.end());
                    st.insert(v);
                }
                mp[nums[j]]++;
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};
