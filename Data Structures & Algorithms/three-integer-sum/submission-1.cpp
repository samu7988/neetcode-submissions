class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> v;                                     // temp storage for one triplet
        set<vector<int>> st;                               // stores unique triplets (auto removes duplicates)

        for(int i = 0; i < nums.size(); i++)
        {
            map<int,int> mp;                               // fresh map for each i (tracks seen nums[j])

            for(int j = i+1; j < nums.size(); j++)
            {
                int third = -(nums[i] + nums[j]);          // third value needed to make sum = 0

                if(mp.find(third) != mp.end())             // was 'third' seen before in this inner loop?
                {
                    v = {nums[i], nums[j], third};         // valid triplet found
                    sort(v.begin(), v.end());              // sort so [−1,0,1] and [0,−1,1] are treated same
                    st.insert(v);                          // set ignores duplicates automatically
                }
                mp[nums[j]]++;                             // mark nums[j] as seen for future j iterations
            }                                              // (like two sum: store candidates, check later)
        }
        return vector<vector<int>>(st.begin(), st.end()); // convert set → vector before returning
    }
};