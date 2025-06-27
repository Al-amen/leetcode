class Solution {
int getNext(int n) {
    int temp = 0;
    while(n != 0) {
        int d = n%10;
        n /= 10;
        temp += d*d;
    }
    return temp;
}
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);

        while(fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
        
    }
};