/*
 * @Author: your name
 * @Date: 2021-11-04 19:48:34
 * @LastEditTime: 2021-11-19 14:45:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++ projects\compile\递归下降预测\yf2.0.cpp
 */
#include <iostream>
#include <vector>
#include <string>
#include "cf2.0.cpp"
using namespace std;

class GrammarParser{
private:
    vector<lexicalUnit> _lexicalUnitArray;
    int _unitPointer;
    bool _flagError;

    /**
     * description: program ==> ?
     * param {*}
     * return {*}
     */    
    void _program();

    /**
     * description: block ==> ?
     * param {*}
     * return {*}
     */  
    void _block();

    /**
     * description: stmts ==> ?
     * param {*}
     * return {*}
     */  
    void _stmts();

    /**
     * description: stmt ==> ?
     * param {*}
     * return {*}
     */  
    void _stmt();

    /**
     * description: bool ==> ?
     * param {*}
     * return {*}
     */  
    void _bool();

    /**
     * description: expr ==> ?
     * param {*}
     * return {*}
     */  
    void _expr();

    /**
     * description: expr1 ==> ?
     * param {*}
     * return {*}
     */  
    void _expr1();

    /**
     * description: term ==> ?
     * param {*}
     * return {*}
     */  
    void _term();

    /**
     * description: term1 ==> ?
     * param {*}
     * return {*}
     */  
    void _term1();

    /**
     * description: factor ==> ?
     * param {*}
     * return {*}
     */  
    void _factor();

    /**
     * description: 出错处理函数
     * param {*}
     * return {*}
     */    
    void _error();
    
    /**
     * description: 判断读头是否与s匹配，匹配则移动读头，否则报错
     * param {string} s：待匹配的串
     * return {*}
     */    
    void _match(string s);
    
public:
    /**
     * description: 构造函数
     * param {*}
     * return {*}
     */    
    GrammarParser();

    /**
     * description: 开始语法分析
     * param {*}
     * return {*}
     */    
    void start();

    /**
     * description: 得到词法分析结果
     * param {vector<lexicalUnit>&} arry: 词法分析三元组集合
     * return {*}
     */    
    void getLexicalUnitArray(vector<lexicalUnit> arry);
    
};

int main(){
    DFA DFAobj;
    DFAobj.getProgram("123.txt");
    DFAobj.start();
    cout << endl << "词法分析结束!" << endl;
    GrammarParser obj;
    obj.getLexicalUnitArray(DFAobj.getAnswer());
    obj.start();
    return 0;
}

/**
 * description: 构造函数
 * param {*}
 * return {*}
 */    
GrammarParser::GrammarParser(){
    _unitPointer = 0;
    _flagError = false;
}

/**
 * description: 开始语法分析
 * param {*}
 * return {*}
 */    
void GrammarParser::start(){
    cout << "语法分析开始：" << endl;
    _program();
}

/**
 * description: program ==> ?
 * param {*}
 * return {*}
 */    
void GrammarParser::_program(){
    cout << "       program ==> block" << endl;
    _block();
    if(_flagError){
        _error();
        return;
    }
    cout << "合法语句！" << endl;
}

/**
 * description: block ==> ?
 * param {*}
 * return {*}
 */  
void GrammarParser::_block(){
    if(_flagError)
        return;

    cout << "       block ==> {stmts}" << endl;
    _match("{");
    _stmts();
    _match("}");
}

/**
 * description: stmts ==> ?
 * param {*}
 * return {*}
 */  
void GrammarParser::_stmts(){
    if(_flagError)
        return;
    
    //右括号
    if(_lexicalUnitArray[_unitPointer].token == "}"){
        cout << "       stmts ==> null" << endl;
    }
    else{
        cout << "       stmts ==> stmt stmts" << endl;
        _stmt();
        _stmts();
    }
}

/**
 * description: stmt ==> ?
 * param {*}
 * return {*}
 */  
void GrammarParser::_stmt(){
    if(_flagError)
        return;
    //变量名 id
    if(_lexicalUnitArray[_unitPointer].state == VARIABLE_NAME){
        cout << "       stmt ==> id = expr;" << endl;
        _match(_lexicalUnitArray[_unitPointer].token);  //match("id")
        _match("=");
        _expr();
        _match(";");
    }
    //保留字 if
    else if(_lexicalUnitArray[_unitPointer].state == IF){
        _match("if");  //if
        _match("(");
        _bool();
        _match(")");
        _stmt();
        if(_lexicalUnitArray[_unitPointer].state == ELSE){
            cout << "       stmt ==> if(bool) stmt else stmt" << endl;
            _match("else");
            _stmt();
        }
        else{
            cout << "       stmt ==> if(bool) stmt null" << endl;
        }
    }
    //while
    else if(_lexicalUnitArray[_unitPointer].state == WHILE){
        cout << "       stmt ==> while(bool) stmt" << endl;
        _match("while");
        _match("(");
        _bool();
        _match(")");
        _stmt();
    }
    //do
    else if(_lexicalUnitArray[_unitPointer].state == DO){
        cout << "       stmt ==> do stmt while(bool)" << endl;
        _match("do");
        _stmt();
        _match("while");
        _match("(");
        _bool();
        _match(")");
    }
    //break
    else if(_lexicalUnitArray[_unitPointer].state == BREAK){
        cout << "       stmt ==> break" << endl;
        _match("break");
    }
    //block
    else{
        cout << "       stmt ==> block" << endl;
        _block();
    }
}

