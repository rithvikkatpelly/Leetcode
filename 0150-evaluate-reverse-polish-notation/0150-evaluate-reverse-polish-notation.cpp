class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& tok : tokens) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                // Pop the top two operands
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = 0;

                if (tok == "+")      res = a + b;
                else if (tok == "-") res = a - b;
                else if (tok == "*") res = a * b;
                else if (tok == "/") res = a / b;  // truncates toward zero

                st.push(res);
            } else {
                // It's a number
                st.push(stoi(tok));
            }
        }

        return st.top();
    }
};
