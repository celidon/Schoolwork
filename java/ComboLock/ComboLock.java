/*
   File Name: Main.java
   Developer: Anthony Hansen
   Date Last Modified: 16.04.2014
   Description: The assignment was to write a program that simulates a combination
				lock with a 3 number combination, a dial that goes between 0 and
				39, and functions to reset the lock, turn the dial both directions,
				and try to open the lock.
Email Address: hansen.tony92@gmail.com
*/

public class ComboLock
{
    // instance variables - replace the example below with your own
    private int num1, num2, num3, guess1, guess2, guess3, cnum=0;

    /**
     * Constructor for objects of class ComboLock
     */
    public ComboLock(int secret1, int secret2, int secret3)
    {
        num1=secret1;
        num2=secret2;
        num3=secret3;
    }

    public void reset()
    {
       cnum=0;
       guess1=0;
       guess2=0;
       guess3=0;
    }
    
    public void turnLeft(int ticks)
    {
        cnum=cnum+ticks;
        while(cnum>39)
        {
            cnum-=40;
        }
        guess2=cnum;
    }
    
    public void turnRight(int ticks)
    {
        cnum=cnum-ticks;
        while(cnum<0)
        {
            cnum+=40;
        }
        if(guess1!=num1)
        {
            guess1=cnum;
        }
        if(guess3!=num3)
        {
            guess3=cnum;
        }
    }
    
    public void open()
    {
        System.out.println(guess1==num1&&guess2==num2&&guess3==num3 ? "Lock open!":"Lock locked!");
    }
}
