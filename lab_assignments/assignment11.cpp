#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans(nums1.size(), -1), nge(nums2.size());
    stack<int> st;
    unordered_map<int, int> hash;

    for (int i = 0; i < nums2.size(); i++)
    {
        hash[nums2[i]] = i;
    }

    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(nums2[i]);
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        ans[i] = nge[hash[nums1[i]]];
    }
    return ans;
}

int main(){
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2},ans;
    ans=nextGreaterElement(nums1,nums2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
        

    return 0;
}