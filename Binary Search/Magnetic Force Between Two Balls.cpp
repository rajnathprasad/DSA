class Solution {
public:
    bool canWePlace(vector<int> &position,int dist, int m){
        int countBalls=1;
        int last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=dist){
                countBalls++;
                last=position[i];
            }
            if(countBalls>=m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int min=1;
        int max=position.back() - position.front();;
        int ans=0;
        while(min<=max){
            int mid=(min+max)/2;
            if(canWePlace(position, mid,m)){
                min=mid+1;
                ans=mid;
            }
            else{
                max=mid-1;
            }
        }
        return max;
    }
};