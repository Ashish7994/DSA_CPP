#include<iostream>
using namespace std;
#include <vector>

class solution{
    public:
    vector<int> pairsum(vector<int>& num,int target)
    {
        vector<int> res;
        int i = 0;
        int j= num.size();
        while(i<j)
        {
            int pairsum = num[i] + num[j];
            if(pairsum > target)
                j--;
            else if(pairsum < target)
                i++;
            else
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
        }
        return res;
    }
};

int main()
{
    vector<int> num = {2,7,11,15};
    solution sol;
    vector<int> ans = sol.pairsum(num,18);
    cout << ans[0] << " " << ans[1] <<endl;
    return 0;
}