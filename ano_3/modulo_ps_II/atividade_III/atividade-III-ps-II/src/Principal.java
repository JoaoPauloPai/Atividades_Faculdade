
public class Principal{

    public static void main(String args[]) {

       //Carro meuCarro ; ERRO
        Carro meuCarro = new Carro();//Criar um novo objeto
        meuCarro.marca = "BMW";
        meuCarro.modelo = "525i";
        meuCarro.anoFabricacao = 1992;
        meuCarro.anoModelo = 1992;

        meuCarro.imprimirInformacoes();
    }
}