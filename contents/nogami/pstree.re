#@# 

== pstree
プロセスの親子関係をツリー表示する。

===== 実行例

//list[][][fontsize=xx-small]{
$ pstree
//}
===== 実行結果

//list[][][fontsize=xx-small]{
systemd─┬─2*[agetty]
        ├─dbus-daemon
        ├─polkitd───2*[{polkitd}]
        ├─sshd───sshd───sshd───bash───script───bash───pstree　※
        ├─sudo───bash─┬─bash
        │             └─inotifywait
        ├─systemd───(sd-pam)
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-network
        ├─systemd-resolve
        ├─systemd-timesyn───{systemd-timesyn}
        ├─systemd-udevd
        └─unattended-upgr
//}
※bash(pstreeと入力したターミナル)がpstreeを呼び出していることがわかる