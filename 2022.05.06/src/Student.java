import java.util.ArrayList;
import java.util.Scanner;

class Student{
    private String name;
    private String subject;
    private int id;
    private double gpa;

    Student(String name,String subject,int id,double gpa){
        this.name = name;
        this.subject = subject;
        this.id = id;
        this.gpa = gpa;
    }

    public String getName(){
        return name;
    }
    public String getSubject(){
        return subject;
    }
    public int getId(){
        return id;
    }
    public double getGPA(){
        return gpa;

    }
}

