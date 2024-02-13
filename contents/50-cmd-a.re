= 頭文字が a のコマンド

#@# 

== aa-enabled

AppArmor(Linuxのセキュリティプロファイルを結びつけることで、ネットワークアクセスやRaw socketアクセス、ファイルへの読み書き実行などの機能に制限をかけることができるプログラム。例えば、あるプログラムに対して、参照しかしないファイルへの書き込み、利用するはずがないファイルへのアクセス、関係がない別のプログラムの呼び出しを禁止できる。"/etc/apparmor/parser.conf"に記述された通りに制限がかけられる。)の状態を確認するためのコマンド。AppArmorが有効になっている場合は"Yes"、無効になっている場合は"No"が出力される。



===== 実行例 



//list[][][fontsize=xx-small]{
  aa-enabled
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Yes
//}



=== オプション一覧




==== -q




何も出力しない。単にAppArmorが有効になっているかどうかを判断するための終了コード。



===== 実行例 



//list[][][fontsize=xx-small]{
  aa-enabled -q
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== -x 


  

AppArmorが有効であるとみなされるには、共有LSMインターフェイスへの排他的アクセスが必要。




===== 実行例　



//list[][][fontsize=xx-small]{
  aa-enabled -x
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Yes
//}


#@# 

== aa-exec

指定したAppArmor(Linuxのセキュリティプロファイルを結びつけることで、ネットワークアクセスやRaw socketアクセス、ファイルへの読み書き実行などの機能に制限をかけることができるプログラム。例えば、あるプログラムに対して、参照しかしないファイルへの書き込み、利用するはずがないファイルへのアクセス、関係がない別のプログラムの呼び出しを禁止できる。"/etc/apparmor/parser.conf"に記述された通りに制限がかけられる。)プロファイルや、指定したnamespace(イメージとしてはコンテナに近い。OS起動時にはデフォルトのnamespaceが存在し、全てのプロセスはデフォルトのnamespaceに属している。プロセスの起動時に独立したnamespaceで実行する指定を行うと、そのプロセスは別のnamespaceで実行できる。独立したnamespaceで実行することで、namespaceごとにドメイン名を持てたり、namespaceごとにマウント操作を行えたり、namespaceごとに各種ネットワークリソースを持つことができたりする。)で、特定のプログラムを起動するためのコマンド。namespaceとプロファイルの両方を指定した場合、新しいnamespace内でプロファイルの制限を受けることになる。namespaceのみを指定した場合、現在の制約のプロファイル名が使用される。プロファイルもnamespaceも指定しない場合、aa-execコマンドなしで実行された場合と同様の実行結果となる。root権限が必要。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-exec /bin/aa-enabled
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Yes
//}



=== オプション一覧




==== -p "PROFILE"




指定したプロファイルでコマンドを制限して実行する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-exec -p /usr/bin/evince aa-enabled
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Yes
//}


==== -n "NAMESPACE" 


  

指定したnamespace内のプロファイルでコマンドを制限して実行する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo aa-exec -n ns1 aa-enabled
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Yes
//}


==== -i 


  

現在のプロファイルに従ってコマンドを制限して実行する。このオプションを実行する前に指定したいプロファイルに遷移しておく必要がある。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo aaa-exec -i aa-enabled
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Yes
//}


==== -v 


  

実行するコマンドを表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo aa-exec -v aa-enabled
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [3037] exec aa-enabled
  Yes
//}


==== -d 


  

実行するコマンドとエラーコードを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo aa-exec -d -- cd aaaaaaaaaa
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [3911] aa-exec: ERROR: Failed to execute "cd": No such file or directory
//}


==== -- 


  

--以前のオプションを終了させ、--以降の引数はコマンドの引数として扱われる。aa-execによって呼び出されるコマンドに引数を渡す場合に便利。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo aa-exec -d -- cd aaaaaaaaaa
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [3911] aa-exec: ERROR: Failed to execute "cd": No such file or directory
//}

#@# 

== aa-status

AppArmor(Linuxのセキュリティプロファイルを結びつけることで、ネットワークアクセスやRaw socketアクセス、ファイルへの読み書き実行などの機能に制限をかけることができるプログラム。例えば、あるプログラムに対して、参照しかしないファイルへの書き込み、利用するはずがないファイルへのアクセス、関係がない別のプログラムの呼び出しを禁止できる。"/etc/apparmor/parser.conf"に記述された通りに制限がかけられる。)の状態を表示するコマンド。デフォルトでは、--verboseオプションと同じ情報が表示される。実行にはroot権限が必要。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-status
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  apparmor module is loaded.
  49 profiles are loaded.
  47 profiles are in enforce mode.
   /snap/snapd/19993/usr/lib/snapd/snap-confine
   /snap/snapd/19993/usr/lib/snapd/snap-confine//mount-namespace-capture-helper
   /snap/snapd/20092/usr/lib/snapd/snap-confine
   /snap/snapd/20092/usr/lib/snapd/snap-confine//mount-namespace-capture-helper
   /snap/snapd/20290/usr/lib/snapd/snap-confine
   /snap/snapd/20290/usr/lib/snapd/snap-confine//mount-namespace-capture-helper
   /usr/bin/evince
   /usr/bin/evince-previewer
   /usr/bin/evince-previewer//sanitized_helper
   /usr/bin/evince-thumbnailer
   /usr/bin/evince//sanitized_helper
   /usr/bin/man
   /usr/lib/NetworkManager/nm-dhcp-client.action
   /usr/lib/NetworkManager/nm-dhcp-helper
   /usr/lib/connman/scripts/dhclient-script
   /usr/lib/cups/backend/cups-pdf
   /usr/lib/snapd/snap-confine
   /usr/lib/snapd/snap-confine//mount-namespace-capture-helper
   /usr/sbin/cups-browsed
   /usr/sbin/cupsd
   /usr/sbin/cupsd//third_party
   /{,usr/}sbin/dhclient
   docker-default
   libreoffice-senddoc
   libreoffice-soffice//gpg
   libreoffice-xpdfimport
   lsb_release
   man_filter
   man_groff
   nvidia_modprobe
   nvidia_modprobe//kmod
   snap-update-ns.firefox
   snap-update-ns.snap-store
   snap-update-ns.snapd-desktop-integration
   snap.firefox.firefox
   snap.firefox.geckodriver
   snap.firefox.hook.configure
   snap.firefox.hook.connect-plug-host-hunspell
   snap.firefox.hook.disconnect-plug-host-hunspell
   snap.firefox.hook.post-refresh
   snap.snap-store.hook.configure
   snap.snap-store.snap-store
   snap.snap-store.ubuntu-software
   snap.snap-store.ubuntu-software-local-file
   snap.snapd-desktop-integration.hook.configure
   snap.snapd-desktop-integration.snapd-desktop-integration
   tcpdump
  2 profiles are in complain mode.
   libreoffice-oosplash
   libreoffice-soffice
  0 profiles are in kill mode.
  0 profiles are in unconfined mode.
  7 processes have profiles defined.
  7 processes are in enforce mode.
   /usr/bin/man (93992)
   /usr/bin/less (94000) /usr/bin/man
   /usr/sbin/cups-browsed (94258)
   /usr/sbin/cupsd (94221)
   /bin/snap-store (1413) snap.snap-store.ubuntu-software
   /bin/snapd-desktop-integration (872) snap.snapd-desktop-integration.snapd-desktop-integration
   /bin/snapd-desktop-integration (1216) snap.snapd-desktop-integration.snapd-desktop-integration
  0 processes are in complain mode.
  0 processes are unconfined but have a profile defined.
  0 processes are in mixed mode.
  0 processes are in kill mode.
//}



=== オプション一覧




==== --enabled




AppArmorが利用不可の場合にエラーコードを表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-status --enabled
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  
//}


==== --profiled 


  

読み込まれたAppArmorプロファイル(AppArmorを利用して設定された権限の情報が書かれたファイル)の数を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo aa-status --profiled
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  49
//}


==== --enforced




読み込まれた強制AppArmorプロファイルの数を表示する。強制AppArmorプロファイルは受けている制限が強制されるとともに、違反の試行が記録される。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-status --enforced
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  47
//}


==== --complaining




読み込まれた苦情AppArmorプロファイルの数を表示する。苦情AppArmorプロファイルは受けている制限が強制されないが、違反の試行は記録される。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-status --complaining
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2
//}


==== --kill




違反時にタスクを強制終了する強制AppArmorプロファイルを読み込み、数を表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-status --kill
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  0
//}


==== --special-unconfined




制限を受けていないモードである、非強制AppArmorプロファイルを読み込み、数を表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-status --special-unconfined
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  0
//}


==== --process-mixed




異なるモードのプロファイルを持つプロファイルスタックによって制限されたプロセスの数を表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-status --process-mixed
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  0
//}


==== --verbose




AppArmorプロファイルの状態を表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-status --verbose
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  apparmor module is loaded.
  49 profiles are loaded.
  47 profiles are in enforce mode.
   /snap/snapd/19993/usr/lib/snapd/snap-confine
   /snap/snapd/19993/usr/lib/snapd/snap-confine//mount-namespace-capture-helper
   /snap/snapd/20092/usr/lib/snapd/snap-confine
   /snap/snapd/20092/usr/lib/snapd/snap-confine//mount-namespace-capture-helper
   /snap/snapd/20290/usr/lib/snapd/snap-confine
   /snap/snapd/20290/usr/lib/snapd/snap-confine//mount-namespace-capture-helper
   /usr/bin/evince
   /usr/bin/evince-previewer
   /usr/bin/evince-previewer//sanitized_helper
   /usr/bin/evince-thumbnailer
   /usr/bin/evince//sanitized_helper
   /usr/bin/man
   /usr/lib/NetworkManager/nm-dhcp-client.action
   /usr/lib/NetworkManager/nm-dhcp-helper
   /usr/lib/connman/scripts/dhclient-script
   /usr/lib/cups/backend/cups-pdf
   /usr/lib/snapd/snap-confine
   /usr/lib/snapd/snap-confine//mount-namespace-capture-helper
   /usr/sbin/cups-browsed
   /usr/sbin/cupsd
   /usr/sbin/cupsd//third_party
   /{,usr/}sbin/dhclient
   docker-default
   libreoffice-senddoc
   libreoffice-soffice//gpg
   libreoffice-xpdfimport
   lsb_release
   man_filter
   man_groff
   nvidia_modprobe
   nvidia_modprobe//kmod
   snap-update-ns.firefox
   snap-update-ns.snap-store
   snap-update-ns.snapd-desktop-integration
   snap.firefox.firefox
   snap.firefox.geckodriver
   snap.firefox.hook.configure
   snap.firefox.hook.connect-plug-host-hunspell
   snap.firefox.hook.disconnect-plug-host-hunspell
   snap.firefox.hook.post-refresh
   snap.snap-store.hook.configure
   snap.snap-store.snap-store
   snap.snap-store.ubuntu-software
   snap.snap-store.ubuntu-software-local-file
   snap.snapd-desktop-integration.hook.configure
   snap.snapd-desktop-integration.snapd-desktop-integration
   tcpdump
  2 profiles are in complain mode.
   libreoffice-oosplash
   libreoffice-soffice
  0 profiles are in kill mode.
  0 profiles are in unconfined mode.
  7 processes have profiles defined.
  7 processes are in enforce mode.
   /usr/bin/man (93992)
   /usr/bin/less (94000) /usr/bin/man
   /usr/sbin/cups-browsed (94258)
   /usr/sbin/cupsd (94221)
   /bin/snap-store (1413) snap.snap-store.ubuntu-software
   /bin/snapd-desktop-integration (872) snap.snapd-desktop-integration.snapd-desktop-integration
   /bin/snapd-desktop-integration (1216) snap.snapd-desktop-integration.snapd-desktop-integration
  0 processes are in complain mode.
  0 processes are unconfined but have a profile defined.
  0 processes are in mixed mode.
  0 processes are in kill mode.
//}


==== --json




AppArmorプロファイルの状態を、JSON形式で表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-status --json
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  {"version": "2", "profiles": {"/snap/snapd/19993/usr/lib/snapd/snap-confine": "enforce", "/snap/snapd/19993/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce", "/snap/snapd/20092/usr/lib/snapd/snap-confine": "enforce", "/snap/snapd/20092/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce", "/snap/snapd/20290/usr/lib/snapd/snap-confine": "enforce", "/snap/snapd/20290/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce", "/usr/bin/evince": "enforce", "/usr/bin/evince-previewer": "enforce", "/usr/bin/evince-previewer//sanitized_helper": "enforce", "/usr/bin/evince-thumbnailer": "enforce", "/usr/bin/evince//sanitized_helper": "enforce", "/usr/bin/man": "enforce", "/usr/lib/NetworkManager/nm-dhcp-client.action": "enforce", "/usr/lib/NetworkManager/nm-dhcp-helper": "enforce", "/usr/lib/connman/scripts/dhclient-script": "enforce", "/usr/lib/cups/backend/cups-pdf": "enforce", "/usr/lib/snapd/snap-confine": "enforce", "/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce", "/usr/sbin/cups-browsed": "enforce", "/usr/sbin/cupsd": "enforce", "/usr/sbin/cupsd//third_party": "enforce", "/{,usr/}sbin/dhclient": "enforce", "docker-default": "enforce", "libreoffice-senddoc": "enforce", "libreoffice-soffice//gpg": "enforce", "libreoffice-xpdfimport": "enforce", "lsb_release": "enforce", "man_filter": "enforce", "man_groff": "enforce", "nvidia_modprobe": "enforce", "nvidia_modprobe//kmod": "enforce", "snap-update-ns.firefox": "enforce", "snap-update-ns.snap-store": "enforce", "snap-update-ns.snapd-desktop-integration": "enforce", "snap.firefox.firefox": "enforce", "snap.firefox.geckodriver": "enforce", "snap.firefox.hook.configure": "enforce", "snap.firefox.hook.connect-plug-host-hunspell": "enforce", "snap.firefox.hook.disconnect-plug-host-hunspell": "enforce", "snap.firefox.hook.post-refresh": "enforce", "snap.snap-store.hook.configure": "enforce", "snap.snap-store.snap-store": "enforce", "snap.snap-store.ubuntu-software": "enforce", "snap.snap-store.ubuntu-software-local-file": "enforce", "snap.snapd-desktop-integration.hook.configure": "enforce", "snap.snapd-desktop-integration.snapd-desktop-integration": "enforce", "tcpdump": "enforce", "libreoffice-oosplash": "complain", "libreoffice-soffice": "complain"}, "processes": {"/bin/snap-store": [{"profile": "snap.snap-store.ubuntu-software", "pid": "1413", "status": "enforce"}], "/bin/snapd-desktop-integration": [{"profile": "snap.snapd-desktop-integration.snapd-desktop-integration", "pid": "872", "status": "enforce"}, {"profile": "snap.snapd-desktop-integration.snapd-desktop-integration", "pid": "1216", "status": "enforce"}], "/usr/bin/less": [{"profile": "/usr/bin/man", "pid": "94000", "status": "enforce"}], "/usr/bin/man": [{"profile": "/usr/bin/man", "pid": "93992", "status": "enforce"}], "/usr/sbin/cups-browsed": [{"profile": "/usr/sbin/cups-browsed", "pid": "94258", "status": "enforce"}], "/usr/sbin/cupsd": [{"profile": "/usr/sbin/cupsd", "pid": "94221", "status": "enforce"}]}}
//}


==== --pretty-json




AppArmorプロファイルの状態を、人間にも読みやすい形式で表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-status --pretty-json
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  {
          "version":      "2",
          "profiles":     {
                  "/snap/snapd/19993/usr/lib/snapd/snap-confine": "enforce",
                  "/snap/snapd/19993/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce",
                  "/snap/snapd/20092/usr/lib/snapd/snap-confine": "enforce",
                  "/snap/snapd/20092/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce",
                  "/snap/snapd/20290/usr/lib/snapd/snap-confine": "enforce",
                  "/snap/snapd/20290/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce",
                  "/usr/bin/evince":      "enforce",
                  "/usr/bin/evince-previewer":    "enforce",
                  "/usr/bin/evince-previewer//sanitized_helper":  "enforce",
                  "/usr/bin/evince-thumbnailer":  "enforce",
                  "/usr/bin/evince//sanitized_helper":    "enforce",
                  "/usr/bin/man": "enforce",
                  "/usr/lib/NetworkManager/nm-dhcp-client.action":        "enforce",
                  "/usr/lib/NetworkManager/nm-dhcp-helper":       "enforce",
                  "/usr/lib/connman/scripts/dhclient-script":     "enforce",
                  "/usr/lib/cups/backend/cups-pdf":       "enforce",
                  "/usr/lib/snapd/snap-confine":  "enforce",
                  "/usr/lib/snapd/snap-confine//mount-namespace-capture-helper":  "enforce",
                  "/usr/sbin/cups-browsed":       "enforce",
                  "/usr/sbin/cupsd":      "enforce",
                  "/usr/sbin/cupsd//third_party": "enforce",
                  "/{,usr/}sbin/dhclient":        "enforce",
                  "docker-default":       "enforce",
                  "libreoffice-senddoc":  "enforce",
                  "libreoffice-soffice//gpg":     "enforce",
                  "libreoffice-xpdfimport":       "enforce",
                  "lsb_release":  "enforce",
                  "man_filter":   "enforce",
                  "man_groff":    "enforce",
                  "nvidia_modprobe":      "enforce",
                  "nvidia_modprobe//kmod":        "enforce",
                  "snap-update-ns.firefox":       "enforce",
                  "snap-update-ns.snap-store":    "enforce",
                  "snap-update-ns.snapd-desktop-integration":     "enforce",
                  "snap.firefox.firefox": "enforce",
                  "snap.firefox.geckodriver":     "enforce",
                  "snap.firefox.hook.configure":  "enforce",
                  "snap.firefox.hook.connect-plug-host-hunspell": "enforce",
                  "snap.firefox.hook.disconnect-plug-host-hunspell":      "enforce",
                  "snap.firefox.hook.post-refresh":       "enforce",
                  "snap.snap-store.hook.configure":       "enforce",
                  "snap.snap-store.snap-store":   "enforce",
                  "snap.snap-store.ubuntu-software":      "enforce",
                  "snap.snap-store.ubuntu-software-local-file":   "enforce",
                  "snap.snapd-desktop-integration.hook.configure":        "enforce",
                  "snap.snapd-desktop-integration.snapd-desktop-integration":     "enforce",
                  "tcpdump":      "enforce",
                  "libreoffice-oosplash": "complain",
                  "libreoffice-soffice":  "complain"
          },
          "processes":    {
                  "/bin/snap-store":      [{
                                  "profile":      "snap.snap-store.ubuntu-software",
                                  "pid":  "1413",
                                  "status":       "enforce"
                          }],
                  "/bin/snapd-desktop-integration":       [{
                                  "profile":      "snap.snapd-desktop-integration.snapd-desktop-integration",
                                  "pid":  "872",
                                  "status":       "enforce"
                          }, {
                                  "profile":      "snap.snapd-desktop-integration.snapd-desktop-integration",
                                  "pid":  "1216",
                                  "status":       "enforce"
                          }],
                  "/usr/bin/less":        [{
                                  "profile":      "/usr/bin/man",
                                  "pid":  "94000",
                                  "status":       "enforce"
                          }],
                  "/usr/bin/man": [{
                                  "profile":      "/usr/bin/man",
                                  "pid":  "93992",
                                  "status":       "enforce"
                          }],
                  "/usr/sbin/cups-browsed":       [{
                                  "profile":      "/usr/sbin/cups-browsed",
                                  "pid":  "94258",
                                  "status":       "enforce"
                          }],
                  "/usr/sbin/cupsd":      [{
                                  "profile":      "/usr/sbin/cupsd",
                                  "pid":  "94221",
                                  "status":       "enforce"
                          }]
          }
  }
//}

#@# 

== aa-teardown

全てのAppArmor(Linuxのセキュリティプロファイルを結びつけることで、ネットワークアクセスやRaw socketアクセス、ファイルへの読み書き実行などの機能に制限をかけることができるプログラム。例えば、あるプログラムに対して、参照しかしないファイルへの書き込み、利用するはずがないファイルへのアクセス、関係がない別のプログラムの呼び出しを禁止できる。"/etc/apparmor/parser.conf"に記述された通りに制限がかけられる。)プロファイルを無効化する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aa-teardown
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Unloading AppArmor profiles
//}

#@# 

== accessdb

Linuxのマニュアルページのデータベース内のデータを人間が読める形式で出力するコマンド。デフォルトでは/var/cache/man/index.<db-type>からデータを出力するが、引数を指定すると上書きできる。



===== 実行例 



//list[][][fontsize=xx-small]{
  accessdb
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $version$ -> "2.5.0"
  .ldaprc -> "- 5 5 1690841590 0 C ldap.conf - gz "
  /etc/adduser.conf -> "- 5 5 1609913810 0 C adduser.conf - gz "
  /etc/anacrontab -> "- 5 5 1648028411 0 C anacrontab - gz "
  /etc/deluser.conf -> "- 5 5 1609913810 0 C deluser.conf - gz "
  /etc/mailcap.order -> "- 5 5 1639178040 0 C mailcap.order - gz "
  /etc/modules -> "- 5 5 1629191993 0 C modules - gz "
  00-upstream-settings -> "- 5 5 1649592997 0 A - - gz dconf configuration file"

  以下マニュアルの一覧がアルファベット順に表示される。
//}

#@# 

== apparmor_status

AppArmor(Linuxのセキュリティプロファイルを結びつけることで、ネットワークアクセスやRaw socketアクセス、ファイルへの読み書き実行などの機能に制限をかけることができるプログラム。例えば、あるプログラムに対して、参照しかしないファイルへの書き込み、利用するはずがないファイルへのアクセス、関係がない別のプログラムの呼び出しを禁止できる。"/etc/apparmor/parser.conf"に記述された通りに制限がかけられる。)の状態を表示するコマンド。デフォルトでは、--verboseオプションと同じ情報が表示される。実行にはroot権限が必要。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo apparmor_status
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  apparmor module is loaded.
  19 profiles are loaded.
  19 profiles are in enforce mode.
    /snap/snapd/20290/usr/lib/snapd/snap-confine
    /snap/snapd/20290/usr/lib/snapd/snap-confine//mount-namespace-capture-helper
    /snap/snapd/20671/usr/lib/snapd/snap-confine
    /snap/snapd/20671/usr/lib/snapd/snap-confine//mount-namespace-capture-helper
    snap-update-ns.firefox
    snap-update-ns.snap-store
    snap-update-ns.snapd-desktop-integration
    snap.firefox.firefox
    snap.firefox.geckodriver
    snap.firefox.hook.configure
    snap.firefox.hook.connect-plug-host-hunspell
    snap.firefox.hook.disconnect-plug-host-hunspell
    snap.firefox.hook.post-refresh
    snap.snap-store.hook.configure
    snap.snap-store.snap-store
    snap.snap-store.ubuntu-software
    snap.snap-store.ubuntu-software-local-file
    snap.snapd-desktop-integration.hook.configure
    snap.snapd-desktop-integration.snapd-desktop-integration
  0 profiles are in complain mode.
  0 profiles are in kill mode.
  0 profiles are in unconfined mode.
  0 processes have profiles defined.
  0 processes are in enforce mode.
  0 processes are in complain mode.
  0 processes are unconfined but have a profile defined.
  0 processes are in mixed mode.
  0 processes are in kill mode.
//}



=== オプション一覧




==== --profiled




読み込まれたAppArmorプロファイル(AppArmorを利用して設定された権限の情報が書かれたファイル)の数を表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo apparmor_status --profiled
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  19
//}


==== --enforced 


  

読み込まれた強制AppArmorプロファイルの数を表示する。強制AppArmorプロファイルは受けている制限が強制されるとともに、違反の試行が記録される。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apparmor_status --enforced
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  19
//}


==== --complaining 


  

読み込まれた苦情AppArmorプロファイルの数を表示する。苦情AppArmorプロファイルは受けている制限が強制されないが、違反の試行は記録される。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apparmor_status --complaining
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  0
//}


==== --kill 


  

違反時にタスクを強制終了する強制AppArmorプロファイルを読み込み、数を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apparmor_status --kill
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  0
//}


==== --special-unconfined 


  

制限を受けていないモードである、非強制AppArmorプロファイルを読み込み、数を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apparmor_status --special-unconfined
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  0
//}


==== --process-mixed 


  

異なるモードのプロファイルを持つプロファイルスタックによって制限されたプロセスの数を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apparmor_status --process-mixed
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  0
//}


==== --verbose 


  

AppArmorプロファイルの状態を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apparmor_status --verbose
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  apparmor module is loaded.
  19 profiles are loaded.
  19 profiles are in enforce mode.
     /snap/snapd/20290/usr/lib/snapd/snap-confine
     /snap/snapd/20290/usr/lib/snapd/snap-confine//mount-namespace-capture-helper
     /snap/snapd/20671/usr/lib/snapd/snap-confine
     /snap/snapd/20671/usr/lib/snapd/snap-confine//mount-namespace-capture-helper
     snap-update-ns.firefox
     snap-update-ns.snap-store
     snap-update-ns.snapd-desktop-integration
     snap.firefox.firefox
     snap.firefox.geckodriver
     snap.firefox.hook.configure
     snap.firefox.hook.connect-plug-host-hunspell
     snap.firefox.hook.disconnect-plug-host-hunspell
     snap.firefox.hook.post-refresh
     snap.snap-store.hook.configure
     snap.snap-store.snap-store
     snap.snap-store.ubuntu-software
     snap.snap-store.ubuntu-software-local-file
     snap.snapd-desktop-integration.hook.configure
     snap.snapd-desktop-integration.snapd-desktop-integration
  0 profiles are in complain mode.
  0 profiles are in kill mode.
  0 profiles are in unconfined mode.
  0 processes have profiles defined.
  0 processes are in enforce mode.
  0 processes are in complain mode.
  0 processes are unconfined but have a profile defined.
  0 processes are in mixed mode.
  0 processes are in kill mode.
//}


==== --json 


  

AppArmorプロファイルの状態を、JSON形式で表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apparmor_status --json
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  {"version": "2", "profiles": {"/snap/snapd/20290/usr/lib/snapd/snap-confine": "enforce", "/snap/snapd/20290/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce", "/snap/snapd/20671/usr/lib/snapd/snap-confine": "enforce", "/snap/snapd/20671/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce", "snap-update-ns.firefox": "enforce", "snap-update-ns.snap-store": "enforce", "snap-update-ns.snapd-desktop-integration": "enforce", "snap.firefox.firefox": "enforce", "snap.firefox.geckodriver": "enforce", "snap.firefox.hook.configure": "enforce", "snap.firefox.hook.connect-plug-host-hunspell": "enforce", "snap.firefox.hook.disconnect-plug-host-hunspell": "enforce", "snap.firefox.hook.post-refresh": "enforce", "snap.snap-store.hook.configure": "enforce", "snap.snap-store.snap-store": "enforce", "snap.snap-store.ubuntu-software": "enforce", "snap.snap-store.ubuntu-software-local-file": "enforce", "snap.snapd-desktop-integration.hook.configure": "enforce", "snap.snapd-desktop-integration.snapd-desktop-integration": "enforce"}, "processes": {}}
//}


==== --pretty-json 


  

AppArmorプロファイルの状態を、人間にも読みやすい形式で表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apparmor_status --pretty-json
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  {
          "version":      "2",
          "profiles":     {
                  "/snap/snapd/20290/usr/lib/snapd/snap-confine": "enforce",
                  "/snap/snapd/20290/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce",
                  "/snap/snapd/20671/usr/lib/snapd/snap-confine": "enforce",
                  "/snap/snapd/20671/usr/lib/snapd/snap-confine//mount-namespace-capture-helper": "enforce",
                  "snap-update-ns.firefox":       "enforce",
                  "snap-update-ns.snap-store":    "enforce",
                  "snap-update-ns.snapd-desktop-integration":     "enforce",
                  "snap.firefox.firefox": "enforce",
                  "snap.firefox.geckodriver":     "enforce",
                  "snap.firefox.hook.configure":  "enforce",
                  "snap.firefox.hook.connect-plug-host-hunspell": "enforce",
                  "snap.firefox.hook.disconnect-plug-host-hunspell":      "enforce",
                  "snap.firefox.hook.post-refresh":       "enforce",
                  "snap.snap-store.hook.configure":       "enforce",
                  "snap.snap-store.snap-store":   "enforce",
                  "snap.snap-store.ubuntu-software":      "enforce",
                  "snap.snap-store.ubuntu-software-local-file":   "enforce",
                  "snap.snapd-desktop-integration.hook.configure":        "enforce",
                  "snap.snapd-desktop-integration.snapd-desktop-integration":     "enforce"
          },
          "processes":    {
          }
  }
//}

#@# 

== apt-mark

パッケージを自動/手動インストール済みとマークできる。自動/手動インストール済みとは、パッケージをインストールすると要求されるもので、別のパッケージが依存関係を満たすためにインストールされた場合に依存関係に自動インストール済みとマークされる。自動的にインストールされたパッケージは手動でインストールしたパッケージに依存されなくなると、apt-get や aptitude により削除が提案される。



===== 実行例 



//list[][][fontsize=xx-small]{
  なし
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}



=== オプション一覧




==== auto




パッケージを自動インストール済みとマークする。このパッケージに依存する手動でインストールされたパッケージがなくなると、このパッケージを削除する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo apt-mark auto nano
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  nano は自動でインストールしたと設定されました。
//}


==== manual 


  

パッケージを手動インストール済みとマークする。このパッケージに依存するほかのパッケージがなくなっても、このパッケージを自動的に削除するのを防ぐ。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt-mark manual nano
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  nano は手動でインストールしたと設定されました。
//}


==== showauto 


  

手動でインストールされたパッケージを、パッケージごとに改行して表示する。パッケージを指定しないと、手動でインストールされたパッケージをすべて一覧表示する。パッケージを指定すると、そのパッケージが手動でインストールされている場合に表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt-mark showauto
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  accountsservice
  acl
  acpi-support
  acpid
  ~略~
//}


==== showmanual 


  

自動的にインストールされたパッケージを、パッケージごとに改行して表示する。パッケージを指定しないと、自動的にインストールされたパッケージをすべて一覧表示する。パッケージを指定すると、そのパッケージが自動的にインストールされている場合に表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt-mark showmanual
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  apparmor-notify
  apparmor-profiles
  apparmor-profiles-extra
  apparmor-utils
  ~略~
//}


==== hold 


  

パッケージを保留としてマークする。パッケージを自動的なインストール、アップグレード、削除から防ぐ。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt-mark hold nano
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  nano は保留に設定されました。
//}


==== unhold 


  

以前保留したパッケージを、また操作できるようキャンセルするのに使用する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt-mark unhold nano
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  nano の保留を解除しました。
//}


==== showhold 


  

保留されたパッケージを、パッケージごとに改行して表示する。パッケージを指定しないと、保留されたパッケージをすべて一覧表示する。パッケージを指定すると、そのパッケージが保留されている場合に表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt-mark showhold
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  nano
//}

#@# 

== apt

パッケージ管理用のコマンド。



===== 実行例 



//list[][][fontsize=xx-small]{
  なし
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}



=== オプション一覧




==== update




パッケージ情報をダウンロードするために使用される。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo apt update
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ヒット:1 http://archive.ubuntulinux.jp/ubuntu jammy InRelease
  ヒット:2 http://archive.ubuntulinux.jp/ubuntu-ja-non-free jammy InRelease
  ~中略~
  パッケージリストを読み込んでいます... 完了
  依存関係ツリーを作成しています... 完了
  状態情報を読み取っています... 完了
  アップグレードできるパッケージが 11 個あります。表示するには 'apt list --upgradable' を実行してください。
//}


==== upgrade 


  

システムに現在インストール済みのすべてのパッケージで利用可能なアップグレードをインストールするために使用される。依存関係を満たすために必要な場合は新しいパッケージがインストールされるが、既存のパッケージが削除されることはない。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt upgrade
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  パッケージリストを読み込んでいます... 完了
  依存関係ツリーを作成しています... 完了
  状態情報を読み取っています... 完了
  アップグレードパッケージを検出しています... 完了
  ~略~
//}


==== full-upgrade 


  

アップグレードの機能を実行するが、システム全体をアップグレードするために必要とされる場合には、現在インストール済みのパッケージを削除する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt full-upgrade
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  パッケージリストを読み込んでいます... 完了
  依存関係ツリーを作成しています... 完了
  状態情報を読み取っています... 完了
  アップグレードパッケージを検出しています... 完了
  ~略~
//}


==== install もしくは reinstall もしくは remove もしくは purge 


  

指定された 1 つ以上のパッケージに対して要求された処理を実行する。要求された処理は、特定のパッケージに対してパッケージ名にプラス (+) を追加してパッケージのインストールを、マイナス (-) を追加してパッケージの削除を上書きすることができる。パッケージ名にイコール (=) とパッケージのバージョンを続けることで、選択したバージョンのパッケージをインストールすることができる。また、必要な場合には、パッケージの依存関係を満たすリリースからバージョンを選択する。

パッケージの削除はパッケージの全データを削除するが、削除の事故に備えて、通常は隠れている小さな (修正された) ユーザ設定ファイルを残す。問題が発生した際は、誤って削除したパッケージのインストール要求を発行すると、以前のようにその機能を復元する。一方、purge を呼び出すことで、既に削除したパッケージの残されたデータを削除することができる。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt reinstall nano
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  パッケージリストを読み込んでいます... 完了
  依存関係ツリーを作成しています... 完了
  状態情報を読み取っています... 完了
  アップグレード: 0 個、新規インストール: 0 個、再インストール: 1 個、削除: 0 個、保留: 9 個。
  280 kB のアーカイブを取得する必要があります。
  この操作後に追加で 0 B のディスク容量が消費されます。
  取得:1 http://jp.archive.ubuntu.com/ubuntu jammy/main amd64 nano amd64 6.2-1 [280 kB]
  280 kB を 2秒 で取得しました (182 kB/s)
  (データベースを読み込んでいます ... 現在 252595 個のファイルとディレクトリがインストールされています。)
  .../archives/nano_6.2-1_amd64.deb を展開する準備をしています ...
  nano (6.2-1) で (6.2-1 に) 上書き展開しています ...
  nano (6.2-1) を設定しています ...
  man-db (2.10.2-1) のトリガを処理しています ...
  install-info (6.8-4build1) のトリガを処理しています ...
//}


==== autoremove 


  

他のパッケージの依存関係を満たすために自動的にインストールされた後、依存関係の変更あるいは必要としていたパッケージが削除されたことでもう必要なくなったパッケージの削除に使用する。手動でインストールされたパッケージは、自動削除のために提案されない。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt autoremove
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  パッケージリストを読み込んでいます... 完了
  依存関係ツリーを作成しています... 完了
  状態情報を読み取っています... 完了
  以下のパッケージは「削除」されます:
    docker-scan-plugin libflashrom1 libftdi1-2 libllvm13
  アップグレード: 0 個、新規インストール: 0 個、削除: 4 個、保留: 9 個。
  この操作後に 113 MB のディスク容量が解放されます。
  続行しますか? [Y/n] y
  (データベースを読み込んでいます ... 現在 252615 個のファイルとディレクトリがインストールされています。)
  docker-scan-plugin (0.23.0~ubuntu-jammy) を削除しています ...
  libflashrom1:amd64 (1.2-5build1) を削除しています ...
  libftdi1-2:amd64 (1.5-5build3) を削除しています ...
  libllvm13:amd64 (1:13.0.1-2ubuntu2.2) を削除しています ...
  libc-bin (2.35-0ubuntu3.5) のトリガを処理しています ...
//}


==== search 


  

指定したパッケージの内容と、その機能を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt search nano
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ソート中... 完了
  全文検索... 完了
  alpine-pico/jammy 2.25+dfsg1-1build1 amd64
    Simple text editor from Alpine, a text-based email client

  arduino-core-avr/jammy,jammy 1.8.4+dfsg1-1 all
    Arduino Core for AVR microcontroller

  bornagain/jammy 1.19.0-3build2 amd64
    Simulate and fit X-ray and neutron GISAS -- binary

  bornagain-doc/jammy,jammy 1.19.0-3build2 all
    Simulate and fit X-ray and neutron GISAS -- doc
//}


==== show 


  

指定されたパッケージに関する情報を表示する。依存関係、インストールおよびダウンロードサイズ、パッケージが入手可能な取得元、パッケージの内容の説明などを含む。パッケージの削除をさせる前や、インストールする新しいパッケージを検索する際に、この情報を見て参考にすることができる。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt show nano 
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Package: nano
  Version: 6.2-1
  Priority: standard
  Section: editors
  Origin: Ubuntu
  Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
  Original-Maintainer: Jordi Mallach <jordi@debian.org>
  Bugs: https://bugs.launchpad.net/ubuntu/+filebug
  Installed-Size: 881 kB
  Depends: libc6 (>= 2.34), libncursesw6 (>= 6), libtinfo6 (>= 6)
  Suggests: hunspell
  Conflicts: pico
  Breaks: nano-tiny (<< 2.8.6-2)
  Replaces: nano-tiny (<< 2.8.6-2), pico
  Homepage: https://www.nano-editor.org/
  Task: standard
  Download-Size: 280 kB
  APT-Manual-Installed: yes
  APT-Sources: http://jp.archive.ubuntu.com/ubuntu jammy/main amd64 Packages
  Description: Pico にヒントを得て作られた、コンパクトで使いやすいテキストエディタ
   GNU nano は使いやすいテキストエディタで、当初は Pico の代替品として設計され ました。Pico とは、かつて non-free
   だったメーラパッケージ Pine の ncurses ベースのエディタです (現在 Pine 自体は、Apache ライセンスで Alpine
   という名 前で入手できます)。
   .
   However, GNU nano also implements many features missing in Pico, including:
    - undo/redo
    - line numbering
    - syntax coloring
    - soft-wrapping of overlong lines
    - selecting text by holding Shift
    - interactive search and replace (with regular expression support)
    - a go-to line (and column) command
    - support for multiple file buffers
    - auto-indentation
    - tab completion of filenames and search terms
    - toggling features while running
    - and full internationalization support
//}


==== list 


  

一定の基準を満たすパッケージのリストを表示することができる。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo apt list nano
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  一覧表示... 完了
  nano/jammy,now 6.2-1 amd64 [インストール済み]
//}

#@# 

== aptdcon

ソフトウェアのインストールや削除などのパッケージ管理タスクを実行できる。



===== 実行例 



//list[][][fontsize=xx-small]{
  なし
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}



=== オプション一覧




==== -i もしくは --install




パッケージをインストールする。複数のパッケージをインストールしたい場合は、パッケージ名を""で囲う。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aptdcon -i "nano init"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [\]   0% 依存関係を解決しています
  [\]   0% ソフトウェアの一覧を読み込んでいます
  [/]   0% 処理の開始を待っています
  The following NEW packages will be installed (2):
    init nano
  Do you want to continue [Y/n]?y
  [-]   0% 認証を待っています
  [-]   0% タスクを実行中です
  [-]  11% タスクを実行中です
  [+] 100%  成功しました
//}


==== --reinstall 


  

パッケージを再インストールする。複数のパッケージを再インストールしたい場合は、パッケージ名を""で囲う。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo aptdcon --reinstall "nano init"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [\]   0% 依存関係を解決しています
  [\]   0% ソフトウェアの一覧を読み込んでいます
  [/]   0% 処理の開始を待っています
  The following packages will be reinstalled (2):
    init nano
  Do you want to continue [Y/n]?y
  [-]   0% 認証を待っています
  [-]   0% タスクを実行中です
  [-]  11% タスクを実行中です
  [+] 100%  成功しました
//}


==== -r もしくは --remove




パッケージを削除する。複数のパッケージを削除したい場合は、パッケージ名を""で囲う。removeの場合設定ファイルは残るが、purgeの場合は設定ファイルも削除される。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aptdcon -r nano
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [\]   0% 依存関係を解決しています
  [\]   0% ソフトウェアの一覧を読み込んでいます
  [/]   0% 処理の開始を待っています
  The following package will be REMOVED (1):
    nano
  After this operation, -880640.0B of additional disk space will be freed.
  Do you want to continue [Y/n]?y
  [-]   0% 認証を待っています
  [-]   0% タスクを実行中です
  [-]  11% タスクを実行中です
  [-]  11% ダウンロード中です
  [-]  11% ダウンロード中です
  [-]  50% ダウンロード中です
  [-]  50% 変更を適用しています
  (データベースを読み込んでいます ... 現在 253199 個のファイルとディレクトリがインストールされています。)
  nano (6.2-1) を削除しています ...
  update-alternatives: using /usr/bin/vim.tiny to provide /usr/bin/editor (editor) in auto mode
  install-info (6.8-4build1) のトリガを処理しています ...
  man-db (2.10.2-1) のトリガを処理しています ...
  [\]  76% 終了しました インストール後トリガ dpkg-exec を実行しています
  [\] 100% 終了しました インストール後トリガ dpkg-exec を実行しています
  [\] 100% 終了しました インストール後トリガ dpkg-exec を実行しています
  [\] 100% 終了しました インストール後トリガ dpkg-exec を実行しています
  [\] 100% 終了しました インストール後トリガ dpkg-exec を実行しています
  /usr/lib/python3/dist-packages/aptdaemon/console.py:337: Warning: Source ID 22 was not found when attempting to remove it
    GLib.source_remove(wid)
  /usr/lib/python3/dist-packages/aptdaemon/console.py:337: Warning: Source ID 23 was not found when attempting to remove it
    GLib.source_remove(wid)
  [+] 100%  成功しました
//}


==== -p もしくは --purge 


  

パッケージを完全に削除する。複数のパッケージを完全に削除したい場合は、パッケージ名を""で囲う。removeの場合設定ファイルは残るが、purgeの場合は設定ファイルも削除される。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo aptdcon -p nano
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [\]   0% 依存関係を解決しています
  [\]   0% ソフトウェアの一覧を読み込んでいます
  [/]   0% 処理の開始を待っています
  The following packages will be REMOVED (2):
    nano nano
  After this operation, -880640.0B of additional disk space will be freed.
  Do you want to continue [Y/n]?y
  [-]   0% 認証を待っています
  [-]   0% タスクを実行中です
  [-]  11% タスクを実行中です
  [-]  11% ダウンロード中です
  [-]  11% ダウンロード中です
  [-]  50% ダウンロード中です
  [-]  50% 変更を適用しています
  (データベースを読み込んでいます ... 現在 253199 個のファイルとディレクトリがインストールされています。)
  nano (6.2-1) を削除しています ...
  update-alternatives: using /usr/bin/vim.tiny to provide /usr/bin/editor (editor) in auto mode
  install-info (6.8-4build1) のトリガを処理しています ...
  man-db (2.10.2-1) のトリガを処理しています ...
  (データベースを読み込んでいます ... 現在 253127 個のファイルとディレクトリがインストールされています。)
  nano (6.2-1) の設定ファイルを削除しています ...
  [\]  82% 終了しました インストール後トリガ dpkg-exec を実行しています
  [\] 100% 終了しました インストール後トリガ dpkg-exec を実行しています
  [\] 100% 終了しました インストール後トリガ dpkg-exec を実行しています
  [\] 100% 終了しました インストール後トリガ dpkg-exec を実行しています
  [\] 100% 終了しました インストール後トリガ dpkg-exec を実行しています
  /usr/lib/python3/dist-packages/aptdaemon/console.py:337: Warning: Source ID 22 was not found when attempting to remove it
    GLib.source_remove(wid)
  /usr/lib/python3/dist-packages/aptdaemon/console.py:337: Warning: Source ID 23 was not found when attempting to remove it
    GLib.source_remove(wid)
  [+] 100%  成功しました
//}


==== -u もしくは --upgrade




パッケージをアップグレードする。複数のパッケージをアップグレードしたい場合は、パッケージ名を""で囲う。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aptdcon -u "nano init"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [\]   0% 依存関係を解決しています
  [\]   0% ソフトウェアの一覧を読み込んでいます
  [/]   0% 処理の開始を待っています
  The following packages will be upgraded (2):
    init nano
  Do you want to continue [Y/n]?y
  [-]   0% 認証を待っています
  [-]   0% タスクを実行中です
  [-]  11% タスクを実行中です
  [+] 100%  成功しました
//}


==== --upgrade-system 


  

システム全体をアップグレードする。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo aptdcon --upgrade-system
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [\]   0% 依存関係を解決しています
  [\]   0% ソフトウェアの一覧を読み込んでいます
  [/]   0% 依存関係を解決しています
  [-]   0% 処理の開始を待っています
  The following packages will be upgraded (7):
    linux-firmware python3-software-properties python3-update-manager software-properties-common software-properties-gtk update-manager-core update-manager
  The following packages have been kept back (3):
    dnsmasq-base gjs libgjs0g
  Need to get 251.6MB of archives.
  After this operation, 19.9MB of additional disk space will be used.
  Do you want to continue [Y/n]?y
  [\]   0% 認証を待っています
  [\]   0% タスクを実行中です
  [\]  11% タスクを実行中です
  [\]  11% ダウンロード中です
  [\]  11% ダウンロード中です (Downloaded 0.0B of 251.6MB)
  ~略~
//}


==== --fix-install




"dpkg --configure -a"を呼び出し、以前にキャンセルされたインストールを実行する。



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo aptdcon --fix-install nano
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [\]   9% 依存関係を解決しています
  [\]   9% 処理の開始を待っています
  [\]   9% 認証を待っています
  [\]   9% タスクを実行中です
  [\]  11% タスクを実行中です
  [\]  11% クリーンアップ中です
  [\]  11% 変更を適用しています
  [\]  11% ソフトウェアの一覧を読み込んでいます
  [\]   1% ソフトウェアの一覧を読み込んでいます
  /usr/lib/python3/dist-packages/aptdaemon/console.py:337: Warning: Source ID 20 was not found when attempting to remove it
    GLib.source_remove(wid)
  /usr/lib/python3/dist-packages/aptdaemon/console.py:337: Warning: Source ID 21 was not found when attempting to remove it
    GLib.source_remove(wid)
  [+] 100%  成功しました
//}

