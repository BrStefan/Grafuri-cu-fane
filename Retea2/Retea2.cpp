//Varianta din laborator

#include <cstdio>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

struct muchie_struct
{
	int nod1,nod2,tip1,tip2,viz;
	double cost;
};

double distanta(pair<int,int> a,pair<int,int> b)
{
    return sqrt(pow((a.first-b.first),2) + pow((a.second-b.second),2));
}
void citire_date(vector <muchie_struct> &v , int& n , int& m,int& e)
{
    muchie_struct aux;
    vector<pair<int,int> >coord;
    int a,b;
	scanf("%d%d%d",&n,&m,&e);
	for(int i=0;i<n+m;i++)
	{
	    scanf("%d%d",&a,&b);
	    coord.push_back(make_pair(a,b));
	}
	for(int i=0;i<e;i++)
	{
	    scanf("%d%d",&aux.nod1,&aux.nod2);
	    if(aux.nod1<=n)aux.tip1=1;
	    else aux.tip1=2;
	    if(aux.nod2<=n)aux.tip2=1;
	    else aux.tip2=2;
	    aux.cost=distanta(coord[aux.nod1-1],coord[aux.nod2-1]);
	    aux.viz=0;
	    v.push_back(aux);
	}
}

bool cmp(muchie_struct a,muchie_struct b)
{
	return a.cost<=b.cost;
}

int Reprezentant(int nod,int t[])
{
	if(t[nod]==0)return nod;
	t[nod]=Reprezentant(t[nod],t);
	return t[nod];
}

void Reuneste(int u,int v, int tata[],int h[])
{
	int ru,rv;
	ru=Reprezentant(u,tata);
	rv=Reprezentant(v,tata);
	if(h[ru]>h[rv])tata[rv]=u;
	else
	{
		tata[ru]=v;
		if(h[ru]==h[rv])h[rv]++;
	}
}

void Kruskal(vector <muchie_struct> v,int n,int m,int t)
{
	unsigned int cnt,r1,r2,cate=0;
	int *tata,*inaltime;

	tata=new int[n+1];
	inaltime=new int[n+1];

	vector <muchie_struct> aux;
	muchie_struct aux2;

	for(int i=0;i<=n;i++)tata[i]=inaltime[i]=0;
	for(unsigned int i=0;i<m;i++)
	{
	    if(v[i].tip1==1 && v[i].tip2==1)continue;
		r1=Reprezentant(v[i].nod1,tata);
		r2=Reprezentant(v[i].nod2,tata);
		if(r1!=r2)
		{
			Reuneste(v[i].nod1,v[i].nod2,tata,inaltime);
			cnt++;
			aux2.nod1=v[i].nod1;
			aux2.nod2=v[i].nod2;
			aux2.cost=v[i].cost;
			aux.push_back(aux2);
			if(v[i].tip1==2 && v[i].viz==0)
			{
			    cate++;
			    v[i].viz=1;
			}
			if(v[i].tip2==2 && v[i].viz==0)
			{
			    cate++;
			    v[i].viz=1;
			}
		}
		if(cate==t)break;
	}
	for(int i=0;i<cate;i++)
		printf("Muchia %d: %d-%d de cost %f\n",i+1,aux[i].nod1,aux[i].nod2,aux[i].cost);
}
int main()
{
	int nr_centrale,nr_blocuri,nr_muchii;
	vector<muchie_struct> muchie;

	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);

	citire_date(muchie,nr_centrale,nr_blocuri,nr_muchii);

	sort(&muchie[0],&muchie[nr_muchii],cmp);

	Kruskal(muchie,nr_centrale+nr_blocuri,nr_muchii,nr_blocuri);

}
