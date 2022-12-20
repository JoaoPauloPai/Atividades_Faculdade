package br.com.mapa.Principal;

import br.com.mapa.controller.PrincipalController;

/**
 * Atividade MAPA Módulo Progamação de Sistema II R.A 20012120-5
 *
 * @author João Paulo Gomes da Silva
 * @version 2.3 Data 04/12/2022
 */
public class Principal {

    public static void main(String[] args) throws InterruptedException {
        PrincipalController principalController = new PrincipalController();
        principalController.chamaPrincipalContoller();
    }

}
