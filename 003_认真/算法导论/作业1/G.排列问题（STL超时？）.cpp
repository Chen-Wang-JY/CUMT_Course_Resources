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
#include <algorithm>

using namespace std;

int main()
{	
	string s;
	getline(cin, s, ',');
	sort(s.begin(), s.end());
	cout<<s<<endl;
	while(next_permutation(s.begin(), s.end())){
		cout<<s<<endl;
	}
	return 0;
}

