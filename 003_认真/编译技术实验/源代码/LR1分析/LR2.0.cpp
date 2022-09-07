/*
 * @Author: Chen
 * @Date: 2021-11-19 15:07:48
 * @LastEditTime: 2021-11-19 15:15:46
 * @FilePath: \C++ projects\compile\LR1分析\LR2.0.cpp
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

typedef pair<char, int> production;

class LR1{
private:
    //LR分析表
    map<int, map<char, string>> _talbeLR;
    //产生式与其长度表
    map<int, production> _tableProduction;
    vector<int> _stateStack;
    vector<char> _symbolStack;
    string _sentence;
    int _pointer;
    string _IP;
    int _step;

    /**
     * description: 根据状态栈栈顶与读头内容，确定LR分析器的下一步_IP
     * param {*}
     * return {*} 
     */
    void _analyze();

    /**
     * description: 根据IP值，执行对应动作
     * param {*}
     * return {int}：返回动作执行后是否分析完成等状态
     */    
    int _update();

    /**
     * description: 打印当前分析步骤
     * param {*}
     * return {*}
     */
    void print();
    
public:
    /**
     * description: 构造函数，初始化LR分析表等
     * param {string} s：待分析句子
     * return {*}
     */
    LR1(string s);
    
    /**
     * description: LR分析开始
     * param {*}
     * return {*}
     */    
    void start();
};

int main()
{
    string s;
    cin >> s;
    LR1 obj(s);
    obj.start();
    
    return 0;
}

/**
 * description: 构造函数，初始化LR分析表等
 * param {string} s：待分析句子
 * return {*}
 */
LR1::LR1(string s){
    _talbeLR[0] = {{'+', "error"}, {'-', "error"}, {'*', "error"}, {'/', "error"}, {'(', "S4"}, {')', "error"}, {'i', "S5"}, {'#', "error"}, {'E', "1"}, {'T', "2"}, {'F', "3"}};
    _talbeLR[1] = {{'+', "S6"}, {'-', "S6"}, {'*', "error"}, {'/', "error"}, {'(', "error"}, {')', "error"}, {'i', "error"}, {'#', "acc"}, {'E', "error"}, {'T', "error"}, {'F', "error"}};
    _talbeLR[2] = {{'+', "R2"}, {'-', "R2"}, {'*', "S7"}, {'/', "S7"}, {'(', "error"}, {')', "R2"}, {'i', "error"}, {'#', "R2"}, {'E', "error"}, {'T', "error"}, {'F', "error"}};
    _talbeLR[3] = {{'+', "R4"}, {'-', "R4"}, {'*', "R4"}, {'/', "R4"}, {'(', "error"}, {')', "R4"}, {'i', "error"}, {'#', "R4"}, {'E', "error"}, {'T', "error"}, {'F', "error"}};
    _talbeLR[4] = {{'+', "error"}, {'-', "error"}, {'*', "error"}, {'/', "error"}, {'(', "S4"}, {')', "error"}, {'i', "S5"}, {'#', "error"}, {'E', "8"}, {'T', "2"}, {'F', "3"}};
    _talbeLR[5] = {{'+', "R6"}, {'-', "R6"}, {'*', "R6"}, {'/', "R6"}, {'(', "error"}, {')', "R6"}, {'i', "error"}, {'#', "R6"}, {'E', "error"}, {'T', "error"}, {'F', "error"}};
    _talbeLR[6] = {{'+', "error"}, {'-', "error"}, {'*', "error"}, {'/', "error"}, {'(', "S4"}, {')', "error"}, {'i', "S5"}, {'#', "error"}, {'E', "error"}, {'T', "9"}, {'F', "3"}};
    _talbeLR[7] = {{'+', "error"}, {'-', "error"}, {'*', "error"}, {'/', "error"}, {'(', "S4"}, {')', "error"}, {'i', "S5"}, {'#', "error"}, {'E', "error"}, {'T', "error"}, {'F', "10"}};
    _talbeLR[8] = {{'+', "S6"}, {'-', "S6"}, {'*', "error"}, {'/', "error"}, {'(', "error"}, {')', "S11"}, {'i', "error"}, {'#', "error"}, {'E', "error"}, {'T', "error"}, {'F', "error"}};
    _talbeLR[9] = {{'+', "R1"}, {'-', "R1"}, {'*', "S7"}, {'/', "S7"}, {'(', "error"}, {')', "R1"}, {'i', "error"}, {'#', "R1"}, {'E', "error"}, {'T', "error"}, {'F', "error"}};
    _talbeLR[10] = {{'+', "R3"}, {'-', "R3"}, {'*', "R3"}, {'/', "R3"}, {'(', "error"}, {')', "R3"}, {'i', "error"}, {'#', "R3"}, {'E', "error"}, {'T', "error"}, {'F', "error"}};
    _talbeLR[11] = {{'+', "R5"}, {'-', "R5"}, {'*', "R5"}, {'/', "R5"}, {'(', "error"}, {')', "R5"}, {'i', "error"}, {'#', "R5"}, {'E', "error"}, {'T', "error"}, {'F', "error"}};

    _tableProduction[1] = production('E', 3);
    _tableProduction[2] = production('E', 1);
    _tableProduction[3] = production('T', 3);
    _tableProduction[4] = production('T', 1);
    _tableProduction[5] = production('F', 3);
    _tableProduction[6] = production('F', 1);

    _sentence = s;
    _sentence.push_back('#');
    _pointer = 0;
    _step = 1;
}

