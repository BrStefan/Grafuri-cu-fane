#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define INF -100000

struct heap_struct
{
	int nod,cost;
};

void citire_graf(int nr_muchi , vector<pair<int,int> > *la,int*cost,int nr_noduri)
{
	int a,b;
	int *marcat;
	marcat = new int[nr_noduri+2];
	for(int i=0;i<=nr_noduri+2;i++)marcat[i]=0;
	a=b=0;
	for(int i=1;i<=nr_muchi;i++)
	{
		scanf("%d%d",&a,&b);
		la[a].push_back(make_pair(b,cost[a]));
		marcat[b]++;
	}
	for(int i=1;i<=nr_noduri;i++)
     {
        if(marcat[i]==0)la[0].push_back(make_pair(i,0));
        else if(la[i].size()==0)la[i].push_back(make_pair(nr_noduri+1,cost[i]));
     }
}


//urcarea unui element in heap
void min_heap(heap_struct *h,int poz,int *v)
{
	while(1)
	{
		if(h[poz/2].cost<h[poz].cost)
		{
			swap(v[h[poz].nod],v[h[poz/2].nod]);
			swap(h[poz],h[poz/2]);
			poz=poz/2;
		}
		else break;
	}
}
//functia de inserare a unui nod si a costului sau intr-un heap
void inserare(heap_struct *h,int c,int n,int *poz)
{
	int i;
	for(i=0;h[i].cost;i++);
		h[i].nod=n;
		h[i].cost=c;
		poz[n]=i;
	//operatia de transformare a unui heap intr-un min-heap
	min_heap(h,i,poz);
}

void down(heap_struct *h, int *v)
{
	int poz=0,f1,f2;
	while(1)
	{
		f1=2*poz+1;
		f2=2*poz+2;
		if(h[f1].cost == 0 && h[f2].cost) // are doar fiu drept
		{
			if(h[f2].cost>h[poz].cost)
			{
				swap(v[h[f2].nod],v[h[poz].nod]);
				swap(h[f2],h[poz]);
				poz=f2;
			}
		}
		else if(h[f1].cost && h[f2].cost==0) // are doar fiu stang
		{
			if(h[f1].cost>h[poz].cost)
			{
				swap(v[h[f1].nod],v[h[poz].nod]);
				swap(h[f1],h[poz]);
				poz=f1;
			}
		}
		else if(h[f1].cost && h[f2].cost) // are ambii fii
		{
			if(h[f1].cost>h[f2].cost)
			{
				swap(v[h[f1].nod],v[h[poz].nod]);
				swap(h[f1],h[poz]);
				poz=f1;
			}
			else if(h[f2].cost>h[f1].cost)
			{
				swap(v[h[f2].nod],v[h[poz].nod]);
				swap(h[f2],h[poz]);
				poz=f2;
			}
			else break;
		}
		else break; // nu mai are niciun fiu
	}
}

void Decapitare(heap_struct *h,int *v)
{
	int i;
	for(i=0;h[i+1].cost;i++);
	///////////////////////////////////////////////////////////////
		swap(h[0],h[i]);
		swap(v[0],v[i]);
	v[h[i].nod]=-1;
	h[i].nod=h[i].cost=0;
	down(h,v);

}
void algoritm(vector<pair<int,int> > *la,int n,int m,int start,int* timp)
{
	//variabile
	int *tata,*costuri,*viz,vecin,curent,cost,*poz;
	heap_struct *heap;

	//alocare memorie
	tata=new int [n+2];
	costuri=new int [n+2];
	viz=new int [n+2];
	heap=new heap_struct[n+2];
	poz=new int[n+2];

	//initializare variabile
	for(int i=0;i<=n+1;i++)
		{
			tata[i]=viz[i]=0;
			heap[i].nod=heap[i].cost=0;
			costuri[i]=INF;
			poz[i]=-1;
		}
	costuri[start]=0;
	poz[start]=0;

	//inserare start in heap
	inserare(heap,costuri[start],start,poz);

	for(int i=1;i<=n+2;i++)
	{
		curent=heap[0].nod;
		Decapitare(heap,poz);
		viz[curent]=1;
		//printf("Nodul %d este: %d\n",i,curent);
		for(int j=0;j<la[curent].size();j++)
		{
			vecin = la[curent][j].first;
			cost = la[curent][j].second;
			if(viz[vecin]==0)
			{
				if(costuri[curent]+cost>costuri[vecin]) // if modificat fata de prim
				{
					tata[vecin] = curent;
					costuri[vecin]=cost+costuri[curent]; // modifcare fata de prim
					if(poz[vecin]==-1) // trebuie inserat in heap
						inserare(heap,costuri[vecin],vecin,poz);
					else // se face o reordonare
					{
						heap[poz[vecin]].cost=cost+costuri[curent]; // modificare fata de prim
						min_heap(heap,poz[vecin],poz);
					}
				}
			}
		}
	}


    printf("Timp minim: %d\n",costuri[n+1]);
    int nod=n+1;

    //Afiseaza drumul invers
    while(tata[nod])
    {
        printf("%d ",tata[nod]);
        nod=tata[nod];
    }
    printf("\n");

    for(int i=1;i<=n;i++)
    printf("%d: %d %d\n",i,costuri[i],timp[i]+costuri[i]);

}

int main()
{
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	//declarare variabile
	int n,m,start,*cost;
	//vectorul de liste de adiacenta pentru muchii. Pereche de (i,j), cu prop ca i este vecin, j cost
	vector <pair<int, int> > *la;

	//citire numar noduri si muchii;
	scanf("%d",&n);

	la=new vector<pair<int, int> >[n+2];

	cost = new int[n+2];
	for(int i=1;i<=n;i++)scanf("%d",&cost[i]);
	scanf("%d",&m);

	citire_graf(m,la,cost,n);

	start=0;

	algoritm(la,n,m,start,cost);
	return 0;
}
