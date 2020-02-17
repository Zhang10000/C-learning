#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int main()
{
    int number = 0;
    cin >> number;
    int arr[10000];
    for(int idn = 0;idn < number;++idn)
    {
        cin >> arr[idn];
    }
    
    sort(arr,arr+number);
    long long int sum1,sum2,sum3,sum4;
    sum1 = arr[0] * arr[1] * arr[2];
    sum2 = arr[number-1] * arr[number-2] * arr[number-3];
    sum3 = arr[number-1] * arr[number-2] * arr[0];
    sum4 = arr[0] * arr[1] * arr[number-1];
    
    int long long sum_zj1 = 0;
    int long long sum_zj2 = 0;
    sum_zj1 = sum1 > sum2 ? sum1 : sum2;
    sum_zj2 = sum3 > sum4 ? sum3 : sum4;
    int long long sum = 0;
    sum = sum_zj1 > sum_zj2 ? sum_zj1 :sum_zj2;
    cout << sum <<endl;
}
