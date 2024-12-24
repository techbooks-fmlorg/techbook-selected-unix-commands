#@# 

== df
Unixのストレージ利用状況を確認できる。
===== 実行例

//list[][][fontsize=xx-small]{
$ df 
//}
===== 実行結果

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
Filesystem:各ファイルシステム
1K-blocks:使用できるディスク容量、基本単位はKBである(udevは485284KBである)
Used:使用しているディスク容量
Available:ディスクの空き容量
Use%:ディスクの使用率
Mounted on:どのフォルダでファイルシステムが使えるか示してる。(udevは/devというフォルダが使える。)

=== オプション一覧
==== -m
MB単位で出力する。(1MB=1024KB)
===== 実行例

//list[][][fontsize=xx-small]{
$df -m 
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
udevの485284KB/1024=473.9…からMBに変換されていることがわかる。