#include <iostream>
#include <vector>

using namespace std;

string converte(string a)
{

    for(int i=0; i<a.size(); i++)
    {

        if(a[i]<97)
        {
            a[i]+=32;
        }
    }
    return a;
}
int main()
{
    int num,soma=0;
    string palavra;
    vector <string> vetor;

    cin>>num;

    for(int i=0; i<num; i++)
    {
        cin>>palavra;
        converte(palavra);
        vetor.push_back(converte(palavra));
        soma+=palavra.size();
    }
    cout<<"Total de caracteres: "<<soma<<endl;

    for(int i=0; i<num; i++)
    {
        int maior=0;
        for(int k=i+1; k<num; k++)
        {
            if(vetor[i]>vetor[k])
            {
                if(vetor[maior]>vetor[k])
                {
                    maior=k;
                }
            }
        }
        cout<<vetor[maior]<<endl;
        vetor.erase(vetor.begin()+maior);
        maior=0;
        num--;
        i--;
    }
    return 0;
}







//32 de diferença
