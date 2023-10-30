#include<iostream>
#include<cstring>
using namespace std;
#define V 5
#define HIGH 999999

int main()
{
    int G[V][V]={
    {0,4,0,5,2},
    {4,0,1,3,0},
    {0,1,0,8,0},
    {5,3,8,0,2},
    {2,0,0,2,0}
    };


    int v_array[V];
    memset(v_array,false,sizeof(v_array));
    v_array[0]=true;
    cout << "Edge :weight\n";
    int no_edge = 0;
    while(no_edge< V-1)
    {
        int min = HIGH;
        int r =0;
        int c =0;
        for(int i=0;i<5;++i)
        {
            if(v_array[i])
            {
                for (int j=0;j<5;++j)
                {
                    if(min>G[i][j])
                    {
                        if(!v_array[j] && G[i][j])
                        {
                        min=G[i][j];
                        r=i;
                        c=j;
                        }
                    }
                }
            }
        }
        cout<<" "<<r<<"-"<<c<<"  :  "<<G[r][c]<<endl;
        v_array[c]=true;
        no_edge++;

    }
    return 0;

}
