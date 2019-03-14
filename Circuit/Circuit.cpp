#include<iostream>
#include<vector>
using namespace std;
struct muchie
{
    int a,b;
};
void DF(int nod,vector<muchie>v,int* viz,int* tata)
{
    viz[nod]=1;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].a==nod)
        {
            if(viz[v[i].b]==0)
            {
                tata[v[i].b]=nod;
                DF(v[i].b,v,viz,tata);
            }
            else if(viz[v[i].b]==1)
            {
                int ind = v[i].a;
                cout<<"\n";
                while(ind!=v[i].b)
                {
                    cout<<ind<<" ";
                    ind = tata[ind];
                }
                cout<<ind;
                return ;
            }
        }
    }
    viz[nod]=2;
}
int main()
{
    int n,m;
    vector<muchie> muchii;
    int *viz,*tata;
    muchie aux;
    cin>>n>>m;
    viz = new int[n+1];
    tata = new int[n+1];
    for(int i=0;i<=n;i++)viz[i]=tata[i]=0;
    for(int i=0;i<m;i++)
    {
        cin>>aux.a>>aux.b;
        muchii.push_back(aux);
    }
    DF(1,muchii,viz,tata);
    cout<<"\n";
    //for(int i=1;i<=6;i++)cout<<viz[i]<<" ";
    return 0;
}
