#include "depth_filter.h"
#include "common.h"

int Seed::num_of_seed = 0;
Seed::Seed(const double& a_, const double& b_, const double& mu_, const double& sigma_) : a(a_),b(b_),mu(mu_),sigma(sigma_)
{
  ++num_of_seed;
} // any contents


void DepthFilter::updateSeed(const double& x_, const double& tau_, Seed* seed){
  double C1 = seed->a / (seed->a + seed->b) * 1.0/ sqrt(2*PI) / seed->sigma *exp(-pow(x_ - seed->mu,2)/(2*seed->sigma*seed->sigma));
  double C2 = seed->b/ (seed->a+seed->b) /(this->z_max - this->z_min);
  double C1C2 = C1 + C2;
  C1 /= C1C2; // normalize
  C2 /= C1C2;

  double s = sqrt( 1.0/ (1.0/pow(seed->sigma,2) + 1.0/pow(tau_,2) ) );
  double m = s*s *(seed->mu / pow(seed->sigma,2) + x_ / pow(tau_,2) );

  double mu_new = C1*m + C2*seed->mu;
  double sigma_new = sqrt( C1*(pow(s,2) + pow(m,2)) + C2*(seed->sigma*seed->sigma + seed->mu*seed->mu) - mu_new*mu_new );

  double F = C1 * (seed->a + 1.0)/(seed->a + seed->b + 1.0) + C2*seed->a/(seed->a + seed->b + 1.0);
  double E = C1 * (seed->a + 1.0)/(seed->a + seed->b + 1.0)* (seed->a +2.0)/(seed->a + seed->b + 2.0) + C2 * seed->a / (seed->a + seed->b + 1.0)*(seed->a + 1.0)/(seed->a + seed->b + 2.0);

//  double a_new = (E-F)/(F-E/F);
//  double b_new = a_new * (1-F)/F;

  seed->a = (E-F)/(F-E/F);
  seed->b = seed->a*(1-F)/F;
  seed->mu = mu_new;
  seed->sigma = sigma_new;
}
