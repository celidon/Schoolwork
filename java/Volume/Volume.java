/*
   File Name: Volume.java
   Developer: Anthony Hansen
   Date Last Modified: 12.03.2014
   Description: The assignment was to write a program that allows the user to
				input a radius and a height and will output the values of the
				volume and surface area of a sphere, cylinder, and cone using
				the input.
Email Address: hansen.tony92@gmail.com
*/

import java.util.Scanner;

public class Volume
{
	public static double sphereVolume(double r)
	{
		double volume;
		
		volume=(4.0/3)*Math.PI*Math.pow(r,3);
		
		return volume;
	}
	
	public static double sphereSurface(double r)
	{
		double surface;
		
		surface=4*Math.PI*Math.pow(r,2);
		
		return surface;
	}
	
	public static double cylinderVolume(double r, double h)
	{
		double volume;
		
		volume=h*Math.PI*Math.pow(r,2);
		
		return volume;
	}
	
	public static double cylinderSurface(double r, double h)
	{
		double surface;
		
		surface=(2*Math.PI*r*h)+(2*Math.PI*Math.pow(r,2));
		
		return surface;
	}
	
	public static double coneVolume(double r, double h)
	{
		double volume;
		
		volume=(h/3)*Math.PI*Math.pow(r,2);
		
		return volume;
	}
	
	public static double coneSurface(double r, double h)
	{
		double surface;
		
		surface=Math.PI*r*(r+Math.sqrt(Math.pow(r,2)+Math.pow(h,2)));
		
		return surface;
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		
		System.out.println("Please enter a radius length:");
		double r=in.nextDouble();
		
		System.out.println("Please enter a height:");
		double h=in.nextDouble();
		
		double sphVol=sphereVolume(r);
		double sphSA=sphereSurface(r);
		
		double cylVol=cylinderVolume(r,h);
		double cylSA=cylinderSurface(r,h);
		
		double coneVol=coneVolume(r,h);
		double coneSA=coneSurface(r,h);
		
		System.out.println("For a sphere with a radius of "+r);
		System.out.println("Volume: "+sphVol);
		System.out.println("Surface Area: "+sphSA+"\n");
		
		System.out.println("For a cylinder with a radius of "+r+" and a height of "+h);
		System.out.println("Volume: "+cylVol);
		System.out.println("Surface Area: "+cylSA+"\n");
		
		System.out.println("For a cone with a radius of "+r+" and a height of "+h);
		System.out.println("Volume: "+coneVol);
		System.out.println("Surface Area: "+coneSA+"\n");
	}
}