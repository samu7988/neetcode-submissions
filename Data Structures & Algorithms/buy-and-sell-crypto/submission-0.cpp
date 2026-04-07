class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;           // buy pointer
        int right = 1;          // sell pointer
        int maxPro = 0;         // best profit

        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                // profitable → calculate profit
                int profit = prices[right] - prices[left];
                maxPro = max(maxPro, profit);
            } else {
                // found cheaper price → move buy pointer
                left = right;
            }
            right++;
        }

        return maxPro;
    }
};