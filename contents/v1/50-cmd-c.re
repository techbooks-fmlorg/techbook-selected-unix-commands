= 頭文字が c のコマンド

#@# 

== cat

ファイルの内容を確認するコマンド。複数のファイルの内容を確認することも可能。設定ファイルをエディターで開くと壊れる恐れがあるため、内容をまず確認すると安全。



===== 実行例 



//list[][][fontsize=xx-small]{
  cat sample.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  red


  blue
  yellow
//}



=== オプション一覧




==== -n




行番号を表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  cat -n sample.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1 red
  2 
  3
  4 blue
  5 yellow
//}


==== -b 


  

空行を飛ばして行番号を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  cat -b sample.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1 red


  2 blue
  3 yellow
//}


- @<strong>{-s} 

  

連続した空行を1行にする。




===== 実行例　



//list[][][fontsize=xx-small]{
  cat -s sample.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  red

  blue
  yellow
//}

#@# 

== cd

cd: cd 
作業ディレクトリを変更します。

現在のディレクトリをDIRに変更します。デフォルトのDIRはHOMEシェル変数の値です。

変数CDPATHは、DIRを含むディレクトリの検索パスを定義します。CDPATH内の代替ディレクトリ名はコロン（:）で区切られます。空のディレクトリ名は現在のディレクトリと同じです。DIRがスラッシュ（/）で始まる場合、CDPATHは使用されません。

ディレクトリが見つからない場合、シェルオプション「cdable_vars」が設定されている場合、単語は変数名と見なされます。その変数に値がある場合、その値がDIRとして使用されます。

オプション:


==== -L シンボリックリンクを強制的にたどる：..'のインスタンスを処理した後、DIR内のシンボリックリンクを解決します。




==== -P	シンボリックリンクをたどらずに物理的なディレクトリ構造を使用する：..'のインスタンスを処理する前にDIR内のシンボリックリンクを解決します。





==== -e -Pオプションが指定されており、現在の作業ディレクトリを正常に特定できない場合、終了ステータスを非ゼロで終了します。




==== -@ サポートされているシステムでは、拡張属性を持つファイルをファイル属性を含むディレクトリとして表示します。



