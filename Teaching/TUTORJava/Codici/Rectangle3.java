/**
Another class that represents a rectangle.
*/
public class Rectangle2
{
    private int larghezza;
    private int altezza;

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

    public int getArea ()
    {
        return larghezza * altezza;
    }
}