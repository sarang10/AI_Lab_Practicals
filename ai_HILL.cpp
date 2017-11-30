#include<iostream>
#include<cmath>
#include<conio.h>
using namespace std;
int goal[3][3];
struct hashing
{
    int i;
    int j;
}ha1[9],ha2[9];
struct element{
int val;
int a[3][3];
int emptyLoc[2];
};
int hueristic(int a[3][3],int b[3][3])
{
    int ans=0,i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            ha1[a[i][j]].i = i;
            ha1[a[i][j]].j = j;
            ha2[b[i][j]].i = i;
            ha2[b[i][j]].j = j;
        }
    }
    for(k=0;k<9;k++)
        ans = ans + abs(ha1[k].i-ha2[k].i) + abs(ha2[k].j-ha1[k].j);
    return ans;
}
void display(int a[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        cout<<"\n";
        for(j=0;j<3;j++)
            cout<<a[i][j]<<" ";
    }
    int zz;
    cin>>zz;
}
void swaps(int &x,int&y)
{
    int temp = x;
    x=y;
    y=temp;
}
int main()
{
    int initial[3][3],inter[3][3],i,j,m,n,val1,val2,k,z=1,temp;
    cout<<"Enter the Initial state\n";
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            cin>>initial[i][j];
            if(initial[i][j]==0)
            {
                m = i;
                n = j;
            }
        }
    cout<<"Enter the Final state\n";
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            cin>>goal[i][j];
    val1 = hueristic(initial,goal);
    cout<<"\nInitial Hueristic is:\n"<<val1;
    element *e = new element;
    e->emptyLoc[0] = m;
    e->emptyLoc[1] = n;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            e->a[i][j] = initial[i][j];
    e->val = val1;
    cout<<"\n";
    while(1)
    {
        display(e->a);
        k=0;z=1;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                if(e->a[i][j] != goal[i][j])
                {
                    k=1;
                    break;
                }
            if(k==1)
                break;
        }
        if(k!=1)
            break;
        k=0;
        int x = e->emptyLoc[0];
        int y = e->emptyLoc[1];
        if(y-1>=0)
        {
            swaps(e->a[x][y-1],e->a[x][y]);
            val2 = hueristic(e->a,goal);
            if(val2<val1)
            {
                val1=val2;
                e->emptyLoc[1] = y-1;
                k=1;
                continue;
            }
            else swaps(e->a[x][y-1],e->a[x][y]);
        }
        if(x-1>=0)
        {
            swaps(e->a[x-1][y],e->a[x][y]);
            val2 = hueristic(e->a,goal);
            if(val2<val1)
            {
                val1=val2;
                k=1;
                e->emptyLoc[0] = x-1;
                continue;
            }
            else swaps(e->a[x-1][y],e->a[x][y]);
        }
        if(y+1<3)
        {
            swaps(e->a[x][y+1],e->a[x][y]);
            val2 = hueristic(e->a,goal);
            if(val2<val1)
            {
                val1=val2;
                e->emptyLoc[1] = y+1;
                k=1;
                continue;
            }
            else swaps(e->a[x][y+1],e->a[x][y]);
        }
        if(x+1<3)
        {
            swaps(e->a[x+1][y],e->a[x][y]);
            val2 = hueristic(e->a,goal);
            if(val2<val1)
            {
                val1=val2;
                k=1;
                e->emptyLoc[0] = x+1;
                continue;
            }
            else swaps(e->a[x+1][y],e->a[x][y]);
        }
        if(k==0)
        {
            z=0;
            break;
        }

    }
    if(z==0)
        cout<<"Solution Not Possible\n";
    else if(k==0)
        cout<<"Solution Exist\n";
    else cout<<"Solution does not exist\n";
    return 0;
}
