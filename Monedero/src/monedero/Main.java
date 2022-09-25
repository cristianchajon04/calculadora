package monedero;

import java.util.Scanner;

public class Main {
    static double DineroCuenta = 6500.00;

    public static void main(String[] args) {
        int menu = 5;
        Scanner lectormenu = new Scanner(System.in);
        do {
            System.out.println("");
            System.out.println("\tMonedero");
            System.out.println("1) Consultar estado");
            System.out.println("2) retirar dinero");
            System.out.println("3) Depositar dinero");
            System.out.println("0) Salir");
            System.out.println("Escriba el numero de la opcion a seguir: ");
            menu = lectormenu.nextInt();
            switch (menu) {
                case 0:
                    System.out.println("Esta saliendo");
                    break;
                case 1:
                    consulta();
                    break;
                case 2:
                    retiro();
                    break;
                case 3:
                    deposito();
                    break;
                default:
                    System.out.println("El numero escrito es invalido.");
                    break;
            }
            if (menu == 1 || menu == 2 || menu == 3) {
                System.out.println("Volvera al menu principal...\n");
            }
        } while (menu != 0);
    }

    public static void retiro() {//Restarle a la cuenta
        double cantidadRetirar;
        Scanner en = new Scanner(System.in);
        System.out.println("\tRetiro");
        System.out.println("Escriba la cantidad de dinero a retirar: ");
        cantidadRetirar = en.nextDouble();
        DineroCuenta -= cantidadRetirar;
        System.out.println("El dinero ha sido retirado de su cuenta.");
    }

    public static void deposito() { //Sumarle a la cuenta
        double cantidadDepositar;
        Scanner on = new Scanner(System.in);
        System.out.println("\tDeposito");
        System.out.println("Escriba la cantidad de dinero a depositar: ");
        cantidadDepositar = on.nextDouble();
        DineroCuenta += cantidadDepositar;
        System.out.println("El dinero ha sido depositado exitosamente.");
    }

    public static void consulta() {
        System.out.println("\tConsulta de cuenta");
        System.out.println("Su saldo disponible es Q"+DineroCuenta);
    }
}