#include<iostream>
#include"List.cpp"
using namespace std;

class JosephusCircle {
private:
	int n;//第n个人死
	int m;//m个人围成圈
	int s;//从第s个人开始报数
	List<int> list;
	LinkNode<int>* success;//指向最终留下的那个人
public:
	JosephusCircle(int m, int n, int s) {
		this->m = m;
		this->n = n;
		this->s = s;
		success = NULL;

		//如果s>m，则输入不合法，退出程序。
		//如果三者任一小于等于0，非法输入
		if (s > m||m<=0||s<=0||n<=0) {
			cout << "非法输入!" << endl;
			exit(0);
		}


		//初始化数据，m个人的data域分别标号1-m
		LinkNode<int>* xx = list.getHead();
		for (int j = 0; j < m; j++) {
			xx->data = j + 1;
			LinkNode<int>* yy = new LinkNode<int>;
			xx->link = yy;
			xx = xx->link;
		}

		//找到第m个人，并将其link指向第一个结点，形成循环链表。
		xx = list.getHead();
		for (int j = 1; j <= m-1; j++)
			xx = xx->link;
		xx->link = list.getHead();
		
		
	}
	void Run() {
		//指针p指向开始报数的人，即s。
		LinkNode<int>* p = list.getHead();
		for (int i = 0; i < s-1; i++) {
			p = p->link;
		}
		//指针last指向开始报数人的前一个人。
		LinkNode<int>* last = p;
		for (int j = 0; j < m-1; j++) {
			last = last->link;
		}


		while (p != p->link) {

			//这个循环结束，p指向出局的人，last指向出局的前一个人。
			for (int i = 0; i < n-1; i++) {
				p = p->link;
				last = last->link;
			}

			//将出局的人移出链表
			last->link = p->link;
			LinkNode<int>* del = p;
			p = p->link;
			delete del;
		}
		success = p;
	}

	void output() {
		cout << success->data << endl;
	}
};



int main()
{
	//写程序的时候写乱了，m表示有m个人，报数报到n的人出局，从第s个人开始报数
	int m, n;
	int s;
	cin >> m >> n >> s;
	cout << "测试:m=9，九个人；n=5，报数到五出局；s=1，从第一个人开始报数。" << endl;
	JosephusCircle j(m, n, s);
	j.Run();
	j.output();
	cout << "Success!" << endl << endl;;

	cout << "测试：m=9，九个人；n=0，报数到0出局（非法）；s=1，从第一个人开始报数" << endl;
	cin >> m >> n >> s;
	JosephusCircle o(m, n, s);
	o.Run();
	o.output();
	
	return 0;
}