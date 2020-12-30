#include <iostream>

using namespace std;

char n1[105], n2[105];
int rn1[105], rn2[105], ln1, ln2;

bool SwapNumNeeded(const char *s1, int size1, const char *s2, int size2)
{
    if (size1 < size2) {
        return true;
    } else if (size1 > size2) {
        return false;
    } else {
        for (int i = 0; i < size1; i++) {
            if (s1[i] < s2[i]) {
                return true;
            } else if(s1[i] > s2[i]){
                return false;
            }
        }
    }
    return false;
}

void printc(int *n, int size)
{
    for (int i = 0; i <= size; i++) {
        cout << *n++;
    }
    cout << endl;
}

bool equals(const char *s1, int len1, const char *s2, int len2)
{
    if (len1 != len2) return false;
    for (int i = 0; i < len1; i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> ln1 >> ln2;
    cin >> n1 >> n2;

    bool negetive = false;
    char *pn1, *pn2;
    pn1 = n1;
    pn2 = n2;
    if (equals(n1, ln1, n2, ln2)) {
        cout << 0 << endl;
        return 0;
    }
    if (SwapNumNeeded(n1, ln1, n2, ln2)) {
        pn1 = n2;
        pn2 = n1;

        int temp = ln1;
        ln1 = ln2;
        ln2 = temp;
        negetive = true;
    }


    rn1[0] = ln1;
    rn2[0] = ln2;

    for (int i = ln1 - 1, j = 1; i >= 0; i--, j++) {
        rn1[j] = pn1[i] - '0';
    }

    for (int i = ln2 - 1, j = 1; i >= 0; i--, j++) {
        rn2[j] = pn2[i] - '0';
    }

//    printc(rn1, ln1);
//    printc(rn2, ln2);


//    cout << pn1 << endl;
//    cout << pn2 << endl;
//    printc(rn1, rn1[0]);
//    printc(rn2, rn2[0]);

    for (int i = 1; i <= rn1[0]; i++) {
        if (rn1[i] < rn2[i]) {
            rn1[i + 1]--;
            rn1[i] += 10;
        }
        rn1[i] -= rn2[i];
        if (i == rn1[0] && rn1[i] == 0) {
            rn1[0]--;
        }
    }


    if (negetive) cout << "-";
    for (int i = rn1[0]; i >= 1; i--) {
        static bool firstZero = true;
        if (rn1[i] == 0 && firstZero) {
            continue;
        } else {
            firstZero = false;
        }
        cout << rn1[i];
    }
    cout << endl;

    return 0;
}
