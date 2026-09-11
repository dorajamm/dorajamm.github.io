/**
Class che rappresenta un rettangolo di cui calcola l'area
*/
public class Rectangle4
{
    private int larghezza;
    private int altezza;
    private int area;
    public void setDimensions (int newLarghezza, int newAltezza)
    {
        larghezza = newLarghezza;
        altezza = newAltezza;

    }
    public int getLarghezza ()
		    {
		        return larghezza ;
	    }

	    public int getAltezza ()
		    {
		        return  altezza;
    }

    public int getArea ()
    {
        return area= larghezza * altezza;
    }

    /**
	    cerca di cambiare il valore di una variabile intera passandola come parametro.
	    Ma un paramentro di tipo primitivo non puo' essere cambiato.
	    */
	    public void cercaDiCambiare (int newlarghezza, int newaltezza)
	    {
	        newlarghezza = this.larghezza;
	        newaltezza = this.altezza;
	    }


	    /**
	    Cerca di cambiare il riferimento di altroRett con this
	    Un argomento di tipo classe non puo' essere sostituito
	    */
	    public void provaASostituire (Rectangle4 altroRett)
	    {
	        altroRett = this;
	    }


	    /**

	    Cambia i dati di altroRett con quelli di this che rimane invariato
	    */
	    public void cambia (Rectangle4 altroRett)
	    {
	        altroRett.larghezza = this.larghezza;
	        altroRett.altezza = this.altezza;

	    }




}