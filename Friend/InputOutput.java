import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while(true){
            try {
                String commandName = scanner.next();
                switch (commandName) {
                    case "load":
                        try {
                            String pluginName = scanner.next();
                            String classpath = scanner.next();

                        } catch (Exception e){
                            System.out.println("Som Error while reading arguments for command 'load'");
                        }
                        break;
                    case "run":
                        try {
                            String pluginName = scanner.next();

                        } catch (Exception e){
                            System.out.println("Som Error while reading arguments for command 'run'");
                        }
                        break;
                    case "unload":
                        try {
                            String pluginName = scanner.next();

                        } catch (Exception e){
                            System.out.println("Som Error while reading arguments for command 'unload'");
                        }
                        break;
                    default:
                        System.out.println("Wrong command!!");
                        System.out.println("Please use one off this commands :");
                        System.out.println("load name classpath");
                        System.out.println("run name");
                        System.out.println("unload name");
                }
            }
            catch (Exception e){
                System.out.println("Some Error");
                e.printStackTrace();
            }
        }
    }

}
