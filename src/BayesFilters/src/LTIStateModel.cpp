#include <BayesFilters/LTIStateModel.h>

#include <Eigen/Dense>

using namespace bfl;
using namespace Eigen;


LTIStateModel::LTIStateModel(Eigen::MatrixXf& transition_matrix,
                             Eigen::MatrixXf& noise_covariance_matrix) :
    F_(transition_matrix), Q_(noise_covariance_matrix)
{
    if ((F_.rows() == 0) || (F_.cols() == 0))
        throw std::runtime_error("ERROR::LTISTATEMODEL::CTOR\nERROR:\n\tState transition matrix dimensions cannot be 0.");
    else if ((Q_.rows() == 0) || (Q_.cols() == 0))
        throw std::runtime_error("ERROR::LTISTATEMODEL::CTOR\nERROR:\n\tNoise covariance matrix dimensions cannot be 0.");
    else if (F_.rows() != F_.cols())
        throw std::runtime_error("ERROR::LTISTATEMODEL::CTOR\nERROR:\n\tState transition matrix must be a square matrix.");
    else if (Q_.rows() != Q_.cols())
        throw std::runtime_error("ERROR::LTISTATEMODEL::CTOR\nERROR:\n\tNoise covariance matrix must be a square matrix.");
    else if (F_.rows() != Q_.rows())
        throw std::runtime_error("ERROR::LTISTATEMODEL::CTOR\nERROR:\n\tNumber of rows of the state transition matrix must be the same as the size of the noise covariance matrix.");
}


void LTIStateModel::propagate(const Eigen::Ref<const Eigen::MatrixXf>& cur_states,
                              Eigen::Ref<Eigen::MatrixXf> prop_states)
{
    prop_states = F_ * cur_states;
}


Eigen::MatrixXf LTIStateModel::getNoiseCovarianceMatrix()
{
    return Q_;
}


Eigen::MatrixXf LTIStateModel::getStateTransitionMatrix()
{
    return F_;
}


bool LTIStateModel::setProperty(const std::string& property)
{
    return false;
}


Eigen::MatrixXf LTIStateModel::getJacobian()
{
    return F_;
}
