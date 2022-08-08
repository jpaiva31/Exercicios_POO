#include <iostream>
#include <set>

using namespace std;
void imprimeMaior(set<int> c)
{
    int maior;
    set<int>::iterator it;
    for(it=c.begin(); it!=c.end(); it++)
    {
        if(*it==*c.begin()) maior=*it;
        else if(*it>maior)maior=*it;
    }
    cout<<maior<<endl;
}
void imprimeMenor(set<int> c)
{
    int menor;
    set<int>::iterator it;
    for(it=c.begin(); it!=c.end(); it++)
    {
        if(*it==*c.begin()) menor=*c.begin();
        else if(*it<menor)menor=*it;
    }
    cout<<menor<<endl;
}
void imprime(set<int> c)
{
    set<int>::iterator it;
    for(it=c.begin(); it!=c.end(); it++)
    {
        cout<<*it<<" ";
    }
}

int main()
{
    set <int> conjunto;
    string n;
    int m;
    while(n!="*")
    {
        cin>>n;
        if(n=="+")
        {
            cin>>m;
            conjunto.insert(m);
        }
        else if(n=="-")
        {
            cin>>m;
            conjunto.erase(m);
        }
        else if(n=="?")
        {
            cin>>m;
            set<int>::iterator it=conjunto.find(m);
            if(it!=conjunto.end())cout<<"sim"<<endl;
            else cout<<"nao"<<endl;

        }
        else if(n==">")
        {
            imprimeMaior(conjunto);
        }
        else if(n=="<")
        {
            imprimeMenor(conjunto);
        }

    }
    imprime(conjunto);
    return 0;
}
