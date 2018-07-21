#!/bin/bash -l

#SBATCH --job-name=broadcast
#SBATCH --output=broadcast.out
#SBATCH --error=broadcast.err
#SBATCH --ntasks=8
#SBATCH --partition=sandyb
#SBATCH --time=00:02:00

module load openmpi

### MPI executable
mpiexec -np $SLURM_NTASKS ./broadcast.exe
