function mergeKLists(lists) {
   
    //Get first list as element as the root
  
    let root = lists[0];
    //loop through list starting from second list
    for (let i = 1; i < lists.length; i++) {
      //call merge function to merge the root and list[i] and update root
      root = merge(root, lists[i]);
    }

    return root || null;
  }
   function merge (l1, l2) {
      //If root or list[i] is empty return any that has value  
      if (!l1 || !l2){
          return l1 || l2;
      } 
      // create the new root node
      let node = {};    
      const root = node;
      //while the rooot or list[i] has value
      while (l1 && l2) {
        // check and sort between root.val element and list[i].val element
        if (l1.val <= l2.val) {
          node.next = l1;
          l1 = l1.next;
        } else {
          node.next = l2;
          l2 = l2.next;
        }
        node = node.next;
      }
      //if rooot is the one not exhauseted update next to  new root next to root
      if (l1){
          node.next = l1;
      }   //if list[i] is the one not exhauseted update next to  new root next to root

      if (l2) {
          node.next = l2;
      }
      //return root.next
      return root.next;
    }