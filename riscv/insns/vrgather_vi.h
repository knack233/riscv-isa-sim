// vrgather.vi vd, vs2, zimm5 vm # vd[i] = (zimm5 >= VLMAX) ? 0 : vs2[zimm5];
require_align(insn.rd(), P.VU.vflmul);
require_align(insn.rs2(), P.VU.vflmul);
require(insn.rd() != insn.rs2());
require_vm;

reg_t zimm5 = insn.v_zimm5();

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
  case e8:
#ifndef CPU_NANHU
    P.VU.elt<uint8_t>(rd_num, i, true) = zimm5 >= P.VU.vlmax ? 0 : P.VU.elt<uint8_t>(rs2_num, zimm5);
#else
    if (1 == mata_action) \
      P.VU.elt<uint8_t>(rd_num, i, true) = zimm5 >= P.VU.vlmax ? 0 : P.VU.elt<uint8_t>(rs2_num, zimm5);
    else \
      P.VU.elt<uint8_t>(rd_num, i, true) = vector_agnostic(P.VU.elt<uint8_t>(rd_num, i, false)); \

#endif
    break;
  case e16:
#ifndef CPU_NANHU
    P.VU.elt<uint16_t>(rd_num, i, true) = zimm5 >= P.VU.vlmax ? 0 : P.VU.elt<uint16_t>(rs2_num, zimm5);
#else
    if (1 == mata_action) \
      P.VU.elt<uint16_t>(rd_num, i, true) = zimm5 >= P.VU.vlmax ? 0 : P.VU.elt<uint16_t>(rs2_num, zimm5);
    else \
      P.VU.elt<uint16_t>(rd_num, i, true) = vector_agnostic(P.VU.elt<uint16_t>(rd_num, i, false)); \

#endif
    break;
  case e32:
#ifndef CPU_NANHU
    P.VU.elt<uint32_t>(rd_num, i, true) = zimm5 >= P.VU.vlmax ? 0 : P.VU.elt<uint32_t>(rs2_num, zimm5);
#else
    if (1 == mata_action) \
      P.VU.elt<uint32_t>(rd_num, i, true) = zimm5 >= P.VU.vlmax ? 0 : P.VU.elt<uint32_t>(rs2_num, zimm5);
    else \
      P.VU.elt<uint32_t>(rd_num, i, true) = vector_agnostic(P.VU.elt<uint32_t>(rd_num, i, false)); \

#endif
    break;
  default:
#ifndef CPU_NANHU
    P.VU.elt<uint64_t>(rd_num, i, true) = zimm5 >= P.VU.vlmax ? 0 : P.VU.elt<uint64_t>(rs2_num, zimm5);
#else
    if (1 == mata_action) \
      P.VU.elt<uint64_t>(rd_num, i, true) = zimm5 >= P.VU.vlmax ? 0 : P.VU.elt<uint64_t>(rs2_num, zimm5);
    else \
      P.VU.elt<uint64_t>(rd_num, i, true) = vector_agnostic(P.VU.elt<uint64_t>(rd_num, i, false)); \

#endif
    break;
  }
VI_LOOP_END;
