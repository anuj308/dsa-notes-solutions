#include <bits/stdc++.h>
using namespace std;

int evenlyDivides(int n)
{
    int ori = n;
    int count = 0;
    while (n > 0)
    {
        int temp = n % 10;
        if (temp != 0 && ori % temp == 0)
        {
            count++;
        }
        n /= 10;
    }
    return count;
}
// https://leetcode.com/problems/reverse-integer/
int reverse(int n)
{
    int ans = 0;
    int x = n;
    while (x > 0)
    {
        int temp = x % 10;
        ans = ans * 10 + temp;
        x /= 10;
    }
    if (n < 0)
    {
        cout << -1 * ans;
    }

    cout << ans;
}

bool isPalindrome(int x)
{
    long long reverse = 0;
    long long original = x;

    while (x > 0)
    {
        int temp = x % 10;
        reverse = reverse * 10 + temp;
        x /= 10;
    }
    if (original == reverse)
    {
        return true;
    }
    return false;
}
bool checkArmstrong(int n)
{
    int original = n;
    int ans = 0;
    int numDigit = 0;
    while (n > 0)
    {
        numDigit++;
        n /= 10;
    }
    n = original;
    while (n > 0)
    {
        int temp = n % 10;
        ans += pow(temp, numDigit);
        n /= 10;
    }

    if (original == ans)
        return true;
    return false;
}
// https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
int sumOfDivisors(int n)
{

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        ans += sum;
        sum = 0;
    }

    return ans;
}
bool isPrime(int n)
{
    // if (n == 0 || n == 1)
    //     return false;
    // for (int i = 2; i < n; i++)
    // {   
    //     if (n % i == 0)
    //     {
    //         return false;
    //     }
    // }
    // return true;
    int x = sqrt(n);
    int c=0;
    for (int i = 1; i <=x; i++)
    {   
        if (n % i == 0)
        {
            c++;
        }
    }
    if(c==1) return true;
    return false;
}

int gcd(int a,int b){
    int gcd = 1;
        
    int n = min(a,b);
    
    for(int i=n;i>1;i--){
        if(a%i==0 && b%i==0){
            gcd = i;
            break;
        }
    }
    return gcd;
}
// https://www.geeksforgeeks.org/problems/count-digits5716/1


int main()
{
    // ctrl + shift + b
    // basic maths

    // 2344%10 = 4
    // 2344/10=234.4 = 234(int)
    // reverse(-123);
    // cout << checkArmstrong(1634);
    // cout << sumOfDivisors(4);
    cout << isPrime(36);
    return 0;
}