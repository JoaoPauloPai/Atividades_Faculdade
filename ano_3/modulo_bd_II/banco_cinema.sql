/*Criando Banco de Dados*/
CREATE SCHEMA cinema;
COMMIT;


/*tabela funcao*/
CREATE TABLE funcao(
idfuncao integer PRIMARY KEY NOT NULL,
nome varchar(45) NOT NULL);

/*tabela funcionario*/
CREATE TABLE funcionario(
idfuncionario integer PRIMARY KEY NOT NULL,
nome varchar(45) NOT NULL,,
carteiraTrabalho integer NOT NULL,,
data_contratacao Date NOT NULL,,
salario float NOT NULL,);

/*tabela sala*/
create TABLE sala(
idSala integer PRIMARY KEY NOT NULL,
nome varchar(45) NOT NULL,
capacidade integer NOT NULL,);

/*tabela horario*/
CREATE TABLE HORARIO(
idHorario integer PRIMARY KEY NOT NULL,
horario Time NOT NULL);

/*tabela diretor*/
CREATE TABLE diretor(
idDiretor integer PRIMARY KEY NOT NULL,
nome varchar(45) NOT NULL,);

/*tabela genero*/
CREATE TABLE genero(
idgenero integer PRIMARY KEY NOT NULL,
nome varchar(45) NOT NULL);

/*tabela premiacao*/
CREATE TABLE premiacao(
idpremiacao integer PRIMARY KEY NOT NULL,
nome varchar(45 ) NOT NULL ,
ano integer NOT NULL);

/*tabela horario_tarbalho_funcionario*/
CREATE TABLE horario_tarbalho_funcionario(
horario_idfuncionario integer PRIMARY KEY NOT NULL,
funcionario_idfuncionario integer NOT NULL,
funcao_idfuncao int NOT NULL,);

/*tabela filme*/
CREATE TABLE filme(
idfilme int NOT NULL,
nomeBR varchar(45) NOT NULL,
nomeEN varchar(45) NOT NULL,
anoLancamento int NOT NULL,
diretor_idDiretor int NOT NULL,
sinopse text NOT NULL,,
genero_idGenero int NOT NULL,);

/*tabela filme_has_premiacao*/
CREATE TABLE filme_has_premiacao(
filme_idfilme int NOT NULL,
premiacao_idpremiacao int NOT NULL,,
ganhou BOOL NOT NULL,);

/*tabela filme_exibido_sala*/
CREATE TABLE filme_exibido_sala(
filme_idFilme int NOT NULL,
sala_idSala INTEGER NOT NULL,
horario_idHorario int NOT NULL,);

ALTER TABLE filme
 ADD CONSTRAINT diretor_fk_hr_filme
  FOREIGN KEY (diretor_idDiretor)
	  REFERENCES diretor(idDiretor);
      
      ALTER TABLE  horario_tarbalho_funcionario 
 ADD CONSTRAINT funcionario_fk_hr_trabalho
  FOREIGN KEY (funcionario_idfuncionario)
	  REFERENCES funcionario(idfuncionario);

   ALTER TABLE  filme_has_premiacao
 ADD CONSTRAINT filme_fk_premiacao
  FOREIGN KEY (filme_idfilme)
	  REFERENCES filme(idfilme);

