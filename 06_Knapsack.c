//06_Knapsack.c
#include<stdio.h>
#define MAX_N 20
#define MAX_W 100
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[MAX_N+1][MAX_W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   return K[n][W];
}
int main()
{
    int i, n, val[MAX_N], wt[MAX_N], W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter value and weight of items:\n");
    for(i = 0;i < n; ++i){
     scanf("%d%d", &val[i], &wt[i]);
    }
    printf("Enter size of knapsack: ");
    scanf("%d", &W);
    printf("%d\n", knapSack(W, wt, val, n));
    return 0;
}
