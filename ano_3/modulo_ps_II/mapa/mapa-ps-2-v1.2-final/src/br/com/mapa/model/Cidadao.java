package br.com.mapa.model;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Atividade MAPA Módulo Progamação de Sistema II R.A 20012120-5
 *
 * @author João Paulo Gomes da Silva
 * @version 2.3 Data 04/12/2022
 */
public class Cidadao extends Pessoa {

    public Date primeiraDose;
    public Date segundaDose;
    public Date terceiraDose;
    public Date quartaDose;
    public SimpleDateFormat formatador;

    public Cidadao() {
        this.formatador = new SimpleDateFormat("dd/MM/yyyy");
    }

    public Cidadao(String nomePessoa, String cpfPessoa, Date primeiraDose,
            SimpleDateFormat formatador, Date segundaDose, Date terceiraDose, Date quartaDose) {
        this.nomePessoa = nomePessoa;
        this.primeiraDose = primeiraDose;
        this.formatador = formatador;
        this.segundaDose = segundaDose;
        this.terceiraDose = terceiraDose;
        this.quartaDose = quartaDose;

    }

    public Cidadao(Date primeiraDose) {

    }

    public Cidadao(String nomePessoa, String cpfPessoa, Date primeiraDose, Date segundaDose, Date terceiraDose, Date quartaDose) {
        this.nomePessoa = nomePessoa;
        this.cpfPessoa = cpfPessoa;
        this.primeiraDose = primeiraDose;
        this.segundaDose = segundaDose;
        this.terceiraDose = terceiraDose;
        this.quartaDose = quartaDose;
    }

    public Cidadao(Cidadao c) {
        this.nomePessoa = nomePessoa;
        this.cpfPessoa = cpfPessoa;
        this.formatador = formatador;
        this.primeiraDose = primeiraDose;
        this.terceiraDose = terceiraDose;
        this.quartaDose = quartaDose;
    }

    public String getCpfPessoa() {
        return cpfPessoa;
    }

    public Date getPrimeiraDose() {
        return primeiraDose;
    }

    public String getPrimeiraDoseFormatada() {
        return this.formatador.format(primeiraDose);
    }

    public void setPrimeiraDose(Date primeiraDose) {
        this.primeiraDose = primeiraDose;
    }

    public void setPrimeiraDose(String primeiraDose) {
        try {
            this.primeiraDose = this.formatador.parse(primeiraDose);
        } catch (ParseException ex) {
            System.out.println("ERRO, data primeira dose inválida " + ex.getMessage());
        }
    }

    public void setCpfPessoa(String cpfPessoa) {
        this.cpfPessoa = cpfPessoa;
    }

    public String getNomePessoa() {
        return nomePessoa;
    }

    public void setNomePessoa(String nomePessoa) {
        this.nomePessoa = nomePessoa;
    }

    public Date getSegundaDose() {
        return segundaDose;
    }

    public String getSegundaDoseFormatada() {
        return this.formatador.format(segundaDose);
    }

    public void setSegundaDose(Date segundaDose) {
        this.segundaDose = segundaDose;
    }

    public void setSegundaDose(String segundaDose) {
        try {
            this.segundaDose = this.formatador.parse(segundaDose);
        } catch (ParseException ex) {
            System.out.println("ERRO, data segunda dose inválida " + ex.getMessage());
        }
    }

    public Date getTerceiraDose() {
        return terceiraDose;
    }

    public String getTerceiraDoseFormatada() {
        return this.formatador.format(terceiraDose);
    }

    public void setTerceiraDose(Date terceiraDose) {
        this.terceiraDose = terceiraDose;
    }

    public void setTerceiraDose(String terceiraDose) {
        try {
            this.terceiraDose = this.formatador.parse(terceiraDose);
        } catch (ParseException ex) {
            System.out.println("ERRO, data terceira dose inválida " + ex.getMessage());
        }

    }

    public Date getQuartaDose() {
        return quartaDose;
    }

    public String getQuartaDoseFormatada() {
        return this.formatador.format(quartaDose);
    }

    public void setQuartaDose(Date quartaDose) {
        this.quartaDose = quartaDose;
    }

    public void setQuartaDose(String quartaDose) {
        try {
            this.quartaDose = this.formatador.parse(quartaDose);
        } catch (ParseException ex) {
            System.out.println("ERRO, data quarta dose inválida " + ex.getMessage());
        }

    }

}
