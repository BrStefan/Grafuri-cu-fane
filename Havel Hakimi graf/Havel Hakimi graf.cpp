#include<iostream>
#include<algorithm>
using namespace std;
struct nod
{
    int grad,eticheta;
};
bool cmp(nod a,nod b)
{
    return a.grad>b.grad;
}
int main()
{
    int n,s=0;
    nod *v;
    cin>>n;
    v=new nod[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>v[i].grad;
        if(v[i].grad>n)
        {
            cout<<"Nu";
            return 0;
        }
        v[i].eticheta=i+1;
        s+=v[i].grad;
    }
    sort(v,v+n,cmp);
    if(s%2)cout<<"Nu";
    else
    {
        for(int i=0;i<n;i++)
        {
            if(v[i].grad>0)
            {
                for(int j=i+1;v[i].grad;j++)
                {
                    if(v[j].grad>0)
                    {
                        v[i].grad--;
                        v[j].grad--;
                        cout<<v[i].eticheta<<" "<<v[j].eticheta<<endl;
                    }
                }
                sort(v,v+n,cmp);
                i=-1;
            }
        }
    }
    return 0;
}
