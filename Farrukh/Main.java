import queue.logic.Customer;
import queue.logic.EngineeredQueue;

import java.io.PrintWriter;
import java.nio.channels.ScatteringByteChannel;
import java.util.Scanner;

/**
 * modified : 11.02.2020
 */
public class Main {

    public static void main(String[] args) {
        System.out.println("Hello world.");
        try(Scanner scanner = new Scanner(System.in);
            PrintWriter printWriter = new PrintWriter(System.out)) {

            ConsoleQueue consoleQueue = new ConsoleQueue(scanner, printWriter);
        }
    }
}
