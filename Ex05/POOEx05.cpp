#include <iostream>
#include <vector>


using namespace std;

class Flores
{
public:
    virtual int resolver() {};
    virtual float getValor() {};
    virtual int getQtde() {};
};

class normais: public Flores
{
    int x;
    float valor;
public:

    normais(int a):Flores()
    {
        x=a;
        resolver(a);
    }
    void resolver(int a)
    {
        valor=2*a;
    }
    float getValor()
    {
        return valor;
    }
    int getQtde()
    {
        return x;
    }
};

class especiais: public Flores
{
    int x;
    float valor;
public:

    especiais(int a):Flores()
    {
        x=a;
        resolver(a);
    }
    void resolver(int a)
    {
        int aux=a/10+1;
        valor=2*a+aux*5;
    }
    float getValor()
    {
        return valor;
    }
    int getQtde()
    {
        return x;
    }
};


int main()
{
    vector<Flores*>vetor;
    string a;
    int qtd,qtdTotal=0,qtdTotal2=0;
    while(a!="fim")
    {
        cin>>a;
        if(a=="tradicional")
        {
            cin>>qtd;
            vetor.push_back(new normais(qtd));
        }
        else if(a=="especial")
        {
            cin>>qtd;
            vetor.push_back(new especiais(qtd));
        }
    }

    cout<<"Total: "<<vetor.size()<<" pedidos"<<endl;
    for(int i=0; i<vetor.size(); i++)
    {
        qtdTotal+=vetor[i]->getValor();
        qtdTotal2+=vetor[i]->getQtde();
        cout<<"Pedido "<<i<<": RS "<<vetor[i]->getValor()<<",00"<<endl;
    }
    cout<<"Total de Rosas: "<<qtdTotal2<<endl;
    cout<<"Valor Total : RS "<<qtdTotal<<",00"<<endl;

    return 0;
}
