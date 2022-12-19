package principal;

import java.awt.LayoutManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import java.text.ParseException;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFormattedTextField;
import javax.swing.JFrame;
import javax.swing.JLabel;

import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.text.MaskFormatter;

/**
 * Atividade MAPA Módulo Progamação de Sistema I R.A 20012120-5
 *
 * @author João Paulo Gomes da Silva
 * @version 2.7 Data 04/12/2022
 */
public class MenuPrincipal {

    public String presenca;

    public static void main(String[] args) throws ParseException {

        JFrame janela = new JFrame();

        JPanel painel = new JPanel();
        LayoutManager layoutManager = new BoxLayout(painel, BoxLayout.Y_AXIS);
        painel.setLayout(layoutManager);
        painel.setBorder(BorderFactory.createEmptyBorder(20, 10, 10, 20));

        janela.add(painel);
        JLabel labelMatricula = new JLabel("Matrícula Aluno");
        JFormattedTextField campoAlunoMatricula = new JFormattedTextField();
        MaskFormatter msk = new MaskFormatter("#########");
        msk.install(campoAlunoMatricula);
        JLabel labelAlunoNome = new JLabel("Nome Aluno");
        JTextField campoAlunoNome = new JTextField();
        JLabel labelNota1 = new JLabel("1° Nota Aluno");
        JFormattedTextField campoNota1 = new JFormattedTextField();
        MaskFormatter msk1 = new MaskFormatter("##.##");
        msk1.install(campoNota1);
        JLabel labelNota2 = new JLabel("2° Nota Aluno");
        JFormattedTextField campoNota2 = new JFormattedTextField();
        MaskFormatter msk2 = new MaskFormatter("##.##");
        msk2.install(campoNota2);
        JLabel labelNota3 = new JLabel("3° Nota Aluno");
        JFormattedTextField campoNota3 = new JFormattedTextField();
        MaskFormatter msk3 = new MaskFormatter("##.##");
        msk3.install(campoNota3);
        JLabel labelPresencaAluno = new JLabel("Quantidade de Presença");
        JFormattedTextField campoPresencaAluno = new JFormattedTextField();
        MaskFormatter msk4 = new MaskFormatter("##");
        msk4.install(campoPresencaAluno);

        JButton botaoSalvar = new JButton("SALVAR");
        botaoSalvar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    String alunoMatricula = campoAlunoMatricula.getText();
                    String alunoNome = campoAlunoNome.getText();
                    String nota1 = campoNota1.getText();
                    String nota2 = campoNota2.getText();
                    String nota3 = campoNota3.getText();
                    String presenca = campoPresencaAluno.getText();
                    int presencaAluno = Integer.parseInt(presenca);

                    if (alunoMatricula.trim().equals("") || alunoMatricula == null) {
                        JOptionPane.showMessageDialog(janela, "Adicione a Matrícula da Aluno!",
                                "Erro", JOptionPane.ERROR_MESSAGE);

                    }
                    if (alunoNome.trim().equals("") || alunoNome == null) {
                        JOptionPane.showMessageDialog(janela, "Adicione o Nome do Aluno!",
                                "Erro", JOptionPane.ERROR_MESSAGE);
                    }
                    if (nota1.trim().equals("") || nota1 == null) {
                        JOptionPane.showMessageDialog(janela, "Adicione a 1° Nota do Aluno!",
                                "Erro", JOptionPane.ERROR_MESSAGE);
                    }
                    if (nota2.trim().equals("") || nota2 == null) {
                        JOptionPane.showMessageDialog(janela, "Adicione a 2° Nota do Aluno!",
                                "Erro", JOptionPane.ERROR_MESSAGE);
                    }
                    if (nota3.trim().equals("") || nota3 == null) {
                        JOptionPane.showMessageDialog(janela, "Adicione a 3° Nota do Aluno!",
                                "Erro", JOptionPane.ERROR_MESSAGE);
                    }

                    if (presenca.trim().equals("") || presenca == null) {
                        JOptionPane.showMessageDialog(janela, "Adicione a Qunatidade de presença do Aluno!",
                                "Erro", JOptionPane.ERROR_MESSAGE);
                    }
                    if (presencaAluno > 60) {

                        JOptionPane.showMessageDialog(janela, "A Qunatidade de presença do Aluno \n"
                                + " não pode ser maior que 60 !",
                                "Erro", JOptionPane.ERROR_MESSAGE);
                    }

                    if (!alunoMatricula.trim().equals("") && !alunoNome.trim().equals("")
                            && !nota1.trim().equals("") && !nota2.trim().equals("")
                            && !nota3.trim().equals("") && !presenca.trim().equals("")
                            && !presenca.trim().equals("") && presencaAluno < 60) {
                        JOptionPane.showMessageDialog(janela, "Os Dados do Aluno estão todos preenchidos!",
                                "OK", JOptionPane.INFORMATION_MESSAGE);

                        double nota1Aluno = Double.parseDouble(nota1);
                        double nota2Aluno = Double.parseDouble(nota2);
                        double nota3Aluno = Double.parseDouble(nota3);
                        double quantPresenca = Integer.parseInt(presenca);

                        double percentualPrecenca = (quantPresenca / 60) * 100;
                        double media = (nota1Aluno + nota2Aluno + nota3Aluno) / 3;

                        JOptionPane.showMessageDialog(painel,
                                " --INFORMAÇÕES DO ALUNO--" + "\n"
                                + "Matrícula:     " + alunoMatricula + "\n"
                                + "Nome do Aluno: " + alunoNome + "\n"
                                + "Nota 1:        " + nota1 + "\n"
                                + "Nota 2:        " + nota2 + "\n"
                                + "Nota 3:        " + nota3 + "\n"
                                + "Média das Notas:     " + new DecimalFormat(".##").format(media) + "\n"
                                + "Quantidade Presença: " + presencaAluno + " aulas" + "\n"
                                + "Percentual Presença: " + new DecimalFormat(".##").format(percentualPrecenca) + "%",
                                "Cadastro Notas Aluno", JOptionPane.INFORMATION_MESSAGE);
                        System.exit(0);
                    } else {
                        JOptionPane.showMessageDialog(janela, "Preencha todas as informações do Aluno!",
                                "Erro", JOptionPane.ERROR_MESSAGE);

                    }
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(janela, "Preencha todas as informações do Aluno!",
                            "Erro", JOptionPane.ERROR_MESSAGE);
                }
            }

        });

        painel.add(labelMatricula);
        painel.add(campoAlunoMatricula);
        painel.add(labelAlunoNome);
        painel.add(campoAlunoNome);
        painel.add(labelNota1);
        painel.add(campoNota1);
        painel.add(labelNota2);
        painel.add(campoNota2);
        painel.add(labelNota3);
        painel.add(campoNota3);
        painel.add(labelPresencaAluno);
        painel.add(campoPresencaAluno);

        painel.add(botaoSalvar);

        janela.setSize(300, 400);
        janela.setTitle("Cadastro Notas Aluno");
        janela.setVisible(true);
        janela.setResizable(false);
        janela.setLocationRelativeTo(null);
        janela.setDefaultCloseOperation(janela.DISPOSE_ON_CLOSE);
    }

}
