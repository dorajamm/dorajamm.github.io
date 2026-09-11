public class Esame extends Insegnamento{
	private int voto;
	private boolean lode;

	public Esame(){
		super();
		voto=0;
		lode=false;
	}
	public Esame(int newVoto){
		super();
		setVoto(newVoto);
		setLode();
	}
	public Esame(String newNomeCorso, int newAnnoDiCorso, int newVoto){
		super(newNomeCorso, newAnnoDiCorso);
		setVoto(newVoto);
		setLode();
	}

	public Esame(String newNomeCorso, int newAnnoDiCorso){ // con voto random
			super(newNomeCorso, newAnnoDiCorso);
			this.voto=(int)( Math.floor(Math.random() * (13)) + 18);
			setLode();
	}
	public void setVoto(){

	}
	public void setVoto(int voto){
		this.voto=voto;
	}
	public void setLode(){
		if(voto==30)
		lode=true;
	}
	public int getVoto(){
		return voto;
	}
	public boolean getLode(){
		return lode;
	}
	public String toString(){
		if(lode)
			return (super.toString()+" Voto: "+ this.voto + " e lode.");
		else
			return (super.toString()+" Voto: "+ this.voto);
	}
}