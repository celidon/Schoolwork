/*
File Name: GridLinesPanel.java
Description: The assignment was to modify this and the code contained in 
			GridLinesApp.java so that a 25x25 grid was drawn in a GUI window.
Author: Anthony Hansen
Email Address: hansen.tony92@gmail.com
Date Created: Sun May 18 21:41:53 PDT 2014
*/
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JPanel;

public class GridLinesPanel extends JPanel {

   public GridLinesPanel() {
   
   }
   
   public void paintComponent(Graphics g) {
   
      super.paintComponent(g);  // Call the paintComponent method from the 
                                // superclass, JPanel.  This simply fills the 
                                // entire panel with the background color, black.
      
      int width = getWidth();
      int height = getHeight();
	  for(int i=0; i<=500;i+=20)
	  {
	    g.drawLine(i,0,i,500);
		g.drawLine(0,i,500,i);
	  }
		
   } // end paintComponent()
   

}  // end class GridLinesPanel
