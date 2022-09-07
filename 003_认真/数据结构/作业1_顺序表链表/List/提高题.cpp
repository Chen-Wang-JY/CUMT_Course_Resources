#pragma once
#include<iostream>
#include"List.cpp"
using namespace std;

template<typename T>
void PaiXu(List<T>& list) {
    LinkNode<T>* p = list.getHead()->link;
    while (p != NULL) {
        LinkNode<T>* q = p->link,* min = p;
        while (q != NULL) {
			if (min->data > q->data)
                min = q;
            q = q->link;
        }
        T r = p->data;
        p->data = min->data;
        min->data = r;

        p = p->link;
    }
}

template<typename T>
void GuiBing(List<T>& List_1,List<T>& list_2,List<T>& list){
    LinkNode<T>* p = List_1.getHead()->link;
    LinkNode<T>* q = list_2.getHead()->link;
    LinkNode<T>* r = list.getHead();
	while (p != NULL || q != NULL) {
        if (p != NULL && q != NULL) {
            if (p->data > q->data) {
                r->link = q;
                q = q->link;
                r = r->link;
            }
            else {
                r->link = p;
                p = p->link;
                r = r->link;
            }
        }
        else if (p != NULL && q == NULL) {
            r->link = p;
            break;
        }
        else if (p == NULL && q != NULL) {
            r->link = q;
            break;
        }
    }
}

int main(){
    List<int> list1,list2,list;
    list1.inPut();
    list2.inPut();
    PaiXu(list1);
    PaiXu(list2);
    GuiBing(list1,list2,list);
    list.outPut();
    cout<<endl;
    system("pause");
    return 0;
}