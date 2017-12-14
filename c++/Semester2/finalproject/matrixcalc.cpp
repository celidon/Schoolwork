/*
File Name: matrixcalc.cpp
Description: The assignment was to write a program that would function as a
			 matrix calculator. The calcuator takes user input and then adds,
			 subtracts, or multiplies two matrices or multiplies a matrix and
			 a scalar.
Author: Anthony Hansen
Email Address: hansen.tony92@gmail.com
Date Created: Thu May 15 14:58:54 PDT 2014
*/
#include<iostream>
#include<cstdlib>

using namespace std;

void addMatrix();
void subMatrix();
void multiMatrix();
void multiScalar();

int main()
{
	char choice;
	cout<<"Welcome to the matrix calculator!\nPlease only use whole numbers";
	do{
		cout<<"What would you like to do?\n";
		cout<<"1)Add two matrices\n2)Subtract two matrices\n3)Multiply two matrices\n4)Multiply a matrix by a scalar\n5)Exit\n";
		cin>>choice;
		if(isdigit(choice))
		{
			int option=static_cast<int>(choice)-48;
			if(option==1)
			{
				addMatrix();
			}
			else if(option==2)
			{
				subMatrix();
			}
			else if(option==3)
			{
				multiMatrix();
			}
			else if(option==4)
			{
				multiScalar();
			}
			else if(option==5)
			{
				cout<<"Goodbye"<<endl;
				exit;
			}
			else
			{
				cout<<"Please make a valid choice\n";
			}
		}
		else
		{
			cout<<"Please make a valid choice\n";
		}
	}while(choice!='5');
	return 0;
}

void addMatrix()
{
	char col,row;
	do{
		cout<<"How many rows do the matrices have?\n";
		cin>>row;
	}while(!isdigit(row));
	do{
		cout<<"How many columns do the matrices have?\n";
		cin>>col;
	}while(!isdigit(col));
	
	int R=static_cast<int>(row)-48;
	int C=static_cast<int>(col)-48;
	
	int m1[R][C],m2[R][C],m3[R][C],num;
	char input;
	
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			do{
				cout<<"For the first matrix, what value is in row "<<i+1<<", column "<<j+1<<endl;
				cin>>input;
			}while(!isdigit(input));

			num=static_cast<int>(input)-48;
			m1[i][j]=num;
		}
	}

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			do{
				cout<<"For the second matrix, what value is in row "<<i+1<<", column "<<j+1<<endl;
				cin>>input;
			}while(!isdigit(input));

			num=static_cast<int>(input)-48;
			m2[i][j]=num;
		}
	}

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			m3[i][j]=m1[i][j]+m2[i][j];
		}
	}

	cout<<"Matrix 1: \n";
					
	for(int i=0;i<R;i++)
	{
		cout<<"[";
		for(int j=0;j<C;j++)
		{
			cout<<" "<<m1[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}

	cout<<"plus\nMatrix 2: \n";
					
	for(int i=0;i<R;i++)
	{
		cout<<"[";
		for(int j=0;j<C;j++)
		{
			cout<<" "<<m2[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}

	cout<<"is\nMatrix 3: \n";
					
	for(int i=0;i<R;i++)
	{
		cout<<"[";
		for(int j=0;j<C;j++)
		{
			cout<<" "<<m3[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}
}

void subMatrix()
{
	char col,row;
	do{
		cout<<"How many rows do the matrices have?\n";
		cin>>row;
	}while(!isdigit(row));
	do{
		cout<<"How many columns do the matrices have?\n";
		cin>>col;
	}while(!isdigit(col));

	int C=static_cast<int>(col)-48;
	int R=static_cast<int>(row)-48;

	int m1[R][C],m2[R][C],m3[R][C],num;
	char input;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			do{
				cout<<"For the first matrix, what value is in row "<<i+1<<", column "<<j+1<<endl;
				cin>>input;
			}while(!isdigit(input));

			num=static_cast<int>(input)-48;
			m1[i][j]=num;
		}
	}

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			do{
				cout<<"For the second matrix, what value is in row "<<i+1<<", column "<<j+1<<endl;
				cin>>input;
			}while(!isdigit(input));

			num=static_cast<int>(input)-48;
			m2[i][j]=num;
		}
	}

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			m3[i][j]=m1[i][j]-m2[i][j];
		}
	}

	cout<<"Matrix 1: \n";
					
	for(int i=0;i<R;i++)
	{
		cout<<"[";
		for(int j=0;j<C;j++)
		{
			cout<<" "<<m1[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}

	cout<<"minus\nMatrix 2: \n";
					
	for(int i=0;i<R;i++)
	{
		cout<<"[";
		for(int j=0;j<C;j++)
		{
			cout<<" "<<m2[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}

	cout<<"is\nMatrix 3: \n";
					
	for(int i=0;i<R;i++)
	{
		cout<<"[";
		for(int j=0;j<C;j++)
		{
			cout<<" "<<m3[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}
}

void multiScalar()
{
	char col,row;
	do{
		cout<<"How many rows does the matrix have?\n";
		cin>>row;
	}while(!isdigit(row));
	do{
		cout<<"How many columns does the matrix have?\n";
		cin>>col;
	}while(!isdigit(col));

	int C=static_cast<int>(col)-48;
	int R=static_cast<int>(row)-48;

	int m1[R][C],m2[R][C],num,scalar;
	char input,s;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			do{
				cout<<"For the matrix, what value is in row "<<i+1<<", column "<<j+1<<endl;
				cin>>input;
			}while(!isdigit(input));

			num=static_cast<int>(input)-48;
			m1[i][j]=num;
		}
	}

	do{
		cout<<"What is the value of the scalar?\n";
		cin>>s;
	}while(!isdigit(s));

	scalar=static_cast<int>(s)-48;
	
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			m2[i][j]=m1[i][j]*scalar;
		}
	}

	cout<<"The matrix:\n";

	for(int i=0;i<R;i++)
	{
		cout<<"[";
		for(int j=0;j<C;j++)
		{
			cout<<" "<<m1[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}

	cout<<"multiplied by "<<scalar<<"\nis Matrix 2: \n";
					
	for(int i=0;i<R;i++)
	{
		cout<<"[";
		for(int j=0;j<C;j++)
		{
			cout<<" "<<m2[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}
}

void multiMatrix()
{
	int C1,R1,C2,R2;
	int test=1;
	char row,col;

	do{
		do{
			cout<<"How many rows does the first matrix have?\n";
			cin>>row;
		}while(!isdigit(row));
		R1=static_cast<int>(row)-48;
		do{
			cout<<"How many columns does the first matrix have?\n";
			cin>>C1;
		}while(!isdigit(col));
		C1=static_cast<int>(col)-48;
		do{
			cout<<"How many rows does the first matrix have?\n";
			cin>>row;
		}while(!isdigit(row));
		R2=static_cast<int>(row)-48;
		do{
			cout<<"How many columns does the first matrix have?\n";
			cin>>C1;
		}while(!isdigit(col));
		C2=static_cast<int>(col)-48;

		if(C1==R2)
		{
			test++;
		}
		else
		{
			cout<<"Matrices sizes are incompatible. Please try again.\n";
			test=1;
		}
	}while(test==1);
	
	int m1[R1][C1],m2[R2][C2],m3[R1][C2], num;
	char input;
	for(int i=0;i<R1;i++)
	{
		for(int j=0;j<C1;j++)
		{
			do{
				cout<<"For the first matrix, what value is in row "<<i+1<<", column "<<j+1<<endl;
				cin>>input;
			}while(!isdigit(input));

			num=static_cast<int>(input)-48;
			m1[i][j]=num;
		}
	}

	for(int i=0;i<R2;i++)
	{
		for(int j=0;j<C2;j++)
		{
			do{
				cout<<"For the second matrix, what value is in row "<<i+1<<", column "<<j+1<<endl;
				cin>>input;
			}while(!isdigit(input));

			num=static_cast<int>(input)-48;
			m2[i][j]=num;
		}
	}

	for(int i=0;i<R1;i++)
	{
		for(int j=0;j<C2;j++)
		{
			m3[i][j]=0;
		}
	}
	
	for(int i=0;i<R1;i++)
	{
		for(int j=0;j<C2;j++)
		{
			for(int m=0;m<R2;m++)
			{
				m3[i][j]+=m1[i][m]*m2[m][j];
			}
		}
	}

	cout<<"Matrix 1: \n";
					
	for(int i=0;i<R1;i++)
	{
		cout<<"[";
		for(int j=0;j<C1;j++)
		{
			cout<<" "<<m1[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}

	cout<<"multiplied by\nMatrix 2: \n";
					
	for(int i=0;i<R2;i++)
	{
		cout<<"[";
		for(int j=0;j<C2;j++)
		{
			cout<<" "<<m2[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}

	cout<<"is\nMatrix 3: \n";
					
	for(int i=0;i<R1;i++)
	{
		cout<<"[";
		for(int j=0;j<C2;j++)
		{
			cout<<" "<<m3[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}

}
