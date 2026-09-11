import java.util.Scanner; 

public class FaiDivisione { 
	
    private int numeratore;
    private int denominatore;
    private double quoziente;

    public void casoNormale() throws DivisionePerZeroException { 
        System.out.println("Inserisci numeratore:");
        Scanner tastiera = new Scanner(System.in);
        numeratore = tastiera.nextInt(); 
        System.out.println("Inserisci denominatore:");
        denominatore = tastiera.nextInt(); 
        
        if (denominatore == 0)
            throw new DivisionePerZeroException(); 
        
        quoziente = numeratore / (double)denominatore;
        System.out.println(numeratore + "/" + denominatore + " = " + quoziente); 
    }
    
    public void daiSecondaPossibilita() { 
        System.out.println("Tenta di nuovo.");
        System.out.println("Inserisci numeratore:");
        Scanner tastiera = new Scanner(System.in);
        numeratore = tastiera.nextInt(); 
        System.out.println("Inserisci denominatore:");
        System.out.println("Accertati che il denominatore non sia zero.");
        denominatore = tastiera.nextInt(); 

        if (denominatore == 0) {
            System.out.println("Non posso dividere per zero.");
            System.out.println("Poiche' non posso fare cio' che chiedi,");
            System.out.println("il programma terminera' ora.");
            System.exit(0);
        } 
        
        quoziente = ((double)numeratore) / denominatore;
        System.out.println(numeratore + "/" + denominatore + " = " + quoziente); 
    }
    
    
    public static void main(String[] args) { 
        FaiDivisione fai = new FaiDivisione();

        try {
            fai.casoNormale();
        } catch(DivisionePerZeroException e) {
            System.out.println(e.getMessage());
            fai.daiSecondaPossibilita();
        }
        System.out.println("Fine Programma.");
    }
}
