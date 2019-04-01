#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct muchie
{
    int st,dr,cost;
};
void citire_date(int &n,int &m,vector<muchie>&lm)
{

    /**
    * vector<string> cuv;
    * string aux;
    * cin>>n>>k;
    * for(int i=0;i<n;i++)
    * {
    *   cin>>aux;
    *   cuv.push_back(aux);
    * }
    * for(int i=0;i<n;i++)
    * for(int j=0;j<n;j++)
    * if(i!=j)
    * {
    *   cost=distanta(cuv[i],cuv[j]);
    *   aux.st=i+1;
    *   aux.dr=j+1;
    *   aux.cost=cost;
    *   lm.push_back(aux);
    * }
    *
    *

    */
    cin>>n>>m;
    muchie aux;
    for(int i=0;i<m;i++)
    {
        cin>>aux.st>>aux.dr>>aux.cost;
        lm.push_back(aux);
    }
}
bool cmp(muchie a,muchie b)
{
    return a.cost<b.cost;
}
void Initializare_culori(vector<int> &c,int n)
{
    for(int i=0;i<=n;i++)c.push_back(i);
}
int reprezentant(int n,vector<int>c)
{
    return c[n];
}
void Reuneste(int n1,int n2,vector<int>&c)
{
    int k1=reprezentant(n1,c);
    int k2=reprezentant(n2,c);
    for(int i=1;i<=c.size();i++)if(c[i]==k1)c[i]=k2;
}
void Kruskal(vector<muchie>lm,int n,int m)
{
    vector<int>culori;
    Initializare_culori(culori,n);
    int cnt=0,r1,r2;
    vector<muchie> rez;
    muchie aux;
    for(int i=0;i<m;i++)  // m-k pentru k-kluster
    {
        r1=reprezentant(lm[i].st,culori);
        r2=reprezentant(lm[i].dr,culori);
        if(r1!=r2)
        {
            cnt++;
            Reuneste(lm[i].st,lm[i].dr,culori);
            aux.st=lm[i].st;
            aux.dr=lm[i].dr;
            aux.cost=lm[i].cost;
            rez.push_back(aux);
        }
        if(cnt==n-1)break;
    }
    cout<<endl<<endl;
    for(int i=0;i<cnt;i++)cout<<rez[i].st<<" "<<rez[i].dr<<" "<<rez[i].cost<<endl;
}
int main()
{
    int nr_noduri,nr_muchii;
    vector<muchie>lm;
    citire_date(nr_noduri,nr_muchii,lm);
    sort(&lm[0],&lm[nr_muchii],cmp);
    Kruskal(lm,nr_noduri,nr_muchii);
    return 0;
}
