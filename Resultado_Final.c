#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NM_MAX_EST_DIS 10
#define MAX_ESTUD 15 
#define NM_PROF 3
#define NM_DISC 2


struct Professor
{
    char funcional[30], ministra_discipla[50];
    char nome_prof[30], titulacao[20];
};

struct Estudante
{
    char nome_estud[30], matricula[20], cursando_disciplina[50];
    int idade_estud;
}aux1,aux2;

struct Disciplina
{

    char nome_disc[50];
    int codigo_disc;
    int carga_hor;
    struct Professor professor_respon[3];
    struct Estudante estudante[MAX_ESTUD];
};


void le_valida_idade(int j, int k ,struct Disciplina *d){

    int retorno = -1;
    char letra;
    
    
    
        printf("Idade: ");
        scanf("%d", &d[j].estudante[k].idade_estud);
        
        

        while(d[j].estudante[k].idade_estud < 16 || d[j].estudante[k].idade_estud >26){
            
            do
            {
                printf("\tATENCAO!!\nDigite uma idade entre 16 e 26!\n");
                printf("Inclusive:\n");
                printf("Idade: ");
                // tem algum lixo de memoria no buffer?...? 
                retorno = scanf("%d\n", &d[j].estudante[k].idade_estud);
                
                if(retorno == 0){
                    printf("\nIsto nao eh um numero!\n");
                }

                do{
                    letra = getchar();
                }while(letra != '\n');

            }while(retorno == 0);
        }
        
    
}


