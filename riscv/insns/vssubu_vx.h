// vssubu.vx vd, vs2, rs1
VI_CHECK_SSS(false);
#ifndef CPU_NANHU
VI_LOOP_BASE
#else
VI_LOOP_BASE(1)
#endif
bool sat = false;

#ifdef CPU_NANHU
if (0 == P.VU.vta && i >= vl) { \
  continue; \
} \
if ((true == skip && 1 == P.VU.vma && i < vl) || (1 == P.VU.vta && i >= vl)) \
  mata_action = 2; \
else \
  mata_action = 1;
#endif

switch (sew) {
case e8: {
  VX_U_PARAMS(e8);
#ifndef CPU_NANHU
  vd = sat_subu<uint8_t>(vs2, rs1, sat);
#else
  if (1 == mata_action) \
    vd = sat_subu<uint8_t>(vs2, rs1, sat);
  else \
    vd = vector_agnostic(vd);
#endif
  break;
}
case e16: {
  VX_U_PARAMS(e16);
#ifndef CPU_NANHU
  vd = sat_subu<uint16_t>(vs2, rs1, sat);
#else
  if (1 == mata_action) \
    vd = sat_subu<uint16_t>(vs2, rs1, sat);
  else \
    vd = vector_agnostic(vd);
#endif
  break;
}
case e32: {
  VX_U_PARAMS(e32);
#ifndef CPU_NANHU
  vd = sat_subu<uint32_t>(vs2, rs1, sat);
#else
  if (1 == mata_action) \
    vd = sat_subu<uint32_t>(vs2, rs1, sat);
  else \
    vd = vector_agnostic(vd);
#endif
  break;
}
default: {
  VX_U_PARAMS(e64);
#ifndef CPU_NANHU
  vd = sat_subu<uint64_t>(vs2, rs1, sat);
#else
  if (1 == mata_action) \
    vd = sat_subu<uint64_t>(vs2, rs1, sat);
  else \
    vd = vector_agnostic(vd);
#endif
  break;
}
}
P_SET_OV(sat);
VI_LOOP_END
