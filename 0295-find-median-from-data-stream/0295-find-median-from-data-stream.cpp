class MedianFinder {
private:
    priority_queue<int> low; // max-heap
    priority_queue<int, vector<int>, greater<int>> high; // min-heap

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        low.push(num);
        // Balance: ensure all elements in low <= all elements in high
        high.push(low.top());
        low.pop();

        // Maintain size property
        if (low.size() < high.size()) {
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        if (low.size() > high.size()) {
            return low.top();
        } else {
            return (low.top() + high.top()) / 2.0;
        }
    }
};