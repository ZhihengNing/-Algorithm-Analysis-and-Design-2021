#include <iostream>
using namespace std;
const int max_num = 10000;
static int dp[1001][10][10];//dp[i][x][y]的含义就是前i位已经转好，并且此时第i+1位为x,i+2位置是y
inline int fun(const int arr, const int x, const char sign)//sign是符号位，+代表正转，-代表倒转
{
	if (sign == '+')
		return (arr + x) % 10;
	else
		return (arr - x + 10) % 10;
}
inline bool check(const string& arr, const string& pat)//判断两个字符串是否全是数字以及长度是否相等
{
	for (auto i : arr)
	{
		if (i < '0' || i>'9')
			return false;
	}
	for (auto i : arr)
	{
		if (i < '0' || i>'9')
			return false;
	}
	return arr.size() == pat.size();
}
int main()
{
	string arr, pat;
	cout << "请输入两个数字序列:" << endl;
	while (1)
	{
		cin >> arr >> pat;
		if (cin.good() != true||!check(arr, pat))
		{
			cout << "请重新输入两个数字序列:" << endl;
			cin.clear();
			cin.ignore(9999,'\n');
			continue;
		}
		break;
	}
	int size = arr.size();
	arr += "00";
	pat += "00";
	for (int i = 0; i <= size; ++i)//最大初始化到size即可，因为dp[n][0][0]就是我们所求
	{
		for (int x = 0; x <= 9; ++x)
		{
			for (int y = 0; y <= 9; ++y)
			{
				dp[i][x][y] = max_num;//因为要求最小值，所以数组初始化为max_num
			}
		}
	}
	dp[0][arr[0] - '0'][arr[1] - '0'] = 0;//初始只有这个状态为0
	for (int i = 1; i <= size; ++i)
	{
		for (int x = 0; x <= 9; ++x)
		{
			for (int y = 0; y <= 9; ++y)
			{
				int positive_seq= (pat[i - 1] - '0' - x + 10) % 10;//计算正转
				//这里n<=m<=positive_seq,i位转的次数>=i+1位置转的次数>=i+2位置转的次数，因为本质只对第i位操作
				//所以i+1和i+2只是从动的感觉
				for (int m = 0; m <= positive_seq; m++)
				{
					for (int n = 0; n <= m; n++)
					{
						dp[i][fun(y, m, '+')][fun(arr[i + 1] - '0', n, '+')] = min(dp[i][fun(y, m, '+')][fun(arr[i + 1] - '0', n, '+')], dp[i - 1][x][y] + positive_seq);

						//要让第i位复原，则i,i+1,i+2都可以转动（ps:这里arr[i+1]其实是第i+2位了)
					}
				}
				int negative_seq = 10 - positive_seq;//正转和逆转之和是10
				for (int m = 0; m <= negative_seq; m++)
				{
					for (int n = 0; n <= m; n++)
					{
						dp[i][fun(y, m, '-')][fun(arr[i + 1] - '0', n, '-')] = min(dp[i][fun(y, m, '-')][fun(arr[i + 1] - '0', n, '-')], dp[i - 1][x][y] + negative_seq);
					}
				}
			}
		}
	}
	cout << dp[size][0][0] << endl;
}

