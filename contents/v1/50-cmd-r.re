= 頭文字が r のコマンド

#@# 

== rbash

Bashを制限付きモードで起動する。制限付きモードで使用すると、cdコマンドでのディレクトリ移動や、シェルスクリプトの実行などの行動が制限される。「rbash」とターミナルに入力すれば制限モードでBashが起動する。また、「exit」か「bash」をターミナルで入力することで制限モードを解除することができる。



===== 実行例 



//list[][][fontsize=xx-small]{
  rbash

  または

  rbash -r
//}





===== 実行結果.1　



//list[][][fontsize=xx-small]{
  $ rbash
  $ cd
  rbash: cd: restricted
//}


cdコマンドが制限されている。





===== 実行結果.2　



//list[][][fontsize=xx-small]{
  $ rbash
  $ cat test.sh //シェルスクリプトの内容を表示
  #!/bin/bash

  # 引数が与えられているかチェック
  if [ $# -eq 0 ]; then
  echo "Usage: $0 [name]"
  exit 1
  fi

  # 引数の取得とメッセージの表示
  name=$1
  echo "Hello, $name!"

  $ ./test.sh　//シェルスクリプトの実効 
  rbash: ./test.sh: restricted: cannot specify `/' in command names
//}


シェルスクリプトの実行が制限されている。





===== 実行結果.3　



//list[][][fontsize=xx-small]{
  $ rbash
  $ man rbash > output.txt
  rbash: output.txt: restricted: cannot redirect output
//}


">、>|、<>、>&、>>`などのリダイレクション演算子を使用して出力をリダイレクトすることが制限されている。


#@# 

== realpath

指定したパスを絶対パスに変換する。



===== 実行例 



//list[][][fontsize=xx-small]{
  realpath test.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  /home/user/Prmn
//}



=== オプション一覧




==== -e




指定したパスが存在すれば、絶対パスが表示される。

存在しない場合はエラーメッセージが表示される。



===== 実行例 



//list[][][fontsize=xx-small]{
  realpath -e aaa.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls    //ディレクトリ内に存在するファイルを確認
  test.txt 
  $ realpath -e test.txt　//存在するファイルパスを指定
  /home/user/Prmn
  $ realpath -e aaa.txt   //存在しないファイルパスを指定
  realpath: aaa.txt: No such file or directory
//}


==== -m 


  

指定したパスが存在しない場合でも絶対パスを表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  realpath -m aaa.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ls    //ディレクトリ内に存在するファイルを確認
  test.txt
  $ realpath -m aaa.txt  // 存在しないファイルパスを指定
  /home/user/Prmn/aaa.txt 
//}


==== -s 


  

指定したパスがシンボリックリンクの場合、シンボリックリンクを展開せずにそのままのパスで表示する。シンボリックリンクとは、ファイルやディレクトリを参照するファイルである。




===== 実行例　



//list[][][fontsize=xx-small]{
  realpath -s read_test/file1.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  $ ln -s /home/user/test  read_test  //「/home/user/test」を参照するシンボリックリンクを作成
  $ cd read_test　//シンボリックリンク内のファイル確認
  $ ls
  file1.txt  file2.txt
  $ cd ..
  $ realpath read_test/file1.txt  //オプション無しで実行
  /home/user/test/file1.txt　　//参照元のパスを表示
  $ realpath -s read_test/file1.txt  //オプションありで実行
  /home/user/Prmn/read_test/file1.txt //シンボリックリンクを展開せずにパスを表示する
//}

