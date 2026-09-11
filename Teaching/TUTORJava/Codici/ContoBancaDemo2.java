public class ContoBancaDemo2 {

	public static void main(String[] args) {
		ContoBanca.setTassoInteresse(0.01);
		ContoBanca [] registroConti;
		ContoBanca tuoConto = new ContoBanca();
		ContoBanca mioConto = new ContoBanca();
		ContoBanca suoConto = mioConto;
        registroConti= new ContoBanca[10];
		for(int i=0; i<10;i++)
			registroConti[i]=new ContoBanca();
		for(int i=0; i<10;i++)
			registroConti[i].deposita(50.00);
		
		System.out.println("R0 ha depositato 10.75 Euro.");
		registroConti[0].deposita(10.75);

		System.out.println("Ho depositato 10.75 Euro.");
		mioConto.deposita(10.75);
		System.out.println("Hai depositato 75 Euro.");
		tuoConto.deposita(75.00);
		System.out.println("Hai depositato 55 Euro.");
		tuoConto.deposita(55.00);

		double contante = tuoConto.preleva(15.75);
		System.out.println("Hai prelevato " + contante + " Euro.");
		if (tuoConto.getSaldo() > 100.00) {
			System.out.println("Hai ricevuto un interesse.");
			tuoConto.aggiungiInteresse();
		}
		System.out.println("Il tuo conto e' di " + tuoConto.getSaldo() + " Euro.");

		System.out.print("Il mio conto e' di ");
		ContoBanca.mostraSaldo(mioConto);
		
		System.out.print("\n\n\nPROVA:\n ");
		for(int i=0; i<10;i++){
			ContoBanca.mostraSaldo(registroConti[i]);
			System.out.println("\n");
		}
		
		System.out.println(" Euro.");
		int conti = ContoBanca.getNumeroDiConti();
		System.out.println("Abbiamo aperto " + conti + " conti in banca oggi.");
	}
}
