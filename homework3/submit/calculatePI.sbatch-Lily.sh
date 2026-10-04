#!/bin/sh

#SBATCH -J "MNXB11 Pi homework3"
#SBATCH --time=00:07:20
#SBATCH -A hep2023-1-6
#SBATCH --mem 28000000K
#SBATCH -o PI-%j.out
#SBATCH -e PI-%j.out
#SBATCH --nodes=3

# Launch the calculatePI.sh application script using the container script
run_in_container_calculatePI.sh
