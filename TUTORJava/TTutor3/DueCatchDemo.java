import java.util.Scanner;

public class DueCatchDemo {

   public static double divisioneEccezionale(double numeratore, double denominatore) throws DivisionePerZeroException {
      if (denominatore == 0)
    	  throw new DivisionePerZeroException();
      return numeratore / denominatore;
   }

   public static void main(String[] args) {
      try {
         System.out.println("Inserire il numero di oggetti prodotti:");
         Scanner tastiera = new Scanner(System.in);
         int oggetti = tastiera.nextInt();

         if (oggetti < 0)
             throw new NumeroNegativoException("oggetti");

         System.out.println("Quanti di questi erano difettosi?");
         int difettosi = tastiera.nextInt();

         if (difettosi < 0)
            throw new NumeroNegativoException("oggetti difettosi");
          // throw new NumeroNegativoException();

          double rapporto = divisioneEccezionale(oggetti, difettosi);
          System.out.println("Un oggetto ogni " + rapporto + " e' difettoso");
      } catch(DivisionePerZeroException e) {
          System.out.println("Congratulazioni! Un record perfetto!");
      } catch(NumeroNegativoException e) {
          System.out.println("Impossibile avere un numero negativo di " + e.getMessage());
      }
      System.out.println("Fine programma.");
   }
}
