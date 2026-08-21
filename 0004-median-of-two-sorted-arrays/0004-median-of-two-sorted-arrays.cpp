class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0;
        int h = n;  //because we moving on the particition not on the array there are n+1 combination between element and when the particition is done on the end and the start of the array 

        while (l <= h) {
            int cutA = l + (h - l) / 2;
            int cutB = (n + m + 1) / 2 - cutA;

            int Aleft = (cutA == 0) ? INT_MIN : nums1[cutA - 1];   //if  =  yes and then no ? :  for the boundary values 
            int Aright = (cutA == n) ? INT_MAX : nums1[cutA];

            int Bleft = (cutB == 0) ? INT_MIN : nums2[cutB - 1];
            int Bright = (cutB == m) ? INT_MAX : nums2[cutB];

            if (Aleft <= Bright && Bleft <= Aright) {
                if ((n + m ) % 2 != 0) { 
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Bright, Aright)) / 2.0;   //max for the small half of both array and min of the right grater half 
            } else if (Aleft > Bright) {
                h = cutA - 1;    // we move the high to the left because to increase the b greater number and smaller a number 
            } else { 
                l = cutA + 1; // we move to the left the low pointer 
            }
        }
        return 0.0;
    }
};