int main()
{
    struct Disciplina V_estud[15];
    struct Disciplina disciplina[2];

    int /*cont2 = 0,*/ cont3 = 0, /*cont4 = 0,*/ cont_estud = 0,  nm_est_dis1 = 0, nm_est_dis2 = 0;
    int nm_prof_dis1 = 0, nm_prof_dis2 = 0;
    int opcoes_carga_hor = 0;
    int ret1, ret2, ret3, ret4;
    char consumir, opcao_estudante;


    for (int j = 0, i = 0; (j < NM_DISC) || (i < NM_PROF); j++, i++)
    {
        if( j == 2){ // proporcao NM_DISC:NM_PROF
            j--;
        }

        printf("----- Cadastro do %do Professor ----- \n\n", cont3 + 1);
        printf("Digite seu nome: ");
        fgets(disciplina[j].professor_respon[i].nome_prof, 30, stdin);

        printf("Digite sua titulacao: ");
        scanf("%[^\n]s", &disciplina[j].professor_respon[i].titulacao);
        scanf("%c", &consumir);
        printf("\n");

        printf("Digite sua funcional: ");
        scanf("%[^\n]s", &disciplina[j].professor_respon[i].funcional);
        scanf("%c", &consumir);
        printf("\n");

        do
        {

            do
            {
                printf("Selecione uma disciplina a ser ministrada:\n");
                printf("(1) PROGRAMACAO ESTRUTURADA\n");
                printf("(2) NUVEM COMPUTACIONAL\n");

                scanf("%d", &disciplina[j].codigo_disc);


                /* VALIDACAO PARA A EXIGENCIA DE 2 DISCIPLINAS DIFERENTES*/
                if( (disciplina[j].codigo_disc == 1 && nm_prof_dis1>=2) || (disciplina[j].codigo_disc == 2 && nm_prof_dis2>=2) )
                {
                    printf("\tATENCAO!!\nNumero limite de professores atingido nessa disciplina!\n");
                    printf("Inclusive:\n\n");
                }



            } while( (disciplina[j].codigo_disc == 1 && nm_prof_dis1>=2) || (disciplina[j].codigo_disc == 2 && nm_prof_dis2>=2));
            



            /* ------------ VALIDACAO DAS DISCIPLINAS ----------------- */
            switch (disciplina[j].codigo_disc)
            {
            case 1:
                strcpy(disciplina[j].professor_respon[i].ministra_discipla, "PROGRAMACAO ESTRUTURADA"); 
                strcpy(disciplina[0].nome_disc, "PROGRAMACAO ESTRUTURADA");
                
                nm_prof_dis1++;
                break;

            case 2:
                strcpy(disciplina[j].professor_respon[i].ministra_discipla, "NUVEM COMPUTACIONAL");
                strcpy(disciplina[1].nome_disc, "NUVEM COMPUTACIONAL");
                
                nm_prof_dis2++;
                break;

            default:
                printf("\tATENCAO!!\nSelecione uma opcao valida.\n\n");
                break;
            }

        } while (disciplina[j].codigo_disc != 1 && disciplina[j].codigo_disc != 2);
        scanf("%c", &consumir);

        do
        {
            printf("Selecione a carga horaria:\n");
            printf("(1) 80h\n");
            printf("(2) 90h\n");
            printf("(3) 120h\n");

            scanf("%d", &opcoes_carga_hor); // deveria ser tipo char para ocorrer a  validacao de letras 


            /*------VALIDACAO DE CARGA HORARIA-------*/
            switch (opcoes_carga_hor) 
            {
            case 1:
                disciplina[j].carga_hor = 80;
                break;

            case 2:
                disciplina[j].carga_hor = 90;
                break;

            case 3:
                disciplina[j].carga_hor = 120;
                break;

            default:
                printf("\tATENCAO!!\nSelecione uma opcao valida.\n\n");
                break;
            }

        } while (opcoes_carga_hor != 1 && opcoes_carga_hor != 2 && opcoes_carga_hor != 3);
        scanf("%c", &consumir);

        cont3++;
    } // final do for de cadastro de professores

    

    
    int k=0;
    while (k < MAX_ESTUD) // maximo de ate 15 estudantes
    {
        int j;
        for ( j = 0, k = 0; (j < NM_DISC) || (k < MAX_ESTUD); j++, k++)
        {

            if( j == 2){ // proporcao NM_DISC:MAX_ESTUD
                j--;
            }

            printf("----- Cadastro do %do Estudante ----- \n\n", cont_estud + 1);
            printf("Matricula: ");                                      // nao possui dados armazenados em disciplina[0].estudante[1] e disciplina[1].estudante[0]
            scanf(" %[^\n]s\n", &disciplina[j].estudante[k].matricula); // disciplina[0].estudante[0] ... disciplina[1].estudante[1] ... disciplina[1].estudante[2]
            printf("Nome do estudante: ");
            scanf(" %[^\n]s\n", &disciplina[j].estudante[k].nome_estud);

            le_valida_idade(j, k, disciplina);



            /*----------------- VALIDACAO - CADA DISCIPLINA PODE TER NO MAX 10 ESTUDANTES*/

            do
            {
            
                do
                {

                    printf("Selecione uma disciplina a ser cursada:\n");
                    printf("(1) PROGRAMACAO ESTRUTURADA\n");
                    printf("(2) NUVEM COMPUTACIONAL\n");


                    scanf("%d", &V_estud[k].codigo_disc);

                    /*VALIDACAO PARA O NUMERO MAXIMO DE ESTUDANTES POR DISCIPLINA*/
                    if((V_estud[k].codigo_disc == 1 && nm_est_dis1>=NM_MAX_EST_DIS) || (V_estud[k].codigo_disc == 2 && nm_est_dis2>=NM_MAX_EST_DIS)){
                        printf("\tATENCAO!!\nNumero limite de estudantes atingido nessa disciplina!\n");
                        printf("Inclusive:\n\n");
                    }


                } while( (V_estud[k].codigo_disc == 1 && nm_est_dis1>=NM_MAX_EST_DIS) || (V_estud[k].codigo_disc == 2 && nm_est_dis2>=NM_MAX_EST_DIS));


                /*------------------ CADA ESTUDANTE IRA CURSAR UMA UNICA DISCIPLINA ----------------*/
                switch (V_estud[k].codigo_disc)
                {
                case 1:
                    strcpy(disciplina[j].estudante[k].cursando_disciplina, "PROGRAMACAO ESTRUTURADA");
                    nm_est_dis1++;
                    break;
                
                case 2:
                    strcpy(disciplina[j].estudante[k].cursando_disciplina, "NUVEM COMPUTACIONAL");
                    nm_est_dis2++;
                    break;
                    
                default:
                    printf("\tATENCAO!!\nSelecione uma opcao valida.\n\n");
                    break;
                }

            }while(V_estud[k].codigo_disc != 1 && V_estud[k].codigo_disc != 2);
            scanf("%c", &consumir);

            


        
            
            
           

            printf("\nDeseja cadastrar outro estudante(S/N): ");
            scanf(" %c", &opcao_estudante);

           
            
            //---------- Validacao para o numero de estudante registrados ----
            if (opcao_estudante != 's' && opcao_estudante != 'S')
            {
                k = MAX_ESTUD; // com k e j assim, finaliza o looping for  
                j = NM_DISC;
            }

            
            cont_estud++; // numero de estudantes cadastrados em um maximo de 15
            

            

        } // final do for de cadastro dos estudantes    
        
        k++;
    } // final do while(i < MAX_ESTUD){...}



    /* ----------------- Ordenação crescente dos alunos segundo a idade -----------------------------------------------*/     
        for (int a =  (cont_estud) - 1; a > 0; a--) {
            for (int b = 0; b < a; b++) 
            {
                if (disciplina[0].estudante[0].idade_estud > disciplina[1].estudante[b + 1].idade_estud) 
                {
                    aux1 = disciplina[0].estudante[0];
                    disciplina[0].estudante[0] = disciplina[1].estudante[b + 1];
                    disciplina[1].estudante[b + 1] = aux1;
                }
            }      
        }

        
        for (int a =  (cont_estud) - 1; a > 0; a--) {
                for (int b = 1; b < a; b++) 
                {
                    if (disciplina[1].estudante[b].idade_estud > disciplina[1].estudante[b + 1].idade_estud) 
                    {

                        aux2 = disciplina[1].estudante[b];
                        disciplina[1].estudante[b] = disciplina[1].estudante[b + 1];
                        disciplina[1].estudante[b + 1] = aux2;
                    }
                }
        }
           
    /*-------------------------------------------------------------------------------------------------------*/



    printf("+-------------- RELATORIO DA 1 DISCIPLINA - %s ---------------+\n\n",disciplina[0].nome_disc);
    for ( int j = 0, i = 0; (j < NM_DISC) || (i < NM_PROF); j++, i++){
        if( j == 2){
            j--;
        }

        ret1 = strcmp(disciplina[j].professor_respon[i].ministra_discipla, disciplina[0].nome_disc);//estou comparando strings // equivalente a (disciplina[j].professor_respon[i].ministra_discipla) == (disciplina[0].nome_disc)

        if( ret1 == 0 ){ // se as strings comparadas forem iguais o ret1 tera valo 0, se ret1<0 a primeira string comparada serah a menor, se ret1>0 a segunda string comparada serah a menor
            printf("Codigo da disciplina: %d\tProfessor Responsavel: %s", disciplina[0].codigo_disc, disciplina[j].professor_respon[i].nome_prof);

        }
    }
   
   int w;
    for ( w = 0, k = 0; (w < NM_DISC) || (k < cont_estud); w++, k++){
        if( w == 2){
            w--;
        }

        ret2 = strcmp(disciplina[w].estudante[k].cursando_disciplina, disciplina[0].nome_disc);

        if( ret2 == 0 )
        {
            printf("\nEstudante: %s\tIdade: %d\n",disciplina[w].estudante[k].nome_estud, disciplina[w].estudante[k].idade_estud);
        }
    }


    /* ----------------- Ordenação decrescente dos alunos segundo a idade -----------------------------------------------*/     
        for (int a =  (cont_estud) - 1; a > 0; a--) {
            for (int b = 0; b < a; b++) 
            {
                if (disciplina[0].estudante[0].idade_estud < disciplina[1].estudante[b + 1].idade_estud) 
                {
                    aux1 = disciplina[0].estudante[0];
                    disciplina[0].estudante[0] = disciplina[1].estudante[b + 1];
                    disciplina[1].estudante[b + 1] = aux1;
                }
            }      
        }

        
        for (int a =  (cont_estud) - 1; a > 0; a--) {
                for (int b = 1; b < a; b++) 
                {
                    if (disciplina[1].estudante[b].idade_estud < disciplina[1].estudante[b + 1].idade_estud) 
                    {

                        aux2 = disciplina[1].estudante[b];
                        disciplina[1].estudante[b] = disciplina[1].estudante[b + 1];
                        disciplina[1].estudante[b + 1] = aux2;
                    }
                }
        }
           
    /*-------------------------------------------------------------------------------------------------------*/







    /*-------------------------------------------------------------------------------------------------------*/

    printf("+-------------- RELATORIO DA 2 DISCIPLINA - %s ---------------+\n\n",disciplina[1].nome_disc);
    for ( int j = 0, i = 0; (j < NM_DISC) || (i < NM_PROF); j++, i++){
        if( j == 2){
            j--;
        }

        ret3 = strcmp(disciplina[j].professor_respon[i].ministra_discipla, disciplina[1].nome_disc);

        if( ret3 == 0 ){ // se as strings comparadas forem iguais o ret1 tera valo 0, se ret1<0 a primeira string comparada serah a menor, se ret1>0 a segunda string comparada serah a menor
            printf("Codigo da disciplina: %d\tProfessor Responsavel: %s", disciplina[1].codigo_disc, disciplina[j].professor_respon[i].nome_prof);
        }

    }



    for ( w = 0, k = 0; (w < NM_DISC) || (k < cont_estud); w++, k++){
        if( w == 2){
            w--;
        }

        ret4 = strcmp(disciplina[w].estudante[k].cursando_disciplina, disciplina[1].nome_disc);

        if( ret4 == 0 )
        {
            printf("\nEstudante: %s\tIdade: %d\n\n",disciplina[w].estudante[k].nome_estud, disciplina[w].estudante[k].idade_estud);
        }

    }
    return 0;
}
