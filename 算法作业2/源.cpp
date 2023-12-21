#include <iostream>
using namespace std;
const int max_num = 10000;
static int dp[1001][10][10];//dp[i][x][y]�ĺ������ǰiλ�Ѿ�ת�ã����Ҵ�ʱ��i+1λΪx,i+2λ����y
inline int fun(const int arr, const int x, const char sign)//sign�Ƿ���λ��+������ת��-����ת
{
	if (sign == '+')
		return (arr + x) % 10;
	else
		return (arr - x + 10) % 10;
}
inline bool check(const string& arr, const string& pat)//�ж������ַ����Ƿ�ȫ�������Լ������Ƿ����
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
	cout << "������������������:" << endl;
	while (1)
	{
		cin >> arr >> pat;
		if (cin.good() != true||!check(arr, pat))
		{
			cout << "����������������������:" << endl;
			cin.clear();
			cin.ignore(9999,'\n');
			continue;
		}
		break;
	}
	int size = arr.size();
	arr += "00";
	pat += "00";
	for (int i = 0; i <= size; ++i)//����ʼ����size���ɣ���Ϊdp[n][0][0]������������
	{
		for (int x = 0; x <= 9; ++x)
		{
			for (int y = 0; y <= 9; ++y)
			{
				dp[i][x][y] = max_num;//��ΪҪ����Сֵ�����������ʼ��Ϊmax_num
			}
		}
	}
	dp[0][arr[0] - '0'][arr[1] - '0'] = 0;//��ʼֻ�����״̬Ϊ0
	for (int i = 1; i <= size; ++i)
	{
		for (int x = 0; x <= 9; ++x)
		{
			for (int y = 0; y <= 9; ++y)
			{
				int positive_seq= (pat[i - 1] - '0' - x + 10) % 10;//������ת
				//����n<=m<=positive_seq,iλת�Ĵ���>=i+1λ��ת�Ĵ���>=i+2λ��ת�Ĵ�������Ϊ����ֻ�Ե�iλ����
				//����i+1��i+2ֻ�ǴӶ��ĸо�
				for (int m = 0; m <= positive_seq; m++)
				{
					for (int n = 0; n <= m; n++)
					{
						dp[i][fun(y, m, '+')][fun(arr[i + 1] - '0', n, '+')] = min(dp[i][fun(y, m, '+')][fun(arr[i + 1] - '0', n, '+')], dp[i - 1][x][y] + positive_seq);

						//Ҫ�õ�iλ��ԭ����i,i+1,i+2������ת����ps:����arr[i+1]��ʵ�ǵ�i+2λ��)
					}
				}
				int negative_seq = 10 - positive_seq;//��ת����ת֮����10
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

