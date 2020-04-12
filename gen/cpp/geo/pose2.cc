//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./pose2.h"

// Explicit instantiation
template class geo::Pose2<double>;
template class geo::Pose2<float>;

// Print implementations
std::ostream& operator<<(std::ostream& os, const geo::Pose2d& a) {
    const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
    os << "<Pose2d " << a.Storage().transpose().format(fmt) << ">";
    return os;
}
std::ostream& operator<<(std::ostream& os, const geo::Pose2f& a) {
    const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
    os << "<Pose2f " << a.Storage().transpose().format(fmt) << ">";
    return os;
}


// Concept implementations for this class
#include "./ops/impl/pose2/storage_ops.cc"
#include "./ops/impl/pose2/group_ops.cc"
#include "./ops/impl/pose2/lie_group_ops.cc"
