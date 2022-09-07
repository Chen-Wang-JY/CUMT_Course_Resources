#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
//哈夫曼树节点定义
struct HNode
{
	HNode* leftChild;
	HNode* rightChild;
	HNode* parent;
	float data;//字符的权值
	char ch;//字符
	string code;//字符编码
	HNode() { code = ""; }
	HNode(float data, HNode* leftChild = NULL, HNode* rightChild = NULL, HNode* parent = NULL) :
		data(data), leftChild(leftChild), rightChild(rightChild), parent(parent) {
		code = "";
	}
};
struct cmp
{
	bool operator () (const HNode& a, const HNode& b) {
		return a.data >= b.data;
	}
};


//哈夫曼树类定义
class HTree {
public:
	HNode* root;//根结点指针
	HTree(float w[], int n,char ch[]);//构造函数
	void createCode(HNode*& p);//生成编码
	void preOut(HNode* p) {
		if (p != NULL)
		{
			if (p->leftChild == NULL && p->rightChild == NULL)
				cout << p->ch << " " << p->code << endl;
			preOut(p->leftChild);
			preOut(p->rightChild);
		}
	}
};

//构造函数，利用n个权值创建哈夫曼树森林
HTree::HTree(float w[], int n,char ch[]) {

	priority_queue<HNode, vector<HNode>, cmp > heep;//最小堆
	HNode* forest = new HNode[n];//n棵树的森林
	//加权，并插入最小堆中
	for (int i = 0; i < n; i++) {
		forest[i].data = w[i];
		forest[i].leftChild = NULL;
		forest[i].rightChild = NULL;
		forest[i].parent = NULL;
		forest[i].ch = ch[i];
		forest[i].code = "";
		heep.push(forest[i]);
	}
	//建立哈夫曼树
	for (int i = 0; i < n - 1; i++) {
		HNode left = heep.top();
		heep.pop();
		HNode right = heep.top();
		heep.pop();
		//取出两个小权值后合并
		//必须使用new，否则结点会乱套唉
		HNode* pparent = new HNode;
		HNode* lleft = new HNode(left);
		HNode* rright = new HNode(right);
		pparent->leftChild = lleft;
		pparent->rightChild = rright;
		pparent->data = left.data + right.data;
		lleft->parent = pparent;
		rright->parent = pparent;
		pparent->leftChild->code = "0";
		pparent->rightChild->code = "1";
		//合并后的树插入最小堆
		heep.push(*pparent);
		//更新哈夫曼树的根节点（只要最后一趟更新就行）
		root = pparent;
	}
	//将根节点的编码设置为空
	root->code = "";
}

//生成编码，逻辑上应该没问题，但是结果不正确
void HTree::createCode(HNode*& p) {
	if (p != NULL)
	{
		//p不是根节点且是左孩子，则编码加0，否则编码+1
		if (p->parent != NULL && p->parent->leftChild == p) {
			p->code = p->parent->code + "0";
		}
		else if (p->parent != NULL && p->parent->rightChild == p) {
			p->code = p->parent->code + "1";
		}
		createCode(p->leftChild);
		createCode(p->rightChild);
	}
}



int main()
{
	//哈夫曼树生成的没有问题，但是编码的函数有错误
	int n;
	cout << "请输入字符的数量：";
	cin >> n;
	cout << endl << "请输入字符及其对应的频率：" << endl;
	char* p = new char[n];
	float* f = new float[n];
	for (int i = 0; i < n; i++)
		cin >> p[i] >> f[i];
	HTree result(f, n,p);
	//生成编码，根节点不需要编码，从左右子树开始编码
	result.createCode(result.root->leftChild);
	result.createCode(result.root->rightChild);
	//前序输出编码
	result.preOut(result.root);;
	return 0;
}

