#@# 

== lscpu
CPUの情報を表示できる

===== 実行例

//list[][][fontsize=xx-small]{
$lscpu
//}
===== 実行結果

//list[][][fontsize=xx-small]{
Architecture:             x86_64
  CPU op-mode(s):         32-bit, 64-bit
  Address sizes:          46 bits physical, 48 bits virtual
  Byte Order:             Little Endian
CPU(s):                   1
  On-line CPU(s) list:    0
Vendor ID:                GenuineIntel
  Model name:             Intel(R) Xeon(R) CPU E5-2686 v4 @ 2.30GHz
    CPU family:           6
    Model:                79
    Thread(s) per core:   1
    Core(s) per socket:   1
    Socket(s):            1
    Stepping:             1
    BogoMIPS:             4599.99
    Flags:                fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca 
                          cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rd
                          tscp lm constant_tsc rep_good nopl xtopology cpuid tsc_kn
                          own_freq pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 
                          x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c
                           rdrand hypervisor lahf_lm abm invpcid_single pti fsgsbas
                          e bmi1 avx2 smep bmi2 erms invpcid xsaveopt
Virtualization features:  
  Hypervisor vendor:      Xen
  Virtualization type:    full
Caches (sum of all):      
  L1d:                    32 KiB (1 instance)
  L1i:                    32 KiB (1 instance)
  L2:                     256 KiB (1 instance)
  L3:                     45 MiB (1 instance)
NUMA:                     
  NUMA node(s):           1
  NUMA node0 CPU(s):      0
Vulnerabilities:          
  Gather data sampling:   Not affected
  Itlb multihit:          KVM: Mitigation: VMX unsupported
  L1tf:                   Mitigation; PTE Inversion
  Mds:                    Vulnerable: Clear CPU buffers attempted, no microcode; SM
                          T Host state unknown
  Meltdown:               Mitigation; PTI
  Mmio stale data:        Vulnerable: Clear CPU buffers attempted, no microcode; SM
                          T Host state unknown
  Reg file data sampling: Not affected
  Retbleed:               Not affected
  Spec rstack overflow:   Not affected
  Spec store bypass:      Vulnerable
  Spectre v1:             Mitigation; usercopy/swapgs barriers and __user pointer s
                          anitization
  Spectre v2:             Mitigation; Retpolines; STIBP disabled; RSB filling; PBRS
                          B-eIBRS Not affected; BHI Retpoline
  Srbds:                  Not affected
  Tsx async abort:        Not affected
//}
Architecture:CPUのアーキテクチャを示している。
CPU op:CPUがサポートしてるモード(64bit,32bitアーキテクチャをサポートしている。)
Address sizes:物理アドレスと仮想アドレスのサイズを示している。(物理アドレス46bit,仮想アドレス48bit)
Byte Order:バイト順序(リトルエンディアンという最下位バイトが最初に来る形式である。)
CPU(s):システムに搭載されてるCPUの数
On-line CPU(s) list:現在使用可能なCPUのリスト(0という名称のCPU1つが使用可能)
