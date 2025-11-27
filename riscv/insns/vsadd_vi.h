// vsadd.vi vd, vs2 simm5
VI_CHECK_SSS(false);
#ifndef CPU_NANHU
VI_LOOP_BASE
bool sat = false;
#else
VI_LOOP_BASE(1)
bool sat = false;
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
  VI_PARAMS(e8);
#ifndef CPU_NANHU
  vd = sat_add<int8_t, uint8_t>(vs2, vsext(simm5, sew), sat);
#else
  if (1 == mata_action) \
    vd = sat_add<int8_t, uint8_t>(vs2, vsext(simm5, sew), sat);
  else \
    vd = vector_agnostic(vd);
#endif
  break;
}
case e16: {
  VI_PARAMS(e16);
#ifndef CPU_NANHU
  vd = sat_add<int16_t, uint16_t>(vs2, vsext(simm5, sew), sat);
#else
  if (1 == mata_action) \
    vd = sat_add<int16_t, uint16_t>(vs2, vsext(simm5, sew), sat);
  else \
    vd = vector_agnostic(vd);
#endif
  break;
}
case e32: {
  VI_PARAMS(e32);
#ifndef CPU_NANHU
  vd = sat_add<int32_t, uint32_t>(vs2, vsext(simm5, sew), sat);
#else
  if (1 == mata_action) \
    vd = sat_add<int32_t, uint32_t>(vs2, vsext(simm5, sew), sat);
  else \
    vd = vector_agnostic(vd);
#endif
  break;
}
default: {
  VI_PARAMS(e64);
#ifndef CPU_NANHU
  vd = sat_add<int64_t, uint64_t>(vs2, vsext(simm5, sew), sat);
#else
  if (1 == mata_action) \
    vd = sat_add<int64_t, uint64_t>(vs2, vsext(simm5, sew), sat);
  else \
    vd = vector_agnostic(vd);
#endif
  break;
}
}
P_SET_OV(sat);
VI_LOOP_END
