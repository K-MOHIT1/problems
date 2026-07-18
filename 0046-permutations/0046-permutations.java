

class Solution {
    public static void recur(List<List<Integer>> ans, List<Integer> temp, int[] nums){
        if(temp.size() == nums.length){
            ans.add(new ArrayList(temp));
            return;
        }
        for(int i = 0; i < nums.length; i++){
            if(temp.contains(nums[i])) continue;
            else{
                int ch=nums[i];
                temp.add(ch);
                recur(ans, temp, nums);
                temp.remove(temp.size()-1);
            }
            
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> tem = new ArrayList<>();
        recur(ans, tem , nums);
        return ans;
    }
}


