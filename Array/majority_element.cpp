#include <iostream>
using namespace std;
#include <vector>

class solution{
    public:
    int majority_elem(vector<int>& num)
    {
        int ans = 0;
        int freq = 0;
        for(int i=0; i<(int) num.size(); i++)
        {
            if(freq == 0)
            ans = num[i];
            if(ans == num[i]) freq++;
            else freq--;
        }
        int count = 0;
        for(int val:num)
        {
            if(ans == val) count++;
        }
        int n= (int) num.size();
        if(count > n/2) 
            return ans;
        return -1;
    }
};

int main()
{
    vector<int> num = {1,2,2,1,1,2,2};
    solution sol;
    cout << sol.majority_elem(num) << endl;
    return 0;
}