import javax.swing.JOptionPane;

public class HelloWorld {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String name = JOptionPane.showInputDialog("What is your name?");
		System.out.print("Hello, ");
		System.out.println(name);

	}

}
