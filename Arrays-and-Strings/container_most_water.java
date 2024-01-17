class container_most_water{
  public static int maxArea(int[] height) {
    int left = 0;
    int right = height.length-1;
    int maxArea = 0;
    while(left<right){
        int currArea = Math.min(height[left],height[right]) * (right-left);
        maxArea = Math.max(maxArea,currArea);               //store maximum area in it
        if(height[left]<height[right]){                     //if left height is less than right height then move left forward      
            left++;
        }
        else{                                               //else move right backwards
            right--;
        }
    }
    return maxArea;
  }
  public static void main(String[] args) {
    int arr[] = {1,8,6,2,5,4,8,3,7};
    System.out.println(maxArea(arr));
  }
}