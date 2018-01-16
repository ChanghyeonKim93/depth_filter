#ifndef _DEPTH_FILTER_H_
#define _DEPTH_FILTER_H_


  struct Seed
  {
    static int num_of_seed;
    int id; // seed id for debug

    double a;
    double b;
    double mu;
    double sigma;
    Seed(const double& a_, const double& b_, const double& mu_, const double& sigma_); // constructor

  };


  class DepthFilter
  {

  public:
    void updateSeed(const double& x_, const double& tau_, Seed* seed);
  private:
    double z_max = 10,z_min = -10;

  };

#endif
