class GiocaDadi1 {

	// Simula il lancio di due dadi
	public static void main(String[] args){

		DadoPlus dado1, dado2;

		dado1	= new DadoPlus();
		dado2	= new DadoPlus();


		dado1.lancia();
		System.out.println("Il risultato del mio lancio e'... " +		dado1.faccia + "\n" );


		dado2.lancia();
		System.out.println("Il risultato del tuo lancio e'........ " +		dado2.faccia + "\n" );


		if (dado1.equals(dado2)  )
		  System.out.println(" PARI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");




	}
}