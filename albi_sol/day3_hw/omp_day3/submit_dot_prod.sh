#!/bin/bash

#SBATCH --job-name=dot_prod
#SBATCH --output=dot_prod.out
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=8
#SBATCH --partition=sandyb

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

### openmp executable
./dot_prod.exe
