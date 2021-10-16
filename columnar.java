import java.util.Arrays;
import java.util.Scanner;

public class columnar {
    public static void main(String[] args) {
        String key;
        String message;
        String encryptedMessage;
        int x = 0;
        int y = 0;
        System.out.print("Type your Key : ");
        Scanner scan = new Scanner(System.in);
        key = scan.nextLine();

        System.out.print("Type your Message : ");

        message = scan.nextLine();

        int msglen = message.length();
        int keylen = key.length();

        if (!((msglen % keylen) == 0)) {
            do {
                message = message + "x";
                msglen = message.length();
            } while (!((msglen % keylen) == 0));
        }

        encryptedMessage = "";
        char temp[][] = new char[key.length()][message.length()];
        char msg[] = message.toCharArray();
        x = 0;
        y = 0;
        for (int i = 0; i < msg.length; i++) {
            temp[x][y] = msg[i];
            if (x == (key.length() - 1)) {
                x = 0;
                y = y + 1;
            }
            else {
                x++;
            }
        }

        char t[] = key.toCharArray();
        Arrays.sort(t);

        for (int j = 0; j < y; j++) {
            for (int i = 0; i < key.length(); i++) {
                System.out.print(temp[i][j]);
            }
            System.out.println();
        }

    }
}
