class Solution {
public:
    int maxArea(vector<int>& hts) {
        int left = 0 ; 
        int right = hts.size()-1;
        int area = 0;
        int max_area = 0;

        while(left < right)
        {
            area = (right - left) * min(hts[left],hts[right]);
            max_area = max(area,max_area);
            if(hts[left] < hts[right])
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
