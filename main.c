#include <stdio.h>
#include <stdlib.h>
#define width 3000

int main()
{
    int k,r,t,n;
    int d[width];

    while(scanf("%d",&n) != EOF){
        t = 0;
        for(int i = 0;i < width;i++)             //将数组各位初始化为零
            d[i] = 0;
        d[0] = 1;                                //各位初试化为1
        for(int i = 1;i <= n;i++){               //从1乘到n
            k = 0;                               //为需向高位进的位
            for(int j = 0;j <= t;j++){
                r = (d[j] * i + k)/10;           //第j位乘以i加上后一位运算得好的k，再除以10得到新的k值
                d[j] = (d[j] * i + k)%10;        //第j位的值
                k = r;                           //更新k值
            }
            while(k != 0){                       //k不为零表示需要向高位进位
                d[++t] = k % 10;
                k /= 10;
            }
        }
        for(int i = t;i >= 0;i--)
            printf("%d",d[i]);
        printf("\n");
    }
    return 0;
}
