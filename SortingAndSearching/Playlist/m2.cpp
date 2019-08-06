#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> playlist;
    playlist.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int song_id; cin >> song_id;
        playlist.emplace_back(song_id);
    }
    
    unordered_set<int> unique;
    unique.reserve(n);
    size_t max_unique_seq = 1;
    
    for (int i = 0; i < n; i++)
    {
        while (unique.find(playlist[i]) != unique.end())
        {
        unique.erase(playlist[i - unique.size()]);
        }
        unique.insert(playlist[i]);
        max_unique_seq = max(max_unique_seq, unique.size());
    }
    
    cout << max_unique_seq;
    return 0;
}