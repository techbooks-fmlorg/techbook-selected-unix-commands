=={top} @<term>{top}

top コマンドは、OSのステータスのサマリを表示する。

 *  表示は@<B>{数秒おきに自動的に更新}される
 *  8行目以下はpsコマンドに似たプロセス一覧表
 ** いま活発に動いているプロセスが上の方に表示される
 ** 同じコマンドが表示され続けているなら、そのコマンドはシステムを重くしている犯人候補だ

=== 書式

//list[][][fontsize=xx-small]{
$ top
//}

//list[][][fontsize=xx-small]{
top - 01:29:59 up 1 min,  1 user,  load average: 0.09, 0.04, 0.01
Tasks:  86 total,   1 running,  85 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.0 us,  0.3 sy,  0.0 ni, 89.0 id,  0.6 wa,  0.0 hi,  0.0 si, 10.1 st
MiB Mem :    970.0 total,    748.8 free,    229.1 used,    123.9 buff/cache
MiB Swap:      0.0 total,      0.0 free,      0.0 used.    740.9 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
     36 root       0 -20       0      0      0 I   0.3   0.0   0:00.01 kworker/0:1H-kblockd
      1 root      20   0  102128  12068   9184 S   0.0   1.2   0:00.79 systemd
      2 root      20   0       0      0      0 S   0.0   0.0   0:00.00 kthreadd
   ... 以下略 ... 
//}

特に注意するべき項目は次の2ヶ所だろう。

 *  @<code>{load average: 0.09, 0.04, 0.01}
 ** どれくらいシステム（OS）が忙しいのか？の目安@<fn>{loadavg}
 *  @<code>{MiB Mem :    970.0 total,    748.8 free}
 ** メモリ使用量。
    この例では、
    トータルが970MB、未使用が748MB（つまり220MBほど使用中）なので、まだまだ余力があることが分かる

表示の詳細はUnixマニュアルを参照のこと。


//footnote[loadavg][おおむねCPUコア数以下なら気にしなくてよいだろう。load averageとは、プロセスの待ち行列の長さなので、直感的な忙しさとは微妙に異なるが、システム負荷の目安とされている。]
