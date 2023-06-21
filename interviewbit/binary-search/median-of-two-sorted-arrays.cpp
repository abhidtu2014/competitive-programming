// Correct solution but TLE as Time complexity is O(NLogN + MLogM) and expected is O(log(N+M))

double findMedian (const vector<int> &A) {
    int n = A.size();
    int half = n/2;
    // cout<<half<<" "<<A[half]<<" "<<A[half];
    if (n % 2 == 0) {
        return (A[half] + A[half-1])/2.0;
    } else {
        return A[half];
    }
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.size() == 0) {
        return findMedian(B);
    } else if (B.size() == 0) {
        return findMedian(A);
    } else if (A.size() == 1 && B.size() == 1) {
        return (A[0]+B[0])/2.0;
    }
    
    priority_queue <int> max_pq;
    priority_queue <int, vector<int>, greater<int>> min_pq;
    
    int pointA = 0, pointB = 0;
    int lenA = A.size(), lenB = B.size();
    
    while (pointA < lenA || pointB < lenB) {
        int toInsert = -1;
        
        if (pointA < lenA && pointB < lenB) {
            toInsert = A[pointA] < B[pointB] ? A[pointA++]: B[pointB++];
        } else if (pointA < lenA) {
            toInsert = A[pointA++];
        } else {
            toInsert = B[pointB++];
        }
        
        if (max_pq.size() == 0) {
            max_pq.push(toInsert);
        } else if (max_pq.top() < toInsert) {
            min_pq.push(toInsert);
        } else {
            max_pq.push(toInsert);
        }
        
        // Re-balance
        if (max_pq.size() > (min_pq.size() + 1)) {
            min_pq.push(max_pq.top());
            max_pq.pop();
        } else if (min_pq.size() > (max_pq.size() + 1)) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }
    
    if ((lenA+lenB) % 2  == 0) {
        return (max_pq.top() + min_pq.top())/2.0;
    } else if (max_pq.size() > min_pq.size()) {
        return max_pq.top();
    } else {
        return min_pq.top();
    }
}
