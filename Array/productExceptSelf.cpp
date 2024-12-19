#include<iostream>
using namespace std;
#include<vector>
#include<thread>

class solution
{
    public:
    vector<int> productexceptself(vector<int> &num)
    {
        int n = num.size();
        vector<int> ans(n,1);
        for(int i = 1;i<n;i++)
        {
            ans[i] = ans[i-1]*num[i-1];
        }
        int suffix = 1;
        for(int i = n-2;i>=0;i--)
        {
            suffix = suffix*num[i+1];
            ans[i] = ans[i] * suffix;
        }
        return ans;
    }
};

int main()
{
    vector<int> num = {1,2,3,4};
    solution sol;
    vector<int> ans = sol.productexceptself(num);
    for(int val:ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}