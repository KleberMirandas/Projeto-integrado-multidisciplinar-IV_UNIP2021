#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}rgData;

rgData entrada(char msg[]){
    rgData dt;

    printf("%s Exemplo(dd/mm/aaaa): ",msg);
    scanf ("%d/%d/%d", &dt.dia,&dt.mes, &dt.ano);

    return(dt);

}

int main (int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    system("color 0A");
    printf("\n\t\t\t\t\t ***** AVISO!! ***** \n\n ");
    printf("\n\t\t\tTodas informações digitadas NÃO devem conter ACENTUAÇÕES!!! \n ");
    printf("\t\t\tem caso de duvida, favor consultar o manual do usuario. \n\n\n\n");
    system("pause");
    system("cls");
    menu_inicial();


    system("pause");
    return 0;
}

void login()
    {
        int  senha = 1234;
        int digSenha;
        char login[10] = "admin";
        char digLogin[10];

        system("cls");
        printf("\n\t\t\t\t**************  LOGIN  *********************** \n\n\n");
        printf("\t\t\t\tLOGIN: ");
        scanf("%s", &digLogin);

        printf("\n\t\t\t\tSENHA: ");
        scanf("%i", &digSenha);

        while (strcmp(digLogin,login) || digSenha != senha)
               {
                    system("cls");
                    system("color 0C");
                    printf("\n\t\t\t\t**************  LOGIN  *********************** \n");
                    printf("\nLogin ou Senha ERRADA!Tente novamente \n");
                    system("pause");
                    system("cls");
                    system("color 0A");
                    printf("\n\t\t\t\t**************  LOGIN  *********************** \n\n");
                    printf("\t\t\t\tLOGIN: ");
                    scanf("%s", &digLogin);

                    system("cls");
                    printf("\n\t\t\t\t**************  LOGIN  *********************** \n\n");
                    printf("\t\t\t\tSENHA: ");
                    scanf("%i", &digSenha);
               }

        menu_principal();

    }

