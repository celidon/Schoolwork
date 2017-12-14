/*
File Name: MouseMove.java
Description: The assignement was to use the code from the GridLines project and
			use it to modify the BlankArea.java file so that a 25x25 grid was
			drawn in a GUI window. The code was then further modified to allow
			clicking on a square in the grid to toggle the square through a range of colors.
Author: Anthony Hansen
Email Address: hansen.tony92@gmail.com
Date Created: Sun May 18 21:44:11 PDT 2014
*/
/*
* MouseEventDemo.java
*/

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Point;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.*;

import javax.swing.*;

public class MouseMove extends JPanel
        implements MouseListener {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	BlankArea blankArea;
    JTextArea textArea;
    static final String NEWLINE = System.getProperty("line.separator");
    
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }
	
    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event dispatch thread.
     */
    private static void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame("MouseEventDemo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        //Create and set up the content pane.
        JComponent newContentPane = new MouseMove();
        newContentPane.setOpaque(true); //content panes must be opaque
        frame.setContentPane(newContentPane);
        
        //Display the window.
        frame.pack();
        frame.setVisible(true);
		frame.setResizable(false);
	}
    
    public MouseMove() {
        super(new GridLayout(0,1));
        blankArea = new BlankArea(Color.YELLOW);
        add(blankArea);
        //Register for mouse events on blankArea and the panel.
        blankArea.addMouseListener(this);
        addMouseListener(this);
        setPreferredSize(new Dimension(530, 530));
    }
    
    void eventOutput(String eventDescription, MouseEvent e) {
    	System.out.println(eventDescription + " detected on "
                + e.getComponent().getClass().getName()
                + "." + NEWLINE);
    }
    
    public void mousePressed(MouseEvent e) {
        eventOutput("Mouse pressed (# of clicks: " 
                + e.getClickCount() + ") and had " , e);
    }
    
    public void mouseReleased(MouseEvent e) {
    	Point p = e.getPoint();
    	int X = (int)p.getX();
    	int Y = (int)p.getY();
		int height=getHeight();
		int width=getWidth();
		int x=X/(height/27);
		int y=Y/(width/27);
    	//
        eventOutput("Mouse released with button " + String.format("%d",e.getButton())+ "(# of clicks: "
                + e.getClickCount() + ") Point=" + String.format("%d,%d",x,y), e);
	    blankArea.setValue(x,y);
		blankArea.repaint();
		
    }
    public void mouseEntered(MouseEvent e) {
    }
    
    public void mouseExited(MouseEvent e) {
    }
    
    public void mouseClicked(MouseEvent e) {
	
    }
}
