#@# 

== ps

OSで自分が現在実行されているプロセス(プログラムやアプリケーション)から自身のターミナル(画面)に関連するプロセスの情報を表示できる。

===== 実行例

//list[][][fontsize=xx-small]{
$ ps   
//}
===== 実行結果

//list[][][fontsize=xx-small]{
    PID TTY          TIME CMD
1177754 pts/1    00:00:00 bash
1177761 pts/1    00:00:00 ps
//}
PID:プログラムごとに割り当てられている番号
TTY:プロセスが関連つけられている端末
TIME:プロセスが使用したCPU時間
CMD:実行されているコマンド

=== オプション一覧

==== a
他のターミナルを含めた、端末操作のプロセスを表示する

===== 実行例

//list[][][fontsize=xx-small]{
$ ps a
//}
===== 実行結果

//list[][][fontsize=xx-small]{
    PID TTY      STAT   TIME COMMAND
    656 tty7     Ssl+ 777:24 /usr/lib/xorg/Xorg :0 -seat seat0 -
    657 tty1     Ss+    0:00 /sbin/agetty -o -p -- \u --noclear
1174896 pts/0    Ss+    0:00 -bash
1177754 pts/1    Ss     0:00 -bash
1177757 pts/1    R+     0:00 ps a
//}
TTYを見るとpsと違い-bashが複数あり、自分のほかの人が同じサーバーでターミナルを開いていることがわかる。
STAT:プロセスの状態を表している。
R:実行中(CPUを今使っている)
S:待機中(-bashはユーザーからの入力を待っている)
sセッションリーダー(sがついてるものがついてないプロセスを呼び出してる)
l:マルチスレッドプロセスであること（複雑なプロセスにつくことが多い）
+:フォアグランドのプロセス状態(画面上で動いてるプログラム)
上記のものを組み合わせたものが表示されている。

==== u
プロセスの所有者やCPU・メモリの使用率をわかりやすく表示する。

===== 実行例

//list[][][fontsize=xx-small]{
$ ps u 
//}
===== 実行結果

//list[][][fontsize=xx-small]{
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
h205     1174896  0.0  0.0   9456  7328 pts/0    Ss+  13:53   0:00 -bash
h205     1177754  0.0  0.0   6408  5020 pts/1    Ss   13:58   0:00 -bash
h205     1178343  100  0.0   9388  4864 pts/1    R+   14:00   0:00 ps u 
//}
USER:ユーザーネーム
%CPU:プロセスのCPUの使用率
%MEM:プロセスの物理メモリの使用率
VSZ:仮想メモリを確保しているサイズ
RSS:物理メモリを確保しているサイズ

==== x
端末に紐づかないプロセス(サーバー動作中に動作するシステムのプロセスなど)も表示する。

===== 実行例

//list[][][fontsize=xx-small]{
$ ps x
//}

===== 実行結果

//list[][][fontsize=xx-small]{
    PID TTY      STAT   TIME COMMAND
    800 ?        Ss     0:01 /lib/systemd/systemd --user
    801 ?        S      0:00 (sd-pam)
    816 ?        S<sl   0:00 /usr/bin/pulseaudio --daemonize=no
----------省略-------------
1174895 ?        S      0:00 sshd: h205@pts/0
1174896 pts/0    Ss+    0:00 -bash
1177753 ?        S      0:00 sshd: h205@pts/1
1177754 pts/1    Ss     0:00 -bash
1178609 pts/1    R+     0:00 ps x
//}
TTYが?なものは、バックグラウンドで動作するプロセスのためTTYが割り当たってない

==== aux,auxww
これまで説明したオプションのa,u,xを組み合わせたもの
しかし、auxだと長いコマンドの場合省略されるため、コマンドライン引数をすべて確認したい場合、auxwwとつける

===== 実行例

//list[][][fontsize=xx-small]{
$ ps aux
$ ps auxww
//}

===== 実行結果

//list[][][fontsize=xx-small]{
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.0  0.0 169460 13824 ?        Ss   14:56   0:03 /sbin/init
root           2  0.0  0.0      0     0 ?        S    14:56   0:00 [kthreadd]
----------省略-------------
root       27816  0.0  0.0 1238196 15296 ?       Sl   15:16   0:00 /usr/bin/hogehogehogehoge-v2 -namespace dummy -id c5ca6239 //idの途中までしか表示されていない
----------省略-------------
h205       32687  0.0  0.0   6408  4864 pts/0    Ss   16:40   0:00 -bash
root       32947  0.0  0.0      0     0 ?        I    16:42   0:00 [kworker/3:2-events_power_efficient]
root       32957  0.0  0.0      0     0 ?        I    16:45   0:00 [kworker/u12:4-be_err_recover]
root       33214  0.0  0.0      0     0 ?        I    16:47   0:00 [kworker/3:1-mm_percpu_wq]
h205       33215  200  0.0  10612  5460 pts/0    R+   16:48   0:00 ps aux

$ps auxww
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.0  0.0 169460 13824 ?        Ss   14:56   0:03 /sbin/init
root           2  0.0  0.0      0     0 ?        S    14:56   0:00 [kthreadd]
----------省略-------------
root       27816  0.0  0.0 1238196 15296 ?       Sl   15:16   0:00 /usr/bin/hogehogehogehoge-v2 -namespace dummy -id c5cadb62398fbbad3823e8e4eaf6003e0d68f1853fed4b4cf9ff1bfe6f39d0270cac8 -address /hoge/hoge/hoge/hoge //PID:27816に関する情報がすべて表示されている
----------省略-------------
h205       32687  0.0  0.0   6408  4864 pts/0    Ss   16:40   0:00 -bash
root       32957  0.0  0.0      0     0 ?        I    16:45   0:00 [kworker/u12:4-events_unbound]
root       33214  0.0  0.0      0     0 ?        I    16:47   0:00 [kworker/3:1-events_power_efficient]
root       33480  0.0  0.0      0     0 ?        I    16:52   0:00 [kworker/3:2-events]
h205       33481  0.0  0.0  10612  5492 pts/0    R+   16:54   0:00 ps auxww
//}
※一部改変有
省略されているが基本的に全てのプロセスが表示されている
PID 27816のCOMMANDを見比べるとauxだと末尾まで出力されていないのがわかる。