
import java.util.*;
class Partita {

	// Simula il lancio di tre dadi
	public static void main(String[] args){

        int mioRis, tuoRis;
		LancioDadi round ;

		round	= new LancioDadi();


		int num;

        Scanner input = new Scanner(System.in);

        System.out.println("Oggi ci giochiamo un caffe' a dadi");
        System.out.print("Con quanti dadi vuoi giocare (2 o 3)?   ");


		num = input.nextInt();

        System.out.print("\n\n");
        if (num ==2)
	       {
		   tuoRis =	  round.tira2();
           mioRis =	  round.tira2();
	       }
	     else
	       {
		         tuoRis =	  round.tira3();
		   		 mioRis =	  round.tira3();
	       }
        System.out.println("Il risultato del TUO lancio di due dadi e' " + 	 tuoRis	);
		System.out.println("Il risultato del MIO lancio di due dadi e' " +	mioRis);

		if (tuoRis > mioRis)
		          System.out.println("\n\n Hai vinto tu... andiamo al bar\n\n"	);
		else
		      {   if (tuoRis < mioRis)
		             System.out.println("\n\n Ho vinto io... andiamo al bar\n\n"	);
				  else
				     System.out.println("\n\n pari... niente caffe' per oggi\n\n"	);
				 }
      }





}
