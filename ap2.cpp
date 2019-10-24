#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
	int n,max_item_id=0,i,j,t1,k,l,m,f,f1,f2,f3;
	cout<<"Please enter no of Transactions :-\n";
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	{
		int x;
		cout<<"\n Enter no of items from purchase "<<i+1<<":\n";
		cin>>x;
		arr[i]=x;
		cout<<"\n Enter items from purchase "<<i+1<<":\n";
		for(j=0;j<x;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>max_item_id)
				max_item_id=a[i][j];
		}
	}
	int min;
	cout<<"\n Enter minimum acceptance level\n";
	cin>>min;
	cout<<"\nInitial Input:\n";
	cout<<"\nTrasaction\tItems\n";
	for(i=0;i<n;i++)
	{
		cout<<i+1<<":\t\t";
		for(j=0;j<arr[i];j++)
        {
            if(a[i][j]>=min)
                cout<<a[i][j]<<" FREQUENT ITEM SET"<<"\t";
            cout<<a[i][j]<<"\t";
        }
		cout<<"\n";
	}
	cout<<"\nAssume minimum support: "<<min;
	int l1[max_item_id];
	for(i=0;i<max_item_id;i++)
	{
		t1=0;
		for(j=0;j<n;j++)
			for(k=0;k<arr[j];k++)
				if(a[j][k]==i+1)
					t1++;
		l1[i]=t1;
	}
	cout<<"\n\nGenerating C1 from data\n";
	for(i=0;i<max_item_id;i++)
		cout<<i+1<<": "<<l1[i]<<"\n";
	int p2pcount=0;
	int p2items[max_item_id];
	int p2pos=0;
	for(i=0;i<max_item_id;i++)
	{
		if(l1[i]>=min)
		{
			p2pcount++;
			p2items[p2pos]=i;
			p2pos++;
		}
	}
	int y=(p2pcount*(p2pcount-1))/2;
	cout<<"\nGenerating L1 From C1\n";
	for(i=0;i<p2pos;i++)
		cout<<p2items[i]+1<<"\t"<<l1[p2items[i]]<<"\n";
	int l2[y][3];
	int l2t1;
	int l2t2;
	int l2pos1=0;
	int l2ocount=0;
	int l2jcount=0;
	for(i=0;i<p2pcount;i++)
	{
		for(j=i+1;j<p2pcount;j++)
		{
			l2t1=p2items[i]+1;
			l2t2=p2items[j]+1;
			if(l2t1!=l2t2)
			{
				l2[l2pos1][0]=l2t1;
				l2[l2pos1][1]=l2t2;
				l2jcount++;
				l2ocount=0;
				for(k=0;k<n;k++)
				{
					f1=f2=0;
					for(l=0;l<arr[k];l++)
					{
						if(l2t1==a[k][l])
							f1=1;
						if(l2t2==a[k][l])
							f2=1;
					}
					if(f1==1&&f2==1)
						l2ocount++;
				}
				l2[l2pos1][2]=l2ocount;
				l2pos1++;
			}
		}
	}
	cout<<"\n\nGenerating L2\n";
	for(i=0;i<l2jcount;i++)
	{
		for(j=0;j<3;j++)
			cout<<l2[i][j]<<"\t";
		cout<<"\n";
	}
	int p3pcount=0;
	int p3items[y]; //={-1,-1,-1,-1,-1};
	memset(p3items,-1,y*sizeof(int));
	int p3pos=0;
	for(i=0;i<y;i++)
	{
		if(l2[i][2]>=min)
		{
			f=0;
			for(j=0;j<y;j++)
			{
				if(p3items[j]==l2[i][0])
					f=1;
			}
			if(f!=1)
			{
				p3items[p3pos]=l2[i][0];
				p3pos++;
				p3pcount++;
			}
			f=0;
			for(j=0;j<y;j++)
				if(p3items[j]==l2[i][1])
					f=1;
			if(f!=1)
			{
				p3items[p3pos]=l2[i][1];
				p3pos++;
				p3pcount++;
			}
		}
	}
	int z=(p3pcount*(p3pcount-1))/2;
	int l3[100][4];
	int l3ocount=0;
	int l3jcount=0;
	for(i=0;i<p3pcount;i++)
	{
		for(j=i+1;j<p3pcount;j++)
		{
			for(k=j+1;k<p3pcount;k++)
			{
				l3[i][0]=p3items[i];
				l3[i][1]=p3items[j];
				l3[i][2]=p3items[k];
				l3jcount++;
				l3ocount=0;
				for(k=0;k<n;k++)
				{
					f1=f2=f3=0;
					for(l=0;l<arr[k];l++)
					{
						if(l3[i][0]==a[k][l])
							f1=1;
						if(l3[i][1]==a[k][l])
							f2=1;
						if(l3[i][2]==a[k][l])
							f3=1;
					}
					if(f1==1&&f2==1&&f3==1)
						l3ocount++;
				}
				l3[i][3]=l3ocount;
			}
		}
	}
	cout<<"\n\nGenerating L3\n";
	for(i=0;i<l3jcount;i++)
	{
		for(j=0;j<=min;j++)
			cout<<l3[i][j]<<"\t";
		cout<<"\n";
	}
	return 0;
}
