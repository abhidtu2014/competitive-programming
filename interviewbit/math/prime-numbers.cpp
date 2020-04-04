vector<int> Solution::sieve(int A) {
    vector<int> prime(A, 1);
    prime[1]=prime[0]=0;
    for(int i=2;i<=A;i++) {
        if (prime[i]) {
            for(int j=2;i*j<=A;j++) {
                prime[i*j]=0;
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<=A;i++) {
        if (prime[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}
