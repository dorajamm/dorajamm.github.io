import java.util.Scanner;

public class PrendiLatte { 
	
    public static void main(String[] args) { 
    	
        Scanner tastiera = new Scanner(System.in);
        
        System.out.println("Inserire il numero di ciambelle:");
        int conteggioCiambelle = tastiera.nextInt(); 
        
        System.out.println("Inserire il numero di bicchieri di latte:");
        int conteggioLatte = tastiera.nextInt(); 
        
        //Gestione degli eventi eccezionali senza utilizzare le struttre
        //di gestione delle eccezioni di Java
        if (conteggioLatte < 1) {
             System.out.println("Niente latte!");
             System.out.println("Vai a comprare del latte."); 
        } else { 
             double ciambellePerBicchiere = conteggioCiambelle / (double)conteggioLatte;
             System.out.println(conteggioCiambelle + " ciambelle.");
             System.out.println(conteggioLatte + " bicchieri di latte.");
             System.out.println("Hai " + ciambellePerBicchiere + " ciambelle per ogni bicchiere di latte."); 
        }
        System.out.println("Fine programma.");
    }
}
