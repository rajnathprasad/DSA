class Solution {
  public:
    int eggDrop(int e, int f) {
        // code here
        if(f==0 || f==1) return f;
        if(e==1) return f;
        int mn=INT_MAX;
        int temp;
        for(int k=1;k<=f;k++){
            temp=1+max(eggDrop(e-1,k-1), eggDrop(e,f-k));
            mn=min(mn,temp);
        }
        return mn;
    }
};