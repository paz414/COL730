#!/bin/sh
#PBS -N COL730
#PBS -P col730.me1221438.course
#PBS -q standard
#PBS -M $me1221438@iitd.ac.in
#PBS -m bea
#PBS -l select=1:ncpus=1
#PBS -l walltime=02:00:00

## Environment
echo "==============================="
echo $PBS_JOBID
cat $PBS_NODEFILE
echo "==============================="
cd /home/mech/btech/me1221438/Assignment1

## Modules
module purge
module load compiler/intel/2020u4/intelpython3.7
module load compiler/gcc/9.1.0

## CPU JOB
bash run.sh
