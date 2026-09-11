class LancioDadi{


		Dado dado1= new Dado();
		Dado dado2= new Dado();
		Dado dado3= new Dado();

		int risul;

     public int tira2(){     // Simula il lancio di due dadi

		dado1.lancia();
		dado2.lancia();

        System.out.print("lancio........ " );
        System.out.printf( "(%d, %d) ", dado1.faccia, dado2.faccia);
        System.out.println("\n\n" );
		risul = dado1.faccia + dado2.faccia;

		return risul;
	}

     public int tira3(){     // Simula il lancio di tre dadi

		dado1.lancia();
		dado2.lancia();
		dado3.lancia();

         System.out.print("lancio........ " );
         System.out.printf( "(%d, %d, %d) ", dado1.faccia, dado2.faccia, dado3.faccia);
        System.out.println("\n\n" );
		risul = dado1.faccia + dado2.faccia + dado3.faccia;

		return risul;
	}
}
