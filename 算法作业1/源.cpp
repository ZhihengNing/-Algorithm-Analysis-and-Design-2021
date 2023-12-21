#include <iostream>
#include <vector>
using namespace std;
class solution
{
private:
	static int sign;//标志位用来标记输出的是否是第一个数字，若是则不需要输出逗号
	int size;//用来表示vector数组的大小,也等于数字的位数
	int differ_num;//表述相邻两位差的绝对值
public:
	vector<int>buf;//用来存储数字
	solution(int  n = 0, int k = 0) :size(n), differ_num(k){};//构造函数
	void function(int num,int num_count);//n代表数字位上的大小，num_count为记录数字的位数
	void display();//输出数组中的元素
	void main_function();//k为相邻两位差值的绝对值
	~solution() {};//析构函数
};
int solution::sign = 0;
void solution::function(int num,  int num_count)
{
	if (size ==1)//
	{
		cout << "不存在符合条件的数字" << endl;
		exit(0);
	}
	else
	{
		if (num_count == size - 1)//当数组的数组存储符合要求位数时,便输出
		{
			display();
			return;
		}
		//先进行减法的判断
		if (num -  differ_num>= 0)
		{
			buf.push_back(num - differ_num);//数组存入符合要求的数字
			function(num - differ_num, num_count + 1);//递归
			buf.pop_back();//递归回溯，数组弹出最后一位数字
		}
		//再进行加法的判断
		if (num + differ_num<= 9 && differ_num!= 0)//防止重复加入元素，若k=0，则n+k=n-k,此时将会重复计算
		{
			buf.push_back(num + differ_num);//数组存入符合要求的数字
			function(num + differ_num,  num_count + 1);//递归
			buf.pop_back();//递归回溯，数组弹出最后一位数字
		}
	}
}
void solution::display()
{
	if (sign != 0)
	{
		cout << ",";
	}
	for (int i = 0; i < size; i++)
	{
		cout << buf[i];
	}
	sign++;
}
void solution::main_function()
{
	for (int i = 1; i <= 9; i++)//数字开头不能为0，所以循环只需要遍历九次
	{
		buf.push_back(i);//先往数组里面添加第一位数字
		function(i, 0);
		buf.pop_back();//把最开始加入到数组里的数移除
	}
}
int main()
{
	int n, k;//n为数字的位数，k为相邻两位的差值
	cout << "请输入数字的位数和相邻两位的差值：" << endl;
	while (1)
	{
		cin >> n >> k;
		//错误输入的判断，只有输入的数据符合要求才会被变量接收
		if (cin.good() != true || k < 0 || k > 9 || n <= 0)
		{
			cout << "输入的数据有误,请重新输入:" << endl;
			cin.clear();
			cin.ignore(9999, '\n');
			continue;
		}
		break;
	}
	solution temp(n, k);
	cout << "符合条件的数字有:" << endl;
	temp.main_function();
}