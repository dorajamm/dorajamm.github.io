public class TestDado1
{
   public static void main( String args[] )
   {
      Dado miodado	= new Dado();

      int freq[]= new int[7]; // uso una posizione in piu'

      int ris;
      int i;

      // risultati di 6000 lanci
      for ( i = 1; i <= 600000; i++ )
      {
         miodado.lancia();


         ++freq[ miodado.faccia ];

      } // end for

      System.out.println( "Risultato\tFrequenza" ); // intestazione output

      for (i=1; i<=6; i++)
      {
        System.out.println( i + "\t \t " + freq[i] );
      }
   } // end main
} // end class
