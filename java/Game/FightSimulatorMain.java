/*
File Name: FightSimulatorMain.java
Description: See gamedescription.txt 
Author: Anthony Hansen
Email Address: hansen.tony92@gmail.com
Date Created: Sun May 18 22:03:17 PDT 2014
*/
import java.util.Random;
import javax.swing.JOptionPane;
class FightSimulatorMain {

    public static void main(String[] args) {
        start();
    }

    public static void start(){
        int i=1;
		int num=10;
		HeroSimulator hs  = new HeroSimulator(num);
        MonsterSimulator ms  = new MonsterSimulator(num);
		JOptionPane.showMessageDialog(null,"HERO HP: "+hs.hitpoints+"\nMONSTER HP: "+ms.hitpoints);
        while((hs.hitpoints>0 && ms.hitpoints>0)&&i<=num){
			System.out.println("Round "+i);
			int hd;
			Random r=new Random();
			hd=Math.abs(r.nextInt())%100+1;
			Event heroHit = hs.nextEvent();
            Event monsterHit = ms.nextEvent();
			double mDamage=hs.damageDealt((Hit)heroHit);
			double hDamage=ms.damageDealt((Hit)monsterHit);
			if(hd<=75)
			{
				hs.hitpoints-=hDamage;
				System.out.println("The hero was hit!(Damage: "+hDamage+")");
			}
			ms.hitpoints-=mDamage;
			
			i++;
			System.out.println("HERO HP: "+hs.hitpoints);
			System.out.println("MONSTER HP: "+ms.hitpoints);
		}
		JOptionPane.showMessageDialog(null,"In "+(i-1)+" rounds:\nHero: "+hs.hitpoints+"\nMonster: "+ms.hitpoints);
		
        if(ms.hitpoints<=0) JOptionPane.showMessageDialog(null,"Monster died.\nHero WINS!\n");
		else if(hs.hitpoints<=0) JOptionPane.showMessageDialog(null,"Hero died.\nThe monster now rules the world!\n");
		else 
		{
			if(hs.hitpoints>ms.hitpoints) JOptionPane.showMessageDialog(null,"Hero wins,but the monster still lives....\n");
			else if(hs.hitpoints<ms.hitpoints) JOptionPane.showMessageDialog(null,"The monster brutally wounded the hero, but he will return.\n");
			else if(hs.hitpoints==ms.hitpoints) JOptionPane.showMessageDialog(null,"The two have beaten each other to a standstill.\n");
		}
		JOptionPane.showMessageDialog(null,"Game Over! Thanks for playing!");
		System.exit(1);
        //System.out.println("Hero Stats(%):\n"+hs.getStats(num)+"\n");
        //System.out.println("Monster Stats(%):\n"+ms.getStats(num));
    }
}
