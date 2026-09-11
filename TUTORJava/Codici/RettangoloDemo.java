
import java.util.Scanner;

public class Rettangolo1Demo
{
	public static void main(String[] args)
	{
		Scanner tastiera = new Scanner(System.in);


		Rettangolo1 mioRettan = new Rettangolo1();
        mioRettan.setDimensioni(5,7);
        System.out.println("La larghezza del rettangolo e' " + mioRettan.larghezza);
        System.out.println("L'altezza del rettangolo e' " + mioRettan.altezza);

        System.out.println("L'area del rettangolo e' " + mioRettan.getArea());
        System.out.println("");

        System.out.print("Inserisci un nuovo valore per la larghezza: ");
        mioRettan.larghezza = tastiera.nextInt();
		System.out.println("");

        System.out.println("La larghezza del rettangolo e' " + mioRettan.larghezza);
		System.out.println("L'altezza del rettangolo e' " + mioRettan.altezza);

		System.out.println("L'area del rettangolo e' " + mioRettan.getArea());


         }
 }