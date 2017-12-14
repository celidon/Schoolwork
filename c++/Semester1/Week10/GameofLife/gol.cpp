/*
File Name: gol.cpp
Developer: Anthony Hansen
Date Last Modified: 09.11.2013
Description: The assignment was to write a program that simulates the Game of Life
             as it was designed by James Conway in a 22 by 80 matrix. The game has
             3 simple rules: If a 'live' cell has 4 or more live neighboring cells,
             it will 'die'. If a 'live' cell has less than 2 'live' neighboring cells,
             it 'dies'. If an empty cell has exactly 3 members, a new 'life' is 'born'
             into it.
Email Address: hansen.tony92@gmail.com
*/


#include <iostream>
#include <ctime>
#include <cstdlib>

const int height=10;
const int width=10;
void generation(char [][height]);
void display(char [][height]);
void copyArray(char [][height], char [][height]);
void fillGame(char [][height], char);
void zeroArray(char [][height]);
int neighbors(char [][height], int, int);

using namespace std;

int main()
{
    char world[width][height];
    char newworld[width][height];

    zeroArray(world);
    fillGame(world, '*');

    char ans=0;
    int i=1;

    cout<<"This is the Game of Life.\nThe board will be filled for you,\nall you need to do is determine how long it will go.\n";

    do{
        cout<<"Would you like to see the "<<i<<" generation? y/n\n";
        cin>>ans;
        if(ans=='y' || ans=='Y')
        {
            display(world);
            generation(world);
            i++;
            cout<<endl;
        }
        else if(ans=='n' || ans=='N')
        {
            break;
        }
        else
        {
            cout<<"Please choose an option\n";
        }

    }while(ans!='n' || ans!='N');

    cout<<"Goodbye";

    return 0;
}

//Editting the matrix according to the rules.
void generation(char world[][height])
{
    char newworld[width][height];

//First the matrix is copied in order to avoid accidental changes
    copyArray(world, newworld);

//The rules are then applied to each cell individually
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int neighbor = neighbors(world, j, i);
            if(neighbor==1 || neighbor==0)
            {
                newworld[j][i]=0;
            }
            else if(neighbor==3 && world[j][i]==0)
            {
                newworld[j][i]='*';
            }
            else if(neighbor>3 && world[j][i]=='*')
            {
                newworld[j][i]=0;
            }
            else if((neighbor==2 || neighbor==3) && (world[j][i]=='*'))
            {
                newworld[j][i]='*';
            }
        }
    }

//The matrix is then copied back over for output and so that changes are permanent
    copyArray(newworld, world);
}

//Printing the matrix
void display(char world[][height])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            cout<<world[j][i];
        }

        cout<<endl;

    }
}

//Copying the matrix so that changes do not effect future changes what is currently
//contained and being used in the matrix
void copyArray(char old[][height], char newcopy[][height])
{
   for(int i=0; i<height; i++)
   {
       for(int j=0; j<width; j++)
       {
           newcopy[j][i]=old[j][i];
       }
   }

}

//Randomly filling the matrix to start the game
void fillGame(char world[][height], char filler)
{
    srand(time(0));
    int randfill=0;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            randfill=rand()%3+1;
            if(randfill == 2)
            {
                world[j][i]=filler;
            }
        }
    }

}

//Filling an empty matrix inorder to avoid unwanted characters
void zeroArray(char world[][height])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            world[j][i]=0;
        }
    }
}

//Determining the whether or not neighboring cells are 'alive' or dead'
int neighbors(char world[][height], int j, int i)
{
    int neighbors = 0;

    for(int k = i-1; k <=i+1;k++)
    {
        for(int l = j-1;l<=j+1;l++)
        {
            if((k == i && l == j) || (k < 0 || k >= height) || (l < 0 || l >= width))
                continue;
            else
            {
                if(world[l][k]=='*')
                {
                    neighbors++;
                }
            }
        }
    }
    return neighbors;
}
