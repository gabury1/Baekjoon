#include <iostream>
using namespace std;

int op[4];
int n;  int num[100];

int maxx = -1000000001, minn = 1000000001;

int cal(int a, int b, int op)
{
    switch (op)
    {
    case 0:
        return a+b;
        break;

    case 1:
        return a-b;
        break;

    case 2:
        return a*b;
        break;

    case 3:
        return a/b;
        break;
    
    default:
        break;
    }

}

void f(int ind, int res)
{
    if(ind == n-1){
        if(maxx < res) maxx = res;
        if(minn > res) minn = res;
    }

    for(int i=0; i<4; i++)
    {
        if(op[i]>0)
        {
            op[i]--;
            f(ind+1, cal(res, num[ind+1], i));
            op[i]++;
        }

    }

}

int main()
{

    cin >> n;                               // 숫자 개수
    for(int i=0; i<n; i++) cin >> num[i];   // 숫자
    for(int i=0; i<4; i++) cin >> op[i];    // 연산자 개수

    f(0, num[0]);

    cout << maxx << "\n" << minn;

    return 0;
}