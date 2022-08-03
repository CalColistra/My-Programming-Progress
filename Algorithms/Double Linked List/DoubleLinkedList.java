
public class DoubleLinkedList<E> {
	//inner class
	private static class Node<E>{
		private E data;
		private Node<E> prev;
		private Node<E> next;
		
	private Node(E value, Node<E> prevItem, Node<E> nextItem) {
		data = value;
		prev = prevItem;
		next = nextItem;
		}		
	}//end inner class
	
	private Node<E> head = null;
	private Node<E> tail = null;
	int size = 0;
	
	public DoubleLinkedList() {
		head= null;
		tail= null;
	}
	
	private void addFirst(E value) {
		if(size==0) {//current list is empty
			head = new Node<E>(value, null, null);
			tail = head;
		}
		else {//the current list is NOT empty
			Node<E> newNode = new Node<E>(value, null, head);
			head.prev = newNode;
			head = newNode;
		}
		size++;
	}
	
	private void addLast(E value) {
		if(size==0) {//list is empty
			head = new Node<E>(value, null, null);
			tail = head;
		}
		else {		//list is NOT empty
			Node<E> newNode = new Node<E>(value, tail, null);
			tail.next = newNode;
			tail = newNode;
		}
		size++;
	}
	
	private Node<E> getRef2Node(int index) {
		if(index<0 || index>=size) {
			throw new ArrayIndexOutOfBoundsException(index);
		}
		Node<E> ref = head;
		for(int i=0; i<index; i++) {
			ref = ref.next;
		}
		return ref;
	}
	
	public void add(int index, E value) {
		if(index==0) {
			addFirst(value);
		}
		else {
			if(index ==size) {
				addLast(value);
			}else {//insert new node in the middle of  the list
				Node<E> ref = getRef2Node(index);
				Node<E> newNode = new Node<E>(value, ref.prev, ref);
				ref.prev.next = newNode;
				ref.prev = newNode;
				size++;
			}
		}
	}
	private E removeFirst() {
		E oldValue = head.data;
		if(size<=0) {
			System.out.println("Cannot call the method");
			return null;
		}
		if(size>1) {
			head =  head.next;
			head.prev = null;
		}else {
			head = null;
			tail = null;
		}
		size--;
		return oldValue;
	}
	
	private E removeLast() {
		E oldValue = tail.data;
		if(size<=0) {
			System.out.println("Cannot call the method");
			return null;
		}
		if(size > 1) {
			tail = tail.prev;
			tail.next = null;
		}else {
			head = null;
			tail = null;
		}
		size--;
		return oldValue;
	}

	public E remove(int index) {
		if(index<0 || index>=size) {
			throw new ArrayIndexOutOfBoundsException(index);
		}		
		if(index==0) return removeFirst();
		if(index == size-1) return removeLast();
		Node<E> curnode = getRef2Node(index);
		E oldValue = curnode.data;
		curnode.prev.next = curnode.next;
		curnode.next.prev = curnode.prev;
		curnode.prev = null;
		curnode.next = null;
		size--;
		return oldValue;
	}
	public void traverse() {
		if(size > 0) {
			Node<E> ref = head;
			while (ref != null) {
				System.out.print(ref.data + " ");
				ref = ref.next;
			}//traverse in forward direction
			System.out.println();
			
			ref = tail;
			while (ref != null) {
				System.out.print(ref.data + " ");
				ref = ref.prev;
			}//traverse in backwards direction
			System.out.println();			
		}
	}
	
}//end class

