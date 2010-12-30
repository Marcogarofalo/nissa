#pragma once

#include "bgp_instructions.c"
#include "dirac_operator.c"

void inv_Q2_cgmms(spincolor **sol,spincolor *source,spincolor **guess,quad_su3 *conf,double kappac,double *m,int niter,int rniter,double residue,int nmass)
{
  static double _Complex A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32;
  static double _Complex B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32;
  static double _Complex N0,N1,N2;
  static double _Complex R;

  int *flag=(int*)malloc(sizeof(int)*nmass);
  int riter=0;
  spincolor *t=(spincolor*)malloc(sizeof(spincolor)*(loc_vol+loc_bord)); //temporary for internal calculation of DD
  spincolor *s=(spincolor*)malloc(sizeof(spincolor)*(loc_vol));
  spincolor *r=(spincolor*)malloc(sizeof(spincolor)*loc_vol);
  spincolor *p=(spincolor*)malloc(sizeof(spincolor)*(loc_vol+loc_bord));
  spincolor **ps=(spincolor**)malloc(sizeof(spincolor*)*nmass);
  for(int imass=0;imass<nmass;imass++) ps[imass]=(spincolor*)malloc(sizeof(spincolor)*(loc_vol+loc_bord));

  for(int imass=0;imass<nmass;imass++)
    {
      if(guess==NULL) memset(sol[imass],0,sizeof(spincolor)*(loc_vol+loc_bord));
      else memcpy(sol[imass],guess[imass],sizeof(spincolor)*(loc_vol+loc_bord));
      
      flag[imass]=1;
    }

  //external loop, used if the internal exceed the maximal number of iterations
  double lambda; //(r_(k+1),r_(k+1))
  
  do
    {

      //calculate p0=r0=DD*sol_0 and delta_0=(p0,p0), performing global reduction and broadcast to all nodes
      double delta;
      {

	apply_Q2(s,sol,conf,kappac,m,t);

	complex cloc_delta={0,0};

	bgp_color_put_to_zero(N0,N1,N2);
	for(int i=0;i<loc_vol;i++)
	  {
	    bgp_load_spincolor(A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,source[i]);
	    bgp_load_spincolor(B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32,s[i]);
	    bgp_subtassign_spincolor(A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32);
	    bgp_save_spincolor(p[i],A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32);
	    bgp_save_spincolor(r[i],A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32);
	    bgp_summassign_color_square_spincolor(N0,N1,N2,A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32);
	  }
	bgp_square_norm_color(N0,N1,N2);
	bgp_save_complex(cloc_delta,N0);
	
	if(rank_tot>0) MPI_Allreduce(cloc_delta,&delta,1,MPI_DOUBLE,MPI_SUM,MPI_COMM_WORLD);
	else delta=cloc_delta[0];
      }


      //main loop
      int iter=0;
      do
	{
	  double omega; //(r_k,r_k)/(p_k*DD*p_k)
	  {
	    double alpha;
	    if(rank_tot>0) communicate_lx_spincolor_borders(p);
	    apply_Q2(s,p,conf,kappac,m,t);

	    complex cloc_alpha={0,0};

	    bgp_color_put_to_zero(N0,N1,N2);
	    for(int i=0;i<loc_vol;i++)
	      { //real part of the scalar product
		bgp_load_spincolor(A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,s[i]);
		bgp_load_spincolor(B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32,p[i]);
		bgp_summassign_color_realscalarprod_spincolor(N0,N1,N2,A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32);
	      }
	    bgp_square_norm_color(N0,N1,N2);
	    bgp_save_complex(cloc_alpha,N0);
	    
	    if(rank_tot>0) MPI_Allreduce(cloc_alpha,&alpha,1,MPI_DOUBLE,MPI_SUM,MPI_COMM_WORLD);
	    else alpha=cloc_alpha[0];

	    omega=delta/alpha;
	  }
	  
	  {
	    complex cloc_lambda={0,0};
	    complex comega={omega,0};
	    bgp_load_complex(R,comega);

	    bgp_color_put_to_zero(N0,N1,N2);
	    for(int i=0;i<loc_vol;i++)
	      {        //sol_(k+1)=x_k+omega*p_k
		bgp_load_spincolor(A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,sol[i]);
		bgp_load_spincolor(B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32,p[i]);
		bgp_summassign_spincolor_prod_real(A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32,__creal(omega));
		bgp_save_spincolor(sol[i],A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32);

		//r_(k+1)=x_k-omega*p_k and residue calculation
		bgp_load_spincolor(A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,r[i]);
		bgp_load_spincolor(B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32,s[i]);
		bgp_subtassign_spincolor_prod_real(A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32,__creal(R));
		bgp_summassign_color_square_spincolor(N0,N1,N2,A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32);
		bgp_save_spincolor(r[i],A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32);
	      }
	    bgp_square_norm_color(N0,N1,N2);
	    bgp_save_complex(cloc_lambda,N0);
	    if(rank_tot>0) 
	      {
		communicate_lx_spincolor_borders(sol);
		MPI_Allreduce(cloc_lambda,&lambda,1,MPI_DOUBLE,MPI_SUM,MPI_COMM_WORLD);
	      }
	    else lambda=cloc_lambda[0];
	  }

	  double gammag=lambda/delta; //(r_(k+1),r_(k+1))/(r_k,r_k)
	  delta=lambda;
	  
	  //p_(k+1)=r_(k+1)+gammag*p_k
	  {
	    complex cgammag={gammag,0};
	    bgp_load_complex(R,cgammag);

	    for(int i=0;i<loc_vol;i++)
	      {
		bgp_load_spincolor(A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,p[i]);
		bgp_load_spincolor(B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32,r[i]);
		bgp_summ_spincolor_prod_real(A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,B00,B01,B02,B10,B11,B12,B20,B21,B22,B30,B31,B32,A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32,__creal(R));
		bgp_save_spincolor(p[i],A00,A01,A02,A10,A11,A12,A20,A21,A22,A30,A31,A32);
	      }
	    }

	  iter++;

	  if(rank==0 && debug) printf("iter %d residue %g\n",iter,lambda);
	}
      while(lambda>residue && iter<niter);
      
      //last calculation of residual, in the case iter>niter
      apply_Q2(s,sol,conf,kappac,m,t);
      {
	double loc_lambda=0;
	double *ds=(double*)s,*dsource=(double*)source;
	for(int i=0;i<loc_vol*3*4*2;i++)
	  {
	    double c1=(*dsource)-(*ds);
	    loc_lambda+=c1*c1;
	    
	    dsource++;ds++;
	  }
	if(rank_tot>0) MPI_Allreduce(&loc_lambda,&lambda,1,MPI_DOUBLE,MPI_SUM,MPI_COMM_WORLD);
	else lambda=loc_lambda;
      }

      riter++;
    }
  while(lambda>residue && riter<rniter);
  
  for(int imass=0;imass<nmass;imass++) free(ps[imass]);
  free(ps);
  free(s);
  free(p);
  free(r);
  free(t);

  free(flag);
}
