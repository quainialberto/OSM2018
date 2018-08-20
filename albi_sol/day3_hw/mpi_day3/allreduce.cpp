#include <stdio.h>
#include <mpi.h>

int 
main (int argc, char *argv[])
{
    int my_rank=0, sum=0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    /* Compute sum of all ranks. */
    MPI_Allreduce(&my_rank, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    
    printf ("Rank %i:\tSum = %i\n", my_rank, sum);
    MPI_Finalize();

    return 0;
}
