#include <stdio.h>
#include <stdlib.h>

//Aluno Marco Aurelio Souza Barreto - 201001064

/*Variaveis:
notasN = Quantidade de nota gasto para operacao
qnotas = Quantidade de notas disponiveis
ressarcir = Variavel para colocar de volta os valores do Qnotas caso nao seja possivel completar o saque
saquerealizado = o saque realizado kkkkkk
saquemaximo = O valor maximo possivel para ser sacado, contando a quantidade de cedulas
*/
void op1(int *qnotas)
{
    int notas100=0, notas50=0, notas20=0, notas10=0, notas5=0, notas2=0, saque=0, saquerealizado=0, saquemaximo=0, reassercir=0;
    int qcedulas[6]={0,0,0,0,0,0};
    saquemaximo=qnotas[0]*100+qnotas[1]*50+qnotas[2]*20+qnotas[3]*10+qnotas[4]*5+qnotas[5]*2;
    printf("Saque maximo = %i\n", saquemaximo);
    printf("Digite o numero a ser sacado\n\n");
    scanf("%i", &saque);
    system("cls");
    saquerealizado=saque;
    if(saque>0)
    {
        while((saque%5!=0)&&(saque>=2)&&(qnotas[5]>=1))
        {
            saque=saque-2;
            ++notas2;
            qnotas[5]-=1;
            qcedulas[5]+=1;
        }
        while((saque>=100)&&(qnotas[0]>=1))
        {
            saque=saque-100;
            ++notas100;
            qnotas[0]-=1;
            qcedulas[0]+=1;
        }
        while((saque>=50)&&(qnotas[1]>=1))
        {
            saque=saque-50;
            ++notas50;
            qnotas[1]-=1;
            qcedulas[1]+=1;
        }
        while((saque>=20)&&(qnotas[2]>=1))
        {
            saque=saque-20;
            ++notas20;
            qnotas[2]-=1;
            qcedulas[2]+=1;
        }
        while((saque>=10)&&(qnotas[3]>=1))
        {
            saque=saque-10;
            ++notas10;
            qnotas[3]-=1;
            qcedulas[3]+=1;
        }
        while((saque>=5)&&(qnotas[4]>=1))
        {
            saque=saque-5;
            ++notas5;
            qnotas[4]-=1;
            qcedulas[4]+=1;
        }
        while((saque>=2)&&(qnotas[5]>=1))
        {
            saque=saque-2;
            ++notas2;
            qnotas[5]-=1;
            qcedulas[5]+=1;
        }

        if(saque>0)
        {
            printf("Nao foi possivel realizar o saque, saque cancelado, faltaram %i reais\n\nDinheiro ressarcido\n\n", saque);
            for (; reassercir<6; reassercir++){
                qnotas[reassercir]=qnotas[reassercir]+qcedulas[reassercir];
            }
            system("pause");
            system("cls");
        }
        else
        {
            printf("Saque efetivado = %i reais, contendo as seguintes cedulas\n\n", saquerealizado);
            if (notas100>0) printf("Quantidade de cedulas de 100 reais = %i\n", notas100);
            if (notas50>0) printf("Quantidade de cedulas de 50 reais = %i\n", notas50);
            if (notas20>0) printf("Quantidade de cedulas de 20 reais = %i\n", notas20);
            if (notas10>0) printf("Quantidade de cedulas de 10 reais = %i\n", notas10);
            if (notas5>0) printf("Quantidade de cedulas de 5 reais = %i\n", notas5);
            if (notas2>0) printf("Quantidade de cedulas de 2 reais = %i\n\n", notas2);

            system("pause");
            system("cls");
        }
    }
    else if (saque==0)
    {
        printf("Nenhum valor foi digitado\n");
    }
    else
    {
        printf("Nao e possivel sacar valores negativos\n");
        system("pause");
        system("cls");
    }

return;
}

int main()
{
    /*
    Recargap = Recarga personalizada
    qnotas = quantidade de notas
    oprecarga = opcao de recarga
    Variavel para recarga personalizada do for
    */
    int sair=0,op=0, recarga=0;
    int oprecarga;
    int recargap [6]={0, 0, 0, 0, 0, 0};
    int qnotas [6]={20, 20, 20, 20, 20, 20};

    while(sair!=1)
    {
        printf("-----------------------------------------------------------------------\n");
        printf("\t\t\tCAIXA ELETRONICO\n");
        printf("-----------------------------------------------------------------------\n\n");
        printf("notas de 100 disponiveis:%i\n", qnotas[0]);
        printf("notas de 50 disponiveis:%i\n", qnotas[1]);
        printf("notas de 20 disponiveis:%i\n", qnotas[2]);
        printf("notas de 10 disponiveis:%i\n", qnotas[3]);
        printf("notas de 5 disponiveis:%i\n", qnotas[4]);
        printf("notas de 2 disponiveis:%i\n\n", qnotas[5]);
        printf("Digite 1 para sacar, 2 para recarregar as cedulas e 0 para sair\n\n");
        scanf("%i", &op);
        system("cls");
        switch (op)
        {
        case 1:
            op1(qnotas);
            continue;
        case 0:
            printf("Saindo\n");
            sair=1;
            break;
        case 2:
            printf("Digite 1 para recarga padrao, 2 para recargas personalizadas, e 0 para sair\n\n");
            scanf("%i", &oprecarga);
            if (oprecarga==1)
            {
                oprecarga=0;
                for (; oprecarga<6; oprecarga++){
                    qnotas[oprecarga]=20;
                }
                printf("\nRecarregado\n");
                system("pause");
                system("cls");
            }
            else if (oprecarga==2)
            {
                system("cls");
                printf("------------------------------------------------\n");
                printf("RECARGA PERSONALIZADA\n");
                printf("------------------------------------------------\n\n");
                printf("Digite a quantidade disponivel de cada nota:\n");
                printf("Quantidade de notas de 100 reais\n");
                scanf("%i", &recargap[0]);
                printf("quantidade de notas de 50 reais\n");
                scanf("%i", &recargap[1]);
                printf("quantidade de notas de 20 reais\n");
                scanf("%i", &recargap[2]);
                printf("quantidade de notas de 10 reais\n");
                scanf("%i", &recargap[3]);
                printf("quantidade de notas de 5 reais\n");
                scanf("%i", &recargap[4]);
                printf("quantidade de notas de 2 reais\n");
                scanf("%i", &recargap[5]);

                if ((recargap[5]>=0)&&(recargap[4]>=0)&&(recargap[3]>=0)&&(recargap[2]>=0)&&(recargap[1]>=0)&&(recargap[0]>=0))
                {
                    for (;recarga<6; recarga++)
                    {
                        qnotas[recarga]=recargap[recarga];
                    }
                    printf("Recarga efetuada\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("\nDigite apenas valores positivos, recarga cancelada\n");
                    system("pause");
                    system("cls");
                }
            }
            else if (oprecarga==0)
            {
                system("cls");
                continue;
            }
            else
            {
                printf("Digite uma opcao valida\n");
                system("pause");
                system("cls");
            }
            continue;
        default:
            printf("Opcao nao disponivel\n");
            system("pause");
            system("cls");
            continue;

        }




    }
    return 0;
}
