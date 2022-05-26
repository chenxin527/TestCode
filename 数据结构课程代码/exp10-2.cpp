//文件名：exp10-2.cpp
#include "seqlist.cpp"				
void BinInsertSort(RecType R[],int n) 
{	int i, j, low, high, mid;
	RecType tmp;
	for (i=1;i<n;i++) 
	{
		if (R[i].key<R[i-1].key)		
		{	printf("  i=%d，插入%d，插入结果: ",i,R[i].key); 
			tmp=R[i];		  			
	     	low=0;  high=i-1;
			while (low<=high)	  		
			{
				mid=(low+high)/2;		
				if (tmp.key<R[mid].key)
					high=mid-1;			
				else 
					low=mid+1;	
			}                          	
			for (j=i-1;j>=high+1;j--)	
				R[j+1]=R[j];
			R[high+1]=tmp;				
		}
		DispList(R,n);
	} 
}

int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	CreateList(R,a,n);
	printf("排序前:"); DispList(R,n);
	BinInsertSort(R,n);
	printf("排序后:"); DispList(R,n);
	return 1;
}


