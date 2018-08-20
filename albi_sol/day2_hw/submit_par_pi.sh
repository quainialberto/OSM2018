#!/bin/bash

#SBATCH --job-name=par_pi
#SBATCH --output=par_pi.out
#SBATCH --account=osmlab
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=8
#SBATCH --partition=sandyb

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
# Run the process
./par_pi.exe
