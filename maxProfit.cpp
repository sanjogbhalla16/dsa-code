class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for(int i=0;i<n;i++)
        {
            //where dec will stop we buy
            while(i+1<n && prices[i]>prices[i+1])
            {
                i++;
            }
            //we now buy
            int buy = prices[i]; //next one is bigger
            while(i+1<n && prices[i]<prices[i+1])
            {
                i++;
            }
            //now we sell
            ans += (prices[i]-buy);
        }
        return ans;
    }
};
