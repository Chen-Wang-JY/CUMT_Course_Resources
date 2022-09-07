/*题目描述
密码学是研究编制密码和破译密码的技术科学。研究密码变化的客观规律，应用于编制密码以保守通信秘密的，称为编码学；应用于破译密码以获取通信情报的，称为破译学，总称密码学。密码是通信双方按约定的法则进行信息特殊变换的一种重要保密手段。依照这些法则，变明文为密文，称为加密变换；变密文为明文，称为脱密变换。密码在早期仅对文字或数码进行加、脱密变换，随着通信技术的发展，对语音、图像、数据等都可实施加、脱密变换。
现在要求你用下面给定的方法对数据实现加密。给定长度为n的字符串S（1<=n<=2000,S中只有大写字母）作为明文，要求构造一个字符串T作为密文，起初T是一个空串，之后反复执行以下任意操作
1.从S的头部删除一个字符，加入到T的尾部
2.从S的尾部删除一个字符，加入到T的尾部
最后S会变成空串，T会变成一个长度为n的字符串作为密文。当然并非所有的构造方案都是符合条件的，我们要求构造出的密文T的字典序尽可能小，你能找出这个字典序最小的密文吗？
输入
输入包含多组数据，每组数据占两行，第一行为一个整数n（1<=n<=2000）代表字符串S的长度，第二行为一个长度为n的字符串S代表明文，保证S中只有大写字母
输出
对每组数据，输出一行字符串，代表构造出的字典序最小的密文T
样例输入 Copy
6
ACDBCB
样例输出 Copy
ABCBCD
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string S;
string T;
int main()
{
	int n;
	while(cin >> n >> S){
		while(!S.empty()){
			int index = 0;
			for(auto left = S.begin(), right = S.end() - 1; left < right; left++, right--){
				if(*left < *right){
					index = 0;
					break;
				}
				else if(*left > *right){
					index = S.size() - 1;
					break;
				}
			}
			T.push_back(S[index]);
			S.erase(S.begin() + index);
		}
		cout << T << endl;
		T.clear();
	}
	return 0;
}

