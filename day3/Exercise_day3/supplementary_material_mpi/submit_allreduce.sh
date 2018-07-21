#!/bin/bash -l

#SBATCH --job-name=allreduce
#SBATCH --output=allreduce.out
#SBATCH --error=allreduce.err
#SBATCH --ntasks=8
#SBATCH --partition=sandyb
#SBATCH --time=00:02:00

module load openmpi

### MPI executable
mpiexec -np $SLURM_NTASKS ./allreduce.exe
