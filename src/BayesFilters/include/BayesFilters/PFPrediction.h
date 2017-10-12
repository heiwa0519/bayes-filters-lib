#ifndef PFPREDICTION_H
#define PFPREDICTION_H

#include "StateModel.h"

#include <Eigen/Dense>
#include <string>

namespace bfl {
    class PFPrediction;
}


class bfl::PFPrediction
{
public:
    virtual ~PFPrediction() noexcept { };

    virtual void predict(const Eigen::Ref<const Eigen::MatrixXf>& prev_state, Eigen::Ref<Eigen::MatrixXf> pred_state) = 0;

    virtual StateModel& getStateModel() = 0;
};

#endif /* PFPREDICTION_H */
