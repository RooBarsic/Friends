
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
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
                break;
            case "--ignore-case" :
                break;
            case "--ignore-nonprinting":
                break;
            case "--numeric-sort" :
                break;
            case "--reverse" :
                break;
            default:
                System.out.println(" Error. Wrong option! ");
        }
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
