public class IntLinkedList {

	private Node head = null;
	private int size = 0;
	
	private static class Node {
		private int data;
		private Node next;
		
		private Node(int dataItem){
			data = dataItem;
			next = null;
		}
		
		private Node(int dataItem, Node nodeRef){
			data = dataItem;
			next = nodeRef;
		}

	}
	
	public void addFirst(int dataItem){
		head = new Node(dataItem, head);
		size++;
	}
	
	public void traverse(){
		Node currentnode = head;
		while(currentnode != null){
			System.out.print(currentnode.data);
			currentnode = currentnode.next;
			if (currentnode != null){
				System.out.print(" ==> ");
			}
		}
		System.out.println(" ");
	}
	
	public Node getNode(int index){
		if(index < 0 || index >= size){
			throw new ArrayIndexOutOfBoundsException(index);
		}
		Node currentnode = head;
		for(int i =0; i < index && currentnode != null; i++){
			currentnode = currentnode.next;
		}
		return currentnode;
	}
	
	public void add(int index, int dataItem){
		if(index < 0 || index > size){
			throw new ArrayIndexOutOfBoundsException(index);
		}
		if (index == 0){
			//insert at the head of the chain
			addFirst(dataItem);
		} else {
			Node prevnode = getNode(index-1);
			prevnode.next = new Node(dataItem, prevnode.next);
			size++;
		}
	}
	
	public void removeFirst(){
		Node targetnode = head;
		if (head != null){ 
			head = head.next;
		}
		if (targetnode != null){
			size--;
		}
	}
	
	public void remove(int index){
		if(index < 0 || index >= size){
			throw new ArrayIndexOutOfBoundsException(index);
		}
		if (index == 0){
			removeFirst();
		} else {
			Node prevnode = getNode(index-1);
			Node targetnode = prevnode.next;
			prevnode.next = targetnode.next;
			size--;		
		}
		
	}
	
	public static void showContent(Node nodeRef){
		if (nodeRef == null){
			System.out.print("null");
		} else{ 
			System.out.print(nodeRef.data);
		}
	}
	
	public int getLength(){
		int count=0;
		for(int i=1; i<=size; i++) {
			count++;
		}
		return count;
	}// 1pt
	
	public void addTail(int dataItem){
		add(size, dataItem);
	}// 1pt
	
	public IntLinkedList copyList(){
		IntLinkedList newList = new IntLinkedList();
		Node oHead = this.head;
		Node ref = this.head;
		newList.head = ref;
		while(ref.next == null) {
			for(int i=0; i<=this.size; i++) {
				ref.next = oHead.next;
				ref = oHead.next;
				oHead= oHead.next;
				newList.size++;
			}
		}
		return newList;
	}// 2pt
	
	public Node findItem(int dataItem){
		Node theNode = this.head;
		int check = theNode.data;
		for(int i=0; i<=size;i++) {
			if(check == dataItem) {
				i=size+1;
			}
			else if(i==size && check!= dataItem) {
				theNode=null;
				i=size+1;
			}
			else if(theNode.next != null) {
					theNode = theNode.next;
					check = theNode.data;
				}
			

		}
		return theNode;
	}//1pt
	
	public int maxValue(){
		Node ref = this.head;
		Node max = ref;
		while(ref.next != null) {
			if(ref.next.data > max.data) {
				max = ref.next;
				}
			ref = ref.next;
		}

		int m = max.data;
		return m;
	}//1pt
	
	public IntLinkedList scaleBy(int n){
		Node currentnode = head;
		IntLinkedList copiedList = new IntLinkedList();
		while(currentnode != null){
			copiedList.addTail(currentnode.data*n);
			currentnode = currentnode.next;
		}
		return copiedList;
	}//take this as an example
	
	public IntLinkedList divisibleBy(int divisor){
		Node currentnode = head;
		IntLinkedList copiedList = new IntLinkedList();
		while(currentnode != null){
			if(currentnode.data%divisor == 0) {
			copiedList.addTail(currentnode.data);
			}
			currentnode = currentnode.next;
		}
		return copiedList;
	}//2pt
	
	
	public IntLinkedList filter(int n){
		Node currentnode = head;
		IntLinkedList copiedList = new IntLinkedList();
		while(currentnode != null){
			if(currentnode.data != n) {
			copiedList.addTail(currentnode.data);
			}
			currentnode = currentnode.next;
		}
		return copiedList;
	}//2pt
	
	public IntLinkedList reverseCopy(){
		Node ref = this.head;
		IntLinkedList newList = new IntLinkedList();
		for(int i=this.size; i>0; i--) {
			newList.addFirst(ref.data);
			ref = ref.next;
		}
		return newList;
	}//Extra point: 1pt

}
