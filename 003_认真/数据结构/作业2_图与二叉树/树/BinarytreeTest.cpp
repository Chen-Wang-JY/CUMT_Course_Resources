#include "Binarytree.cpp"
int main()
{
    Binarytree<int> obj(0);//创建二叉树，0作为创建二叉树结束结点的标志
    //前序创建二叉树，测试序列为:  1 2 0 3 0 0 4 5 0 7 0 0 6 0 0
    cout << "开始创建，请输入序列："; obj.preCreate();
    cout << "二叉树建立完成！" << endl;;
    cout << "前序遍历二叉树，理论应为：1 2 3 4 5 6 7，实际得到："; obj.preOut(); cout << endl;
	cout << "中序遍历二叉树，理论应为：2 3 1 5 7 4 6，实际得到: "; obj.inOut(); cout << endl;
    cout << "后序遍历二叉树，理论应为：3 2 7 5 6 4 1，实际得到："; obj.postOut(); cout << endl;
    cout << "层次遍历二叉树，理论应为：1 2 4 3 5 6 7， 实际得到："; obj.levelOrder(); cout << endl << endl;
    
    cout << "当前二叉树的节点数和叶子节点数分别为：" << obj.NodeNum() << " " << obj.LeafNodeNum() << endl << endl;

    cout << "找到值为5的结点，并输出该节点的值以及其右孩子的值：";
    BinTreeNode<int>* p = obj.findData(5);
    cout << p->data << " " << p->rightChild->data << endl;
    cout << "该节点的父节点的值以及其父节点的左孩子的值：";
    p = obj.findParents(p);
    cout << p->data << " " << p->leftChild->data << endl << endl;
    cout << "测试结束" << endl;
    return 0;;
}

