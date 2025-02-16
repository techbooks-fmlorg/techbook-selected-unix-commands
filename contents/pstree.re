#@# X-TODO pstree にある「親子関係」の説明が必要だろう、脚注？

=={pstree} @<term>{pstree}

@<idx>{プロセス((ぷろせす))<<>>の親子関係をツリー状に表示する((のおやこかんけいをつりーじょうにひょうじする))}。

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

 * @<code>{※}は実際には出力されない
 * この行をみると、 bash(pstreeと入力したターミナル)がpstreeを呼び出していることがわかる
