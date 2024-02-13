= 頭文字が p のコマンド

#@# 

== psicc(途中)

色管理プロファイルを適用するとコマンドツール。ICC（International Color Consortium）プロファイルを使用して、画像やグラフィックスの色空間を変更するために使用する。


=== オプション一覧




==== -b




-bオプションを使用すると、プロファイルの変換を行う際に、画像やグラフィックスのバックアップファイルを作成できる。



===== 実行例 



//list[][][fontsize=xx-small]{
  psicc -b input.icc output.icc
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  バックアップファイルが作成される: "input.icc"ファイルは、変換前の状態を保持したバックアップファイルとして保存される。バックアップファイルの名前は通常、元のファイル名に".bak"などの拡張子が追加されることがある。例えば、"input.icc"のバックアップファイルは"input.icc.bak"となる場合がある。
//}


==== -c precision 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}



==== -i profile 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}




==== -n gridpoints 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}




==== -o profile 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}



==== -t intent 


  

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

== pslog

pslogコマンドは、プロセスの現在の作業ログを報告する。


=== オプション一覧




==== -V




バージョン情報を表示します



===== 実行例 



//list[][][fontsize=xx-small]{
  pslog -V
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  pslog (PSmisc) 23.4
  Copyright (C) 2015-2017 Vito Mule'.
  PSmisc comes with ABSOLUTELY NO WARRANTY.
  This is free software, and you are welcome to redistribute it underthe terms of the GNU General Public License.
  For more information about these matters, see the files named COPYING.
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

== pstree

現在実行されているプロセスをツリー表示するコマンド


===== 実行例 



//list[][][fontsize=xx-small]{
  pstree
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  systemd─┬─ModemManager───2*[{ModemManager}]
        ├─agetty
        ├─containerd───8*[{containerd}]
        ├─cron
        ├─dbus-daemon
        ├─dockerd───9*[{dockerd}]
        ├─irqbalance───{irqbalance}
        ├─multipathd───6*[{multipathd}]
        ├─networkd-dispat
        ├─packagekitd───2*[{packagekitd}]
        ├─polkitd───2*[{polkitd}]
        ├─rsyslogd───3*[{rsyslogd}]
        ├─snapd───10*[{snapd}]
        ├─sshd───sshd───sshd───bash───pstree
        ├─systemd───(sd-pam)
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-network
        ├─systemd-resolve
        ├─systemd-timesyn───{systemd-timesyn}
        ├─systemd-udevd
        ├─tailscaled───10*[{tailscaled}]
        ├─thermald───{thermald}
        ├─udisksd───4*[{udisksd}]
        ├─unattended-upgr───{unattended-upgr}
        └─upowerd───2*[{upowerd}]
//}




=== オプション一覧











==== -a 


  

各プロセスのコマンドライン引数を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  pstree -a
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  systemd --system --deserialize 36
  ├─ModemManager
  │   └─2*[{ModemManager}]
  ├─agetty -o -p -- \\u --noclear tty1 linux
  ├─containerd
  │   └─8*[{containerd}]
  ├─cron -f -P
  ├─dbus-daemon --system --address=systemd: --nofork --nopidfile...
  ├─dockerd -H fd:// --containerd=/run/containerd/containerd.sock
  │   └─9*[{dockerd}]
  ├─irqbalance --foreground
  │   └─{irqbalance}
  ├─multipathd -d -s
  │   └─6*[{multipathd}]
  ├─networkd-dispat /usr/bin/networkd-dispatcher --run-startup-triggers
  ├─packagekitd
  │   └─2*[{packagekitd}]
  ├─polkitd --no-debug
  │   └─2*[{polkitd}]
  ├─rsyslogd -n -iNONE
  │   └─3*[{rsyslogd}]
  ├─snapd
  │   └─10*[{snapd}]
  ├─sshd
  │   └─sshd
  │       └─sshd
  │           └─bash
  │               └─pstree -a
  ├─systemd --user
  │   └─(sd-pam)
  ├─systemd-journal
  ├─systemd-logind
  ├─systemd-network
  ├─systemd-resolve
  ├─systemd-timesyn
  │   └─{systemd-timesyn}
  ├─systemd-udevd
  ├─tailscaled --state=/var/lib/tailscale/tailscaled.state--socket=/run/ta
  │   └─10*[{tailscaled}]
  ├─thermald --systemd --dbus-enable --adaptive
  │   └─{thermald}
  ├─udisksd
  │   └─4*[{udisksd}]
  ├─unattended-upgr ...
  │   └─{unattended-upgr}
  └─upowerd
      └─2*[{upowerd}]
//}



==== -c 


  

-cオプションを使用すると、各プロセスの実行可能ファイル(コマンド)の名前を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  pstree -c
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  systemd─┬─ModemManager─┬─{ModemManager}
        │              └─{ModemManager}
        ├─agetty
        ├─containerd─┬─{containerd}
        │            ├─{containerd}
        │            ├─{containerd}
        │            ├─{containerd}
        │            ├─{containerd}
        │            ├─{containerd}
        │            ├─{containerd}
        │            └─{containerd}
        ├─cron
        ├─dbus-daemon
        ├─dockerd─┬─{dockerd}
        │         ├─{dockerd}
        │         ├─{dockerd}
        │         ├─{dockerd}
        │         ├─{dockerd}
        │         ├─{dockerd}
        │         ├─{dockerd}
        │         ├─{dockerd}
        │         └─{dockerd}
        ├─irqbalance───{irqbalance}
        ├─multipathd─┬─{multipathd}
        │            ├─{multipathd}
        │            ├─{multipathd}
        │            ├─{multipathd}
        │            ├─{multipathd}
        │            └─{multipathd}
        ├─networkd-dispat
        ├─packagekitd─┬─{packagekitd}
        │             └─{packagekitd}
        ├─polkitd─┬─{polkitd}
        │         └─{polkitd}
        ├─rsyslogd─┬─{rsyslogd}
        │          ├─{rsyslogd}
        │          └─{rsyslogd}
        ├─snapd─┬─{snapd}
        │       ├─{snapd}
        │       ├─{snapd}
        │       ├─{snapd}
        │       ├─{snapd}
        │       ├─{snapd}
        │       ├─{snapd}
        │       ├─{snapd}
        │       ├─{snapd}
        │       └─{snapd}
        ├─sshd───sshd───sshd───bash───pstree
        ├─systemd───(sd-pam)
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-network
        ├─systemd-resolve
        ├─systemd-timesyn───{systemd-timesyn}
        ├─systemd-udevd
        ├─tailscaled─┬─{tailscaled}
        │            ├─{tailscaled}
        │            ├─{tailscaled}
        │            ├─{tailscaled}
        │            ├─{tailscaled}
        │            ├─{tailscaled}
        │            ├─{tailscaled}
        │            ├─{tailscaled}
        │            ├─{tailscaled}
        │            └─{tailscaled}
        ├─thermald───{thermald}
        ├─udisksd─┬─{udisksd}
        │         ├─{udisksd}
        │         ├─{udisksd}
        │         └─{udisksd}
        ├─unattended-upgr───{unattended-upgr}
        └─upowerd─┬─{upowerd}
                  └─{upowerd}
//}



- @<strong>{-h} 

  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  pstree -h
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  systemd─┬─ModemManager───2*[{ModemManager}]
        ├─agetty
        ├─containerd───8*[{containerd}]
        ├─cron
        ├─dbus-daemon
        ├─dockerd───9*[{dockerd}]
        ├─irqbalance───{irqbalance}
        ├─multipathd───6*[{multipathd}]
        ├─networkd-dispat
        ├─packagekitd───2*[{packagekitd}]
        ├─polkitd───2*[{polkitd}]
        ├─rsyslogd───3*[{rsyslogd}]
        ├─sh───node─┬─node─┬─bash───pstree
        │           │      └─11*[{node}]
        │           ├─node─┬─node───6*[{node}]
        │           │      └─15*[{node}]
        │           ├─node───12*[{node}]
        │           └─10*[{node}]
        ├─snapd───10*[{snapd}]
        ├─sshd─┬─sshd───sshd───bash
        │      └─sshd───sshd
        ├─systemd───(sd-pam)
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-network
        ├─systemd-resolve
        ├─systemd-timesyn───{systemd-timesyn}
        ├─systemd-udevd
        ├─tailscaled───10*[{tailscaled}]
        ├─thermald───{thermald}
        ├─udisksd───4*[{udisksd}]
        ├─unattended-upgr───{unattended-upgr}
        └─upowerd───2*[{upowerd}]
//}


 - @<strong>{-l} 


長い行を表示。デフォルトでは、長い行はディスプレイの幅で切られる。




===== 実行例　



//list[][][fontsize=xx-small]{
  pstree -l
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  systemd─┬─ModemManager───2*[{ModemManager}]
        ├─agetty
        ├─containerd───8*[{containerd}]
        ├─cron
        ├─dbus-daemon
        ├─dockerd───9*[{dockerd}]
        ├─irqbalance───{irqbalance}
        ├─multipathd───6*[{multipathd}]
        ├─networkd-dispat
        ├─packagekitd───2*[{packagekitd}]
        ├─polkitd───2*[{polkitd}]
        ├─rsyslogd───3*[{rsyslogd}]
        ├─sh───node─┬─node─┬─bash───pstree
        │           │      └─11*[{node}]
        │           ├─node───12*[{node}]
        │           ├─node───15*[{node}]
        │           └─10*[{node}]
        ├─snapd───10*[{snapd}]
        ├─sshd─┬─sshd───sshd───bash
        │      └─sshd───sshd
        ├─systemd───(sd-pam)
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-network
        ├─systemd-resolve
        ├─systemd-timesyn───{systemd-timesyn}
        ├─systemd-udevd
        ├─tailscaled───10*[{tailscaled}]
        ├─thermald───{thermald}
        ├─udisksd───4*[{udisksd}]
        ├─unattended-upgr───{unattended-upgr}
        └─upowerd───2*[{upowerd}]
//}




==== -n




同じ親を持つプロセスを、名前ではなくPIDでソートしる。



===== 実行例 



//list[][][fontsize=xx-small]{
  pstree -n
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  systemd─┬─multipathd───6*[{multipathd}]
        ├─cron
        ├─dbus-daemon
        ├─irqbalance───{irqbalance}
        ├─networkd-dispat
        ├─polkitd───2*[{polkitd}]
        ├─rsyslogd───3*[{rsyslogd}]
        ├─systemd-logind
        ├─thermald───{thermald}
        ├─agetty
        ├─ModemManager───2*[{ModemManager}]
        ├─unattended-upgr───{unattended-upgr}
        ├─tailscaled───10*[{tailscaled}]
        ├─snapd───10*[{snapd}]
        ├─containerd───8*[{containerd}]
        ├─dockerd───9*[{dockerd}]
        ├─systemd-timesyn───{systemd-timesyn}
        ├─packagekitd───2*[{packagekitd}]
        ├─upowerd───2*[{upowerd}]
        ├─sshd─┬─sshd───sshd───bash
        │      └─sshd───sshd
        ├─systemd-journal
        ├─udisksd───4*[{udisksd}]
        ├─systemd-udevd
        ├─systemd-network
        ├─systemd-resolve
        ├─systemd───(sd-pam)
        └─sh───node─┬─10*[{node}]
                    ├─node─┬─11*[{node}]
                    │      └─bash───pstree
                    ├─node───12*[{node}]
                    └─node───15*[{node}]
//}




==== -p




文章説明



===== 実行例 



//list[][][fontsize=xx-small]{
  pstree -p
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  systemd(1)─┬─ModemManager(743)─┬─{ModemManager}(749)
           │                   └─{ModemManager}(755)
           ├─agetty(702)
           ├─containerd(12189)─┬─{containerd}(12190)
           │                   ├─{containerd}(12191)
           │                   ├─{containerd}(12192)
           │                   ├─{containerd}(12193)
           │                   ├─{containerd}(12194)
           │                   ├─{containerd}(12195)
           │                   ├─{containerd}(12196)
           │                   └─{containerd}(12199)
           ├─cron(665)
           ├─dbus-daemon(666)
           ├─dockerd(12520)─┬─{dockerd}(12521)
           │                ├─{dockerd}(12522)
           │                ├─{dockerd}(12523)
           │                ├─{dockerd}(12524)
           │                ├─{dockerd}(12525)
           │                ├─{dockerd}(12526)
           │                ├─{dockerd}(12527)
           │                ├─{dockerd}(12528)
           │                └─{dockerd}(12531)
           ├─irqbalance(673)───{irqbalance}(688)
           ├─multipathd(457)─┬─{multipathd}(462)
           │                 ├─{multipathd}(463)
           │                 ├─{multipathd}(464)
           │                 ├─{multipathd}(465)
           │                 ├─{multipathd}(466)
           │                 └─{multipathd}(467)
           ├─networkd-dispat(674)
           ├─packagekitd(240910)─┬─{packagekitd}(240915)
           │                     └─{packagekitd}(240916)
           ├─polkitd(675)─┬─{polkitd}(689)
           │              └─{polkitd}(729)
           ├─rsyslogd(676)─┬─{rsyslogd}(703)
           │               ├─{rsyslogd}(704)
           │               └─{rsyslogd}(705)
           ├─sh(250384)───node(250393)─┬─node(250456)─┬─bash(2+
           │                           │              ├─sh(253+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              └─{node}+
           │                           ├─node(250588)─┬─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              └─{node}+
           │                           ├─node(250601)─┬─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              ├─{node}+
           │                           │              └─{node}+
           │                           ├─{node}(250396)
           │                           ├─{node}(250398)
           │                           ├─{node}(250399)
           │                           ├─{node}(250400)
           │                           ├─{node}(250402)
           │                           ├─{node}(250404)
           │                           ├─{node}(250405)
           │                           ├─{node}(250406)
           │                           ├─{node}(250407)
           │                           └─{node}(250408)
           ├─snapd(7523)─┬─{snapd}(7542)
           │             ├─{snapd}(7553)
           │             ├─{snapd}(7554)
           │             ├─{snapd}(7555)
           │             ├─{snapd}(7556)
           │             ├─{snapd}(7560)
           │             ├─{snapd}(7563)
           │             ├─{snapd}(7564)
           │             ├─{snapd}(7604)
           │             └─{snapd}(8387)
           ├─sshd(240914)─┬─sshd(241403)───sshd(241510)───bash+
           │              ├─sshd(250501)───sshd(250558)
           │              └─sshd(253237)───sshd(253294)
           ├─systemd(241406)───(sd-pam)(241407)
           ├─systemd-journal(240920)
           ├─systemd-logind(681)
           ├─systemd-network(240946)
           ├─systemd-resolve(240948)
           ├─systemd-timesyn(240909)───{systemd-timesyn}(24094+
           ├─systemd-udevd(240939)
           ├─tailscaled(793)─┬─{tailscaled}(794)
           │                 ├─{tailscaled}(795)
           │                 ├─{tailscaled}(796)
           │                 ├─{tailscaled}(797)
           │                 ├─{tailscaled}(798)
           │                 ├─{tailscaled}(799)
           │                 ├─{tailscaled}(800)
           │                 ├─{tailscaled}(802)
           │                 ├─{tailscaled}(803)
           │                 └─{tailscaled}(811)
           ├─thermald(684)───{thermald}(746)
           ├─udisksd(240921)─┬─{udisksd}(240924)
           │                 ├─{udisksd}(240926)
           │                 ├─{udisksd}(240932)
           │                 └─{udisksd}(240943)
           ├─unattended-upgr(744)───{unattended-upgr}(765)
           └─upowerd(240913)─┬─{upowerd}(240930)
                             └─{upowerd}(240931)
//}



==== -u




文章説明



===== 実行例 



//list[][][fontsize=xx-small]{
  pstree -u
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  systemd─┬─ModemManager───2*[{ModemManager}]
        ├─agetty
        ├─containerd───8*[{containerd}]
        ├─cron
        ├─dbus-daemon(messagebus)
        ├─dockerd───9*[{dockerd}]
        ├─irqbalance───{irqbalance}
        ├─multipathd───6*[{multipathd}]
        ├─networkd-dispat
        ├─packagekitd───2*[{packagekitd}]
        ├─polkitd───2*[{polkitd}]
        ├─rsyslogd(syslog)───3*[{rsyslogd}]
        ├─sh(tomo)───node─┬─node─┬─bash───pstree
        │                 │      ├─sh───cpuUsage.sh───sleep
        │                 │      └─11*[{node}]
        │                 ├─node───12*[{node}]
        │                 ├─node───15*[{node}]
        │                 └─10*[{node}]
        ├─snapd───10*[{snapd}]
        ├─sshd─┬─sshd───sshd(tomo)───bash
        │      └─2*[sshd───sshd(tomo)]
        ├─systemd(tomo)───(sd-pam)
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-network(systemd-network)
        ├─systemd-resolve(systemd-resolve)
        ├─systemd-timesyn(systemd-timesync)───{systemd-timesyn+
        ├─systemd-udevd
        ├─tailscaled───10*[{tailscaled}]
        ├─thermald───{thermald}
        ├─udisksd───4*[{udisksd}]
        ├─unattended-upgr───{unattended-upgr}
        └─upowerd───2*[{upowerd}]
//}




#@# 

== patar

Perlで書いたtarに似たコマンド。PerlモジュールであるArchive::Tarを使用して、ファイルやディレクトリ構造を含めたtarアーカイブの抽出、作成、およびリスト表示を行うためのプログラム。



===== 実行例 



//list[][][fontsize=xx-small]{
  オプションなしでは実行できない
//}







=== オプション一覧




==== -c




tarアーカイブを作成する。



===== 実行例 



//list[][][fontsize=xx-small]{
  ptar -c　file1.text file2.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls
  file1.text file2.txt //実行前

  $ ptar -c　file1.text file2.txt

  $ ls
  default.tar  file1.text file2.txt/実行後
//}


==== -f 


  

ファイル名の指定ができる。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptar -c -f test.tar test_1.txt test_2.txt 
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ls
  test_1.txt  test_2.txt/実行前
  
  $ls
  test_1.txt  test_2.txt  test.tar/実行後
//}


==== -t 


  

tarファイルの中身をリスト表示します。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptar -t -f test.tar
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ./test_1.txt
  ./test_2.txt
//}


- @<strong>{-x} 

  

tarアーカイブは抽出されるを行う。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptar -xf archive.tar
//}







===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls //実行前
  archive.tar

  $ ptar -xf archive.tar

  $ ls 
  archive.tar file1.txt file2.txt
//}



==== -z 


  

zlib圧縮されたアーカイブファイルを読み書きするためオプション。zlibは、低レベルのデータ圧縮と解凍のためのライブラリおよびフォーマット。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptar -czf test.tar.gz test_1.txt test_2.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls
  test_1.txt  test_2.txt  test.tar /実行前

  $ ptar -czf test.tar.gz test_1.txt test_2.txt

  $ ls
  test_1.txt  test_2.txt  test.tar  test.tar.gz/実行後
//}




==== -v 


  

tarアーカイブの作成または抽出されるファイル名が表示される。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptar -cvf archive.tar test_1.txt test_2.txt
//}


この実行例では、text_1.txtとtext_2.txtを使用してarchive.tarという名前のtarファイルを作成している。vオプションを使用することで、上記のコマンドの実行後にtext_1.txtとtext_2.txtのファイル名が表示される。








===== 実行結果　



//list[][][fontsize=xx-small]{
  ./test_1.txt
  ./test_2.txt
//}






==== -T 




tarファイルの作成にテキストファイルを使用する。テキストファイルには、tarファイルの作成に使用するファイルのパスが記載されている。あらかじめテキストファイルを作成することで多くのファイルをtarファイルの作成に使用できる。



===== 実行例　



使用するファイル:filelist.txt





//list[][][fontsize=xx-small]{
  ptar -cvf archive.tar -T filelist.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls //実行前
  filelist.txt 

  $ cat filelist.txt 
  /home/user/file1.txt
  /home/user/file2.txt

  //filelist.txtには、2つのディレクトリ構造が記載されている

  $ ptar -cvf archive.tar -T filelist.txt
  //filelist.txtに記載されているディレクトリ構造をもとにarchive.tarを作成。

  /home/user/file1.txt
  /home/user/file2.txt

  $ ls //実行後
  archive.tar  filelist.txt

  $ tar -xf archive.tar
  //作成されたtarファイルの確認のため、中身を抽出

  $ ls
  archive.tar  filelist.txt  home
  // home/userのディレクトリが抽出される。
  $ cd home/user
  $ ls
  file1.txt file2.txt
  //その中にfile1.txt file2.txtが含まれる。
//}






#@# 

== ptardiff



指定したアーカイブファイル内のファイルと、カレントディレクトリ内にある同じ名前のファイルとの差分を表示するコマンド。



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

== ptargrep

tarアーカイブ内のファイルの内容にパターンマッチングを適用するためのツール



===== 実行例 



//list[][][fontsize=xx-small]{
  オプション無しで実行できない
//}







=== オプション一覧





==== --basename




アーカイブファイル内のファイル名に対して、指定したベース名（パターン）に一致するものを検索するためのコマンド。一致するファイルを抽出する場合、アーカイブからのディレクトリパスを無視し、現在のディレクトリにアーカイブ内のファイルのベース名を使用して書き込む。ただし、アーカイブ内の2つの一致するファイルが同じベース名を持つ場合、2番目のファイルが最初のファイルを上書きする。








===== 実行例 



  使用するアーカイブファイル
//list[][][fontsize=xx-small]{
  test.tar
   └─ home
       └── user
             ├──file1.txt
             └──file2.txt
//}



//list[][][fontsize=xx-small]{
  $ ptargrep --basename "file" test.tar
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  file1.txt
  file2.txt
//}


==== --ignore-case 


  

--ignore-caseオプションは、大文字と小文字を区別せずに検索を行うためのオプション






===== 実行例　



//list[][][fontsize=xx-small]{
  $ ptargrep --ignore-case "file" test.tar
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  File.txt
  file.jpg
//}


==== --list-only 


  

文章説明




===== 実行例　



//list[][][fontsize=xx-small]{
  $ ptargrep --list-only fruits.tar

//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Apple.txt
  apple.jpg
  Orange.txt
  orange.jpg
  Pineapple.txt
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

== ptx 

ptxコマンドは、与えられたテキストファイルを処理し、単語の順列索引を生成する。順列索引は、単語をアルファベット順にソートし、単語ごとにその出現箇所や参照情報を提供する。順列索引は、単語を検索したり、単語の出現パターンを分析したりするのに役立つ。



===== 実行例 



//list[][][fontsize=xx-small]{
  ptx file.txt
//}





===== 実行結果　




//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ ptx file.txt　/実行後

   with various words.                 It contains multiple lines of text
   permuted index of these/            The ptx command will generate a
   the ptx command.                    This is a sample file for testing
   command.                  This is   a sample file for testing the ptx
       The ptx command will generate   a permuted index of these words.
     sample file for testing the ptx   command.                   This is a
   index of these words/     The ptx   command will generate a permuted
   with various words.            It   contains multiple lines of text
                    This is a sample   file for testing the ptx command.
               This is a sample file   for testing the ptx command.
   words.       The ptx command will   generate a permuted index of these
            will generate a permuted   index of these words.       /command
   ptx command.                 This   is a sample file for testing the
                It contains multiple   lines of text with various words.
   various words.        It contains   multiple lines of text with
          It contains multiple lines   of text with various words.
      will generate a permuted index   of these words.         /ptx command
     The ptx command will generate a   permuted index of these words.
       a sample file for testing the   ptx command.                 This is
   permuted index of these/      The   ptx command will generate a
   command.                This is a   sample file for testing the ptx
           This is a sample file for   testing the ptx command.
       It contains multiple lines of   text with various words.
        is a sample file for testing   the ptx command.                This
        generate a permuted index of   these words.           /command will
         multiple lines of text with   various words.           It contains
   these words.      The ptx command   will generate a permuted index of
     contains multiple lines of text   with various words.               It
          lines of text with various   words.                     /multiple
           a permuted index of these   words.                /will generate

  
  
//}



===== 実行結果の中央を見ると、上から「It」,「The」,「This」～のようにアルファベット順でキーワードの順列索引が生成されます。キーワードの両サイドには前後の文脈が表示される。






=== オプション一覧

このオプションを用いると、左の列にファイル名とキーワードが含まれている行番号を表示することができる。ただし、標準入力の場合ファイル名は表示されない。


==== -A








===== 実行例.1 



//list[][][fontsize=xx-small]{
  ptx file.txt -A

 
//}





===== 実行結果.1　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ ptx file.txt -A /実行後
  file.txt:2:  of text with various/        It contains multiple lines
  file.txt:3:  generate a permuted/         The ptx command will
  file.txt:1:  testing the ptx/             This is a sample file for
  file.txt:1:  the ptx/           This is   a sample file for testing
  file.txt:3:      /command will generate   a permuted index of these/
  file.txt:1:    file for testing the ptx   command.            /a sample
  file.txt:3:  permuted/          The ptx   command will generate a
  file.txt:2:  text with various/      It   contains multiple lines of
  file.txt:1:            This is a sample   file for testing the ptx/
  file.txt:1:       This is a sample file   for testing the ptx command/
  file.txt:3:        The ptx command will   generate a permuted index/
  file.txt:3:   /will generate a permuted   index of these words.
  file.txt:1:  testing the ptx/      This   is a sample file for
  file.txt:2:        It contains multiple   lines of text with various/
  file.txt:2:  various/       It contains   multiple lines of 

//}



===== 実行例.2 



//list[][][fontsize=xx-small]{
   cat file.txt | ptx -A
  //catでfile.txtの中身を標準出力し、それをpxtで順列索引する。
//}





===== 実行結果.2　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.


  $ cat file.txt | ptx -A /実行後


  :2:  text with various words.         It contains multiple lines of
  :3:  permuted index of these/         The ptx command will generate a
  :1:  testing the ptx command.         This is a sample file for
  :1:  ptx command.           This is   a sample file for testing the
  :3:      /ptx command will generate   a permuted index of these words/
  :1:        file for testing the ptx   command.             /is a sample
  :3:  permuted index of/     The ptx   command will generate a
  :2:  with various words.         It   contains multiple lines of text
  :1:  command.      This is a sample   file for testing the ptx
  :1:           This is a sample file   for testing the ptx command.
  :3:            The ptx command will   generate a permuted index of/
  :3:        will generate a permuted   index of these words.    /command
  :1:  the ptx command.          This   is a sample file for testing
  :2:            It contains multiple   lines of text with various/
  :2:  various words/     It contains   multiple lines of text with
  :2:      It contains multiple lines   of text with various words.
  :3:       generate a permuted index   of these words.     /command will
  :3:    /ptx command will generate a   permuted index of these words.
  :1:     sample file for testing the   ptx command.            This is a
  :3:  permuted index of/         The   ptx command will generate a
  :1:  command.             This is a   sample file for testing the ptx
  :1:       This is a sample file for   testing the ptx command.
  :2:      contains multiple lines of   text with various words.       It
  :1:    is a sample file for testing   the ptx command.             This
  :3:    generate a permuted index of   these words.                /will
  :2:     multiple lines of text with   various words.        It contains
  :3:  of these/      The ptx command   will generate a permuted index
  :2:          multiple lines of text   with various words.     /contains
  :2:      lines of text with various   words.                  /multiple
  :3:       a permuted index of these   words.             /will generate
//}





==== -W




正規表現を用いて、順列索引するキーワードを設定できる。



===== 実行例 



//list[][][fontsize=xx-small]{
  ptx file.txt -W 'It'
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ ptx file.txt -W 'It' /実行後
  with various words.                 It contains multiple lines of text
//}


==== -f 


  

索引のソートや正規表現の大文字と小文字を区別する動作を変更する。索引のソートは大文字と小文字を区別しなくなり、正規表現の大文字と小文字の区別もなくなる




===== 実行例　



//list[][][fontsize=xx-small]{
  ptx file.txt -f
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.


  $ ptx file.txt -f /実行後
      This is   　　　　　　　　　　　   a sample file for testing the ptx
       The ptx command will generate   a permuted index of these words.
     sample file for testing the ptx   command.                   This is a
   index of these words/     The ptx   command will generate a permuted
   with various words.            It   contains multiple lines of text
                    This is a sample   file for testing the ptx command.
               This is a sample file   for testing the ptx command.
   words.       The ptx command will   generate a permuted index of these
            will generate a permuted   index of these words.       /command
   ptx command.                 This   is a sample file for testing the
   with various words.                 It contains multiple lines of text
                It contains multiple   lines of text with various words.
   various words.        It contains   multiple lines of text with
          It contains multiple lines   of text with various words.
      will generate a permuted index   of these words.         /ptx command
     The ptx command will generate a   permuted index of these words.
       a sample file for testing the   ptx command.                 This is
   permuted index of these/      The   ptx command will generate a
   command.                This is a   sample file for testing the ptx
           This is a sample file for   testing the ptx command.
       It contains multiple lines of   text with various words.
        is a sample file for testing   the ptx command.                This
   permuted index of these/            The ptx command will generate a
        generate a permuted index of   these words.           /command will
   the ptx command.                    This is a sample file for testing
         multiple lines of text with   various words.           It contains
   these words.      The ptx command   will generate a permuted index of
     contains multiple lines of text   with various words.               It
          lines of text with various   words.                     /multiple
           a permuted index of these   words.                /will generate
//}


オプション無しの場合では大文字から小文字の順にソートされるが、fオプションを使うと、大文字小文字の区別なしにアルファベット順にソートされる。
　　

==== -g 


  


===== 実行結果の中央部分にあるスペースを変更するオプション。gの後に数字を指定して幅を変える。デフォルトでは3になっている。





===== 実行例　



//list[][][fontsize=xx-small]{
  ptx -g 7 file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.



  $ ptx -g 7 file.txt /実行後
       with various words.                 It contains multiple lines of text
       permuted index of/                  The ptx command will generate a
       the ptx command.                    This is a sample file for testing
       command.              This is       a sample file for testing the ptx
          /ptx command will generate       a permuted index of these words.
            file for testing the ptx       command.            This is a sample
       index of/             The ptx       command will generate a permuted
       with various/              It       contains multiple lines of text
                    This is a sample       file for testing the ptx command.
               This is a sample file       for testing the ptx command.
                The ptx command will       generate a permuted index of these/
           /will generate a permuted       index of these words.
       ptx command.             This       is a sample file for testing the
                It contains multiple       lines of text with various words.
       various/          It contains       multiple lines of text with
          It contains multiple lines       of text with various words.
           generate a permuted index       of these words.        /command will
        /ptx command will generate a       permuted index of these words.
         sample file for testing the       ptx command.               This is a
       permuted index/           The       ptx command will generate a
       command.            This is a       sample file for testing the ptx
           This is a sample file for       testing the ptx command.
          contains multiple lines of       text with various words.          It
           a sample file for testing       the ptx command.             This is
                 a permuted index of       these words.          /will generate
         multiple lines of text with       various words.           It contains
                     The ptx command       will generate a permuted index of/
              multiple lines of text       with various words.        /contains
          lines of text with various       words.                     /multiple
           a permuted index of these       words.                /will generate
//}



==== -T 


  

出力をTeXディレクティブとして生成します。TeXディレクティブは、ptxコマンドによって生成される出力形式の1つ。TeXは、文書作成システムであり、特に科学技術文書や数式を含む文書の作成に広く使用される。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptx file.txt -T
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ ptx file.txt -T /実行後
  \xx {with various words.}{}{It}{ contains multiple lines of text}{}
  \xx {permuted index of these}{}{The}{ ptx command will generate a}{}
  \xx {the ptx command.}{}{This}{ is a sample file for testing}{}
  \xx {command.}{This is}{a}{ sample file for testing the ptx}{}
  \xx {}{The ptx command will generate}{a}{ permuted index of these words.}{}
  \xx {}{sample file for testing the ptx}{command}{.}{This is a}
  \xx {index of these words}{The ptx}{command}{ will generate a permuted}{}
  \xx {with various words.}{It}{contains}{ multiple lines of text}{}
  \xx {}{This is a sample}{file}{ for testing the ptx command.}{}
  \xx {}{This is a sample file}{for}{ testing the ptx command.}{}
  \xx {words.}{The ptx command will}{generate}{ a permuted index of these}{}
  \xx {}{will generate a permuted}{index}{ of these words.}{command}
  \xx {ptx command.}{This}{is}{ a sample file for testing the}{}
  \xx {}{It contains multiple}{lines}{ of text with various words.}{}
  \xx {various words.}{It contains}{multiple}{ lines of text with}{}
  \xx {}{It contains multiple lines}{of}{ text with various words.}{}
  \xx {}{will generate a permuted index}{of}{ these words.}{ptx command}
  \xx {}{The ptx command will generate a}{permuted}{ index of these words.}{}
  \xx {}{a sample file for testing the}{ptx}{ command.}{This is}
  \xx {permuted index of these}{The}{ptx}{ command will generate a}{}
  \xx {command.}{This is a}{sample}{ file for testing the ptx}{}
  \xx {}{This is a sample file for}{testing}{ the ptx command.}{}
  \xx {}{It contains multiple lines of}{text}{ with various words.}{}
  \xx {}{is a sample file for testing}{the}{ ptx command.}{This}
  \xx {}{generate a permuted index of}{these}{ words.}{command will}
  \xx {}{multiple lines of text with}{various}{ words.}{It contains}
  \xx {these words.}{The ptx command}{will}{ generate a permuted index of}{}
  \xx {}{contains multiple lines of text}{with}{ various words.}{It}
  \xx {}{lines of text with various}{words}{.}{multiple}
  \xx {}{a permuted index of these}{words}{.}{will generate}
//}




==== -S 


  

行の終わりまたは文の終わりを指定するために使用される。具体的な正規表現を指定する必要がある。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptx -S '\.|\?|!' file.txt
  //文の終わりを .(ピリオド),?,!に設定。
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.


  $ ptx -S '\.|\?|!' file.txt
  　   /for testing the ptx command.   It contains multiple lines of text/
        /of text with various words.   The ptx command will generate a/
   the ptx command. It/                This is a sample file for testing
   command. It contains/     This is   a sample file for testing the ptx
    /. The ptx command will generate   a permuted index of these words.
     sample file for testing the ptx   command. It contains multiple/    /a
        /with various words. The ptx   command will generate a permuted/
    /for testing the ptx command. It   contains multiple lines of text/
   It contains/     This is a sample   file for testing the ptx command.
               This is a sample file   for testing the ptx command. It/
        /words. The ptx command will   generate a permuted index of these/
            will generate a permuted   index of these words.       /command
   ptx command. It/             This   is a sample file for testing the
      /command. It contains multiple   lines of text with various words./
       /the ptx command. It contains   multiple lines of text with/
       /. It contains multiple lines   of text with various words. The/
      will generate a permuted index   of these words.         /ptx command
     The ptx command will generate a   permuted index of these words.    /.
      /a sample file for testing the   ptx command. It contains multiple/
    /of text with various words. The   ptx command will generate a/
   command. It/            This is a   sample file for testing the ptx
           This is a sample file for   testing the ptx command. It/
    /. It contains multiple lines of   text with various words. The ptx/
       /is a sample file for testing   the ptx command. It contains/
        generate a permuted index of   these words.           /command will
        /multiple lines of text with   various words. The ptx command/
     /various words. The ptx command   will generate a permuted index of/
     contains multiple lines of text   with various words. The ptx/   /. It
         /lines of text with various   words. The ptx command will/
           a permuted index of these   words.                /will generate
//}




==== -r 


  

各入力行の先頭の非空白文字を参照IDとして扱うために使用される。参照IDは行のテキストとは別に扱われ、インデックス生成時にそれぞれの行に関連付けられる。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptx -r file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{

  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.


  $ ptx -r file.txt /実行後
  This   ptx command.               is   a sample file for testing the
  The        ptx command will generate   a permuted index of these/
  This        file for testing the ptx   command.             is a sample
  The    permuted index of/        ptx   command will generate a
  It     text with various words/        contains multiple lines of
  This   command.          is a sample   file for testing the ptx
  This                is a sample file   for testing the ptx command.
  The    these/       ptx command will   generate a permuted index of
  The        /will generate a permuted   index of these words.
  This   the ptx command.                is a sample file for testing
  It     words.      contains multiple   lines of text with various
  It     various words.       contains   multiple lines of text with
  It           contains multiple lines   of text with various words.
  The        generate a permuted index   of these words.    /command will
  The      ptx command will generate a   permuted index of these words.
  This     sample file for testing the   ptx command.                is a
  The    permuted index of these/        ptx command will generate a
  This   ptx command.             is a   sample file for testing the
  This            is a sample file for   testing the ptx command.
  It        contains multiple lines of   text with various words.
  This       a sample file for testing   the ptx command.              is
  The              a permuted index of   these words.      /will generate
  It       multiple lines of text with   various words.          contains
  The    of these/         ptx command   will generate a permuted index
  It            multiple lines of text   with various words.     contains
  It        lines of text with various   words.                 /multiple
  The        a permuted index of these   words.                 /generate
//}


-Aオプションでは左端にファイル名と行番号が表現されるが、-rオプションでは各行の先頭に来る単語「This」,「The」,「It」が左端に表示される。



==== -w 


  

出力行の長さを指定した数字によって設定することができるオプション。




===== 実行例.1　



//list[][][fontsize=xx-small]{
  ptx -w 20 file.txt
//}





===== 実行結果.1　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ ptx -w 20 file.txt /実行後

             It/
             The ptx/
   a/        This is
       /is   a sample/
          /   a/
      /ptx   command.
      /ptx   command/
        It   contains/
          /   file for/
     /file   for/
     /will   generate/
          /   index of/
      This   is a/
          /   lines of/
          /   multiple/
    /lines   of text/
    /index   of these/
        /a   permuted/
      /the   ptx/
       The   ptx/
     /is a   sample/
      /for   testing/
       /of   text/
          /   the ptx/
       /of   these/
     /with   various/
          /   will/
     /text   with/
          /   words.
    /these   words.
//}



===== 実行例.2　



//list[][][fontsize=xx-small]{
  ptx -w 100 file.txt
//}





===== 実行結果.2　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ ptx -w 100 file.txt /実行後


     words.                                          It contains multiple lines of text with various
   of these words.                                   The ptx command will generate a permuted index
   command.                                          This is a sample file for testing the ptx
                                           This is   a sample file for testing the ptx command.
                     The ptx command will generate   a permuted index of these words.
         This is a sample file for testing the ptx   command.
   words.                                  The ptx   command will generate a permuted index of these
   words.                                       It   contains multiple lines of text with various
                                  This is a sample   file for testing the ptx command.
                             This is a sample file   for testing the ptx command.
                              The ptx command will   generate a permuted index of these words.
          The ptx command will generate a permuted   index of these words.
                                              This   is a sample file for testing the ptx command.
                              It contains multiple   lines of text with various words.
                                       It contains   multiple lines of text with various words.
                        It contains multiple lines   of text with various words.
        ptx command will generate a permuted index   of these words.                                The
                   The ptx command will generate a   permuted index of these words.
             This is a sample file for testing the   ptx command.
   these words.                                The   ptx command will generate a permuted index of
                                         This is a   sample file for testing the ptx command.
                         This is a sample file for   testing the ptx command.
                     It contains multiple lines of   text with various words.
                 This is a sample file for testing   the ptx command.
     ptx command will generate a permuted index of   these words.
                        The
           It contains multiple lines of text with   various words.
                                   The ptx command   will generate a permuted index of these words.
                It contains multiple lines of text   with various words.
      contains multiple lines of text with various   words.




//}



==== -b 


  

単語の区切りをコンマ(,)やピリオド(.)などの文字で指定することができる。-bオプションを使用しない場合は、タブ文字（\t）、改行文字（\n）、およびスペースが単語の区切りとして扱われる。指定方法は、テキストファイルに記載された文字を参照する。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptx -b separators.txt file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ cat  separators.txt /単語を区切る文字の出力
  .
  ,
  ;


  $ ptx -b separators.txt file.txt /実行後

   .                                   It contains multiple lines of text with various words　
   .                                   The ptx command will generate a permuted index of these words
   .                                   This is a sample file for testing the ptx command



//}


上の例ではピリオド(.)がヒットし、file.txt内の各1文が単語として区切られている。



==== -o 


  

順序索引するワードの指定を、ファイル指定によって行うオプション。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptx -o keywords.txt file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ cat keywords.txt /順序索引するワード表示
  It
  The
  This
  a
  command


  $  ptx -o keywords.txt file.txt /実行後
   with various words.                 It contains multiple lines of text
   permuted index of these/            The ptx command will generate a
   the ptx command.                    This is a sample file for testing
   command.                  This is   a sample file for testing the ptx
       The ptx command will generate   a permuted index of these words.
     sample file for testing the ptx   command.                   This is a
   index of these words/     The ptx   command will generate a permuted
//}



==== -i 


  

順序索引しないワードをテキストファイルで指定する。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptx -i ignore.txt file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ cat ignore.txt /順序索引しないワードの表示
  It
  The
  This
  a
  command

  $ ptx -i ignore.txt file.txt
  with various words.            It    contains multiple lines of text
                    This is a sample   file for testing the ptx command.
               This is a sample file   for testing the ptx command.
   words.       The ptx command will   generate a permuted index of these
            will generate a permuted   index of these words.       /command
   ptx command.                 This   is a sample file for testing the
                It contains multiple   lines of text with various words.
   various words.        It contains   multiple lines of text with
          It contains multiple lines   of text with various words.
      will generate a permuted index   of these words.         /ptx command
     The ptx command will generate a   permuted index of these words.
       a sample file for testing the   ptx command.                 This is
   permuted index of these/      The   ptx command will generate a
   command.                This is a   sample file for testing the ptx
           This is a sample file for   testing the ptx command.
       It contains multiple lines of   text with various words.
        is a sample file for testing   the ptx command.                This
        generate a permuted index of   these words.           /command will
         multiple lines of text with   various words.           It contains
   these words.      The ptx command   will generate a permuted index of
     contains multiple lines of text   with various words.               It
          lines of text with various   words.                     /multiple
           a permuted index of these   words.                /will generate

//}



==== -R 


  

参照行を右に配置する。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptx -RA file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ ptx -RA file.txt
  with various words.                 It contains multiple lines of text     file.txt:2
  permuted index of these/            The ptx command will generate a        file.txt:3
  the ptx command.                    This is a sample file for testing      file.txt:1
  command.                  This is   a sample file for testing the ptx      file.txt:1
      The ptx command will generate   a permuted index of these words.       file.txt:3
    sample file for testing the ptx   command.                   This is a   file.txt:1
  index of these words/     The ptx   command will generate a permuted       file.txt:3
  with various words.            It   contains multiple lines of text        file.txt:2
                   This is a sample   file for testing the ptx command.      file.txt:1
              This is a sample file   for testing the ptx command.           file.txt:1
  words.       The ptx command will   generate a permuted index of these     file.txt:3
           will generate a permuted   index of these words.       /command   file.txt:3
  ptx command.                 This   is a sample file for testing the       file.txt:1
               It contains multiple   lines of text with various words.      file.txt:2
  various words.        It contains   multiple lines of text with            file.txt:2
         It contains multiple lines   of text with various words.            file.txt:2
     will generate a permuted index   of these words.         /ptx command   file.txt:3
    The ptx command will generate a   permuted index of these words.         file.txt:3
      a sample file for testing the   ptx command.                 This is   file.txt:1
  permuted index of these/      The   ptx command will generate a            file.txt:3
  command.                This is a   sample file for testing the ptx        file.txt:1
          This is a sample file for   testing the ptx command.               file.txt:1
      It contains multiple lines of   text with various words.               file.txt:2
      is a sample file for testing   the ptx command.
  This   file.txt:1
       generate a permuted index of   these words.           /command will   file.txt:3
        multiple lines of text with   various words.           It contains   file.txt:2
  these words.      The ptx command   will generate a permuted index of      file.txt:3
    contains multiple lines of text   with various words.
    It   file.txt:2
  
  
//}


オプション-Aで表示されるファイル名と行番号が右に表示される


==== -O 


  

出力をROFFディレクティブとして生成する。ROFFディレクティブは、テキストのフォーマットやスタイルを指定するためのコマンドセットである。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptx -O file.txt > output.roff
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat file.txt /実行前

  This is a sample file for testing the ptx command.
  It contains multiple lines of text with various words.
  The ptx command will generate a permuted index of these words.

  $ ptx -O file.txt > output.roff 

  $ cat output.roff /実行後
  .xx "with various words." "" "It contains multiple lines of text" ""
  .xx "permuted index of these/" "" "The ptx command will generate a" ""
  .xx "the ptx command." "" "This is a sample file for testing" ""
  .xx "command." "This is" "a sample file for testing the ptx" ""
  .xx "" "The ptx command will generate" "a permuted index of these words." ""
  .xx "" "sample file for testing the ptx" "command." "This is a"
  .xx "index of these words/" "The ptx" "command will generate a permuted" ""
  .xx "with various words." "It" "contains multiple lines of text" ""
  .xx "" "This is a sample" "file for testing the ptx command." ""
  .xx "" "This is a sample file" "for testing the ptx command." ""
  .xx "words." "The ptx command will" "generate a permuted index of these" ""
  .xx "" "will generate a permuted" "index of these words." "/command"
  .xx "ptx command." "This" "is a sample file for testing the" ""
  .xx "" "It contains multiple" "lines of text with various words." ""
  .xx "various words." "It contains" "multiple lines of text with" ""
  .xx "" "It contains multiple lines" "of text with various words." ""
  .xx "" "will generate a permuted index" "of these words." "/ptx command"
  .xx "" "The ptx command will generate a" "permuted index of these words." ""
  .xx "" "a sample file for testing the" "ptx command." "This is"
  .xx "permuted index of these/" "The" "ptx command will generate a" ""
  .xx "command." "This is a" "sample file for testing the ptx" ""
  .xx "" "This is a sample file for" "testing the ptx command." ""
  .xx "" "It contains multiple lines of" "text with various words." ""
  .xx "" "is a sample file for testing" "the ptx command." "This"
  .xx "" "generate a permuted index of" "these words." "/command will"
  .xx "" "multiple lines of text with" "various words." "It contains"
  .xx "these words." "The ptx command" "will generate a permuted index of" ""
  .xx "" "contains multiple lines of text" "with various words." "It"
  .xx "" "lines of text with various" "words." "/multiple"
  .xx "" "a permuted index of these" "words." "/will generate"


  
//}





==== -F 


  

行の切り詰めを示すためのフラグを指定するために使用さる。行の切り詰めとは、テキストが行の幅に収まらずに途中で切り捨てられた場合に、それを示すための特定のフラグや記号を挿入することを指す。




===== 実行例　



//list[][][fontsize=xx-small]{
  ptx -F "/---" input.txt > output.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat input.txt /実行前
  This is a sample text that is too long to fit within a single line. /---

  $ ptx -F "/---" input.txt > output.txt /実行後

  $ $ cat output.txt
     is too long to fit/---            This is a sample text that
   long to fit/---           This is   a sample text that is too
           is too long to fit within   a single line. /---         /---that
        /---text that is too long to   fit within a single line. /-/---
   long to fit/---              This   is a sample text that is too
           /---is a sample text that   is too long to fit within a/---
              to fit within a single   line. /---           /---is too long
       /---a sample text that is too   long to fit within a single/---
   to fit/---              This is a   sample text that is too long
            too long to fit within a   single line. /---        /---that is
                    This is a sample   text that is too long to fit/---
               This is a sample text   that is too long to fit/---
           /---text that is too long   to fit within a single line./---
        /---is a sample text that is   too long to fit within a/---
         /---that is too long to fit   within a single line. /---

//}



==== -G 


  

System Vのptxコマンドと同様の動作をするようにptxコマンドを設定する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ ptx -G input.txt > output.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat input.txt /実行前
  This is line 1.
  This is line 2.
  This is line 3.

  $  ptx -G input.txt > output.txt

  $ cat output.txt
  .xx "" "This is line" "1." ""
  .xx "" "This is line" "2." ""
  .xx "" "This is line" "3." ""
  .xx "" "" "This is line 1." ""
  .xx "" "" "This is line 2." ""
  .xx "" "" "This is line 3." ""
  .xx "" "This" "is line 1." ""
  .xx "" "This" "is line 2." ""
  .xx "" "This" "is line 3." ""
  .xx "" "This is" "line 1." ""
  .xx "" "This is" "line 2." ""
  .xx "" "This is" "line 3." ""
//}






#@# 

== pwck

Linuxシステムでユーザやグループのパスワードファイルをチェックするためのコマンド。パスワードファイル内のエントリに関する問題を検出し、修正するのに役立つ。このコマンドを実行するにはrootユーザまたはsudo権限を持つユーザである必要がある。



===== 実行例 



//list[][][fontsize=xx-small]{
  pwck
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
    user 'lp': directory '/var/spool/lpd' does not exist
    user 'news': directory '/var/spool/news' does not exist
    user 'uucp': directory '/var/spool/uucp' does not exist
    user 'www-data': directory '/var/www' does not exist
    user 'list': directory '/var/list' does not exist
    user 'irc': directory '/run/ircd' does not exist
    user 'gnats': directory '/var/lib/gnats' does not exist
    user '_apt': directory '/nonexistent' does not exist
    user 'nobody': directory '/nonexistent' does not exist
    pwck: no changes
//}



=== オプション一覧




==== -r




読み込み専用（書き込みできない）でコマンドを実行する



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo pwck -r
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  user 'john' has an invalid home directory '/home/john'
  user 'jane' has an invalid shell '/bin/false'
  user 'testuser' is missing a password entry
//}


この実行結果のから、ユーザー「john」のホームディレクトリが無効であること、ユーザー「jane」のシェルが無効であること、そして「testuser」のパスワードエントリが存在しないことが確認できる。





==== -q 


  

システムやグループ設定に関するエラーや警告を表示するオプション。




===== 実行例　



//list[][][fontsize=xx-small]{
  pwck -q
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  user 'john' has an invalid home directory '/home/john'
  user 'jane' has an invalid shell '/bin/false'
//}


この実行結果から、ユーザー「john」のホームディレクトリが無効であること、ユーザー「jane」のシェルが無効であることがわかる



==== -R 


  

指定されたchrootディレクトリ内の設定ファイルを使用して、pwckコマンドを実行するためのオプション。chrootとは、プロセスが利用できるルートディレクトリを変更することを指す。




===== 実行例　



//list[][][fontsize=xx-small]{
  pwck -R /mnt/chroot
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  user 'john': directory '/mnt/chroot/home/john' does not exist
  user 'jane': directory '/mnt/chroot/home/jane' does not exist
//}



==== -s 


  

パスワードファイル (/etc/passwd) と shadow ファイル (/etc/shadow) のエントリを UID (ユーザー識別子) の昇順でソートするオプション。




===== 実行例　



//list[][][fontsize=xx-small]{
  pwck -s
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示なし
//}







#@# 

== pwconv



   
etc/passwd（パスワードファイル）をシャドウパスワードファイルへ変換するコマンド。
シャドウパスワードファイルとは、パスワードのデータを一般ユーザから保護するために使用するファイルである。
このコマンドを実行するには、管理者権限を持つユーザが使用する必要がある。



===== 実行例 



//list[][][fontsize=xx-small]{
  pwconv
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ sudo cat passwd | grep user　/実行前のパスワードファイル確認

  user:$6$tR9u4.BHS～:1000:1000:user:/home/user:/bin/bash

 ここでは、パスワードファイルの中にあるユーザエントリを表示している。
 表示されたエントリは:(コロン)によって区切られている。

  ・ユーザ名：user
  ・パスワード：$6$tR9u4.BHS～ (本来なら長めの文字列が表示される。)
  ・ユーザID：1000
  ・グループID：1000
  ・ユーザ情報：user
  ・ホームディレクトリ：/home/user
  ・ログインシェル：/bin/bash
  ここに表示されているパスワードはLinuxで使用されているハッシュ関数に
  よってハッシュ化された文字列である。

  $ pwconv  //実行

  $ cat passwd | grep user
  user:x:1000:1000:user:/home/user:/bin/bash

  　pwconvを実行してからもう一度パスワードファイルを確認すると、
  パスワードのフィールドを確認するとxとなっており、ファイルに
  パスワードが記載されていないことが確認できる。

  $ sudo cat shadow- | grep user /シャドウパスワードファルの確認。
 user:$6$tR9u4.BHS～:19635:0:99999:7:::
//}



シャドウパスワードファルを確認すると、ユーザのエントリが記載されており、\$6\$tR9u4.BHS～のようにパスワード情報が記載されている。
パスワードのほかにも、最終パスワード変更日やパスワード有効期限などが記載されている。
このシャドウパスワードファル確認するためには、管理者権限を持つユーザである必要がある。
#@# 

== pwd

自分が現在自分がいるディレクトリを表示するコマンド



===== 実行例 



//list[][][fontsize=xx-small]{
  pwd
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  /home/user 　//現在自分がいるディレクトリを表示
//}



=== オプション一覧




==== -L




オプション無しと同じ挙動をします。オプションをつけても付けなくてもいい。



===== 実行例 



//list[][][fontsize=xx-small]{
  pwd -L
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  /home/user  //現在自分がいるディレクトリを表示
//}


==== -P 




このオプションは、カレントディレクトリの物理的なパスを表示する。シンボリックリンクが含まれる場合でも、シンボリックリンクが解決され、実際のディレクトリのパスが表示される。別のファイルやディレクトリへの参照を作成するための特殊なファイル。






===== 実行例　



//list[][][fontsize=xx-small]{
  pwd -P
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ln -s /tmp tmp  /現在のディレクトリにシンボリックリンクを貼る

  $ ls
  tmp //現在のディレクトリで/（ルート）直下のtmpを参照できる
  $ cd tmp
  $ pwd    //オプション無し
  home/user/Prmn/pwd

  $ pwd -P //オプションあり
  /tmp
//}

#@# 

== pwd

PWD(1) ユーザーコマンド PWD(1)

名前
pwd - 現在の作業ディレクトリの名前を表示する

概要
pwd 

説明
現在の作業ディレクトリの完全なファイル名を表示します。

-L もしくは --logical

        環境変数のPWDを使用し、シンボリックリンクが含まれていても使用する

-P もしくは --physical

        すべてのシンボリックリンクを避ける

--help ヘルプを表示して終了する

 --version

        バージョン情報を出力して終了する

オプションが指定されていない場合、-Pが仮定されます。

注意: シェルには通常、ここで説明されているバージョンよりも優先される独自のpwdがある可能性があります。オプションの詳細については、シェルのドキュメントを参照してください。





===== 実行例 



//list[][][fontsize=xx-small]{
  pwd
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  /home/user 　//現在自分がいるディレクトリを表示
//}



=== オプション一覧




==== -L




オプション無しと同じ挙動をします。オプションをつけても付けなくてもいい。



===== 実行例 



//list[][][fontsize=xx-small]{
  pwd -L
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  /home/user  //現在自分がいるディレクトリを表示
//}


==== -P 




このオプションは、カレントディレクトリの物理的なパスを表示する。シンボリックリンクが含まれる場合でも、シンボリックリンクが解決され、実際のディレクトリのパスが表示される。シンボリックリンクとは別のファイルやディレクトリへの参照を作成するための特殊なファイル。






===== 実行例　



//list[][][fontsize=xx-small]{
  pwd -P
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ln -s /tmp tmp  /現在のディレクトリにシンボリックリンクを貼る

  $ ls
  tmp //現在のディレクトリで/（ルート）直下のtmpを参照できる
  $ cd tmp
  $ pwd    //オプション無し
  home/user/Prmn/pwd

  $ pwd -P //オプションあり
  /tmp
//}

#@# 

== pwdx

プロセスの作業ディレクトリを表示するコマンド



===== 実行例 



//list[][][fontsize=xx-small]{
  pwdx [PSID]
//}



===== 実行結果.1　



//list[][][fontsize=xx-small]{
  $ ps //プロセスの確認
    PID TTY          TIME CMD
  1071025 pts/0    00:00:00 bash
  1072332 pts/0    00:00:00 ps

  $ pwdx 1071025 //bashを対象にpwdxを実行
  1071025: /home/user/
//}






===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ps aux //Linuxのシステムが動かしているプロセスを確認
  USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
  root           1  0.0  0.0 167728 13464 ?        Ss   Oct05   1:44 /lib/systemd/systemd --system --deserialize 71
  root           2  0.0  0.0      0     0 ?        S    Oct05   0:00 [kthreadd]
  root           3  0.0  0.0      0     0 ?        I<   Oct05   0:00 [rcu_gp]
  root           4  0.0  0.0      0     0 ?        I<   Oct05   0:00 [rcu_par_gp]
  root           5  0.0  0.0      0     0 ?        I<   Oct05   0:00 [slub_flushwq]
  ・
  ・
  ・

 
  $ sudo pwdx 1
 1: / 
  $ sudo pwdx 2
 2: /
  $ sudo pwdx 3
 3: /
  $ sudo pwdx 4
 4: /
  $ sudo pwdx 5
 5: /
 ・
 ・
 ・
//}

この例では、Linuxのシステムが自動的に実行しているプロセスに対してpwdxを行った。このことからシステムが動かしているプロセスは/(ルート)で動かしていることがわかる。#@# 

== pwunconv

pwconvコマンドでシャドウ化したetc/passwdを元に戻すコマンド。シャドウ化とは、パスワードファイルを一般ユーザから閲覧されないようにするための工夫。



===== 実行例 



//list[][][fontsize=xx-small]{
  pwunconv
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat passwd | grep user //実行前のパスワードファイルを確認
  user:x:1000:1000:user:/home/user:/bin/bash
  ここでは、パスワードファイルの中にあるユーザエントリを表示している。
  表示されたエントリは：(コロン)によって区切られている。
  ・ユーザ名：usre
  ・パスワード：x 
  ・ユーザID：1000
  ・グループID：1000
  ・ユーザ情報：user
  ・ホームディレクトリ：/home/user
  ・ログインシェル：/bin/bash
  パスワードフィールドがxとなっている。
  これは、パスワードがシャドウ化により閲覧ができなくなっているためである。

  $ pwunconv //実行
  $ cat passwd | grep user //実行後のパスワードファイルを確認
  user:$6$tR9u4.BHS～:1000:1000:user:/home/user:/bin/bash
//}








エントリの中にパスワードが表示された。$6$tR9u4.BHS～はLinuxのシステムで使用されるハッシュ関数によって生成される。

#@# 

== py3compile

python3のソースファイルをバイトコンパイルするためのコマンド。Pythonの実行には通常、ソースコードをもとに仮想マシンからバイトコードに変化し、そのバイトコードを用いてPCの機械言語に翻訳する必要がある。ソースコードからバイトコードへ変換することをバイトコンパイルという。py3compileの使用目的は、あらかじめソースコドをバイトコンパイルすることで、プログラムの実行までの時間を短くするために使われることである。



===== 実行例 



//list[][][fontsize=xx-small]{
   py3compile test.py
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls  //実行前
  test.py

  $ py3compile test.py // 実行

  $ ls  //実行後
  __pycache__  test.py  //__pycache__ディレクトリが作成される

  $ cd __pycache__

  $ ls test.cpython-310.pyc //.pycが作成される。
//}



=== オプション一覧




==== -f




タイムスタンプに関係なく常にバイトコードファイルを再構築するためのオプション。つまり、ソースファイル（.pyファイル）の最終更新日時とバイトコードファイル（.pycファイル）の最終更新日時を比較し、ソースファイルが変更されていなくてもバイトコードファイルを再構築することを指す。



===== 実行例 



//list[][][fontsize=xx-small]{
  py3compile -f test.py
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ pwd
  /home/user/py3compile/__pycache__
  $ ls
  test.cpython-310.pyc //.pycファイルがすでにある状態

  $cd ..
  $pwd
  home/user/py3compile
  $ ls
  __pycache__  test.py

  $ py3compile -f test.py //実行
  $ cd __pycache__
  $ ls 
  test.cpython-310.pyc // 同じ.pyが生成されている。
//}


==== -O 


  

pyoファイルにコンパイル




===== 実行例　



//list[][][fontsize=xx-small]{
  py3compile -O test.py
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls
  test.py

  $ py3compile -O test.py

  $ ls
  __pycache__  test.py

  $ cd __pycache__
  $ ls
  test.cpython-310.opt-1.pyc //.pyoファイルが生成される
//}


==== -v 


  

コンパイルの際に、詳細な実行情報を表示




===== 実行例　



//list[][][fontsize=xx-small]{
  $ py3compile -v test.py
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  D: py3compile:253: argv: ['/usr/bin/py3compile', '-vf', 'test.py']
  D: py3compile:254: options: {'verbose': True, 'force': True, 'optimize': False, 'package': None, 'vrange': None, 'regexpr': None}
  D: py3compile:255: args: ['test.py']
//}


#@# 

== pydoc3

Pythonのモジュール、クラス、メソッド等のドキュメントを生成するためのツール。ドキュメントを作成することで、モジュールに含まれる関数やクラスを確認できる。


===== 実行例 



//list[][][fontsize=xx-small]{
  pydoc3 math
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Help on built-in module math:

    NAME
        math

    DESCRIPTION
        This module provides access to the mathematical functions
        defined by the C standard.

    FUNCTIONS
    acos(x, /)
        Return the arc cosine (measured in radians) of x.

        The result is between 0 and pi.

    acosh(x, /)
        Return the inverse hyperbolic cosine of x.

    asin(x, /)
        Return the arc sine (measured in radians) of x.

        The result is between -pi/2 and pi/2.

    asinh(x, /)
        Return the inverse hyperbolic sine of x.

    atan(x, /)
        Return the arc tangent (measured in radians) of x.

        The result is between -pi/2 and pi/2.

    atan2(y, x, /)
        Return the arc tangent (measured in radians) of y/x.

        Unlike atan(y/x), the signs of both x and y are considered.

    atanh(x, /)
        Return the inverse hyperbolic tangent of x.

    ceil(x, /)
        Return the ceiling of x as an Integral.

        This is the smallest integer >= x.
        ・
        ・
        ・

  DATA
    e = 2.718281828459045
    inf = inf
    nan = nan
    pi = 3.141592653589793
    tau = 6.283185307179586

//}

ドキュメントには、「DESCRIPTION」、「FUNCTIONS」、「DATA」の3つのタグがある。
DESCRIPTION：モジュールの説明文
FUNCTIONS：モジュールに含まれている関数を表示
DATA：モジュール内で使用されている定数の表示

上の例では、mathモジュールのドキュメントを表示している。

===== 実行結果からmathモジュールには、acos()やasin()などの関数が含まれていることが確認できる。また、自然対数（e）や演習率などの定数も確認できる。




=== オプション一覧




==== -w




指定したモジュールのドキュメントを、HTMLドキュメントとして現在いるディレクトリに作成する。



===== 実行例 



//list[][][fontsize=xx-small]{
  pydoc3 -w math
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls //現在のディレクトリにあるファイルを確認
  file.txt
  $ pydoc3 -w math //コマンドの実効
  wrote math.html 
  $ ls　//実効後のファイルを確認
  file.txt math.html
//}


==== -b 


  

pydocを使用して任意の未使用ポート上でHTTPサーバーをローカルホストで起動し、ウェブブラウザにウェブサイトが自動的に開かれる。このサイトでは、モジュールを検索しドキュメントを表示することができる。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ pydoc3 -b
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Server ready at http://localhost:44161/
  Server commands: [b]rowser, [q]uit
  server>
//}


実行すると、サーバが起動して表示されたURLからアクセスできる。また、




==== -n 


  

指定されたホスト名でHTTPサーバを起動して、ドキュメントを表示するウェブサイトを表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  pydoc3 -n 10.20.30.40
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Server ready at http://10.20.30.40:41009/
  Server commands: [b]rowser, [q]uit
  server> 
//}



==== -p 


  

指定したポート番号でHTTPサーバを起動して、ドキュメントを表示するウェブサイトを表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  pydoc3 -p 5000
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Server ready at http://localhost:5000/
  Server commands: [b]rowser, [q]uit
  server>
//}


==== -k




キーワードを指定して、それに関するモジュールを検索する



===== 実行例 



//list[][][fontsize=xx-small]{
  pydoc3 -k math
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  cmath - This module provides access to mathematical functions for complex
  math - This module provides access to the mathematical functions
  numpy._core._multiarray_umath
  numpy._core.umath
  numpy.core._multiarray_umath
  numpy.core._umath_tests
  numpy.core.tests.test_scalarmath
  numpy.core.tests.test_umath
  numpy.core.tests.test_umath_accuracy
  numpy.core.tests.test_umath_complex
  numpy.core.umath - Create the numpy.core.umath namespace for backward compatibility. In v1.16
  numpy.core.umath_tests - Shim for _umath_tests to allow a deprecation period for the new name.
  numpy.lib.scimath - Wrapper functions to more user-friendly calling of certain math functions
  numpy.linalg._umath_linalg
//}


上の例では、キーワード「math」を含んでいるモジュールの検索を行っている。


===== 実行結果から"cmath"、"math"、"numpy"などのモジュールが表示されている。

#@# 

== python3

python 





DESCRIPTION
Pythonは、解釈型で、対話的に使えるオブジェクト指向のプログラミング言語です。Pythonは、非常にわかりやすい構文と強力な機能を備えています。
PythonにはPythonチュートリアルがあり、Pythonのプログラミング入門に役立ちます。Pythonライブラリリファレンスでは、組み込みおよび標準の型、定数、関数、およびモジュールについて説明しています。また、Pythonリファレンスマニュアルでは、コア言語の構文と意味論について詳細に説明しています。Pythonの基本的な機能は、CやC++で書かれた独自のモジュールで拡張することもできます。ほとんどのシステムでは、このようなモジュールを動的にロードすることができます。Pythonは既存のアプリケーションの拡張言語としても適応可能です。インストールされたPythonモジュールやパッケージのドキュメントは、pydocプログラムを実行することで表示することができます。
COMMAND LINE OPTIONS

-B     .pyc ファイルをインポート時に書き込まない。PYTHONDONTWRITEBYTECODE も参照してください。

-b     str(bytes_instance)、str(bytearray_instance)、および bytes もしくは bytearray と str の比較について警告を表示する（-bb: エラーを発生させる）。

-c command

      実行するコマンドを指定する（次のセクションを参照）。これにより、オプションリストが終了し、以降のオプションはコマンドの引数として渡されます。

--check-hash-based-pycs mode

      ハッシュベースの .pyc ファイルの最新情報の評価方法を設定する。

-d     パーサーデバッグ出力を有効にする（専門家向け、コンパイルオプションに依存）。

-E     PYTHONPATH や PYTHONHOME のような環境変数を無視する。これらはインタプリタの動作を変更するために使用されます。

-h もしくは -? もしくは --help

      インタプリタの実行ファイルの使用方法を表示し、終了します。

-i     スクリプトが最初の引数として渡された場合、または -c オプションが使用された場合、スクリプトまたはコマンドの実行後に対話モードに入る。$PYTHONSTARTUP ファイルは読み込まれません。スクリプトが例外を発生させた場合、グローバル変数やスタックトレースを調査するのに便利です。

-I     Python を隔離モードで実行する。これには -E と -s も含まれます。隔離モードでは、sys.path にはスクリプトのディレクトリやユーザーの site-packages ディレクトリは含まれません。また、PYTHON* 環境変数も無視されます。さらに、悪意のあるコードの注入を防ぐために追加の制限が課される場合があります。

-m module-name

      名前付きモジュールを sys.path で検索し、対応する .py ファイルをスクリプトとして実行する。これにより、オプションリストが終了し、以降のオプションはモジュールの引数として渡されます。

-O     assert 文と __debug__ の値に基づく条件付きコードを削除する；コンパイル（バイトコード）ファイルの拡張子の前に .opt-1 を追加してファイル名を変更する。

-OO    -O を行い、また docstrings を破棄する；コンパイル（バイトコード）ファイルの拡張子の前に .opt-2 を追加してファイル名を変更する。

-q バージョンと著作権メッセージを表示しない。これらのメッセージは対話モード以外でも抑制されます。

-s     ユーザーサイトディレクトリを sys.path に追加しない。

-S     モジュール site のインポートとそれに関連する sys.path の操作を無効にする。site が後で明示的にインポートされた場合も、これらの操作は無効になります。

-u     標準出力と標準エラー出力ストリームを非バッファリングにする。このオプションは標準入力ストリームには影響しません。

-v     モジュールが初期化されるたびにメッセージを表示し、それがロードされる場所（ファイル名または組み込みモジュール）を示す。2回指定すると、モジュールを検索する際にチェックされる各ファイルに対してメッセージを表示します。また、終了時のモジュールのクリーンアップに関する情報も提供します。

-V もしくは --version

      実行可能ファイルの Python バージョン番号と終了メッセージを表示します。2回指定すると、ビルドに関する詳細情報も表示されます。




===== 実行例 



//list[][][fontsize=xx-small]{
  python3 hello.py
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat hello.py
  print("Hello World")
  $ python3 hello.py
  Hello World
//}



=== オプション一覧




==== -c




コマンドラインからpythonのスクリプトを直接実効するためのオプション



===== 実行例.1 



//list[][][fontsize=xx-small]{
  python3 -c "result = 2 + 3; print(result)"
//}





===== 実行結果.1　



//list[][][fontsize=xx-small]{
  5
//}



===== 実行例.2　



//list[][][fontsize=xx-small]{
  python3 -c "import math; result = math.sqrt(25); print(result)"
//}





===== 実行結果.2　



//list[][][fontsize=xx-small]{
  5.0
//}



===== 実行例2では、モジュールをインポートしている。


==== -i 


  

pythonの実行後に対話モードに入る。対話モードに入ると、式の演算や変数の定義を操作などを行うことができる。




===== 実行例　



//list[][][fontsize=xx-small]{
  python3 -i hello.py 
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat hello.py
  print("Hello World")
  $ python3 -i hello.py 
  Hello World
  >>>
  対話モードに入ると「>>>」が表示されるようになり、
  ここから入力ができる。

  $ python3 -i hello.py 
  Hello World
  >>> 2 + 3                // 2+3の計算
  5
  >>> "Hello, " + "World!" //Hello World!の表示
  'Hello, World!'
  >>> 10 > 5               //10>5が正しいかどうかを判断する
  True
  >>> len([1, 2, 3])　　　　//配列の長さを表示
  3
//}


==== -m 


  

Pythonのモジュールを直接実効するためのオプション




===== 実行例.1　



//list[][][fontsize=xx-small]{
  python3 -m mymodule
//}





===== 実行結果.1　



//list[][][fontsize=xx-small]{
  $ cat mymodule.py
  # mymodule.py

  def main():
    print("This is the main function.")

  if __name__ == '__main__':
    main()
  $ python3 -m mymodule
  This is the main function.
//}





===== 実行例.2　



//list[][][fontsize=xx-small]{
  python3 -m http.server
//}





===== 実行結果.2　



//list[][][fontsize=xx-small]{
  Serving HTTP on 0.0.0.0 port 8000 (http://0.0.0.0:8000/) ...
//}


"http://0.0.0.0:8000/" にアクセスすると、ウェブサイトがブラウザで開かれる。このサイトには、現在いるディレクトリのファイル情報が記載されている。




==== -O 


  

Pythonの最適化モードを有効するためのオプション。最適化モードにすることで、実効速度が向上する。




===== 実行例　



//list[][][fontsize=xx-small]{
  python3  -O time.py 
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat time.py
  import time

  def calculate_sum(n):
      start_time = time.time()
      total = 0
      for i in range(1, n+1):
          total += i
      end_time = time.time()
      execution_time = end_time - start_time
      print(f"Sum of numbers from 1 to {n} is: {total}")
      print(f"Execution Time: {execution_time} seconds")

  if __name__ == "__main__":
      calculate_sum(10000000)

  このコードは、calculate_sum関数が与えられた範囲の数値の総和を計算する。
  計算が終わると、プロセスの実行時間が表示される。


  $ python3 time.py  //最適化モードなし
  Sum of numbers from 1 to 10000000 is: 50000005000000
  Execution Time: 0.5327153205871582 seconds
  $ python3 -O time.py //最適化モードを適用
  Sum of numbers from 1 to 10000000 is: 50000005000000
  Execution Time: 0.5239436626434326 seconds

//}


オプション無しで実行した場合、時間が0.532sであるのに対し、

-Oオプションありで実行すると時間が0.523sとなり、実行時間が短くなっていることが確認できる。




==== -B 


  

Python実行時に.pycファイルを生成しないようにするためのオプション。




===== 実行例　



//list[][][fontsize=xx-small]{
  python3 -Bc "import mymodule"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat mymodule.py //使用するモジュールの表示
  # mymodule.py

  def main():
      print("This is the main function.")

  if __name__ == '__main__':
      main()


  $ ls //ディレクトリにあるファイルを確認
  mymodule.py
  $ python3 -c "import mymodule" //-Bオプション無しで実行
  $ ls
  mymodule.py  __pycache__

  __pycache__ディレクトリが作成されており、その中には.pycファイルが存在する。


  $ rm -r  __pycache__ // __pycache__の削除
  $ python3 -Bc "import mymodule"  //-Bオプションありで実行
  $ ls 
  mymodule.py  //__pycache__が作成されていない
//}


==== -v 


  

Pythonが実行される際に行われる様々な処理や読み込まれるモジュールなどの情報が表示される。




===== 実行例　



//list[][][fontsize=xx-small]{
  python3 -v hello.py
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  import _frozen_importlib # frozen
  import _imp # builtin
  import '_thread' # <class '_frozen_importlib.BuiltinImporter'>
  import '_warnings' # <class '_frozen_importlib.BuiltinImporter'>
  import '_weakref' # <class '_frozen_importlib.BuiltinImporter'>
  import '_io' # <class '_frozen_importlib.BuiltinImporter'>
  import 'marshal' # <class '_frozen_importlib.BuiltinImporter'>
  import 'posix' # <class '_frozen_importlib.BuiltinImporter'>
  import '_frozen_importlib_external' # <class '_frozen_importlib.FrozenImporter'>
  # installing zipimport hook
  import 'time' # <class '_frozen_importlib.BuiltinImporter'>
  import 'zipimport' # <class '_frozen_importlib.FrozenImporter'>
  # installed zipimport hook
  # /usr/lib/python3.10/encodings/__pycache__/__init__.cpython-310.pyc matches /usr/lib/python3.10/encodings/__init__.py
  # code object from '/usr/lib/python3.10/encodings/__pycache__/__init__.cpython-310.pyc'
  # /usr/lib/python3.10/__pycache__/codecs.cpython-310.pyc matches /usr/lib/python3.10/codecs.py
  # code object from '/usr/lib/python3.10/__pycache__/codecs.cpython-310.pyc'
  import '_codecs' # <class '_frozen_importlib.BuiltinImporter'>
  import 'codecs' # <_frozen_importlib_external.SourceFileLoader object at 0x7f7e6fdd32e0>

  ・
  ・
  ・
  
  # cleanup[3] wiping builtins
  # destroy _thread
  # destroy posix
  # destroy _frozen_importlib_external
  # destroy _imp
  # destroy io
  # destroy marshal
  # destroy time
  # destroy _warnings
  # destroy os
  # destroy stat
  # destroy genericpath
  # destroy _abc
  # destroy _frozen_importlib
  # destroy codecs
  # destroy sys
  # destroy encodings.aliases
  # destroy encodings.utf_8
  # destroy _codecs
  # destroy builtins
  # clear sys.audit hooks
//}


#@# 

== python3

pythonのプログラムを動かすためのコマンド



===== 実行例 



//list[][][fontsize=xx-small]{
  python3 hello.py
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat hello.py
  print("Hello World")
  $ python3 hello.py
  Hello World
//}



=== オプション一覧




==== -c




コマンドラインからpythonのスクリプトを直接実効するためのオプション



===== 実行例.1 



//list[][][fontsize=xx-small]{
  python3 -c "result = 2 + 3; print(result)"
  
//}





===== 実行結果.1　



//list[][][fontsize=xx-small]{
  5
//}



===== 実行例.2　



//list[][][fontsize=xx-small]{
  python3 -c "import math; result = math.sqrt(25); print(result)"
//}





===== 実行結果.2　



//list[][][fontsize=xx-small]{
  5.0
//}



===== 実行例2では、モジュールをインポートしている。


==== -i 


  

pythonの実行後に対話モードに入る。対話モードに入ると、式の演算や変数の定義を操作などを行うことができる。




===== 実行例　



//list[][][fontsize=xx-small]{
  python3 -i hello.py 
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat hello.py
  print("Hello World")
  $ python3 -i hello.py 
  Hello World
  >>>
  対話モードに入ると「>>>」が表示されるようになり、
  ここから入力ができる。

  $ python3 -i hello.py 
  Hello World
  >>> 2 + 3                // 2+3の計算
  5
  >>> "Hello, " + "World!" //Hello World!の表示
  'Hello, World!'
  >>> 10 > 5               //10>5が正しいかどうかを判断する
  True
  >>> len([1, 2, 3])　　　　//配列の長さを表示
  3
//}


==== -m 


  

Pythonのモジュールを直接実効するためのオプション




===== 実行例.1　



//list[][][fontsize=xx-small]{
  python3 -m mymodule
//}





===== 実行結果.1　



//list[][][fontsize=xx-small]{
  $ cat mymodule.py
  # mymodule.py

  def main():
    print("This is the main function.")

  if __name__ == '__main__':
    main()
  $ python3 -m mymodule
  This is the main function.
//}





===== 実行例.2　



//list[][][fontsize=xx-small]{
  python3 -m http.server
//}





===== 実行結果.2　



//list[][][fontsize=xx-small]{
  Serving HTTP on 0.0.0.0 port 8000 (http://0.0.0.0:8000/) ...
//}


"http://0.0.0.0:8000/"にアクセスすると、ウェブサイトがブラウザで開かれる。このサイトには、現在いるディレクトリのファイル情報が記載されている。




==== -O 


  

Pythonの最適化モードを有効するためのオプション。最適化モードにすることで、実効速度が向上する。




===== 実行例　



//list[][][fontsize=xx-small]{
  python3  -O time.py 
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat time.py
  import time

  def calculate_sum(n):
      start_time = time.time()
      total = 0
      for i in range(1, n+1):
          total += i
      end_time = time.time()
      execution_time = end_time - start_time
      print(f"Sum of numbers from 1 to {n} is: {total}")
      print(f"Execution Time: {execution_time} seconds")

  if __name__ == "__main__":
      calculate_sum(10000000)

  このコードは、calculate_sum関数が与えられた範囲の数値の総和を計算する。
  計算が終わると、プロセスの実行時間が表示される。


  $ python3 time.py  //最適化モードなし
  Sum of numbers from 1 to 10000000 is: 50000005000000
  Execution Time: 0.5327153205871582 seconds
  $ python3 -O time.py //最適化モードを適用
  Sum of numbers from 1 to 10000000 is: 50000005000000
  Execution Time: 0.5239436626434326 seconds

//}


オプション無しで実行した場合、時間が0.532sであるのに対し、

-Oオプションありで実行すると時間が0.523sとなり、実行時間が短くなっていることが確認できる。




==== -B 


  

Python実行時に.pycファイルを生成しないようにするためのオプション。




===== 実行例　



//list[][][fontsize=xx-small]{
  python3 -Bc "import mymodule"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ cat mymodule.py //使用するモジュールの表示
  # mymodule.py

  def main():
      print("This is the main function.")

  if __name__ == '__main__':
      main()


  $ ls //ディレクトリにあるファイルを確認
  mymodule.py
  $ python3 -c "import mymodule" //-Bオプション無しで実行
  $ ls
  mymodule.py  __pycache__

  __pycache__ディレクトリが作成されており、その中には.pycファイルが存在する。


  $ rm -r  __pycache__ // __pycache__の削除
  $ python3 -Bc "import mymodule"  //-Bオプションありで実行
  $ ls 
  mymodule.py  //__pycache__が作成されていない
//}


#@# 

== pzstd

ファイルの圧縮を目的としたコマンド。写真や動画などを圧縮することができる。



===== 実行例 



//list[][][fontsize=xx-small]{
  pzstd file.txt

  pzstd -9 file.txt //圧縮レベルの指定

  $ pzstd --ultra -22 file1.txt  //より高い圧縮レベルを指定できる
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
 $ ls  //ディレクトリにあるファイルを確認
 file1.txt  
 $ pzstd file1.txt
 
 file1.txt            :2500.00%   (     0 =>     25 bytes, file1.txt.zst)
 $ ls  //実行後のディレクトリにあるファイルの確認
 file1.txt file1.txt.zst
//}


上の例では、1つのファイルを指定して圧縮ファイルを作成しているが、

複数のファイルを指定して圧縮ファイルを作成できる。例えば、「file1.txt」、「file2.txt」を指定すると、「file1.txt.zst」、「file2.txt.zst」の2種類圧縮ファイルが作成される。

ハイフン(-)の後に数字を入れることで、圧縮レベルを指定できる。圧縮レベルは1から19まである。また、「--ultra」を付けることで圧縮レベルを22まで指定できる


=== オプション一覧




==== -d




.zst形式の圧縮ファイルを解凍する



===== 実行例 



//list[][][fontsize=xx-small]{
  pzstd -d file1.txt.zst
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls  //ディレクトリにあるファイルの確認
  file1.txt.zst
  $ pzstd -d file1.txt.zst　//実行
  
  file1.txt.zst       : 0 bytes
  $ ls　//実行後のディレクトリにあるファイルの確認
  file1.txt file1.txt.zst
//}


==== -p 


  

圧縮および解凍に使用するスレッド数を指定する。スレッドとは、プロセス内で実行される個々のタスクや処理の単位である。




===== 実行例　



//list[][][fontsize=xx-small]{
  pzstd -p 4 file1.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls //ディレクトリ内のファイルを確認
  file1.txt
  $ pzstd -p 4 file1.txt
  file1.txt            :2500.00%   (     0 =>     25 bytes, file1.txt.zst)
  $ ls　//実行後のディレクトリ内のファイルを確認
  file1.txt  file1.txt.zst  man.txt
//}


==== -o 


  

出力ファイルの名前を指定する。




===== 実行例　



//list[][][fontsize=xx-small]{
  pzstd -o test.zst file1.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls
  file1.txt  file1.txt.zst  
  $ pzstd -o test.zst file1.txt  // 出力ファイルの名前を"test.zst"に指定
  file1.txt            :2500.00%   (     0 =>     25 bytes, test.zst)
  $ pzstd -o output.zst file1.txt　// 出力ファイルの名前を"output.zst"に指定
  file1.txt            :2500.00%   (     0 =>     25 bytes, output.zst)
  $ ls
  file1.txt  file1.txt.zst output.zst  test.zst
//}



==== -f 


  

圧縮されたファイルを強制的に上書きする。通常、出力ファイルと同名のファイルが存在する場合、上書きするかどうかユーザに確認するメッセージが表示されるが、このオプションを使用するとメッセージが表示されなくなる。




===== 実行例　



//list[][][fontsize=xx-small]{
  pzstd -f file1.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls　//ディレクトリ内のファイルを確認
  file1.txt file1.txt.zst
  $ pzstd file1.txt　//オプション無しで実行
  pzstd: file1.txt.zst already exists; do you wish to overwrite (y/n) ? y 
  //上書きするかどうかの確認メッセージが表示される
  file1.txt            :2500.00%   (     0 =>     25 bytes, file1.txt.zst)

  $ pzstd -f file1.txt  //-fオプションで実行
  file1.txt            :2500.00%   (     0 =>     25 bytes, file1.txt.zst)
  //上書きするかどうかの確認メッセージが表示されない
//}




==== -v 


  

処理の詳細を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  pzstd -v file1.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ pzstd -v file1.txt
  Chosen frame size: 8388608
  file1.txt            :2500.00%   (     0 =>     25 bytes, file1.txt.zst)

//}


"Chosen frame size" は圧縮に使用されるフレームサイズである。上の例では、フレームサイズが8388608バイト(8メガバイト)であることがわかる。



==== -r 


  

ディレクトリを指定して、そのディレクトリ内のファイルを圧縮する。圧縮されたファイルは指定したディレクトリ内にある




===== 実行例　



//list[][][fontsize=xx-small]{
  pzstd -r test
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls //現在いるディレクトリ(/test)内のファイルを確認 
  file1.txt      file2.txt      file3.txt
  $ cd ..
  $ pzstd -r test
  $ cd test
  $ ls //実行後のtestディレクトリ内のファイル確認
  file1.txt      file2.txt      file3.txt     
  file1.txt.zst  file2.txt.zst  file3.txt.zst 
//}





