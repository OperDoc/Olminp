map<int, int> mask;
vector<int> unmask;

void comp(vector<int> &arr)
{
    cnt = 0;
    unmask.push_back(-1);
    sort(arr.begin(), arr.end());
    for(auto &i:arr)
    {
        if(mask[i] == 0)
        {
            cnt++;
            mask[i] = cnt;
            unmask.push_back(i);
        }
        i = mask[i];
    }
}