void cadastro()
    {
        novoPaciente();
        menu_principal();

    }
    void novoPaciente()//cadastra novo paciente fazendp um novo arquivo
        {
            system("cls");
            printf("\n\t\t\t\t NOVO CADASTRO PACIENTE \n\n\n");
            char filename[100], nome[15]="", sNome[15]="", cpf[30], fone[11], email[50];
//-------------------------------------------------------------
            char rua[100], numero[10], comp[100], bairro[100], cidade[100],estado[2],pais[50], cep[8];

//---------------------------------------------------------------
            char comor[100];
            int  comorbool;
            rgData nasc,hoje;

            printf("\t\t\t ****PREENCHER A FICHA**** \n\n\n");
            printf("\n\tDigite a data de hoje\n");
            hoje = entrada("       ");
            printf("\n\tPrimeiro nome *EM MINÚSCULO*: ");
            scanf("%s",nome);
            printf("\n\tSobrenome *EM MINÚSCULO*: ");
            scanf("%s",sNome);
            printf("\n\tData de Nascimento:\n\t");
            nasc = entrada("Nascimento");
            int idade = hoje.ano - nasc.ano;
            printf("\n\tTelefone com DDD *SOMENTE NÚMEROS*: ");
            scanf("%s",fone);
            printf("\n\tEmail: ");
            scanf("%s",email);
            FILE *file;
            sprintf(filename,"%s_%s.txt",nome,sNome);
            file = fopen(filename,"w");
            fprintf(file,"\n Data do Diagnóstico: %d/%d/%d \n\t\t\t",hoje.dia,hoje.mes,hoje.ano);
            fprintf(file,"\n Nome: %s ",nome);
            fprintf(file,"%s \n",sNome);
            fprintf(file," Idade: %i anos \n",idade);
            fprintf(file," Telefone: +55 %s \n",fone);
            fprintf(file," Email: %s \n",email);
            printf("\n\tCPF: ");
            scanf("%s",cpf);
            fprintf(file," CPF: %s \n \n",cpf);
            fprintf(file,"");
            system("cls");
            printf("\n\t\t\t****Endereço**** \n\n");
            printf(" \n\tRua: ");
            fflush(stdin);
            fgets(rua,100,stdin);
            fflush(stdin);
            fprintf(file," Rua: %s",rua);
            printf("\n\tNúmero: ");
            scanf("%s",numero);
            fprintf(file," Número: %s",numero);
            printf("\n\tComplemento (CASO NÃO TENHA DIGITE 0): ");
            fflush(stdin);
            fgets(comp,100,stdin);
            fflush(stdin);
            fprintf(file," complemento: %s",comp);
            printf(" \n\tBairro: ");
            fflush(stdin);
            fgets(bairro,100,stdin);
            fflush(stdin);
            fprintf(file," Bairro: %s",bairro);
            printf("\n\tCidade: ");
            fflush(stdin);
            fgets(cidade,100,stdin);
            fflush(stdin);
            fprintf(file," Cidade: %s",cidade);
            printf("\n\tEstado: ");
            fflush(stdin);
            fgets(estado,50,stdin);
            fflush(stdin);
            fprintf(file," Estado: %s",estado);
            printf("\n\tPaís: ");
            fflush(stdin);
            fgets(pais,100,stdin);
            fflush(stdin);
            fprintf(file," País: %s",pais);
            printf("\n\tCEP: ");
            fflush(stdin);
            fgets(cep,100,stdin);
            fflush(stdin);
            fprintf(file," CEP: %s",cep);
            do{
            system("cls");
            printf("\n\tO paciente possui algum tipo de comorbidade?\n\t\t[1]SIM\t[2]NÃO \n");
            scanf("%i", &comorbool);
            }while(comorbool<=0 || comorbool>2);

            if(comorbool==1){
                printf("\n\tQual comorbidade o paciente possui: ");
                fflush(stdin);
                fgets(comor,100,stdin);
                fflush(stdin);
                fprintf(file," Comorbidades: %s",comor);
                fclose(file);
            }
            if(comorbool==2){
                system("cls");
                printf("\tCadastro realizado com sucesso!");
                system("pause");
            }

            if(comorbool==1 || idade>=65)
              {
                  FILE *file;
                  sprintf(filename,"RISCO_%s_%s.txt",nome,sNome);
                  file = fopen(filename,"w");
                  fprintf(file,"\n Nome: %s ",nome);
                  fprintf(file,"%s \n",sNome);
                  fprintf(file," Idade: %i anos \n",idade);
                  fprintf(file," CEP: %s",cep);
                  fprintf(file," Comorbidades: %s",comor);
                  fclose(file);

              }
           system("cls");
           printf("\n Cadastro realizado com sucesso \n ");

        }

    void menu_principal()
        {
         system("cls");
         char op = NULL;
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t**************  SISTEMA UNIP SAÚDE  ***********************");
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t***********************************************************\n");
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t***********   1- Consultar Paciente   *********************");
    printf("\n\t\t\t\t***********   2- Cadastrar Paciente   *********************");
    printf("\n\t\t\t\t***********   3- Encerrar Sessão      *********************");
    printf("\n\t\t\t\t***********   4- Sair                 *********************");
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t***********************************************************\n");

    printf("\n\n\t\t\t\t\t DIGITE A OPÇÃO  DESEJADA: ");
    scanf("%s",&op);
    switch(op)
        {
            case '1':
                op = NULL;
                consultar();
                break;
            case '2':
                op = NULL;
                cadastro();
                break;

            case '3':
                op = NULL;
                login();
                break;

            case '4':
                op = NULL;
                sair();
                break;

            default:
                op = NULL;
                system("color 0C");
                printf("\n\t\t\t\t\t\t Opção Errada! Tente novamente\n\n\n");
                system("pause");
                system ("color 0A");
                system("cls");

                 menu_principal();
                break;
        }

        }

        void consultar()
                {

                        system("cls");
                        char nome[100];
                        char sNome[100];
                        char filename[100];

                          printf("\n\t\t\t ******************************************************");
                          printf("\n\t\t\t *********  CONSULTA CADASTRO PACIENTE  ***************");
                          printf("\n\t\t\t ****************************************************** \n");

                          printf("\n\n\n\t\t\t ATENÇÃO! Escreva tudo em minúsculo \n\n");

                          printf("\n\t\t\t Primeiro nome do paciente: ");
                          scanf("%s",nome);
                          printf("\n\t\t\t Sobrenome do paciente: ");
                          scanf("%s",sNome);

                          FILE *file;
                          sprintf(filename,"%s_%s.txt",nome,sNome);
                          file = fopen(filename,"r");
                          if(file == NULL)
                            {
                             system("cls");
                             system("color 0C");
                             printf("\n ERRO! Paciente não encontrado! \n ");
                             printf("\n Verifique o nome e sobrenome do paciente e tente novamente! \n");
                             system("pause");
                             system ("color 0A");
                             consultar();

                            }
                          char frase[100];
                          system("cls");
                          printf("\n\t\t\t ******************************************************");
                          printf("\n\t\t\t *********  CONSULTA CADASTRO PACIENTE  ***************");
                          printf("\n\t\t\t ****************************************************** \n\n");

                          while(fgets(frase,100,file) != NULL)
                               {
                                    printf("%s",frase);

                              }

                          fclose(file);
                          printf("\n\t\t\t Aperte a tecla ENTER para voltar ao menu. \n\n\n");
                          system("pause");
                          menu_principal();

                }

void menu_inicial()
{
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t**************  SISTEMA UNIP SAÚDE  ***********************");
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t***********************************************************\n");
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t****************   1- Login     ***************************");
    printf("\n\t\t\t\t****************   2- Sair      ***************************");
    printf("\n\t\t\t\t***********************************************************");
    printf("\n\t\t\t\t***********************************************************\n");
    char op = NULL;
    printf("\n\n\t\t\t\t\t DIGITE A OPÇÃO  DESEJADA: ");
    scanf("%s",&op);

    if(op == '1')
        {
          login();
        }else if(op == '2')
             {
               sair();
             }else
                 {
                    op = NULL;
                    system("color 0C");
                    printf("\n\t\t\t\t\t\t Opção Errada! Tente novamente\n\n\n");
                    system("pause");
                    system ("color 0A");
                    system("cls");
                    menu_inicial();
                 }




}
void sair()
    {
        system("exit");
    }

