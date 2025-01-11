= 頭文字が t のコマンド

#@# 

== timedatectl

大まかな文章説明


=== オプション一覧




==== -a




文章説明



===== 実行例 



//list[][][fontsize=xx-small]{
  ls -a
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Downloads Music .......................
//}


==== オプション 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}

#@# 

== timeout

timeoutコマンドは、指定された時間内にコマンドやプロセスを実行し、制限時間が経過すると実行を中断する。  
※timeoutコマンドは、コマンドがタイムアウトした場合にはステータスコード124で終了し、--preserve-statusオプションが設定されている場合には実行中のコマンドの終了ステータスを保持する。タイムアウト時にはTERMシグナルが送信され、キャッチできない場合にはKILL（9）シグナルが使用される。これにより、timeoutコマンドはタイムアウト制御とプロセス終了の管理を行う。



===== 実行例 



//list[][][fontsize=xx-small]{
  timeout 1 ping localhost
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  PING localhost (127.0.0.1) 56(84) bytes of data.
  64 bytes from localhost (127.0.0.1): icmp_seq=1 ttl=128 time=0.136 ms
//}


=== オプション一覧



==== -s もしくは --signal=SIGNAL




タイムアウト時に送信するシグナルを指定。デフォルトではTERMシグナルを使用。



===== 実行例 



//list[][][fontsize=xx-small]{
  timeout -s USR1 -k 2 3 ./test-u.sh
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  test
  test
  test
  User defined signal 1
  USER1 signal
  test
  test
  Killed
//}


==== -k もしくは --kill-after=DURATION 


  

初期のシグナルが送信されてから指定した時間が経過してもコマンドが実行中の場合には、KILLシグナルも送信することで確実にコマンドのキルをする。




===== 実行例　



//list[][][fontsize=xx-small]{
  timeout -k 2 3 ./test-u.sh
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  test
  test
  test
  Terminated
  TERM signal
  test
  test
  Killed
//}

#@# 

== tipc

TIPC（Transparent Inter-Process Communication）は、Linux上のプロトコルであり、クラスタ化されたコンピュータ環境内のアプリケーション間での通信を可能にする。TIPCコマンドは、TIPCプロトコルの設定と管理を行うためのツールである。



===== 実行例 



//list[][][fontsize=xx-small]{
  timeout 1 ping localhost
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  PING localhost (127.0.0.1) 56(84) bytes of data.
  64 bytes from localhost (127.0.0.1): icmp_seq=1 ttl=128 time=0.136 ms
//}


=== オプション一覧




==== -j もしくは -json




文章説明



===== 実行例 



//list[][][fontsize=xx-small]{
  ls -a
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Downloads Music .......................
//}


==== -p もしくは pretty 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}

#@# 

== tload


現在のシステムの負荷(load average)を指定されたttyにグラフで表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  tload
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
   0.52, 0.58, 0.59
  *

  *

  *

  *

  *      
//}


=== オプション一覧




==== -s


画面上の縦軸を設定する。load average 1に対応するグラフのひと目盛が、指定した文字分になる。したがって小さい値を設定するとスケールは大きくなる。逆も同じ。





===== 実行例 



//list[][][fontsize=xx-small]{
  tload -s 10
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  0.52, 0.58, 0.59
  ----------
  **********
  **********
  **********
  **********
  **********
  **********
//}


==== -d 


  

グラフの更新間隔を秒単位で指定する。




===== 実行例　



//list[][][fontsize=xx-small]{
  tload -d 10
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
   0.52, 0.58, 0.59
  *

  *

  *

  *

  *
//}

#@# 

== man

大まかな文章説明



===== 実行例 



//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果　


//list[][][fontsize=xx-small]{
  実行結果
//}



=== オプション一覧



==== オプション




文章説明



===== 実行例 



//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果　


//list[][][fontsize=xx-small]{
  実行結果
//}


==== オプション 




文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}




===== 実行結果　


//list[][][fontsize=xx-small]{
  実行結果
//}

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

#@# 

== touch


