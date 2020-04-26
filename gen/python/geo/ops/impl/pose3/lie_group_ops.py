import numpy


class LieGroupOps(object):
    """
    Python LieGroupOps implementatino for <class 'symforce.geo.pose3.Pose3'>.
    """

    @staticmethod
    def from_tangent(vec, epsilon):
        # Input arrays

        # Output array
        res = [0.] * 7

        # Intermediate terms (19)
        _tmp0 = vec[2]**2
        _tmp1 = vec[1]**2
        _tmp2 = vec[0]**2
        _tmp3 = _tmp0 + _tmp1 + _tmp2 + epsilon**2
        _tmp4 = numpy.sqrt(_tmp3)
        _tmp5 = (1./2.)*_tmp4
        _tmp6 = numpy.sin(_tmp5)/_tmp4
        _tmp7 = (_tmp4 - numpy.sin(_tmp4))/_tmp3**(3./2.)
        _tmp8 = _tmp7*vec[0]*vec[2]
        _tmp9 = (1 - numpy.cos(_tmp4))/_tmp3
        _tmp10 = _tmp9*vec[1]
        _tmp11 = _tmp7*vec[1]
        _tmp12 = _tmp11*vec[0]
        _tmp13 = _tmp9*vec[2]
        _tmp14 = -_tmp1
        _tmp15 = -_tmp0
        _tmp16 = _tmp11*vec[2]
        _tmp17 = _tmp9*vec[0]
        _tmp18 = -_tmp2

        # Output terms (7)
        res[0] = _tmp6*vec[0]
        res[1] = _tmp6*vec[1]
        res[2] = _tmp6*vec[2]
        res[3] = numpy.cos(_tmp5)
        res[4] = vec[3]*(_tmp7*(_tmp14 + _tmp15) + 1) + vec[4]*(_tmp12 - _tmp13) + vec[5]*(_tmp10 + _tmp8)
        res[5] = vec[3]*(_tmp12 + _tmp13) + vec[4]*(_tmp7*(_tmp15 + _tmp18) + 1) + vec[5]*(_tmp16 - _tmp17)
        res[6] = vec[3]*(-_tmp10 + _tmp8) + vec[4]*(_tmp16 + _tmp17) + vec[5]*(_tmp7*(_tmp14 + _tmp18) + 1)

        return res

    @staticmethod
    def to_tangent(a, epsilon):
        # Input arrays
        _a = a.data

        # Output array
        res = [0.] * 6

        # Intermediate terms (25)
        _tmp0 = numpy.arccos(numpy.amax((-1,numpy.amin((1,_a[3])))))
        _tmp1 = numpy.amax((epsilon,1 - _a[3]**2))
        _tmp2 = 1/numpy.sqrt(_tmp1)
        _tmp3 = 2*_tmp0*_tmp2
        _tmp4 = _tmp0*_tmp2
        _tmp5 = _a[2]*_tmp4
        _tmp6 = 4*_tmp0**2/_tmp1
        _tmp7 = _a[1]**2*_tmp6
        _tmp8 = _a[0]**2*_tmp6
        _tmp9 = _a[2]**2*_tmp6
        _tmp10 = _tmp7 + _tmp8 + _tmp9 + epsilon
        _tmp11 = numpy.sqrt(_tmp10)
        _tmp12 = 0.5*_tmp11
        _tmp13 = (-1./2.*_tmp11*numpy.cos(_tmp12)/numpy.sin(_tmp12) + 1)/_tmp10
        _tmp14 = _a[0]*_tmp13*_tmp6
        _tmp15 = _a[1]*_tmp14
        _tmp16 = 1.0*_tmp5
        _tmp17 = _a[2]*_tmp14
        _tmp18 = 1.0*_tmp4
        _tmp19 = _a[1]*_tmp18
        _tmp20 = -_tmp7
        _tmp21 = -_tmp9
        _tmp22 = _a[1]*_a[2]*_tmp13*_tmp6
        _tmp23 = _a[0]*_tmp18
        _tmp24 = -_tmp8

        # Output terms (6)
        res[0] = _a[0]*_tmp3
        res[1] = _a[1]*_tmp3
        res[2] = 2*_tmp5
        res[3] = _a[4]*(_tmp13*(_tmp20 + _tmp21) + 1.0) + _a[5]*(_tmp15 + _tmp16) + _a[6]*(_tmp17 - _tmp19)
        res[4] = _a[4]*(_tmp15 - _tmp16) + _a[5]*(_tmp13*(_tmp21 + _tmp24) + 1.0) + _a[6]*(_tmp22 + _tmp23)
        res[5] = _a[4]*(_tmp17 + _tmp19) + _a[5]*(_tmp22 - _tmp23) + _a[6]*(_tmp13*(_tmp20 + _tmp24) + 1.0)

        return res

    @staticmethod
    def retract(a, vec, epsilon):
        # Input arrays
        _a = a.data

        # Output array
        res = [0.] * 7

        # Intermediate terms (39)
        _tmp0 = vec[2]**2
        _tmp1 = vec[1]**2
        _tmp2 = vec[0]**2
        _tmp3 = _tmp0 + _tmp1 + _tmp2 + epsilon**2
        _tmp4 = numpy.sqrt(_tmp3)
        _tmp5 = (1./2.)*_tmp4
        _tmp6 = numpy.sin(_tmp5)/_tmp4
        _tmp7 = _a[1]*_tmp6
        _tmp8 = _a[2]*_tmp6
        _tmp9 = _tmp6*vec[0]
        _tmp10 = numpy.cos(_tmp5)
        _tmp11 = _tmp6*vec[2]
        _tmp12 = _tmp6*vec[1]
        _tmp13 = 2*_a[2]
        _tmp14 = _a[3]*_tmp13
        _tmp15 = 2*_a[0]*_a[1]
        _tmp16 = (_tmp4 - numpy.sin(_tmp4))/_tmp3**(3./2.)
        _tmp17 = _tmp16*vec[1]
        _tmp18 = _tmp17*vec[2]
        _tmp19 = (1 - numpy.cos(_tmp4))/_tmp3
        _tmp20 = _tmp19*vec[0]
        _tmp21 = -_tmp2
        _tmp22 = -_tmp0
        _tmp23 = _tmp17*vec[0]
        _tmp24 = _tmp19*vec[2]
        _tmp25 = vec[3]*(_tmp23 + _tmp24) + vec[4]*(_tmp16*(_tmp21 + _tmp22) + 1) + vec[5]*(_tmp18 - _tmp20)
        _tmp26 = -2*_a[2]**2
        _tmp27 = 1 - 2*_a[1]**2
        _tmp28 = _tmp16*vec[0]*vec[2]
        _tmp29 = _tmp19*vec[1]
        _tmp30 = -_tmp1
        _tmp31 = vec[3]*(_tmp16*(_tmp22 + _tmp30) + 1) + vec[4]*(_tmp23 - _tmp24) + vec[5]*(_tmp28 + _tmp29)
        _tmp32 = 2*_a[3]
        _tmp33 = _a[1]*_tmp32
        _tmp34 = _a[0]*_tmp13
        _tmp35 = vec[3]*(_tmp28 - _tmp29) + vec[4]*(_tmp18 + _tmp20) + vec[5]*(_tmp16*(_tmp21 + _tmp30) + 1)
        _tmp36 = -2*_a[0]**2
        _tmp37 = _a[0]*_tmp32
        _tmp38 = _a[1]*_tmp13

        # Output terms (7)
        res[0] = _a[0]*_tmp10 + _a[3]*_tmp9 + _tmp7*vec[2] - _tmp8*vec[1]
        res[1] = -_a[0]*_tmp11 + _a[1]*_tmp10 + _a[3]*_tmp12 + _tmp8*vec[0]
        res[2] = _a[0]*_tmp12 + _a[2]*_tmp10 + _a[3]*_tmp11 - _tmp7*vec[0]
        res[3] = -_a[0]*_tmp9 - _a[1]*_tmp12 - _a[2]*_tmp11 + _a[3]*_tmp10
        res[4] = _a[4] + _tmp25*(-_tmp14 + _tmp15) + _tmp31*(_tmp26 + _tmp27) + _tmp35*(_tmp33 + _tmp34)
        res[5] = _a[5] + _tmp25*(_tmp26 + _tmp36 + 1) + _tmp31*(_tmp14 + _tmp15) + _tmp35*(-_tmp37 + _tmp38)
        res[6] = _a[6] + _tmp25*(_tmp37 + _tmp38) + _tmp31*(-_tmp33 + _tmp34) + _tmp35*(_tmp27 + _tmp36)

        return res

    @staticmethod
    def local_coordinates(a, b, epsilon):
        # Input arrays
        _a = a.data
        _b = b.data

        # Output array
        res = [0.] * 6

        # Intermediate terms (51)
        _tmp0 = -_a[0]*_b[3] - _a[1]*_b[2] + _a[2]*_b[1] + _a[3]*_b[0]
        _tmp1 = _a[0]*_b[0] + _a[1]*_b[1] + _a[2]*_b[2] + _a[3]*_b[3]
        _tmp2 = numpy.arccos(numpy.amax((-1,numpy.amin((1,_tmp1)))))
        _tmp3 = numpy.amax((epsilon,1 - _tmp1**2))
        _tmp4 = 1/numpy.sqrt(_tmp3)
        _tmp5 = _tmp2*_tmp4
        _tmp6 = 2*_tmp5
        _tmp7 = _a[0]*_b[2] - _a[1]*_b[3] - _a[2]*_b[0] + _a[3]*_b[1]
        _tmp8 = -_a[0]*_b[1] + _a[1]*_b[0] - _a[2]*_b[3] + _a[3]*_b[2]
        _tmp9 = 4*_tmp2**2/_tmp3
        _tmp10 = _tmp7**2*_tmp9
        _tmp11 = _tmp8**2*_tmp9
        _tmp12 = _tmp0**2*_tmp9
        _tmp13 = _tmp10 + _tmp11 + _tmp12 + epsilon
        _tmp14 = numpy.sqrt(_tmp13)
        _tmp15 = 0.5*_tmp14
        _tmp16 = (-1./2.*_tmp14*numpy.cos(_tmp15)/numpy.sin(_tmp15) + 1)/_tmp13
        _tmp17 = _tmp0*_tmp16*_tmp8*_tmp9
        _tmp18 = 1.0*_tmp5
        _tmp19 = _tmp18*_tmp7
        _tmp20 = -2*_a[1]**2
        _tmp21 = 1 - 2*_a[0]**2
        _tmp22 = _tmp20 + _tmp21
        _tmp23 = 2*_a[3]
        _tmp24 = _a[0]*_tmp23
        _tmp25 = 2*_a[1]*_a[2]
        _tmp26 = -_tmp24 + _tmp25
        _tmp27 = _a[1]*_tmp23
        _tmp28 = 2*_a[0]
        _tmp29 = _a[2]*_tmp28
        _tmp30 = _tmp27 + _tmp29
        _tmp31 = -_a[4]*_tmp30 - _a[5]*_tmp26 - _a[6]*_tmp22 + _b[4]*_tmp30 + _b[5]*_tmp26 + _b[6]*_tmp22
        _tmp32 = -_tmp10
        _tmp33 = -_tmp11
        _tmp34 = -_tmp27 + _tmp29
        _tmp35 = _a[2]*_tmp23
        _tmp36 = _a[1]*_tmp28
        _tmp37 = _tmp35 + _tmp36
        _tmp38 = -2*_a[2]**2
        _tmp39 = _tmp20 + _tmp38 + 1
        _tmp40 = -_a[4]*_tmp39 - _a[5]*_tmp37 - _a[6]*_tmp34 + _b[4]*_tmp39 + _b[5]*_tmp37 + _b[6]*_tmp34
        _tmp41 = _tmp16*_tmp7*_tmp9
        _tmp42 = _tmp0*_tmp41
        _tmp43 = 1.0*_tmp2*_tmp4*_tmp8
        _tmp44 = _tmp21 + _tmp38
        _tmp45 = -_tmp35 + _tmp36
        _tmp46 = _tmp24 + _tmp25
        _tmp47 = -_a[4]*_tmp45 - _a[5]*_tmp44 - _a[6]*_tmp46 + _b[4]*_tmp45 + _b[5]*_tmp44 + _b[6]*_tmp46
        _tmp48 = _tmp41*_tmp8
        _tmp49 = _tmp0*_tmp18
        _tmp50 = -_tmp12

        # Output terms (6)
        res[0] = _tmp0*_tmp6
        res[1] = _tmp6*_tmp7
        res[2] = _tmp6*_tmp8
        res[3] = _tmp31*(_tmp17 - _tmp19) + _tmp40*(_tmp16*(_tmp32 + _tmp33) + 1.0) + _tmp47*(_tmp42 + _tmp43)
        res[4] = _tmp31*(_tmp48 + _tmp49) + _tmp40*(_tmp42 - _tmp43) + _tmp47*(_tmp16*(_tmp33 + _tmp50) + 1.0)
        res[5] = _tmp31*(_tmp16*(_tmp32 + _tmp50) + 1.0) + _tmp40*(_tmp17 + _tmp19) + _tmp47*(_tmp48 - _tmp49)

        return res

