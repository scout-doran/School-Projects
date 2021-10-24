package com.csc2310.lab05;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class UserAccountDriver {

    public static void main(String[] args) {
        int userChoice = 0;
        String username, password;
        boolean isLoginSuccessful;
        ArrayList<User> users = new ArrayList<>();

        while (userChoice != 3) {
            System.out.println();
            System.out.println("Select one of the options below:\n1) Create a new user account\n2) Login with an existing account\n3) Exit");
            InputReader ir;
            userChoice = ir.readIntegerValue();
            while (userChoice < 1 || userChoice > 3) {
                System.out.println("Please select a valid option!!!");
                userChoice = ir.nextInt();
            }

            if (userChoice == 1) {
                System.out.println("Let's create a new user account!");
                System.out.println("Enter a new username:");
                Scanner inputReader = new Scanner(System.in);
                username = inputReader.nextLine().trim();
                while (username.isEmpty()) {
                    System.out.println("Enter a new username:");
                    username = inputReader.nextLine().trim();
                }

                System.out.println("Enter password for the username:");
                Scanner inputReader2 = new Scanner(System.in);
                password = inputReader2.nextLine().trim();
                while (password.isEmpty()) {
                    System.out.println("Enter password for the username:");
                    password = inputReader2.nextLine().trim();
                }

                users.add(new User(username, password));
                System.out.println("Congratulations! A new user account has been created with the username \"" + username + "\".\nYou can now login with this account.");

            } else if (userChoice == 2) {

                System.out.println("Enter username:");
                Scanner inputReader3 = new Scanner(System.in);
                username = inputReader3.nextLine().trim();
                while (username.isEmpty()) {
                    System.out.println("Enter username:");
                    username = inputReader3.nextLine().trim();
                }

                System.out.println("Enter password:");
                Scanner inputReader4 = new Scanner(System.in);
                password = inputReader4.nextLine().trim();

                Iterator iterator = users.iterator();
                isLoginSuccessful = false;
                while (iterator.hasNext()) {
                    User user = (User) iterator.next();
                    String username_ = user.getUsername();
                    String password_ = user.getPassword();
                    if (username.equals(username_) && password.equals(password_)) {
                        System.out.println("*********************************************************" +
                                "\n\n   Welcome " + username + ", you are now logged in!  \n\n" +
                                "*********************************************************");
                        isLoginSuccessful = true;

                        System.out.println("\nLogging you out now ....");
                        break;
                    }
                }
                if (!isLoginSuccessful) {
                    System.out.println("Unable to login with the provided credentials. Try again.");
                }

            }
        }
    }
}
