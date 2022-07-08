

CREATE TABLE usuario_paciente(
id             INTEGER NOT NULL,
login          VARCHAR(45) NOT NULL UNIQUE,
senha          VARCHAR(45) NOT NULL UNIQUE,
CONSTRAINT id_usuario_pk PRIMARY KEY (id)
);

CREATE TABLE usuario_profissional(
id             INTEGER NOT NULL,
login          VARCHAR(45) NOT NULL UNIQUE,
senha          VARCHAR(45) NOT NULL UNIQUE,
CONSTRAINT id_profissional_pk PRIMARY KEY (id)
);

CREATE TABLE paciente(
id                            INTEGER NOT NULL, 
nome                          VARCHAR(100) NOT NULL,
sexo                          VARCHAR(50) NOT NULL,
pais                          VARCHAR(100) NOT NULL,
estado                        VARCHAR(100) NOT NULL,
provincia                     VARCHAR(100) NOT NULL,
cidade                        VARCHAR(100) NOT NULL,
endereco                      VARCHAR(100) NOT NULL,
usuario_pac_id                INTEGER NOT NULL UNIQUE,
CONSTRAINT id_pk PRIMARY KEY (id),
CONSTRAINT usuario_pac_id_fk FOREIGN KEY (usuario_pac_id)
REFERENCES usuario_paciente(id) 
);

CREATE TABLE profissional(
id                            INTEGER NOT NULL, 
numero_registro               VARCHAR(100) NOT NULL,
nome                          VARCHAR(100) NOT NULL,
sexo                          VARCHAR(50) NOT NULL,
pais                          VARCHAR(100) NOT NULL,
estado                        VARCHAR(100) NOT NULL,
provincia                     VARCHAR(100) NOT NULL,
cidade                        VARCHAR(100) NOT NULL,
endereco                      VARCHAR(100) NOT NULL,
usuario_pro_id                INTEGER NOT NULL UNIQUE,
CONSTRAINT id_pk PRIMARY KEY (id),
CONSTRAINT usuario_prof_id_fk FOREIGN KEY (usuario_pro_id)
REFERENCES usuario_profissional(id) 
);


CREATE TABLE especialidade(
id                          INTEGER NOT NULL,
tipo_especialidade          VARCHAR(95) NOT NULL,
CONSTRAINT id_pk PRIMARY KEY (id)
);

CREATE TABLE especialidade_profissional(
id             INTEGER NOT NULL,
espe_pro_id    INTEGER NOT NULL,
prof_pro_id    INTEGER NOT NULL,
CONSTRAINT id_espe_prof_id_pk PRIMARY KEY (id),
CONSTRAINT espe_pro_id_fk FOREIGN KEY (espe_pro_id)
REFERENCES especialidade(id),
CONSTRAINT prof_pro_id_fk FOREIGN KEY (prof_pro_id)
REFERENCES profissional(id)
);

CREATE TABLE contatos_paciente(
id                          INTEGER NOT NULL,
telefone                    VARCHAR(20) NOT NULL,
email                       VARCHAR(90),
instagram                   VARCHAR(90),
paciente_id                 INTEGER NOT NULL,
CONSTRAINT id_pk PRIMARY KEY (id),
CONSTRAINT paciente_id_fk FOREIGN KEY (paciente_id)
REFERENCES paciente(id)
);

CREATE TABLE tabela_preco(
id                          INTEGER NOT NULL,
data_inicial                DATE NOT NULL,
data_final                  DATE NOT NULL,
valor_exame                 DECIMAL(10,2) NOT NULL,
tipo_exame                  VARCHAR(90),
valor_laudo                 DECIMAL(10,2) NOT NULL,
CONSTRAINT id_pk PRIMARY KEY (id)
);

CREATE TABLE laudos(
id                          INTEGER NOT NULL,
data                        DATE NOT NULL,
obs                         TEXT NOT NULL,
tabela_pr_id                INTEGER NOT NULL,
CONSTRAINT id_pk PRIMARY KEY (id),
CONSTRAINT tabela_pr_id_fk FOREIGN KEY (tabela_pr_id)
REFERENCES tabela_preco(id)
);

CREATE TABLE estabelecimento(
id                            INTEGER NOT NULL, 
numero_registro               VARCHAR(45) NOT NULL,
nome_registro                 VARCHAR(100) NOT NULL,
nome_fantasia                 VARCHAR(90) NOT NULL,
email                         VARCHAR(90) NOT NULL,
telefone                      VARCHAR(20) NOT NULL,
endereco                      VARCHAR(100) NOT NULL,
pais                          VARCHAR(100) NOT NULL,
estado                        VARCHAR(100) NOT NULL,
cidade                        VARCHAR(100) NOT NULL,
CONSTRAINT id_pk PRIMARY KEY (id)
);

CREATE TABLE consulta(
id                          INTEGER NOT NULL,
paciente_id                 INTEGER NOT NULL,
profissional_id             INTEGER NOT NULL,
estabelecimento_id          INTEGER NOT NULL,
laudo_id                    INTEGER NOT NULL,
CONSTRAINT id_pk PRIMARY KEY (id),
CONSTRAINT paciente_con_id_fk FOREIGN KEY (paciente_id)
REFERENCES paciente(id),
CONSTRAINT profissional_con_id_fk FOREIGN KEY (profissional_id )
REFERENCES profissional(id),
CONSTRAINT estabelimento_con_id_fk FOREIGN KEY (estabelecimento_id)
REFERENCES estabelecimento(id),
CONSTRAINT laudo_con_id_fk FOREIGN KEY (laudo_id)
REFERENCES laudos(id)
);

CREATE TABLE usuario_estab(
id                          INTEGER NOT NULL,
paciente_id                 INTEGER NOT NULL,
estabelecimento_id          INTEGER NOT NULL,
CONSTRAINT id_pk PRIMARY KEY (id),
CONSTRAINT paciente_us_es_id_fk FOREIGN KEY (paciente_id)
REFERENCES paciente(id),
CONSTRAINT estabelecimento_us_es_id_fk FOREIGN KEY (estabelecimento_id)
REFERENCES estabelecimento(id)
);

CREATE TABLE acesso_estab(
id                          INTEGER NOT NULL,
profissional_id             INTEGER NOT NULL,
estab_id                    INTEGER NOT NULL,
CONSTRAINT id_pk PRIMARY KEY (id),
CONSTRAINT profissional_ace_id_fk FOREIGN KEY (profissional_id)
REFERENCES profissional(id),
CONSTRAINT estab_ace_id_fk FOREIGN KEY (estab_id)
REFERENCES estabelecimento(id)
);

CREATE TABLE profissional_estab(
id                          INTEGER NOT NULL,
profissional_id             INTEGER NOT NULL,
estab_acesso_id          INTEGER NOT NULL,
CONSTRAINT id_pk PRIMARY KEY (id),
CONSTRAINT profissional_pr_es_id_fk FOREIGN KEY (profissional_id)
REFERENCES profissional(id),
CONSTRAINT estabelecimento_pr_es_id_fk FOREIGN KEY (estab_acesso_id)
REFERENCES acesso_estab(estab_id)
);
