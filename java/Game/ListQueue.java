/*
File Name: ListQueue.java
Description: See ProgramDescription.txt 
Author: Anthony Hansen
Email Address: hansen.tony92@gmail.com
Date Created: Sun May 18 22:09:56 PDT 2014
*/
import java.util.Vector;
class ListQueue extends OrderedSet {

    private Vector<Comparable> elements = new Vector<Comparable>();

    void insert(Comparable x) {
        int i = 0;
        while (i < elements.size() && ((Comparable) elements.elementAt(i)).lessThan(x)) {
            i++;
        }
        elements.insertElementAt(x,i);
     }

     Comparable removeFirst() {
        if (elements.size() ==0) return null;
            Comparable x = (Comparable) elements.firstElement();
            elements.removeElementAt(0);
            return x;
     }

    Comparable remove(Comparable x) {
            for (int i = 0; i < elements.size(); i++) {
                if (elements.elementAt(i).equals(x)) {
                   Object y = elements.elementAt(i);
                   elements.removeElementAt(i);
                    return (Comparable) y;
                }
            }
        return null;
    }

    public int size() {
        return elements.size();
    }
}
