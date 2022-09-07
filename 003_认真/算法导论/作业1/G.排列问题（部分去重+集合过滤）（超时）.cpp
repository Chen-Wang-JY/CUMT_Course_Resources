/*题目描述
    输入一个可能含有重复字符的字符串，打印出该字符串中所有字符的全排列。
输入
单组测试数据，输入数据是一个长度不超过10个字符的字符串，以逗号结尾。
输出
打印出该字符串中所有字符的全排列。以字典序顺序输出，用空格分隔。
样例输入 Copy
abc,
样例输出 Copy
abc acb bac bca cab cba
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

string s;
set<string> ans;

void Perm(int left, int right){
	if(left == right){
		ans.insert(s);
	}
	else{
		for(int i = left; i <= right; i++){
			if(left != i && s[left] == s[i])
				continue;
			swap(s[left], s[i]);
			Perm(left + 1, right);
			swap(s[left], s[i]);
		}
	}
}

int main()
{	

	getline(cin, s, ',');
	Perm(0, s.size() - 1);
	for(auto it = ans.begin(); it != ans.end(); it++)
		cout<<*it<<endl;
	return 0;
}

