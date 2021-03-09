//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
//
// Instead modify:
//     symforce/codegen/cpp_templates/example/cam_package_cpp_test.cc.jinja
//
// And then run `symforce_cam_codegen_test --update`.
// -----------------------------------------------------------------------------
/**
 * Tests for C++ camera types. Mostly checking all the templates compile since
 * the math is tested comprehensively in symbolic form.
 */

#include <iostream>
#include <random>

#include <Eigen/Dense>
#include <sym/atan_camera_cal.h>
#include <sym/camera.h>
#include <sym/equidistant_epipolar_camera_cal.h>
#include <sym/linear_camera_cal.h>
#include <sym/pose3.h>
#include <sym/posed_camera.h>
#include <sym/rot3.h>
#include <symforce/util/random.h>

// TODO(hayk): Use the catch unit testing framework (single header).
#define assertTrue(a)                                      \
  if (!(a)) {                                              \
    std::ostringstream o;                                  \
    o << __FILE__ << ":" << __LINE__ << ": Test failure."; \
    throw std::runtime_error(o.str());                     \
  }

template <typename Scalar>
std::vector<sym::LinearCameraCal<Scalar>> GetCamCalsLinearCameraCal() {
  std::vector<sym::LinearCameraCal<Scalar>> cam_cals;

  Eigen::Matrix<Scalar, 4, 1> data1;
  data1 << 90, 90, 60, 80;
  cam_cals.push_back(sym::LinearCameraCal<Scalar>(data1));

  Eigen::Matrix<Scalar, 4, 1> data2;
  data2 << 380, 380, 320, 240;
  cam_cals.push_back(sym::LinearCameraCal<Scalar>(data2));

  Eigen::Matrix<Scalar, 4, 1> data3;
  data3 << 500, 500, 1000, 800;
  cam_cals.push_back(sym::LinearCameraCal<Scalar>(data3));

  return cam_cals;
}

template <typename Scalar>
std::vector<sym::EquidistantEpipolarCameraCal<Scalar>> GetCamCalsEquidistantEpipolarCameraCal() {
  std::vector<sym::EquidistantEpipolarCameraCal<Scalar>> cam_cals;

  Eigen::Matrix<Scalar, 4, 1> data1;
  data1 << 90, 90, 60, 80;
  cam_cals.push_back(sym::EquidistantEpipolarCameraCal<Scalar>(data1));

  Eigen::Matrix<Scalar, 4, 1> data2;
  data2 << 380, 380, 320, 240;
  cam_cals.push_back(sym::EquidistantEpipolarCameraCal<Scalar>(data2));

  Eigen::Matrix<Scalar, 4, 1> data3;
  data3 << 500, 500, 1000, 800;
  cam_cals.push_back(sym::EquidistantEpipolarCameraCal<Scalar>(data3));

  return cam_cals;
}

template <typename Scalar>
std::vector<sym::ATANCameraCal<Scalar>> GetCamCalsATANCameraCal() {
  std::vector<sym::ATANCameraCal<Scalar>> cam_cals;

  Eigen::Matrix<Scalar, 5, 1> data1;
  data1 << 90, 90, 60, 80, 0.68;
  cam_cals.push_back(sym::ATANCameraCal<Scalar>(data1));

  Eigen::Matrix<Scalar, 5, 1> data2;
  data2 << 380, 380, 320, 240, 0.35;
  cam_cals.push_back(sym::ATANCameraCal<Scalar>(data2));

  Eigen::Matrix<Scalar, 5, 1> data3;
  data3 << 500, 500, 1000, 800, 0.21;
  cam_cals.push_back(sym::ATANCameraCal<Scalar>(data3));

  return cam_cals;
}

template <typename T>
void TestStorageOps(const T& cam_cal) {
  using Scalar = typename T::Scalar;

  std::cout << "*** Testing StorageOps: " << cam_cal << " ***" << std::endl;

  constexpr int32_t storage_dim = sym::StorageOps<T>::StorageDim();
  assertTrue(cam_cal.Data().rows() == storage_dim);
  assertTrue(cam_cal.Data().cols() == 1);

  std::array<Scalar, storage_dim> arr;
  cam_cal.ToStorage(arr.data());
  for (int i = 0; i < arr.size(); ++i) {
    assertTrue(arr[i] == cam_cal.Data()[i]);
  }

  const T cam_cal2 = sym::StorageOps<T>::FromStorage(arr.data());
  assertTrue(cam_cal.Data() == cam_cal2.Data());
  arr[0] = 2.1;
  const T cam_cal3 = sym::StorageOps<T>::FromStorage(arr.data());
  assertTrue(cam_cal.Data() != cam_cal3.Data());
}

