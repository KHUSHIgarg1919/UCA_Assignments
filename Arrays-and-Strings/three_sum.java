import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
class three_sum{
  public static List<List<Integer>> threeSum(int[] nums) {
        /*Sort the array firstly and then apply 2 pointer approach */
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);                                               //Sort the array
        for(int i=0;i<nums.length-2;i++){
            if(i>0 && nums[i]==nums[i-1]){                               //skip the duplicate elements
                continue;
            }
            int j = i+1;
            int k = nums.length-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.add(Arrays.asList(nums[i],nums[j],nums[k]));   //Found a triplet with 0 sum(add it in ans list as arraylist)
                    while(j<k && nums[j]==nums[j+1]){                  //Skip duplicate elements for j
                        j++;
                    }
                    while(j<k && nums[k]==nums[k-1]){                  //Skip duplicate elements for k
                        k--;
                    }
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;                                                //Sum is less than zero, increment j to increase the sum
                }
                else{
                    k--;                                                //Sum is greater than zero, decrement k to decrease the sum
                }
            }
        }
        return ans;
  }
  public static void main(String[] args) {
    int arr[] = {-1,0,1,2,-1,-4};
    System.out.println(threeSum(arr));
  }
}
