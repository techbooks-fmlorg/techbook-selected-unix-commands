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
