class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;
        int maxa = INT_MIN;

        while(left<right){
            ans = (long long)(right-left)*min(height[left],height[right]);


            maxa = max(maxa,ans);

            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxa;
    }
};