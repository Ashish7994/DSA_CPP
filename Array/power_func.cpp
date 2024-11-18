#include<iostream>
using namespace std;

class solution{
    public:
    double powerfun(double x, int n)
    {
        if(n==0) return 1.0;
        if(x==1.0) return 1.0;
        if(x == -1.0)
        {
            if(n%2 == 0) return 1.0;
            return -1.0;
        }
        if(n<0)
        {
            x = 1/x;
            n = -n;
        }
        long binform = n;
        double ans = 1;
        while(binform > 0)
        {
            if(binform %2 == 1.0)
                ans *= x;
            x *= x;
            binform /= 2;
        }
        return ans;
    }
};

int main()
{
    double x = 3;
    int n = 4;
    solution sol;
    cout << sol.powerfun(x,n) << endl;
    return 0;
}