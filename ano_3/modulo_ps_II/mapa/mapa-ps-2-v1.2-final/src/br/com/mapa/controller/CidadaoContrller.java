package br.com.mapa.controller;

import java.util.ArrayList;
import br.com.mapa.model.Cidadao;
import java.text.SimpleDateFormat;

/**
 * Atividade MAPA Módulo Progamação de Sistema II R.A 20012120-5
 *
 * @author João Paulo Gomes da Silva
 * @version 2.3 Data 04/12/2022
 */
public class CidadaoContrller {

    ArrayList<Cidadao> cidadaos = new ArrayList();

    Cidadao c = new Cidadao();
    SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");

    public void salvaCidadao(Cidadao cidadao) {
        cidadaos.add((new Cidadao(cidadao.getNomePessoa(), cidadao.getCpfPessoa(),
                cidadao.getPrimeiraDose(), cidadao.getSegundaDose(), cidadao.getTerceiraDose(),
                cidadao.getQuartaDose())));
        System.out.println("Cidadão vacinado com susseso");
        for (int i = 0; i < cidadaos.size(); i++) {
            System.out.println("nome - " + cidadaos.get(i).getNomePessoa());

        }
        System.out.println(cidadaos.size() + " - " + " Cidadão Vacinado.");

    }

    public void listaCidadao(Cidadao cidadao) {
        System.out.println("---- CIDADÃO VACINADOS ---");
        for (int i = 0; i < cidadaos.size(); i++) {
            System.out.println("NOME - " + cidadaos.get(i).getNomePessoa());
            System.out.println("CPF  - " + cidadaos.get(i).getCpfPessoa());
            System.out.println("data 1ª Dose - " + format.format(cidadaos.get(i).getPrimeiraDose()));
            System.out.println("data 2ª Dose - " + format.format(cidadaos.get(i).getSegundaDose()));
            System.out.println("data 3ª Dose - " + format.format(cidadaos.get(i).getTerceiraDose()));
            System.out.println("data 4ª Dose - " + format.format(cidadaos.get(i).getQuartaDose()));
            System.out.println("---------------------------------");
        }
        System.out.println("Total " + cidadaos.size() + " vacinados.");
    }

}