各ファイルのタイムスタンプを変更する。主にファイル内容の変更日時(ctime:Change Time)やファイルへの書き込みや権限などのパラメータ情報の修正日時(mtime:Modify Time)を変更する。

指定のファイルがない場合は作成される



===== 実行例 



//list[][][fontsize=xx-small]{
  touch hoge.txt
  stat hoge.txt(更新日時を確認)
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  File: hoge.txt
  Size: 0               Blocks: 0          IO Block: 4096   regular empty file
  Device: 802h/2050d      Inode: 5806706     Links: 1
  Access: (0664/-rw-rw-r--)  Uid: ( 1000/shunsuke)   Gid: ( 1000/shunsuke)
  Access: 2023-12-11 00:57:09.763776785 +0900
  Modify: 2023-12-11 00:57:09.763776785 +0900
  Change: 2023-12-11 00:57:09.763776785 +0900
  Birth: 2023-12-11 00:07:45.595626196 +0900
//}




=== オプション一覧




==== -a


アクセス日時(atime)とctimeを変更する。





===== 実行例 



//list[][][fontsize=xx-small]{
  touch -a hoge.txt
  stat hoge.txt(更新日時を確認)
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  File: hoge.txt
  Size: 0               Blocks: 0          IO Block: 4096   regular empty file
  Device: 802h/2050d      Inode: 5806706     Links: 1
  Access: (0664/-rw-rw-r--)  Uid: ( 1000/shunsuke)   Gid: ( 1000/shunsuke)
  Access: 2023-12-11 01:00:24.002451121 +0900
  Modify: 2023-12-11 00:57:09.763776785 +0900
  Change: 2023-12-11 01:00:24.002451121 +0900
  Birth: 2023-12-11 00:07:45.595626196 +0900
//}


==== -c もしくは --no-create 


  

touch実行時、指定ファイルが無い際にファイルを作成しない。




===== 実行例　



//list[][][fontsize=xx-small]{
  touch -c hoge1.txt
  ls
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  hoge.txt     snap    　ダウンロード  ドキュメント  ミュージック
  テンプレート  ビデオ     公開         user         デスクトップ  ピクチャ
//}


==== -d もしくは --date=STRING 


  

STRING(日時)を解析して、現在の時刻の代わりに使用する。




===== 実行例　



//list[][][fontsize=xx-small]{
  touch -d "2002-05-0210:00:00" hoge.txt　(2002年5月2日は筆者の誕生日)
  stat hoge.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  File: hoge.txt
  Size: 0               Blocks: 0          IO Block: 4096   regular empty file
  Device: 802h/2050d      Inode: 5806706     Links: 1
  Access: (0664/-rw-rw-r--)  Uid: ( 1000/shunsuke)   Gid: ( 1000/shunsuke)
  Access: 2002-05-02 10:00:00.000000000 +0900
  Modify: 2002-05-02 10:00:00.000000000 +0900
  Change: 2023-12-11 01:15:56.288362108 +0900
  Birth: 2023-12-11 00:07:45.595626196 +0900
//}


==== -f 


  

既存のファイルと同じ名前のファイルが存在していても上書きする。しかし動作的には通常のtouchと変わりはない。

明示的にファイルを強制的に上書きするという意味合いが込められているのみ。




===== 実行例　



//list[][][fontsize=xx-small]{
  同様のため省略
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  同様のため省略
//}


==== -h もしくは --no-dereference 


  

シンボリックリンクの場合、リンク先ではなくシンボリックそのもののタイムスタンプを変更する。シンボリックリンクとはリンクしているファイルのパス自体のこと。




===== 実行例　



