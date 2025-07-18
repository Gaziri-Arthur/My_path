package Exercicios_04_07;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class List003Principal {
	private List<String> nomes;

	private void popular() {
		nomes.add("Rodrigo Benjamin Dias");
		nomes.add("Manuel Leandro Filipe Almeida");
		nomes.add("Adriana Gabrielly Antonella das Neves");
		nomes.add("Bernardo Yuri César Aparício");
		nomes.add("Filipe Cauê Brito");
		nomes.add("Julia Manuela Pinto");
		nomes.add("Mirella Marina Camila Nogueira");
		nomes.add("Miguel Ricardo Souza");
		nomes.add("Rosa Sophia Marlene Souza");
		nomes.add("Allana Eloá Souza");
	}

	private void mostrarTradicional() {
		System.out.println("==> Tradicional <==");
		for (int i = 0; i < nomes.size(); i++)
			System.out.println(nomes.get(i));

		System.out.println();
	}

	private void mostrarForEach() {
		System.out.println("==> ForEach <==");
		for (String nome : nomes)
			System.out.println(nome);

		System.out.println();
	}

	private void mostrarIterator() {
		Iterator<String> it = nomes.iterator();

		System.out.println("==> Iterator <==");
		while (it.hasNext()) {
			String nome = it.next();

			System.out.println(nome);
		}
		System.out.println();
	}

	public List003Principal() {
		nomes = new ArrayList<>();

		popular();
		System.out.println("===> COLEÇÃO SEM ORDENAR <===");
		mostrarTradicional();
//		mostrarForEach();
//		mostrarIterator();
		// ordenar a coleção
		Collections.sort(nomes);

		System.out.println("===> COLEÇÃO ORDENADA <===");
		mostrarTradicional();
	}

	public static void main(String[] args) {
		new List003Principal();
	}
}

