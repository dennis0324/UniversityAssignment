import java.util.Scanner;

public class StringHistogramApp {
    final int ALPABETCOUNT = 26;
    int[] alpaArr = new int[ALPABETCOUNT];

    StringHistogramApp(){
        for(int i =0; i < alpaArr.length; i++){
            alpaArr[i] = 0;
        }
    }

    public String getString(){
        StringBuffer sb = new StringBuffer();
        Scanner scanner = new Scanner(System.in);
        while(true){
            String line = scanner.nextLine();
            if(line.equals(";")){
                break;
            }
            sb.append(line);
        }
        scanner.close();
        return sb.toString();
    }

    public void printHistogram(String str){
        for(int i = 0; i < str.length(); i++){
            char character = str.charAt(i);
            
            character = Character.toUpperCase(character);
            if(!Character.isAlphabetic(character)){
                continue;
            }
            alpaArr[character - 'A']++;
        }

        for(int i = 0; i < str.length(); i++){
            System.out.print((char)('A' + i) + " : " + "-".repeat(alpaArr[i]) + "\n");
        }
    }
    public static void main(String[] args){
        StringHistogramApp stringHistogramApp = new StringHistogramApp();
        String returnValue = stringHistogramApp.getString();
        stringHistogramApp.printHistogram(returnValue);
    }
}