//list[][][fontsize=xx-small]{
  touch -h link (linkとhoge.txtがつながっている)
  stat link (シンボリックリンク自体のタイムスタンプを確認)
  stat hoge.txt (sourceのタイムスタンプを確認)
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $touch -h link
  $stat link
    File: hoge.txt
    Size: 9               Blocks: 8          IO Block: 4096   regular file
    Device: 802h/2050d      Inode: 5806905     Links: 1
    Access: (0664/-rw-rw-r--)  Uid: ( 1000/shunsuke)   Gid: ( 1000/shunsuke)
    Access: 2023-12-12 02:16:22.142100484 +0900
    Modify: 2023-12-12 02:16:22.142100484 +0900
    Change: 2023-12-12 02:16:22.142100484 +0900
    Birth: 2023-12-12 01:42:56.393351377 +0900

  $stat hoge.txt
    File: link -> /home/shunsuke/hoge.txt
    Size: 23              Blocks: 0          IO Block: 4096   symbolic link
    Device: 802h/2050d      Inode: 5806911     Links: 1
    Access: (0777/lrwxrwxrwx)  Uid: ( 1000/shunsuke)   Gid: ( 1000/shunsuke)
    Access: 2023-12-12 02:16:44.658122212 +0900
    Modify: 2023-12-12 02:16:44.658122212 +0900
    Change: 2023-12-12 02:16:44.658122212 +0900
    Birth: 2023-12-12 02:08:13.509685780 +0900
//}


シンボリックリンクと元ファイルのhoge.txtのタイムスタンプを比較すると違う。

touch linkをすれば元のhoge.txtのタイムスタンプも変更される。


==== -m 


  

変更時刻（mtime）のみ変更する。




===== 実行例　



//list[][][fontsize=xx-small]{
  touch -m hoge.txt
  stat hoge.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  File: hoge.txt
  Size: 9               Blocks: 8          IO Block: 4096   regular file
  Device: 802h/2050d      Inode: 5806905     Links: 1
  Access: (0664/-rw-rw-r--)  Uid: ( 1000/shunsuke)   Gid: ( 1000/shunsuke)
  Access: 2023-12-12 02:25:55.299271733 +0900
  Modify: 2023-12-12 02:47:38.463970752 +0900
  Change: 2023-12-12 02:47:38.463970752 +0900
  Birth: 2023-12-12 01:42:56.393351377 +0900
//}


==== -r もしくは --reference=FILE 


  

現在の時刻の代わりに、指定したファイルのタイムスタンプを使用する。




===== 実行例　



//list[][][fontsize=xx-small]{
  touch -r hoge_source.txt hoge.txt
  stat hoge.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  File: hoge.txt
  Size: 9               Blocks: 8          IO Block: 4096   regular file
  Device: 802h/2050d      Inode: 5806905     Links: 1
  Access: (0664/-rw-rw-r--)  Uid: ( 1000/shunsuke)   Gid: ( 1000/shunsuke)
  Access: 2023-12-12 02:25:55.299271733 +0900
  Modify: 2023-12-12 02:47:38.463970752 +0900
  Change: 2023-12-12 02:47:38.463970752 +0900
  Birth: 2023-12-12 01:42:56.393351377 +0900
//}


==== -r もしくは --reference=FILE 


  

タイムスタンプで現在の時刻の代わりに、




===== 実行例　



//list[][][fontsize=xx-small]{
  touch -t 202312111234.56 hoge.txt
  stat hoge.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  File: hoge.txt
  Size: 9               Blocks: 8          IO Block: 4096   regular file
  Device: 802h/2050d      Inode: 5806905     Links: 1
  Access: (0664/-rw-rw-r--)  Uid: ( 1000/shunsuke)   Gid: ( 1000/shunsuke)
  Access: 2023-12-11 12:34:56.000000000 +0900
  Modify: 2023-12-11 12:34:56.000000000 +0900
  Change: 2023-12-12 03:13:33.025723661 +0900
  Birth: 2023-12-12 01:42:56.393351377 +0900
//}


==== --time=WORD 


  

タイムスタンプの変更するタイムを指定できる。しかしWORDがacces,atime,useの場合は-aのオプションと同様である。またWORDがmodify,mtimeのときは-mと同様である。




===== 実行例　



