
    /*Dados Tabela instrutor*/
    INSERT INTO instrutor(
            id_instrutor, rg, nome, nascimento, titulacao)
    VALUES 
	(1, 214545, 'José da Silva', '1987-09-25', 2324),
	(2, 904394, 'Maria Genikde lima', '1988-09-25', 1029),
	(3, 893750, 'Nair Gorete', '2007-09-25', 2344),
	(4, 943550, 'Antonio Bandeiras', '2008-09-25', 0392),
	(5, 092844, 'Shakira Gomes', '1990-09-25', 9475),
	(6, 826664, 'Frank Sinatra', '1995-09-25', 9465),
	(7, 102847, 'Claudia Raia', '1999-09-25', 0098),
	(8, 657392, 'Manoel Da Cruz', '2001-09-25', 7432),
	(9, 718294, 'Jamille Goes', '2003-09-25', 1123),
	(10, 0192874, 'Camila Souza', '2009-09-25', 3210);
	
    /*Dados Tabela ATIVIDA*/
	INSERT INTO atividade(
            id_atividade, nome)
    VALUES 
	(1, 'EDUCACAO-FISICA'),
	(2, 'PORTUGUES'),
	(3, 'MATEMATICA'),
	(4, 'HISTORIA'),
	(5, 'GEOGRAFIA');

    /*Dados Tabela turma*/
    INSERT INTO turma(
            id_turma, horario, duracao, data_inicio, data_fim, atividade_id_atividade, 
            instrutor_id_instrutor)
    VALUES 
	(1, '10:30', 20, '2022-01-10', '2022-06-30', 1, 1),
	(2, '11:10', 20, '2022-01-10', '2022-06-30', 3, 9);
			

    /*Dados Tabela aluno*/			
    INSERT INTO aluno(
            cod_matricula, turma_id_turma, data_matricula, nome, endereco, 
            telefone, data_nascimento, altura, peso)
    VALUES 
	(1, 1, '2022-01-12', 'Pedro Aontonio de Souza', 'Cuiaba - MT', 99203944, '1995-06-27', 1.98,52 ),
	(2, 2, '2022-01-12', 'Margarida da Cruz', 'Cuiaba - MT', 99203944, '1995-06-27', 1.98,52 ),
	(3, 2, '2022-01-12', 'Maoela DAvilas Boas', 'Cuiaba - MT', 99203944, '1995-06-27', 1.98,52 ),
	(4, 1, '2022-01-12', 'Carlos Nascimento', 'Cuiaba - MT', 99203944, '1995-06-27', 1.98,52 ),
	(5, 1, '2022-01-12', 'Silvia Mendes', 'Cuiaba - MT', 99203944, '1995-06-27', 1.98,52 );
		
		
    /*Dados Tabela TELEFONE INSTRUTOR*/	
	INSERT INTO telefone_instrutor(
         id_telefone, numero, tipo, instrutor_id_instrutor)
    VALUES
	(1, 35463727, 'RESIDENCIAL', 1);
	

    /*Dados Tabela MATRICULA*/		
	INSERT INTO matricula(
            id_matricula, aluno_cod_matricula, turma_id_turma)
    VALUES 
	(1, 5, 1),
	(2, 4, 2);

    /*Dados Tabela CHAMADA*/	
    INSERT INTO chamada(
            id_chamada, data_chamada, presente, matricula_aluno_cod_matricula, 
            matricula_turma_id_turma)
    VALUES 
	(1, '2022-06-11', TRUE , 1, 1),
	(2, '2022-06-11', FALSE, 1, 1),
	(3, '2022-06-12', TRUE , 1, 1);