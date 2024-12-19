#include<iostream>
using namespace std;
#include<vector>

class solution{
    public:
    int itr_search_rot_array(vector<int> &arr,int tar)
    {
        int low=0,high = arr.size()-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(tar == arr[mid]) return mid;
            if(arr[low] < arr[mid])
            {
                if(tar > arr[low] && tar < arr[mid])
                    high = mid-1;
                else
                    low = mid+1;

            }
            else{
                if(tar > arr[mid] && tar < arr[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
    int recur_search_rot_array(vector<int> &arr,int tar,int low,int high)
    {
        while(low <=high)
        {
            int mid = low + (high-low)/2;
            if(tar == arr[mid]) return mid;
            if(arr[low] < arr[mid])
            {
                if(tar > arr[low] && tar < arr[mid])
                    return recur_search_rot_array(arr,tar,low,mid-1);
                return recur_search_rot_array(arr,tar,mid+1,high);
            }
            else{
                if(tar > arr[mid] && tar < arr[high])
                    return recur_search_rot_array(arr,tar,mid+1,high);
                return recur_search_rot_array(arr,tar,low,mid-1);                   
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> arr = {3,4,5,6,7,0,1,2};
    solution sol;
    cout << sol.itr_search_rot_array(arr,0) << endl;
    cout << sol.recur_search_rot_array(arr,0,0,arr.size()-1);
    return 0;
}
