/* Description : 
*/

public class MyQueue<T> {
	private static class QueueNode<T> {
		private T data;
		private QueueNode<T> next;

		public QueueNode(T data){
			this.data = data;
		}
	}

	private QueueNode<T> first;
	private QueueNode<T> last;

	public void add(T item){
		QueueNode<T> t = new StackNode<T>(item);
		if (last != Null){
			last.next = t;
		}
		last = t;
		if (firt == Null){
			first = last;
		}
	}

	public T remove(){
		if(first == Null) throw new NoSuchElementException();
		T data = first.data;
		first = first.next;
		if(first = Null){
			last = Null;
		}
		return data;
	}

	public T peek() {
		if (first == Null) throw new NoSuchElementException();
		return fist.data;
	}

	public boolean isEmpty(){
		return first == Null ;
	}
}

/* javac RemoveDupgetKthToLastElement_03(Node head,int k,int index)s.java
	java RemoveDups

*/