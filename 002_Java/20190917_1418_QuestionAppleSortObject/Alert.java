import java.util.*;

/* Description : 
Given a list of alerts :
alert
	String name
	long date

method to sort the alerts

*/
public class Alert{


	String name;
	int date;

	public Alert(String s, int d){
		this.name = s;
		this.date = d;
	}

	public String toString(){
		return name + " " + date ;
	}

	static class SortByDate implements Comparator<Alert> { 
    // Used for sorting in ascending order of 
    // roll number 
	    public int compare(Alert a, Alert b) { 
	        return a.date - b.date; 
	    } 
	} 

	public void sortAlerts(ArrayList<Alert> t){

		Collections.sort(t,new SortByDate());

	}

	public static void main(String[] args){
		ArrayList<Alert> a = new ArrayList<Alert>();
		Alert a1 = new Alert("reveil",2);
		a.add(new Alert("reveil",2));
		a.add(new Alert("alarm",1));
		a.add(new Alert("alert",35));

		Collections.sort(a,new SortByDate());
		System.out.println(a.get(0));
		System.out.println(a.get(1));
		System.out.println(a.get(2));
	}

}


/* javac ....java
	java ...

*/