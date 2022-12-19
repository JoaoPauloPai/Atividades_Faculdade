/**
 * @author João Paulo Gomes da Silva
 * @ra 20012120-5
 * @curso Engenharia de Software
 * @disciplina Programacao de Sistemas I
 *         12 de out. de 2022 09:12:35
 */

public class CalculaSalario {
    public static void main(String[] args) {

    //Valor do Salário a calcular
    double salarioBruto = 2500.00;
    //Valor em % descontar
    int percentualDesconto =  25;

    double valorDesconto = salarioBruto * percentualDesconto / 100;
    double salarioFuncionario = salarioBruto  - valorDesconto;

        System.out.println("Salário bruto do Funcionário R$: " + salarioBruto);
        System.out.println("Valor Desconto R$: "+ valorDesconto);
        System.out.println("Salário Líquido do Funcionário R$: "+ salarioFuncionario);

    }
}