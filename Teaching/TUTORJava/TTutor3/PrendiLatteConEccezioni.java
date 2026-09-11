import java.util.Scanner; 

public class PrendiLatteConEccezioni {
	
    public static void main(String[] args) { 
        
    	Scanner tastiera = new Scanner(System.in); 
        
    	try {
             System.out.println("Inserire il numero di ciambelle:");
             int conteggioCiambelle = tastiera.nextInt(); 
             
             System.out.println("Inserire il numero di bicchieri di latte:");
             int conteggioLatte = tastiera.nextInt(); 
        
             if (conteggioLatte < 1)
                  throw new Exception("Eccezione: Niente latte!");

             double ciambellePerBicchiere = conteggioCiambelle / (double)conteggioLatte;
             System.out.println(conteggioCiambelle + " ciambelle.");
             System.out.println(conteggioLatte + " bicchieri di latte.");
             System.out.println("Hai " + ciambellePerBicchiere + " ciambelle per ogni bicchiere di latte."); 
        } catch(Exception e) {
             System.out.println(e.getMessage());
             System.out.println("Vai a comprare del latte.");
        }
        
        System.out.println("Fine programma.");
    }
}

