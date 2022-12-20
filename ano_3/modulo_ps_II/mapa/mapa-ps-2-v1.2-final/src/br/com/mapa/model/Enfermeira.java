
package br.com.mapa.model;
/**
 * Atividade MAPA Módulo Progamação de Sistema II R.A 20012120-5
 *
 * @author João Paulo Gomes da Silva
 * @version 1.1 Data 04/12/2022
 */
public class Enfermeira extends Pessoa {

    private String crmEnfermeira;

    public Enfermeira() {
        this.crmEnfermeira = crmEnfermeira;
        this.nomePessoa = nomePessoa;
        this.cpfPessoa = cpfPessoa;
    }

    public String getCrmEnfermeira() {
        return crmEnfermeira;
    }

    public void setCrmEnfermeira(String crmEnfermeira) {
        this.crmEnfermeira = crmEnfermeira;
    }

    public String getNomePessoa() {
        return nomePessoa;
    }

    public void setNomePessoa(String nomePessoa) {
        this.nomePessoa = nomePessoa;
    }

    public String getCpfPessoa() {
        return cpfPessoa;
    }

    public void setCpfPessoa(String cpfPessoa) {
        this.cpfPessoa = cpfPessoa;
    }

}
