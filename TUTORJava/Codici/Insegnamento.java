public class Insegnamento{
	private String nomeCorso;
	private int annoDiCorso;

	public Insegnamento(){
		nomeCorso="Nessun corso";
		annoDiCorso=0;
	}
	public Insegnamento(String newNomeCorso, int newAnnoDiCorso){
		setNome(newNomeCorso);
		setAnno(newAnnoDiCorso);
	}
	public void setAnno(int annoDiCorso){
		this.annoDiCorso=annoDiCorso;
		//while(annoDiCorso<1 || annoDiCorso>3);
	}
	public void setNome(String nomeCorso){
		this.nomeCorso=nomeCorso;
	}
	public String getNomeCorso(){
		return nomeCorso;
	}
	public int getAnnoDiCorso(){
		return annoDiCorso;
	}
	public String toString(){
		return ("Nome del corso: "+ this.nomeCorso + " Anno di corso: " + this.annoDiCorso);
	}
}