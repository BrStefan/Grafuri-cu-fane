#include<iostream>
#include<vector>
using namespace std;
void DF(int nod,int *viz,vector<int>*la)
{
    viz[nod]=1;
    for(int i=0;i<la[nod].size();i++)
        if(viz[la[nod][i]]==0)DF(la[nod][i],viz,la);
}
int BF(int start,vector<int>*la,int n,int &maxim)
{
    int *coada,*viz,*h;
    int curent;
    coada = new int[n+1];
    viz = new int[n+1];
    h = new int[n+1];
    for(int i=0;i<=n;i++)coada[i]=viz[i]=h[i]=0;
    int prim,ultim;
    prim=ultim=0;
    coada[prim]=start;
    h[start]=0;
    while(prim<=ultim)
    {
        curent = coada[prim];
        viz[curent]=1;
        for(int i=0;i<la[curent].size();i++)
        {
            if(viz[la[curent][i]]==0)
            {
                h[la[curent][i]]=h[curent]+1;
                if(h[curent]+1>maxim)maxim=h[curent]+1;
                viz[la[curent][i]]=1;
                ultim++;
                coada[ultim]=la[curent][i];
            }
        }
        prim++;
    }
    return coada[ultim];
}
int main()
{
    int n,m,x,y,*viz,max,*h;
    bool e=0;
    vector<int>*la;
    cin>>n>>m;
    la=new vector<int>[n+1];
    viz = new int[n+1];
    h = new int[n+1];
    for(int i=0;i<=n;i++)viz[i]=h[i]=0;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        la[x].push_back(y);
        la[y].push_back(x);
    }
    DF(1,viz,la);
    for(int i=1;i<=n;i++)if(viz[i]==0)e=1;
    if(e==1 || m+1!=n)cout<<"Nu e arbore";
    else
    {
        int capat;
        for(int i=0;i<=n;i++)viz[i]=0;
        capat=BF(1,la,n,max);
        BF(capat,la,n,max);
        cout<<max; // diametrul;
    }
    return 0;
}
