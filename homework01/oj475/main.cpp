#include <iostream>
#include <cstring>

using namespace std;

char cn[1005], cm[1005];
int rn[1005], rm[1005];

int ans[1005];
int tmp[1005];

bool smallerthen(const int *n1, const int *n2)
{
    int size1 = *n1;
    int size2 = *n2;
    if (size1 < size2) return true;
    if (size1 > size2) return false;
    if (size1 == size2) {
        for (int i = 1; i <= size1; i++) {
            if (*(n1 + i) > *(n2 + i)) {
                return false;
            } else if (*(n1 + i) < *(n2 + i)){
                return true;
            }
        }
    }
    return true;
}

void minusNum(int *tmp, int *n)
{
    // tmp must be greater then n
    int tlen = *tmp;
    int nlen = *n;
    // 3 221
    // 3 112
    for (int i = nlen; i >= 1; i--) {
        if (tmp[i] < n[i]) {
            tmp[i] += 10;
            tmp[i - 1] -= 1;
        }
        tmp[i] -= n[i];
    }

    bool isFirstZero = true;
    int len = tmp[0];
    for (int i = 1; i <= len; i++) {
        if (isFirstZero && tmp[i] == 0) {
            tmp[0]--;
        } else if (tmp[i] != 0) {
            isFirstZero = false;
        }
    }

    for (int i = 1; i <= tmp[0]; i++) {
        tmp[i] = tmp[len - tmp[0] + i];
    }
}


void printc(int *n, int size)
{
    for (int i = 0; i <= size; i++) {
        cout << *n++;
    }
    cout << endl;
}

int main()
{
    cin >> cn >> cm;
    int ln = 0, lm = 0;
    ln = strlen(cn);
    lm = strlen(cm);

    if (ln > lm) {
        cout << 0 << endl;
        return 0;
    }

    rn[0] = ln;
    rm[0] = lm;

    for (int i = 0; i < ln; i++) {
        rn[i + 1] = cn[i] - '0';
    }

    for (int i = 0; i < lm; i++) {
        rm[i + 1] = cm[i] - '0';
    }

    // rn is the 分子， rm is the 分母
    // 1. 依次从分母里取值，放入tmp中
    // 2. 判断tmp里的数据是几倍的rn, 如果小于rn, 则回到1，继续向tmp中加数据
    // 3. 如果大于rn, 则让rn从1，2，3依次相乘，大于tmp中的index， 然后把得到的值放入ans中，更新ans[0]
    // 4. 直到取完rm中的数

    int curIndex = 1;
    int curmIndex = 1;
    int curAnsIndex = 1;

    bool firstZero = true;
    while (curmIndex <= lm) {
        //printc(tmp, tmp[0]);
        tmp[0]++;
        tmp[tmp[0]] = rm[curmIndex++];
        cout << "curmIndex:" << curmIndex << endl;
        int curDivideValue = 0;
        printc(tmp, tmp[0]);
        while (smallerthen(rn, tmp)) {
            // tmp - rn 直到rn > tmp
            cout << "minus before:";
            printc(tmp, tmp[0]);
            minusNum(tmp, rn);
            cout << "minus after:";
            printc(tmp, tmp[0]);
           // cout << endl;
            curDivideValue++;
        }
        cout << "curDivide Value:" << curDivideValue << endl;

        if (curDivideValue == 0 && firstZero) {
            continue;
        } else if (curDivideValue != 0) {
            firstZero = false;
        }
        ans[0]++;
        ans[curAnsIndex++] = curDivideValue;
    }


    for (int i = 1; i <= ans[0]; i++) {
        cout << ans[i];
    }
    cout << endl;



    return 0;
}
