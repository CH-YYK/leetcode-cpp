class Solution {
    public String findDifferentBinaryString(String[] nums) {
        // The method below is to construct a string that has at least one
        // different bit with any of the other strings.
        // For example:
        //  result differs from nums[0] at position 0
        //  result differs from nums[1] at position 1
        //  result differs from nums[2] at position 2
        //  ...
        //  result differs from nums[n-1] at position n-1
        //
        // 
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < nums.length; i++) {
            if(nums[i].charAt(i) == '1') sb.append(0);
            else sb.append(1);
        }
        return sb.toString();
    }
}