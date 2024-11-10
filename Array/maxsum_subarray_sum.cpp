#include <iostream>
using namespace std;
#include <vector>

class solution{
    public:
    int maxsum_subarray(int arr[],int n)
    {
        int currsum = 0;
        int maxsum = INT16_MIN;
        for(int i =0;i<n;i++)
        {
            currsum += arr[i];
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }

};

int main(){
    int arr[] = {0,1,2,3,4,5,-6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    solution maxsum;

    cout << "max sum: " << maxsum.maxsum_subarray(arr,n) << endl;
    return 0;
}