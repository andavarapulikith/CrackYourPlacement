void countsort(int arr[],int n,int pos){
    vector<int>count(10,0);
    for(int i=0;i<n;i++){
        count[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++)
    count[i]=count[i]+count[i-1];
    vector<int>b(n,0);
    for(int i=n-1;i>=0;i--){
        b[--count[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++)
    arr[i]=b[i];
    
}

void radixSort(int arr[], int n) 
{ 
   // code here
   int maxi=INT_MIN;
   for(int i=0;i<n;i++)
   maxi=max(maxi,arr[i]);
   for(int pos=1;maxi/pos>0;pos=pos*10){
       countsort(arr,n,pos);
   }
} 