/*
 * Copyright (c) 2008 Radu Bogdan Rusu <rusu -=- cs.tum.edu>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 *
 */

/** \author Radu Bogdan Rusu */

#ifndef _SAMPLE_CONSENSUS_SACMODELCYLINDER_H_
#define _SAMPLE_CONSENSUS_SACMODELCYLINDER_H_

#include <door_handle_detector/sample_consensus/sac_model.h>
#include <door_handle_detector/sample_consensus/model_types.h>

/** \brief Define the maximum number of iterations for collinearity checks */
#define MAX_ITERATIONS_COLLINEAR 1000

namespace sample_consensus
{
  /** \brief A Sample Consensus Model class for cylinder segmentation.
    */
  class SACModelCylinder : public SACModel
  {
    public:
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** \brief Constructor for base SACModelCylinder. */
      SACModelCylinder () { nx_idx_ = ny_idx_ = nz_idx_ = -1; }

      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** \brief Destructor for base SACModelCylinder. */
      virtual ~SACModelCylinder () { }

      virtual void getSamples (int &iterations, std::vector<int> &samples);

      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** \brief Test whether the given model coefficients are valid given the input point cloud data.
        * \param model_coefficients the model coefficients that need to be tested
        * \todo implement this
        */
      bool testModelCoefficients (const std::vector<double> &model_coefficients) { return true; }

      virtual bool computeModelCoefficients (const std::vector<int> &samples);

      virtual void refitModel (const std::vector<int> &inliers, std::vector<double> &refit_coefficients);
      virtual void getDistancesToModel (const std::vector<double> &model_coefficients, std::vector<double> &distances);
      virtual void selectWithinDistance (const std::vector<double> &model_coefficients, double threshold, std::vector<int> &inliers);

      virtual void projectPoints (const std::vector<int> &inliers, const std::vector<double> &model_coefficients, sensor_msgs::PointCloud &projected_points);

      virtual void projectPointsInPlace (const std::vector<int> &inliers, const std::vector<double> &model_coefficients);
      virtual bool doSamplesVerifyModel (const std::set<int> &indices, double threshold);

      static int functionToOptimize (void *p, int m, int n, const double *x, double *fvec, int iflag);

      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** \brief Return an unique id for this model (SACMODEL_CYLINDER). */
      virtual int getModelType () { return (SACMODEL_CYLINDER); }

    private:
      /** \brief The coordinates of point normals in the dataset. */
      int nx_idx_, ny_idx_, nz_idx_;
      /** \brief temporary pointer to a list of given indices for refitModel () */
      const std::vector<int> *tmp_inliers_;
  };
}

#endif
