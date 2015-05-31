/*
 * Doubly Linked List in Java
 */
public class DLList {
	/**
	 * @param args
	 */
	
	/*
	 * Insert
	 * Find 
	 * Remove 
	 * 
	 */
	
	private class LLNode{
		Object data;
		LLNode next;
		LLNode prev;
		
		public LLNode(Object obj){
			data = obj;
			next = null;
		}

		public Object getData() {
			return data;
		}

		public void setData(Object data) {
			this.data = data;
		}

		public LLNode getNext() {
			return next;
		}

		public void setNext(LLNode next) {
			this.next = next;
		}
	}
	
	private int n=0;
	private LLNode head, end;
	
	
	public DLList(){
		head=null;
	}
	
	
	public void insert(int pos, Object data){
		if(pos>n) System.out.println("Error, Can't insert at postion : "+pos);
		else if(pos==0){
			LLNode insert_node;
			insert_node = new LLNode(data);
			insert_node.next = head;
			if(head!=null) head.prev=insert_node;
			head = insert_node;
			if(n==0) end=insert_node;
			n+=1;
		}
		else{
			LLNode insert_node, next, prev,temp;
			temp = head;
			insert_node = new LLNode(data);
			for(int i=0;i<pos-1;i++){
				temp = temp.next;
			}
			prev = temp;
			next = temp.next;
			
			prev.next = insert_node;
			insert_node.prev = prev;
			
			insert_node.next = next;
			next.prev = insert_node;
			
			if(pos==n) end=insert_node;
			n+=1;
			
		}
		
	}
	
	public void append(Object data){
		LLNode insert_node;
		insert_node = new LLNode(data);
		/*LLNode insert_node, temp;
		temp = head;
		insert_node = new LLNode(data);
		for(int i=0;i<n-1;i++){
			temp = temp.next;
		}
		temp.next = insert_node;*/
		if(n==0) {
			head = insert_node;
			head.prev = null;
			head.next = null;
			end = head;
		}
		else{
			end.next = insert_node;
			insert_node.prev = end;
		}
		n+=1;
		end = insert_node;
	}
	
	
	public void pop(){
		LLNode temp;
		temp = head;
		for(int i=0;i<n-2;i++){
			temp = temp.next;
		}
		
		temp.next.prev = null;
		temp.next = null;
		n-=1;
	}
	
	
	public void remove(int pos){
		LLNode temp;
		temp = head;
		if(pos==0){
			if(n==0) return;
			head = head.next;
			if(head!=null) head.prev=null;
			n-=1;
		}
		else{
			for(int i=0;i<pos-1;i++){
				temp = temp.next;
			}
			temp.next = temp.next.next;
			temp.next.prev = temp;
			n-=1;
		}
	}
	
	public void clear(){
		head = null;
		n=0;
	}
	
	public int size(){
		return n;
	}
	
	
	public void print(){
		if(n==0) System.out.println("Empty List");
		else{
			LLNode temp;
			temp = head;
			
			for(int i=0;i<n;i++){
				System.out.print(temp.getData());
				System.out.print(" ");
				temp=temp.next;
			}
		}
		System.out.print("\n");
	}
	
	public String toString() {
		String response;
		response = new String("[");
		if(n==0) return response;
		else{
			LLNode temp;
			temp = head;
			
			for(int i=0;i<n;i++){
				//System.out.print(temp.getData());
				//System.out.print(" ");
				if(i!=n-1)
					response += temp.getData()+ ", ";
				else response += temp.getData();
				temp=temp.next;
			}
		}
		response+="]";
		return response;
	}
	
	public Object get(int pos) {
		if(pos==0) return head.data;
		LLNode temp;
		temp=head;
		for(int i=1;i<pos;i++){
			temp = temp.next;
		}
		return temp.data;
	}
	
	public int find(Object obj) {
		LLNode temp;
		temp=head;
		for(int i=0;i<n;i++){
			if(obj.equals(temp.data)) return 1;
			temp = temp.next;
		}
		return 0;
	}
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DLList test;
		test = new DLList();
		test.append("vikas22");
		test.append(1);
		test.append(100);
		test.print();
		System.out.println(test);
	}

}
