#@# X-TODO psコマンドの「端末」「ターミナル」を統一すること

=={ps} @<term>{ps}

@<idx>{プロセス((ぷろせす))<<>>の情報を表示する((のじょうほうをひょうじする))}コマンド。


=== 書式

//list[][][fontsize=xx-small]{
$ ps [options]
//}

 * 引数なしで実行しても、あまり有益な情報は得られない
 * 典型的な使い方は@<code>{ps auxww}である。この形で覚えることを推奨
 * 書式は歴史的に二系統ある
 ** Linux搭載の@<code>{ps}コマンドは両系統の上位互換にみえる動作をする
 ** 以下では伝統のUnix由来のオプションだけを紹介する
 * psコマンドは、オプションに@<B>{-}をつけてもつけなくても、
   オプションを受け付ける数少ないコマンドである
  （これも古代Unixとの互換性を保つため）
   

=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ ps   
//}

==== 実行結果

//list[][][fontsize=xx-small]{
    PID TTY          TIME CMD
1177754 pts/1    00:00:00 bash
1177761 pts/1    00:00:00 ps
//}
自分が実行しているプロセス群が表示されている。
3行目のpsは、いま実行中のpsコマンド自身。
各項目の詳細は@<table>{ps-no-option}を参照。

ちなみに「TTY列が同じ値（pts/1）のみ」であることを覚えておきつつ、
次のaオプション以降を読んでほしい

//table[ps-no-option][psコマンドの基本出力]{
１行目の各項目	説明
------------------------------------------------------
PID		プログラムごとに割り当てられている番号（プロセスIDの略）
TTY		プロセスが関連つけられている端末
STAT		プロセスの状態を表している（aオプション指定時）
TIME		プロセスが使用したCPU時間
CMD		実行されているコマンド
//}


=== 知っていると便利なオプション: a 

他の端末（ターミナル）を含めた、端末操作のプロセスを表示する

==== 実行例

//list[][][fontsize=xx-small]{
$ ps a
//}

==== 実行結果

//list[][][fontsize=xx-small]{
    PID TTY      STAT   TIME COMMAND
    656 tty7     Ssl+ 777:24 /usr/lib/xorg/Xorg :0 -seat seat0 -
    657 tty1     Ss+    0:00 /sbin/agetty -o -p -- \u --noclear
1174896 pts/0    Ss+    0:00 -bash
1177754 pts/1    Ss     0:00 -bash
1177757 pts/1    R+     0:00 ps a
//}

TTY列を見ると値が複数あることが分かる。
TTY列は各ユーザに割り当てられた端末である（正確には「（疑似）端末」）。
前述の出力例で分かるとおり、pts/1の行が自分がいる@<B>{"端末"}を意味している。
その他のtty1、tty7、pts/0は別の端末である。
この例では、pts/0の行が@<code>{-bash}なので、
自分以外のユーザも同じサーバ上にログインして（＝シェルを起動していて）作業中であることが分かる。

STAT列はプロセスの状態（state）で、
@<table>{ps-stat}を組み合わせた値が表示されている。

//table[ps-stat][psコマンドのSTAT列の読み方]{
STAT列の項目	説明
------------------------------------------------------
R		実行中(CPUを今使っている)
S		待機中(例：-bashはユーザーからの入力を待っている)
s 		セッションリーダー(sがついてるものがついてないプロセスを呼び出してる)
l		マルチスレッドプロセスであること（複雑なプロセスにつくことが多い）
+		フォアグランドのプロセスであることを示す(ターミナル上で動いてるプログラム)
//}
#@# X-TODO ps: foreground definiton ?



=== 知っていると便利なオプション: u

プロセスの所有者やCPU・メモリの使用率をわかりやすく表示する。

==== 実行例

//list[][][fontsize=xx-small]{
$ ps u 
//}

==== 実行結果

