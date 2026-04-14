class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
	    vector<int>v;

    for(int i=0 ; i < nums.size(); i++)
    {
        int rem = target - nums[i];

        if(mp.find(rem) != mp.end())     // if got it 
        {	
            v.push_back(mp[rem]);
            v.push_back(i);

            break;
        }
            mp[nums[i]] = i; //future use 
    }
        return v;

}
};
