#include <iostream>
#include <cstring>
using namespace std;
int nextval[10005];
void get_nextval(char T[100005])
{
	int i=1,j=0,n; nextval[1]=0;
   	n=strlen(T);
	while(i<n)
	{
		if(j==0||T[i]==T[j])
		{
			++i;++j;
		
			if(T[i]!=T[j])
				nextval[i]=j;
		   else nextval[i]=nextval[j];
		}
	else j=nextval[j];
	}
}
int index(char S[100005],char T[100005],int pos)
{
	int i=pos,j=0,ns,nt;
	ns=strlen(S);
	nt=strlen(T);
	while(i<ns&&j<nt)
	{
		if(j==0||S[i]==T[j])
		{
			++i;++j;
		}
		else j=nextval[j];
	}
	if(j>=nt)
		return i-nt;
	else
		return -1;
}
int main()
{
	int f,count,pos,result;
	char W[100005],T[100005];
    scanf("%d",&f);
	for(count=1;count<=f;count++)
	{
		result=0;pos=0;
		scanf("%s",W);
		scanf("%s",T);
		get_nextval(W);
        while(pos=index(T,W,pos)+1)
		{

			result++;	
		}
	printf("%d\n",result);
	}
	return 0;
}

