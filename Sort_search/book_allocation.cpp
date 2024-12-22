#include<iostream>
using namespace std;
#include<vector>

class solution{
    public:
    bool isValid(vector<int> &arr,int n,int m,int mid)
    {
        int std = 1,pages = 0,allowed_page=mid;
        for(int i=0;i<n;i++)
        {
            if(arr[i] > allowed_page) return false;
            if(pages + arr[i] <= allowed_page)
                pages += arr[i];
            else{
                std++;
                pages = arr[i];
            }
        }
        if(std > m) return false;
        return true;
    }
    int max_book_alloc(vector<int> &arr,int m)
    {
        int low = 0,n = arr.size(),ans;
        int high = 0;
        for(int i =0;i<n;i++)
        {
            high += arr[i];
        }
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(isValid(arr,n,m,mid))
                {
                    high = mid-1;
                    ans=mid;
                }
            else
                low = mid+1;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {2,1,3,4};
    int m = 2;
    solution sol;
    cout << sol.max_book_alloc(arr,m) <<endl;
    return 0;
}