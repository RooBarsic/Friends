
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    private static final List<String> optionsList = new ArrayList<>();

    public static void main(String[] args) {
        initOptions();
        String fileName = null;
        if(args.length == 0){
            System.out.println(" Error. No option was found ");
            return;
        } else {
            int n = args.length;
            if(args.length > 1){
                fileName = args[args.length - 1];
                n--;
            }
            List<String> data = getData(fileName);
            for(int i = 0; i < n; i++){
                execute(data, args[i]);
            }
        }
    }

    public static void initOptions(){
        optionsList.add("--ignore-leading-blanks" );
        optionsList.add("--dictionary-order" );
        optionsList.add( "--ignore-case" );
        optionsList.add( "--ignore-nonprinting");
        optionsList.add( "--numeric-sort" );
        optionsList.add( "--reverse" );
    }

    public static void execute(final List<String> data, final String option){
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
