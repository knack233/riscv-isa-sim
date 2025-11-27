//vfslide1down.vf vd, vs2, rs1
VI_CHECK_SLIDE(false);

#ifndef CPU_NANHU
VI_VFP_LOOP_BASE
#else
VI_VFP_LOOP_BASE(1)
if (0 == P.VU.vta && i >= vl) { \
  continue; \
} \
if ((true == skip && 1 == P.VU.vma && i < vl) || (1 == P.VU.vta && i >= vl)) \
  mata_action = 2; \
else \
  mata_action = 1; \

#endif
if (i != vl - 1) {
  switch (P.VU.vsew) {
    case e16: {
      VI_XI_SLIDEDOWN_PARAMS(e16, 1);
#ifndef CPU_NANHU
      vd = vs2;
#else
      if (1 == mata_action) \
        vd = vs2;
      else \
        *((type_sew_t<e16>::type *)&vd)  = vector_agnostic(*((type_sew_t<e16>::type *)&vd)); \

#endif
    }
    break;
    case e32: {
      VI_XI_SLIDEDOWN_PARAMS(e32, 1);
#ifndef CPU_NANHU
      vd = vs2;
#else
      if (1 == mata_action) \
        vd = vs2;
      else \
        *((type_sew_t<e32>::type *)&vd)  = vector_agnostic(*((type_sew_t<e32>::type *)&vd)); \

#endif
    }
    break;
    case e64: {
      VI_XI_SLIDEDOWN_PARAMS(e64, 1);
#ifndef CPU_NANHU
      vd = vs2;
#else
      if (1 == mata_action) \
        vd = vs2;
      else \
        *((type_sew_t<e64>::type *)&vd)  = vector_agnostic(*((type_sew_t<e64>::type *)&vd)); \

#endif
    }
    break;
  }
} else {
  switch (P.VU.vsew) {
    case e16:
#ifndef CPU_NANHU
      P.VU.elt<float16_t>(rd_num, vl - 1, true) = P.VU.altfmt ? FRS1_BF : FRS1_H;
#else
      if (1 == mata_action) \
        P.VU.elt<float16_t>(rd_num, vl - 1, true) = P.VU.altfmt ? FRS1_BF : FRS1_H;\
      else \
        P.VU.elt<type_sew_t<e16>::type>(rd_num, vl - 1, true)  = vector_agnostic(P.VU.elt<type_sew_t<e16>::type>(rd_num, vl - 1, false)); \

#endif
      break;
    case e32:
#ifndef CPU_NANHU
      P.VU.elt<float32_t>(rd_num, vl - 1, true) = FRS1_F;
#else
      if (1 == mata_action) \
        P.VU.elt<float32_t>(rd_num, vl - 1, true) = FRS1_F;
      else \
        P.VU.elt<type_sew_t<e32>::type>(rd_num, vl - 1, true)  = vector_agnostic(P.VU.elt<type_sew_t<e32>::type>(rd_num, vl - 1, false)); \

#endif
      break;
    case e64:
#ifndef CPU_NANHU
      P.VU.elt<float64_t>(rd_num, vl - 1, true) = FRS1_D;
#else
      if (1 == mata_action) \
        P.VU.elt<float64_t>(rd_num, vl - 1, true) = FRS1_D;
      else \
        P.VU.elt<type_sew_t<e64>::type>(rd_num, vl - 1, true)  = vector_agnostic(P.VU.elt<type_sew_t<e64>::type>(rd_num, vl - 1, false)); \

#endif
      break;
  }
}
VI_VFP_LOOP_END
