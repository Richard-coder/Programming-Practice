//两个栈实现队列，一个负责push，一个负责pop就好了
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int node;
        if (stack1.empty()&&stack2.empty())
            return -1;
        else{
            if (stack2.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            
            node=stack2.top();
            stack2.pop();
            return node;
        }
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

//用两个队列实现栈,进栈出栈后，一定有一个队列空的，进栈直接压入非空队列，出栈是将除最后一个元素都压入空队列，然后弹出原非空栈的最后一个元素即可
class Solution
{
public:
    void push(int node) {
        if （!queue1.empty()）{
            queue1.push(node);
        }else{
            queue2.push(node);
        }
    }

    int pop() {
        if (queue1.empty()&&queue1.empty())
            return -1;
        else{
            if （!queue1.empty()）{
                while （!queue1.empty()）{
                    if (queue1.size()==1)
                         return queue1.top();
                    queue2.push(queue1.top());
                    queue1.pop();
                }else{
                    while （!queue2.empty()）{
                        if (queue2.size()==1)
                            return queue2.top();
                        queue1.push(queue2.top());
                        queue2.pop();
                    }
                }
            }
        }
    }
private:
    queue<int> queue1;
    queue<int> queue2;
};