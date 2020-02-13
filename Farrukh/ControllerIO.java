package exampler.console;

import java.util.Scanner;
import org.jetbrains.annotations.NotNull;
import queue.logic.Customer;

import java.io.PrintWriter;

/**
 * Вспомогательный класс для работы с консолью
 * Author: Farrukh Karimov
 * Modification Date: 12.02.2020
 */

public class ControllerIO {
    private final String ostup = ":::";
    private final Scanner scanner;
    private final PrintWriter printer;

    public ControllerIO(@NotNull final Scanner scanner, @NotNull final PrintWriter printer){
        this.scanner = scanner;
        this.printer = printer;
    }

    /**
     * Метод для чтения параметра из консоли
     * @param fieldName принимает на вход название параметра
     * @return возвращает значение параметра
     */
    public String getField(@NotNull final String fieldName){
        printer.print(ostup + " " + fieldName + " : ");
        printer.flush();
        return scanner.next();
    }

    /**
     * Метод для чтения/получения клиента из консоли
     * @return возвращает обект класса Customer
     */
    public Customer getCustomer(){
        final String customerPhoneNumber = getField("phone");
        final String customerName = getField("name");
        return new Customer(customerName, customerPhoneNumber);
    }

    /**
     * Метод для вывода  сообщений
     * @param message принимает на вход текст сообщения
     */
    public void printMessage(@NotNull final String message){
        printer.println(ostup + " " + message);
        printer.flush();
    }

    /**
     * Метод для вывода предупреждающих сообщений ( сообщений об ошибках )
     * @param message принимает на вход текст сообщения
     */
    public void printErrorMessage(@NotNull final String message){
        printMessage(ostup + " ATTENTION!!! " + message);
        printer.flush();
    }

}
