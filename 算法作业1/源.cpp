#include <iostream>
#include <vector>
using namespace std;
class solution
{
private:
	static int sign;//��־λ�������������Ƿ��ǵ�һ�����֣���������Ҫ�������
	int size;//������ʾvector����Ĵ�С,Ҳ�������ֵ�λ��
	int differ_num;//����������λ��ľ���ֵ
public:
	vector<int>buf;//�����洢����
	solution(int  n = 0, int k = 0) :size(n), differ_num(k){};//���캯��
	void function(int num,int num_count);//n��������λ�ϵĴ�С��num_countΪ��¼���ֵ�λ��
	void display();//��������е�Ԫ��
	void main_function();//kΪ������λ��ֵ�ľ���ֵ
	~solution() {};//��������
};
int solution::sign = 0;
void solution::function(int num,  int num_count)
{
	if (size ==1)//
	{
		cout << "�����ڷ�������������" << endl;
		exit(0);
	}
	else
	{
		if (num_count == size - 1)//�����������洢����Ҫ��λ��ʱ,�����
		{
			display();
			return;
		}
		//�Ƚ��м������ж�
		if (num -  differ_num>= 0)
		{
			buf.push_back(num - differ_num);//����������Ҫ�������
			function(num - differ_num, num_count + 1);//�ݹ�
			buf.pop_back();//�ݹ���ݣ����鵯�����һλ����
		}
		//�ٽ��мӷ����ж�
		if (num + differ_num<= 9 && differ_num!= 0)//��ֹ�ظ�����Ԫ�أ���k=0����n+k=n-k,��ʱ�����ظ�����
		{
			buf.push_back(num + differ_num);//����������Ҫ�������
			function(num + differ_num,  num_count + 1);//�ݹ�
			buf.pop_back();//�ݹ���ݣ����鵯�����һλ����
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
	for (int i = 1; i <= 9; i++)//���ֿ�ͷ����Ϊ0������ѭ��ֻ��Ҫ�����Ŵ�
	{
		buf.push_back(i);//��������������ӵ�һλ����
		function(i, 0);
		buf.pop_back();//���ʼ���뵽����������Ƴ�
	}
}
int main()
{
	int n, k;//nΪ���ֵ�λ����kΪ������λ�Ĳ�ֵ
	cout << "���������ֵ�λ����������λ�Ĳ�ֵ��" << endl;
	while (1)
	{
		cin >> n >> k;
		//����������жϣ�ֻ����������ݷ���Ҫ��Żᱻ��������
		if (cin.good() != true || k < 0 || k > 9 || n <= 0)
		{
			cout << "�������������,����������:" << endl;
			cin.clear();
			cin.ignore(9999, '\n');
			continue;
		}
		break;
	}
	solution temp(n, k);
	cout << "����������������:" << endl;
	temp.main_function();
}