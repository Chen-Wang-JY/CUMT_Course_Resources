#include<iostream>
using namespace std;

class Complex{
private:
    double real;
    double imag;
public:
    Complex(){real=0;imag=0;}
    Complex(double r ,double i);
    Complex AddCom(Complex c2);
    void OutCom();
};

Complex::Complex(double r,double i){
    real=r;
    imag=i;
}
Complex Complex::AddCom(Complex c2){
    this->real+=c2.real;
    this->imag+=c2.imag;
    return *this;
}
void Complex::OutCom(){
    if(real!=0&&imag!=0)
        cout<<real<<"+"<<imag<<"i";
    else if(real==0&&imag!=0)
        cout<<imag<<"i";
    else if(real!=0&&imag==0)
        cout<<real;
}

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    Complex cx(a,b),cy(c,d);
    cx.AddCom(cy);
    cx.OutCom();
    return 0;
}