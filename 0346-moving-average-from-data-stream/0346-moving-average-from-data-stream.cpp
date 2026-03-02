class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int qsize;
    int sum=0;
    MovingAverage(int size) {
        qsize=size;
    }
    
    double next(int val) {
        if(q.size()==qsize){
            sum-=q.front();
            q.pop();
        }
        q.push(val);
        sum+=val;
        return (double)sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */