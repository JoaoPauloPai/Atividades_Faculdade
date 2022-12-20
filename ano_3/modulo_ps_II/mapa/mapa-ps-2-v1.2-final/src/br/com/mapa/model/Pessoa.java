
package br.com.mapa.model;
/**
 * Atividade MAPA Módulo Progamação de Sistema II R.A 20012120-5
 *
 * @author João Paulo Gomes da Silva
 * @version 2.3 Data 04/12/2022
 */
public abstract class Pessoa {
    
      public Pessoa() {
    }
    
   public String nomePessoa;
   public String cpfPessoa;

  
    
    

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
