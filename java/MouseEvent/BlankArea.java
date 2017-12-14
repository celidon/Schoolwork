/*
File Name: BlankArea.java
Description: The assignment is described in MouseMove.java. The majority of the
			code changes occured in this file.
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

import java.awt.Component;
import java.awt.Dimension;
import java.awt.Color;
import java.awt.Graphics;

public class BlankArea extends Component {

    public BlankArea(Color color) {
        setBackground(color);

    }

	private String[][] matrix=new String[27][27];
	//The following function allows the selected squares to be toggled. I decided
	//to allow each square to have three different forms of on before finally
	//going off
	public void setValue(int x, int y)
	{
		if(matrix[x][y]!="on"&&matrix[x][y]!="twice"&&matrix[x][y]!="third")
		{
			matrix[x][y]="on";
		}
		else if(matrix[x][y]=="on")
		{
			matrix[x][y]="twice";
		}
		else if(matrix[x][y]=="twice")
		{
			matrix[x][y]="third";
		}
		else
		{
			matrix[x][y]="off";
		}
	}

    public void paint(Graphics g) {
        int width = getWidth();
        int height = getHeight();
		//Drawing the original 25x25 grid
		for(int i=width/27; i<=width;i+=width/27)
		{
			g.drawLine(i,height/27,i,height-height/27);
		}
		for(int i=height/27; i<=height;i+=height/27)
		{
			g.drawLine(width/27,i,width-width/27,i);
		}
		//Checking to see what state the selected square is in and setting it's color.
		for(int i=1; i<26; i++)
		{
			for(int j=1; j<26; j++)
			{
				if(matrix[i][j]=="on")
				{
					g.setColor(Color.BLUE);
					g.fillRect((i)*width/27,(j)*height/27,width/27,height/27);
				}
				else if(matrix[i][j]=="twice")
				{
					g.setColor(Color.RED);
					g.fillRect((i)*width/27,(j)*height/27,width/27,height/27);
				}
				else if(matrix[i][j]=="third")
				{
					g.setColor(Color.YELLOW);
					g.fillRect((i)*width/27,(j)*height/27,width/27,height/27);
				}
			}
		}

    }
}
