class ArithmaticSlices {
    public int numberOfArithmeticSlices(int[] nums) {
        int c = 0, ans = 0;
        for(int i = 0; i < nums.length-2; i++){
            if(nums[i+2]+nums[i] == 2*nums[i+1]) c++;
            else{
                ans += (c*(c+1)/2);
                c = 0;
            }
            
        }
        ans += (c*(c+1)/2);
        return ans;
    }
}