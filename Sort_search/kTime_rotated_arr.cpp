#include<iostream>
using namespace std;
#include<vector>

class solution{
    public:
    int k_rotations(vector<int> &arr)
    {
        int low=0,high = arr.size()-1;
        while(low <= high)
        {
            if(arr[low] <= arr[high]) return low;
            int mid = low+(high-low)/2;
            if(arr[mid] > arr[high])
                low =mid+1;
            else 
                high = mid;

        }
        return low;
    }

};

int main()
{
    vector<int> arr = {3,4,5,6,7,0,1,2};
    solution sol;
    cout << sol.k_rotations(arr) << endl;
    //cout << sol.recursive_sol(arr,120,0,arr.size()-1);
    return 0;
}