class FrontMiddleBackQueue {
public:
    list<int> q;

    FrontMiddleBackQueue() {
        
    }

    void pushFront(int val) {
        q.push_front(val);
    }

    void pushMiddle(int val) {
        auto it = q.begin();
        advance(it, q.size() / 2);
        q.insert(it, val);
    }

    void pushBack(int val) {
        q.push_back(val);
    }

    int popFront() {
        if (q.empty()) return -1;

        int ans = q.front();
        q.pop_front();
        return ans;
    }

    int popMiddle() {
        if (q.empty()) return -1;

        auto it = q.begin();
        advance(it, (q.size() - 1) / 2);

        int ans = *it;
        q.erase(it);

        return ans;
    }

    int popBack() {
        if (q.empty()) return -1;

        int ans = q.back();
        q.pop_back();
        return ans;
    }
};