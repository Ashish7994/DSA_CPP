#include<iostream>
using namespace std;
#include<vector>

class solution{
    public:
    int mountain_arr_idx(vector<int> &arr)
    {
        int low=1,high=arr.size()-2;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid;
            if(arr[mid-1] < arr[mid]) 
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }

};

int main()
{
    vector<int> arr = {0,3,8,9,11,5,2};
    solution sol;
    cout << sol.mountain_arr_idx(arr) <<endl;
    return 0;

}