/**
 * description: LR分析开始
 * param {*}
 * return {*}
 */    
void LR1::start(){
    cout << "步骤\t\t\t" << "状态栈\t\t\t" << "符号栈\t\t\t" << "待分析语句" << endl;
    //初始状态入栈
    _stateStack.push_back(0);
    //根据读头与状态栈栈顶判断下一步的操作
    while(true){
        print();
        _analyze();
        int flag = _update();
        if(flag == 0){
            _step++;
            continue;
        }
        else if(flag == 1){
            cout << "语法分析成功!" << endl;
            break;
        }
        else{
            cout << "error" << endl;
            break;
        }
    }
}

void LR1::_analyze(){
    int currentState = _stateStack.back();
    char pointerContent = _sentence[_pointer];
    _IP = _talbeLR[currentState][pointerContent];
}

/**
 * description: 根据IP值，执行对应动作
 * param {*}
 * return {int}：返回动作执行后是否分析完成等状态
 */   
int LR1::_update(){
    int flag = 0;
    //移进
    if(_IP[0] == 'S'){
        _symbolStack.push_back(_sentence[_pointer++]);
        _stateStack.push_back(stoi(_IP.substr(1)));
    }
    //规约
    else if(_IP[0] == 'R'){
        int indexOfProduction = stoi(_IP.substr(1));
        int reduceCount = _tableProduction[indexOfProduction].second;
        char reduceSym = _tableProduction[indexOfProduction].first;
        while(reduceCount--){
            _stateStack.pop_back();
            _symbolStack.pop_back();
        }
        _symbolStack.push_back(reduceSym);
        //规约后根据符号栈与状态栈栈顶元素，将新的状态入栈  
        int reduceState = stoi(_talbeLR[_stateStack.back()][_symbolStack.back()]);
        _stateStack.push_back(reduceState);
    }
    else if(_IP == "acc"){
        flag = 1;
    }
    else{
        flag = -1;
    }
    return flag;
}

/**
 * description: 打印当前分析步骤
 * param {*}
 * return {*}
 */
void LR1::print(){
    cout << "  " << _step << "\t\t\t";
    for(auto it = _stateStack.begin(); it != _stateStack.end(); it++)
        cout << *it;
    cout << "\t\t\t";
    for(auto it = _symbolStack.begin(); it != _symbolStack.end(); it++)
        cout << *it;
    cout << "\t\t\t";
    for(int i = _pointer; i < _sentence.size(); i++)
        cout << _sentence[i];
    cout << endl;
}