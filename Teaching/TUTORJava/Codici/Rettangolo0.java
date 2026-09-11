/**
Class che rappresenta un rettangolo di cui calcola l'area
*/
public class Rettangolo0
{
    public int larghezza;
    public int altezza;
    public int area;
    public void setDimensions (int newLarghezza, int newAltezza)
    {
        larghezza = newLarghezza;
        altezza = newAltezza;
        area = larghezza * altezza;
    }


    public int getArea ()
    {
        return area;
    }
}