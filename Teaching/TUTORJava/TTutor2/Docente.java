public class Docente extends Persona{
	private Insegnamento materia1;
	private Insegnamento materia2;

	public Docente(){
		super();
		materia1=null;
		materia2=null;
	}
	public Docente(String newNome, int newAnno, String nomeMat1, int annoMat1, String nomeMat2, int annoMat2){
		super(newNome, newAnno);
		//setMat(materia1, nomeMat1, annoMat1);
		materia1=new Insegnamento(nomeMat1, annoMat1);
		materia2=new Insegnamento(nomeMat2, annoMat2);
	}
	public Insegnamento getMat1(){
		return materia1;
	}
	public Insegnamento getMat2(){
		return materia2;
	}
	public String toString(){

		return ("Prof." + super.toString()+"\nMateria 1: "+ materia1 + "\nMateria 2: " + materia2 + "\n\n");
	}
}