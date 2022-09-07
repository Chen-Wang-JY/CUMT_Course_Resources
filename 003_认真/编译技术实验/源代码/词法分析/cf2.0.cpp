#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define NUM_OF_RESERVEDWORD 21


enum DFASTATE{
    START,                  //0

    //变量
    BEFORE_VARIABLE_NAME,     
    VARIABLE_NAME,

    //保留字   
    IF,                    
    ELSE,                
    CINT,
    CDOUBLE,      
    CFLOAT,
    CBOOL,
    WHILE,
    INCLUDE,
    USING,
    NAMESPACE,
    STD,     
    IOSTREAM,
    RETURN,
    CIN,
    COUT,
    ENDL,
    CSTRING,
    STATIC,
    DO,
    BREAK,
    VECTOR,

    //数字
         
    DIGIT,
    //字符串  
    STRINGVAL,             
    //符号
    PLUS,                   // +
    SUBTRACT,               // -
    MULTIPLY,               // *
    DIVISION,               // /
    EQUAL,                  // =
    SMALLER,                // <
    BIGGER,                 // >
    SEMICOLON,              // ;
    LEFT,                   // (
    RIGHT,                  // )
    LEFTBRACE,              // {
    RIGHTBRACE,             // }
    HASHTAG,                // #
    LEFTSTREAM,             // <<
    RIGHTSTREAM,            // >>
    LESS_EQUAL,             // <=
    GREATER_EQUAL,          // >=
    MOD,                    // %

    //非法状态
    BEFORE_STRINGVAL = -1,   //字符串缺少右引号
    UNKNOWN_SYMBOL = -2,     //未知的符号
    BEFORE_DIGIT = -3,       //数字错误
    ILLEGAL = -5,            //未知错误

};

struct lexicalUnit{
    int row;
    DFASTATE state;
    string token;
    lexicalUnit(int row, DFASTATE state, string token){
        this->row = row;
        this->state = state;
        this->token = token;
    }
};

class DFA{
private:
    //待分析程序
    string _program;
    //程序指针
    int _programPoint;
    //保留字集合
    string* _reservedWord;
    //单词
    string _token;           
    //当前分析的行数
    int _row;   
    bool _nextRow;
    //全部词法分析单元
    vector<lexicalUnit> _lexicalUnitArray;

    /**
     * description: 移动程序指针，分析下一个单词，得到token以及类别num
     * param {*}
     * return {DFASTATE} token的类别sym
     */    
    DFASTATE _getToken();

    /**
     * description: 识别字母
     * param {char} ch:当前已读入字符
     * return {DFASTATE} token的类别sym
     */       
    DFASTATE _letterRecognition(char ch);

    /**
     * description: 识别数字
     * param {char} ch:当前已读入字符
     * return {DFASTATE} token的类别sym
     */    
    DFASTATE _digitRecognition(char ch);

    /**
     * description: 识别字符串
     * param {char} ch：当前读入字符串
     * return {DFASTATE} token的类别sym
     */    
    DFASTATE _stringRecognition(char ch);

    /**
     * description: 根据非法状态，输出错误类型
     * param {DFASTATE} sym：当前的非法状态
     * return {*}
     */    
    void errorHandling(DFASTATE sym);

    
public:
    /**
     * description: 构造函数，初始化保留字等
     * param {*}
     * return {*}
     */
    DFA();

    /**
     * description: 读取待分析程序
     * param {string} path: 程序文件的路径
     * return {*}
     */    
    void getProgram(string path);
    
    /**
     * description: 开始词法分析
     * param {*}
     * return {*}
     */    
    void start();

    /**
     * description: 返回词法分析的全部三元组，用于语法分析
     * param {*}
     * return {vector<lexicalUnit>} 词法分析全部三元组
     */    
    vector<lexicalUnit> getAnswer();
};

int main()
{
    DFA* a = new DFA();
    a->getProgram("./sourceCode.txt");
    a->start();
    return 0;
}

/**
 * description: 构造函数，初始化保留字等
 * param {*}
 * return {*}
 */
DFA::DFA(){
    _reservedWord = new string[NUM_OF_RESERVEDWORD] 
    {"if", "else", "int", "double",
    "float", "bool", "while", "include", "using", "namespace", "std", "iostream", "return",
    "cin", "cout", "endl", "string", "static", "do", "break", "vector"};
    _programPoint = 0;
    _token = "";
    _row = 1;
    _nextRow = false;
}

/**
 * description: 读取待分析程序
 * param {string} path: 程序文件的路径
 * return {*}
 */
void DFA::getProgram(string path){
    fstream fp(path, ios::in);
    if(!fp.is_open()){
        cout << "文件打开失败！" << endl;
        return;
    }
    while(!fp.eof()){
        _program.push_back(fp.get());
    }
    fp.close();
}

/**
 * description: 移动程序指针，分析下一个单词，得到token以及类别num
 * param {*}
 * return {DFASTATE} token的类别num
 */  
