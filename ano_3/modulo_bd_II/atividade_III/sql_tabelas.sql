/*Tabela ATIVIDADE*/
CREATE TABLE atividade
(id_atividade            INTEGER(7)    NOT NULL,
nome                     VARCHAR(100),
CONSTRAINT id_atividade_pk PRIMARY KEY (id_atividade)
);

/*Tabela INSTRUTOR*/
CREATE TABLE instrutor
(id_instrutor          INTEGER    NOT NULL,
rg                     INTEGER,
nome                   VARCHAR(45),
nascimento             DATE,
titulacao              INTEGER, 
CONSTRAINT id_instrutor_pk PRIMARY KEY (id_instrutor)
);

/*Tabela TELEFOE_INSTRUTOR*/
CREATE TABLE telefone_instrutor
(id_telefone           INTEGER     NOT NULL,
numero                 INTEGER,
tipo                   VARCHAR(45),
instrutor_id_instrutor INTEGER NOT NULL,
CONSTRAINT id_telefone_pk PRIMARY KEY (id_telefone),
CONSTRAINT instrutor_id_instrutor_fk FOREIGN KEY (instrutor_id_instrutor)
REFERENCES instrutor (id_instrutor)
);

/*Tabela TURMA*/
 CREATE TABLE turma
(id_turma              INTEGER       NOT NULL,
horario                TIME,
duracao                INTEGER,
data_inicio            DATE,
data_fim               DATE,
atividade_id_atividade INTEGER     NOT NULL,
instrutor_id_instrutor INTEGER     NOT NULL,
CONSTRAINT id_turma_pk PRIMARY KEY (id_turma),
CONSTRAINT atividade_id_atividade_fk FOREIGN KEY (atividade_id_atividade)
REFERENCES atividade (id_atividade),
CONSTRAINT instrutor_id_instrutor_turma_fk FOREIGN KEY (instrutor_id_instrutor)
REFERENCES instrutor (id_instrutor)
);

/*Tabela ALUNO*/
 CREATE TABLE aluno
(cod_matricula         INTEGER       NOT NULL,
turma_id_turma         INTEGER,
data_matricula         DATE,
nome                   VARCHAR(45),
endereco               VARCHAR(200),
telefone               INTEGER,
data_nascimento        DATE,
altura                 FLOAT,
peso                   INTEGER,
CONSTRAINT cod_matricula_pk PRIMARY KEY (cod_matricula),
CONSTRAINT turma_id_turma_fk FOREIGN KEY (turma_id_turma)
REFERENCES turma (id_turma)
);

/*Tabela MATRICULA*/
CREATE TABLE matricula(
aluno_cod_matricula            INTEGER NOT NULL,
turma_id_turma                 INTEGER NOT NULL,
CONSTRAINT aluno_cod_matricula_mat_fk FOREIGN KEY (aluno_cod_matricula)
REFERENCES aluno (cod_matricula),
REFERENCES turma (id_turma)
);

/*Tabala CHAMADA*/
CREATE TABLE chamada
(id_chamada                    INTEGER     NOT NULL,
data_chamada                   DATE,
presente                       BOOLEAN,
matricula_aluno_cod_matricula  INTEGER     NOT NULL,
matricula_turma_id_turma       INTEGER     NOT NULL,
CONSTRAINT  id_chamada_pk PRIMARY KEY (id_chamada),
CONSTRAINT matricula_aluno_cod_matricula_cha_pk FOREIGN KEY (matricula_aluno_cod_matricula)
REFERENCES matricula (aluno_cod_matricula),
CONSTRAINT matricula_turma_id_turma_cha_pk FOREIGN KEY (matricula_turma_id_turma)
REFERENCES matricula (turma_id_turma)
);


