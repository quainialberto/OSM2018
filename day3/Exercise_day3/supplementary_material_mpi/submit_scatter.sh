#!/bin/bash -l

#SBATCH --job-name=scatter
#SBATCH --output=scatter.out
#SBATCH --error=scatter.err
#SBATCH --ntasks=7
#SBATCH --partition=sandyb
#SBATCH --time=00:02:00

module load openmpi

### MPI executable
mpiexec -np $SLURM_NTASKS ./scatter.exe
