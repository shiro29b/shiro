

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press Run button to compile and execute it.



#include bitsstdc++.h
#include unordered_map

using namespace std;

int main()
{
    int n,m,z;
    cinnmz;
    stdqueueint a;
    queueint b;
    int sum=0;
    int t;
    for(int i=0;in;i++)
    {
        cint;
        a.push(t);
    }
    for(int i=0;im;i++)
    {
        cint;
        b.push(t);
    }
    while(!a.empty() && !b.empty() && z=0)
    {
        
        if((a.front()b.front()))
        {
            z=z-a.front();
            a.pop();
            sum++;
        }
        else if((a.front()=b.front()))
        {
            z=z-b.front();
            b.pop();
            sum++;
        }
        else
        break;
    }
    
    while(!a.empty() && z=0)
    {
        z=z-a.front();
            a.pop();
            sum++;
    }
    while(!b.empty() && z=0)
    {
        z=z-b.front();
            b.pop();
            sum++;
    }
    sum--;
    coutsum;

    return 0;
}
