import java.util.Scanner;

import javax.swing.plaf.basic.BasicSliderUI.ScrollListener;

class GamePlayer{
    private String name;
    GamePlayer(String name){
        this.name = name;
    }

    public String getName(){
        return name;
    }
}

public class GambleGame {
    private GamePlayer[] gamePlayer;
    Scanner scanner = new Scanner(System.in);

    GambleGame(){
        System.out.print("갬블링 게임에 참여할 숫자>>");
        int nPlayers = scanner.nextInt();
        gamePlayer = new GamePlayer[nPlayers];
    }

    public void inputName(){

        for(int i = 0; i < gamePlayer.length; i++){
            System.out.print(i + "번째 선수 이름>>");
            String name = scanner.next();
            gamePlayer[i] = new GamePlayer(name);
        }
        String key = scanner.nextLine();
    }

    public boolean compareNum(int[] arr){
        int comapreNumIndex = 0;
        for(int i =0; i< 3; i++){
            if(arr[i] != arr[comapreNumIndex]){
                return false;
            }
        }
        return true;
    }
    public void gameStart(){
        int[] randNum = new int [3];
        int index = 0;
        while(true){
            System.out.println("[" + gamePlayer[index % gamePlayer.length].getName() +"]:<Enter>");
            String key = scanner.nextLine();
            for(int i = 0; i < 3; i++){
                randNum[i] = (int)(Math.random() * 3) + 1;
                System.out.print(String.format("%5d",randNum[i]));
            }
            
            if(compareNum(randNum)){
                System.out.println(String.format("%10s님이 이겼습니다.",gamePlayer[index % gamePlayer.length].getName()));
                break;
            }
            else{
                System.out.println(String.format("%10s","아쉽습니다."));
            }
            index++;
        }
    }
    public void run(){
        inputName();
        gameStart();
    }

    public static void main(String[] args){
        GambleGame gambleGame = new GambleGame();
        gambleGame.run();
    }
}