#include<iostream>
using namespace std;
#include<vector>

class solution{
    public:
    int maxprofit(vector<int> &price)
    {
        int maxprofit = 0, bestbuy = price[0];
        for(int val:price)
        {
            if(val>bestbuy)
                maxprofit = max(maxprofit,val-bestbuy);
            bestbuy = min(bestbuy,val);
        }
        return maxprofit;
    }

};

int main()
{
    vector<int> price = {7,1,5,3,6,4};
    solution sol;
    cout << sol.maxprofit(price)<< endl;
    return 0;
}