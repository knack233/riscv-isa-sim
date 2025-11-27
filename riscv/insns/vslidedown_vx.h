//vslidedown.vx vd, vs2, rs1
VI_CHECK_SLIDE(false);

const uint128_t sh = RS1;
#ifndef CPU_NANHU
VI_LOOP_BASE
#else
\
require(P.VU.vsew >= e8 && P.VU.vsew <= e64); \
require_vector(true); \
reg_t vl = P.VU.vl->read(); \
reg_t UNUSED sew = P.VU.vsew; \
reg_t rd_num = insn.rd(); \
reg_t UNUSED rs1_num = insn.rs1(); \
reg_t rs2_num = insn.rs2(); \
V_EXT_VSTART_CHECK; \
for (reg_t i = P.VU.vstart->read(); i < std::max(P.VU.vlmax, P.VU.VLEN/P.VU.vsew); ++i) { \
\
VI_MASK_VARS \
__attribute__((unused)) int mata_action = 0; \
bool skip = false; \
mata_action = 0; \
if (insn.v_vm() == 0) { \
  skip = ((P.VU.elt<uint64_t>(0, midx) >> mpos) & 0x1) == 0; \
  if (skip && 0 == P.VU.vma && i < vl) { \
      continue; \
  } \
} \

#endif

reg_t offset = 0;
bool is_valid = (i + sh) < P.VU.vlmax;

if (is_valid) {
  offset = sh;
}

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
  VI_XI_SLIDEDOWN_PARAMS(e8, offset);
#ifndef CPU_NANHU
  vd = is_valid ? vs2 : 0;
#else
  if (1 == mata_action) \
    vd = is_valid ? vs2 : 0; \
  else \
    vd = vector_agnostic(vd);
#endif
}
break;
case e16: {
  VI_XI_SLIDEDOWN_PARAMS(e16, offset);
#ifndef CPU_NANHU
  vd = is_valid ? vs2 : 0;
#else
  if (1 == mata_action) \
    vd = is_valid ? vs2 : 0; \
  else \
    vd = vector_agnostic(vd);
#endif
}
break;
case e32: {
  VI_XI_SLIDEDOWN_PARAMS(e32, offset);
#ifndef CPU_NANHU
  vd = is_valid ? vs2 : 0;
#else
  if (1 == mata_action) \
    vd = is_valid ? vs2 : 0; \
  else \
    vd = vector_agnostic(vd);
#endif
}
break;
default: {
  VI_XI_SLIDEDOWN_PARAMS(e64, offset);
#ifndef CPU_NANHU
  vd = is_valid ? vs2 : 0;
#else
  if (1 == mata_action) \
    vd = is_valid ? vs2 : 0; \
  else \
    vd = vector_agnostic(vd);
#endif
}
break;
}
VI_LOOP_END
