class MedianFinder {
public:
priority_queue<int>mxp;
priority_queue<int,vector<int>,greater<int>>mnp;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mxp.push(num);
        mnp.push(mxp.top());
        mxp.pop();
        if(mnp.size()>mxp.size()){
            mxp.push(mnp.top());
            mnp.pop();
        }
    }
    
    double findMedian() {
        if(mxp.size() > mnp.size())
        return mxp.top();
        return (mxp.top()+mnp.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */