/* 递归算法，求在给定二叉树结点总数 N 的情况下，二叉树可能拥有的形状数 M。*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 105
int a[MAXSIZE];
void arrange(int arr[],int idx,int n,long long &tree_count,long long &height);

int main() 
{
	int n;

	printf("请输入结点个数：");
	scanf("%d",&n);
	long long count = 0,H = 0;
	a[0] = 1;
	arrange(a,1,n,count,H);
	printf("\ntree_count is %lld when N is %d\n\n",count,n);
	long long t = 1;
	for(int i = n+1;i <= n*2;i++) 
		t = 1ll*i*t;
	for(int i = 1;i<=n+1;i++) 
		t = t / (1ll*i);
	printf("count = %lld , Catalan = %lld \n\n",count,t);
	printf("average_Height = %.6lf\n\n",H*1.0/count);
	printf("(log2(N)+N)/2 = %.6lf\n\n",(log2(n)+n)*1.0/2);

	return 0;
}

void arrange(int arr[],int idx,int n,long long &tree_count,long long &height)
{
	if(idx == n){
		int w = 1;

		tree_count++;
		printf("   %lld:",tree_count);
		printf("%d",arr[0]);
		for(int i = 1;i <= n - 1;i++){
			if(arr[i] >= arr[i-1]*2) 
				w++; 
			printf(",%d",arr[i]);
		}
		printf("\n");
		height += w;
		return ; 
	}
    int t = arr[idx-1];
	for(int i = idx-1;i >= 0;i--){
		if(arr[i]*2+1 < t) 
			break;
		if(arr[i]*2>t){ 
			arr[idx] = arr[i]*2;
			arrange(arr,idx+1,n,tree_count,height);
		}
		if(arr[i]*2 + 1 > t){ 
			arr[idx] = arr[i]*2 + 1;
			arrange(arr,idx + 1,n,tree_count,height);
		}
	}
	
} 