//list[][][fontsize=xx-small]{
  touch --time=aime
  stat hoge.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  File: hoge.txt
  Size: 9               Blocks: 8          IO Block: 4096   regular file
  Device: 802h/2050d      Inode: 5806905     Links: 1
  Access: (0664/-rw-rw-r--)  Uid: ( 1000/shunsuke)   Gid: ( 1000/shunsuke)
  Access: 2023-12-12 03:19:11.378151886 +0900
  Modify: 2023-12-11 12:34:56.000000000 +0900
  Change: 2023-12-12 03:19:11.378151886 +0900
  Birth: 2023-12-12 01:42:56.393351377 +0900
//}


#@# 

== tr

標準入力から文字を変換、スクイーズ、削除し、標準出力に書き出す。


===== 実行例 


//list[][][fontsize=xx-small]{
cat file1.txt | tr a-z a  (file1の中身を出力し、aからzまでの文字を全てaに置き換えるという意味)
//}



===== 実行結果 


//list[][][fontsize=xx-small]{
aaaaa,aaaaa!!
I aa Laaaa.
//}


=== オプション一覧


  

==== -d もしくは --delete



「-d」オプションで、指定した文字を削除することができる。一例として、Windows環境で作成したファイルの改行コードを、Linux環境向けに置き換えるといった用途に使用できる。



===== 実行例 


//list[][][fontsize=xx-small]{
  cat file1.txt | tr -d ami
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  hello,world!!
  I  Lnux.
//}



==== -s もしくは --squeeze-repeats



指定した文字が1回だけ出現するように置き換える。一例として、複数改行して間が大きく空いている文書などの間も縮めることができる。



===== 実行例 


//list[][][fontsize=xx-small]{
  cat file1.txt | tr -s a
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  hello,world!!
  I am Linux.
//}



==== -t もしくは --truncate-set1



置換する文字列の長さや個数に合わせて置換が行われる。連続している文字列は一つに集約されて出力される。



===== 実行例 


//list[][][fontsize=xx-small]{
  cat file1.txt | tr  -s hel! HEL?
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  HELo,worLd?
  I am Linux.
//}



#@# 

== tzselect

本体に保存されているそれぞれの地域のタイムゾーンを調べるコマンドである。
タイムゾーンを設定する際に用いる文字列を確認することもできる。他の国の時刻を知りたいときや、どんなタイムゾーンがあるのか知りたいときに便利である。

tzselectはシェルからパラメータなしで呼び出され、地域のリストが表示される。数字で地域を選ぶと、その地域にある国と都市のリストが表示される。
Enterキーを押せば、リストを再表示できる。タイムゾーンを選ぶには、その左の数字を押す。
Ctrl-Cを押すと、いつでもスクリプトを中断できる。
tzselectは実際にはタイムゾーンを変更しない。変更するには"dpkg-reconfigure","tz-date"を用いる。


===== 実行例 


//list[][][fontsize=xx-small]{
tzselect
//}



===== 実行結果 


//list[][][fontsize=xx-small]{
Please identify a location so that time zone rules can be set correctly.
Please select a continent, ocean, "coord", or "TZ".
 1) Africa
 2) Americas
 3) Antarctica
 4) Asia
 5) Atlantic Ocean
 6) Australia
 7) Europe
 8) Indian Ocean
 9) Pacific Ocean
10) coord - I want to use geographical coordinates.
11) TZ - I want to specify the timezone using the Posix TZ format.
    #? 4(入力)
Please select a country whose clocks agree with yours.
 1) Afghanistan              20) Iran                     39) Palestine
 2) Antarctica               21) Iraq                     40) Philippines
 3) Armenia                  22) Israel                   41) Qatar
 4) Azerbaijan               23) Japan                    42) Russia
 5) Bahrain                  24) Jordan                   43) Réunion
 6) Bangladesh               25) Kazakhstan               44) Saudi Arabia
 7) Bhutan                   26) Korea (North)            45) Seychelles
 8) Brunei                   27) Korea (South)            46) Singapore
 9) Cambodia                 28) Kuwait                   47) Sri Lanka
