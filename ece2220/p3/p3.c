/* 
Gabe Volheim
Bgvolhe
ECE 2220
Project 3
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int flag,indexQ,i,indexO,indexH,finalIndex,k;
    indexQ=0;
    indexO=0;
    indexH=0;
    char number[34],qua[33],oct[33],hex[33]; //Initialized to 34 to save space for both the newline char and also the letter for the base
    unsigned char hexInc;
do{
    //Getting user input
    do{
    flag = 0;
    printf("Please input a number in either Quaternary (Denoted with an Q), octal (Denoted with a O), or hexadecimal (Denoted with an H) or quit to quit.\n");
    fgets(number,34,stdin);

        if(strcmp(number,"quit") == 0 ) break;

        if(number[strlen(number)-1] != '\n') //Makes sure terminating char is \n
        {
            printf("Error, number is too long. Please input a number that is of max 32 digits.\n");
            flag = 1;
        }
        if ((number[0] != 'O') && (number[0] != 'H') && (number[0] != 'Q'))
        {
            flag = 1;
            printf("Error, invalid notation detected. Please note that the denotions must be at the beginning.\n");
        }
        if (number[1] == '\n')
        {
            printf("Error, no number detected. Please make sure to include a number after the initial notation\n");
            flag = 1;
        }

    fflush(stdin);

    }while(flag == 1);

    if((strcmp(number,"quit") == 0)) break;

    //Case for octal
    if(number[0] == 'O')
    {
        //Normalizing the string into binary
        int k = strlen(number);
        for (i=1; i<(k-1); i++)
        {
            if((number[i] >= '0') && (number[i] <= '9')) number[i] -= 0x30;
        }

        i=(k-2);
        int n=i-1;
        do{
            
            hex[n]=((number[i] & 0x7) + ((number[i-1] & 0x1) << 3)); //Setting first hex value equal to first 4 bits
            if(i-1 == 0){      
            hex[n] = (number[i] & 0x7); //Checks to make sure that i-1 is not the last value for oct
            break;
            }
            hex[n-1]=(((number[i-1] & 0x6) >> 1) + ((number[i-2] & 0x3) << 2)); //Setting the second hex value equal to the middle 4 bits
            if (i-2 == 0)
            {
                hex[n-1] = ((number[i-1] & 0x6) >> 1);
                break;
            } 

            hex[n-2]=((number[i-2] & 0x4) >> 2) + (number[i-3] << 1); //Setting the last 4 bits to a hex value
            if(i-3 == 0)
            {
                hex[n-2]= (number[i-2] & 0x4 >> 2);
                break;
            }
            i=i-4;
            n=n-3;
        }while(i>0);

        i=(k-2);
        i--;
        indexQ=0;

        //Conversion from hex to qua
        do{
       hexInc=0x3;
            for(int j=0;j<3;j=j+2){
                qua[indexQ] = ((hex[i] & hexInc) >> j);
                hexInc += 0x9;
                ++indexQ;
            }
        i--;
        }while(i>-1);
        //For statement that removes and preceeding zeros.
        for(i=1;i < (k-2);i++)
        { 
            if((hex[i] > 0) && (hex[i] <= 9) ) break;
            if((hex[i] >= 10) && (hex[i] <= 15)) break;
        }

        //Printing out hex
        printf("The value for hexadecimal is H");
        for(i=i;i < (k-2) ;i++)
        {
         if  ((hex[i] >= 0) && (hex[i] <= 9)) printf("%c", hex[i] += 0x30);
         if ((hex[i] >= 10) && (hex[i] <= 15)) printf("%c",hex[i] += 55);
        }

        printf("\n");

        //Printing out qua
        printf("and the value for quanternary is Q");
        for(i=(indexQ-3);i>-1;i--){
            if((qua[i] > 0) && (qua[i] <= 3) ) break;
        }

        for(i=i;i>-1;i--) {
            printf("%d",qua[i]);
        }
        }

        //Case for Qua
        else if (number[0] == 'Q'){

        k = strlen(number);

        //Normalizing the given value
        for (i=1; i<(k-1); i++)
        {
            if((number[i] >= '0') && (number[i] <= '9')) number[i] -= 0x30;
        }
        //Converting from qua to hex
        int l = k-2;
            indexH=0; // index for Hex
            for(indexH=indexH;indexH < ((k-2)/2);indexH++)
            {
                hex[indexH] = number[l] + (number[l-1] << 2);
                l = (l-2);
            }

        i = indexH;

        indexO= i + (i/3); 

        //Converting from hex to octal
         do{
            oct[indexO]=(hex[i-indexH] & 0x7);
            oct[indexO-1]=(((hex[i-indexH] & 0x8) >> 3) + ((hex[i-indexH+1] & 0x3) << 1));
            oct[indexO-2]=(((hex[i-indexH+1] & 0xC) >> 2) + ((hex[i-indexH+2] & 0x1) << 2));
            oct[indexO-3]=((hex[i-indexH+2] & 0xE) >> 1);
            finalIndex=indexO-3;
        i= i - 3;
        indexO = indexO - 4;
        }while(i>0);

    //Printing out octal 
    while(finalIndex < 0) finalIndex++;
    printf("The value for octal is O");
    for(i=finalIndex;i < ((indexH + (indexH/3))+1);i++) printf("%d",oct[i]);

        printf("\n");
    // Printing out hex
        printf("The hex value is H");
        for(i=indexH-1;i >= 0;i--){
         if  ((hex[i] >= 0) && (hex[i] <= 9)) printf("%c", hex[i] += 0x30);
         if ((hex[i] >= 10) && (hex[i] <= 15)) printf("%c",hex[i] += 55);
        }
        printf("\n");
        }

        else if(number[0] == 'H')
        {
        //Normalizing number string
        indexQ=0,indexO=0;
        k=strlen(number)-1;
        for (i=1; i<k; i++)
        { 
            if ((number[i] >= 'A') && (number[i] <= 'F')) number[i] -= 55;
            else if ((number[i] >= 'a') && (number[i] <= 'f')) number[i] -= 87;
            else if ((number[i] >= '0') && (number[i] <= '9')) number[i] -= 0x30;
        }
        i--;

        //Converting from qua to hex
        do{
        hexInc=0x3;
            for(int j=0;j<3;j=j+2){
                qua[indexQ] = ((number[i] & hexInc) >> j); //Dividing a hex bit into two qua bits
                hexInc += 0x9;
                ++indexQ;
            }
        i--;
        }while(i>-1);

        --k;
        i=k;
        indexO= i + (i/3);

        // Converting from hex to oct
        do{
            oct[indexO]=(number[i] & 0x7);
            printf("Octal[%d] %d\n",indexO,oct[indexO]);
            oct[indexO-1]=(((number[i] & 0x8) >> 3) + ((number[i-1] & 0x3) << 1));
            printf("Octal[%d] %d\n",indexO-1,oct[indexO-1]);
            oct[indexO-2]=(((number[i-1] & 0xC) >> 2) + ((number[i-2] & 0x1) << 2));
            printf("Octal[%d] %d\n",indexO-2,oct[indexO-2]);
            oct[indexO-3]=((number[i-2] & 0xE) >> 1);
            printf("Octal[%d] %d\n",indexO-3,oct[indexO-3]);
        i= i - 3;
        indexO = indexO - 4;

        }while(i>0);
        i=1;
        if(indexO < 0) i=0;
        printf("%d\n",indexO);
        printf("The value for octal is O");
        for(i=i;i < ((k + (k/3))+1);i++) printf("%d",oct[i]);
        printf("\n");
        printf("and the value for quanternary is Q");
        for(i=(indexQ-3);i>-1;i--) printf("%d",qua[i]);
        printf("\n");
    }
    printf("\n");
}while(strcmp(number,"quit"));

return 0;
}

