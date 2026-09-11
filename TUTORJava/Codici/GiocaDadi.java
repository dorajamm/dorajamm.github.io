class GiocaDadi {

	// Simula il lancio di due dadi
	public static void main(String[] args){

		Dado dado1, dado2;

		dado1	= new Dado();
		dado2	= new Dado();


		dado1.lancia();
		System.out.println("Il risultato del mio lancio e'... " +		dado1.faccia + "\n" ); //!!

		dado2.lancia();
		System.out.println("Il risultato del tuo lancio e'........ " +		dado2.faccia + "\n" ); //!!

		if (dado1 == dado2)  //!!
		  System.out.println(" PARI");




	}
}