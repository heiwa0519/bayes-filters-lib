#ifndef PFCORRECTIONDECORATOR_H
#define PFCORRECTIONDECORATOR_H

#include <BayesFilters/PFCorrection.h>

#include <memory>

namespace bfl {
    class PFCorrectionDecorator;
}


class bfl::PFCorrectionDecorator : public PFCorrection
{
public:
    std::pair<bool, Eigen::VectorXf> getLikelihood() override;

protected:
    PFCorrectionDecorator(std::unique_ptr<PFCorrection> correction) noexcept;

    PFCorrectionDecorator(PFCorrectionDecorator&& correction) noexcept;

    virtual ~PFCorrectionDecorator() noexcept;

    void correctStep(const Eigen::Ref<const Eigen::MatrixXf>& pred_states, const Eigen::Ref<const Eigen::VectorXf>& pred_weights,
                     Eigen::Ref<Eigen::MatrixXf> cor_states, Eigen::Ref<Eigen::VectorXf> cor_weights) override;

private:
    std::unique_ptr<PFCorrection> correction_;
};

#endif /* PFCORRECTIONDECORATOR_H */
