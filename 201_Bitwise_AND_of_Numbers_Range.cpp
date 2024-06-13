#include<bits/stdc++.h>
using namespace std;
int rangeBitwiseAnd(int left, int right) {

    int x = 0;
    int y = 0;
    int a = left;
    int b = right;
    while(left != 0) {
        x++;
        left /= 2;
    }
    while(right != 0) {
        y++;
        right /= 2;
    }
    //cout << x << " " << y << endl;
    if (x != y || a == 0 || b == 0) {
        return 0; // If either left or right is 0, the result is always 0.
    }

    if (a == b ) {
        return a; // If left and right are equal, or if their most significant bit positions are different, the result is 0.
    } else {
        int d = (a & b);

        cout << (d & (d + 1)) << endl;
    }
}
int main() {
    int left, right;
    cin >> left >> right;

    cout << rangeBitwiseAnd(left, right) << endl;
}
