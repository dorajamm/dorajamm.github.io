import java.util.Scanner;


public class EseTutor2{
	public static void main(String[] args){
		Scanner tastiera = new Scanner(System.in);


		Docente prof1=new Docente("Carl Gauss", 1777, "Analisi1", 1, "Analisi2", 2);
		System.out.println(prof1);
		Docente prof2=new Docente("Galileo Galilei", 1564, "Meccanica", 1, "Astronomia", 3);
		System.out.println(prof2);
		Docente prof3=new Docente("Alan Turing", 1912, "Programmazione", 1, "Codici", 2);
		System.out.println(prof3);

System.out.println("\n\n adesso una persona...!\n");
Persona pers4 = new Persona("Valentino Rossi", 1979);
		System.out.println(pers4);



		System.out.println("\n\n adesso lo studente...!\n");
		Studente a=new Studente("Gigi", 1994);

		for (int i=0; i<2; i++){
			System.out.println("Digita nome esame");
			String nome=tastiera.next();
			System.out.println("Digita anno di corso");
			int anno= tastiera.nextInt();
			Esame e= new Esame(nome,anno);
			a.setLibretto(i, e);
		}

		System.out.println(a);

	}
}