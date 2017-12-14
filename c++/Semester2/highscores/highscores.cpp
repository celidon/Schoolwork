/*
   File Name: highscores.cpp
   Developer: Anthony Hansen
   Date Last Modified: 06.02.2014
   Description: Write a program that maintains a high score table of five
                entries, where each entry is made up of a player's name and
                score. The table should store the entries in order, from
                highest score to lowest.  Your program should initialize the
                table using your name and 1000 for all five entries.  Next,
                your program should display the entries and allow a player to
                add a new one. Your program should accept a name and a  score
                for the potential new entry.  If the score is greater than or
                equal to the lowest score in the table, your program should
                insert the new entry at the correct position, adjust the rest
                of the table accordingly, and display a message saying that the
                entry was inserted.  Otherwise, your program should display a
                message telling the player that the score was too low for the
                entry to be added. Your program should continue to display the
                table and allow the player to add new entries as long as he or
                she wants.(Hint: Your program doesn't have to do a full sort of
                the entries when a new one is added.  You can assume that the
                entries are already sorted; a new entry needs only to be
                inserted at the correct position with the rest of the table
                adjusted accordingly)
   Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;

void original(char **, int[]);
void printScores(char **, int[]);
void compareScores(char **, int [], char [], int);

int main()
{
    char *names[5], newname[9], ans='y';
    int scores[5], newscore;

    for(int i=0; i<5; i++)
    {
        names[i]=new char[9];
    }

    original(names, scores);
    printScores(names, scores);

    do{
        if(ans=='y' || ans=='Y')
        {
            cout<<"Please enter your name: \n";
            cin>>newname;
            cout<<"Please enter your score: \n";
            cin>>newscore;

            compareScores(names, scores, newname, newscore);

            printScores(names, scores);

            cout<<"Enter new highscore? y/n\n";
            cin>>ans;
        }
        else if(ans=='n' || ans=='N')
        {
            break;
        }
        else
        {
            cout<<"Please choose an option\n";
            cin>>ans;
        }

    }while(ans!='n');

    cout<<"Good-bye\n";

    return 0;
}
//Filling the arrays for the first list
void original(char **names, int scores[])
{
    char name[9]="Tony";

    for(int i=0; i<5; i++)
    {
        strcpy(names[i], name);
        scores[i]=1000;
    }
}
//Function to print out the two arrays
void printScores(char **names, int scores[])
{
    cout<<setw(18)<<"HIGHSCORES"<<endl;
    cout<<setw(10)<<"Name"<<setw(10)<<"Score"<<endl;

    for(int i=0; i<5; i++)
    {
        cout<<setw(10)<<names[i]<<setw(10)<<scores[i]<<endl;
    }

    cout<<endl;
}
//Function to compare the new score to the old score and rearranges the table accordingly
void compareScores(char **names, int scores[], char newname[], int newscore)
{
    for(int i=0; i<5; i++)
    {
        if(newscore>=scores[i])
        {
            int j=4;
            while(i<j)
            {
                *names[j]=*names[j-1];//Dereference pointers so that the data moves down the list smoothly
                scores[j]=scores[j-1];
                j--;
            }
            strcpy(names[i],newname);
            scores[i]=newscore;
            break;
        }
        if(i>=4 && newscore<scores[i])
        {
            cout<<"I'm sorry, that score is too low to be added to the high scores list.\n";
        }
    }
}
