#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int M=(1<<25);
int ST[M],top=-1;
void buildtree(int N,long long &tree_count);

int main() {
	int n;

	long long e = 0;
	printf("请输入结点个数："); 
	scanf("%d",&n);
	buildtree(n,e);
	printf("\ntree_count is %lld when N is %d\n",e,n);

	return 0;
}

void buildtree(int N,long long &tree_count)
{
	int arr[32],pos[32];
	int idx = 1;

	arr[idx++] = 1;
	pos[1] = 1;
	ST[++top] = 2;
	ST[++top] = 3;
	while(idx > 0){
		int now = ST[top];
		if(idx == N){
			top--;
			while(arr[idx-1] < now){
				tree_count++;
				printf("  %lld:",tree_count);
				for(int i = 1;i < idx;i++)
					printf("%d,",arr[i]);
				printf("%d\n",now);
				now = ST[top];
				top--;
			}
			top++;
			idx--;
			continue;
		}
		if(arr[idx - 1] < now){
			top--;
			arr[idx] = now;
			pos[idx] = pos[idx-1];
			for(int i = pos[idx];i <= idx;i++){
				if(arr[i]*2+1<arr[idx])
				{
					pos[idx] = i;
					continue;
				}
				if(arr[i]*2 > arr[idx])
					ST[++top] = arr[i]*2;
				if(arr[i]*2+1 > arr[idx])
					ST[++top] = arr[i]*2 + 1;
			}
			idx++;
		}
		else idx--;
	}
}