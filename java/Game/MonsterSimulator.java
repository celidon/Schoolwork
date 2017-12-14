/*
File Name: MonsterSimulator.java
Description: See ProgramDescription.txt 
Author: Anthony Hansen
Email Address: hansen.tony92@gmail.com
Date Created: Sun May 18 22:06:08 PDT 2014
*/
class MonsterSimulator extends Simulator{
    
  double hitpoints=30;
    
	 public double damageDealt(Hit h)
	 {
        if(h.getHit() == 3)
		{
			damage=6;
		}
        else if(h.getHit() == 2)
		{
			damage=3;
		}
        else if(h.getHit() == 1) 
		{
			damage=1.5;
		}
		return damage;
	 }
	 
    public String getStats(int num){
        return "Heavy:"+heavy*(100.0/num)+"\nMedium:"+medium*(100.0/num)+"\nLight:"+light*(100.0/num)+"\nNo Hit:"+nohit*(100.0/num);
    }
   
   public MonsterSimulator(int num) {
        events = new ListQueue();
        for(int i=0;i<num;i++){
           Hit h = new Hit();
           saveHit(h);
          insert( h );
        }
    }
}
