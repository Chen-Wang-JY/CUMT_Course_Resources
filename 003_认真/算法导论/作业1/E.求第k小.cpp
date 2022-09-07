/*题目描述
给定n(1<=n<=1000000)个元素，求第k小数(1<=k<=n)。

输入
一组样例。第一行输入两个整数n和k。第二行输入n个不同的int范围内的数。

输出
输出一行，输出第k小数。

样例输入 Copy
5 2
1 5 3 2 4

样例输出 Copy
2
*/
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> nums;

int getPartition(int start, int end) {
    int left = start;
    int right = end;
    int temp = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= temp) right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= temp) left++;
        nums[right] = nums[left];
    }
    nums[left] = temp;
    return left;
}
int select(int left, int right, int k){
	if(left == right){
		return nums[left];
	}
	int mid = getPartition(left, right);
	int leftLength = mid - left + 1;
	if(k <= leftLength)
		return select(left, mid, k);
	else
		return select(mid + 1, right, k - leftLength);
}

int main()
{
	cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		nums.push_back(x);
	}
	cout<<select(0, nums.size() - 1, k)<<endl;
	return 0;
}