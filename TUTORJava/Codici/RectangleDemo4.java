
import java.util.Scanner;

public class RectangleDemo4
{
	public static void main(String[] args)
	{
		Scanner tastiera = new Scanner(System.in);


		Rectangle4 r1 = new Rectangle4();
        r1.setDimensions(5,7);
        System.out.println("La larghezza del primo rettangolo e' " + r1.getLarghezza() );
        System.out.println("L'altezza del primo rettangolo e' " + r1.getAltezza() );
        System.out.println("\n\n");

        Rectangle4 r2 = new Rectangle4();
        r2.setDimensions(50,70);
        System.out.println("La larghezza del secondo rettangolo e' " + r2.getLarghezza());
        System.out.println("L'altezza del secondo rettangolo e' " + r2.getAltezza());
        System.out.println("\n\n");

        System.out.println("Applico adesso i metodi per cambiare i valori del secondo rettangolo con quelli del primo ");
        System.out.println("\n\n");

        System.out.println("Applico adesso il metodo cercaDiCambiare ");

		int alt=0;
		int lar=0;
		r1.cercaDiCambiare(lar, alt);
		r2.setDimensions(lar,alt);
		System.out.println("La larghezza del secondo rettangolo e' " + r2.getLarghezza());
        System.out.println("L'altezza del secondo rettangolo e' " + r2.getAltezza());
        System.out.println("\n");

        System.out.println("Applico adesso il metodo provaASostituire ");

		r1.provaASostituire(r2);
		System.out.println("La larghezza del secondo rettangolo e' " + r2.getLarghezza());
        System.out.println("L'altezza del secondo rettangolo e' " + r2.getAltezza());
        System.out.println("\n");


        System.out.println("Applico adesso il metodo cambia ");

		r1.cambia(r2);
		System.out.println("La larghezza del secondo rettangolo e' " + r2.getLarghezza());
        System.out.println("L'altezza del secondo rettangolo e' " + r2.getAltezza());
        System.out.println("\n");

         }
 }