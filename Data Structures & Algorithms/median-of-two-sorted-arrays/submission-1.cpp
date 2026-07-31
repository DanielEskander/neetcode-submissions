class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] > nums2[j]){
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
            }
            else{
                i++;
            }
        }
        while(j < nums2.size()){
            nums1.push_back(nums2[j]);
            j++;
        }
        for(int i = 0; i < nums1.size(); i++){
            cout << nums1[i];
        }

        int l = 0;
        int r = nums1.size() - 1;
        double mid = l + (r - l + 0.0) / 2;
        int left = nums1[(int)floor(mid)];
        int right = nums1[(int)ceil(mid)];
        if(left != right){
            return (0.0 + left + right) / 2;
        }
        else{
            return left + 0.0;
        }
    }
};
