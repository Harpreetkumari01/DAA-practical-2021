#include<iostream>
using namespace std;

class edge
{
	public:
	int v1;
	int v2;
	int w;	
};

class node
{
	public:
	int ele;
	node *next;
	node()
	{
		next=NULL;	
	}
		
};

class list
{
	public:
	node *head;
	node *tail;
	list()
	{
		head=tail=0;
	}	
};

node *vlist;   
list *comp;
void create_comp(int v)
{
	comp=new list[v+1];
	for(int i=1;i<=v;i++)
	{
		comp[i].head=comp[i].tail=&vlist[i];
	}
}

void sort(edge *E,int e)
{
	int j;
	edge temp;
	for(int i=2;i<=e;i++)         
	{
		j=i-1;
		temp=E[i];
		while(j>0&&E[j].w>temp.w)
		{
			E[j+1].v1=E[j].v1;
			E[j+1].v2=E[j].v2;
			E[j+1].w=E[j].w;
			j--;
		}
		E[j+1]=temp;
	}
}

void kruskel(edge *E,int e,int v)
{
	node* h2;
	create_comp(v);  
	sort(E,e);
	cout<<"\nselected edges are: ";
	for(int i=1;i<=e;i++)
	{	
		if((comp[E[i].v1].head!=comp[E[i].v2].head)&&(comp[E[i].v1].tail!=comp[E[i].v2].tail)) 
		{  
			h2=comp[E[i].v2].head;
		
			comp[E[i].v1].tail->next=h2;            
			comp[E[i].v1].tail=comp[E[i].v2].tail;
			
			while(h2!=NULL)                    
			{
				comp[h2->ele]=comp[E[i].v1];
				h2=h2->next;
			}
			
			cout<<"("<<E[i].v1<<" , "<<E[i].v2<<") ";
		}
	}
}

int main()
{
	edge *E;  
	int v,e;  
	cout<<"\nenter no. of vertices: ";
	cin>>v;
	cout<<"\nenter no. of edges: ";
	cin>>e;
	vlist=new node[v+1];
	for(int i=1;i<=v;i++)     
	{
		vlist[i].ele=i;
	}
	E = new edge[e+1];
	cout<<"\nenter edges in format v1 v2 and weight";
	for(int i=1;i<=e;i++)
	{
		cout<<"\nenter edge no"<<i<<": ";
		cin>>E[i].v1>>E[i].v2>>E[i].w;
	}
	kruskel(E,e,v);
}
