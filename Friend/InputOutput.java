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
                            e.printStackTrace();
                        }
                        break;
                    case "run":
                        try {
                            String pluginName = scanner.next();

                        } catch (Exception e){
                            System.out.println("Som Error while reading arguments for command 'run'");
                            e.printStackTrace();
                        }
                        break;
                    case "unload":
                        try {
                            String pluginName = scanner.next();

                        } catch (Exception e){
                            System.out.println("Som Error while reading arguments for command 'unload'");
                            e.printStackTrace();
                        }
                        break;
                    default:
                        System.out.println("Wrong command!!");
                        System.out.println("Please use one of these commands :");
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
