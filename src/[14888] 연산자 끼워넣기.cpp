#include <iostream>
using namespace std;

int op[4];              // 연산 부호의 개수를 저장
int n;  int num[100];   // 항의 개수와 항을 저장

int maxx = -1000000001, minn = 1000000001; // 정답으로 나올 최대값, 최소값 저장

int cal(int a, int b, int op); // a와 b를 입력된 연산자로 계산해주는 함수

void f(int ind, int res)
{
    // 종료 조건 :
    // 마지막 항에 도달 시, 최대값/최소값을 최신화 해준다.
    if(ind == n-1){
        if(maxx < res) maxx = res;
        if(minn > res) minn = res;
    }

    // 각 연산자들을 한번씩 계산해봄.
    for(int i=0; i<4; i++)
    {
        if(op[i]>0) // 연산자가 하나 이상 남아있을 것.
        {
            op[i]--; // 해당 연산자를 하나 제거해준다.
            f(ind+1, cal(res, num[ind+1], i)); // 계산 후 다음 항으로 넘겨준다.
            op[i]++; // 계산이 끝났으니 다시 연산자를 추가해준다.
        }

    }

}

int main()
{

    cin >> n;                               // 숫자 개수
    for(int i=0; i<n; i++) cin >> num[i];   // 숫자
    for(int i=0; i<4; i++) cin >> op[i];    // 연산자 개수

    f(0, num[0]); // 연산 시작

    cout << maxx << "\n" << minn;

    return 0;
}

// 연산자를 적용하는 함수
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