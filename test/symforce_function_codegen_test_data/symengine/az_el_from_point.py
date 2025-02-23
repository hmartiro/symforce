# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     python_templates/function/FUNCTION.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import math  # pylint: disable=unused-import
import numpy  # pylint: disable=unused-import
import typing as T  # pylint: disable=unused-import

import sym  # pylint: disable=unused-import


# pylint: disable=too-many-locals,too-many-lines,too-many-statements,unused-argument


def az_el_from_point(nav_T_cam, nav_t_point, epsilon):
    # type: (sym.Pose3, T.Sequence[float], float) -> T.List[float]
    """
    Transform a nav point into azimuth / elevation angles in the
    camera frame.

    Args:
        nav_T_cam (geo.Pose3): camera pose in the world
        nav_t_point (geo.Matrix): nav point
        epsilon (Scalar): small number to avoid singularities

    Returns:
        geo.Matrix: (azimuth, elevation)
    """

    # Total ops: 77

    # Input arrays
    _nav_T_cam = nav_T_cam.data

    # Intermediate terms (23)
    _tmp0 = 2 * _nav_T_cam[0]
    _tmp1 = _nav_T_cam[3] * _tmp0
    _tmp2 = 2 * _nav_T_cam[1]
    _tmp3 = _nav_T_cam[2] * _tmp2
    _tmp4 = _tmp1 + _tmp3
    _tmp5 = -2 * _nav_T_cam[0] ** 2
    _tmp6 = 1 - 2 * _nav_T_cam[2] ** 2
    _tmp7 = _tmp5 + _tmp6
    _tmp8 = _nav_T_cam[1] * _tmp0
    _tmp9 = 2 * _nav_T_cam[2] * _nav_T_cam[3]
    _tmp10 = _tmp8 - _tmp9
    _tmp11 = (
        -_nav_T_cam[4] * _tmp10
        - _nav_T_cam[5] * _tmp7
        - _nav_T_cam[6] * _tmp4
        + _tmp10 * nav_t_point[0]
        + _tmp4 * nav_t_point[2]
        + _tmp7 * nav_t_point[1]
    )
    _tmp12 = -2 * _nav_T_cam[1] ** 2
    _tmp13 = _tmp12 + _tmp6
    _tmp14 = _tmp8 + _tmp9
    _tmp15 = _nav_T_cam[3] * _tmp2
    _tmp16 = _nav_T_cam[2] * _tmp0
    _tmp17 = -_tmp15 + _tmp16
    _tmp18 = (
        -_nav_T_cam[4] * _tmp13
        - _nav_T_cam[5] * _tmp14
        - _nav_T_cam[6] * _tmp17
        + _tmp13 * nav_t_point[0]
        + _tmp14 * nav_t_point[1]
        + _tmp17 * nav_t_point[2]
    )
    _tmp19 = -_tmp1 + _tmp3
    _tmp20 = _tmp12 + _tmp5 + 1
    _tmp21 = _tmp15 + _tmp16
    _tmp22 = (
        -_nav_T_cam[4] * _tmp21
        - _nav_T_cam[5] * _tmp19
        - _nav_T_cam[6] * _tmp20
        + _tmp19 * nav_t_point[1]
        + _tmp20 * nav_t_point[2]
        + _tmp21 * nav_t_point[0]
    )

    # Output terms
    _res = [0.0] * 2
    _res[0] = math.atan2(
        _tmp11, _tmp18 + epsilon * ((0.0 if _tmp18 == 0 else math.copysign(1, _tmp18)) + 0.5)
    )
    _res[1] = (
        -math.acos(_tmp22 / (epsilon + math.sqrt(_tmp11 ** 2 + _tmp18 ** 2 + _tmp22 ** 2)))
        + (1.0 / 2.0) * math.pi
    )
    return _res
