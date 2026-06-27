// 2. Find the Maximum & Minimum Element

vector<int> getMinMax(vector<int> &arr) {
    int maxi = arr[0], mini = arr[0];

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
        else if(arr[i] < mini){
            mini = arr[i];
        }
    }

    return {mini, maxi};
}

// TC : O(N)
// SC : O(1)