#@#

//footnote[process-tree][Unixの場合、プロセスにも親子関係があり、プロセスもツリー状になっている（注：学部のOSの授業では、ここまで説明しない）。そのため、親プロセス、子プロセスという言い回しもある]

=={pstree} @<term>{pstree}

@<idx>{プロセス((ぷろせす))<<>>の親子関係をツリー状に((のおやこかんけいをつりーじょうに))}アスキーアートで表示する@<fn>{process-tree}

=== 書式

//list[][][fontsize=xx-small]{
$ pstree [options]
//}

=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ pstree
//}

==== 実行結果

//list[][][fontsize=xx-small]{
systemd─┬─2*[agetty]
        ├─dbus-daemon
        ├─polkitd───2*[{polkitd}]
        ├─sshd───sshd───sshd───bash───script───bash───pstree　@<balloon>{(1)}
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

 * (1)の行をみると、 bash(pstreeと入力したターミナル)がpstreeを呼び出していることがわかる
