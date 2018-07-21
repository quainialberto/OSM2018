#!/bin/bash

#SBATCH --job-name=pi-serial
#SBATCH --output=serial_pi.out
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=sandyb

./serial_pi.exe
