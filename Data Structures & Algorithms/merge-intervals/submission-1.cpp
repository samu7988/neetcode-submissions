class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // ── Step 1: sort intervals by start time ──
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);                   // add first interval

        // ── Step 2: iterate and merge ──
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int>& last = result.back();             // last merged interval

            if (intervals[i][0] <= last[1])                // overlap detected
            {
                last[1] = max(last[1], intervals[i][1]);   // extend end if needed
            }
            else
            {
                result.push_back(intervals[i]);            // no overlap → add as new
            }
        }

        return result;
    }
};