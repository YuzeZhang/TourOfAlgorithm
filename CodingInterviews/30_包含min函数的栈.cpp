//
// Created by Zeno on 2020/6/6.
//

/*
 * 思路：
 * 一个数据栈一个辅助栈，每次push时，数据栈插入push的元素，辅助栈插入当前最小元素
 */

class MinStack {
public:
    MinStack() {

    }

    void push(int x) {
        if (m_min.empty() || x < m_min.top()) {
            m_min.push(x);
        } else {
            m_min.push(m_min.top());
        }
        m_data.push(x);
    }

    void pop() {
        m_data.pop();
        m_min.pop();
    }

    int top() {
        return m_data.top();
    }

    int min() {
        return m_min.top();
    }
private:
    stack<int> m_data;
    stack<int> m_min;
};