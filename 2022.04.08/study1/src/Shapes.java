
interface Shape {
    final double PI = 3.14;
    void draw();
    double getArea();
    default public void redraw(){
        System.out.print("--- 다시 그립니다. ---");
        draw();
    }
}

class Circle implements Shape{
    private int radius; //반지름
    
    public Circle(int radius){
        this.radius = radius;
    }

    public void draw(){
        System.out.println("반지름 " + radius + "인 원입니다.");
    }
    
    public double getArea(){
        return PI * radius * radius;
    }
}

class Oval implements Shape{
    private int radiusX, radiusY;
    
    public Oval(int radiusX, int radiusY){
        this.radiusX = radiusX;
        this.radiusY = radiusY;
    }

    public void draw(){
        System.out.println(radiusX + "x" + radiusY + "에 내접하는 원입니다.");
    }

    public double getArea(){
        return radiusX * radiusY * PI;
    }
}

class Rect implements Shape{
    private int x,y;

    public Rect(int x,int y){
        this.x = x;
        this.y = y;
    }

    public void draw(){
        System.out.println(x + "x" + y + "크기의 사각형 입니다.");
    }

    public double getArea(){
        return x * y;
    }
}


public class Shapes {

    public static void main(String[] args){
        Shape [] list = new Shape[3];
        list[0] = new Circle(10);
        list[1] = new Oval(20,30);
        list[2] = new Rect(10,40);

        for(int i = 0; i < list.length; i++) list[i].redraw();
        for(int i = 0;i < list.length; i++)
            System.out.println("면적은 " + list[i].getArea());
    }



}
