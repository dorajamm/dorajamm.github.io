/*
	 da utilizzare per giocare a dadi
*/

import java.util.*;

class Dado {


	// Dati

	// Il numero massimo su un dado
	private static final int MAX = 6;

	// Il numero minimo su un dado
	private static final int MIN = 1;

	int faccia;


	// Lancia il dado
	public void lancia(){
		faccia = (int)(Math.floor(Math.random() *(MAX - MIN + 1)) + MIN);
	}



}

