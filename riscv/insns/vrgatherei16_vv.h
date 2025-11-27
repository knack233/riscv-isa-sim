// vrgatherei16.vv vd, vs2, vs1, vm # vd[i] = (vs1[i] >= VLMAX) ? 0 : vs2[vs1[i]];
float vemul = (16.0 / P.VU.vsew * P.VU.vflmul);
require(vemul >= 0.125 && vemul <= 8);
require_align(insn.rd(), P.VU.vflmul);
require_align(insn.rs2(), P.VU.vflmul);
require_align(insn.rs1(), vemul);
require_noover(insn.rd(), P.VU.vflmul, insn.rs1(), vemul);
require(insn.rd() != insn.rs2());
require_vm;

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
    mata_action = 1; \

#endif
  switch (sew) {
  case e8: {
    auto vs1 = P.VU.elt<uint16_t>(rs1_num, i);
#ifndef CPU_NANHU
    P.VU.elt<uint8_t>(rd_num, i, true) = vs1 >= P.VU.vlmax ? 0 : P.VU.elt<uint8_t>(rs2_num, vs1);
#else
    if (1 == mata_action) \
      P.VU.elt<uint8_t>(rd_num, i, true) = vs1 >= P.VU.vlmax ? 0 : P.VU.elt<uint8_t>(rs2_num, vs1);
    else \
      P.VU.elt<uint8_t>(rd_num, i, true) = vector_agnostic(P.VU.elt<uint8_t>(rd_num, i, false)); \

#endif
    break;
  }
  case e16: {
    auto vs1 = P.VU.elt<uint16_t>(rs1_num, i);
#ifndef CPU_NANHU
    P.VU.elt<uint16_t>(rd_num, i, true) = vs1 >= P.VU.vlmax ? 0 : P.VU.elt<uint16_t>(rs2_num, vs1);
#else
    if (1 == mata_action) \
      P.VU.elt<uint16_t>(rd_num, i, true) = vs1 >= P.VU.vlmax ? 0 : P.VU.elt<uint16_t>(rs2_num, vs1);
    else \
      P.VU.elt<uint16_t>(rd_num, i, true) = vector_agnostic(P.VU.elt<uint16_t>(rd_num, i, false)); \

#endif
    break;
  }
  case e32: {
    auto vs1 = P.VU.elt<uint16_t>(rs1_num, i);
#ifndef CPU_NANHU
    P.VU.elt<uint32_t>(rd_num, i, true) = vs1 >= P.VU.vlmax ? 0 : P.VU.elt<uint32_t>(rs2_num, vs1);
#else
    if (1 == mata_action) \
      P.VU.elt<uint32_t>(rd_num, i, true) = vs1 >= P.VU.vlmax ? 0 : P.VU.elt<uint32_t>(rs2_num, vs1);
    else \
      P.VU.elt<uint32_t>(rd_num, i, true) = vector_agnostic(P.VU.elt<uint32_t>(rd_num, i, false)); \

#endif
    break;
  }
  default: {
    auto vs1 = P.VU.elt<uint16_t>(rs1_num, i);
#ifndef CPU_NANHU
    P.VU.elt<uint64_t>(rd_num, i, true) = vs1 >= P.VU.vlmax ? 0 : P.VU.elt<uint64_t>(rs2_num, vs1);
#else
    if (1 == mata_action) \
      P.VU.elt<uint64_t>(rd_num, i, true) = vs1 >= P.VU.vlmax ? 0 : P.VU.elt<uint64_t>(rs2_num, vs1);
    else \
      P.VU.elt<uint64_t>(rd_num, i, true) = vector_agnostic(P.VU.elt<uint64_t>(rd_num, i, false)); \

#endif
    break;
  }
  }
VI_LOOP_END;
