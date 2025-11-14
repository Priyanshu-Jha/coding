#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    sort(begin(hand), end(hand));
    unordered_map<int, int> mp;
    for (auto it : hand)
        mp[it]++;

    for (int i = 0; i < hand.size(); i++)
    {
        if (mp.find(hand[i]) != mp.end())
        {
            for (int j = hand[i]; j < hand[i] + groupSize; j++)
            {
                if (mp.find(j) == mp.end())
                    return false;
                mp[j]--;
                if (mp[j] == 0)
                    mp.erase(mp.find(j));
            }
        }
    }
    return true;
}

//  t = O(nlogn), s = (n)