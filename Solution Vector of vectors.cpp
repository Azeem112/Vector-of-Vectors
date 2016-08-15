#include<iostream>
using namespace std;
#include<windows.h>
#include<cstring>

class VectorOfVectors
{
	int num;
	int size;
	int len;
	int *v;
	
	public:
		
	VectorOfVectors ()
		{
			num=0;
			size=0;
			len=0;
		}////////////////////////////
		
	VectorOfVectors (int x,int y)
		{
		v=new int [y];
		size=len=y;
		
			for (int loop=0; loop<10 ; loop++)
			v[loop]=x;
		}////////////////////////////
	
	VectorOfVectors (int x, int a[] , int z)
		{
		num =x;
		size=z;
		len=x*z;

		v = new int [x*z];
		
		int index=0;
		for(int loop=0 ; loop<len ; loop++)
			{
			v[loop]=a[index];
			if((loop)%size==0 && loop>=size)
			index++;
			}
		}////////////////////////////
		
	bool insert(int value , int num1 )		
	{
		int loop=num1*size-size;
		int end=num1*size-1;
		
		while(loop<=end)
		{
			if(v[loop]==-1)
			{
				v[loop]=value;
				return true;
			}
			loop++;
		}
		
		if (loop>end)
		{	
			int temp;
			temp=size+size/2;
			
			int *arr= new int [temp*num];
			
			for(int x=0 ; x<temp*num ; x++)
			arr[x]=-1;
			
			int temp2=num;
			for ( ; temp2>0 ; temp2--)
		{
			
			int index=temp2*temp-temp;
			
			for (int x=temp2*size-size ; x<=temp2*size-1 ; x++ )
			{
			arr[index]=v[x];
			index++;
			}
		}
			
			size=temp;
			len=size*num;
			
			v=arr;
			return false;
		}
	}////////////////////////////
	
	bool remove(int num1 , int index)
	{
		int loop=num1*size-size;
		
		if(v[loop+index+1]==-1)
		return false;
		
		else
		{
		v[loop+index+1]=-1;
		return true;
		}
	}////////////////////////////
	
	bool change(int num1 , int index , int newvalue)
	{
		int loop=num1*size-size;
		if(v[loop+index+1]==newvalue)
		return false;
		
		else
		{
			v[loop+index+1]=newvalue;
			return true;
		}
	}////////////////////////////
	
	void printall()
	{
		for(int x=0 ; x<len ; x++)
		{
			if( x%size==0 )
			cout<<endl<<v[x]<<"  ";
			
			else
			cout<<v[x]<<"  ";
		}
	}////////////////////////////
	
	bool get(int num1 , int index , int &value)
	{
		int loop=num1*size-size;
		
		loop+=index;
		value=v[loop];
	}////////////////////////////
	
	void removeofvectors(int x)
	{
		int z=0;
		int index;
		for(; z<= len ; z++)
		{
			if(v[z]==x)
			index = z;
			else
			continue;
		
		int temp=index;
		
		for(int y=0 ; y<index ; y++)
		if(index%size==0)
		break;
		else	index--;		/////Start at the current row;
		
		int vector=(index/size)+1;
		int loop=vector*size-1;		///////End at the current row
		
		for(int y=index ; y<=loop ; y++)	////// current row removed
		v[y]=-1;
		
		index=temp;
		
		while(index<len)
		index+=size;
		
		index-=size;	/////end at current column
		
		while(index>=0)
		{
			v[index]=-1;
			index-=size;
		}				////////// current column removed
		
		
		if(vector!=num)
		{
		vector++;
		for(int y=vector*size-size ; y<vector*size-1 ; y++)
		{v[y-size]=v[y];	v[y]=-1;		}//////// Shifting Row
		}
		
		if (temp!=vector*size-1)
		{
			temp++;
			
			while(temp<len && temp>=0)
		temp-=size;
		
		temp+=size;	/////Start at current column
		
			for(int y=temp; y<len ; y+=size)
			{v[temp-1]=v[temp];	v[temp]=-1;	}/////////// Shifting Column
		
			}
			z=0;	////Again searching and removing
			
		}
	
	}///////////////////// END OF KAHPU PROGRAME
	
		};

////////////////////////////////////////////////////////////////////////////////////

	int main()
	{
		int num,*a,size;
		cout<<"Enter number of vectors you want to enter: ";
		cin>>num;
		
		a = new int [num];
		for (int x=0 ; x< num ; x++)
		{
			cout<<"Enter value for vector"<<x+1<<"	";
			cin>>a[x];
		}
		
		cout<<"Enter size of vectors::   ";
		cin>>size;
		
		VectorOfVectors v(num , a , size);
		
		if(v.insert(4,2))
		cout<<endl<<"value inserted successflly";
		else
		cout<<endl<<"No space, vectors expanded successfully";
		
		if(v.remove(2,13))
		cout<<endl<<"Data removed successfully";
		else
		cout<<endl<<"Given space is empty, can't remove";
		
		if(v.change(2,3,6))
		cout<<endl<<"Data changed successfully";
		else
		cout<<endl<<"Can't change, Given data exists already";
		
		v.printall();
		
		int value;
		v.get(2,5,value);
		cout<<endl<<"Data at given index is "<<value;
		
		v.removeofvectors(6);
		
		v.printall();
		
		cout<<endl;
		char credit[]="Thanks for using VECTORS version 2.2 beta, Made by M.J ";
		
		cout<<endl<<endl;
		for(int y=0 ; y<strlen(credit) ; y++)
		{
		Sleep(150);
		cout<<credit[y];
		}
	}////////////////////////////
