//
// Created by Zeno on 2020/6/7.
//

/*
 * 思路：
 * 使用双向链表记录history，使用迭代器记录current page
 */

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curPage = history.begin();
    }

    void visit(string url) {
        while (--history.end() != curPage) {
            history.pop_back();
        }
        history.push_back(url);
        curPage = ++curPage;
    }

    string back(int steps) {
        while (curPage != history.begin() && steps) {
            curPage = --curPage;
            steps--;
        }
        return *curPage;
    }

    string forward(int steps) {
        while (curPage != history.end() && steps) {
            curPage = ++curPage;
            steps--;
        }
        if (curPage == history.end()) {
            curPage = --curPage;
        }
        return *curPage;
    }

private:
    list<string> history;
    list<string>::iterator curPage;
};