デフォルトでは、シンボリックリンクをたどります。`..'は、直前のパス名コンポーネントをスラッシュまたはDIRの先頭まで削除して処理されます。

終了ステータス:
ディレクトリが変更されると0を返し、-Pが使用される場合は$PWDが正常に設定された場合に成功します。それ以外の場合は非ゼロを返します。





===== 実行例.1 




cdを単体で使用した場合、ユーザのホームディレクトリへ移動
//list[][][fontsize=xx-small]{
  cd
//}





===== 実行結果.1　


//list[][][fontsize=xx-small]{
  $ pwd  //実行前の現在地を確認
  home/user/Prmn

  $ cd //実行
  $ pwd //実行後の現在地を確認
  homo/user  //ユーザのホームディレクトリに移動したことがわかる
//}





===== 実行例.2 




cdの後ろにディレクトリ名を指定するとそのディレクトリへ移動する。
//list[][][fontsize=xx-small]{
  cd ディレクトリ名
//}





===== 実行結果.2　



//list[][][fontsize=xx-small]{
  $ pwd  //実行前の現在地を確認
  home/user
  $ ls //現在地にあるディレクトリを確認
  Prmn test
  $ cd Prmn // 実行
  $ pwd //実行後の現在地を確認
  home/user/Prmn //Prmnディレクトリに移動したことがわかる
//}





===== 実行例.3 


 

1つ前のディレクトリへ戻る


//list[][][fontsize=xx-small]{
  cd ..
//}





===== 実行結果.3　



//list[][][fontsize=xx-small]{
  $ pwd //実行前の現在地を確認
  home/user/Prmn/test
  $ cd ..  //実行
  $ pwd //実行後の現在地を確認
  home/user/Prmn //1つ前のディレクトリへ戻ったことが確認できる
//}





===== 実行例.4 



cd単体でコマンドを実行した場合と同じ挙動をする。主に複雑なディレクトリ間を移動する際に使用.。
//list[][][fontsize=xx-small]{
  cd ~/Prmm
//}





===== 実行結果.4　



//list[][][fontsize=xx-small]{
  $ pwd
  home/user/prac
  $ cd ~/Prmn //一度ユーザのホームディレクトリへ移動してからPrmnへ移動
  $ pwd 
  home/user/Prmn //Prmnディレクトリへ移動していることを確認
//}





===== 実行例.5




前に居たディレクトリへ移動する。
//list[][][fontsize=xx-small]{
  cd -
//}





===== 実行結果.5　



//list[][][fontsize=xx-small]{
  $ pwd //移動する前のディレクトリを表示
  home/user/Prmn
  $ cd /etc　// etcへ移動
  $ pwd
  /etc
  $ cd -　// 実行
  $ pwd
  home/user/Prmn //元居た場所へ戻ったことを確認できる
//}





=== オプション一覧




==== -L




移動先のディレクトリがシンボリックリンクだった場合、シンボリックリンクに移動するオプション。シンボリックリンクとは別のファイルやディレクトリへの参照を作成するための特殊なファイル。




===== 実行例 



//list[][][fontsize=xx-small]{
  cd -L tmp
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ pwd
  home/user/Prmn //現在地のディレクトリを確認
  $ ln -s tmp/ tmp //現在のディレクトリにシンボリックリンクを作成。
  $ ls
  tmp　//ルート直下のtmpが参照されている
  $ cd -L tmp //参照先のtmpへ移動
  $ pwd 
  home/user/Prmn/tmp　/

//}


==== -P 


  

移動先がシンボリックリンクだったらシンボリックリンクのターゲット飛ぶためのオプション。つまり、参照したディレクトリの元のディレクトリへ移動する。

 


===== 実行例 



//list[][][fontsize=xx-small]{
  cd -P tmp
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ pwd
  home/user/Prmn //現在地のディレクトリを確認
  $ ln -s tmp/ tmp //現在のディレクトリにシンボリックリンクを作成。
  $ ls
  tmp　//ルート直下のtmpが参照されている
  $ cd -P tmp //参照先のtmpへ移動
  $ pwd 
  /tmp  //ルート直下のtmpディレクトリへ移動していることがわかる。
//}





#@# 

== chmod

ファイルやディレクトリのパーミッション（アクセス権限）を変更するためのコマンド。  
これにより、ファイルやディレクトリに対する読み取り、書き込み、実行などの権限を設定可能。

モードには、数値を用いた絶対値指定と、シンボルによる指定がある。 数値指定では、以下の値を足し合わせた 8 進数を用いる。

==== 4000	(setuid ビット) ファイルにこのビットがセットされている場合、そのファイルを実行したときにそのプロセスは、ファイルの所有者の権限ではなくファイルの所有者として指定されているユーザーの権限を使用する。


==== 2000	(setgid ビット) ファイルにこのビットがセットされている場合、そのファイルを実行したときにそのプロセスは、ファイルの所有者の権限ではなく、ファイルの所有者として指定されているグループの権限を使用する。一般的には、グループが共有データにアクセスできるようにするために使用される。


==== 1000	(sticky ビット) ディレクトリにこのビットがセットされている場合、そのディレクトリ内のファイルは、そのディレクトリを作成したユーザー、またはファイルの所有者以外は削除できない。通常は、一時的なディレクトリなどで使用される。


==== 0400	所有者の読み込みを許可。


==== 0200	所有者の書き込みを許可。


==== 0100	ファイルの場合、所有者の実行を許可。 ディレクトリの場合、所有者の検索を許可。


==== 0040	グループのメンバの読み込みを許可。


==== 0020	グループのメンバの書き込みを許可。


==== 0010	ファイルの場合、グループのメンバの実行を許可。 ディレクトリの場合、グループのメンバの検索を許可。


==== 0004	他者の読み込みを許可。


==== 0002	他者の書き込みを許可。


==== 0001	ファイルの場合、他者の実行を許可。 ディレクトリの場合、他者の検索を許可。


例えば、所有者に読み込み・書き込み・実行を許可し、 グループのメンバに読み込み・実行を許可し、 他者に読み込み・実行を許可し、 set-uid と set-gid を指定しない絶対値指定のモードは、 755 (400+200+100+040+010+004+001) となる。

who シンボルの u'', g'', o'' はそれぞれユーザ、グループ、それ以外に 相当します。``a'' シンボルは ugo'' を指定した場合と同じになる。

perm シンボルはモードの各ビットを以下のように表現する。


==== r	読み込み許可ビット


==== s	実行時 setuid および実行時 setgid ビット


==== t	sticky ビット


==== w	書き込み許可ビット


==== x	実行 もしくは 検索 許可ビット


==== X	対象がディレクトリであるか、変更前のモードで誰かの実行 もしくは 検索許可ビット が立っている場合に、実行 もしくは 検索許可ビットがセットされる。 　



perm シンボルでの X'' の指定は、 op シンボルを +''で連結する時のみ意味があり、他の場合は無視する。

==== u	元の、ファイルの所有者許可ビット


==== g	元の、ファイルのグループ許可ビット


==== o	元の、ファイルの所有者とグループ以外の許可ビット





===== 実行例 


パーミッションが0664(rw-rw-r--)のtext.txtに0644(rw-r--r--)を設定する。


//list[][][fontsize=xx-small]{
$ chmod -v 644 text.txt
$ chmod -v u=rw,g=r,o=r text.txt
'test.txt' モードを 0664 (rw-rw-r--) から 0644 (rw-r--r--)　へ変更しました
//}

読み取り・書き込み権限を所有者に、読み取り権限をグループとその他のユーザーに与える。



=== オプション一覧



==== -v もしくは --verbose



処理されたファイルごとに診断結果を出力する



===== 実行例 


//list[][][fontsize=xx-small]{
  $ chmod -v 614 text.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  'test.txt' モードを 0644 (rw-r--r--) から 0614 (rw---xr--)　へ変更しました
//}


  

==== -c もしくは --changes



verboseと同様に、変更があったときだけ報告する。



===== 実行例 


//list[][][fontsize=xx-small]{
  $ chmod -c 614 text.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  'test.txt' モードを 0644 (rw-r--r--) から 0614 (rw---xr--)　へ変更しました

//}



==== -f もしくは --silent もしくは --quiet



ほとんどのエラーメッセージを表示しない



===== 実行例 


//list[][][fontsize=xx-small]{
  $ chmod -f 644 text.txt 
//}




===== 実行結果 


エラーメッセージ例


- 存在しないファイルやディレクトリを対象にした場合
//list[][][fontsize=xx-small]{
  $ chmod 644 t.txt
  chmod: 't.txt' にアクセスできません: そのようなファイルやディレクトリはありません
//}



- パーミッションが不正な場合
//list[][][fontsize=xx-small]{
  $ chmod 999 text.txt
  chmod: 無効なモード: '999'
//}



- 権限がない場合
//list[][][fontsize=xx-small]{
  $ chmod 777 /etc/apt
  chmod: '/etc/apt' のパーミッションを変更しています: 許可されていない操作です
//}




==== --no-preserve-root



ルートディレクトリ('/')の保護を無効にする。  

通常、Unix系のオペレーティングシステムでは、ルートディレクトリの変更や削除を防ぐためにセキュリティ対策が施されている。しかし、このオプションを使用することで、ルートディレクトリに対する操作が制限なしに行えるようになる。




===== 実行例 


//list[][][fontsize=xx-small]{
  $ chmod -v --no-preserve-root 777 /etc/apt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  '/etc/apt' のモードを 0644 (rw-r--r--) から 0777 (rwxrwxrwx) へ変更されました
//}



==== --preserve-root



ルートディレクトリ ('/') の保護を有効にする。




===== 実行例 


//list[][][fontsize=xx-small]{
  $ chmod -v --preserve-root 777 /etc/apt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  chmod: '/etc/apt' のパーミッションを変更しています: 許可されていない操作です
  '/etc/apt' のモードを 0755 (rwxr-xr-x) から 0777 (rwxrwxrwx) へ変更できませんでした
//}



==== --reference=RFILE



指定したファイルのパーミッションをコピーして、既存のファイルやディレクトリに設定する。



===== 実行例 


//list[][][fontsize=xx-small]{
  $ chmod --reference=text.txt new_text.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  'new_text.txt' のモードを 0644 (rw-r--r--) から 0614 (rw---xr--)　へ変更しました
//}



==== -R もしくは --recursive



ファイルとディレクトリを再帰的に変更する
//list[][][fontsize=xx-small]{
  .
  ├─chmod
  │   ├─new_text.txt
  │   ├─text/txt
//}


上記のディレクトリ構造に対して実行する



===== 実行例 


//list[][][fontsize=xx-small]{
  $ chmod -v -R 777 chmod
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  'chmod' のモードを 0775 (rwxrwxr-x) から 0777 (rwxrwxrwx) へ変更しました
  'chmod/text.txt' のモードを 0641 (rw-r---x) から 0777 (rwxrwxrwx) へ変更しました
  'chmod/new_text.txt' のモードを 0641 (rw-r----x) から 0777 (rwxrwxrwx) へ変更しました
//}


#@# 

== chown

ファイルやディレクトリの所有者（ユーザー）を変更するために利用する。  
chownコマンドは通常、ルートユーザーまたはファイルの現在の所有者で実行する必要がある。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ chown -v new_user text.txt
  'text.txt' の所有者を old_user から new_user へ変更しました
//}





===== 実行例 


//list[][][fontsize=xx-small]{
  $ chown -v new_user:new_user text.txt
  'text.txt' の所有者を old_user:old_user から new_user:new_user へ変更しました
//}



=== オプション一覧




==== -v もしくは --verbose




処理されたファイルごとに変更内容を出力する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ chown -v new_user text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  'text.txt' の所有者を old_user から new_user へ変更しました
//}


==== -c もしくは --changes 


  

verboseと同様に、変更があったときだけ報告する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ chown -c new_user text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  'text.txt' の所有者を old_user から new_user へ変更しました
//}


==== -f もしくは --silent もしくは --quiet 


  

ほとんどのエラーメッセージを表示しない。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ chown -f new_user text.txt
//}





===== 実行結果　


エラーメッセージ例


- 権限がない場合
//list[][][fontsize=xx-small]{
  $ chown new_user text.txt
  chown: 'text.txt' の所有者を変更中: 許可されていない操作です
//}



- 対象のファイルやディレクトリが存在しない場合
//list[][][fontsize=xx-small]{
  $ chown new_user t.txt
  chown: 'text.txt' にアクセスできません: そのようなファイルやディレクトリはありません
//}



- 存在しないユーザーやグループを指定した場合
//list[][][fontsize=xx-small]{
  $ chown user text.txt
  chown: ユーザー指定が不正: 'user'
//}



==== -h もしくは --no-dereference 


  

指定したファイルがシンボリックリンクであるとき、そのシンボリックリンクの所有者を変更する。このオプションが指定されていない場合は、そのシンボリックリンクによって参照されるファイルの所有者が変更される。

- シンボリックリンク

  UnixおよびUnix系オペレーティングシステムで使用されるファイルやディレクトリへの参照。シンボリックリンクは、別のファイルやディレクトリを指す「参照」のようなもので、通常のファイルとは異なり、単なるポインタのような存在である。


//list[][][fontsize=xx-small]{
  .
  ├─chown
  │  ├─text.txt
  │
  ├─ln
  │　├─text
//}




===== 実行例　



//list[][][fontsize=xx-small]{
  $ chown -v -h new_user text
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  'text' の所有者を old_user から new_user へ変更しました
//}


==== -R 


  

ファイルとディレクトリを再帰的に変更する。

//list[][][fontsize=xx-small]{
  .
  ├─chown
  │   ├─new_text.txt
  │   ├─text.txt
//}





===== 実行例　



//list[][][fontsize=xx-small]{
  $ chown -v -R new_user chown
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  'chown/text.txt' の所有者を old_user から new_user へ変更しました  
  'chown/new_text.txt' の所有者を old_user から new_user へ変更しました
  'chown' の所有者を old_user から new_user へ変更しました
//}

