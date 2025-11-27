//vslide1down.vx vd, vs2, rs1
VI_CHECK_SLIDE(false);

#ifndef CPU_NANHU
VI_LOOP_BASE
#else
VI_LOOP_BASE(1)
if (0 == P.VU.vta && i >= vl) { \
  continue; \
} \
if ((true == skip && 1 == P.VU.vma && i < vl) || (1 == P.VU.vta && i >= vl)) \
  mata_action = 2; \
else \
  mata_action = 1;
#endif
if (i != vl - 1) {
  switch (sew) {
  case e8: {
    VI_XI_SLIDEDOWN_PARAMS(e8, 1);
#ifndef CPU_NANHU
    vd = vs2;
#else
  if (1 == mata_action) \
    vd = vs2; \
  else \
    vd = vector_agnostic(vd);
#endif
  }
  break;
  case e16: {
    VI_XI_SLIDEDOWN_PARAMS(e16, 1);
#ifndef CPU_NANHU
    vd = vs2;
#else
  if (1 == mata_action) \
    vd = vs2; \
  else \
    vd = vector_agnostic(vd);
#endif
  }
  break;
  case e32: {
    VI_XI_SLIDEDOWN_PARAMS(e32, 1);
#ifndef CPU_NANHU
    vd = vs2;
#else
  if (1 == mata_action) \
    vd = vs2; \
  else \
    vd = vector_agnostic(vd);
#endif
  }
  break;
  default: {
    VI_XI_SLIDEDOWN_PARAMS(e64, 1);
#ifndef CPU_NANHU
    vd = vs2;
#else
  if (1 == mata_action) \
    vd = vs2; \
  else \
    vd = vector_agnostic(vd);
#endif
  }
  break;
  }
} else {
  switch (sew) {
  case e8:
#ifndef CPU_NANHU
    P.VU.elt<uint8_t>(rd_num, vl - 1, true) = RS1;
#else
    if (1 == mata_action) \
      P.VU.elt<uint8_t>(rd_num, vl - 1, true) = RS1; \
    else \
      P.VU.elt<uint8_t>(rd_num, vl - 1, true) = vector_agnostic(P.VU.elt<uint8_t>(rd_num, vl - 1, false));
#endif
    break;
  case e16:
#ifndef CPU_NANHU
    P.VU.elt<uint16_t>(rd_num, vl - 1, true) = RS1;
#else
    if (1 == mata_action) \
      P.VU.elt<uint16_t>(rd_num, vl - 1, true) = RS1; \
    else \
      P.VU.elt<uint16_t>(rd_num, vl - 1, true) = vector_agnostic(P.VU.elt<uint16_t>(rd_num, vl - 1, false));
#endif
    break;
  case e32:
#ifndef CPU_NANHU
    P.VU.elt<uint32_t>(rd_num, vl - 1, true) = RS1;
#else
    if (1 == mata_action) \
      P.VU.elt<uint32_t>(rd_num, vl - 1, true) = RS1; \
    else \
      P.VU.elt<uint32_t>(rd_num, vl - 1, true) = vector_agnostic(P.VU.elt<uint32_t>(rd_num, vl - 1, false));
#endif
    break;
  default:
#ifndef CPU_NANHU
    P.VU.elt<uint64_t>(rd_num, vl - 1, true) = RS1;
#else
    if (1 == mata_action) \
      P.VU.elt<uint64_t>(rd_num, vl - 1, true) = RS1; \
    else \
      P.VU.elt<uint64_t>(rd_num, vl - 1, true) = vector_agnostic(P.VU.elt<uint64_t>(rd_num, vl - 1, false));
#endif
    break;
  }
}
VI_LOOP_END
