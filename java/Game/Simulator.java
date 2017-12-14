/*
File Name: Simulator.java
Description: See ProgramDescription.txt 
Author: Anthony Hansen
Email Address: hansen.tony92@gmail.com
Date Created: Sun May 18 22:08:11 PDT 2014
*/
abstract class Event extends AbstractEvent {
    double time;

    public boolean lessThan(Comparable y) {
        Event e = (Event) y;  // Will throw an exception if y is not an Event
        return this.time < e.time;
    }
}

class Simulator extends AbstractSimulator {
    double time;
	double damage;
	double hitpoints;
	int heavy=0,medium=0,light=0,nohit=0;
    double now() {
        return time;
    }

    Event nextEvent(){
        return (Event) events.removeFirst();
    }

    String executeNext(){
        Event e  = (Event) events.removeFirst();
        return e.execute(this);
    }
	protected void saveHit(Hit h)
	{
		if(h.getHit()==3)
		{
			heavy++;
		}
		else if(h.getHit()==2)
		{
			medium++;
		}
		else if(h.getHit()==1)
		{
			light++;
		}
		else nohit++;
	}

    void doAllEvents() {
        Event e;
        while ( (e= (Event) events.removeFirst()) != null) {
            time = e.time;
            e.execute(this);
        }
    }
}
