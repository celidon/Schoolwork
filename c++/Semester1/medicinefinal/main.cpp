#include <iostream>
#include <iomanip>

using namespace std;
int Total(int [], int);
double Total(double [], int);

int main()
{
    int size;
    int ttlnum;
    double aveprice, sum=0;

    cout<<"How many different vitamins need to be entered?\n";
    cin>>size;

    char name[size];
    int number[size];
    double price[size];
    double ttlprice[size];


    cout<<"Please input the information for a vitamin in the following format:\n";
    cout<<"X $0.00 00\n";
    cout<<"Press return to enter a new vitamin\n";

    for(int i=0; i<size; i++)
    {
        cin>>name[i]>>price[i]>>number[i];
    }

    for(int i=0; i<size; i++)
    {
        ttlprice[i]=number[i]*price[i];
    }

    for(int i=0; i<size; i++)
    {
        sum=Total(price, size);
        aveprice=sum/size;
    }

    ttlnum=Total(number, size);

    cout<<setw(8)<<"Vitamin"<<setw(15)<<"Price"<<setw(15)
        <<"Inventory"<<setw(15)<<"Total\n";

    for(int i=0; i<size; i++)
    {
        cout<<setw(8)<<name[i]<<setw(15)<<price[i]<<setw(15)
            <<number[i]<<setw(15)<<ttlprice[i]<<endl;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"The average price for a vitamin is $"<<aveprice<<endl;

    cout<<"The total store inventory is "<<ttlnum<<" jars of vitamins\n";

    return 0;
}

int Total(int arr[], int size)
{
    int sum=0;

    for(int i=0; i<size; i++)
    {
        sum=sum+arr[i];
    }

    return sum;
}

double Total(double arr[], int size)
{
    double sum=0;

    for(int i=0; i<size; i++)
    {
        sum=sum+arr[i];
    }

    return sum;
}
