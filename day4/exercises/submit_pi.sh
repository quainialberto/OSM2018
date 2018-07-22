#!/bin/bash -l

#SBATCH --job-name=pi
#SBATCH --output=pi_4_8.out
#SBATCH --error=pi_4_8.err
#SBATCH --ntasks=4
#SBATCH --cpus-per-task=8
#SBATCH --partition=sandyb
#SBATCH --time=00:02:00

module load openmpi

### MPI executable
mpiexec -np $SLURM_NTASKS ./pi.exe
