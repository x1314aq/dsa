//
// 多重背包问题
//

#include <bits/stdc++.h>
using namespace std;

int need[105];
int value[105];
int quanties[105];
int best[50005];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> need[i] >> value[i] >> quanties[i];

    for(int i = 1; i <= n; i++)
        for(int j = m; j >= need[i]; j--)
            for(int k = min(quanties[i], j / need[i]); k >= 0; k--)
                best[j] = max(best[j], best[j - k * need[i]] + value[i] * k);

    cout << best[m] << endl;
    return 0;
}

#if 0
#include <bits/stdc++.h>
using namespace std;
int dp[100000],q[100000],book[100000];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        //k表示物品体积，value表示物品价值，cnt表示物品数量
        int k,value,cnt;
        scanf("%d%d%d",&k,&value,&cnt);
        //ind表示背包放下最大可容个数后剩余容量，ind=m%k，所以ind是小于k的
        for(int ind=0;ind<k;ind++)
        {
            //头指针和尾指针
            int head=0,tail=0;
            //jnd表示能放几个物体，(m-ind)/k即表示能放得的最大物体数量
            for(int jnd=0;jnd<=(m-ind)/k;jnd++)
            {
                int y=dp[jnd*k+ind]-jnd*value;
                //printf("%d ",y);
                while(head<tail&&y>=q[tail-1])
                   tail--;
                book[tail]=jnd;
                q[tail++]=y;
                /*这是一个由大到小的单调队列，如果超出限制需要将队首出队，
                每次单调队列入队时都将当前元素放在队尾，它前面的元素数值肯定
                比他都大，且下标都小于它的下标。
                */
                if(book[head]<jnd-cnt)
                    head++;
                dp[jnd*k+ind]=q[head]+jnd*value;
                //printf("%d\n",dp[jnd*k+ind]);
            }
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}
#endif
