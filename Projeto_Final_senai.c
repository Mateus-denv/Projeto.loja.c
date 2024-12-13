#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define capacidades_estoque 100000
/*
Definir as Estruturas de Dados
Criando as estruturas typedef struct para cada módulo. 
*/
typedef struct{ // Criada para armazenar os dados da empresa
    char nome_empresa[100];
    double cnpj;
} armazena_dados_empresa;

typedef struct{ // Criada para armazenar os dados do cleinte
    char nome[50];
    double cpf;
    char email[50];
} armazena_dados_cliente;

typedef struct {
    int codigo_produto;
    char tipo[20];
    int tamanho;
    int quantidade;
    float preco;
    int vendidos;
} camisa;

typedef struct {
    int codigo_produto;
    char tipo[20];
    int quantidade;
    int tamanho;
    float preco;
    int vendidos;
} shorte;
// Estrutura para armazenar os dados das calças
typedef struct {
    int codigo_produto;
    char tipo[20];
    int quantidade;
    int tamanho;
    float preco;
    int vendidos;
} Calca;

// Estrutura para armazenar os dados das meias
typedef struct {
    int codigo_produto;
    char tipo[20];
    int quantidade;
    float preco;
    int vendidos;
} Meia;

// Estrutura para armazenar os dados das tenis
typedef struct{
    int codigo_produto;
    char tipo[10];
    int quantidade;
    int tamanho ;
    float preco;
    int vendidos;
}calcados;

// Estrutura para armazenar os dados das assesorios
typedef struct{
    int codigo_produto;
    char tipo[10];
    int quantidade;
    float preco;
    int vendidos;
}assesorios;

// Estrutura para armazenar os dados do estoque 
typedef struct{ 
    int capacidade_estoque;
    int produtos_no_estoque;
    int produtos_bloqueados;
    int espaco_disponivel;
    camisa camisa_estoque[3];
    shorte shorte_estoque[3];
    Calca calca_estoque[3];
    assesorios acessorios_estoque[4];
    calcados calcados_estoque[3];
    Meia meia_estoque[2];  
}armazena_dados_estoque;

armazena_dados_estoque estoque[1];

typedef struct{
    float entradas;
    float saidas;
    float ganhos;
}valores;

valores financeiro[1];

armazena_dados_cliente clientes[100];
armazena_dados_empresa empresas[20];
int produtos_no_estoque = 0;
int p = 0; // Quantidade de Produtos que foram adicionados
int cc = 0; // Quantidade de calcas que foram adicionados
int cd = 0; // Quantidade de calcados que foram adicionados
int m = 0; // Quantidade de meias que foram adicionados
int cms = 0; // Quantidade de meias que foram adicionados
int sh = 0; // Quantidade de shorts que foram adicionados
int a = 0; // Quantidade de acessorios que foram adicionados
int adc_mais = 0; // Usado para repetir e para adicionar mais produtos 
int Bloqueado = 0; // Mostra quantos produtos foram Bloqueados
int quantidade_c = 0; // 
int *pQuantidade_de_clientes_cadastradas = &quantidade_c;
int quantidade_e = 0; //
int *pQuantidade_de_empresa_cadastradas = &quantidade_e;
int op = 0;



