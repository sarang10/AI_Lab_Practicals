#include<iostream>
using namespace std;
int a[10];
int turn;
void display()
{
    int i;
    cout<<"\n";
    for(i=0;i<9;i++)
    {
            if(i%3==0)
            cout<<"\n";
            if(a[i+1]==2)
            cout<<" - ";
            else if(a[i+1]==5)
                cout<<" O ";
            else cout<<" X ";
    }
    cout<<"\n";
}
int make2()
{
    if(a[5]==2)
        return 5;
    else if(a[2]==2)
        return 2;
    else if(a[4]==2)
        return 4;
    else if(a[6]==2)
        return 6;
    else if(a[8]==2)
        return 8;
}
int posswin(int p)
{
    int i,j;
    int ex = 0;
    if(p==1)
        ex = 18;
    else ex= 50;
    for(i=1;i<=7;i=i+3)
    {
        if(a[i]*a[i+1]*a[i+2]==ex)
        {
            for(j=i;j<i+3;j++)
                if(a[j]==2)
                    return j;
        }
    }
    for(i=1;i<=3;i++)
    {
        if(a[i]*a[i+3]*a[i+6]==ex)
        {
            for(j=i;j<=i+6;j=j+3)
                if(a[j]==2)
                    return j;
        }
    }
    if(a[1]*a[5]*a[9]==ex)
    {
        if(a[1]==2)
            return 1;
        else if(a[5]==2)
            return 5;
        else return 9;
    }
    if(a[3]*a[5]*a[7]==ex)
    {
        if(a[3]==2)
            return 3;
        else if(a[5]==2)
            return 5;
        else return 7;
    }
    return 0;
}
int go(int n)
{
    if(turn%2==0)
        a[n] = 5 ;
    else a[n] = 3 ;
    turn++;
}
int main()
{
    int p,i,m;
    turn = 1;
    cout<<"You are X and your turn is first\n";
    cout<<"\nInitial State Of Tic-Tac-Toe\n";
    for(i=0;i<9;i++)
        a[i+1]=2;
    display();
    cout<<"\n";
    while(turn<=9)
    {
        if(turn==1||turn==3||turn==5||turn==7||turn==9)
            {
                cout<<"\nYour Turn:(Enter position from 1 to 9)\n";
                cin>>m;
                while(a[m]!=2||m<1||m>9)
                {
                    cout<<"\nPlease enter the correct value\n";
                    cin>>m;
                }
                a[m]=3;
                turn++;
                display();
                if(turn==10)
                    cout<<"\nMatch is Drawn\n";
            }
            else if(turn==2)
            {
                if(a[5]==2)
                    go(5);
                else go(1);
               display();
            }
            else if(turn==4)
            {
                if(posswin(1)!=0)
                    go(posswin(1));
                else go(make2());
                display();
            }
            else if(turn==6)
            {
                int temp1 = posswin(1),temp2 = posswin(2);
                if(temp2!=0)
                {
                    go(temp2);
                    cout<<"\nComputer Wins and You Loose\n";
                    display();
                    break;
                }
                else if(temp1!=0)
                    go(temp1);
                else go(make2());
                display();
            }
            else if(turn==8)
            {
                int temp1 = posswin(1),temp2 = posswin(2);
                if(temp2!=0)
                {
                    go(temp2);
                    cout<<"\nComputer Wins and You Loose\n";
                    display();
                    break;
                }
                else if(temp1!=0)
                    go(temp1);
                else{
                    for(i=1;i<=9;i++)
                    if(a[i]==2)
                    {
                            go(i);
                            break;
                    }
                }
                display();
            }
    }
    return 0;
}

