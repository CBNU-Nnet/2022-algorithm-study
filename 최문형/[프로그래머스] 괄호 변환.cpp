#include <string>
#include <vector>
#include <stack>

using namespace std;

int balance_parenthesis(const string& p) {
    int idx;
    int parenthesis_cnt[2] = { 0, 0 };
    
    while (idx < p.size()) {
        if (p[idx] == '(') {
            parenthesis_cnt[0]++;
        }
        else {
            parenthesis_cnt[1]++;
        }
        
        if (parenthesis_cnt[0] == parenthesis_cnt[1]) {
            break;
        }
        
        idx++;
    }
    
    return idx;
}

bool right_parenthesis(const string& p) {
    stack<char> st;
    
    for (auto i : p) {
        if (i == '(') {
            st.push(i);
        }
        else if (!st.empty() && st.top() == '(') {
            st.pop();
        }
        else {
            return false;
        }
    }
    
    return st.empty();
}

string function(string p) {
    if (p.size() == 0) {
        return "";
    }
    
    int div_u_v_idx = balance_parenthesis(p);
    div_u_v_idx++;

    string u = p.substr(0, div_u_v_idx);
    string v = p.substr(div_u_v_idx, p.size());

    if (right_parenthesis(u)) {
        return u + function(v);
    }
    
    string new_string = '(' + function(v) + ')';
    
    string modify_u = "";
    for (int idx = 1; idx < u.size() - 1; idx++) { // 괄호 변환
        if (u[idx] == '(') {
            modify_u += ')';
        }
        else {
            modify_u += '(';
        }
    }
    
    return new_string + modify_u;
}

string solution(string p) {
    string answer = function(p);
    return answer;
}
