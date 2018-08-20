#!/bin/bash

#SBATCH --job-name=pi
#SBATCH --output=pi1.out
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=sandyb

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

### openmp executable
./pi.exe
