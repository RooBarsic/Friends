package exampler.console;

import org.jetbrains.annotations.NotNull;
import queue.logic.Customer;
import queue.logic.EngineeredQueue;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 *
 * Author: Farrukh Karimov
 * Modification Date: 12.02.2020
 */
public class ConsoleQueue {
    private final ControllerIO controllerIO;
    private final String availableCommands;
    private final Map<String, EngineeredQueue> queueByName = new HashMap<>();

    public ConsoleQueue(@NotNull final ControllerIO controllerIO){
        this.controllerIO = controllerIO;
        availableCommands = "\nadd-queue [queueName] \n" +
                            "clean-queue [queueName] \n" +
                            "remove-queue [queueName] \n" +
                            "queue-names-list \n" +
                            "queue-size [queueName] \n" +
                            "add-customer [queueName; customerPhoneNumber; customerName or '-' ] \n" +
                            "remove-customer [queueName; customerPhoneNumber; customerName or '-' ] \n" +
                            "customer-position [queueName; customerPhoneNumber; customerName or '-' ] \n" +
                            "help \n" +
                            "exit";
    }

    /**
     * Метод для запуска демонстрационной версии работы с очередями,
     * с поддержкой всех команд
     * @return возвращает true при успешном завершении работы.
     */
    public boolean runQueueDemo(){
        try {
            queueByName.clear();

            controllerIO.printMessage(" Please write one of following commands : ");
            controllerIO.printMessage(getAvailableCommandsInfo());

            String command = "-";
            while (!command.equals("exit")) {
                command = controllerIO.getField("command");
                switch (command) {
                    case "add-queue":
                        addQueue(controllerIO.getField("queue name"));
                        break;
                    case "clean-queue":
                        cleanQueue(controllerIO.getField("queue name"));
                        break;
                    case "remove-queue":
                        removeQueue(controllerIO.getField("queue name"));
                        break;
                    case "queue-names-list":
                        getQueuesNames().forEach(controllerIO::printMessage);
                        break;
                    case "queue-size":
                        int queueSize = queueSize(
                                controllerIO.getField("queue name")
                        );
                        controllerIO.printMessage(Integer.toString(queueSize));
                        break;
                    case "add-customer":
                        addCustomer(
                                controllerIO.getField("queue name"),
                                controllerIO.getCustomer()
                        );
                        break;
                    case "remove-customer":
                        removeCustomer(
                                controllerIO.getField("queue name"),
                                controllerIO.getCustomer()
                        );
                        break;
                    case "customer-position":
                        int customerPosition = getCustomerPosition(
                                controllerIO.getField("queue name"),
                                controllerIO.getCustomer()
                        );
                        controllerIO.printMessage(Integer.toString(customerPosition));
                        break;
                    case "help":
                        controllerIO.printMessage(getAvailableCommandsInfo());
                        break;
                    case "exit":
                        controllerIO.printMessage("Bye.");
                        break;
                    default:
                        controllerIO.printErrorMessage("Wrong command name.");
                        controllerIO.printMessage("Please write one of following commands :");
                        controllerIO.printMessage(getAvailableCommandsInfo());
                }
            }
        } catch (Exception e){
            e.printStackTrace();
            return false;
        }
        return true;
    }

    /**
     * Метод для получения информации о доступных командах
     */
    public String getAvailableCommandsInfo(){
        return availableCommands;
    }

    /**
     * Метод для проверки существования очереди
     * @param queueName получает на вход имя очереди
     * @return возвращет true если очередь с таким именем существует
     */
    private boolean queueExist(@NotNull final String queueName){
        if(!queueByName.containsKey(queueName)){
            controllerIO.printErrorMessage("queue " + queueName + " not exist");
            return false;
        }
        return true;
    }

    /**
     * Метод для добавления новой очереди
     * @param queueName получает на вход имя очереди
     * @return возвращает false если очередь с таким именем уже существует
     */
    private boolean addQueue(@NotNull final String queueName){
        if(queueByName.containsKey(queueName)) {
            controllerIO.printErrorMessage("queue " + queueName + " already exist. ");
            return false;
        }
        queueByName.put(queueName, new EngineeredQueue(queueName));
        return true;
    }

    /**
     * Метод для очистки содержимого очереди
     * @param queueName получает на вход имя очереди
     * @return возвращет false если очередь с таким название не существует
     */
    private boolean cleanQueue(@NotNull final String queueName){
        if(queueExist(queueName)){
            queueByName.get(queueName).clear();
            return true;
        }
        return false;
    }

    /**
     * Метод для удаления очереди по имени
     * @param queueName почвет на вход имя очереди
     */
    private void removeQueue(@NotNull final String queueName){
        queueByName.remove(queueName);
    }

    /**
     * Метод для получения списка имён существующих очередей
     * @return возвращает список имён существующих очередей
     */
    private List<String> getQueuesNames(){
        return new ArrayList<>(queueByName.keySet());
    }

    /**
     * Метод для получаения информации о количестве клиентов в очереди по имени очереди
     * @param queueName получает на вход имя очереди
     * @return возвращает -1 - если такая очередь не существует, иначе возвращает количество кливентов в очереди
     */
    private int queueSize(@NotNull final String queueName){
        if(!queueExist(queueName)){
            return -1;
        }
        return queueByName
                .get(queueName)
                .queueSize();
    }

    /**
     * Метод для добавления клиента в очередь.
     * Получает на вход :
     * @param queueName имя очереди
     * @param customer клиент которого надо добавить в эту очередь
     * @return возвращет true - если клиент успешно добавлен
     */
    private boolean addCustomer(@NotNull final String queueName, @NotNull final Customer customer){
        return queueExist(queueName) &&
                queueByName.get(queueName)
                        .addCustomer(customer);
    }

    /**
     * Метод для удаления клиента из очередь.
     * Получает на вход :
     * @param queueName имя очереди
     * @param customer клиент которого надо удалить из этой очереди
     * @return возвращет true - если клиент успешно удалён
     */
    private boolean removeCustomer(@NotNull final String queueName, @NotNull final Customer customer){
        return queueExist(queueName) &&
                queueByName.get(queueName)
                        .removeCustomer(customer);
    }

    /**
     * Метод для получения позиции клиента в очереди.
     * Получает на вход :
     * @param queueName имя очереди
     * @param customer клиент позицию которого ищем в этой очереди
     * @return возвращет -1 - если такой клиент не найден в этой очереди, иначе возвращет позицию клиента в очереди
     */
    private int getCustomerPosition(@NotNull final String queueName, @NotNull final Customer customer){
        if(!queueExist(queueName)){
            return -1;
        }
        return queueByName
                .get(queueName)
                .findCustomerPosition(customer);
    }
}
