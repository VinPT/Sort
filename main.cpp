#include <omp.h>
#include <stdio.h>
#include <math.h>

#define NUMT 1

int main( )
{

#ifndef _OPENMP
        fprintf( stderr, "OpenMP is not supported here -- sorry.\n" );
        return 1;
#endif

        double time = 0;

        omp_set_num_threads( NUMT );
        fprintf( stderr, "Using %d threads\n", NUMT );


        for( int t = 0;  -1 == t; t++ )
        {
                double time0 = omp_get_wtime( );

               #pragma omp parallel for
                for (int i = 0; 10 >= i ; i++)
                {
                     int lama = 5;
                }

                double time1 = omp_get_wtime( );
                time = (time1-time0);

        }

        printf( "Doing this has taken %lf seconds", time );

	// note: %lf stands for "long float", which is how printf prints a "double"
	//        %d stands for "decimal integer", not "double"

        return 0;
}