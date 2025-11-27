//vslide1up.vx vd, vs2, rs1
VI_CHECK_SLIDE(true);

#ifndef CPU_NANHU
VI_LOOP_BASE
#else
VI_LOOP_BASE(1)
if (0 == P.VU.vta && i >= vl) { \
  continue; \
} \
if ((true == skip && 1 == P.VU.vma && i < vl) || (i >= vl)) \
  mata_action = 2; \
else \
  mata_action = 1;
#endif
if (i != 0) {
  if (sew == e8) {
    VI_XI_SLIDEUP_PARAMS(e8, 1);
#ifndef CPU_NANHU
    vd = vs2;
#else
    if (1 == mata_action) \
      vd = vs2; \
    else \
      vd = vector_agnostic(vd);
#endif
  } else if (sew == e16) {
    VI_XI_SLIDEUP_PARAMS(e16, 1);
#ifndef CPU_NANHU
    vd = vs2;
#else
    if (1 == mata_action) \
      vd = vs2; \
    else \
      vd = vector_agnostic(vd);
#endif
  } else if (sew == e32) {
    VI_XI_SLIDEUP_PARAMS(e32, 1);
#ifndef CPU_NANHU
    vd = vs2;
#else
    if (1 == mata_action) \
      vd = vs2; \
    else \
      vd = vector_agnostic(vd);
#endif
  } else if (sew == e64) {
    VI_XI_SLIDEUP_PARAMS(e64, 1);
#ifndef CPU_NANHU
    vd = vs2;
#else
    if (1 == mata_action) \
      vd = vs2; \
    else \
      vd = vector_agnostic(vd);
#endif
  }
} else {
  if (sew == e8) {
#ifndef CPU_NANHU
    P.VU.elt<uint8_t>(rd_num, 0, true) = RS1;
#else
    if (1 == mata_action) \
      P.VU.elt<uint8_t>(rd_num, 0, true) = RS1; \
    else \
      P.VU.elt<uint8_t>(rd_num, 0, true) = vector_agnostic(P.VU.elt<uint8_t>(rd_num, 0, false));
#endif
  } else if (sew == e16) {
#ifndef CPU_NANHU
    P.VU.elt<uint16_t>(rd_num, 0, true) = RS1;
#else
    if (1 == mata_action) \
      P.VU.elt<uint16_t>(rd_num, 0, true) = RS1; \
    else \
      P.VU.elt<uint16_t>(rd_num, 0, true) = vector_agnostic(P.VU.elt<uint16_t>(rd_num, 0, false));
#endif
  } else if (sew == e32) {
#ifndef CPU_NANHU
    P.VU.elt<uint32_t>(rd_num, 0, true) = RS1;
#else
    if (1 == mata_action) \
      P.VU.elt<uint32_t>(rd_num, 0, true) = RS1; \
    else \
      P.VU.elt<uint32_t>(rd_num, 0, true) = vector_agnostic(P.VU.elt<uint32_t>(rd_num, 0, false));
#endif
  } else if (sew == e64) {
#ifndef CPU_NANHU
    P.VU.elt<uint64_t>(rd_num, 0, true) = RS1;
#else
    if (1 == mata_action) \
      P.VU.elt<uint64_t>(rd_num, 0, true) = RS1; \
    else \
      P.VU.elt<uint64_t>(rd_num, 0, true) = vector_agnostic(P.VU.elt<uint64_t>(rd_num, 0, false));
#endif
  }
}
VI_LOOP_END
