class FreqStack {
public:
unordered_map<int,int> mpp1;
unordered_map<int,stack<int>> mpp2;
int maxFreq;
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int val) {
        mpp1[val]++;
        int freq=mpp1[val];
        maxFreq=max(maxFreq,freq);
        mpp2[freq].push(val);
    }
    
    int pop() {
        int val=mpp2[maxFreq].top();
       mpp2[maxFreq].pop();
       mpp1[val]--;
       if(mpp2[maxFreq].empty()){
          maxFreq--;
       }
       return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */