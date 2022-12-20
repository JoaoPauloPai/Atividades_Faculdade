package br.com.mapa.controller;

import java.util.Scanner;
import br.com.mapa.model.Cidadao;
import java.util.concurrent.TimeUnit;

/**
 * Atividade MAPA Módulo Progamação de Sistema II R.A 20012120-5
 *
 * @author João Paulo Gomes da Silva
 * @version 2.3 Data 04/12/2022
 */
public class PrincipalController {

    Cidadao c = new Cidadao();
    CidadaoContrller cidadaoContrller = new CidadaoContrller();
    EnfermeiraController enfermeiraController = new EnfermeiraController();

    int cont;

    private void telaEnfermeira() throws InterruptedException {
        System.out.println("Olá Enfermeira(o)!");
        Thread.sleep(1000);
        limpaTela();
        System.out.println("Para ter acesso ao sistema");
        Thread.sleep(2000);
        limpaTela();
        String nomeEnfermeira = coletaDados("Digite o seu nome!");
        limpaTela();
        String cpfEnfermeira = coletaDados("Agora digite o seu CPF");

        limpaTela();
        enfermeiraController.coletaDadosEnfermeira(nomeEnfermeira, cpfEnfermeira);

    }

    private void vacinaCidadao() {
        limpaTela();
        System.out.println("SISTEMA DE VACINAS");
        String nomeCidadao = coletaDados("Informe o nome do Cidadão");
        String cpfCidadao = coletaDados("Informe o CPF do Cidadão");
        String dataPrimeiraDose = coletaDados("Informe a data da primeira dose");
        String dataSegundaDose = coletaDados("Informe a data da segunda dose");
        //Chama o método para calcular a segunda dose
        calculaDataSegundaDose(nomeCidadao, dataPrimeiraDose, dataSegundaDose);

        String dataTerceiraDose = coletaDados("Informe a data da terceira dose");
        //Chama o método para calcular a terceira dose dose
        calculaDataTerceiraDose(nomeCidadao, dataSegundaDose, dataTerceiraDose);
        //Chama o método para calcular a terceira dose dose
        String dataQuartaDose = coletaDados("Informe a data da quarta dose");
        //Chama o método para calcular a quarta dose dose
        calculaDataQuartaDose(nomeCidadao, cpfCidadao, dataPrimeiraDose,
                dataSegundaDose, dataTerceiraDose, dataQuartaDose);
    }

    public void limpaTela() {
        for (int i = 0; i < 10;
                i++) {
            System.out.println(" ");
        }

    }

    private static String coletaDados(String mensagem) {
        System.out.println(mensagem);
        Scanner sc = new Scanner(System.in);
        return sc.nextLine();
    }

    public void painelPrincipal() throws InterruptedException {
        do {
            System.out.println("\n"
                    + "SISTEMA VACINA CIDADÃO \n"
                    + "  1 - VACINAR \n"
                    + "  2 - LISTAR \n"
                    + "  3 - SAIR \n"
                    + "selecione uma opção...");

            Scanner scValor = new Scanner(System.in);
            String valor = scValor.nextLine();
            cont = Integer.parseInt(valor);

            if (cont == 1) {
                vacinaCidadao();
            }
            if (cont == 2) {
                limpaTela();
                cidadaoContrller.listaCidadao(c);
            }
            if (cont == 3) {

                limpaTela();
                System.out.println("Saindo do Sistema Vacinas");
                Thread.sleep(1000);
                System.exit(0);

            }

        } while (cont < 3);
        limpaTela();
        System.out.println("Erro, número não válido");
        painelPrincipal();
    }

    private void calculaDataSegundaDose(String nomeCidadao, String dataPrimeiraDose,
            String dataSegundaDose) {
        c.setPrimeiraDose(dataPrimeiraDose);
        c.setSegundaDose(dataSegundaDose);
        Long diferencaDatas = (c.segundaDose.getTime() - c.primeiraDose.getTime());
        Long TotalDias = TimeUnit.DAYS.convert(diferencaDatas, TimeUnit.MILLISECONDS);

        if (TotalDias <= 120) {
            try {
                limpaTela();
                System.out.println("O(a) Cidadão(ã) " + nomeCidadao + " não tem direito \n"
                        + " a tomar a segunda dose da vacina! ");
                painelPrincipal();
            } catch (InterruptedException ex) {
                System.out.println("Erro, calculo das datas " + ex.getMessage());

            }
        }

    }

    private void calculaDataTerceiraDose(String nomeCidadao, String dataSegundaDose,
            String dataTerceiraDose) {
        c.setSegundaDose(dataSegundaDose);
        c.setTerceiraDose(dataTerceiraDose);

        Long diferencaDatas = (c.terceiraDose.getTime() - c.segundaDose.getTime());
        Long TotalDias = TimeUnit.DAYS.convert(diferencaDatas, TimeUnit.MILLISECONDS);

        if (TotalDias <= 120) {
            try {
                limpaTela();
                System.out.println("O(a) Cidadão(ã) " + nomeCidadao + " não tem direito \n"
                        + " a tomar a terceira dose da vacina! ");
                painelPrincipal();
            } catch (InterruptedException ex) {
                System.out.println("Erro, calculo das datas " + ex.getMessage());
            }
        }

    }

    private void calculaDataQuartaDose(String nomeCidadao, String cpfCidadao,
            String dataPrimeiraDose, String dataSegundaDose, String dataTerceiraDose,
            String dataQuartaDose) {
        c.setTerceiraDose(dataTerceiraDose);
        c.setQuartaDose(dataQuartaDose);
        Long diferencaDatas = (c.quartaDose.getTime() - c.terceiraDose.getTime());
        Long TotalDias = TimeUnit.DAYS.convert(diferencaDatas, TimeUnit.MILLISECONDS);

        if (TotalDias <= 120) {
            try {
                limpaTela();
                System.out.println("O(a) Cidadão(ã) " + nomeCidadao + " não tem direito \n"
                        + " a tomar a quarta dose da vacina! ");
                painelPrincipal();
            } catch (InterruptedException ex) {
                System.out.println("Erro, calculo das datas " + ex.getMessage());
            }
        }

        c.setNomePessoa(nomeCidadao);
        c.setCpfPessoa(cpfCidadao);
        c.setPrimeiraDose(dataPrimeiraDose);
        c.setSegundaDose(dataSegundaDose);
        limpaTela();
        cidadaoContrller.salvaCidadao(c);

    }

    public void chamaPrincipalContoller() {
        try {
            telaEnfermeira();
        } catch (InterruptedException ex) {
            System.out.println("Erro, Tela Enfermeira " + ex.getMessage());
        }
    }

}
