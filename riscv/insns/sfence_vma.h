require_extension('S');
require_impl(IMPL_MMU);
if (STATE.v) {
  if (STATE.prv == PRV_U || get_field(STATE.hstatus->read(), HSTATUS_VTVM))
    require_novirt();
} else {
  require_privilege(get_field(STATE.mstatus->read(), MSTATUS_TVM) ? PRV_M : PRV_S);
}
#ifndef CPU_NANHU
MMU.flush_tlb();
#else
MMU.flush_tlb_on_sfence_vma();
#endif
