#@# 

=={df} @<term>{df}

Unixの@<idx>{ストレージ((すとれーじ))<<>>利用状況を確認((りようじょうきょうをかくにん))}できる。

=== 書式

//list[][][fontsize=xx-small]{
$ df 
//}

=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ df 
//}

==== 実行結果

//list[][][fontsize=xx-small]{
Filesystem     1K-blocks    Used Available Use% Mounted on
udev              485284       0    485284   0% /dev
tmpfs              99332     488     98844   1% /run
/dev/xvda1       8025124 1944152   5651764  26% /
tmpfs             496660       0    496660   0% /dev/shm
tmpfs               5120       0      5120   0% /run/lock
/dev/xvda15       126678   11840    114838  10% /boot/efi
tmpfs              99332       0     99332   0% /run/user/1000
//}

読み方は@<table>{df}のとおり

//table[df][dfの読み方]{
dfの一行目	説明
----------------------------------------
Filesystem	各ファイルシステム
　		（OSが割り当てた「デバイスの識別子」もしくは「ファイルシスシステムの種類」）
1K-blocks	使用できるディスク容量、基本単位はKBである
　		例：（/の）/dev/xvda1ファイルシステムの容量は7838MBである
Used		使用中のディスク容量
Available	ディスクの空き容量
Use%		ディスクの使用率
Mounted on	ファイルシステムがどのディレクトリで使えるか
　		（Unix用語では「ファイルシステムのマウント先ディレクトリ」）
　		例：/dev/xvda1は/（ルートディレクトリ）にマウントされている
//}


=== 知っていると便利なオプション: -m

MB単位で出力する(1MB=1024KB)@<fn>{df-m}。

===== 実行例

//list[][][fontsize=xx-small]{
$ df -m 
//}

===== 実行結果

//list[][][fontsize=xx-small]{
Filesystem     1M-blocks  Used Available Use% Mounted on
udev                 474     0       474   0% /dev
tmpfs                 98     1        97   1% /run
/dev/xvda1          7838  1899      5520  26% /
tmpfs                486     0       486   0% /dev/shm
tmpfs                  5     0         5   0% /run/lock
/dev/xvda15          124    12       113  10% /boot/efi
tmpfs                 98     0        98   0% /run/user/1000   
//}
たとえば2行目のudevは、@<code>{485284KB/1024 = 474（473.9を繰り上げ）}なので、MBに変換された値が表示されている。


//footnote[df-m][いまどきのストレージは大きいのでMBどころかGBやTB単位で表示してほしいと思うかもしれない。KBとMBの表示は良いのだが、それより大きい単位はLinux(GNU)系とBSDでオプションが異なる。]

//note[IO-unit][ストレージやIOの基本単位]{

dfに限らずストレージやIO統計のツールでは、表示の単位に気をつけたい。
歴史的に@<idx>{ストレージ((すとれーじ))<<>>の基本単位((のきほんたんい))}は1セクタ@<idx>{512}バイトであるが、
ツールやOSごとに表示単位はマチマチなので注意が必要だ。

セクタ数表示なのか？バイト表示なのか？
1000で割った数字なのか？
それとも1024で割った数字なのか？
など気をつける点がいろいろある。
正解はマニュアルを読めとしか言えないのだが...

//}
