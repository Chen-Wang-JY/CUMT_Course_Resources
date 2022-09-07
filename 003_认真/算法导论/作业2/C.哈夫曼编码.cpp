/*题目描述
给定一只含有小写字母的字符串；输出其哈夫曼编码的长度
输入
第一行一个整数T，代表样例的个数，接下来T行，每行一个字符串，0<T<=2000,字符串长度0<L<=1500.
输出
对于每个字符串，输出其哈夫曼编码长度
样例输入 Copy
3
hrvsh
lcxeasexdphiopd
mntflolfbtbpplahqolqykrqdnwdoq
样例输出 Copy
10
51
115*/

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct node{
	int value;
	node* left;
	node* right;
	node(int value, node* left=NULL, node* right=NULL){
		this->value = value;
		this->left = left;
		this->right = right;
	}
	friend bool operator > (const node &n1, const node &n2);
};
inline bool operator > (const node &n1, const node &n2) {
    return n1.value > n2.value;
}

void preOrder(node* p){
	if(p != NULL){
		cout<<p->value<<" ";
		preOrder(p->left);
		preOrder(p->right);
		return;
	}
	return;
}


int main()
{	


	int T;
	cin >> T;
	string s;

	while(T--){
		cin >> s;
		unordered_map<char, int> m;
		priority_queue<node, vector<node>, greater<node>> heap;
		for(char ch: s)
			m[ch]++;
		for(auto it = m.begin(); it != m.end(); it++){
			node temp(it->second, NULL, NULL);
			heap.push(temp);
		}
		int ans = 0;
		m.clear();
		while(heap.size() != 1){
			node temp1 = heap.top();
			heap.pop();
			node temp2 = heap.top();
			heap.pop();
			node temp3(temp1.value + temp2.value, &temp1, &temp2); 
			heap.push(temp3);
			ans += temp3.value;
		}
		cout<<ans<<endl;
	
	}
}