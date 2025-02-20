#@# 

=={lscpu} @<term>{lscpu}

@<idx>{CPU<<>>の情報を表示((のじょうほうをひょうじ))}する

=== 書式

//list[][][fontsize=xx-small]{
$ lscpu [options]
//}
たいていは引数なしで実行すれば十分


=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ lscpu
//}

==== 実行結果

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
   〜省略〜
Virtualization features:  
  Hypervisor vendor:      Xen
  Virtualization type:    full
   〜省略〜
//}
そもそも@<code>{lscpu}コマンドが実行できる時点で、正常にOSが起動できているはずなので、
障害対応の意味合いは薄い。
実運用上は「CPUのコア数の確認」や「CPUの型番を知りたい」という場面くらいか？
@<table>{lscpu}も参照のこと。


#@# X-TODO lscpu table の場所
//table[lscpu][lscpuの読み方(一部)]{
項目(一部)		説明
------------------------------------------------------------
Architecture		CPUのアーキテクチャ
CPU op			CPUがサポートしてるモード
　  			(64bit,32bitアーキテクチャをサポートしている)
Address sizes		物理アドレスと仮想アドレスのサイズ
　			(物理アドレス46bit,仮想アドレス48bit)
Byte Order		バイト順序(リトルエンディアンという最下位バイトが最初に来る形式である)
CPU(s)			システムに搭載されてるCPUの数
On-line CPU(s) list	現在使用可能なCPUのリスト(0という名称のCPU1つが使用可能)
//}
