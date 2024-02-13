

== dir


指定されたディレクトリ内のファイルとサブディレクトリのリストを一覧表示できる


オプション一部一覧



==== -a もしくは -all




隠しファイルを含む全てのファイルを表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  dir -a
  dir -all
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  .       ..      file1.txt   .hidden_file   directory1   .hidden_directory
//}



==== -A もしくは --almost-all もしくは --author




"."と".."は除く"."で始まる隠しファイルを含む全てのファイルを表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  dir -A
  dir --almost-all
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  file1.txt   .hidden_file   directory1   .hidden_directory
//}



==== -b もしくは --escape もしくは --block-size=SIZE 


  

エスケープ文字を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  dir -b
  dir --escape
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  file1.txt  file2.txt  directory1  directory2
//}




==== -B もしくは --ignore-backups 


  

ファイルの最後に「～（チルダ）」がついたバックアップファイルを表示しない




===== 実行例　



//list[][][fontsize=xx-small]{
  dir -B
  dir --ignore-backups
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  file1.txt  file2.txt  directory1  directory2
//}



==== -c




変更日時(ctime)の新しい順でソートする





===== 実行例 



//list[][][fontsize=xx-small]{
  dir -c
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  file3.txt    ctime: Dec 5 2023 12:30
  file1.txt    ctime: Dec 3 2023 09:15
  directory2   ctime: Dec 1 2023 16:45
  directory1   ctime: Nov 30 2023 08:20
//}




==== -color




カラー表示にする



ディレクトリは青色


実行可能なファイルは緑色


一般的なファイルは白色



===== 実行例 



//list[][][fontsize=xx-small]{
  dir -color
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
    directory  file1.txt
//}





==== -d もしくは --directory




ディレクトリそのものの情報を表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  dir -d
  dir --directory
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  .
//}



==== -i




iノード番号を表示



===== 実行例 



//list[][][fontsize=xx-small]{
  dir -i
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  9851624185227536 directory
  7881299348254011 file.txt
//}



==== -l




詳細な情報を表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  dir -l
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  drwxr-xr-x 1 name 197609 0 Dec  6 23:55 file.txt
  drwxr-xr-x 1 name 197609 0 Dec  23 11:32 directory
//}



==== -t




ファイル更新日時でソートして表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  dir -t
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  file3.txt  file1.txt directory2  directory1
//}



- @<strong>{-S}



  ファイルサイズが大きいものからソートする



===== 実行例 



//list[][][fontsize=xx-small]{
  dir -S
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  file1.txt  file2.txt  directory  directory2
//}



- @<strong>{-1}



リストを縦１列で表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  dir -1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  directory
  directory2
  file1.txt
  file4.txt
  file2.txt
//}

