int Solution::isPalindrome(int A) {
    if (A<0) return false;
    int n=A,cnt=0,x,y;
    while(n>0) {
        cnt++;
        n/=10;
    }
    bool isPallin = true;
    for (int i=1;i<=cnt/2;i++) {
        x = A % (int)pow(10,i);
        y = A / (int)pow(10,cnt-i);
        
        x = x/(int)pow(10,i-1);
        y = y%10;
        
        if (x!=y) {
            isPallin = false;
            break;
        }
    }
    return isPallin;
}
