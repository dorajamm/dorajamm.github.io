/**
 * Una classe con variabili di istanza e variabili statiche , medodi di istanza e metodi statici
 */
public class ContoBanca {
	private int codiceCliente;
	private double saldo;

	public static double tassoInteresse = 0;
	public static int numeroDiConti = 0;

	public ContoBanca() {
		saldo = 0;
		numeroDiConti++; //quando si apre un conto viene aggiornata la variabile statica
		codiceCliente=56789+numeroDiConti;  // e viene utilizzata per determinare il numero del conto!
	}

	public static void setTassoInteresse(double nuovoTasso) {
		tassoInteresse = nuovoTasso;

	}

	public static double getTassoInteresse() {
		return tassoInteresse;
	}

	public static int getNumeroDiConti() {
		return numeroDiConti; //numeroDiConti è statica e quindi è accessibile da un metodo statico
	}

	public void deposita(double somma) {
		saldo = saldo + somma;
	}

	public double preleva(double ammontare) {
		if (saldo >= ammontare)
			saldo = saldo - ammontare;
		else
			ammontare = 0;
		return ammontare;
	}

	public void aggiungiInteresse() {
		double interesse = saldo * tassoInteresse;
		//si potrebbe anche sostituire tassoInteresse con getTassoInteresse() ....
		saldo = saldo + interesse;
	}

	public double getSaldo() {
		return saldo;
	}

	public static void mostraSaldo(ContoBanca conto) {
		//per accedere alla variabile saldo bisogna passare l'oggetto nei parametri e usare il metodo getSaldo
		System.out.print(conto.getSaldo());
	}
}
