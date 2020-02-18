import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        System.out.println(dictionaryOrder("A#", "Aa"));
        String option = null, fileName = null;
        if(args.length == 0){
            System.out.println(" Error. No option was found ");
            return;
        } else if(args.length == 1){
            option = args[0];
        } else if(args.length == 2){
            option = args[0];
            fileName = args[1];
        } else if(args.length > 2) {
            System.out.println(" Error. Too many options are given. ");
            return;
        }
        execute(option, fileName);
    }

    public static void execute(final String option, final String fileName){
        List<String> inputData = getData(fileName);
        switch(option){
            case "--ignore-leading-blanks" :
                break;
            case "--dictionary-order" :
                inputData.sort(Main::dictionaryOrder);
                break;
            case "--ignore-case" :
                inputData.sort(String::compareToIgnoreCase);
                break;
            case "--ignore-nonprinting":
                break;
            case "--numeric-sort" :
                break;
            case "--reverse" :
                inputData.sort((a, b) -> -a.compareTo(b));
                break;
            case "--" :
                inputData.sort(String::compareTo);
            default:
                System.out.println(" Error. Wrong option! ");
        }

        printData(inputData);
    }

    public static void printData(final List<String> data){
        for (String row : data){
            System.out.println(row);
        }
    }

    public static boolean isDictionaryLetter(char a){
        if((('A' <= a) && (a <= 'Z')) || (('a' <= a) && (a <= 'z')) || (('0' <= a) && (a <= '9'))){
            return true;
        }
        return false;
    }

    public static int dictionaryOrder(final String a, final String b){
        int aLeft = 0, bLeft = 0;
        while((aLeft < a.length()) && (bLeft < b.length())){
            if(isDictionaryLetter(a.charAt(aLeft)) && isDictionaryLetter(b.charAt(bLeft))) {
                if (a.charAt(aLeft) < b.charAt(bLeft)) return -1;
                if (a.charAt(aLeft) > b.charAt(bLeft)) return +1;
                aLeft++;
                bLeft++;
            } else {
                if(!isDictionaryLetter(a.charAt(aLeft))){
                    aLeft++;
                }
                if(!isDictionaryLetter(b.charAt(bLeft))){
                    bLeft++;
                }
            }
        }
        while(aLeft < a.length()){
            if(isDictionaryLetter(a.charAt(aLeft))){
                return -1;
            }
            aLeft++;
        }
        while(bLeft < b.length()){
            if(isDictionaryLetter(b.charAt(bLeft))){
                return +1;
            }
            bLeft++;
        }
        return 0;
    }

    public static List<String> getData(final String fileName){
        final List<String> inputData = new ArrayList<>();
        Scanner scanner = null;
        try {
            if (fileName == null) {
                scanner = new Scanner(System.in);
            } else {
                scanner = new Scanner(new File(fileName));
            }
            while (scanner.hasNext()) {
                final String inputLine = scanner.nextLine();
                inputData.add(inputLine);
            }
        } catch (FileNotFoundException e) {
            System.out.println("file with name " + fileName + " was not found.");
            e.printStackTrace();
        } finally {
            if(scanner != null){
                scanner.close();
            }
            return inputData;
        }
    }
}
