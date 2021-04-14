class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
        return;
    }

    int pop()
    {
        int return_number = 0;
        if (!(stack2.empty()))
        {
            return_number = stack2.top();
            stack2.pop();
            return return_number;
        }
        else
        {
            if (!(stack1.empty()))
            {
                while (!(stack1.empty()))
                {
                    return_number = stack1.top();
                    stack1.pop();
                    stack2.push(return_number);
                }
                return_number = stack2.top();
                stack2.pop();
                return return_number;
            }
            else
            {
                return 0;
            }
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
