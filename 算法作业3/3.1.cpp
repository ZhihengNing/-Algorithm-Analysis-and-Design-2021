#include <iostream>
using namespace std;
int Permutations(const int m, const int n)//计算排列数
{
    int ans = 1;
    for (int k = m; k > m - n; k--)
    {
        ans *= k;
    }
    return ans;
}
int Solutions(const int n)
{
    int* dp = new int[n + 1];
    dp[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + 9 * Permutations(9, i - 1);
    }
    return dp[n];
}
int main()
{
    int n;
    cout << "请输入数字(0-9):" << endl;
    while (1)
    {
        cin >> n;
        if (!cin.good()||n<0||n>9)
        {
            cout << "输入的数据有误,请重新输入：" << endl;
            cin.clear();
            cin.ignore(9999,'\n');
        }
        else
            break;
    }
    cout << Solutions(n);
}