class next_permutation{
    static void reverse(int[] nums,int a,int b){
      while(a<b){
          int temp = nums[a];
          nums[a] = nums[b];
          nums[b] = temp;
          a++;
          b--;
      }
    }
    public static void nextPermutation(int[] nums){
        int index = -1;
        int n = nums.length;
        for(int i=n-2;i>=0;i--){                 //traverse array from backward
            if(nums[i]<nums[i+1]){               //find first breakpoint and change index
                index = i;
                break;
            }
        }
        if(index==-1){                           //if breakpoint doesn't find means we get ans by reversing the arr
            reverse(nums,0,n-1);
            return;
        }
        for(int i=n-1;i>index;i--){              //if breakpoint find then search for first larger element 
            if(nums[i]>nums[index]){
                int temp = nums[i];              //swap that breakpoint with larger element
                nums[i] = nums[index];
                nums[index] = temp;
                break;
            }
        }
        reverse(nums,index+1,n-1);               //reverse the entire right half
    }
    public static void main(String[] args) {
        int arr[] = {1,2,3};  
        nextPermutation(arr);
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i] + " ");
        }
    }
}
