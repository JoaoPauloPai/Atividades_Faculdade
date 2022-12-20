public class Carro {

    public String marca;
    public String modelo;
    public int anoFabricacao;
    public int anoModelo;
    public String cor;

    public void imprimirInformacoes(){
        System.out.println("Marca: "+this.marca);
        System.out.println("Modelo: "+this.modelo);
        System.out.println("Ano de Fabricação: "+this.anoFabricacao);
        System.out.println("Ano do Modelo: "+this.anoModelo);
        System.out.println("Cor: "+this.cor);
    }
}
