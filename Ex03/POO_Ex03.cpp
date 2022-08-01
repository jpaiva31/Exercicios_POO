/*professor, nao sei se entendi certo o que deveria ser feito no método resolver.
Pelo que entendi, era para pritar na tela a equação, por isso fiz assim apesar
da saída dos programas estarem diferentes.
*/
#include <iostream>
#include <math.h>

using namespace std;

class equacoes
{
public:
    virtual void resolver()=0;
};

class Eq1Grau: public equacoes
{
    int x,y;
    float resp;
public:


    void resolver()
    {
        resp=float(x)/float((-y));
        cout<<resp<<endl;
    }
    Eq1Grau(int a,int b):equacoes()
    {
        x=a;
        y=b;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};

Eq1Grau operator+( Eq1Grau& a,Eq1Grau& b)
{

    Eq1Grau aux(b.getX()+a.getX(),b.getY()+a.getY());
    return aux;
}
Eq1Grau operator-( Eq1Grau& a,Eq1Grau& b)
{

    Eq1Grau aux(b.getX()-a.getX(),b.getY()-a.getY());
    return aux;
}



class Eq2Grau: public equacoes
{
public:
    int x,y,z,raiz1,raiz2;

    void resolver()
    {
        float delta=pow(y,0.5)-4*x*z;
        if(delta>0)
        {
            raiz1=(-y+pow(int(delta),0.5))/2*x;
            raiz2=(-y-pow(int(delta),0.5))/2*x;
            cout<<"raiz1: "<<raiz1<<" raiz 2: "<<raiz2<<endl;
        }
    }
    Eq2Grau(int a,int b, int c):equacoes()
    {
        x=a;
        y=b;
        z=c;
    }

};

Eq2Grau operator+( Eq2Grau& a,Eq2Grau& b)
{

    Eq2Grau aux(b.x+a.x,b.y+a.y,a.z+b.z);
    return aux;
}

Eq2Grau operator-( Eq2Grau& a,Eq2Grau& b)
{

    Eq2Grau aux(b.x-a.x,b.y-a.y,a.z-b.z);
    return aux;
}

ostream &operator<<(ostream &stream, Eq1Grau a)
{
    if(a.getY()>0) stream<<a.getX()<<"*x + "<<a.getY()<<" =0"<<endl;
    else stream<<a.getX()<<"*x "<<a.getY()<<" =0"<<endl;
    return stream;
}
ostream &operator<<(ostream &stream, Eq2Grau a)
{

    if(a.z>0)
    {
        if(a.y>0)
            stream<<a.x<<"*x^2 + "<<a.y<<"*x + "<<a.z<<" =0"<<endl;
        else   stream<<a.x<<"*x^2 + "<<a.y<<"*x "<<a.z<<" =0"<<endl;
    }
    else
    {
        if(a.y>0)
            stream<<a.x<<"*x^2+"<<a.y<<"*x "<<a.z<<" =0"<<endl;
        else  stream<<a.x<<"*x^2 "<<a.y<<"*x "<<a.z<<" =0"<<endl;
    }
    return stream;
}


int main ()
{
    Eq1Grau eq1(2, 3); //2*x + 3 = 0
    cout << "Eq1: " << eq1 << endl;
    eq1.resolver();
    Eq2Grau eq2(1, 1, -6); // 1*x^2 + 1*x – 6 = 0
    cout << "Eq2: " << eq2 << endl;
    eq2.resolver();
    Eq2Grau eq3 (1,1,1); // 1*x^2 + 1*x + 1 = 0
    Eq2Grau eq4 = eq2 + eq3;
    cout << "Eq4: " << eq4 << endl;
    eq4 = eq4 - eq3;
    cout << "Eq4: " << eq4 << endl;
    return 0;
}
