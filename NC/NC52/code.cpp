#include <stack>
class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s)
    {
        // write code here
        stack<char> valid;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            switch (s[i])
            {
                case '{':
                    valid.push(s[i]);
                    break;
                case '}':
                    if (valid.empty())
                        return false;
                    if ((valid.top()) == '{')
                        valid.pop();
                    else
                        return false;
                    break;
                case '(':
                    valid.push(s[i]);
                    break;
                case ')':
                    if (valid.empty())
                        return false;
                    if ((valid.top()) == '(')
                        valid.pop();
                    else
                        return false;
                    break;
                case '[':
                    valid.push(s[i]);
                    break;
                case ']':
                    if (valid.empty())
                        return false;
                    if ((valid.top()) == '[')
                        valid.pop();
                    else
                        return false;
                    break;
                default:
                    break;
            }
        }
        return valid.empty();
    }
};
