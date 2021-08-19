#include <iostream>
#include <queue>
using namespace std;

struct cmp{
   bool operator()(int x, int y){
      if(abs(x) == abs(y))
         return x > y;
      else
         return abs(x) > abs(y);
   }
};
int main(){
   priority_queue<int, vector<int>, cmp> pq;
   int n;
   int x;
   scanf("%d", &n);
   for(int i=0;i<n;i++){
      scanf("%d", &x);
      if(x!=0){
         pq.push(x);
      }
      if(x==0){
         if(pq.empty()){
            printf("0\n");
            continue;
         }
         printf("%d\n", pq.top());
         pq.pop();
      }
   }
}