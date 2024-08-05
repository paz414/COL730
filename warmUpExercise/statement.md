## COL730 Assignment 0

<h4>In this assignment, you will try to use standard tools to profile, measure time and cache efficiency, and see the impact of using compiler flags to vectorize code (see gcc options -O2 -ftree-vectorize -mavx512f -fopt-info-vec-optimized). <br>Use the following matrix multiplication template.
<br><br>

  ```
    Accept command line option n
    Read or Generate matrices A and B, each with nxn double elements
    start = current time
     Compute C = A * B
     end = current time
     print time taken
```
  
   </h4>
<br>

Compute multiplication using the standard loop:<br>
```
   for(int i=0; i<n; i++)
      for(int j=0; j<n; j++) {
         double s = 0;
         for(int k=0; k<n; k++)
            s += A[i][k] * B[k][j];
         A[i][j] = s;
      }
``` 
<h4>Use unix time and perf commands and gnu profiler. For perf, use perf stat, perf record, perf report, and perf mem record commands. Report what you learn about cache utilization and effect of vectorization. Upload the report.
