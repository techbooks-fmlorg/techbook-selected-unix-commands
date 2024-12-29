#@# 

== lsblk
現在利用できるブロックデバイス(ある程度のまとまったデータ量(ブロック)を単位として読み書きすることができる記憶装置、例えばHDDやSSDなどが当てはまる)を一覧表示できる。
表示する際はツリー状に表示される。
===== 実行例

//list[][][fontsize=xx-small]{
$ lsblk
//}
===== 実行結果

//list[][][fontsize=xx-small]{
NAME     MAJ:MIN RM  SIZE RO TYPE MOUNTPOINTS
xvda     202:0    0    8G  0 disk 
├─xvda1  202:1    0  7.9G  0 part /
├─xvda14 202:14   0    3M  0 part 
└─xvda15 202:15   0  124M  0 part /boot/efi
//}
NAME:ブロックデバイスの名前
MAJ:MIN:MAJはデバイスドライバの番号、MINは同一ドライバを使用しているデバイスを区別するための番号
(ここに表示されているxvdaはすべて同一ドライバを使用している)
RM:取り外し可能かどうかを示している。可能であれば1である。
SIZE:デバイスの容量
RO:読み取り専用かどうかを示している。読み取り専用であれば1である。
TYPE:ブロックデバイスのタイプを示している。diskであれば物理ディスク、partであればパーティション(ディスクを論理分割している)を示している。
MOUNTPOINTS:ブロックデバイスにファイルシステムがマウントされていればそのパスが表示される(表示されているファイルシステムがブロックデバイスに入力できる)。