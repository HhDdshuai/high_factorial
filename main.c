#include <stdio.h>
#include <stdlib.h>
#define width 3000

int main()
{
    int k,r,t,n;
    int d[width];

    while(scanf("%d",&n) != EOF){
        t = 0;
        for(int i = 0;i < width;i++)             //�������λ��ʼ��Ϊ��
            d[i] = 0;
        d[0] = 1;                                //��λ���Ի�Ϊ1
        for(int i = 1;i <= n;i++){               //��1�˵�n
            k = 0;                               //Ϊ�����λ����λ
            for(int j = 0;j <= t;j++){
                r = (d[j] * i + k)/10;           //��jλ����i���Ϻ�һλ����úõ�k���ٳ���10�õ��µ�kֵ
                d[j] = (d[j] * i + k)%10;        //��jλ��ֵ
                k = r;                           //����kֵ
            }
            while(k != 0){                       //k��Ϊ���ʾ��Ҫ���λ��λ
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
