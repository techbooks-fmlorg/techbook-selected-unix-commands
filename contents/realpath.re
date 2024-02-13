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

