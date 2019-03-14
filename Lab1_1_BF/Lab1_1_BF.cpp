#include<iostream>
#include<vector>
using namespace std;
struct muchie
{
    int a,b;
};
int BF(int start,vector<muchie>v,int m,int n,vector<int>control)
{
    int *coada,*viz,*tata;
    int curent;
    coada = new int[n+1];
    viz = new int[n+1];
    tata = new int[n+1];
    for(int i=0;i<=n;i++)coada[i]=viz[i]=tata[i]=0;
    int prim,ultim;
    prim=ultim=0;
    coada[prim]=start;
    while(prim<=ultim)
    {
        curent = coada[prim];
        viz[curent]=1;
        for(int i=0;i<m;i++)
        {
            if(v[i].a==curent)
            {
                if(viz[v[i].b]==0)
                {
                    tata[v[i].b]=curent;
                    for(int k=0;k<control.size();k++)if(control[k]==v[i].b)
                    {
                        int ind=tata[v[i].b];
                        while(ind)
                        {
                            cout<<ind<<" ";
                            ind=tata[ind];
                        }
                        return v[i].b;
                    }
                     viz[v[i].b]=1;
                    ultim++;
                    coada[ultim]=v[i].b;
                }
            }
            else if(v[i].b==curent)
            {
                if(viz[v[i].a]==0)
                {
                    tata[v[i].a]=curent;
                    for(int k=0;k<control.size();k++)if(control[k]==v[i].a)
                    {
                        int ind=tata[v[i].a];
                        while(ind)
                        {
                            cout<<tata[ind]<<" ";
                            ind=tata[ind];
                        }
                        return v[i].a;
                    }
                    viz[v[i].a]=1;
                    ultim++;
                    coada[ultim]=v[i].a;
                }
            }
        }
        prim++;
    }
}
int main()
{
    int nr_noduri,nr_muchii,nr_control;
    cin>>nr_noduri>>nr_muchii>>nr_control;
    vector<muchie>muchii;
    vector<int>control;
    muchie aux;
    int aux2;
    for(int i=0;i<nr_muchii;i++)
    {
        cin>>aux.a>>aux.b;
        muchii.push_back(aux);
    }
    for(int i=0;i<nr_control;i++)
    {
        cin>>aux2;
        control.push_back(aux2);
    }
    cout<<BF(1,muchii,nr_muchii,nr_noduri,control);
    return 0;
}
