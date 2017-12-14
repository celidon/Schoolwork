#include <iostream>
#include <ctime>
#include <cstdlib>

void zeroArray(char [], int);
void printArray(char [], int);
int hare(int);
int tortoise(int);

using namespace std;

int main()
{
    srand(time(0));
    char race[72];
    int rabbit=0, turtle=0, kdz=0;


        for(int j=1; j<1001; j++)
        {
            for(int k=0; k<1000; k++)
            {
                int t=0, h=0;

                do{
                    zeroArray(race,72);

                    int tick=rand()%100+1;
                    h=h+hare(tick);
                    t=t+tortoise(tick);

                    if(t<0)
                    {
                        t=0;
                    }
                    else if(h<0)
                    {
                        h=0;
                    }

                }while(t<=70 && h<=70);

                if(t>=70)
                {
                    turtle++;
                }
                else if(h>=70)
                {
                    rabbit++;
                }
                else if(t>=70 && h>=70)
                {
                   kdz++;
                }
            }
            if(j%100==0)
            {cout<<":";}
        }

    cout<<"Tortoise: "<<turtle<<"\nHare: "<<rabbit<<"\nPlatypus: "<<kdz<<endl;
    return 0;
}

//Printing out an array
void printArray(char arr[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        cout<<arr[i];
    }
}
//Filling the array with NULL and drawing the finish line
void zeroArray(char arr[], int size)
{
    for(int i=0; i<size; i++)
        {
            arr[i]='\0';
        }

    arr[size-1]='|';
}

//The movement rules of the hare
int hare(int num)
{
    int pos;

    if(num<=20)
    {
       pos=0;
    }
    else if(num>20 && num<=40)
    {
        pos=9;
    }
    else if(num>40 && num<=50)
    {
        pos=-12;
    }
    else if(num>50 && num<=80)
    {
        pos=1;
    }
    else if(num>80 && num<=100)
    {
        pos=-2;
    }

    return pos;
}

//The movement rules of the tortoise
int tortoise(int num)
{
    int pos;

    if(num<=50)
    {
       pos=3;
    }
    else if(num>50 && num<=70)
    {
        pos=-6;
    }
    else if(num>70 && num<=100)
    {
        pos=1;
    }

    return  pos;
}
