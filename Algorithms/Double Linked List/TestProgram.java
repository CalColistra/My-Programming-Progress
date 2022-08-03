
public class TestProgram {

	public static void main(String[] args) {
		DoubleLinkedList<String> myList = new DoubleLinkedList<String>();
		myList.add(0, "A");
		myList.add(1, "C");
		myList.add(2, "D");
		myList.add(3, "E");
		myList.add(1,  "B");//inset Node in middle list
		myList.traverse();
		
		myList.remove(4);
		myList.traverse();
		
		myList.remove(2);
		myList.traverse();

		DoubleLinkedList<Integer> myList2 = new DoubleLinkedList<Integer>();
		myList2.add(0, 12);
		myList2.add(1, 2);
		myList2.add(2, 6);
		myList2.add(3, 7);
		myList2.add(1,  8);//inserts Node in middle list
		myList2.traverse();
		
		myList2.remove(4);
		myList2.traverse();
		
		myList2.remove(2);
		myList2.traverse();
		
	}

}
