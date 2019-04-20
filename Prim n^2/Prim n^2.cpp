#include<fstream>
#include<vector>

#define INF 9999999
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

void citire_date(int&n,int&m,vector<pair<int,int> >*&v)
{
    int x,y,z;
    fin>>n>>m;
    v = new vector<pair<int,int> >[n+1];
    for(int i=0;i<m;i++)
    {
        fin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
}
int main()
{
    int n,m,*d,*t,*viz,nod,min,vecin,cost;
    vector<pair<int,int> >*v;
    citire_date(n,m,v);

    d = new int[n+1];
    t = new int[n+1];
    viz = new int[n+1];

    for(int i=0;i<=n;i++)
    {
        d[i]=INF;
        t[i]=0;
        viz[i]=0;
    }
    d[1]=0;
    nod=0;
    for(int i=1;i<=n-1;i++)
    {
        min = INF;
        for(int k=1;k<=n;k++)
            if(d[k]<min && viz[k]==0)
            {
                min=d[k];
                nod = k;
            }
        for(int j=0;j<v[nod].size();j++)
        {
            vecin = v[nod][j].first;
            cost = v[nod][j].second;
            if(viz[vecin]==0 && cost<d[vecin])
            {
                d[vecin] = cost;
                t[vecin] = nod;
            }
        }
        viz[nod]=1;
    }
    for(int i=2;i<=n;i++)fout<<i<<" "<<t[i]<<endl;
    return 0;
}
