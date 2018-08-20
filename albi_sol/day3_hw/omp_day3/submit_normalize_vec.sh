#!/bin/bash

#SBATCH --job-name=normalize_vec
#SBATCH --output=normalize_vec.out
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=8
#SBATCH --partition=sandyb

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

### openmp executable
./normalize_vec.exe
