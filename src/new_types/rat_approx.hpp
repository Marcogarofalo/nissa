#ifndef _RAT_APPROX_HPP
#define _RAT_APPROX_HPP

#include <sstream>
#include <vector>
#include <string.h>

#include "io/buffer.hpp"

namespace nissa
{
  //rational approximation
  struct rat_approx_t
  {
    char name[20];
    double minimum;
    double maximum;
    double maxerr;
    double cons;
    int num,den;
    std::vector<double> poles;
    std::vector<double> weights;
    rat_approx_t() :
      minimum(0),maximum(0),maxerr(0),cons(0),
      num(0),den(0){name[0]='\0';}
    
    //return the degree
    int degree(){return poles.size();}
    
    //resize
    void resize(int size){poles.resize(size);weights.resize(size);}
    
    std::string get_str();
    void shift_all_poles(double sh) {for(int iterm=0;iterm<degree();iterm++) poles[iterm]+=sh;}
  };
  
  void convert_rat_approx(char *&data,int &data_length,std::vector<rat_approx_t> &appr);
  std::vector<rat_approx_t> convert_rat_approx(const char *data,size_t len);
}

#endif
