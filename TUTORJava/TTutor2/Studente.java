public class Studente extends Persona{
	private int matricola;
	private Esame[] libretto;
	private static int n=0;

	private  Insegnamento[] materia = new Insegnamento[6];


	public Studente(){
		super();
		matricola=22222;
		libretto=new Esame[6];
	}
	public Studente(String newNome, int newAnno){
		super(newNome, newAnno);
		n++;
		setMat();
		libretto=new Esame[2];

	}
	public void setMat(){
		matricola=222222+n;
	}
	public void setLibretto(int i, Esame newEsame){ //assegna ad una posizione del vettore libretto un esame

			libretto[i]=newEsame;

	}
	public int getMat(){
		return matricola;
	}


	public double setMedia(){
		int somma=0;
		for(int i=0; i<libretto.length; i++)
			somma=somma+libretto[i].getVoto();
		double media;
		media=somma/6.0;
		return media;
	}
	public String toString(){
		String voti="";
		for(int i=0; i<libretto.length; i++)
			voti=voti + libretto[i].toString()+"\n";
		return ("Studente " + super.toString() + "\n Matricola: " + matricola + "\n"+ voti);
	}
}