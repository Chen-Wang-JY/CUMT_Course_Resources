#include<iostream>
using namespace std;
class CStudent {
    unsigned long reg_num;
    char name[30];
    float math, eng, comp;
public:
    float Sum();
    float Average();
    void Display();
    void SetData();
};
float CStudent::Sum() {
    return math + eng + comp;
}
float CStudent::Average() {
    return Sum() / 3;
}
void CStudent::Display() {
    cout << reg_num << " " << name << " " << math << " " << eng << " " << comp;
}
void CStudent::SetData() {
    cin >> reg_num >> name >> math >> eng >> comp;
}

int main() {
    CStudent stu[150];
    int TOTAL;
    cin >> TOTAL;
    for (int i = 0; i < TOTAL; i++) {

        stu[i].SetData();
    }
    int idx_max = 0;
    cout << "TOTAL=" << TOTAL << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "CStudent " << i + 1 << " : ";
        stu[i].Display(); cout << endl;
    }
    for (int i = 0; i < TOTAL; i++) {
        if (stu[idx_max].Sum() < stu[i].Sum())
            idx_max = i;
        cout << "CStudent" << i + 1 << ".Sum=" << stu[i].Sum();
        cout << "," << "CStudent" << i + 1 << ".average=" << stu[i].Average();
        cout << endl;
    }
    cout << "class_Sum_max=" << stu[idx_max].Sum() << endl;
    cout << "The infomation of the CStudent with class_Sum_max : ";
    stu[idx_max].Display();
    system("pause");
    return 0;

}