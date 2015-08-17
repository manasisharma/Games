#include <stdio.h>
#include <iostream>
using namespace std;
long mat[100][100];
bool firstmingo=false;
void assign()
{
    int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            mat[i][j]=rand()%1000000;
        }
    }
    
}
void update(long rand_num)
{
    int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            if(mat[i][j]==rand_num) mat[i][j]=-1;
        }
    }
}
void check()
{
    int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            if(mat[i][j]!=-1) break;
            else if((j==99)&&mat[i][j]==-1) { firstmingo=true; break;}
        }
    }
   if(firstmingo!=true)
   {    for(j=0;j<100;j++)
        {
            for(i=0;i<100;i++)
            {
                if(mat[i][j]!=-1) break;
                else if((i==99)&&mat[i][j]==-1) { firstmingo=true; break;}
            }
        }
       if(firstmingo!=true)
       {
           i=0; j=0;
           while(i<100&&j<100)
                {
                        if(mat[i][j]!=-1) break;
                        else if((j==99)&&mat[i][j]==-1) { firstmingo=true; break;}
                    i++; j++;
                }
           if(firstmingo!=true)
           {
               j=99; i=0;
               while(i<100&&j>=0)
               {
                   if(mat[i][j]!=-1) break;
                   else if((j==0)&&mat[i][j]==-1) { firstmingo=true; break;}
                   j--;
                   i++;
               }
           }
       }
   }
}
void mingo_play()
{
    int counter=1;
    do
    {
        long rand_num=rand()%1000000;
        counter++;
        update(rand_num);
        check();
    }while(firstmingo==false);
    cout<<"\n First Mingo found after"<<counter<<"random numbers";
}
int main()
{
    assign();
    mingo_play();
    return 0;
}
