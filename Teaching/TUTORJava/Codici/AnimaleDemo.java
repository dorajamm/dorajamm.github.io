import java.util.Scanner;

public class AnimaleDemo {

	public static void main(String[] args) {
		Animale elefante = new Animale("Fido");
		System.out.println("Le mie informazioni sul tuo animale non sono accurate.");
		System.out.println("Ecco quello che so:");
		elefante.scriviOutput( );

		Scanner tastiera = new Scanner(System.in);
		System.out.println("Inserisci il nome corretto:");
		String nomeCorretto = tastiera.nextLine();
		elefante.setNome(nomeCorretto);

		System.out.println("Inserisci l'eta corretta:");
		int etaCorretta = tastiera.nextInt();
		elefante.setEta(etaCorretta);

		System.out.println("Inserisci il peso corretto:");
		double pesoCorretto = tastiera.nextDouble();
		elefante.setPeso(pesoCorretto);

		System.out.println("Dati aggiornati:");
		elefante.scriviOutput();



	}
}