/* Description : 
*/

public class MyStack<T> {
	private static class StackNode<T> {
		private T data;
		private StackNode<T> next;

		public StackNode(T data){
			this.data = data;
		}
	}

	private StackNode<T> top;

	public T pop(){
		if(top == Null) throw new emptyStackException();
		T item =top.data;
		top = top.next;
		return item;
	}

	public void push(T item){
		StackNode<T> t = new StackNode<T>(item);
		t.next = top;
		top = t;
	}

	public T peek() {
		return top.data;
	}

	public boolean isEmpty(){
		return top == Null ;
	}
}

/* javac RemoveDupgetKthToLastElement_03(Node head,int k,int index)s.java
	java RemoveDups

*/