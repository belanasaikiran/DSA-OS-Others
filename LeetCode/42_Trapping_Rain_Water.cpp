class Solution {
public:
    int trap(vector<int>& height) {
        // Time: O(n); Space = O(n)
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());

        int Water = 0;
        int maxVal = 0;
        for(int i = 0; i < height.size(); i++){
            maxLeft[i] = max(maxVal, height[i]);
            if(maxVal < height[i]) maxVal = height[i];
        }

        maxVal = 0;
        for(int i = height.size() - 1; i >= 0; i--){
            maxRight[i] = max(maxVal, height[i]);
            if(maxVal < height[i]) maxVal = height[i];
        }

        for(int i = 0; i < height.size(); i++){
            Water += min(maxLeft[i], maxRight[i]) - height[i];
        }



        // Time: O(n); Space: O(1)




        return Water;
    }
};
