#include<iostream>
using namespace std;
int MaxSum(int n,int *a)
{
	int sum=0;
	int b=0,i;
	for(i=1;i<=n;i++){
		if(b>0) b+=a[i];
		else b=a[i];
		if(b>sum) sum=b;
	}
	return sum;
}
int MaxSum2(int m,int n,int ** a)
{
	int sum=0,i,j,k;
	int *b=new int[n+1];
	for(i=1;i<=m;i++){
		for(k=1;k<=n;k++) b[k]=0;
		for(j=i;j<=m;j++){
			for(k=1;k<=n;k++) b[k]+=a[j][k];
			int max=MaxSum(n,b);
			if(max>sum) sum=max;
		}
	}
	return sum;
}
int MaxSum3(int m,int n,int p,int ***a)
{
	int sum=0,i,j,k,l;
	int **c=new int*[n+1];
	for(i=1;i<=n;i++)
	c[i]=new int[p+1];
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)
		for(k=1;k<=p;k++)
		c[j][k]=0;
		for(l=i;l<=m;l++){
			for(j=1;j<=n;j++)
			for(k=1;k<=p;k++)
			c[j][k]+=a[l][j][k];
			int max=MaxSum2(n,p,c);
			if(max>sum) sum=max;
		}
	}
	return sum;
}
int main()
{
	int sum,m,n,p,i,j,k,***a;
	scanf("%d%d%d",&m,&n,&p);
	a=(int***)malloc((m+1)*sizeof(int**));
	for(i=1;i<=m;i++)
	a[i]=(int**)malloc((n+1)*sizeof(int*));
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	a[i][j]=(int*)malloc((p+1)*sizeof(int));
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	for(k=1;k<=p;k++)
	scanf("%d",&a[i][j][k]);
	sum=MaxSum3(m,n,p,a);
	cout<<sum<<endl;
	return 0;
}