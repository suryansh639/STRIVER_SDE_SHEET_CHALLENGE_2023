
vector<int> kthLargest(int k, int arr[], int n) {
    vector<int> results(k - 1, -1); 
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    // iterate the stream of numbers 
    for(int i = 0; i < k; i++)
        pq.push(arr[i]);

    results.push_back(pq.top());
    for(int i = k; i < n; i++) {
        if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
        results.push_back(pq.top());
    }    
    return results;
}
