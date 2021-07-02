#include<stdio.h>

#include<time.h>

#include<windows.h> // for gotoxy()

#include<stdlib.h>  // for system("cls")

#include<string.h>




void gotoxy(int x,int y){

    COORD coord;

    coord.X = x ;

    coord.Y = y ;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}




int main(){

    long long i ,spaces = 1 , letters = 0 , j , letterCount = 0 ;

    float accuracy = 0 , speed = 0 , letterToWord ;

    double time1 , time2 = 0 ;

    gotoxy( 30 , 5 ) ;

    printf( "LOADING........." ) ;

    gotoxy( 25 , 9 ) ;

    for( i=0 ; i < 22 ; i++ ){

        for(j=0; j<10000000; j++);

        printf("%c",177);
    }

    system( "cls" ) ;

    char c,a[10000]="This is a really short text , If you like it we'll give more text as well as more features. BEST OF LUCK :)";

    printf( "                    SPEED: 0          ACCURACY: 0        TOTAL ERROR= 0   \n\nYOUR TEXT:    \n\n" ) ;

    //gets(a);

    puts(a);

    letters = strlen( a ) ;

    for(  i = 0 ; i < letters ; i++ )

        if( a[i] == ' ' )

            spaces++ ;

    letterToWord = ( float )spaces / letters ;

    printf("\n-----------------------------------------------");

    printf("\n\nEnter Any Key To Start Typing.........");

    c=getch();

    gotoxy( 0 , 8 ) ;

    printf("ENTER THE ABOVE TEXT:                     \n\n");

    gotoxy(48,0);

    printf("100%c",'%');

    //gotoxy(0,8);

    time_t t,t1;

    t=clock();

    int k=0,gbg=0;

    gotoxy(0,4);

    while(a[k]!='\0'){

            t1=clock();

            c=getch();

            if(c!=a[k]){

                printf("\a");

                gbg++;

                accuracy=((float)100/letters)*(letters-gbg);

                if(accuracy<=0){

                    gotoxy(48,0);

                    printf("0.00%c    ",'%');
                }

                if(accuracy>0){

                    gotoxy(48,0);

                    printf("%0.2f%c ",accuracy,'%');
                }

                gotoxy(70,0);

                printf("%d",gbg);

                gotoxy(0,4);

                for(j=0; j<k; j++)

                    printf("%c",a[j]);
            }

            else{

                letterCount++;

                gotoxy(0,10);

                for(j=0; j<k; j++)

                    printf("%c",a[j]);

                printf("%c",c);

                k++;

            }

            t1=clock()-t1;

            time1=((double)t1/CLOCKS_PER_SEC);

            time2=time2+time1;

            gotoxy(27,0);

            printf("%0.2f WPM ",(float)(letterToWord*letterCount)/(time2/60));

            gotoxy(0,4);

            for(j=0; j<k; j++)

                printf("%c",a[j]);
    }

    t=clock()-t;

    double your_time=((double)t/CLOCKS_PER_SEC);

    your_time -= (your_time-time2);

    gotoxy(0,10);

    for(j=0; j<k; j++){

        printf("%c",a[j]);
    }

    printf("\n\n-----------------------------------------------\n\n");

    printf("YOUR RESULT");

    for(i=0; i<15; i++){

        for(j=0; j<10000000; j++);

        printf(".") ;
    }

    printf("\n\nYOUR SPEED: %0.2f WPM  \n\n** ( Length Of One Word Is Taken As %0.2f Letters )\n",(float)spaces/(your_time/60),(float)letters/spaces);

    printf("\nEnter Any Key to Exit......");

    getch();

    return 0;
}


