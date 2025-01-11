= 頭文字が e のコマンド

#@# 

== e2freefrag

ext2/3/4ファイルシステムの空き領域の断片化を報告するために使われる。

ext2~ext4ファイルシステムとはLinuxで標準的に利用されるファイルシステムの一つで、
ext4がよく利用され、オペレーティングシステムをサポートしている。

ブロックビットマップ情報をスキャンして、 どれだけの空きブロックが連続し、整列した空き領域として存在するかを調べる。

ブロックビットマップ情報
ブロック毎に空き/使用中を管理している情報



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo e2freefrag
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Device: /dev/sda1
  Blocksize: 4096 bytes
  Total blocks: 256
  Free blocks: 238 (93.0%)
  
  
  Min. free extent: 12 KB
  Max. free extent: 856 KB
  Avg. free extent: 236 KB
  Num. free extent: 4
  
  
  HISTOGRAM OF FREE EXTENT SIZES:
  Extent Size Range : Free extents  Free Blocks Percent
      8K ...  16K-  :            1            3   1.26%
     16K ...  32K-  :            1            6   2.52%
     32K ...  64K-  :            1           15   6.30%
    512K ...1024K-  :            1          214  89.92%
//}



=== オプション一覧




==== -c




チャンクサイズが指定された場合、e2freefragはチャンクサイズの空きチャンクの数をキロバイト単位で表示する


チャンクとはデータベースサーバのデータ格納専用の物理ディスクの最大単位


各チャンクの最大サイズは4TBである



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo e2freefrag -c 8 /dev/sda1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Device: /dev/sda1
  Blocksize: 4096 bytes
  Total blocks: 256
  Free blocks: 238 (93.0%)


  Chunksize: 8192 bytes(2 blocks)
  Total chunks: 129
  Free chunk: 118 (91.5%)
  
  
  Min. free extent: 12 KB
  Max. free extent: 856 KB
  Avg. free extent: 236 KB
  Num. free extent: 4
  
  
  HISTOGRAM OF FREE EXTENT SIZES:
  Extent Size Range : Free extents  Free Blocks Percent
      8K ...  16K-  :            1            3   1.26%
     16K ...  32K-  :            1            6   2.52%
     32K ...  64K-  :            1           15   6.30%
    512K ...1024K-  :            1          214  89.92%
//}


#@# 

== ed

edは行指向のテキストエディタである。

対話的に、あるいはシェルスクリプトを使って、 テキストファイルの作成、表示、変更、その他の操作に使われる。

ed の制限付きバージョンである red は、カレントディレクトリのファイルのみを編集でき、 シェルコマンドを実行することはできない。

edは、Unixのオリジナルエディタであり、広く利用できるという意味で、「標準的な」テキストエディタである。

しかし、ほとんどの用途では、GNU EmacsやGNU Moeのようなフルスクリーンエディタが使用されている。



===== 実行例 



//list[][][fontsize=xx-small]{
  user@Ubuntu:~$ ed
  P
  *i
  Hello
  .
  *a
  Good Morining
  Good Night
  .
  *w test
  30
  *q
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  user@Ubuntu:~$ cat test
  Hello
  Good Morning
  Good Night
//}



=== オプション一覧




==== -E もしくは --extended-regexp




拡張正規表現を使う。



===== 実行例 



//list[][][fontsize=xx-small]{
  1,3p
  1,3s/'o{2}'/o/1
  1,3p
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Hello
  Good Morning
  Good Night

  Hello
  God Morining
  Good Night
//}


==== -G もしくは --traditional 


  

従来型、互換モードで実行する。




===== 実行例　



//list[][][fontsize=xx-small]{
  ed -G test
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  変化なし
//}



==== -l もしくは --loose-exit-status 


  

コマンドに失敗しても0ステータスで終了する。




===== 実行例　



//list[][][fontsize=xx-small]{
  ed -l test
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  *aaaa
  強制終了
//}


==== -p もしくは --prompt=STRING 


  

STRINGを対話型プロンプトとして使う。




===== 実行例　



//list[][][fontsize=xx-small]{
  ed -p test
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  test P
  test i
  Hello
  .
  test p
  Hello
  test w test
  6
  test Q
//}


==== -r もしくは --restricted 


  

制限モードで実行する。




===== 実行例　



//list[][][fontsize=xx-small]{
  ed -r
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  変化なし
//}


==== -s もしくは --quiet もしくは --silent 


  

診断、バイト数、'!'プロンプトを表示しない。




===== 実行例　



//list[][][fontsize=xx-small]{
  ed -s test
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  *w
  *q
//}


==== -v もしくは --verbose 


  

H'コマンドと同じ。




===== 実行例　



//list[][][fontsize=xx-small]{
  ed -v test
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  変化なし
//}


==== --strip-trailing-cr 


  

テキスト行末のキャリッジ・リターンを除去する。


一部のテキストファイルで行末に挿入される\rを削除できる。




===== 実行例　



//list[][][fontsize=xx-small]{
  ed --strip-trailing-cr test
  cat test
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
　Hello
  Good Morning
  Good Night
//}

