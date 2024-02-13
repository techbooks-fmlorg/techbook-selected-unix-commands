#@# 

== dirname

指定されたパスからディレクトリの部分を取得する


=== オプション一覧




==== -z




ヌル文字（\0）を区切り文字として使用して出力する

この出力形式は、他のコマンドと組み合わせて使用する際に便利



===== 実行例 



//list[][][fontsize=xx-small]{
  find . -name "file.txt" -print0 | xargs -0 dirname -z
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ./path/to
  "file.txt"を見つけ、ディレクトリパスをヌル文字で区切って出力する
//}

