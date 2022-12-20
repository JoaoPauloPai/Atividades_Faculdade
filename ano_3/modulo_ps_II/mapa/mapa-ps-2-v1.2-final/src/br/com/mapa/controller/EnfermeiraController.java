
package br.com.mapa.controller;


import java.util.ArrayList;
import br.com.mapa.model.Enfermeira;
/**
 * Atividade MAPA Módulo Progamação de Sistema II R.A 20012120-5
 *
 * @author João Paulo Gomes da Silva
 * @version 2.3 Data 04/12/2022
 */
public class EnfermeiraController {

    ArrayList<Enfermeira> enfermeiras = new ArrayList();

    Enfermeira enfermeira = new Enfermeira();

    void coletaDadosEnfermeira(String nomeEnfermeira, String cpfEnfermeira) {
        enfermeira.setNomePessoa(nomeEnfermeira);
        enfermeira.setCpfPessoa(cpfEnfermeira);

        salvaEnfermeira(enfermeira);

    }

    public void salvaEnfermeira(Enfermeira e) {
        try {
            enfermeiras.add(e);
            
            System.out.println("Seu cadastro foi realizado com susseso!");
            
            for (int i = 0; i < enfermeiras.size(); i++) {
                System.out.println("Nome - " + enfermeiras.get(i).getNomePessoa());
                System.out.println("CPF - " + enfermeiras.get(i).getCpfPessoa());
                
            }
            
            PrincipalController principalController = new PrincipalController();
            principalController.painelPrincipal();
        } catch (InterruptedException ex) {
            System.out.println("Erro, cadastro enfermeira "+ ex.getMessage());
          
        }
        
    }

}
