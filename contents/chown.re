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

