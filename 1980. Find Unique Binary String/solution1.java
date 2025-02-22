class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int n = nums[0].length();
        Set<Integer> num_int = new HashSet<>();

        int min_num = 0;
        int max_num = (1 << n) - 1;

        for (String num : nums) {
            num_int.add(stringToInt(num));
        }

        for (int num : num_int) {
            if (num < max_num && !num_int.contains(num + 1))
                return intToString(num + 1, n);
            if (num > min_num && !num_int.contains(num - 1))
                return intToString(num - 1, n);
        }
        return "";
    }

    private int stringToInt(String str) {
        int num = 0;
        for (char c : str.toCharArray()) {
            num = num * 2 + (c - '0');            
        }
        return num;
    }

    private String intToString(int num, int n) {
        char[] str = new char[n];
        for (int i = n - 1; i >= 0; i--) {
            str[i] = (char)('0' + num % 2);
            num /= 2;
        }
        return new String(str);
    }
}