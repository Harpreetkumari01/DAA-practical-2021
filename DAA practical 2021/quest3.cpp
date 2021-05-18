#include<iostream>
using namespace std;
void Enter(int Arr[], int s);
void display(int Arr[], int s);
void isort(int Arr[], int s);
void ssort(int Arr[], int s);
void bsort(int Arr[],int s);
void msort(int Arr[],int left,int right );
void qsort(int Arr[],int s,int );
int main()
{
	int Arr[100],n,choice;
	cout<<"Enter Size of Array ";
	cin>>n;
	do
	{
		cout<<"\n\nMENU";
		cout<<"\n1. Enter elements of array";
		cout<<"\n2. Display elements of array";
		cout<<"\n3. Sort the array using insertion sort method";
		cout<<"\n4. Sort the array using selection sort method";
		cout<<"\n5. Sort the array using bubble sort method";
		cout<<"\n6. sort the array using merge sort method";
		cout<<"\n7. sort the array using quick sort method";
		cout<<"\n8. Exit";
		cout<<"\n\nEnter your choice 1-8 :";
		cin>>choice;
		switch(choice)
		{
			case 1:	Enter(Arr,n);
				break;
			case 2:	display(Arr,n);
				break;
			case 3:	isort(Arr,n);
				break;
			case 4:	ssort(Arr,n);
				break;
			case 5:	bsort(Arr,n);
				break;
			case 6:msort(Arr,n,n-1);
			    break;
			case 7:qsort(Arr,n,n-1);    
			case 8:	break;
			default:cout<<"\nInvalid choice";
		}
	}while(choice!=8);
	return 0;
}
void Enter(int Arr[], int s)
{
	for(int I=0;I<s;I++)
	{
		cout<<"Enter element "<<I+1<<":";
		cin>>Arr[I];
	}
}
void display(int Arr[], int s)
{
	cout<<"The elements of the array are:\n";
	for(int I=0;I<s;I++)
		cout<<Arr[I]<<" ";
}
void isort(int Arr[], int s)
{
	int I,J,Temp;
	for(I=1;I<s;I++)
	{
		Temp=Arr[I];
		J=I-1;
		while((Temp<Arr[J]) && (J>=0))
		{
			Arr[J+1]=Arr[J];
			J--;
		}
		Arr[J+1]=Temp;
	}
}
void ssort(int Arr[], int s)
{
	int I,J,Temp,Small;
	for(I=0;I<s-1;I++)
	{
		Small=I;
		for(J=I+1;J<s;J++) 	
		if(Arr[J]<Arr[Small])
			Small=J;
		if(Small!=I)
		{
			Temp=Arr[I]; 		//Swapping
			Arr[I]=Arr[Small];
			Arr[Small]=Temp;
		}
	}
}
void bsort(int Arr[],int s)
{
	int I,J,Temp;
	for(I=0;I<s-1;I++)
	{
		for(J=0;J<(s-1-I);J++)
			if(Arr[J]>Arr[J+1])
			{
				Temp=Arr[J]; 	//swapping
				Arr[J]=Arr[J+1];
				Arr[J+1]=Temp;
			}
	}
}
int partition(int arr[], int left, int right) 
{
    int pivot = arr[right];
    cout<<"\npivot element: "<<pivot;
    int i = left - 1;

    for (int j = left; j < right; j++) 
	{
      if (arr[j] <= pivot) 
	  {
        i++;
		swap(arr, i, j);
      }
      comp++;
    }
	swap(arr, i + 1, right);
	cout<<"\narray after swapping: ";
	for(int i=0;i<right;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\ncomparison="<<comp;
	return i + 1; // Return the pivot's final resting position
}

void qsort(int arr[], int left, int right) 
{
    if (left < right) 
	{
      int pivotFinalRestingPosition = partition(arr, left, right);

      quicksort(arr, left, pivotFinalRestingPosition - 1);
      quicksort(arr, pivotFinalRestingPosition + 1, right);
    }
}
void msort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
            comp++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
            comp++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
    cout<<"\n comparision: "<<comp;
    
}
