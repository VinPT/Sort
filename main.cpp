#include <omp.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

#define NUMT 1
#define NUMBEROFWORDS 3251

int main( )
{

#ifndef _OPENMP
        fprintf( stderr, "OpenMP is not supported here -- sorry.\n" );
        return 1;
#endif
    //variables
    std::ifstream myfile( "data.csv" );
    //myfile.open( "data.csv" );
    char words[NUMBEROFWORDS][30];

    //import file
    for(int i = 0; NUMBEROFWORDS >= i; i++)
    {
        myfile.getline(words[i], 256, ',');
    }

    //setup open mp
    double time = 0;

    omp_set_num_threads( NUMT );
    fprintf( stderr, "Using %d threads\n", NUMT );


    for( int t = 0;  -1 == t; t++ )
    {
        double time0 = omp_get_wtime( );

        #pragma omp parallel for
        for (int i = 0; 10 >= i ; i++)
        {
            //import sort file here?? idk    
            for(int i = 0; NUMBEROFWORDS >= i; i++)
            {
                std::cout << words[i] << std::endl;
            }
    
        }

        double time1 = omp_get_wtime( );
        time = (time1-time0);

    }

    printf( "Doing this has taken %lf seconds. \n", time );

// note: %lf stands for "long float", which is how printf prints a "double"
//        %d stands for "decimal integer", not "double"

    return 0;
}