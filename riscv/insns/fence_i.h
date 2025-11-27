#ifndef CPU_NANHU
MMU.flush_icache();
#else
MMU.flush_icache_on_fence_i();
#endif