template <typename T>
void TestProjectDeproject(const T& cam_cal) {
  using Scalar = typename T::Scalar;
  const Scalar epsilon = 1e-6;  // For preventing degenerate numerical cases (e.g. division by zero)
  const Scalar tolerance = 10.0 * epsilon;  // For checking approx. equality

  std::cout << "*** Testing projection model: " << cam_cal << " ***" << std::endl;

  std::mt19937 gen(42);
  // Generate pixels around principal point
  std::uniform_real_distribution<Scalar> pixel_x_dist(0.0, 2.0 * cam_cal.Data()[2]);
  std::uniform_real_distribution<Scalar> pixel_y_dist(0.0, 2.0 * cam_cal.Data()[3]);
  for (int i = 0; i < 10; i++) {
    Eigen::Matrix<Scalar, 2, 1> pixel;
    pixel << pixel_x_dist(gen), pixel_y_dist(gen);

    Scalar is_valid_camera_ray;
    Scalar is_valid_pixel;
    const Eigen::Matrix<Scalar, 3, 1> camera_ray =
        cam_cal.CameraRayFromPixel(pixel, epsilon, &is_valid_camera_ray);
    const Eigen::Matrix<Scalar, 2, 1> pixel_reprojected =
        cam_cal.PixelFromCameraPoint(camera_ray, epsilon, &is_valid_pixel);
    if (is_valid_camera_ray == 1 && is_valid_pixel == 1) {
      assertTrue(pixel.isApprox(pixel_reprojected, tolerance));
    }
  }
}

template <typename T>
void TestCamera(const T& cam_cal) {
  using Scalar = typename T::Scalar;
  const Scalar epsilon = 1e-6;  // For preventing degenerate numerical cases (e.g. division by zero)
  const Scalar tolerance = 10.0 * epsilon;  // For checking approx. equality

  std::cout << "*** Testing Camera class with calibration: " << cam_cal << " ***" << std::endl;

  // Assume the principal point is at the center of the image
  Eigen::Matrix<int, 2, 1> image_size;
  image_size << int(2.0 * cam_cal.Data()[2]), int(2.0 * cam_cal.Data()[3]);

  const sym::Camera<T> cam(cam_cal, image_size);
  Scalar is_valid;

  assertTrue(cam.Calibration() == cam_cal);
  assertTrue(cam.ImageSize() == image_size);

  assertTrue(cam.FocalLength() == cam_cal.FocalLength());
  assertTrue(cam.PrincipalPoint() == cam_cal.PrincipalPoint());
  const auto focal_length_expected = cam_cal.Data().template head<2>();
  assertTrue(cam.FocalLength() == focal_length_expected);
  const auto principal_point_expected = cam_cal.Data().template segment<2>(2);
  assertTrue(cam.PrincipalPoint() == principal_point_expected);

  // Check a pixel that's out of the image
  Eigen::Matrix<Scalar, 2, 1> invalid_pixel;
  invalid_pixel << -1, -1;
  cam.CameraRayFromPixel(invalid_pixel, epsilon, &is_valid);
  assertTrue(is_valid == 0);
  assertTrue(cam.MaybeCheckInView(invalid_pixel) == 0);
  assertTrue(sym::Camera<T>::InView(invalid_pixel, image_size) == 0);

  // Check a point that's at the center of the image
  Eigen::Matrix<Scalar, 2, 1> valid_pixel;
  valid_pixel << image_size[0] / 2.0, image_size[1] / 2.0;
  const Eigen::Matrix<Scalar, 3, 1> valid_camera_point =
      cam.CameraRayFromPixel(valid_pixel, epsilon, &is_valid);
  assertTrue(is_valid == 1);
  assertTrue(cam.MaybeCheckInView(valid_pixel) == 1);
  assertTrue(sym::Camera<T>::InView(valid_pixel, image_size) == 1);

  // Project a point into the camera and check validity
  cam.PixelFromCameraPoint(valid_camera_point, epsilon, &is_valid);
  assertTrue(is_valid == 1);
}

template <typename T>
void TestPosedCamera(const T& cam_cal) {
  using Scalar = typename T::Scalar;
  const Scalar epsilon = 1e-6;  // For preventing degenerate numerical cases (e.g. division by zero)
  const Scalar tolerance = 10.0 * epsilon;  // For assessing approximate equality

  std::cout << "*** Testing PosedCamera class with calibration: " << cam_cal << " ***" << std::endl;

  std::mt19937 gen(42);
  // Generate pixels around principal point
  std::uniform_real_distribution<Scalar> pixel_x_dist(0.0, 2.0 * cam_cal.Data()[2]);
  std::uniform_real_distribution<Scalar> pixel_y_dist(0.0, 2.0 * cam_cal.Data()[3]);
  std::uniform_real_distribution<Scalar> range_dist(1.0, 5.0);
  for (int i = 0; i < 10; i++) {
    const sym::Pose3<Scalar> pose = sym::Random<sym::Pose3<Scalar>>(gen);
    const sym::PosedCamera<T> cam(pose, cam_cal);

    assertTrue(cam.Pose() == pose);

    Eigen::Matrix<Scalar, 2, 1> pixel;
    pixel << pixel_x_dist(gen), pixel_y_dist(gen);
    const Scalar range_to_point = range_dist(gen);

    Scalar is_valid_global_point;
    Scalar is_valid_pixel;
    const Eigen::Matrix<Scalar, 3, 1> global_point =
        cam.GlobalPointFromPixel(pixel, range_to_point, epsilon, &is_valid_global_point);
    const Eigen::Matrix<Scalar, 2, 1> pixel_reprojected =
        cam.PixelFromGlobalPoint(global_point, epsilon, &is_valid_pixel);
    if (is_valid_global_point == 1 && is_valid_pixel == 1) {
      assertTrue(pixel.isApprox(pixel_reprojected, tolerance));
    }

    const sym::Pose3<Scalar> pose2 = sym::Random<sym::Pose3<Scalar>>(gen);
    const sym::PosedCamera<T> cam2(pose2, cam_cal);
    Scalar is_valid_warped_pixel;
    const Scalar inverse_range = 1 / (range_to_point + epsilon);
    const Eigen::Matrix<Scalar, 2, 1> warped_pixel =
        cam.WarpPixel(pixel, inverse_range, cam2, epsilon, &is_valid_warped_pixel);
    const Scalar range2 = (cam2.Pose().Inverse() * global_point).norm();
    const Scalar inverse_range2 = 1 / (range2 + epsilon);
    Scalar is_valid_rewarped_pixel;
    const Eigen::Matrix<Scalar, 2, 1> rewarped_pixel =
        cam2.WarpPixel(warped_pixel, inverse_range2, cam, epsilon, &is_valid_rewarped_pixel);
    if (is_valid_warped_pixel == 1 && is_valid_rewarped_pixel == 1) {
      assertTrue(pixel.isApprox(rewarped_pixel, std::sqrt(epsilon)));
    }
  }
}

