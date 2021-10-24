package com.csc2310.lab05;

import java.util.Scanner;

public class InputReader {
    private static final InputReader ir = new InputReader();
    private final Scanner scan;

    private InputReader() {
        scan = new java.util.Scanner(System.in);
    }

    public static InputReader getInputReader() {
        return ir;
    }

    public int readIntegerValue(String prompt) {
        System.out.println(prompt);
        int number = 0;

        try {
            number = scan.nextInt();
            readStringValue(""); // clear the buffer
        } catch (java.util.InputMismatchException e) {
            readStringValue("");
            number = 0;
        } catch (java.util.NoSuchElementException e) {
            readStringValue("");
            number = 0;
        }
        return number;
    }

    public String readStringValue(String prompt) {
        System.out.println(prompt);
        String string = "";

        try {
            string = scan.nextLine().trim();
        } catch (java.util.NoSuchElementException e) {
            readStringValue("");
            string = "";
        }

        return string;
    }
}
