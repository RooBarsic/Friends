package com.company;

import java.util.ArrayList;

public class Main {
    private static ArrayList<Formula> formulas;

    public static void main(String[] args) {
        if(args.length == 1) {
            final String formulasStr = args[0];
             formulas = parseFormulas(formulasStr);

            for(int i = 0; i < formulas.size(); i++){
                countFormula(formulas.get(i));
                //System.out.println(" i = " + i + " formula = " + formulas.get(i).getFormula() + " val = " + formulas.get(i).getValue());
                System.out.println(formulas.get(i).getValue());
            }
        } else {
            System.out.println("Wrong arguments format.");
        }
	}

    public static void countFormula(final Formula formula){
        if(!formula.isCalculated()) {
            final String formulaStr = formula.getFormula();
            final StringBuilder builder = new StringBuilder();
            char operation1 = '+', operation2 = ' ';
            int result = 0, buff = 0;
            boolean isId = false;
            for (int i = 0; i < formulaStr.length(); i++) {
                if (('0' <= formulaStr.charAt(i)) && (formulaStr.charAt(i) <= '9')) {
                    builder.append(formulaStr.charAt(i));
                }
                else if(formulaStr.charAt(i) == '$'){
                    isId = true;
                }
                else {

                    int arg = Integer.parseInt(builder.toString());
                    builder.delete(0, builder.length());

                    if (isId) {
                        countFormula(formulas.get(arg));
                        arg = formulas.get(arg).getValue();
                        isId = false;
                    }

                    if ((operation2 == '*') || (operation2 == '/')) {
                        buff = doOperation(buff, arg, operation2);
                        operation2 = ' ';
                    } else {
                        buff = arg;
                    }

                    if ((formulaStr.charAt(i) == '*') || (formulaStr.charAt(i) == '/')) {
                        operation2 = formulaStr.charAt(i);
                    } else if (formulaStr.charAt(i) == '$') {
                        isId = true;
                    } else {
                        result = doOperation(result, buff, operation1);
                        operation1 = formulaStr.charAt(i);
                    }
                }
            }
            int arg = Integer.parseInt(builder.toString());
            builder.delete(0, builder.length());

            if (isId) {
                countFormula(formulas.get(arg - 1
                ));
                arg = formulas.get(arg).getValue();
            }

            if ((operation2 == '*') || (operation2 == '/')) {
                buff = doOperation(buff, arg, operation2);
                operation2 = ' ';
            } else {
                buff = arg;
            }
            result = doOperation(result, buff, operation1);
            formula.setValue(result);
        }
    }

    public static int doOperation(int a, int b, char operation){
        switch (operation){
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
        }
        return 0;
    }

	public static ArrayList<Formula> parseFormulas(final String formulasStr){
        final ArrayList<Formula> formulas = new ArrayList<>();
        final StringBuilder formulaBuilder = new StringBuilder();
        for(int i = 0; i < formulasStr.length(); i++){
            if(formulasStr.charAt(i) == '|'){
                formulas.add(new Formula(formulaBuilder.toString()));
                formulaBuilder.delete(0, formulaBuilder.length());
            } else {
                formulaBuilder.append(formulasStr.charAt(i));
            }
        }
        if(formulaBuilder.length() > 0){
            formulas.add(new Formula(formulaBuilder.toString()));
        }
        return formulas;
    }
}
