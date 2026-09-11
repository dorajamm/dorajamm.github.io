import java.util.Scanner;

public class RectangleDemo2
{
	public static void main(String[] args)
	{
		Scanner tastiera = new Scanner(System.in);


		Rectangle2 mioRettan = new Rectangle2();

        mioRettan.setLarghezza(5);
        mioRettan.setAltezza(7);

        System.out.println("La larghezza del rettangolo e' " + mioRettan.getLarghezza() );
        System.out.println("L'altezza del rettangolo e' " + mioRettan.getAltezza() );

        System.out.println("L'area del rettangolo e' " + mioRettan.getArea());
        System.out.println("");

        System.out.print("Inserisci un nuovo valore per la larghezza: ");
        mioRettan.setLarghezza( tastiera.nextInt() );
		System.out.println("");

        System.out.println("La larghezza del rettangolo e' " + mioRettan.getLarghezza());
		System.out.println("L'altezza del rettangolo e' " + mioRettan.getAltezza());

		System.out.println("L'area del rettangolo e' " + mioRettan.getArea());


         }
 }