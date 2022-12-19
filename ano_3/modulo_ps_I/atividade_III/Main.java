import javax.swing.*;
import java.text.DecimalFormat;

public class Main {
    public static void main(String[] args) {


        String nome = JOptionPane.showInputDialog("DIGITE O NOME DO FUNCIONÁRIO!");

        String salario = JOptionPane.showInputDialog("DIGITE O VALOR DO SALÁRIO!");
        double salarioFuncionario = Double.parseDouble(salario);

        String depen = JOptionPane.showInputDialog("DIGITE O NÚMERO DE DEPENDENTES!");
        int numDependente = Integer.parseInt(depen);

        double salarioFamilia = 0;
        double salarioFinal = 0;

        if(numDependente == 0) {
            JOptionPane.showMessageDialog(null, "Funcionário não tem dependentes para calcular");
            salarioFinal = salarioFuncionario;

        } else {

            double salarioFamiliaCalculo = 134.98 * numDependente;
            double acrecimo = salarioFamiliaCalculo * 3 / 100;
            salarioFamilia = salarioFamiliaCalculo+ acrecimo;
            salarioFinal = salarioFamilia + salarioFuncionario;
        }
        JOptionPane.showMessageDialog(null,
                "- IFORMAÇÕES DO FUNIONÁRIO -\n"
                        + "Nome: " + nome + "\n"
                        + "Salário base R$ " + new DecimalFormat(".##").format(salarioFuncionario) + "\n"
                        + "N° Dependentes : " + numDependente + "\n"
                        + "Salário Família R$ " + new DecimalFormat(".##").format(salarioFamilia) + "\n"
                        + "Salário Total R$ " + new DecimalFormat(".##").format(salarioFinal));

    }
}