#@# 

== top


topコマンドは、実行中のシステムの負荷状態を動的に確認できる。カーネルによって管理されているプロセスやスレッドのリストだけでなく、システムの概要情報も表示可能。それぞれのラベルの意味は以下に示す。

PID:プロセスの番号 | USER:実行者 | PR:優先度 | NI:相対優先度 | VIRT:仮想メモリ | RES:物理メモリ | SHR:共有メモリ | S:状態(D:割り込み不可,R:実行中,S:スリープ状態,T:停止中,Z:ゾンビプロセス) | %CPU,%MEM:CPU,メモリの使用率 | TIME+:プロセスの起動してからの経過時間。

オプション無しではCPU使用率順にソートされて表示される。詳しい操作方法はhを推すことで確認が可能である。

以下のオプションはtopコマンドが動いている状態でキーを押しても同様な操作をできる。






===== 実行例 



//list[][][fontsize=xx-small]{
  top
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
 top - 19:46:21 up 3 days,  6:20,  4 users,  load average: 0.75, 0.43, 0.36
Tasks: 243 total,   1 running, 242 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.8 us,  0.7 sy,  0.0 ni, 96.2 id,  2.3 wa,  0.0 hi,  0.0 si,  0.0 st
KiB Mem : 16204116 total,   418872 free,  2862832 used, 12922412 buff/cache
KiB Swap:  2097148 total,  2094076 free,     3072 used. 12585868 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
   2208 shunsuke  20   0   12.2g 600384 238248 S   2.7   3.7 158:45.45 firefox
  33026 shunsuke  20   0 2589236 202292  99788 S   1.3   1.2   7:03.68 Isolated Web Co
  30332 root      20   0 1388388  48296  19712 S   0.7   0.3  86:50.32 tailscaled
  32841 shunsuke  20   0 2616980 175496  94456 S   0.7   1.1  20:30.79 Isolated Web Co
   2942 shunsuke  20   0 2704040 281128  98600 S   0.3   1.7   6:23.49 Isolated Web Co
  33014 shunsuke  20   0 2668360 167660  93040 S   0.3   1.0  11:43.88 Isolated Web Co
  47534 systemd+  20   0   14828   6912   6144 S   0.3   0.0   3:50.44 systemd-oomd
  57499 shunsuke  20   0   14396   4224   3328 R   0.3   0.0   0:00.31 top
      1 root      20   0  166664  11648   8320 S   0.0   0.1   0:14.75 systemd
      2 root      20   0       0      0      0 S   0.0   0.0   0:00.12 kthreadd
      3 root       0 -20       0      0      0 I   0.0   0.0   0:00.00 rcu_gp
      4 root       0 -20       0      0      0 I   0.0   0.0   0:00.00 rcu_par_gp
      5 root       0 -20       0      0      0 I   0.0   0.0   0:00.00 slub_flushwq
  ~~プロセスが多いので省略~~
//}




上の結果を見るとFirefoxブラウザ (PID 2208) は、約12.2GBの仮想メモリを使用し、約600MBの物理メモリを消費しており、CPU使用率は2.3%、メモリ使用率は3.8%だということがわかる。







=== オプション一覧




==== -b


バッチモード。キー操作を受け付けず、「-n」で指定された回数か強制終了するまで実行を続ける。topの結果をファイルに保存する際などに役立つ。





===== 実行例 



//list[][][fontsize=xx-small]{
  tload -s 10
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
   2208 user  20   0   12.2g 546440 238592 S   4.0   3.4  60:48.81 firefox
   30332 root      20   0 1320912  50064  19712 S   1.3   0.3  59:20.04 tailscaled
   2733 user  20   0 2949016 310416 113852 S   0.7   1.9   3:01.25 Isolated Web Co
   15 root      20   0       0      0      0 I   0.3   0.0   1:11.40 rcu_preempt
   ~~(プロセスが多いので省略~~)    
//}




==== -d 


  

グラフの更新間隔を秒単位で指定する。






===== 実行例　



//list[][][fontsize=xx-small]{
  top -d 10
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  (以下、ソートおよび表示変更のため実行結果を記載しない)
//}


==== -d 


  

グラフの更新間隔を秒単位で指定する。






===== 実行例　



//list[][][fontsize=xx-small]{
  top -d 10
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  (以下ソートおよび表示変更のものは実行結果を記載しない)
//}


==== -E 


  

topのエリアに表示されるメモリの表示単位を指定する。






===== 実行例　



//list[][][fontsize=xx-small]{
  top -E k
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  KiB Mem : 16204116 total,   390028 free,  2894688 used, 12919400 buff/　　cache
  KiB Swap:  2097148 total,  2094076 free,     3072 used. 12554084 avail Mem
//}


==== -e 


  

タスクエリアに表示されるメモリの表示単位を指定する。






===== 実行例　



//list[][][fontsize=xx-small]{
  top -e k
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
 
//}


==== -H 


topに個別のスレッドを表示する。このオプションを使用しないと、各プロセスのすべてのスレッドごとの合計が表示される。

  




===== 実行例　



//list[][][fontsize=xx-small]{
  top -e k
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== -i


プロセスがcpuを使用しているもののみを表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  top -e k
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}



==== -n 


表示する回数を指定する。




===== 実行例　



//list[][][fontsize=xx-small]{
  top -n 1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== -o 


ソートなどで指定できる利用可能なフィールド名を表示して終了する。




===== 実行例　



//list[][][fontsize=xx-small]{
  top -e k
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  PID
  PPID
  ~~(長いので省略)~~
  RSsh
  CGNAME
  NU
//}



==== -o 


タスクエリアの表示をフィールド名を指定してソートする。




===== 実行例　



//list[][][fontsize=xx-small]{
  top -n 1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== -p 


特定のプロセスIDのプロセスのみ表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  top -n 1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== -S 


最後に記憶された「S」状態からの計測した累積時間モードに切り替える。




===== 実行例　



//list[][][fontsize=xx-small]{
  top -S 1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== -U 


指定したユーザーのプロセスに関連する情報だけでなく、他のプロセスも表示。




===== 実行例　



//list[][][fontsize=xx-small]{
  top -U root
//}




===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== -u 


指定したユーザーに関連するプロセスのみが表示。




===== 実行例　



//list[][][fontsize=xx-small]{
  top -U root
//}




===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== -w 


出力の幅を指定する。




===== 実行例　



//list[][][fontsize=xx-small]{
  top -w 110
//}




===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== -1 ※小文字Lではない 


サマリーエリアの CPU ステータスを切り替える。




===== 実行例　



//list[][][fontsize=xx-small]{
  top -1
//}




===== 実行結果　



//list[][][fontsize=xx-small]{
  top - 00:29:54 up 2 days, 11:03,  4 users,  load average: 0.12, 0.23, 0.25
  Tasks: 243 total,   1 running, 242 sleeping,   0 stopped,   0 zombie
  %Cpu0  :  5.9 us,  0.0 sy,  0.0 ni, 94.1 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
  %Cpu1  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
  %Cpu2  :  5.9 us,  0.0 sy,  0.0 ni, 94.1 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
  %Cpu3  :  6.2 us,  0.0 sy,  0.0 ni, 93.8 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
  KiB Mem : 16204116 total,   443740 free,  2837256 used, 12923120 buff/cache
  KiB Swap:  2097148 total,  2094076 free,     3072 used. 12611496 avail Mem
//}

