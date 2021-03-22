#ifndef _THREADS_HPP
#define _THREADS_HPP

#ifdef HAVE_CONFIG_H
 #include "config.hpp"
#endif

#define NISSA_CHUNK_WORKLOAD(START,CHUNK_LOAD,END,EXT_START,EXT_END,CHUNK_ID,NCHUNKS) \
  int WORKLOAD=EXT_END-EXT_START,					\
  CHUNK_LOAD=(WORKLOAD+NCHUNKS-1)/NCHUNKS,				\
  START=EXT_START+CHUNK_ID*CHUNK_LOAD,					\
  END=START+CHUNK_LOAD< EXT_END ? START+CHUNK_LOAD : EXT_END

#define NISSA_CHUNK_LOOP(INDEX,EXT_START,EXT_END,CHUNK_ID,NCHUNKS)	\
  for(NISSA_CHUNK_WORKLOAD(START,CHUNK_LOAD,END,EXT_START,EXT_END,CHUNK_ID,NCHUNKS),INDEX=START;INDEX<END;INDEX++)

#define THREADABLE_FUNCTION_END }

#if THREADS_TYPE == NO_THREADS
 #include "threads/no_threads.hpp"
#elif THREADS_TYPE == OPENMP_THREADS
 #include "threads/openmp_threads.hpp"
#elif THREADS_TYPE == CUDA_THREADS
 #include "threads/cuda_threads.hpp"
#else
 #error Unknown thread parallelization THREADS_TYPE !
#endif

#ifndef NISSA_PARALLEL_LOOP
 #define NISSA_PARALLEL_LOOP(INDEX,EXT_START,EXT_END) for(int INDEX=EXT_START;INDEX<EXT_END;INDEX++){
#endif

#ifndef NISSA_PARALLEL_LOOP_END
 #define NISSA_PARALLEL_LOOP_END }
#endif

#ifndef NISSA_PARALLEL_LOOP_EXP
 #define NISSA_PARALLEL_LOOP_EXP(INDEX,EXT_START,EXT_END) NISSA_PARALLEL_LOOP(INDEX,EXT_START,EXT_END)
#endif

#ifndef NISSA_PARALLEL_LOOP_END_EXP
 #define NISSA_PARALLEL_LOOP_END_EXP NISSA_PARALLEL_LOOP_END
#endif


namespace nissa
{
  double *glb_threads_reduce_double_vect(double *vect,int nel);
  inline complex *glb_threads_reduce_complex_vect(complex *vect,int nel)
  {return (complex*)glb_threads_reduce_double_vect((double*)vect,2*nel);}
  
  void _vector_loc_reduce(double* loc_res,double* buf,int64_t n,int nslices=1);
  void _vector_loc_reduce(complex* loc_res,complex* buf,int64_t n,int nslices=1);
#ifdef REPRODUCIBLE_RUN
  void _vector_loc_reduce(float_128* loc_res,float_128* buf,int64_t n,int nslices=1);
  void _vector_loc_reduce(complex_128* loc_res,complex_128* buf,int64_t n,int nslices=1);
#endif
}

#endif