void armazena_dados_camisa_estoque() {
    int index = 0;
    for(int i = cms;i < cms+1;i++){
        if (produtos_no_estoque < capacidades_estoque){
            printf("Digite o tipo de camisa:\n");
            printf("1 - Camisa social\n2 - Camisa polo\n3 - Camisa de manga curta\n|> ");
            scanf("%d", &index);
            if (index >= 1 && index <= 3) {
                // Atribuindo o tipo da camisa ao campo 'tipo'
                if (index == 1) strcpy(estoque[0].camisa_estoque[i].tipo, "Camisa social");
                if (index == 2) strcpy(estoque[0].camisa_estoque[i].tipo, "Camisa polo");
                if (index == 3) strcpy(estoque[0].camisa_estoque[i].tipo, "Camisa de manga curta");

                // Entrada dos outros campos
                printf("Digite o código do produto: ");
                scanf("%d", &estoque[0].camisa_estoque[i].codigo_produto);

                printf("Digite a quantidade: ");
                scanf("%d", &estoque[0].camisa_estoque[i].quantidade);
                if (produtos_no_estoque + estoque[0].camisa_estoque[i].quantidade > capacidades_estoque) {
                    printf("Estoque máximo atingido!\n");
                    estoque[0].camisa_estoque[i].quantidade = 0;
                    estoque[0].camisa_estoque[i].codigo_produto = 0;
                    return;
                }

                printf("Digite o tamanho: ");
                scanf("%d", &estoque[0].camisa_estoque[i].tamanho);

                printf("Digite o preço: ");
                scanf("%f", &estoque[0].camisa_estoque[i].preco);
                financeiro[1].saidas = estoque[0].camisa_estoque[i].preco*estoque[0].camisa_estoque[i].quantidade;
                // Atualizando o número total de produtos no estoque
                produtos_no_estoque += estoque[0].camisa_estoque[i].quantidade;
                p++;
                cms++;
                system("cls");

                // Exibindo os dados em formato de tabela
                printf("+--------------------+----------+------------+---------+---------+\n");
                printf("| Tipo               | Código   | Quantidade | Tamanho | Preço   |\n");
                printf("+--------------------+----------+------------+---------+---------+\n");
                printf("| %-18s | %-8d | %-10d | %-7d | %-7.2f |\n",
                    estoque[0].camisa_estoque[i].tipo,
                    estoque[0].camisa_estoque[i].codigo_produto,
                    estoque[0].camisa_estoque[i].quantidade,
                    estoque[0].camisa_estoque[i].tamanho,
                    estoque[0].camisa_estoque[i].preco);
                printf("+--------------------+----------+------------+---------+---------+\n");
                printf("Camisa adicionada com sucesso!\n");
                system("pause");
                system("cls");
                break;
            } else {
                printf("Opção inválida!\n");
            }
        } else {
            printf("Estoque cheio!\n");
            break;
        }
    }
}
void armazena_dados_shorte_estoque() {
    int index = 0;
    for(int i = sh; i < sh + 1; i++){
        if (produtos_no_estoque < capacidades_estoque){
            printf("Digite o tipo de shorte:\n");
            printf("1 - shorte Jeans\n2 - shorte Tactel\n3 - shorte Polo\n|> ");
            scanf("%d", &index);
            if (index >= 1 && index <= 3) {
                // Atribuindo o tipo do shorte ao campo 'tipo'
                if (index == 1) strcpy(estoque[0].shorte_estoque[i].tipo, "shorte Jeans");
                if (index == 2) strcpy(estoque[0].shorte_estoque[i].tipo, "shorte Tactel");
                if (index == 3) strcpy(estoque[0].shorte_estoque[i].tipo, "shorte Polo");

                // Entrada dos outros campos
                printf("Digite o código do produto: ");
                scanf("%d", &estoque[0].shorte_estoque[i].codigo_produto);

                printf("Digite a quantidade: ");
                scanf("%d", &estoque[0].shorte_estoque[i].quantidade);
                if (produtos_no_estoque + estoque[0].shorte_estoque[i].quantidade > capacidades_estoque) {
                    printf("Estoque máximo atingido!\n");
                    estoque[0].shorte_estoque[i].quantidade = 0;
                    estoque[0].shorte_estoque[i].codigo_produto = 0;
                    return;
                }

                printf("Digite o tamanho: ");
                scanf("%d", &estoque[0].shorte_estoque[i].tamanho);

                printf("Digite o preço: ");
                scanf("%f", &estoque[0].shorte_estoque[i].preco);
                financeiro[1].saidas = estoque[0].shorte_estoque[i].preco*estoque[0].shorte_estoque[i].quantidade;
                // Atualizando o número total de produtos no estoque
                produtos_no_estoque += estoque[0].shorte_estoque[i].quantidade;
                p++;
                sh++;
                system("cls");

                // Exibindo os dados em formato de tabela
                printf("+--------------------+----------+------------+---------+---------+\n");
                printf("| Tipo               | Código   | Quantidade | Tamanho | Preço   |\n");
                printf("+--------------------+----------+------------+---------+---------+\n");
                printf("| %-18s | %-8d | %-10d | %-7d | %-7.2f |\n",
                    estoque[0].shorte_estoque[i].tipo,
                    estoque[0].shorte_estoque[i].codigo_produto,
                    estoque[0].shorte_estoque[i].quantidade,
                    estoque[0].shorte_estoque[i].tamanho,
                    estoque[0].shorte_estoque[i].preco);
                printf("+--------------------+----------+------------+---------+---------+\n");
                printf("shorte adicionado com sucesso!\n");
                system("pause");
                system("cls");
                break;
            } else {
                printf("Opção inválida!\n");
            }
        } else {
            printf("Estoque cheio!\n");
            break;
        }
    }
}
void armazena_dados_calca_estoque() {
    int index = 0;
    for(int i = cc;i < cc+1;i++){
    if (produtos_no_estoque < capacidades_estoque) {
        printf("Digite o tipo de calça:\n");
        printf("1 - Calça social\n2 - Calça jeans\n3 - Calça jogger\n|> ");
        scanf("%d", &index);
        if (index >= 1 && index <= 3) {

            // Atribuindo o tipo da calça ao campo 'tipo'
            if (index == 1) strcpy(estoque[0].calca_estoque[i].tipo, "Calça social");
            if (index == 2) strcpy(estoque[0].calca_estoque[i].tipo, "Calça jeans");
            if (index == 3) strcpy(estoque[0].calca_estoque[i].tipo, "Calça jogger");

            // Entrada dos outros campos
            printf("Digite o código do produto: ");
            scanf("%d", &estoque[0].calca_estoque[i].codigo_produto);

            printf("Digite a quantidade: ");
            scanf("%d", &estoque[0].calca_estoque[i].quantidade);
            if (produtos_no_estoque + estoque[0].calca_estoque[i].quantidade > capacidades_estoque) {
                    printf("Estoque máximo atingido!\n");
                    estoque[0].calca_estoque[i].quantidade = 0;
                    estoque[0].calca_estoque[i].codigo_produto = 0;
                    return;
                }

            printf("Digite o tamanho: ");
            scanf("%d", &estoque[0].calca_estoque[i].tamanho);

            printf("Digite o preço: ");
            scanf("%f", &estoque[0].calca_estoque[i].preco);
            financeiro[1].saidas = estoque[0].calca_estoque[i].preco*estoque[0].calca_estoque[i].quantidade;

            // Atualizando o número total de produtos no estoque
            produtos_no_estoque += estoque[0].calca_estoque[i].quantidade;
            p++;
            cc++;
            system("cls");
            // Exibindo os dados em formato de tabela
            printf("+--------------------+----------+------------+---------+---------+\n");
            printf("| Tipo               | Código   | Quantidade | Tamanho | Preço   |\n");
            printf("+--------------------+----------+------------+---------+---------+\n");
            printf("| %-18s | %-8d | %-10d | %-7d | %-7.2f |\n",
                estoque[0].calca_estoque[i].tipo,
                estoque[0].calca_estoque[i].codigo_produto,
                estoque[0].calca_estoque[i].quantidade,
                estoque[0].calca_estoque[i].tamanho,
                estoque[0].calca_estoque[i].preco);
            printf("+--------------------+----------+------------+---------+---------+\n");
            printf("Calça adicionada com sucesso!\n");
            system("pause");
            system("cls");
            break;
            } 
            else {
                printf("Opção inválida!\n");
            }
        } else {
            printf("Estoque cheio!\n");
            break;
        }
    } 
}
void armazena_dados_meia_estoque() {
    for(int i = m;i < m+1;i++){
    int index = 0;
    if (produtos_no_estoque < capacidades_estoque) {
        printf("Digite o tipo de meia:\n");
        printf("1 - Meia cano alto\n2 - Meia cano baixo\n|> ");
        scanf("%d", &index);

        if (index >= 1 && index <= 2) {

            // Atribuindo o tipo da meia
            if (index == 1) strcpy(estoque[0].meia_estoque[i].tipo, "Meia cano alto");
            if (index == 2) strcpy(estoque[0].meia_estoque[i].tipo, "Meia cano baixo");

            printf("Digite o código do produto: ");
            scanf("%d", &estoque[0].meia_estoque[i].codigo_produto);

            printf("Digite a quantidade: ");
            scanf("%d", &estoque[0].meia_estoque[i].quantidade);
            if (produtos_no_estoque + estoque[0].meia_estoque[i].quantidade > capacidades_estoque) {
                    printf("Estoque máximo atingido!\n");
                    estoque[0].meia_estoque[i].quantidade = 0;
                    estoque[0].meia_estoque[i].codigo_produto = 0;
                    return;
                }
            printf("Digite o preço: ");
            scanf("%f",&estoque[0].meia_estoque[i].preco);
            financeiro[1].saidas = estoque[0].meia_estoque[i].preco*estoque[0].meia_estoque[i].quantidade;
            
            produtos_no_estoque += estoque[0].meia_estoque[i].quantidade;
            p++;
            m++;
            system("cls");
            // Exibindo os dados em formato de tabela
            printf("+--------------------+----------+------------+---------+\n");
            printf("| Tipo               | Código   | Quantidade | Preço   |\n");
            printf("+--------------------+----------+------------+---------+\n");
            printf("| %-18s | %-8d | %-10d | %-7.2f |\n",
                   estoque[0].meia_estoque[i].tipo,
                   estoque[0].meia_estoque[i].codigo_produto,
                   estoque[0].meia_estoque[i].quantidade,
                   estoque[0].meia_estoque[i].preco);
            printf("+--------------------+----------+------------+---------+\n");
            printf("Meia adicionada com sucesso!\n");
            system("pause");
            system("cls");
            break;
        } 
        else {
            printf("Opção inválida!\n");
        }
    } 
    else {
        printf("Estoque cheio!\n");
        Bloqueado++;
        }
    }
}
void armazena_dados_assessrios_estoque() {
    for(int i = a;i < a+1;i++){
        int index = 0;
        if (produtos_no_estoque < capacidades_estoque) {
            printf("Digite o tipo de acessório:\n");
            printf("1 - Chapéu\n2 - Boné\n3 - Corrente/pulseira\n4 - Óculos\n|> ");
            scanf("%d", &index);

            if (index >= 1 && index <= 4) {

                // Atribuindo o tipo do acessório
                if (index == 1) strcpy(estoque[0].acessorios_estoque[i].tipo, "Chapéu");
                else if (index == 2) strcpy(estoque[0].acessorios_estoque[i].tipo, "Boné");
                else if (index == 3) strcpy(estoque[0].acessorios_estoque[i].tipo, "Corrente/pulseira");
                else if (index == 4) strcpy(estoque[0].acessorios_estoque[i].tipo, "Óculos");

                printf("Digite o código do produto: ");
                scanf("%d", &estoque[0].acessorios_estoque[i].codigo_produto);

                printf("Digite a quantidade: ");
                scanf("%d", &estoque[0].acessorios_estoque[i].quantidade);

                if (produtos_no_estoque + estoque[0].acessorios_estoque[i].quantidade > capacidades_estoque) {
                    printf("Estoque máximo atingido!\n");
                    estoque[0].acessorios_estoque[i].quantidade = 0;
                    estoque[0].acessorios_estoque[i].codigo_produto = 0;
                    return;
                }

                produtos_no_estoque += estoque[0].acessorios_estoque[i].quantidade;

                printf("Digite o preço do produto: ");
                scanf("%f", &estoque[0].acessorios_estoque[i].preco);
                financeiro[1].saidas = estoque[0].acessorios_estoque[i].preco*estoque[0].acessorios_estoque[i].quantidade;

                system("cls");

                p++;
                a++;
                system("cls");
                // Exibindo os dados em formato de tabela
                printf("+--------------------+----------+------------+---------+\n");
                printf("| Tipo               | Código   | Quantidade | Preço   |\n");
                printf("+--------------------+----------+------------+---------+\n");
                printf("| %-18s | %-8d | %-10d | %-7.2f |\n", 
                    estoque[0].acessorios_estoque[i].tipo,
                    estoque[0].acessorios_estoque[i].codigo_produto,
                    estoque[0].acessorios_estoque[i].quantidade,
                    estoque[0].acessorios_estoque[i].preco);
                printf("+--------------------+----------+------------+---------+\n");

                printf("Acessório adicionado com sucesso!\n");
                system("pause");
                system("cls");
                break;
            } else {
                printf("Opção inválida!\n");
                return;
            }
        } else {
            printf("Estoque cheio!\n");
            Bloqueado++;
            return;
        }
    }
    
}
void armazena_dados_calcados_estoque() {
    for(int i = cd;i < cd+1;i++){
        int index = 0;
        if (produtos_no_estoque < capacidades_estoque) {
            printf("Digite o tipo de calçados:\n");
            printf("1 - Sapato\n2 - Sandália\n3 - Bota\n4 - Tênis\n|> ");
            scanf("%d", &index);

            if (index >= 1 && index <= 4) {

                if (index == 1) strcpy(estoque[0].calcados_estoque[i].tipo, "Sapato");
                else if (index == 2) strcpy(estoque[0].calcados_estoque[i].tipo, "Sandália");
                else if (index == 3) strcpy(estoque[0].calcados_estoque[i].tipo, "Bota");
                else if (index == 4) strcpy(estoque[0].calcados_estoque[i].tipo, "Tênis");

                printf("Digite o código do produto: ");
                scanf("%d", &estoque[0].calcados_estoque[i].codigo_produto);

                printf("Digite a quantidade: ");
                scanf("%d", &estoque[0].calcados_estoque[i].quantidade);

                if (produtos_no_estoque + estoque[0].calcados_estoque[i].quantidade > capacidades_estoque) {
                    printf("Estoque máximo atingido!\n");
                    estoque[0].calcados_estoque[i].codigo_produto = 0;
                    estoque[0].calcados_estoque[i].quantidade = 0;
                    return;
                }
                printf("Digite o Tamanho:");
                scanf("%d", &estoque[0].calcados_estoque[i].tamanho);


                produtos_no_estoque += estoque[0].calcados_estoque[i].quantidade;

                printf("Digite o preço do produto: ");
                scanf("%f", &estoque[0].calcados_estoque[i].preco);
                financeiro[1].saidas = estoque[0].calcados_estoque[i].preco;

                system("cls");

                p++;
                cd++;

                system("cls");
                printf("+--------------------+----------+------------+---------+\n");
                printf("| Tipo               | Código   | Quantidade |  Tamannho | Preço   |\n");
                printf("+--------------------+----------+------------+---------+\n");
                printf("| %-18s | %-8d | %-10d | %-10d | %-7.2f |\n", 
                    estoque[0].calcados_estoque[i].tipo,
                    estoque[0].calcados_estoque[i].codigo_produto,
                    estoque[0].calcados_estoque[i].quantidade,
                    estoque[0].calcados_estoque[i].tamanho,
                    estoque[0].calcados_estoque[i].preco);
                printf("+--------------------+----------+------------+---------+\n");

                printf("Calçado adicionado com sucesso!\n");
                system("pause");
                system("cls");
                break;
            } else {
                printf("Opção inválida!\n");
                return;
            }
        } else {
            printf("Estoque cheio!\n");
            Bloqueado++;
            return;
        }
    }
}
void cadastroDadosProdutos(){
    system("cls");
    
    if(produtos_no_estoque <= capacidades_estoque){ // Verifica se a espaço no estoque
        while(1){
            printf("Oque você Deseja cadastrar\n1 - Camisas\n2 - shorte\n3 - Calças\n4 - Calçados\n5 - Acessorios\n6 - Meia\n|>");
            scanf("%d",&op);
            switch (op){
                case 1:
                    system("cls");
                    armazena_dados_camisa_estoque();
                    break;
                case 2:
                    system("cls");  
                    armazena_dados_shorte_estoque();
                    break;
                case 3:
                    system("cls");
                    armazena_dados_calca_estoque();
                    break;
                case 4:
                    system("cls");
                    armazena_dados_calcados_estoque();
                    break;
                case 5:
                    system("cls");
                    armazena_dados_assessrios_estoque();
                    break;
                case 6:
                    system("cls");
                    armazena_dados_meia_estoque();
                    break;
                default:
                    system("cls");
                    printf("\nOpcao Invalida!\n");// Se ele digitar um numero invalido
            }
            break;
        }
            printf("\nDeseja adicionar mais produtos?\n1-Sim\n2-Não\n>>");
            scanf("%d",&op);
            if(op == 1){ //Repete para adcionar mais produtos
                cadastroDadosProdutos();
            }
            else if(op == 2){ 
                printf("Ate mais!!");
                system("pause");
                system("cls");
                return;
            }   
            else{
                printf("\nOpcao Invalida!\n");// Se ele digitar um numero invalido
            } 
        }
    else{ 
    printf("ESTOQUE BLOQUEADO SUPER-LOTACAO\n");
    Bloqueado++;
    }
}
void todosDadosProdutos(){
    if (produtos_no_estoque > 0) { // Se houver produtos em estoque
        if(cms > 0){
            printf("\n+--------------------+----------+------------+------------+------------+\n");
            printf("\nPRODUTOS EM ESTOQUE:");
            // Listando calçados
            // Exibe a categoria Calçados
            printf("\nCATEGORIA: Cmaisas\n");
            printf("+--------------------+------------+------------+------------+------------+\n");
            printf("| CÓDIGO             | PREÇO      | QUANTIDADE | TAMANHO    | TIPO       |\n");
            printf("+--------------------+------------+------------+------------+------------+\n");
            for (int i = 0; i <= cms-1; i++) { // Supondo que o estoque de calçados seja de até 100 produtos
                if (cms > 0) { // Verifica se o calçado tem quantidade em estoque
                    printf("| %-19d | %-10.2f | %-10d | %-10d | %-10s |\n",
                    estoque[0].camisa_estoque[i].codigo_produto,
                    estoque[0].camisa_estoque[i].preco,
                    estoque[0].camisa_estoque[i].quantidade,
                    estoque[0].camisa_estoque[i].tamanho,
                    estoque[0].camisa_estoque[i].tipo);
                }
                else{
                    break;
                }
            printf("+--------------------+------------+------------+-----------------+\n");
            printf("\nTotal de produtos em estoque: %d\n", cms); 
            printf("\n----------------------------------------------------------------\n");  
            }    
        }
        else{
            printf("ESTOQUE VAZIO DE CAMISAS VAZIO!\n");
        }

        if(sh > 0){
            printf("\nCATEGORIA: Short\n");
            printf("+--------------------+------------+------------+------------+------------+\n");
            printf("| CÓDIGO             | PREÇO      | QUANTIDADE | TAMANHO    | TIPO       |\n");
            printf("+--------------------+------------+------------+------------+------------+\n");
            for (int i = 0; i <= sh-1; i++) { // Supondo que o estoque de calçados seja de até 100 produtos
                if (sh > 0) { // Verifica se o calçado tem quantidade em estoque
                    printf("| %-19d | %-10.2f | %-10d | %-10d | %-10s |\n",
                    estoque[0].shorte_estoque[i].codigo_produto,
                    estoque[0].shorte_estoque[i].preco,
                    estoque[0].shorte_estoque[i].quantidade,
                    estoque[0].shorte_estoque[i].tamanho,
                    estoque[0].shorte_estoque[i].tipo);
                }
                else{
                    break;
                }
            }
            printf("+--------------------+------------+------------+-----------------+\n");
            printf("\nTotal de produtos em estoque: %d\n", sh); 
            printf("\n----------------------------------------------------------------\n");  
        }
        else{
            printf("\nESTOQUE VAZIO DE SHORTS!\n");
        }
        if(cc > 0){
            printf("\nCATEGORIA: Calcas\n");
            printf("+--------------------+------------+------------+------------+------------+\n");
            printf("| CÓDIGO             | PREÇO      | QUANTIDADE | TAMANHO    | TIPO       |\n");
            printf("+--------------------+------------+------------+------------+------------+\n");
            for (int i = 0; i <= cc-1; i++) { // Supondo que o estoque de acessórios seja de até 100 produtos
                if (cc > 0) { // Verifica se o acessório tem quantidade em estoque
                    printf("| %-19d | %-10.2f | %-10d | %-10d | %-10s |\n",
                        estoque[0].calca_estoque[i].codigo_produto,
                        estoque[0].calca_estoque[i].preco,
                        estoque[0].calca_estoque[i].quantidade,
                        estoque[0].calca_estoque[i].tamanho,
                        estoque[0].calca_estoque[i].tipo);
                }
                else{
                    break;
                }
            }
            printf("+--------------------+------------+------------+-----------------+\n");
            printf("\nTotal de produtos em estoque: %d\n", cc); 
            printf("\n----------------------------------------------------------------\n");
        }
        else{
            printf("\nESTOQUE VAZIO DE CALÇAS!\n");
        }
        if(cd > 0){
           printf("\nCATEGORIA: CALÇADOS\n");
            printf("+--------------------+------------+------------+------------+------------+\n");
            printf("| CÓDIGO             | PREÇO      | QUANTIDADE | TAMANHO    | TIPO       |\n");
            printf("+--------------------+------------+------------+------------+------------+\n");
            for (int i = 0; i <= cd-1; i++) { // Supondo que o estoque de calçados seja de até 100 produtos
                if (cd > 0) { // Verifica se o calçado tem quantidade em estoque
                    printf("| %-19d | %-10.2f | %-10d | %-10d | %-10s |\n",
                    estoque[0].calcados_estoque[i].codigo_produto,
                    estoque[0].calcados_estoque[i].preco,
                    estoque[0].calcados_estoque[i].quantidade,
                    estoque[0].calcados_estoque[i].tamanho,
                    estoque[0].calcados_estoque[i].tipo);
                }
                else{
                    break;
                }
            }    
            printf("+--------------------+------------+------------+-----------------+\n");
            printf("\nTotal de produtos em estoque: %d\n", cd); 
            printf("\n----------------------------------------------------------------\n");
        }
        else{
            printf("\nESTOQUE VAZIO DE CALÇADOS!\n");
        }
        if(a > 0){
            printf("\nCATEGORIA: ACESSÓRIOS\n");
            printf("+--------------------+------------+------------+------------+\n");
            printf("| CÓDIGO             | PREÇO      | QUANTIDADE | TIPO       \n");
            printf("+--------------------+------------+------------+------------+\n");
            for (int i = 0; i <= a-1; i++) { // Supondo que o estoque de acessórios seja de até 100 produtos
                if (a > 0) { // Verifica se o acessório tem quantidade em estoque
                    printf("| %-19d | %-10.2f | %-10d | %-10s |\n", 
                        estoque[0].acessorios_estoque[i].codigo_produto, 
                        estoque[0].acessorios_estoque[i].preco, 
                        estoque[0].acessorios_estoque[i].quantidade,
                        estoque[0].acessorios_estoque[i].tipo);
                }
                else{
                    break;
                }
            }
            printf("+--------------------+------------+------------+-----------------+\n");
            printf("\nTotal de produtos em estoque: %d\n", a); 
            printf("\n----------------------------------------------------------------\n");
        }
        else{
            printf("\nESTOQUE VAZIO DE ACESSORIOS!\n");
        }
        if(m > 0){
            printf("\nCATEGORIA: Meias\n");
            printf("+--------------------+------------+------------+------------+\n");
            printf("| CÓDIGO             | PREÇO      | QUANTIDADE | TIPO       |\n");
            printf("+--------------------+------------+------------+------------+\n");
            for (int i = 0; i <= m-1; i++) { // Supondo que o estoque de acessórios seja de até 100 produtos
                if (m > 0) { // Verifica se o acessório tem quantidade em estoque
                    printf("| %-19d | %-10.2f | %-10d | %-10s |\n", 
                        estoque[0].meia_estoque[i].codigo_produto, 
                        estoque[0].meia_estoque[i].preco, 
                        estoque[0].meia_estoque[i].quantidade, 
                        estoque[0].meia_estoque[i].tipo);
                }
                else{
                    break;
                }
            }
            printf("+--------------------+------------+------------+--------------+\n");
            printf("\nTotal de produtos em estoque: %d\n", m);
        }
        else{
            printf("\nESTOQUE VAZIO DE MEIA!\n");
        }
    }
    else {
        printf("Nenhum produto cadastrado em estoque.\n"); // Caso não haja produtos em estoque
    }
}
void PesquisarPorCodigo(){  
    if(p != 0){ // Verifica se a produtos no estoque
    int codigo_pesquisa;
    int categoria; // Variavel para guardar a categoria do produto.
    printf("Dgite qual é a categoria do produto\n1 - Camisas\n2 - Calsas\n3 - Meias\n4 - Acessorios\n5 - Calcados\n6 - shortes\n7 - \n8 - ");
    scanf("%d",&categoria); // Permite escolher a categoria do produto.

    if( categoria == 0 ){
        printf("Voce não pode pesquisar por produto sem categoria.\n"); // Caso não seja escolhida uma categoria.
        PesquisarPorCodigo(); // Função para pesquisar produto pelo codigo.
    }
    
    else if( categoria == 1 ){
        while(1){
            printf("Digite o codigo do produto que deseja pesquisar: ");
            scanf("%d",&codigo_pesquisa);
                for(int i = 0; i < p; i++){ // Procura o codigo
                    int op = 0;
                    if(estoque[i].camisa_estoque[0].codigo_produto == codigo_pesquisa){ // Procura o codigo se for existente
                        printf("\nCODIGO: %d\n",estoque[0].camisa_estoque[i].codigo_produto); // Exibe o codigo do produto do estoque.
                        printf("Quantidade: %d\n",estoque[0].camisa_estoque[i].quantidade); // Quantidade do produto em estoque
                        printf("Tamanho: %d\n",estoque[0].camisa_estoque[i].tamanho); // Tamanho do produto
                        printf("Preco: %.2f\n",estoque[0].camisa_estoque[i].preco); // Preço do produto
                        system("pause");
                        printf("Deseja procura por outro codigo.\n1 - Sim\n2- Sair");
                        scanf("%d",&op);  // Permite escolher
                        if(op == 1){
                            system("cls");
                            PesquisarPorCodigo();//Função para pesquisar produto pelo codigo.
                        }
                        else{
                            system("cls");
                            return;
                        }
                    }
                    else{ // Se nãoo for existente
                        if(i <= 1){
                        printf("\nNenhum produto encontrado com esse codigo.\n"); // Caso não haja produto com esse codigo.
                    }
                }   
            }
        }
    }
    else if( categoria == 2 ){
        while(1){
            printf("Digite o codigo do produto que deseja pesquisar: ");
            scanf("%d",&codigo_pesquisa);
                for(int i = 0; i < p; i++){ // Procura o codigo
                    int op = 0;
                    if(estoque[i].calca_estoque[0].codigo_produto == codigo_pesquisa){ // Procura o codigo se for existente
                        printf("\nCODIGO: %d\n",estoque[0].calca_estoque[i].codigo_produto); // Exibe o codigo do produto do estoque.
                        printf("Quantidade: %d\n",estoque[0].calca_estoque[i].quantidade); // Quantidade do produto em estoque
                        printf("Tamanho: %d\n",estoque[0].calca_estoque[i].tamanho); // Tamanho do produto
                        printf("Preco: %.2f\n",estoque[0].calca_estoque[i].preco); // Preço do produto
                        system("pause");
                        printf("Deseja procura por outro codigo.\n1 - Sim\n2- Sair");
                        scanf("%d",&op);  // Permite escolher
                        if(op == 1){
                            system("cls");
                            PesquisarPorCodigo();//Função para pesquisar produto pelo codigo.
                        }
                        else{
                            system("cls");
                            return;
                        }
                    }
                    else{ // Se nãoo for existente
                        if(i <= 1){
                        printf("\nNenhum produto encontrado com esse codigo.\n"); // Caso não haja produto com esse codigo.
                    }
                }   
            }
        }
    }
    else if( categoria == 3 ){
        printf("Digite o codigo do produto que deseja pesquisar: ");
        scanf("%d",&codigo_pesquisa);
            for(int i = 0; i < p; i++){ // Procura o codigo
                int op = 0;
                if(estoque[i].meia_estoque[0].codigo_produto == codigo_pesquisa){ // Procura o codigo se for existente
                    printf("\nCODIGO: %d\n",estoque[0].meia_estoque[i].codigo_produto); // Exibe o codigo do produto do estoque.
                    printf("Quantidade: %d\n",estoque[0].meia_estoque[i].quantidade); // Quantidade do produto em estoque
                    printf("Preco: %.2f\n",estoque[0].meia_estoque[i].preco); // Preço do produto
                    system("pause");
                    printf("Deseja procura por outro codigo.\n1 - Sim\n2- Sair");
                    scanf("%d",&op);  // Permite escolher
                    if(op == 1){
                        system("cls");
                        PesquisarPorCodigo();//Função para pesquisar produto pelo codigo.
                    }
                    else{
                        system("cls");
                        return;
                    }
                }
                else{ // Se nãoo for existente
                    if(i <= 1){
                    printf("\nNenhum produto encontrado com esse codigo.\n"); // Caso não haja produto com esse codigo.
                }
            }   
        }
    }
    else if( categoria == 4 ){
        while(1){
            printf("Digite o codigo do produto que deseja pesquisar: ");
            scanf("%d",&codigo_pesquisa);
                for(int i = 0; i < p; i++){ // Procura o codigo
                    int op = 0;
                    if(estoque[i].acessorios_estoque[0].codigo_produto == codigo_pesquisa){ // Procura o codigo se for existente
                        printf("\nCODIGO: %d\n",estoque[0].acessorios_estoque[i].codigo_produto); // Exibe o codigo do produto do estoque.
                        printf("Quantidade: %d\n",estoque[0].acessorios_estoque[i].quantidade); // Quantidade do produto em estoque
                        printf("Preco: %.2f\n",estoque[0].acessorios_estoque[i].preco); // Preço do produto
                        system("pause");
                        printf("Deseja procura por outro codigo.\n1 - Sim\n2- Sair");
                        scanf("%d",&op);  // Permite escolher
                        if(op == 1){
                            system("cls");
                            PesquisarPorCodigo();//Função para pesquisar produto pelo codigo.
                        }
                        else{
                            system("cls");
                            return;
                        }
                    }
                    else{ // Se nãoo for existente
                        if(i <= 1){
                        printf("\nNenhum produto encontrado com esse codigo.\n"); // Caso não haja produto com esse codigo.
                    }
                }   
            }
        }
    }
    else if( categoria == 5 ){
        while(1){
            printf("Digite o codigo do produto que deseja pesquisar: ");
            scanf("%d",&codigo_pesquisa);
                for(int i = 0; i < p; i++){ // Procura o codigo
                    int op = 0;
                    if(estoque[i].calcados_estoque[0].codigo_produto == codigo_pesquisa){ // Procura o codigo se for existente
                        printf("\nCODIGO: %d\n",estoque[0].calcados_estoque[i].codigo_produto); // Exibe o codigo do produto do estoque.
                        printf("Quantidade: %d\n",estoque[0].calcados_estoque[i].quantidade); // Quantidade do produto em estoque
                        printf("Tamanho: %d\n",estoque[0].calcados_estoque[i].tamanho); // Tamanho do produto
                        printf("Preco: %.2f\n",estoque[0].calcados_estoque[i].preco); // Preço do produto
                        system("pause");
                        printf("Deseja procura por outro codigo.\n1 - Sim\n2- Sair");
                        scanf("%d",&op);  // Permite escolher
                        if(op == 1){
                            system("cls");
                            PesquisarPorCodigo();//Função para pesquisar produto pelo codigo.
                        }
                        else{
                            system("cls");
                            return;
                        }
                    }
                    else{ // Se nãoo for existente
                        if(i <= 1){
                        printf("\nNenhum produto encontrado com esse codigo.\n"); // Caso não haja produto com esse codigo.
                    }
                }   
            }
        }
    }
    else if( categoria == 6 ){
        while(1){
            printf("Digite o codigo do produto que deseja pesquisar: ");
            scanf("%d",&codigo_pesquisa);
                for(int i = 0; i < p; i++){ // Procura o codigo
                    int op = 0;
                    if(estoque[i].shorte_estoque[0].codigo_produto == codigo_pesquisa){ // Procura o codigo se for existente
                        printf("\nCODIGO: %d\n",estoque[0].shorte_estoque[i].codigo_produto); // Exibe o codigo do produto do estoque.
                        printf("Quantidade: %d\n",estoque[0].shorte_estoque[i].quantidade); // Quantidade do produto em estoque
                        printf("Tamanho: %d\n",estoque[0].shorte_estoque[i].tamanho); // Tamanho do produto
                        printf("Preco: %.2f\n",estoque[0].shorte_estoque[i].preco); // Preço do produto
                        system("pause");
                        printf("Deseja procura por outro codigo.\n1 - Sim\n2- Sair");
                        scanf("%d",&op);  // Permite escolher
                        if(op == 1){
                            system("cls");
                            PesquisarPorCodigo();//Função para pesquisar produto pelo codigo.
                        }
                        else{
                            system("cls");
                            return;
                        }
                    }
                    else{ // Se nãoo for existente
                        if(i <= 1){
                        printf("\nNenhum produto encontrado com esse codigo.\n"); // Caso não haja produto com esse codigo.
                    }
                }   
            }
        }
    }
    }
    else{
        printf("\nNenhum produto cadastrado no estoque.\n"); // Caso não haja produtos em estoque.
    }
}
void exibirDadosClientes() {
    if(*pQuantidade_de_clientes_cadastradas > 0){
        printf("\nCLIENTES CADASTRADOS:\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("| %-4s | %-15s | %-25s | %-30s |\n", "No.", "CPF", "Nome", "Email");
        printf("-------------------------------------------------------------------------------\n");
        for (int i = 0; i < (*pQuantidade_de_clientes_cadastradas); i++) {
            printf("| %-4d | %-15.0lf | %-25s | %-30s |\n", 
                i + 1, clientes[i].cpf, clientes[i].nome, clientes[i].email);
        }
        printf("-------------------------------------------------------------------------------\n");
        system("pause");
        system("cls");
    }
    else{
        printf("\nNenhum cliente cadastrado.\n");
        system("pause");
        system("cls");
    }
    return;
}
void exibirDadosEmpresas() {
    if((*pQuantidade_de_empresa_cadastradas) > 0){
        printf("\nEMPRESAS CADASTRADAS:\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("| %-4s | %-25s | %-30s |\n", "No.", "CNPJ", "Nome da Empresa");
        printf("-------------------------------------------------------------------------------\n");
        for (int i = 0; i < (*pQuantidade_de_empresa_cadastradas); i++) {
            printf("| %-4d | %-25.0lf | %-25s |\n", i + 1, empresas[i].cnpj, empresas[i].nome_empresa);
        }
        printf("-------------------------------------------------------------------------------\n");
        system("pause");
        system("cls");
    }
    else{
        printf("\nNenhuma empresa cadastrada.\n");
        system("pause");
        system("cls");
    }
    return;
}
void cadastroDadosCliente(){
    // Acessa o índice atual de clientes com base no contador
    int i = *pQuantidade_de_clientes_cadastradas;
    printf("\nCADASTRO DE CLIENTES:");
    printf("\n---------------\n");
    while (1){ // while que força o usuário a corrigir o CPF
        printf("1. CPF (apenas números): ");
        scanf("%lf", &clientes[i].cpf);
        if (clientes[i].cpf >= 10000000000.0 && clientes[i].cpf <= 99999999999.0){// Verifica se o CPF tem 11 dígitos
            break; // CPF válido
        } else{
            printf("CPF inválido! Digite novamente (apenas 11 números).\n");
        }
    }
        // Um CPF tem 11 numeros, acima eu verifico se o usuario digitou a quantidade correta de numero para que seja o CPF valido
        printf("2. NOME COMPLETO: "); // Pede o nome do cliente
        setbuf(stdin, NULL);
        fgets(clientes[i].nome,50, stdin);
        printf("3. EMAIL: ");
        setbuf(stdin, NULL);
        fgets(clientes[i].email,50, stdin);
        (*pQuantidade_de_clientes_cadastradas)++; //Adiciona + 1 Cliente cadastrado e armazena a quantidade de clientes que estão sendo cadastradas.
        system("cls");
        printf("Cliente cadastrado com sucesso!!\n");
        printf("--------------------------------\n");
        printf("CPF: %.0lf\n", clientes[i].cpf);
        printf("Nome: %s", clientes[i].nome);
        printf("Email: %s", clientes[i].email);
        printf("--------------------------------\n");

        system("pause");
}
void cadastroDadosEmpresa(){
    system("cls");
    int i = *pQuantidade_de_clientes_cadastradas;
    printf("\nCADASTRO DE EMPRESA:");
    printf("\n---------------\n");
    // Um cnjp tem 14 numeros, abaixo eu verifico se o usuario digitou a quantidade correta de numero para que seja o CPNJ valido
    while (1) { // Verifica se o CNPJ possui 14 dígitos
        printf("CNPJ da empresa (apenas números): ");
        scanf("%lf", &empresas[i].cnpj);
        if (empresas[i].cnpj >= 10000000000000.0 && empresas[i].cnpj <= 99999999999999.9){
            break; // CNPJ válido
        } else {
            system("cls");
            printf("CNPJ inválido! Digite novamente (apenas 14 números).\n");
        }
    }
        printf("Nome da empresa:"); // Pede o nome da empresa
        setbuf(stdin, NULL);
        fgets(empresas[i].nome_empresa,100, stdin);
        
        (*pQuantidade_de_empresa_cadastradas)++; //Adiciona + 1 empresa cadastrada
        system("cls");
        printf("\nEmpresa cadastrada com sucesso!\n");
        printf("--------------------------------\n");
        printf("CNPJ: %.0lf\n", empresas[i].cnpj);
        printf("Nome: %s", empresas[i].nome_empresa);
        printf("--------------------------------\n");
        system("pause");   
}
void estoque_produtos(){
    int op;
    int capacidade_total = capacidades_estoque;
    printf("\nCAPACIDADE TOTAL:%d\n", capacidade_total);
    printf("PRODUTOS NO ESTOQUE:%d\n", produtos_no_estoque); // Mostra a quantidade de produtos em estoque.
    printf("PRODUTOS BLOQUEADOS:%d\n", Bloqueado); // Mostra a quantidade de produtos que foram bloqueado por estoque cheio
    printf("ESPAÇO EM ESTOQUE:%d\n", capacidade_total - produtos_no_estoque); // Mostra o espaço disponivel no estoque. // Mostra o cabeçalho da tabela do estoque.
    printf("\nPRCURAR POR \n1)CODIGO\n2)LISTAR TODOS OS PRODUTOS EM ESTOQUE\n|>");
    scanf("%d",&op); // Permite escolher o tipo de pesquisa.
    system("cls");
    if(op == 1){
        op = 0;
        PesquisarPorCodigo();  //Função para pesquisar produto pelo codigo.
    }
    else if(op == 2){
        op = 0;
        todosDadosProdutos();  //Função para listar todos os produtos em estoque.
        system("pause");
        system("cls");
        estoque_produtos();
    }
    else{
        printf("\nOpcao Invalida!\n");
        return;
    }
}
void buscar_produtos(){
    int qtd = 0, tmn = 0;
    printf("Categoria:\n");
    printf("1 - CAMISAS\n2 - short\n3 - CALÇAS\n4 - CALÇADOS\n5 - MEIAS\n6 - ACESSORIOS ou 0 para sair\n|>");
    scanf("%d",&op);
    switch(op){
        case 1:
            if(cms > 0){
                printf("\nModelos, tamanhos e quantidade de camisa disponíveis:\n");
                printf("-------------------------------------------------------------\n");
                printf("| %-4s | %-20s | %-10s | %-10s | %-10s |\n", "No.", "Modelo", "Tamanho", "Quantidade", "Preço");
                printf("-------------------------------------------------------------\n");
                for (int i = 0; i < cms-1; i++) {
                    printf("| %-4d | %-20s | %-10d | %-10d | %-10f |\n", 
                    i + 1, estoque[0].camisa_estoque[i].tipo, 
                    estoque[0].camisa_estoque[i].tamanho, 
                    estoque[0].camisa_estoque[i].quantidade,
                    estoque[0].camisa_estoque[i].preco);
                }
                printf("\nDigite 1 a 5 o modelo de acordo com a ordem na tabela: ");
                scanf("%d", &op);
                if (op >= 1 && op <= 5) {
                    printf("Digite a quantidade de produtos que deseja:");
                    scanf("%d",&qtd);
                    printf("Digite o tamanho que Deseja:");
                    scanf("%d",&tmn);
                    system("cls");
                    printf("\nDeseja confirmar a compra?\n1 - SIM\n2 - NÃO");
                    printf("\n\nModelo: %s\nTamanho: %d\nQuantidade: %d\nPreço: R$%.2f\n|>",estoque[0].camisa_estoque[op-1].tipo,tmn,qtd,(estoque[0].camisa_estoque[op-1].preco*qtd));
                    scanf("%d",&op);
                    if( op == 1){
                        printf("\nCompra confirmada com sucesso!\n");
                        // Atualiza o estoque
                        estoque[0].camisa_estoque[op-1].vendidos += 1;
                        estoque[0].camisa_estoque[op-1].quantidade -= qtd;
                        produtos_no_estoque -= qtd;
                        financeiro[1].entradas += estoque[0].camisa_estoque[op-1].preco*qtd;
                        system("pause");
                        system("cls");
                    }
                    else{
                        printf("\nCompra cancelada.\n");
                        break;
                    }
                } else {
                    system("cls");
                    printf("\nOpção inválida. Tente novamente.\n");
                    buscar_produtos();
                }
            }
            else{
                printf("Não temos esse modelo em estoque.\n");
                break;
            }
            printf("-------------------------------------------------------------\n");
            break;
        case 2:
            if(sh > 0){
                printf("\nModelos, tamanhos e quantidade de camisas disponíveis:\n");
                printf("-------------------------------------------------------------\n");
                printf("| %-4s | %-20s | %-10s | %-10s |\n", "No.", "Modelo", "Tamanho", "Quantidade");
                printf("-------------------------------------------------------------\n");
                for (int i = 0; i < sh; i++) {
                    printf("| %-4d | %-20s | %-10d | %-10d |\n", 
                    i + 1, estoque[0].shorte_estoque[i].tipo, 
                    estoque[0].shorte_estoque[i].tamanho, 
                    estoque[0].shorte_estoque[i].quantidade);
                }
                printf("\nDigite 1 a 5 o modelo de acordo com a ordem na tabela: ");
                scanf("%d", &op);
                if (op >= 1 && op <= 5) {
                    printf("Digite a quantidade de produtos que deseja:");
                    scanf("%d",&qtd);
                    printf("Digite o tamanho que Deseja");
                    scanf("%d",&tmn);
                    system("cls");
                    printf("\nDeseja confirmar a compra?\n1 - SIM\n2 - NÃO");
                    printf("\n\nModelo: %s\nTamanho: %d\nQuantidade: %d\nPreço: R$%.2f\n|>",estoque[0].shorte_estoque[op-1].tipo,tmn,qtd,(estoque[0].shorte_estoque[op-1].preco*qtd));
                    scanf("%d",&op);
                    if( op == 1){
                        printf("\nCompra confirmada com sucesso!\n");
                        // Atualiza o estoque
                        estoque[0].shorte_estoque[op-1].vendidos += 1;
                        estoque[0].shorte_estoque[op-1].quantidade -= qtd;
                        produtos_no_estoque -= qtd;
                        financeiro[1].entradas += estoque[0].shorte_estoque[op-1].preco*qtd;
                        system("pause");
                        system("cls");
                    }
                    else{
                        printf("\nCompra cancelada.\n");
                        break;
                    }
                } else {
                    system("cls");
                    printf("\nOpção inválida. Tente novamente.\n");
                    buscar_produtos();
                }
            }
            else{
                printf("Não temos essa peça em estoque.\n");
                break;
            }
            printf("-------------------------------------------------------------\n");
            break;
        case 3:
            if(cc > 0){
                printf("\nModelos, tamanhos e quantidade de calças disponíveis:\n");
                printf("-------------------------------------------------------------\n");
                printf("| %-4s | %-20s | %-10s | %-10s |\n", "No.", "Modelo", "Tamanho", "Quantidade");
                printf("-------------------------------------------------------------\n");
                for (int i = 0; i < cc; i++) {
                    printf("| %-4d | %-20s | %-10d | %-10d |\n", 
                    i + 1, estoque[0].calca_estoque[i].tipo, 
                    estoque[0].calca_estoque[i].tamanho, 
                    estoque[0].calca_estoque[i].quantidade);
                }
                printf("\nDigite 1 a 5 o modelo de acordo com a ordem na tabela: ");
                scanf("%d", &op);
                if (op >= 1 && op <= cc) {
                    printf("Digite a quantidade de produtos que deseja:");
                    scanf("%d",&qtd);
                    printf("Digite o tamanho que Deseja");
                    scanf("%d",&tmn);
                    system("cls");
                    printf("\nDeseja confirmar a compra?\n1 - SIM\n2 - NÃO");
                    printf("\n\nModelo: %s\nTamanho: %d\nQuantidade: %d\nPreço: R$%.2f\n|>",estoque[0].calca_estoque[op-1].tipo,tmn,qtd,(estoque[0].calca_estoque[op-1].preco*qtd));
                    scanf("%d",&op);
                    if( op == 1){
                        printf("\nCompra confirmada com sucesso!\n");
                        // Atualiza o estoque
                        estoque[0].calca_estoque[op-1].vendidos += 1;
                        estoque[0].calca_estoque[op-1].quantidade -= qtd;
                        produtos_no_estoque -= qtd;
                        financeiro[1].entradas += estoque[0].calca_estoque[op-1].preco*qtd;
                        system("pause");
                        system("cls");
                    }
                    else{
                        printf("\nCompra cancelada.\n");
                        break;
                    }
                } else {
                    system("cls");
                    printf("\nOpção inválida. Tente novamente.\n");
                    buscar_produtos();
                }
            }
            else{
                printf("Não temos essa peça em estoque.\n");
                break;
            }
            printf("-------------------------------------------------------------\n");
            break;
        case 4:
            if(cd > 0){
                printf("\nModelos, tamanhos e quantidade de calçados disponíveis:\n");
                printf("-------------------------------------------------------------\n");
                printf("| %-4s | %-20s | %-10s | %-10s |\n", "No.", "Modelo", "Tamanho", "Quantidade");
                printf("-------------------------------------------------------------\n");
                for (int i = 0; i < cd; i++) {
                    printf("| %-4d | %-20s | %-10d | %-10d |\n", 
                        i + 1, estoque[0].calcados_estoque[i].tipo, 
                        estoque[0].calcados_estoque[i].tamanho, 
                        estoque[0].calcados_estoque[i].quantidade);
                }
                printf("\nDigite 1 a 5 o modelo de acordo com a ordem na tabela: ");
                scanf("%d", &op);

                if (op >= 1 && op <= cd) {
                
                    printf("Digite a quantidade de produtos que deseja:");
                    scanf("%d",&qtd);
                    printf("Digite o tamanho que Deseja");
                    scanf("%d",&tmn);
                    system("cls");
                    printf("\nDeseja confirmar a compra?\n1 - SIM\n2 - NÃO");
                    printf("\n\nModelo: %s\nTamanho: %d\nQuantidade: %d\nPreço: R$%.2f\n|>",estoque[0].calcados_estoque[op-1].tipo,tmn,qtd,(estoque[0].calcados_estoque[op-1].preco*qtd));
                    scanf("%d",&op);
                    if( op == 1){
                        printf("\nCompra confirmada com sucesso!\n");
                        // Atualiza o estoque
                        estoque[0].calcados_estoque[op-1].vendidos += 1;
                        estoque[0].calcados_estoque[op-1].quantidade -= qtd;
                        produtos_no_estoque -= qtd;
                        financeiro[1].entradas += estoque[0].calcados_estoque[op-1].preco*qtd;
                        system("pause");
                        system("cls");
                    }
                    else{
                        printf("\nCompra cancelada.\n");
                        break;
                    }
                } else {
                    system("cls");
                    printf("\nOpção inválida. Tente novamente.\n");
                    buscar_produtos();
                }
            }
            else{
                printf("Não temos essa peça em estoque.\n");
                break;
            }
            printf("-------------------------------------------------------------\n");
            break;
        case 5:
            if(m > 0){
                printf("\nModelos, tamanhos e quantidade de meias disponíveis:\n");
                printf("-------------------------------------------------------------\n");
                printf("| %-4s | %-20s | %-10s |\n", "No.", "Modelo", "Quantidade");
                printf("-------------------------------------------------------------\n");
                for (int i = 0; i < m; i++) {
                    printf("| %-4d | %-20s | %-10d |\n", 
                        i + 1, estoque[0].meia_estoque[i].tipo, 
                        estoque[0].meia_estoque[i].quantidade);
                }
                printf("\nDigite 1 a 5 o modelo de acordo com a ordem na tabela: ");
                scanf("%d", &op);

                if (op >= 1 && op <= m) {
                    printf("Digite a quantidade de produtos que deseja:");
                    scanf("%d",&qtd);
                    system("cls");
                    printf("\nDeseja confirmar a compra?\n1 - SIM\n2 - NÃO");
                    printf("\n\nModelo: %s\nQuantidade: %d\nPreço: R$%.2f\n|>",estoque[0].meia_estoque[op-1].tipo,qtd,(estoque[0].meia_estoque[op-1].preco*qtd));
                    scanf("%d",&op);
                    if( op == 1){
                        printf("\nCompra confirmada com sucesso!\n");
                        // Atualiza o estoque
                        estoque[0].meia_estoque[op-1].vendidos += 1;
                        estoque[0].meia_estoque[op-1].quantidade -= qtd;
                        produtos_no_estoque -= qtd;
                        financeiro[1].saidas += estoque[0].meia_estoque[op-1].preco*qtd;
                        system("pause");
                        system("cls");
                    }
                    else{
                        printf("\nCompra cancelada.\n");
                        break;
                    }
                } else {
                    system("cls");
                    printf("\nOpção inválida. Tente novamente.\n");
                    buscar_produtos();
                }
            }
            else{
                printf("Não temos essa peça em estoque.\n");
                break;
            }
            printf("-------------------------------------------------------------\n");
            break;
        case 6:
            if(a > 0){
                printf("\nModelos, tamanhos e quantidade de acessoorios disponíveis:\n");
                printf("-------------------------------------------------------------\n");
                printf("| %-4s | %-20s | %-10s |\n", "No.", "Modelo", "Quantidade");
                printf("-------------------------------------------------------------\n");
                for (int i = 0; i < a; i++) {
                    printf("| %-4d | %-20s | %-10d |\n", 
                        i + 1, estoque[0].acessorios_estoque[i].tipo, 
                        estoque[0].acessorios_estoque[i].quantidade);
                }
                printf("\nDigite 1 a 5 o modelo de acordo com a ordem na tabela: ");
                scanf("%d", &op);

                if (op >= 1 && op <= a) {
                    printf("Digite a quantidade de produtos que deseja:");
                    scanf("%d",&qtd);
                    printf("Digite o tamanho que Deseja");
                    scanf("%d",&tmn);
                    system("cls");
                    printf("\nDeseja confirmar a compra?\n1 - SIM\n2 - NÃO");
                    printf("\n\nModelo: %s\nTamanho: %d\nQuantidade: %d\nPreço: %.2f\n|>",estoque[0].meia_estoque[op-1].tipo,tmn,qtd,estoque[0].meia_estoque[op-1].preco);
                    scanf("%d",&op);
                    if( op == 1){
                        printf("\nCompra confirmada com sucesso!\n");
                        // Atualiza o estoque
                        estoque[0].meia_estoque[op-1].vendidos += 1;
                        estoque[0].meia_estoque[op-1].quantidade -= qtd;
                        produtos_no_estoque -= qtd;
                        financeiro[1].saidas += estoque[0].meia_estoque[op-1].preco*qtd;
                        system("pause");
                        system("cls");
                    }
                    else{
                        printf("\nCompra cancelada.\n");
                        break;
                    }
                } else {
                    system("cls");
                    printf("\nOpção inválida. Tente novamente.\n");
                    buscar_produtos();
                }
            }
            else{
                printf("Não temos essa peça em estoque.\n");
                break;
            }
            printf("-------------------------------------------------------------\n");
        case 0:
            break;
        default:
            printf("NUMERO [%d] INVALIDO, DIGITE UM NUMERO LEGIVEL\n",op);
            buscar_produtos();
    }
    return;
}
void vendas(){
    printf("\nBem vindo a Elemental");
    printf("\nEscolha um categoria que Deseja buscar");
    printf("\n1 - PRODUTOS\n2 - SAIR\n|>");
    scanf("%d",&op);
    if(op == 1){
        system("cls");
        buscar_produtos();
    }
    else if(op == 2){
        system("cls");
        return;
    }
    else{
        system("cls");
        printf("\nNUMERO [%d] INVALIDO, DIGITE UM NUMERO LEGIVEL\n",op);
        vendas();
    }
}
void login_empresa(){
    double cnpj = 0; // Declara uma variável para armazenar o CNPJ digitado pelo usuário.
    printf("Digite o CNPJ ou digite 0 para sair:\n|>"); // Exibe uma mensagem para o usuário informar um CNPJ ou optar por sair.
    scanf("%lf", &cnpj); 
    // Lê o valor inteiro digitado pelo usuário e armazena na variável `cnpj`.
    if (cnpj != 0) { 
        // ERRO: Aqui há uma comparação errada. `cnpj` é do tipo `int` e está sendo comparado com uma string `"0"`.
        // A comparação correta seria: ``.

        for (int i = 0; i < 20; i++) { 
            // Inicia um loop para verificar o CNPJ informado em até 20 registros.
            if (cnpj == empresas[i].cnpj) { 
                // Verifica se o CNPJ informado coincide com o CNPJ de uma empresa no array `empresas`.
                // Caso o CNPJ seja encontrado, chama a função `cadastroDadosProdutos`.
                system("cls");
                printf("Cadastro encontrado.\n"); // Exibe uma mensagem indicando que a empresa foi encontrada.
                cadastroDadosProdutos();  // Chama a função `cadastroDadosProdutos`, que provavelmente faz o cadastro de produtos para a empresa.
                return; // Interrompe o loop para evitar verificação de empresas restantes.
            } 
            else if (i == 19) { 
                // Verifica se chegou ao final da lista de empresas e o CNPJ não foi encontrado.
                system("cls");
                printf("Cadastro não encontrado.\n"); 
                // Informa ao usuário que o cadastro não foi encontrado.
                login_empresa(); 
                // Chama a própria função `login_empresa` novamente, permitindo uma nova tentativa de login.
            }
        }
    } 
    else if (cnpj == 0) { 
        // Caso o usuário tenha digitado 0, encerra o programa.

        system("cls");
        printf("\nPrograma encerrado.\n"); // Exibe uma mensagem indicando que o programa foi encerrado.
    } 
    else { 
        // Caso nenhuma das condições anteriores seja verdadeira, executa o bloco abaixo.
        system("cls");
        printf("\nOpção Invalida.\n"); // Exibe uma mensagem indicando que a opção digitada foi inválida.
        login_empresa(); // Chama a função `login_empresa` novamente para permitir uma nova tentativa.
        
    }
}
void login_cliente() {
    double cpf = 0; // Declara uma variável para armazenar o CPF digitado pelo usuário.
    printf("Digite o CPF ou digite 0 para sair:\n|>"); // Exibe uma mensagem para o usuário informar um CPF ou optar por sair.
    scanf("%lf", &cpf); // Lê o valor inteiro digitado pelo usuário e armazena na variável `cpf`.
    if (cpf != 0) { 
        // ERRO: Aqui há uma comparação errada. `cnpj` é do tipo `int` e está sendo comparado com uma string `"0"`.
        // A comparação correta seria: ``.

        for (int i = 0; i < 20; i++) { 
            // Inicia um loop para verificar o CNPJ informado em até 20 registros.
            if (cpf == clientes[i].cpf) { 
                // Verifica se o CNPJ informado coincide com o CNPJ de uma empresa no array `empresas`.
                // Caso o CNPJ seja encontrado, chama a função `cadastroDadosProdutos`.
                system("cls");
                printf("Cadastro encontrado.\n"); // Exibe uma mensagem indicando que a empresa foi encontrada.
                printf("Olá, %s",clientes[i].nome);
                vendas();
                return; // Interrompe o loop para evitar verificação de empresas restantes.
            } 
            else if (i == 19) { 
                // Verifica se chegou ao final da lista de empresas e o CNPJ não foi encontrado.
                printf("Cadastro não encontrado.\n"); 
                // Informa ao usuário que o cadastro não foi encontrado.
                login_cliente(); 
                // Chama a própria função `login_empresa` novamente, permitindo uma nova tentativa de login.
            }
        }
    } 
    else if (cpf == 0) { 
        // Caso o usuário tenha digitado 0, encerra o programa.
        system("cls");
        printf("\nPrograma encerrado.\n"); // Exibe uma mensagem indicando que o programa foi encerrado.
        return;
    } 
    else { 
        // Caso nenhuma das condições anteriores seja verdadeira, executa o bloco abaixo.
        system("cls");
        printf("\nOpção Invalida.\n"); // Exibe uma mensagem indicando que a opção digitada foi inválida.
        login_cliente(); // Chama a função `login_empresa` novamente para permitir uma nova tentativa.
        
    }

}
void cliente(){
    int op = 0;
    printf("\nPossue cadastro?\n");
    printf("1 - SIM\n2 - NAO\n|>");
    scanf("%d",&op);
    if(op == 1){
        login_cliente();
    }
    else if(op == 2){
        system("cls");
        cadastroDadosCliente();
        printf("Ir as compras ?\n1-SIM \n2-NAO \n|>");
        scanf("%d",&op);
        if (op == 1){
            system("cls");
            printf("Let's go!!!");
            vendas();
        }
        else if (op == 2){
            system("cls");
            return;
        }
        else{
        system("cls");
        printf("\nOpcao Invalida!\n");
        cliente();
        }
    }
    else{
        system("cls");
        cliente();
    }
}
void Empresa(){
    int op = 0;
    printf("\nPossue cadastro?\n");
    printf("1 - SIM\n2 - NAO\n|>");
    scanf("%d",&op);
    if(op == 1){
        login_empresa();
    }
    else if(op == 2){
        cadastroDadosEmpresa();
        printf("Cadastrar produtos?\n1-SIM \n2-NAO \n|>");
        scanf("%d",&op);
        if (op == 1){
            cadastroDadosProdutos();
        }
        else if (op == 2){
            system("cls");
            return;
        }
        else{
        system("cls");
        printf("\nOpcao Invalida!\n");
        return;
        }
    }
    else{
        system("cls");
        Empresa();
    }
}
void Financeiro(){
    printf("Financeiro\n");
    printf("1 - Relatorio de Vendas\n2 - Relatorio de Compras\n3 - Relatorio de ganhos\n|>");
    scanf("%d",&op);
    if(op == 1){
        system("cls");
        printf("\nVendas para usuarios:");
        printf("\nR$ %.2f\n",financeiro[1].entradas);
    }
    else if(op == 2){   
        system("cls");
        printf("\nCompras de estoque:");
        printf("\nR$ %.2f\n",financeiro[1].saidas);
    }
    else if(op == 3){
        system("cls");
        financeiro[1].ganhos = financeiro[1].entradas - financeiro[1].saidas;
        printf("\nGanhos:");
        if(financeiro[1].ganhos < 0){
            printf("\nR$ %.2f\n",financeiro[1].ganhos);
        }
        else{
            system("cls");
            printf("\nNao houve ganhos.\n");
        }
    }
    else{
        system("cls");
        printf("\nOpcao Invalida!\n");
        Financeiro();
    }
    system("pause");
    return;
}
void RelatorioProdutos(){
    printf("Relatorio de Vendas\n");
    printf("1 - Produtos que mais venderam\n2 - Produtos que menos venderam\n");
    scanf("%d",&op);
    if(op == 1){
        if (produtos_no_estoque > 0) { // Se houver produtos em estoque
            printf("Produtos que mais venderam\n");
            printf("ACIMA DE 2 VENDAS\n");
            // Implementar funcionalidades para produtos mais vendidos
            for( int i = 0; i < p; i++){
                if(estoque[0].camisa_estoque[i].vendidos >= 2){
                    printf("%s\n", estoque[0].camisa_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].camisa_estoque[i].vendidos);
                }
                if(estoque[0].shorte_estoque[i].vendidos >= 2){
                    printf("%s\n", estoque[0].shorte_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].shorte_estoque[i].vendidos);
                }
                if(estoque[0].acessorios_estoque[i].vendidos >= 2){
                    printf("%s\n", estoque[0].acessorios_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].acessorios_estoque[i].vendidos);
                }
                if(estoque[0].calca_estoque[i].vendidos >= 2){
                    printf("%s\n", estoque[0].calca_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].calca_estoque[i].vendidos);
                }
                if(estoque[0].calcados_estoque[i].vendidos >= 2){
                    printf("%s\n", estoque[0].calcados_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].calcados_estoque[i].vendidos);
                }
                if(estoque[0].meia_estoque[i].vendidos >= 2){
                    printf("%s\n", estoque[0].meia_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].meia_estoque[i].vendidos);
                }  
            }
        } 
        else {
            printf("Nao existem produtos em estoque.\n");
        }
    }
    else if(op == 2){
        if (produtos_no_estoque > 0) {
            printf("Produtos que menos venderam\n");
            for( int i = 0; i < p; i++){
                if(estoque[0].camisa_estoque[i].vendidos < 2){
                    printf("%s\n", estoque[0].camisa_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].camisa_estoque[i].vendidos);
                }
                if(estoque[0].shorte_estoque[i].vendidos < 2){
                    printf("%s\n", estoque[0].shorte_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].acessorios_estoque[i].vendidos);
                }
                if(estoque[0].acessorios_estoque[i].vendidos < 2){
                    printf("%s\n", estoque[0].acessorios_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].acessorios_estoque[i].vendidos);
                }
                if(estoque[0].calca_estoque[i].vendidos < 2){
                    printf("%s\n", estoque[0].calca_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].calca_estoque[i].vendidos);
                }
                if(estoque[0].calcados_estoque[i].vendidos < 2){
                    printf("%s\n", estoque[0].calcados_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].calcados_estoque[i].vendidos);
                }
                if(estoque[0].meia_estoque[i].vendidos < 2){
                    printf("%s\n", estoque[0].meia_estoque[i].tipo);
                    printf("Vendidos: %d\n", estoque[0].meia_estoque[i].vendidos);
                }
            }
        }
        else {
            printf("Nao existem produtos em estoque.\n");
        }
    }
    else{
        system("cls");
        printf("\nOpcao Invalida!\n");
        RelatorioProdutos();
    }
    system("pause");
    system("cls");
}
void Realatorio(){
    printf("Relatorio");
    printf("\n1 - Vendas\n2 - Financeiro\n0 - Sair\n|>");
    scanf("%d",&op);
    if(op == 1){
        system("cls");
        RelatorioProdutos();
    }
    else if(op == 2){
        system("cls");
        Financeiro();
    }
    else if(op == 0){
        system("cls");
        printf("\nPrograma encerrado.\n");
        return;
    }
    system("cls");
    Realatorio();
}
void Fucionario(){
    int codigo_acesso = 0;
    // Implementar funcionalidades para funcionarios
    printf("\nCodigo [123]\n");
    printf("CODIGO DE ACESSO ou 0 para sair:");
    scanf("%d",&codigo_acesso);
    if(codigo_acesso == 123){
        system("cls");
        printf("Ola, oque Deseja?");
        printf("\n1 - VER ESTOQUE DE PRODUTOS\n2 - RELATORIOS\n3 - VER CNPJS CADASTRADOS\n4 - VER CLIENTE CADASTADOS\n5 - SAIR\n|>");
        scanf("%d",&op);
        if(op == 1){
            system("cls");
            estoque_produtos();
        }
        else if(op == 2){
            system("cls");
            Realatorio();
        }
        else if(op == 3){
            system("cls");
            exibirDadosEmpresas();
        }
        else if(op == 4){
            system("cls");
            exibirDadosClientes();
        }
        else if(op == 5){
            system("cls");
            return;
        }
    }
    else if(codigo_acesso == 0){
        system("cls");
        printf("\nPrograma encerrado.\n");
        return;
    }
    else{
        system("cls");
        printf("\nCodigo de Acesso Invalido!\n");
        Fucionario();
    }
}
void MenuPrincipal(){
    int escolha_menu = 0;
    int op = 1;
    do {
        printf("\nO QUE VOCE E?\n1 - SOU UMA EMPRESA\n2 - SOU CLIENTE\n3 - SOU FUNCIONARIO\n4 - ENCERRAR\n|>");
        scanf("%d",&escolha_menu);
        switch (escolha_menu) {
            case 1:{
                Empresa();
                break;
            }
            case 2:{
                system("cls");
                cliente();
                break;
            }
            case 3:{
                system("cls");
                Fucionario();
                break;
            }
            default:
                system("cls");
                printf("NUMERO [%d] INVALIDO, DIGITE UM NUMERO LEGIVEL\n",escolha_menu);
                op = 1;
                break;
            case 4:{
                system("cls");
                op = 0;
                break;
            }
        }
    } while (op == 1);
    escolha_menu = 0;
    printf("Certeza que Deseja sair?\n1 - SIM\n2 - NAO\n|>"); // VOLTA AO MENU PRICIPAL 
    scanf("%d",&escolha_menu);
    if (escolha_menu != 1){
        system("cls");
        MenuPrincipal(); // VOLTA AO MENU PRICIPAL
    }
    else{
        printf("\nAté mais.\n");
    }
}
int main(){
    printf("Bem vindo a Elemental");
    MenuPrincipal(); 
    return 0;
}