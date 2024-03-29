#@# 

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

