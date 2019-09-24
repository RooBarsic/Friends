import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Farrukhruz {
    public static void main(String[] args) {
        Scanner stdReader = new Scanner(System.in);
        System.out.print("Write file name(path) : ");
        String fileName = stdReader.next();

        try {
            Scanner fileReader = new Scanner(new File(fileName));
            while(fileReader.hasNextLine()){
                String fileRow = fileReader.nextLine();
                StringBuilder result = new StringBuilder();
                for(int i = 0; i < fileRow.length(); i++){
                    if(i > 0){
                        if((fileRow.charAt(i) == ' ') && (fileRow.charAt(i - 1) != ' ')){
                            result.append(fileRow.charAt(i));
                        }
                        else if((('a' <= fileRow.charAt(i)) && (fileRow.charAt(i) <= 'z')) || (('A' <= fileRow.charAt(i)) && (fileRow.charAt(i) <= 'Z'))){
                            if((i + 1 < fileRow.length()) && ((fileRow.charAt(i - 1) != ' ') || (fileRow.charAt(i + 1) != ' '))){
                                result.append(fileRow.charAt(i));
                            }
                            else if(i + 1 == fileRow.length()){
                                result.append(fileRow.charAt(i));
                            }
                        }
                    }
                    else {
                        result.append(fileRow.charAt(i));
                    }
                }
                System.out.println(result.toString());
            }
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
            e.printStackTrace();
        }
    }
}