//list[][][fontsize=xx-small]{
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
h205     1174896  0.0  0.0   9456  7328 pts/0    Ss+  13:53   0:00 -bash
h205     1177754  0.0  0.0   6408  5020 pts/1    Ss   13:58   0:00 -bash
h205     1178343  100  0.0   9388  4864 pts/1    R+   14:00   0:00 ps u 
//}
列の詳細は@<table>{ps-u}を参照。

特に注目する列は、
(1)CPU使用率を意味する%CPU列と、
(2)メモリ使用量を意味するRSS列だろう。
システムが重い時は、
このどちらかの列の値が異常に大きいプロセスが犯人である可能性が高い。

//table[ps-u][ps uで追加表示される列]{
列	 説明
------------------------------------------------------
USER	（右端のコマンドを実行している）ユーザ名
%CPU	プロセスのCPUの使用率
%MEM	プロセスの物理メモリの使用率
VSZ	仮想メモリを確保しているサイズ
RSS	物理メモリを確保しているサイズ
//}


=== 知っていると便利なオプション: x

端末に紐づかないプロセス（サーバとして端末を切り離した状態で動作するプロセスなど）も表示する。

==== 実行例

//list[][][fontsize=xx-small]{
$ ps x
//}

==== 実行結果

//list[][][fontsize=xx-small]{
    PID TTY      STAT   TIME COMMAND
    800 ?        Ss     0:01 /lib/systemd/systemd --user
    801 ?        S      0:00 (sd-pam)
    816 ?        S<sl   0:00 /usr/bin/pulseaudio --daemonize=no
    〜省略〜
1174895 ?        S      0:00 sshd: h205@pts/0
1174896 pts/0    Ss+    0:00 -bash
1177753 ?        S      0:00 sshd: h205@pts/1
1177754 pts/1    Ss     0:00 -bash
1178609 pts/1    R+     0:00 ps x
//}
TTYが？のものは、バックグラウンドで動作するプロセスのため端末（TTY）が割り当たってないことを意味しており、
つまりバックグラウンドで動作している（いわゆるサーバ）プロセス

=== 知っていると便利なオプション: aux,auxww

これまで説明したオプションのa,u,xを組み合わせたもの
しかし、auxだと長いコマンドの場合に出力が省略されるため、コマンドライン引数をすべて確認したい場合はauxwwとする

==== 実行例 （ps auxとauxwwの比較）

//list[][][fontsize=xx-small]{
$ ps aux
$ ps auxww
//}

==== 実行結果 （ps auxとauxwwの比較）

//list[][][fontsize=xx-small]{
$ ps aux
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.0  0.0 169460 13824 ?        Ss   14:56   0:03 /sbin/init
root           2  0.0  0.0      0     0 ?        S    14:56   0:00 [kthreadd]
    〜省略〜
root       27816  0.0  0.0 1238196 15296 ?       Sl   15:16   0:00 /usr/bin/hogehogehogehoge-v2 -namespace dummy -id c5ca6239
    〜省略〜
//}
（上の例では省略されているが）基本的に全てのプロセスが表示されている。

//list[][][fontsize=xx-small]{
$ ps auxww
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.0  0.0 169460 13824 ?        Ss   14:56   0:03 /sbin/init
root           2  0.0  0.0      0     0 ?        S    14:56   0:00 [kthreadd]
    〜省略〜
root       27816  0.0  0.0 1238196 15296 ?       Sl   15:16   0:00 /usr/bin/hogehogehogehoge-v2 -namespace dummy -id c5cadb62398fbbad3823e8e4eaf6003e0d68f1853fed4b4cf9ff1bfe6f39d0270cac8 -address /hoge/hoge/hoge/hoge
    〜省略〜
//}
PID 27816のCOMMAND列を見比べると、
@<idx>{ps<<>> aux}の場合と異なり、
@<idx>{ps<<>> auxww}の場合はコマンドの末尾まで出力されていることがわかる。
