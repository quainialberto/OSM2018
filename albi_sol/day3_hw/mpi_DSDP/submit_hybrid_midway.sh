#!/bin/bash
# a sample job submission script to submit an MPI job to the sandyb
# partition on Midway1 please change the --partition option if you want to use
# another partition on Midway1

#SBATCH --time=02:00:00
#SBATCH --job-name=DSDP_MPI
#SBATCH --output=DSDP_MPI16.out
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=16
#SBATCH --partition=sandyb

module load openmpi
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

mpirun ./VFI
