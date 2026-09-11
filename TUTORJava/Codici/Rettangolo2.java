/**
  Un'altra classe che rappresenta un rettangolo generico. Migliora Rettangolo1 con l'uso di metodi set e get
 */
public class Rettangolo2 {
	private int larghezza;
	private int altezza;

	public void setDimensioni(int nuovaLarghezza, int nuovaAltezza) {
		larghezza = nuovaLarghezza;
		altezza = nuovaAltezza;
	}
public void setLarghezza (int newLarghezza)
    {
        if (newLarghezza >0)
             larghezza = newLarghezza;
    }

	public void setAltezza ( int newAltezza)
	{
	        if (newAltezza >0)
	        altezza = newAltezza;
    }
// riscrivi setAltezza (int altezza)

    public int getLarghezza ()
	    {
	        return larghezza ;
    }

    public int getAltezza ()
	    {
	        return  altezza;
    }


	public int getArea() {
		return altezza*larghezza;
	}
}
