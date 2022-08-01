#include <iostream>
#include <vector>


using namespace std;

class Fila
{

    static int cont,cont2;
    vector<int> vetor;
public:

    Fila(const Fila &obj)
    {
        this->vetor=obj.vetor;
        cont+=obj.vetor.size();
        cont2++;
    }

    Fila()
    {
        cont2++;
    }

    static void stats()
    {
        cout<<"Ha "<<cont2<<" filas com tamanho total "<<cont<<"."<<endl;;
    }
    int getVetor(int a)
    {
        return vetor[a];
    }
    void enqueue(int a)
    {
        if(vetor.size()==50)
            throw -1;
        vetor.push_back(a);
        cont++;
    }
    void dequeue(int a)
    {
        if(vetor.size()==0)
            throw -1;
        for(int i=0; i<vetor.size(); i++)
        {
            if(vetor[i]==a)
            {
                vetor.erase(vetor.begin()+ i);
            }
        }
        cont--;
    }
    int dequeue()
    {
        if(vetor.size()==0)
            throw -1;
        int i=vetor[vetor.size()];
        vetor.erase(vetor.begin());
        cont--;
        return i;
    }

    Fila operator=(Fila a)
    {
        a.vetor=vetor;
        cont-=vetor.size()-a.vetor.size();
        return a;
    }

    ~Fila()
    {
        cont-=vetor.size();
        cont2--;
    }

};

int Fila::cont=0;
int Fila::cont2=0;

int main()
{
    Fila::stats();
    Fila *a = new Fila();
    for (int i=0; i<4; i++)
        a->enqueue(i);
    Fila b = (*a);
    Fila::stats();
    b. enqueue (4);
    b. enqueue (5);
    Fila c = (*a);
    Fila::stats();
    c = b;
    Fila::stats();
    int x = c.dequeue();
    delete a;
    Fila::stats();
    return 0;
}
