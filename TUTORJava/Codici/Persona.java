public class Persona{
	private String nome;
	private int anno;

	public Persona(){
		nome="Nessun nome";
		anno=0;
	}
	public Persona(String newNome, int newAnno){
		setNome(newNome);
		setAnno(newAnno);
	}
	public void setAnno(int anno){
		this.anno=anno;
	}
	public void setNome(String nome){
		this.nome=nome;
	}
	public String getNome(){
		return nome;
	}
	public int getAnno(){
		return anno;
	}
	public String toString(){
		return ("Nome: "+ this.nome + "\nAnno di nascita: " + this.anno);
	}
}