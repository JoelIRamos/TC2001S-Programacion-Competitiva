// Kolya and Tanya
#include<iostream>
#include <math.h>

using namespace std;

const long long modulo= 1000000007;

int getTotalCombinatios(int n)
{
    long long sum1=1;
    long long sum2=1;

    for(int i=1;i<=n;i++)
    {
        sum1= ((int) pow(3, 3) * sum1 ) % modulo;
        sum2 = (7 * sum2 ) % modulo;

    }
    return (((sum1+modulo)-sum2)% modulo);

}


int main()
{
    long long n;

    cin >> n;

    cout << getTotalCombinatios(n);
}