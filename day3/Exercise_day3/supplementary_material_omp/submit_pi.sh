#!/bin/bash

#SBATCH --job-name=pi
#SBATCH --output=pi4.out
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4
#SBATCH --partition=sandyb

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

### openmp executable
./pi.exe
