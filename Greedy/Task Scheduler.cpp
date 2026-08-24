class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26);
        for(char ch:tasks){
            mp[ch-'A']++;
        }

        sort(mp.begin(),mp.end());

        int maxFreq=mp[25];

        int gaddhe=maxFreq-1;

        int slots=gaddhe*n;

        for(int i=24;i>=0;i--){
            slots-=min(mp[i],gaddhe);
        }

        if(slots>0) return tasks.size()+slots;
        return tasks.size();


    }
};