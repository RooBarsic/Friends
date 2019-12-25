import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;

public class Main {
	private HashMap<String, String> podstanovki = new HashMap<>();

    public static void main(String[] args) {
		if(args.length == 2){
			String shablonFileName = args[0];
			String podstanovkiFileName = args[1];
			if(parsePodstanovki(podstanovkiFileName) == 0){
				System.out.println("File " + podstanovkiFileName + " - don't exist or in wong format. Please check it");
			}
			else {
				if(changeShablon(shablonFileName) == 0){
					System.out.println("File " + shablonFileName + " - don't exist. Please check it");					
				}
			}
		}
		else {
			System.out.println("Wrong arguments.");
		}
    }
    
    public static int parsePodstanovki(final String inputFileName){
		try(Scanner scanner = new Scanner(new File(inputFileName));){
			while(scanner.hasNextLine()){
				String line = scanner.nextLine();
				StringBuilder keyBuilder = new StringBuilder("");
				StringBuilder valueBuilder = new StringBuilder("");
				int flag = 1;
				for(int i = 0; i < line.size(); i++){
					if(line.charAt(i) == '='){
						flag = 2;
					}
					else if(flag == 1){
						keyBuilder.append(line.charAt(i));
					}
					else {
						valueBuilder.append(line.charAt(i));
					}
				}
				String key = keyBuilder.toString();
				String value = valueBuilder.toString();
				podstanovki.put(key, value);
			}
			return 1;			
		} catch(Ex e){
			return 0;
		}
	}
	
	    public static int changeShablon(final String inputFileName){
		try(Scanner scanner = new Scanner(new File(inputFileName))){
			List<String> results = new ArrayList();
			while(scanner.hasNextLine()){
				String line = scanner.nextLine();
				StringBuilder buff = new StringBuilder("");
				StringBuilder parsedLine = new StringBuilder("");
				String resa = "";
				int flag = 0;
				for(int i = 0; i < line.size(); i++){
					buff.append(line.charAt(i));
					String key = buff.toString();
					if(podstanovki.containsKey(key)){
						resa = podstanovki.get(key);
						flag = 1;
					}
					else if(flag == 1){
						parsedLine.append(resa);
						buff.delete(0, buff.size());
					}
				}
				if(flag == 1){
					parsedLine.append(resa);					
				}
				results.add(parsedLine.toString());
			}
			scanner.close();
			try(PrintWriter printer = new PrintWriter(new File(inputFileName))){
				for(String row : results){
					printer.println(row);
					printer.flush();
				}
			}
			catch(Ex e){
				return 0;
			}
			return 1;			
		} catch(Ex e){
			return 0;
		}
	}
}
