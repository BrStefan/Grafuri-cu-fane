#include<iostream>
using namespace std;
struct nod
{
    int grad,eticheta;
};
int main()
{
    int n,i1,i2;
    nod *v,x;
    cin>>n;
    v=new nod[n+1];
    i1=0;
    i2=n-1;
    for(int i=0;i<n;i++)
    {
        cin>>x.grad;
        x.eticheta=i+1;
        if(x.grad==1)
        {
            v[i1].grad=x.grad;
            v[i1].eticheta=x.eticheta;
            i1++;
        }
        else
        {
            v[i2].grad=x.grad;
            v[i2].eticheta=x.eticheta;
            i2--;
        }
    }
    i2++;
    i1=0;
    for(int i=i2;i<n;i++)
    {
        while(v[i].grad>1)
        {
            cout<<v[i].eticheta<<" "<<v[i1].eticheta<<endl;
            v[i].grad--;
            v[i1].grad--;
            i1++;
        }

    }
    for(int i=i2;i<n;i++)
    {
        cout<<v[i].eticheta<<" "<<v[i1].eticheta<<endl;
        i++;
    }
    return 0;
}
