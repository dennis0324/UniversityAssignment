import java.util.*;

class Player{
    private String name;
    private Calendar calendar;
    public Player(String name){
        this.name = name;
    }

    public int turn(){
        Scanner scanner = new Scanner(System.in);

        int start, end;
        System.out.print(getName()+" 시작 <ENTER>키 >>");
        String key = scanner.nextLine();
        start = Calendar.getInstance().get(Calendar.SECOND);
        System.out.println("현재 초 시간 = " + start);
        System.out.print(getName()+" 10초 예상 후 <ENTER>키 >>");
        key = scanner.nextLine();
        end = Calendar.getInstance().get(Calendar.SECOND);

        if(end < start)
            end += 60;
        return end - start;
    }
    public String getName(){
        return name;
    }

    public int getSecond(){
        return calendar.get(Calendar.SECOND); 
    }

}

public class GuessTimeGame {
    private Player players[] = new Player[2];

    public GuessTimeGame(){
        players[0] = new Player("철이");
        players[1] = new Player("순이");
    }
    public void run(){
        System.out.println("10초에 가까운 사람이 이기는 게임입니다.");
        int start,end;

        int duration1 = players[0].turn();
        int duration2 = players[1].turn();

        System.out.println(players[0].getName() + "의 결과 " + duration1 + ".");
        System.out.println(players[1].getName() + "의 결과 " + duration2 + ".");

        System.out.println("승자는 ");
        if(Math.abs(10 -duration1) < Math.abs(10 - duration2))
            System.out.println(players[0].getName());
        else
            System.out.println(players[1].getName());
    }

    public static void main(String[] args){
        GuessTimeGame game = new GuessTimeGame();
        game.run();
    }
    
}
