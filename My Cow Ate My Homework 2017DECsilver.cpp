#include<bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int a[N];
int mn[N];
int pre[N];
double ans[N];

int gi(){
  int ans=0,f=1;char i=getchar();
  while(i<'0'||i>'9'){if(i=='-')f=-1;i=getchar();}
  while(i>='0'&&i<='9'){ans=ans*10+i-'0';i=getchar();}
  return ans*f;
}

int main(){
  n=gi(); double ave = 0 , mx;
  memset(mn,127,sizeof(mn));
  for(int i=1;i<=n;i++) a[i]=gi(),pre[i]=pre[i-1]+a[i];
  for(int i=n;i>=1;i--) mn[i]=min(mn[i+1],a[i]);
  for(int i=1;i<n;i++){
    if(ave<=(pre[n]-pre[i]-mn[i+1])*1.0/(n-i-1)){
      ave=(pre[n]-pre[i]-mn[i+1])*1.0/(n-i-1);
      mx=ave; ans[i]=ave;
    }
  }
  for(int i=1;i<=n;i++)
    if(ans[i]==mx) printf("%d\n",i);
  return 0;
}
