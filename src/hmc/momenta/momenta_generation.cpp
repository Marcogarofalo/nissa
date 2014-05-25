#ifdef HAVE_CONFIG_H
 #include "config.hpp"
#endif

#include "base/global_variables.hpp"
#include "base/random.hpp"
#include "base/thread_macros.hpp"
#include "base/vectors.hpp"
#include "new_types/su3.hpp"
#ifdef USE_THREADS
 #include "routines/thread.hpp"
#endif

namespace nissa
{
  //generate momenta using guassian hermitean matrix generator
  THREADABLE_FUNCTION_1ARG(generate_hmc_momenta, quad_su3**,H)
  {
    GET_THREAD_ID();
    for(int par=0;par<2;par++)
      {
	NISSA_PARALLEL_LOOP(ivol,0,loc_volh)
	  for(int mu=0;mu<4;mu++)
	    herm_put_to_gauss(H[par][ivol][mu],&(loc_rnd_gen[loclx_of_loceo[par][ivol]]),1);
	set_borders_invalid(H[par]);
      }
  }
  THREADABLE_FUNCTION_END

  //generate momenta using guassian hermitean matrix generator
  THREADABLE_FUNCTION_1ARG(generate_hmc_B_momenta, double*,H_B)
  {
    GET_THREAD_ID();
    
    if(IS_MASTER_THREAD)
      {
	complex temp,ave={0,0};
	rnd_get_gauss_complex(temp,&glb_rnd_gen,ave,1.0);
	(*H_B)=temp[0];
      }
    THREAD_BARRIER();
  }
  THREADABLE_FUNCTION_END
}
