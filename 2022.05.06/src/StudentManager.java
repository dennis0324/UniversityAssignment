import java.util.*;



public class StudentManager {
    private int studentCount;
    private Scanner scanner = new Scanner(System.in);
    private ArrayList<Student> arrlist =new ArrayList<>();

    StudentManager(int count){
        studentCount = count;
    }

    public void printAll(){
        Iterator<Student> iter = arrlist.iterator();
        while(iter.hasNext()){
            Student s = iter.next();
            if(s.getName() == null) return;
            System.out.println("-".repeat(20));
            System.out.println("이름:" +s.getName());
            System.out.println("학과:" +s.getSubject());
            System.out.println("학번:" +s.getId());
            System.out.println("학점평균:" +s.getGPA());
            System.out.println("-".repeat(20));
        }
        }

    public void read(){
        System.out.println("학생 이름, 학과, 학번, 학점평균을 입력하세요.");
        String name, department;
        int id;
        double grade;
        for(int i =0; i< studentCount;i++){
            System.out.print(">>");
            String temp = scanner.nextLine();
            String[] datas = temp.replace(" ", "").split(",");
            if(datas.length != 4){
                System.err.println(",를 사용하여 구분해주세요");
                i -= 1;
                continue;
            }
            name = datas[0];
            department = datas[1];
            id = Integer.parseInt(datas[2]);
            grade = Double.parseDouble(datas[3]);
            Student st =new Student(name,department,id,grade);
            arrlist.add(st);
            
        }
    }

    public void processQuery(){
        String name;
        Iterator<Student> iter;
        while(true){
            iter = arrlist.iterator();
            System.out.print("학생 이름>>");
            name = scanner.next();
            if(name.equals("그만")) break;

            while(iter.hasNext()){
                Student s = (Student)iter.next();
                if(name.equals(s.getName())){
                    System.out.println(s.getName() + ", " + s.getSubject() + ", " + s.getId() + ", " + s.getGPA());
                }
            }
        }
    }
    public void run(){
        read();
        printAll();
        processQuery();
    }

    public static void main(String[] args){
        StudentManager manager = new StudentManager(4);
        manager.run();


    }
}
