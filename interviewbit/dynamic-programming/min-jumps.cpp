int Solution::jump(vector<int> &A) {
        int n = A.size();
        if (n<=1) return 0;
        
        int ladder_end = 0;
        int jumps = 0;
        int max_position = 0;
        int stairs = 0;
        
        while(stairs<=ladder_end) {
            jumps++;
            while (stairs<=ladder_end) {
                max_position = max(max_position, stairs+ A[stairs]);
                if (max_position>=n-1) return jumps;
                stairs++;
            }
            ladder_end = max_position;
        }
        return -1;
}
