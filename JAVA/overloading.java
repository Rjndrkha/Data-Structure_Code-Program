import java.util.*;
import java.lang.*;
import java.io.*;


public class circle3 {
    public static void main(String[] args) {
        CircleOverload c1 = new CircleOverload();
        System.out.println("The center coordinates are: (" + c1.getX()+","+c1.getY()+")");
        System.out.println("The radius is: " + c1.getRadius());

        CircleOverload c2 = new CircleOverload(5,3);
        System.out.println("The center coordinates are: (" + c2.getX()+","+c2.getY()+")");
        System.out.println("The radius is: " + c2.getRadius());

        CircleOverload c3 = new CircleOverload(5,3,4);
        System.out.println("The center coordinates are: (" + c3.getX()+","+c3.getY()+")");
        System.out.println("The radius is: " + c3.getRadius());

    }
}

class CircleOverload {

    private int x=5;
    private int y=3;
    private int radius=4;

    CircleOverload() {
        this.x = 5;
        this.y = 3;
        this.radius = 4; 
    }

    CircleOverload(int x, int y) {
        this.x = x;
        this.y = y;
        this.radius = 4; 
    }
    
    CircleOverload(int x, int y, int r) {
        this.x = x;
        this.y = y;
        this.radius = r;
    }

    public void initCenter(int a,int b){
        this.x=a;
        this.y =b;
    }
    public void initRadiss(int r){
        this.radius=r;
        
    }
    public int getX() { return x; }
    public int getY() { return y; }
    public int getRadius() { return radius; }
}

