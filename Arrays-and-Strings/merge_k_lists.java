class merge_k_lists{
    static class ListNode{
        int val;
        ListNode next;
        ListNode(int val){
            this.val = val;
            this.next = null;
        }
    }
    static ListNode merge(ListNode list1,ListNode list2){
        ListNode dummyHead = new ListNode(-1);                  //dummy Node
        ListNode dummyTail = dummyHead;
        while(list1!=null && list2!=null){
            if(list1.val<list2.val){
                dummyTail.next = list1;
                list1 = list1.next;
            }
            else{
                dummyTail.next = list2;
                list2 = list2.next;
            }
            dummyTail = dummyTail.next;
        }
        if(list1!=null){                                        //if list1 remains at end
            dummyTail.next = list1;
        }
        else{                                                   //if list2 remains at end
            dummyTail.next = list2;
        }
        return dummyHead.next;
    }
    static ListNode mergeKListsHelper(ListNode[] lists,int start,int end){
        if(start>end) return null;
        if(start == end) return lists[start];                         //means there is only 1 list

        int mid = start + (end-start)/2;
        ListNode left = mergeKListsHelper(lists,start,mid);           
        ListNode right = mergeKListsHelper(lists,mid+1,end);
        return merge(left,right);
       
    }
    public static ListNode mergeKLists(ListNode[] lists) {                  //like merge sort(divide and conquer method)
        if(lists.length == 0){
            return null;
        }
        return mergeKListsHelper(lists,0,lists.length - 1);
    }
    public static void main(String[] args) {
        ListNode list1 = new ListNode(1);
        list1.next = new ListNode(4);
        list1.next.next = new ListNode(5);

        ListNode list2 = new ListNode(1);
        list2.next = new ListNode(3);
        list2.next.next = new ListNode(4);

        ListNode list3 = new ListNode(2);
        list3.next = new ListNode(6);

        ListNode[] lists = {list1, list2, list3};

        ListNode mergedList = mergeKLists(lists);

        while (mergedList != null) {
            System.out.print(mergedList.val + " ");
            mergedList = mergedList.next;
        }
    }
}