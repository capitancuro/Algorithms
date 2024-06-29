/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2)
{
       if(list1 && list2)
   {
      while(list2)
      {
         let ptr = list1, temp = list2;
         while(ptr.next && ptr.next.val <= temp.val)
         {
            ptr = ptr.next;
         }
         
         list2 = list2.next;

         if(!ptr.next)
         {
            if(ptr.val <= temp.val)
            {
                temp.next = ptr.next;
                ptr.next = temp;
            }
            else
            {
                temp.next = ptr;
                list1 = temp;
            }
         }
         else
         {
             if(ptr.val <= temp.val)
             {
                 temp.next = ptr.next;
                 ptr.next = temp;
             }
             else
             {
                 temp.next = ptr;
                 list1 = temp;
             }
         }
      }
    return list1;
   }
   else if(list1)
   {
      return list1;
   }
   else
   {
      return list2;
   }   
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val);
  this.next = (next === undefined ? null : next);
}

let L1 = new ListNode(1, new ListNode(2, new ListNode(4, null)));
let L2 = new ListNode(1, new ListNode(3, new ListNode(4, null)));

var mergeTwoLists = function(list1, list2) {
  if (!list1) {
    return list2;
  }
  if (!list2) {
    return list1;
  }

  let mergedList = new ListNode(); // Placeholder for the merged list
  let current = mergedList;

  while (list1 && list2) {
    if (list1.val <= list2.val) {
      current.next = list1;
      list1 = list1.next;
    } else {
      current.next = list2;
      list2 = list2.next;
    }
    current = current.next;
  }

  // Append the remaining nodes
  if (list1) {
    current.next = list1;
  }
  if (list2) {
    current.next = list2;
  }

  return mergedList.next; // Skip the placeholder node
};

console.log(mergeTwoLists(L1, L2));
