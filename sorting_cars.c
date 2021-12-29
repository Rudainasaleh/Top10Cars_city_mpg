/*
Description: writing a program thar reads a csv file and  find the top 10 cars with highst city mpg  
			by using a sort function and then write it in another csv file 
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 200


/*
car struct that stores the car identification(string),  classification(string), engin_type(string),
 transmission(string), city_mpg(integer), fuel_type(string), and higheay_mpy(integer)
*/
struct cars
{
    char identification[MAX_LEN+1];
    char classification[MAX_LEN+1];
    char engin_type[MAX_LEN+1];
    char transmission[MAX_LEN+1];
    int city_mpg;
    char fuel_type[MAX_LEN+1];
    int higheay_mpy;
};



int compare(const void *p, const void *q);



int main()
{
    // 
    struct cars car[6000];
    int size = sizeof(car) / sizeof(car[0]);
    char input_file[MAX_LEN];
   



    // asking the user to enter the input file
    printf("Enter the  file nme: ");
	scanf("%s", input_file);

    // read the input file
	FILE *fr = fopen(input_file,"r");
	if(fr == NULL)
	{
		printf("\nError opening file");
		return 1; //abnormal termination
	}

	int i = 0;
	//reading until all lines of file are read
	while(!feof(fr) && !ferror(fr))
	{
        // scan thedetails for the car one by one
		fscanf(fr, "%[^,], %[^,], %[^,], %[^,], %d, %[^,], %d\n", car[i].identification, car[i].classification, car[i].engin_type, car[i].transmission, &car[i].city_mpg, car[i].fuel_type, &car[i].higheay_mpy);
		i++;
	}
        printf("%d %d\n", size, i);
	qsort(car, i,sizeof(car[0]), compare); // quick sort for the car 
	



    // opining another file to write
    FILE *fw = fopen("Top10_city_mpg.csv", "w");

    if(fw == NULL)
	{
		printf("\nError opening file");
		return 1; //abnormal termination
	}

    int a = i -1;
	while( a > i - 11) // only 10 top 
	{


		fprintf(fw, "%s,%s,%s,%s,%d,%s,%d\n", car[a].identification, car[a].classification, car[a].engin_type, car[a].transmission, car[a].city_mpg, car[a].fuel_type, car[a].higheay_mpy);
		a--;
	}
	printf("output file name: Top10_city_mpg.csv\n");

	fclose(fr); // close fr file
	fclose(fw); // close fw file
	return 0;


}
/*
int compare(const void *p, const void *q) 
compare function uses the quick sort function library
*/ 
int compare(const void *p, const void *q)
{
    //return the bigger values of city_mpg
    return ((struct cars *) p)->city_mpg - ((struct cars *) q)->city_mpg;
}




