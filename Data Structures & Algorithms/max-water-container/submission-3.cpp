class Solution {
public:
    int maxArea(vector<int>& hts) {
        int left = 0;
        int right = hts.size()-1;
        int area = 0;
        int max_area = 0;

        while(left <= right)
        {
            area = min(hts[left], hts[right]) * (right - left);
            max_area = max(max_area, area);
            if( hts[left] < hts[right] )
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
    }
};