/**
 * description: bool ==> ?
 * param {*}
 * return {*}
 */  
void GrammarParser::_bool(){
    if(_flagError)
        return;
    _expr();
    // <
    if(_lexicalUnitArray[_unitPointer].state == SMALLER){
        cout << "       bool ==> expr < expr" << endl;
        _match("<");
        _expr();
    }
    else if(_lexicalUnitArray[_unitPointer].state == LESS_EQUAL){
        cout << "       bool ==> expr <= expr" << endl;
        _match("<=");
        _expr();
    }
    else if(_lexicalUnitArray[_unitPointer].state == BIGGER){
        cout << "       bool ==> expr > expr" << endl;
        _match(">");
        _expr();
    }
    else if(_lexicalUnitArray[_unitPointer].state == GREATER_EQUAL){
        cout << "       bool ==> expr >= expr" << endl;
        _match(">=");
        _expr();
    }
    else{
        _flagError = true;
    }
}

/**
 * description: expr ==> ?
 * param {*}
 * return {*}
 */  
void GrammarParser::_expr(){
    if(_flagError)
        return;
    cout << "       expr ==> term expr1" << endl;
    _term();
    _expr1();
}

/**
 * description: expr1 ==> ?
 * param {*}
 * return {*}
 */  
void GrammarParser::_expr1(){
    if(_flagError)
        return;
    if(_lexicalUnitArray[_unitPointer].state == PLUS){
        cout << "       expr1 ==> + term expr1" << endl;
        _match("+");
        _term();
        _expr1();
    }
    else if(_lexicalUnitArray[_unitPointer].state == SUBTRACT){
        cout << "expr1 ==> - term expr1" << endl;
        _match("-");
        _term();
        _expr1();
    }
    else{
        cout << "       expr1 ==> null" << endl;
    }
}

/**
 * description: term ==> ?
 * param {*}
 * return {*}
 */  
void GrammarParser::_term(){
    if(_flagError)
        return;
    cout << "       term ==> factor term1" << endl;
    _factor();
    _term1();
}

/**
 * description: term1 ==> ?
 * param {*}
 * return {*}
 */  
void GrammarParser::_term1(){
    if(_flagError)
        return;
    if(_lexicalUnitArray[_unitPointer].state == MULTIPLY){
        cout << "       term1 ==> * factor term1" << endl;
        _match("*");
        _factor();
        _term1();
    }
    else if(_lexicalUnitArray[_unitPointer].state == DIVISION){
        cout << "       term1 ==> / factor term1" << endl;
        _match("/");
        _factor();
        _term1();
    }
    else{
        cout << "       term1 ==> null" << endl;
    }
}

/**
 * description: factor ==> ?
 * param {*}
 * return {*}
 */  
void GrammarParser::_factor(){
    if(_flagError)
        return;
    if(_lexicalUnitArray[_unitPointer].state == LEFT){
        cout << "       factor ==> (expr)" << endl;
        _match("(");
        _expr();
        _match(")");
    }
    else if(_lexicalUnitArray[_unitPointer].state == VARIABLE_NAME){
        cout << "       factor ==> id" << endl;
        _match(_lexicalUnitArray[_unitPointer].token);
    }
    else if(_lexicalUnitArray[_unitPointer].state == DIGIT){
        cout << "       factor ==> num" << endl;
        _match(_lexicalUnitArray[_unitPointer].token);
    }
    else{
        _flagError = true;
    }
}

/**
 * description: 出错处理函数
 * param {*}
 * return {*}
 */    
void GrammarParser::_error(){
    _flagError = true;
    cout << "出现错误！中止分析！" << endl;
}

/**
 * description: 判断读头是否与s匹配，匹配则移动读头，否则报错
 * param {string} s：待匹配的串
 * return {*}
 */    
void GrammarParser::_match(string s){
    //与读头不匹配，报错
    if(_lexicalUnitArray[_unitPointer].token != s){
        _flagError = true;
        return;
    }
    //匹配，则读头后移
    _unitPointer++;
}

/**
 * description: 得到词法分析结果
 * param {vector<lexicalUnit>&} arry: 词法分析三元组集合
 * return {*}
 */    
void GrammarParser::getLexicalUnitArray(vector<lexicalUnit> arry){
    this->_lexicalUnitArray = arry;
}