int main(int argc, char** argv) {
  std::vector<sym::LinearCameraCal<double>> cam_cals_LinearCameraCal_double =
      GetCamCalsLinearCameraCal<double>();
  for (auto cam_cal : cam_cals_LinearCameraCal_double) {
    TestStorageOps<sym::LinearCameraCal<double>>(cam_cal);
    TestProjectDeproject<sym::LinearCameraCal<double>>(cam_cal);
    TestCamera<sym::LinearCameraCal<double>>(cam_cal);
    TestPosedCamera<sym::LinearCameraCal<double>>(cam_cal);
  }

  std::vector<sym::EquidistantEpipolarCameraCal<double>>
      cam_cals_EquidistantEpipolarCameraCal_double =
          GetCamCalsEquidistantEpipolarCameraCal<double>();
  for (auto cam_cal : cam_cals_EquidistantEpipolarCameraCal_double) {
    TestStorageOps<sym::EquidistantEpipolarCameraCal<double>>(cam_cal);
    TestProjectDeproject<sym::EquidistantEpipolarCameraCal<double>>(cam_cal);
    TestCamera<sym::EquidistantEpipolarCameraCal<double>>(cam_cal);
    TestPosedCamera<sym::EquidistantEpipolarCameraCal<double>>(cam_cal);
  }

  std::vector<sym::ATANCameraCal<double>> cam_cals_ATANCameraCal_double =
      GetCamCalsATANCameraCal<double>();
  for (auto cam_cal : cam_cals_ATANCameraCal_double) {
    TestStorageOps<sym::ATANCameraCal<double>>(cam_cal);
    TestProjectDeproject<sym::ATANCameraCal<double>>(cam_cal);
    TestCamera<sym::ATANCameraCal<double>>(cam_cal);
    TestPosedCamera<sym::ATANCameraCal<double>>(cam_cal);
  }

  std::vector<sym::LinearCameraCal<float>> cam_cals_LinearCameraCal_float =
      GetCamCalsLinearCameraCal<float>();
  for (auto cam_cal : cam_cals_LinearCameraCal_float) {
    TestStorageOps<sym::LinearCameraCal<float>>(cam_cal);
    TestProjectDeproject<sym::LinearCameraCal<float>>(cam_cal);
    TestCamera<sym::LinearCameraCal<float>>(cam_cal);
    TestPosedCamera<sym::LinearCameraCal<float>>(cam_cal);
  }

  std::vector<sym::EquidistantEpipolarCameraCal<float>>
      cam_cals_EquidistantEpipolarCameraCal_float = GetCamCalsEquidistantEpipolarCameraCal<float>();
  for (auto cam_cal : cam_cals_EquidistantEpipolarCameraCal_float) {
    TestStorageOps<sym::EquidistantEpipolarCameraCal<float>>(cam_cal);
    TestProjectDeproject<sym::EquidistantEpipolarCameraCal<float>>(cam_cal);
    TestCamera<sym::EquidistantEpipolarCameraCal<float>>(cam_cal);
    TestPosedCamera<sym::EquidistantEpipolarCameraCal<float>>(cam_cal);
  }

  std::vector<sym::ATANCameraCal<float>> cam_cals_ATANCameraCal_float =
      GetCamCalsATANCameraCal<float>();
  for (auto cam_cal : cam_cals_ATANCameraCal_float) {
    TestStorageOps<sym::ATANCameraCal<float>>(cam_cal);
    TestProjectDeproject<sym::ATANCameraCal<float>>(cam_cal);
    TestCamera<sym::ATANCameraCal<float>>(cam_cal);
    TestPosedCamera<sym::ATANCameraCal<float>>(cam_cal);
  }
}
