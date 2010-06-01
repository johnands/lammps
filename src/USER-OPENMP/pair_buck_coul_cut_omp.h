/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef PAIR_CLASS

PairStyle(buck/coul/cut/omp,PairBuckCoulCutOMP)

#else

#ifndef LMP_PAIR_BUCK_COUL_CUT_OMP_H
#define LMP_PAIR_BUCK_COUL_CUT_OMP_H

#include "pair_omp.h"

namespace LAMMPS_NS {

class PairBuckCoulCutOMP : public PairOMP {
 public:
  PairBuckCoulCutOMP(class LAMMPS *);
  ~PairBuckCoulCutOMP();
  virtual void compute(int, int);
  virtual void settings(int, char **);
  virtual void coeff(int, char **);
  virtual void init_style();
  virtual double init_one(int, int);
  virtual void write_restart(FILE *);
  virtual void read_restart(FILE *);
  virtual void write_restart_settings(FILE *);
  virtual void read_restart_settings(FILE *);
  virtual double single(int, int, int, int, double, double, double, double &);

  virtual double memory_usage();

 protected:
      template <int EVFLAG, int EFLAG, int NEWTON_PAIR> void eval();
 protected:
  double cut_lj_global,cut_coul_global;
  double **cut_lj,**cut_ljsq;
  double **cut_coul,**cut_coulsq;
  double **a,**rho,**c;
  double **rhoinv,**buck1,**buck2,**offset;

  void allocate();
};

}

#endif
#endif
