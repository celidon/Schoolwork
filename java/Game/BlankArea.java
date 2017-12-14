/*
File Name: BlankArea.java
Description: The assignment is described in gamedescription.text
Author: Anthony Hansen
Email Address: hansen.tony92@gmail.com
Date Created: Sun May 18 21:48:19 PDT 2014
*/
/*
 * BlankArea.java is used by:
 *    MouseEventDemo.java.
 *    MouseMotionEventDemo.java
 */

import javax.swing.*;
import javax.imageio.*;
import java.io.*;
import java.awt.image.*;
import java.awt.event.*;
import java.awt.*;

public class BlankArea extends JTextArea {

   BufferedImage hero;
   BufferedImage monster;
   
	private String[][] matrix=new String[27][27];
	public void setValue(int x, int y,String setting)
	{
		matrix[x][y]=setting;
	}

	public BlankArea(Color color)
	{
		try{
				hero=ImageIO.read(new File("hero.jpg"));
				monster=ImageIO.read(new File("monster.jpg"));
		}
		catch(IOException e){System.out.println("File not found");}
		
		setBackground(color);
		
       
		}
		

    public void paint(Graphics g) {
        int width = getWidth();
        int height = getHeight();
		//Drawing the original 25x25 grid
		g.setColor(Color.GRAY);
		g.fillRect(0,0,width,height);
		
		//Checking to see what state the selected square is in and setting it's color.
		for(int i=1; i<26; i++)
		{
			for(int j=1; j<26; j++)
			{
				//if(i<=3&&j<=3) System.out.println(matrix[i][j]);
				
				if(matrix[i][j]=="hero")
				{
					g.drawImage(hero,i*width/27,j*height/27,null);
				}
				else if(matrix[i][j]=="monster")
				{
					g.drawImage(monster,i*width/27,j*height/27,null);
				}
				else
				{
					g.fillRect((i)*width/27,(j)*height/27,width/27,height/27);
				}
				
			}
		}
		g.setColor(Color.BLACK);
		for(int i=width/27; i<=width;i+=width/27)
		{
			g.drawLine(i,height/27,i,height-height/27);
		}
		for(int i=height/27; i<=height;i+=height/27)
		{
			g.drawLine(width/27,i,width-width/27,i);
		}
		//repaint();
		
    }
}
