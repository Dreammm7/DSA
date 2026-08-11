class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MP = 0;
        int bestbuy = prices[0];

        for(int i=1; i < prices.size(); i++){
            if(prices[i] > bestbuy){
                MP = max(MP, prices[i]-bestbuy);
            }
            bestbuy = min(bestbuy, prices[i]);
        }
        return MP;
    }
};