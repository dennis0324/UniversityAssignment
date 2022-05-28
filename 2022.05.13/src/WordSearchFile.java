import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Vector;
public class WordSearchFile {
    private Vector<String> linVector = new Vector<>();
    private Vector<Integer> lineNum = new Vector<>();
    private Scanner scanner = new Scanner(System.in);
    

    public void run(){
        String path = getFile();
        readfile(path);
        while(true){
            System.out.print("검색할 단어나 문장>>");
            String input = scanner.nextLine();
            if(input.equals("그만")){
                break;
            }
            searchWord(input);
            printline();
        }
    }
    private String getFile(){
        System.out.print("대상 파일명 검색>>");
        String fileURI = scanner.nextLine();
        File file = new File(fileURI);
        return file.toString();
    }
    private void readfile(String path){
        FileInputStream fin = null;

        try{
            fin = new FileInputStream(path);
            InputStreamReader isr = new InputStreamReader(fin,StandardCharsets.UTF_8);
            BufferedReader bufRead = new BufferedReader(isr);
            String inputBuffer = "";
            while((inputBuffer = bufRead.readLine()) != null ){
                linVector.add(inputBuffer);
            } 
            bufRead.close();

        }
        catch(IOException e){
            throw new RuntimeException(e);
        }
    }
    private void printline(){
        for (int i = 0; i < lineNum.size(); i++){
            int lineNo = lineNum.get(i);
            String line = linVector.get(lineNo);
            System.out.println((lineNo + 1) + " : " + line);
        }
    }
    private void searchWord(String word){
        for(int i = 0; i < linVector.size(); i++){
            String temp = linVector.get(i);
            if(temp.contains(word)){
                lineNum.add(i);
            }
        }
    }
    public static void main(String[] args){
        WordSearchFile ws = new WordSearchFile();
        ws.run();
        
        
    }
}
