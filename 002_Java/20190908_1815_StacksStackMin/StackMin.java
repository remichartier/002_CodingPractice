/* Description : How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element ?
Push, pop, and min should all operatin in O(1) time

Hints #27, #59, #78.
*/

public class MyStack<T> {
	public static class StackNode<T> {
		private T data;
		private StackNode<T> next;
		private T min;
		public StackNode<T>(T item){
			data = item;
		}
	}

	private StackNode<T> top;

	//peek()

	public T pop(){
		if (top == Null) throws new Exception...;
		T item = top.data;
		top = top.next;
		return item;
	}

	public void push(T item){
		StackNode<T> t = new StackNode<T>(item);
		if (top = Null){
			t.min = item;
		}
		else{
			if (item < t.next.min){
				t.min = item;
			}
			else{
				t.min=t.next.min;
			}
		}
		t.next = top;
		top = t;
		
	}

	public T min(){
		if (top == Null) throws new Exception...;
		return top.min;
	}

}


/* javac RemoveDupgetKthToLastElement_03(Node head,int k,int index)s.java
	java RemoveDups

*/