#include<string>
#include<iostream>
#include<queue>
using namespace std;

class MyStack {
private:
    queue<int> queueAsStack;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queueAsStack.push(x);
    }
    
    int pop() {
        int tmpNum;
        for(int i=0;i < queueAsStack.size() - 1;++i){
            tmpNum = queueAsStack.front();
            queueAsStack.pop();
            queueAsStack.push(tmpNum);
        }
        tmpNum = queueAsStack.front();
        queueAsStack.pop();
        return tmpNum;
    }
    
    int top() {
        return queueAsStack.back();
    }
    
    bool empty() {
        return queueAsStack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
#if 0
int main()
{
    MyStack* job  = new MyStack();
    job->push(1);
    job->push(2);
    int tmp1 = job->top();
    int tmp2 = job->pop();
    bool flag = job->empty();

    delete job;
    
}
#endif