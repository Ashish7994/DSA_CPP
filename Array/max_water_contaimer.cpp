#include<iostream>
#include<vector>
 class solution{
    public:
    int optimal(std::vector<int> &vol)
    {
        int lp = 0,rp = vol.size()-1;
        int ans =0;
        while(lp<rp)
        {
            int w = rp-lp;
            int h = std::min(vol[lp],vol[rp]);
            int area = w*h;
            ans = std::max(ans,area);
            if(vol[lp] < vol[rp])
                lp++;
            else
                rp--;
        }
        return ans;
    }
    int brute(std::vector<int> &vol)
    {
        int ans=0,n=vol.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int w = j-i;
                int h = std::min(vol[i],vol[j]);
                int area = w*h;
                ans = std::max(ans,area);
            }
        }
        return ans;
    }
 };


int main()
{
    std::vector<int> vol = {1,8,6,2,5,4,8,3,7};
    solution sol;
    std::cout << sol.optimal(vol)<< std::endl;
    std::cout << sol.brute(vol)<< std::endl;
    return 0;
}