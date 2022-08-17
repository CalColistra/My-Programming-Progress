

public class Application {
	//testing example

	public static void main(String[] args) {
		//initialization
		IntLinkedList alist = new IntLinkedList();
		alist.addFirst(3);
		alist.addFirst(2);
		alist.addFirst(6);
		alist.addFirst(4);
		alist.addFirst(3);
		System.out.println(" constructed a list:");
		alist.traverse();
		
		//step 1: 
		System.out.println("\n step 1: get length");
		System.out.println("The length of this linkedList is " + alist.getLength());
		
		//step 2:
		System.out.println("\n step 2: add new item at the end");
		System.out.println("The original list is: ");
		alist.traverse();
		System.out.println("Add 5 at the end of the list: ");
		alist.addTail(5);
		alist.traverse();
		
		//step 3: 
		System.out.println("\n step 3: make a copy");
		IntLinkedList blist = alist.copyList();
		System.out.print("The first list is: ");
		alist.traverse();
		System.out.print("The second list is: ");
		blist.traverse();
		
		//step 4:
		System.out.println("\n step 4: finding item");
		System.out.print("Finding the first element contains 4: ");
		IntLinkedList.showContent(alist.findItem(4));
		System.out.println(" ");
		
		//step 5:
		System.out.println("\n step 5: finding maximum value");
		System.out.println("The original list is: ");
		alist.traverse();
		System.out.println("The max value of the list is: " + alist.maxValue());
		
		//step 6: (already done for you)
		//take this as an example
		System.out.println("\n step 6: scale");
		System.out.println("The original list is: ");
		alist.traverse();
		System.out.println("The new list, which is scaled by 4, is: ");
		IntLinkedList clist = alist.scaleBy(4);
		clist.traverse();
		
		//step 7:
		System.out.println("\n step 7: divisible");
		System.out.println("The original list is: ");
		alist.traverse();
		System.out.println("The new list, which is divisible by 3, is: ");
		IntLinkedList dlist = alist.divisibleBy(3);
		dlist.traverse();
		
		//step 8:
		System.out.println("\n step 8: filtering");
		System.out.println("The original list is: ");
		alist.traverse();
		System.out.println("The new list is: ");
		IntLinkedList elist = alist.filter(3);
		elist.traverse();
		
		//step 9:
		System.out.println("\n step 9: reverse copy");
		IntLinkedList flist = clist.reverseCopy();
		System.out.println("The original list is: ");
		clist.traverse();
		System.out.println("The reversed list is: ");
		flist.traverse();
	}

}
