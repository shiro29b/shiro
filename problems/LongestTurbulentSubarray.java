class LongestTurbulentSubarray {   
    public int maxTurbulenceSize(int[] arr) {
        int n = arr.length, ans = 0, c = 0;
        
        for(int i = 0; i < n; i++){
            if((i >= 2) && ((arr[i-2] < arr[i-1] && arr[i-1] > arr[i]) || (arr[i-2] > arr[i-1] && arr[i-1] < arr[i])))
                c++;
            else if(i >= 1 && arr[i-1] != arr[i])
                c = 2;
            else 
                c = 1;
            ans = Math.max(ans, c);
        }
        return ans;    
    }
}