10) China                    29) Kyrgyzstan               48) Syria
11) Christmas Island         30) Laos                     49) Taiwan
12) Cocos (Keeling) Islands  31) Lebanon                  50) Tajikistan
13) Cyprus                   32) Macau                    51) Thailand
14) East Timor               33) Malaysia                 52) Turkmenistan
15) French S. Terr.          34) Mongolia                 53) United Arab Emirates
16) Georgia                  35) Myanmar (Burma)          54) Uzbekistan
17) Hong Kong                36) Nepal                    55) Vietnam
18) India                    37) Oman                     56) Yemen
19) Indonesia                38) Pakistan
    #? 23(入力)

The following information has been given:

        Japan

Therefore TZ='Asia/Tokyo' will be used.
Selected time is now:   Tue Jan  9 18:45:08 JST 2024.
Universal Time is now:  Tue Jan  9 09:45:08 UTC 2024.
Is the above information OK?
1) Yes
2) No
   #? 1(入力)

You can make this change permanent for yourself by appending the line
        TZ='Asia/Tokyo'; export TZ
to the file '.profile' in your home directory; then log out and log in again.

Here is that TZ value again, this time on standard output so that you
can use the /usr/bin/tzselect command in shell scripts:
Asia/Tokyo
//}


=== オプション一覧


  

==== -c



コード

  大陸、国、都市の順に入力する代わりに

  緯度経度を打ち込み、最も近い都市を含むタイムゾーンから選択する。

  COORDはISO 6709表記を使用する。

  日本なら北緯35度41分、東経139度41分であるため、「+3541+13941」であり、ブエノスアイレスならば「-35-058」or「-3436-05826」である。

  「緯度経度だけでも理解してくれる。



===== 実行例 


//list[][][fontsize=xx-small]{
  tzselect -c +35+139
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  Please identify a location so that time zone rules can be set correctly.
  Please select one of the following timezones, echo listed roughly in increasing order of distance from +35+139.
  1) Japan                                      6) Guam, Northern Mariana Islands
  2) Russia - MSK+08 - Sakhalin Island          7) Russia - MSK+06 - Tomponsky, Ust-Maysky
  3) Russia - MSK+07 - Amur River               8) China - Beijing Time
  4) Korea (South)                              9) Russia - MSK+07 - Oymyakonsky
  5) Korea (North)                             10) Palau
     #? 1

  The following information has been given:

          coord +35+139
          Japan

  Therefore TZ='Asia/Tokyo' will be used.
  Selected time is now:   Tue Jan  9 19:00:09 JST 2024.
  Universal Time is now:  Tue Jan  9 10:00:09 UTC 2024.
  Is the above information OK?
  1) Yes
  2) No
     #? 1

  You can make this change permanent for yourself by appending the line
          TZ='Asia/Tokyo'; export TZ
  to the file '.profile' in your home directory; then log out and log in again.

  Here is that TZ value again, this time on standard output so that you
  can use the /usr/bin/tzselect command in shell scripts:
  Asia/Tokyo
//}



==== -n



  cを使用したとき、地域リスト表示の最大値を設定する（デフォルトは10）。



===== 実行例 


//list[][][fontsize=xx-small]{
  tzselect -c +35+139 -n 2
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  tzselect -c +35+139 -n 2
  Please identify a location so that time zone rules can be set correctly.
  Please select one of the following timezones, echo listed roughly in increasing order of distance from +35+139.
  1) Japan
  2) Russia - MSK+08 - Sakhalin Island
  #? 1

  The following information has been given:

          coord +35+139
          Japan

  Therefore TZ='Asia/Tokyo' will be used.
  Selected time is now:   Tue Jan  9 19:01:59 JST 2024.
  Universal Time is now:  Tue Jan  9 10:01:59 UTC 2024.
  Is the above information OK?
  1) Yes
  2) No
  #? 1

  You can make this change permanent for yourself by appending the line
          TZ='Asia/Tokyo'; export TZ
  to the file '.profile' in your home directory; then log out and log in again.

  Here is that TZ value again, this time on standard output so that you
  can use the /usr/bin/tzselect command in shell scripts:
  Asia/Tokyo
//}