DFASTATE DFA::_getToken(){
    DFASTATE sym;
    _token.clear();
    _nextRow = false;

    char ch = _program[_programPoint++];
    while(ch == ' ' || ch == '\n' || ch == '\t' || (ch == '/' && _program[_programPoint] == '/')){
        if(ch == '\n'){
            _row++;
            _nextRow = true;
        }
        //如果是注释
        if(ch == '/'){
            while(ch != '\n') ch = _program[_programPoint++];
            _row++;
            _nextRow = true;
        }
        ch = _program[_programPoint++];
    }
    
    //字母
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        sym = _letterRecognition(ch);
    }
    //数字
    else if(ch >= '0' && ch <= '9' || ch == '.'){
        sym = _digitRecognition(ch);
    }
    //字符串
    else if(ch == '"'){
        ch = _program[_programPoint++];
        sym = _stringRecognition(ch);
    }
    //其他
    else{
        switch (ch)
        {
        case '+': sym = PLUS;        _token.push_back(ch); break;
        case '-': sym = SUBTRACT;    _token.push_back(ch); break;
        case '*': sym = MULTIPLY;    _token.push_back(ch); break;
        case '/': sym = DIVISION;    _token.push_back(ch); break;
        case '=': sym = EQUAL;       _token.push_back(ch); break;
        case ';': sym = SEMICOLON;   _token.push_back(ch); break;
        case '(': sym = LEFT;        _token.push_back(ch); break;
        case ')': sym = RIGHT;       _token.push_back(ch); break;
        case '{': sym = LEFTBRACE;   _token.push_back(ch); break;
        case '}': sym = RIGHTBRACE;  _token.push_back(ch); break;
        case '#': sym = HASHTAG;     _token.push_back(ch); break;
        case '%': sym = MOD;         _token.push_back(ch); break;
        case '<':  
                    sym = SMALLER;    
                    _token.push_back(ch); 
                    ch = _program[_programPoint++];
                    if(ch == '<'){
                        _token.push_back(ch);
                        sym = LEFTSTREAM;
                    }
                    else if(ch == '='){
                        _token.push_back(ch);
                        sym = LESS_EQUAL;
                    }
                    else
                        _programPoint--;
                    break;
        case '>': 
                    sym = BIGGER;      
                    _token.push_back(ch); 
                    ch = _program[_programPoint++];
                    if(ch == '>'){
                        _token.push_back(ch);
                        sym = RIGHTSTREAM;
                    }
                    else if(ch == '='){
                        _token.push_back(ch);
                        sym = GREATER_EQUAL;
                    }
                    else
                        _programPoint--;
                    break;
        default:
            sym = UNKNOWN_SYMBOL;
            break;
        }
    }

    return sym;
}

/**
 * description: 开始词法分析
 * param {*}
 * return {*}
 */    
void DFA::start(){
    cout << "行 " << _row << "\t";
    while(_programPoint < _program.size() - 1){
        DFASTATE sym = _getToken();
        //cout << sym << endl;
        //出错
        if(sym < 0){
            cout << endl << "错误！错误位于第[" << _row << "]行。";
            errorHandling(sym);
            break;
        }
        else{
            if(_nextRow){
                cout << endl << "行 " << _row << "\t";
            }
            cout << "[" << sym << ", " << _token << "]" << '\t';
            _lexicalUnitArray.push_back(lexicalUnit(_row, sym, _token));
        }
    }
    //cout << "--------------------------------" << endl;
    //for(auto unit: _lexicalUnitArry)
    //    cout << unit.row << " " << unit.state << " " << unit.token << endl;
}

/**
 * description: 识别字母
 * param {*}
 * return {DFASTATE} token的类别sym
 */    
DFASTATE DFA::_letterRecognition(char ch){
    DFASTATE sym = BEFORE_VARIABLE_NAME;
    while((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        _token.push_back(ch);
        ch = _program[_programPoint++];
    }
    sym = VARIABLE_NAME;
    for(int i = 0; i < NUM_OF_RESERVEDWORD; i++){
        if(_token == _reservedWord[i]){
            sym = DFASTATE(i + 3);
            break;
        }
    }
    _programPoint--;
    return sym;
}

/**
 * description: 识别数字
 * param {char} ch:当前已读入字符
 * return {DFASTATE} token的类别sym
 */    
DFASTATE DFA::_digitRecognition(char ch){
    DFASTATE sym = BEFORE_DIGIT;
    bool flag = false;
    while(ch >= '0' && ch <= '9' || ch == '.'){
        if(!flag && ch == '.')
            flag = true;
        else if(ch == '.' && flag){
            return sym;
        }
        _token.push_back(ch);
        ch = _program[_programPoint++];
    }
    sym = DIGIT;
    _programPoint--;

    return sym;
}

/**
 * description: 识别字符串
 * param {char} ch：当前读入字符串
 * return {DFASTATE} token的类别sym
 */    
DFASTATE DFA::_stringRecognition(char ch){
    _token.push_back('"');
    DFASTATE sym = BEFORE_STRINGVAL;
    //(ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')
    while(ch != '"' && ch != '\n'){
        _token.push_back(ch);
        ch = _program[_programPoint++];
    }
    if(ch == '"'){
        sym = STRINGVAL;
        _token.push_back('"');
    }
    //else
    //    sym = ILLEGAL;
    return sym;
}

/**
 * description: 返回词法分析的全部三元组，用于语法分析
 * param {*}
 * return {vector<lexicalUnit>} 词法分析全部三元组
 */    
vector<lexicalUnit> DFA::getAnswer(){
    return _lexicalUnitArray;
}

/**
 * description: 根据非法状态，输出错误类型
 * param {DFASTATE} sym：当前的非法状态
 * return {*}
 */    
void DFA::errorHandling(DFASTATE sym){
    switch (sym)
    {
    case BEFORE_STRINGVAL:
        cout << "字符串变量缺少 \"" << endl;
        break;
    case UNKNOWN_SYMBOL:
        cout << "未知的符号" << endl;
        break;
    case BEFORE_DIGIT:
        cout << "数字格式错误" << endl;
        break;
    default:
        cout << "未知错误！" << endl;
        break;
    }
}