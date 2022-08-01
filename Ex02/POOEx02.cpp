#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Ponto
{
    double x,y;
public:

    Ponto(double X, double Y)
    {
        x=X;
        y=Y;
    }

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    double distanciaParaPonto(Ponto p)
    {
        double dpp= pow(pow((p.getX() -x), 2) + pow((p.getY() -y), 2),0.5);
        return dpp;
    }

};

class Reta
{
    double m,b;
public:

    Reta(Ponto p1, Ponto p2)
    {
        m=(p2.getY()-p1.getY())/(p2.getX()-p1.getX());
        b=p2.getY()-m*p2.getX();
    }

    double getM()
    {
        return m;
    }

    double getB()
    {
        return b;
    }

    bool ehParalela(Reta R)
    {
        if(b=R.getB())
            return true;

        else return false;
    }

    double distanciaParaPonto(Ponto p)
    {

        double aux=(m*p.getX())+(b-p.getY());
        if(aux<0)
        {
            aux=aux*(-1);
        }
        double dpr=aux/pow(1+pow(m,2),0.5);
        return dpr;
    }
};






int main()
{

    double x,y;


    cin>>x>>y;
    Ponto ponto1(x,y);

    cin>>x>>y;
    Ponto ponto2(x,y);

    cin>>x>>y;
    Ponto ponto3(x,y);

    cin>>x>>y;
    Ponto ponto4(x,y);

    cin>>x>>y;
    Ponto ponto5(x,y);

    Reta reta1(ponto1,ponto2);
    Reta reta2(ponto3,ponto4);
    cout<<"Distancia entre os pontos A  e B: "<< ponto1.distanciaParaPonto(ponto2)<<endl;
    cout<<"Valor de m para reta entre A e B: "<<reta1.getM()<<endl;
    cout<<"Valor de b para reta entre A e B: "<<reta1.getB()<<endl;

    cout<<"Valor de m para reta entre C e D: "<<reta2.getM()<<endl;
    cout<<"Valor de b para reta entre C e D: "<<reta2.getB()<<endl;

    cout<<"Distancia entre a reta AB e o ponto E: "<<reta1.distanciaParaPonto(ponto5)<<endl;
    cout<<"Distancia AB e CD sao paralelas?"<<reta1.ehParalela(reta2)<<endl;


    return 0;
}
