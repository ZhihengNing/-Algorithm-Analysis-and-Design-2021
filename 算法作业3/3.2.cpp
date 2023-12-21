#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
template <class type>
int Solution(const vector<vector<type>>& arr) //贪心算法
{
    int size = arr.size();
    if (size == 0)
        return 0;
    type minend = arr[0][1];
    int count = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i][0] >= minend)//如果前一个任务的结束时间小于等于下一个任务的开始时间
        {
            minend = arr[i][1];
            count++;
        }
    }
    return size - count;
}
template <class type>
void sort(vector<vector<type>>& arr) //按照结束时间进行排序
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j][1] > arr[j + 1][1]|| arr[j][1] == arr[j + 1][1] && arr[j][0] > arr[j + 1][0])
            {
                vector<type> temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
template <class type>
void Init(vector<vector<type>>& arr)//初始化
{
    type StartNumber;
    type EndNumber;
    while (1)
    {
        cin >> StartNumber;
        if (StartNumber == -1)
            break;
        cin >> EndNumber;
        if (cin.good() == true && EndNumber >= StartNumber)
        {
            vector<type> temp{ StartNumber, EndNumber };
            arr.push_back(temp);
        }
        else
        {
            cout << "输入数据有误,请重新输入:" << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }
    }
}
int main()
{
    vector<vector<int>> arr;
    cout << "请输入序列(输入-1表示结束)" << endl;
    Init(arr);
    sort(arr);
    cout << Solution(arr);
}