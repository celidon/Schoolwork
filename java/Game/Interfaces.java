/*
File Name: Interfaces.java
Description: See ProgramDescription.txt 
Author: Anthony Hansen
Email Address: hansen.tony92@gmail.com
Date Created: Sun May 18 22:09:19 PDT 2014
*/
interface Comparable {
    boolean lessThan(Comparable y);
}

abstract class  AbstractEvent implements Comparable {
    abstract String execute(AbstractSimulator simulator);
}

abstract class OrderedSet {
    abstract void insert(Comparable x);
    abstract Comparable  removeFirst();
    abstract int size();
    abstract Comparable remove(Comparable x);
}
    
class AbstractSimulator {

    OrderedSet events;
    void insert(AbstractEvent e) {
        events.insert(e);
    }
    AbstractEvent cancel(AbstractEvent e)  {
        throw new java.lang.RuntimeException("Method not implemented");
    }
}
