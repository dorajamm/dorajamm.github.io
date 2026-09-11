/**
 Classe che rappresenta un generico rettangolo
 identica a Rettangolo0 ma adesso le variabili sono dichiarate private
 */
public class Rettangolo1 {
	private int larghezza;
	private int altezza;
	private int area;

	public void setDimensioni(int nuovaLarghezza, int nuovaAltezza) {
		larghezza = nuovaLarghezza;
		altezza = nuovaAltezza;
		area = larghezza * altezza;
	}

	public int getArea() {
		return area;
	}
}
