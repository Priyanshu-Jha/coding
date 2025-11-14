#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxi.empty())
            maxi.push(num);
        else
        {
            if (maxi.top() >= num)
                maxi.push(num);
            else
                mini.push(num);
        }
        int sizemaxi = max(maxi.size(), mini.size());
        int sizemini = min(maxi.size(), mini.size());
        while (sizemaxi - sizemini > 1)
        {
            if (maxi.size() > mini.size())
            {
                mini.push(maxi.top());
                maxi.pop();
            }
            else
            {
                maxi.push(mini.top());
                mini.pop();
            }
            sizemaxi--;
            sizemini++;
        }
    }

    double findMedian()
    {
        if (mini.size() == maxi.size())
        {
            return (double)(mini.top() + maxi.top()) / 2.0;
        }
        else if (mini.size() > maxi.size())
        {
            return mini.top();
        }
        else
            return maxi.top();
    }
};
// T = O(logn) s= O(n)
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */