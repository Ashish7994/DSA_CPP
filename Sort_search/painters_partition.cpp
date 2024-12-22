#include<iostream>
using namespace std;
#include<vector>

class solution{
    public:
    bool isValid(vector<int> &arr,int n,int m,int mid)
    {
        int painter =1,board =0,allowed_time = mid;
        for(int i=0;i<n;i++)
        {
            if(arr[i] > allowed_time) return false;
            if(board+arr[i] <= allowed_time)
                board += arr[i];
            else{
                painter++;
                board = arr[i];
            }
        }
        return painter > m? false:true;
    }
    int painter_partition(vector<int> &arr,int m)
    {
        int n= arr.size();
        int low = 0,high=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(low < arr[i])
                low = arr[i];
        }
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
    vector<int> arr = {40,30,10,20};
    int m = 2;
    solution sol;
    cout << sol.painter_partition(arr,m) <<endl;
    return 0;
}