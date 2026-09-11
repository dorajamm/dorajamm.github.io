public class NumeroNegativoException extends Exception { 
    
	public NumeroNegativoException() {
        super("Eccezione numero negativo!");
    } 
    
	public NumeroNegativoException(String messaggio) {
        super(messaggio);
    }
}