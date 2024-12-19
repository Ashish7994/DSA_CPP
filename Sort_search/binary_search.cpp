#include<iostream>
using namespace std;
#include<vector>

class solution{
    public:
    int iterative_sol(vector<int> &arr,int tar)
    {
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(tar < arr[mid])
                high = mid-1;
            else if(tar > arr[mid])
                low = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    int recursive_sol(vector<int> &arr,int tar, int low,int high)
    {
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(tar == arr[mid])
                return mid;
            if(tar > arr[mid])
                return recursive_sol(arr,tar,mid+1,high);
            return recursive_sol(arr,tar,low,mid-1);
        }
        return -1;
    }
};

int main()
{
    vector<int> arr = {20,26,35,63,120,155,178};
    solution sol;
    cout << sol.iterative_sol(arr,120) << endl;
    cout << sol.recursive_sol(arr,120,0,arr.size()-1);
    return 0;
}