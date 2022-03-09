/*
Gabe Volheim
Bgvolhe
ECE 2220
Project 2
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 32

struct Company {
    char Name[MAX];
    char Country[MAX];
    char Holder[MAX];
    char Number[17];
    char Email[MAX];
    int intialized;
    char CountryHolder[MAX];
};

struct ShotInfo {
    float Cost;
    unsigned char Dose;
    float Dosage;
    int initialized;
};

struct ShotApp {
    bool App;
    float Sold;
    double Sales;
    unsigned int Injuries;
    unsigned int Deaths;
    int initialized;
    float DeathsPer;
    float InjuriesPer;
};


int main(void){
    int choice,ch;
    char letter,fda;
    struct Company Company;
    struct ShotInfo ShotInfo;
    struct ShotApp ShotApp;
    Company.intialized=0;
    ShotApp.initialized=0;
    ShotInfo.initialized=0;
    FILE *fptr=fopen("countries.txt","r");
    char line[35] = {0};
    int j=0;
//Getting user input
do{
    do{
printf("Please type the number of the following data that is wished to be inputed\n");
printf("1. Enter Company Information\n2. Enter Shot Information\n3. Enter Shot Application\n4. Display all data\n5. Clear all data\n6. Quit\n");
scanf(" %d", &choice);
while((ch = getchar()) != '\n' && ch != EOF); //Eats Whitespace
if(choice < 0 || choice > 6) printf("Invalid Input\n");
    }while(choice < 0 || choice > 6);

//Using if else to determie 
if(choice==1){
    letter=0;
    Company.intialized=1;
        printf("Company information\n");
        printf("____________________\n");
    //Gets Company Name
        do{
            printf("Please input the company name(Max of 32 characters): ");
            fgets(Company.Name,MAX,stdin);
            if(Company.Name[strlen(Company.Name)-1] != '\n') 
            {
                printf("Error: Name too long, consider using an abbreviation\n");
                while ((ch = getchar()) != '\n' && ch != EOF); //"Clears" stdin
            }
        }while (Company.Name[strlen(Company.Name)-1] != '\n');

    //Gets Country
        do{
        printf("Please input the company country's first letter(Make Sure its capitalized): ");
        scanf(" %c", &letter);
        while((ch = getchar()) != '\n' && ch != EOF); //Eats whitespace and only gets first letter
        if(letter>90 || letter<65) printf("Error, invalid input please try again!\n");
        }while(letter>90 || letter<65);

        //Iterates through the file and prints the line if it has the same first letter
        while (fgets(line, 35, fptr)){
        if(strncmp(&letter,line,strlen(&letter)) == 0){
            printf("%s" , line);
        }
        if (line[strlen(line) - 1] != '\n') //Adds a new line if there is not one present
        printf("\n");
        }
        fclose(fptr); //Closes file so we can reiterate through it in the future
    
        //User inputs abbreviation string and it is then checked to see if it is contained in the text file
        do{
        fptr=fopen("countries.txt","r"); // Reopens the file everytime so we can start at the beginning 
        printf("Please input the country abbreviation that you wish to display: ");
        fgets(Company.Holder,MAX,stdin);
        while (fgets(line, 35, fptr)){
            if(strstr(line,Company.Holder)){
                j=1; 
            }
        }
        if(j==0){
        fclose(fptr);
        printf("Error: Abbreviation is not in the list, please try again!\n");
        }
        }while(j==0);
        fclose(fptr);
        fptr=fopen("countries.txt","r");
        while (fgets(line, 35, fptr)){
            if(strstr(line,Company.Holder)){ //Checks to see if the line that is read contains the inputed Abbreviation
                for(int i=0;i<(strlen(line)-strlen(Company.Holder)-1);i++){ // Copies the string cell by cell while excluding the abbreviation and semicolon
                    Company.Country[i]=line[i];
                }
            }
            }
    //Gets Phone Number and Makes sure user inputs it in Valid format
    do{
        printf("Please input phone number using the exact format nn-XXX-XXX-XXXX\n");
        printf("Number: ");
        fgets(Company.Number,17,stdin);
        for(int i=2;i<11;i += 4){
            if(Company.Number[i] != '-'){
                printf("Error: Invalid format\n");
                j=1;
                break;
            }
             else j=0;
        }
        }while(j==1);

    //Gets Email and Makes sure the Characters @ and . exist in it        
        do{
        printf("Please enter company email: ");
        fgets(Company.Email,MAX,stdin);
        if((strchr(Company.Email,'@')==NULL)||(strchr(Company.Email,'.')==NULL)) printf("Error: Either missing . or @. Please try again\n");
        }while((strchr(Company.Email,'@')==NULL)||(strchr(Company.Email,'.')==NULL));
}

else if(choice==2){
    ShotInfo.initialized=1; 
        printf("Shot Information\n");
        printf("_________________\n");

        //Getting total shot cost
        do{
            printf("Please Input the Shot Cost in US Dollars: ");
            scanf(" %f", &ShotInfo.Cost);
            while ((ch = getchar()) != '\n' && ch != EOF);
            if(ShotInfo.Cost < 0.00 || ShotInfo.Cost > 999999.99) printf("Error: Value either too large or to small, please input a smaller value\n");
        }while(ShotInfo.Cost < 0.00 || ShotInfo.Cost > 999999.99);

        //Getting recommeneded shot doses
        do{
            printf("Please input the Recommended Shot Doses: ");
            scanf(" %hhd", &ShotInfo.Dose);
            while ((ch = getchar()) != '\n' && ch != EOF);
            if(ShotInfo.Dose < 1 || ShotInfo.Dose > 255) printf("Error: Value either too large or to small, please input a smaller value\n");
        }while(ShotInfo.Dose < 1 || ShotInfo.Dose > 255);
        
        //Getting recommeneded shot dosage
        do{
            printf("Please input the Recommended Shot Dosage: ");
            scanf(" %f", &ShotInfo.Dosage);
            while ((ch = getchar()) != '\n' && ch != EOF);
            if(ShotInfo.Dosage < 0.1 || ShotInfo.Dosage > 100.0) printf("Error: Value either too large or to small, please input a smaller value\n");
        }while(ShotInfo.Dosage < 0.1 || ShotInfo.Dosage > 100.0);
}      

else if(choice==3){
        printf("Shot Application\n");
        printf("_________________\n");
        ShotApp.initialized=1;

        do{ // Validating user input then saving the value as either 1 or 0
        printf("Please input the fdas approval as a lowercase y or n: "); 
        scanf("%c", &fda);
        while((ch = getchar()) != '\n' && ch != EOF); //Eating whitespace
        if(fda != 'n' && fda != 'y') printf("Error, wrong input, please try again\n");
        }while(fda!= 'y'&& fda != 'n');
        if(fda=='n') ShotApp.App=0;
        else ShotApp.App=1;
        
        //Total Shot Dosage Sold
        do{
        printf("Please input the total shot doses sold: ");
        scanf(" %f", &ShotApp.Sold);
        while ((ch = getchar()) != '\n' && ch != EOF);
        if(ShotApp.Sold < 0 || ShotApp.Sold > 100000000000) printf("Error, value is either too large or too small, please try again! \n");
        }while(ShotApp.Sold < 0 || ShotApp.Sold > 100000000000);

        //Total Shot Sales
        do{
        printf("Please input the total shot sales: ");
        scanf(" %le", &ShotApp.Sales);
        while ((ch = getchar()) != '\n' && ch != EOF);
        if(ShotApp.Sales < 0 || ShotApp.Sales > 9999999999999.99) printf("Error, value is either too large or too small, please try again! \n");
        }while(ShotApp.Sales < 0 || ShotApp.Sales > 9999999999999.99);
        
        //Total Shot Injuries
        do{
        printf("Please input the total shot injuries: ");
        scanf(" %d", &ShotApp.Injuries);
        while ((ch = getchar()) != '\n' && ch != EOF);
        if(ShotApp.Injuries < 0 || ShotApp.Injuries > 4000000000) printf("Error, value is either too large or too small, please try again! \n");
        }while(ShotApp.Injuries < 0 || ShotApp.Injuries > 4000000000);

        //Total Shot Deaths
        do{
        printf("Please input the total shot deaths: ");
        scanf(" %u", &ShotApp.Deaths);
        while ((ch = getchar()) != '\n' && ch != EOF);
        if(ShotApp.Deaths < 0 || ShotApp.Deaths > 1000000000) printf("Error, value is either too large or too small, please try again! \n");
        }while(ShotApp.Deaths < 0 || ShotApp.Deaths > 1000000000);
        
        //Calculates Injuries and deaths per Dose
        ShotApp.InjuriesPer= (ShotApp.Injuries/ShotApp.Sold)*100;
        ShotApp.DeathsPer= (ShotApp.Deaths/ShotApp.Sold)*100;

}
else if(choice==4){ // Either printing out data or printing out the unitialized value depenings on the respective structs intialized value
        printf("Display all Data\n");
        printf("________________\n");
        if(Company.intialized==1){
        printf("Company Name: %s" , Company.Name);
        printf("Company Country: %s\n" , Company.Country);
        printf("Company Number: %s" , Company.Number);
        printf("Company Email: %s" , Company.Email);
        }
        else{
        printf("Company Name: Uninitialized\n");
        printf("Company Country: Uninitialized\n");
        printf("Company Number: Uninitialized\n");
        printf("Company Email: Uninitialized\n");
        }
        if(ShotInfo.initialized==1){
        printf("Shot Cost: $ %.2f\n", ShotInfo.Cost);
        printf("Reccomended Shot Doses: %d\n",ShotInfo.Dose);
        printf("Reccomended Shot Dosage: %.2f mL\n",ShotInfo.Dosage);
        }
        else{
        printf("Shot Cost: Uninitialized\n");
        printf("Reccomended Shot Doses: Uninitialized\n");
        printf("Reccomended Shot Dosage: Uninitialized\n");
        }
        if(ShotApp.initialized==1){
            if (ShotApp.App == 1) printf("Fda Approval: Yes\n");
            else if(ShotApp.App == 0) printf("Fda Approval: No\n");
        printf("Total Shot Doses Sold: %.0f\n",ShotApp.Sold);
        printf("Total Shot Sales: $%.2f\n",ShotApp.Sales);
        printf("Total Shot Injuries: %d\n",ShotApp.Injuries);
        printf("Total Shot Deaths: %d\n",ShotApp.Deaths);
    }
        else{
        printf("Fda Approval: Uninitialized\n");
        printf("Total Shot Doses Sold: Uninitialized\n");
        printf("Total Shot Sales: Uninitialized\n");
        printf("Total Shot Injuries: Uninitialized\n");
        printf("Total Shot Deaths: Uninitialized\n");
        printf("Injuries per dose %%: Unitialized\n");        
        printf("Deaths per dose %%: Unitialized\n");
        }
        if(ShotApp.initialized==1){
        printf("Injuries per dose %.02f%%\n",ShotApp.InjuriesPer);
        printf("Deaths per dose %.02f%%\n",(ShotApp.Deaths/ShotApp.Sold)*100);
        }
}
else if(choice==5){
Company.intialized=0;
ShotApp.initialized=0;
ShotInfo.initialized=0;
}

}while(choice!=6);
return 0;    
}
