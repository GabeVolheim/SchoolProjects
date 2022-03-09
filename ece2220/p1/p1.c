/* Gabe Volheim
Bgvolhe
ECE 2720 Spring 2022
Project 1
*/

#include <stdio.h>
#include <math.h>

// Function that takes the input char and checks which number it is equal too, then returns the answer at the given spot. Float i is the number that needs to be calculated.
float solve(char ans,float i){
float answer;
    if(ans==49){
        answer=exp(i);
}
        else if(ans==50){
            answer=log(i);
        }
            else if(ans==51){
                answer=sin(i);
            }
                else if(ans==52){
                    answer=cos(i);
                }
                else if(ans==53){
                    answer=tan(i);
                }
return answer;
}

int main(void){

int ch,r,c,z;
char ans;
float min,max,inc,answer,i,maxI,minI,range,h;
maxI=0;
minI=1000000000;

do{
//Asking for the users input on graph
printf("1. e(x)\n2. ln(x)\n3. sine(x)\n4. cosine(x)\n5. tangent(x)\nq. Quit.\n");
printf("Please input the number of the graph you wish to diplay:\n");
scanf(" %c", &ans);
while( (ch = getchar()) != '\n' && ch != EOF); //Getting only the first char entered into command line
if(ans==113) break;

//Asking user for input on min and max values
do{
printf("Please input a minimum value:");
scanf("%f", &min);
printf("Please input a maximum value (Note the max value must be greater than the min):");
scanf("%f", &max);
if(min>max) printf("Please make sure that the minimum value is less than the max value!\n");
}while(min>max);

//Asking user to input rows and columns and declaring bin array
do{
printf("Please input the number of rows you wish to have (Max of 50):");
scanf("%i",&r);
printf("Please input the number of columns you wish to have(Max of 200):");
scanf("%i",&c);
if(r>50 ||c>200) printf("Please make sure that the value for the rows is less than 51 and the value for Columns is less than 201\n");
}while(r>50 || c>200 || r<0 || c<0);

int bin[r][c];
for(int k=0; k<r;k++){
    for(int b=0;b<c;b++){
        bin[k][b]=0;
    }
}

//Finding the value by which the period increments and then using that to find the max and min

inc=(max-min)/c;
for(i=min;i<max;i=i+inc){
answer=solve(ans,i);
if(answer>maxI)
    maxI=answer;
    else if(answer<minI)
    minI=answer;
}

//Dividing the distance between all of the points then checking for each value if it is between or equal to either of the values

range=(maxI-minI)/r; //Calcutlating the difference between the values by which we will compare in lines 90-95
i=min;
for(int b=0;b<c;b++){
    answer=solve(ans,i);
    int k=0;
        for(h=minI+((r)*range);h>minI+range;h=h-range){ //This for loop is calculating the value so the answer determinded in line 88 can be compared.
                if(answer==h||(answer<h && answer>(h-range))||answer==(h-range)){ //This is checking if the answer is equal to or inbetween two values of the given h and then setting equal to one
                bin[k][b]=1;
            }
            k++;
            if(bin[k][b]==1) break; //Since the answer can only be equal to or inbetween two values once per row and col, we break the value if that is the case.
    }
    i=i+inc; //used for next value to be calculated
}

//Checking if there is a one present and replacing if there is an X or a blank for a zero
float print=minI+(r*range); // declared as the max value that the item will be calculated
z=r-1; //z is intitalized as r-1 so then it will always be equal to the max that k will increment to in the for loop on line 103
for(int k=0;k<r;k++){
    printf("%02d:%+.6f - ",k+z,print); //The k+z is to be able to print out the number that we are calculating.
    for(int b=0;b<c;b++){
        if(bin[k][b]==0) printf(" ");
        else if(bin[k][b]==1) printf("X"); 
    }
printf("\n");
print=print-range;
z=z-2; //z must decrease by two everytime since k is increasing by one.
}

}while(ans!=113);
return 0;
}
