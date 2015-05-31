
public class Stack extends LList{

	/**
	 * @param args
	 */
	public void push(Object obj){
		this.append(obj);
	}
	
	public void pop(){
		this.pop_last();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack vik; 
		vik = new Stack();
		
		vik.append(10);
		System.out.println(vik);
		
		vik.pop();
		System.out.println(vik);
		
		vik.append("vikas");
		System.out.println(vik);

	}
	
}
