#!/bin/bash -l

#SBATCH --job-name=pi
#SBATCH --output=pi.out
#SBATCH --error=pi.err
#SBATCH --ntasks=4
#SBATCH --partition=sandyb
#SBATCH --time=00:02:00

module load openmpi

### MPI executable
mpiexec -np $SLURM_NTASKS ./pi.exe
