
/* a- Mostar todos os itens de solicitação do produto 5 */
select * from item_solic
where cod_produto = 5;

/* b- Mostar todos os itens de solicitação em que a quantidade solicitada é de ate 3 unidades */
SELECT * FROM item_solic
WHERE qtd_solic <= 3;

/* c- Mostar todos os itens de solicitação em que a quantidade solicitada é acima 5 unidades */
SELECT * FROM item_solic
WHERE qtd_solic > 5;

/* d- Mostar todas as decrições de produto que não são medidas por unidades */
SELECT * FROM produto
WHERE dsc_unidade NOT LIKE 'unidades';

/* e- Mostar código e descrição dos produtos em que a unidade de medida é nula */
SELECT * FROM produto
WHERE dsc_unidade LIKE null;

/* f- Mostar a descrição dos departamentos 3, 4 e 7 */
SELECT dsc_departamento FROM depto
WHERE cod_depto = 3 or cod_depto = 4 or cod_depto = 7;

/* g- Mostar os numeros dos pedidos em janeiro de 1997 */
SELECT num_pedido FROM pedido
WHERE dat_emiss <= '1997-01-31' AND dat_emiss >= '1997-01-01' ;

/*h- Mostar todas as informaçoes dos fornecedores em que a razão social contem 'err' */
SELECT * FROM fornecedor
WHERE dsc_razao_social LIKE '%err%';

/* i- Mostar o código e descrição dos produtos que foram pedidos pelo menos uma vez*/
SELECT DISTINCT produto.cod_produto, produto.dsc_produto 
FROM item_pedido INNER JOIN produto ON item_pedido.cod_produto=produto.cod_produto;

/* j- Mostar código e descrição dos departamentos que fizarm pedidos pelo menos uma solicitação de compra */
SELECT DISTINCT depto.cod_depto, dsc_departamento 
FROM solic_compra INNER JOIN depto ON solic_compra.cod_depto = depto.cod_depto;

/* k) Mostrar todas as informações dos produtos que são medidos por 'Lata' ou que custam até R$ 1,00.*/
SELECT DISTINCT depto.cod_depto, depto.dsc_departamento 
FROM solic_compra INNER JOIN depto ON solic_compra.cod_depto = depto.cod_depto;
SELECT * FROM produto WHERE produto.vlr_unit <= 1.00 OR produto.dsc_unidade LIKE '%Lata%';




