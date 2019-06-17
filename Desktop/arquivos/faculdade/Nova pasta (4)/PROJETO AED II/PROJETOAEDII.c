#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <graphics.h>
#include <time.h>


void constroiPainelEstacionamento();

    main()
    {



        int i;
        int r;
        char estadoVaga[20];

            initwindow (1376,680,"Controle do Estacionamento",0,0);
            readimagefile("vagas.jpg",0,0,1376,680);

            printf("Iniciando busca...por favor aguarde.\n");
            for(i=0;i<17;i++)
            {
                srand(clock());

                r = rand()%3;
                printf("\nBuscando vagas de estacionamento...\n\n");

                if(r==0){
                strcpy(estadoVaga, "*LIVRE*");//livre
                setfillstyle(1,10);
    bar(10,45,25,55);Sleep(200);
    bar(165,45,180,55);Sleep(200);
    bar(335,45,350,55);Sleep(200);
    bar(530,45,515,55);Sleep(200);
    bar(720,45,705,55);Sleep(200);
    bar(900,45,885,55);Sleep(200);
    bar(1165,45,1180,55);Sleep(200);
    bar(485,122,470,132);Sleep(200);
    bar(665,122,650,132);Sleep(200);
    bar(475,505,490,515);Sleep(200);
    bar(700,505,685,515);Sleep(200);
    bar(10,635,25,625);Sleep(200);
    bar(225,635,240,625);Sleep(200);
    bar(465,635,480,625);Sleep(200);
    bar(695,635,710,625);Sleep(200);
    bar(935,635,920,625);Sleep(200);
    bar(1150,635,1165,625);Sleep(200);
                }

                if(r==1){
                strcpy(estadoVaga, "*AGENDADO*");//agendado
                setfillstyle(1,11);

         bar(10,45,25,55);Sleep(200);
    bar(165,45,180,55);Sleep(200);
    bar(335,45,350,55);Sleep(200);
    bar(530,45,515,55);Sleep(200);
    bar(720,45,705,55);Sleep(200);
    bar(900,45,885,55);Sleep(200);
    bar(1165,45,1180,55);Sleep(200);
    bar(485,122,470,132);Sleep(200);
    bar(665,122,650,132);Sleep(200);
    bar(475,505,490,515);Sleep(200);
    bar(700,505,685,515);Sleep(200);
    bar(10,635,25,625);Sleep(200);
    bar(225,635,240,625);Sleep(200);
    bar(465,635,480,625);Sleep(200);
    bar(695,635,710,625);Sleep(200);
    bar(935,635,920,625);Sleep(200);
    bar(1150,635,1165,625);Sleep(200);
                }

                if(r==2){
                strcpy(estadoVaga, "*OCUPADO*");//ocupado
                 setfillstyle(1,12);
        bar(10,45,25,55);Sleep(200);
    bar(165,45,180,55);Sleep(200);
    bar(335,45,350,55);Sleep(200);
    bar(530,45,515,55);Sleep(200);
    bar(720,45,705,55);Sleep(200);
    bar(900,45,885,55);Sleep(200);
    bar(1165,45,1180,55);Sleep(200);
    bar(485,122,470,132);Sleep(200);
    bar(665,122,650,132);Sleep(200);
    bar(475,505,490,515);Sleep(200);
    bar(700,505,685,515);Sleep(200);
    bar(10,635,25,625);Sleep(200);
    bar(225,635,240,625);Sleep(200);
    bar(465,635,480,625);Sleep(200);
    bar(695,635,710,625);Sleep(200);
    bar(935,635,920,625);Sleep(200);
    bar(1150,635,1165,625);Sleep(200);

                }


                Sleep(200);
                constroiPainelEstacionamento();
                clearmouseclick(WM_LBUTTONDOWN);



                printf("Vaga %d: %s\n\n", i+1, estadoVaga);


            }

            printf("\nBusca encerrada\n");
                getchar();
                closegraph();




    }

    void constroiPainelEstacionamento()
{
       setbkcolor(10);
    setcolor(1);
    outtextxy(10,660,"*SMART* *PARKING*");
        setbkcolor(10);
    setcolor(1);
    outtextxy(210,660,"*SMART* *PARKING*");
        setbkcolor(10);
    setcolor(1);
    outtextxy(410,660,"*SMART* *PARKING*");
        setbkcolor(10);
    setcolor(1);
    outtextxy(610,660,"*SMART* *PARKING*");
       setbkcolor(10);
    setcolor(1);
    outtextxy(810,660,"*SMART* *PARKING*");
       setbkcolor(10);
    setcolor(1);
    outtextxy(1010,660,"*SMART* *PARKING*");
       setbkcolor(10);
    setcolor(1);
    outtextxy(1210,660,"*SMART* *PARKING*");
        setbkcolor(10);
    setcolor(1);
    outtextxy(1410,660,"*SMART* *PARKING*");


    setfillstyle(1,15);
    bar(10,45,25,55);Sleep(200);
    bar(165,45,180,55);Sleep(200);
    bar(335,45,350,55);Sleep(200);
    bar(530,45,515,55);Sleep(200);
    bar(720,45,705,55);Sleep(200);
    bar(900,45,885,55);Sleep(200);
    bar(1165,45,1180,55);Sleep(200);
    bar(485,122,470,132);Sleep(200);
    bar(665,122,650,132);Sleep(200);
    bar(475,505,490,515);Sleep(200);
    bar(700,505,685,515);Sleep(200);
    bar(10,635,25,625);Sleep(200);
    bar(225,635,240,625);Sleep(200);
    bar(465,635,480,625);Sleep(200);
    bar(695,635,710,625);Sleep(200);
    bar(935,635,920,625);Sleep(200);
    bar(1150,635,1165,625);Sleep(200);
}
