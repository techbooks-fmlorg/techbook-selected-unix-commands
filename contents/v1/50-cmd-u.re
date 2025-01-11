= 頭文字が u のコマンド


#@# 

== uniq

ファイル同士を比較し、連続して重複している部分を削るコマンドである。オプションなしだと、指定したファイルに上書きされる。
長いオプションに必須の引数は、短いオプションにも必須である。
基本ファイル内はsort済みであることを想定されているため、Sortは"必須"である。


===== 実行例 


//list[][][fontsize=xx-small]{
sort File2.txt -o File2.txt　(uniqにはsortが必要なため)
cat File2.txt　(catはそれぞれのtxtを確認するため)
uniq FIle2.txt
//}



===== 実行結果 


//list[][][fontsize=xx-small]{
$cat File2.txt
    Blossom
    blossom
    blooooooooooossom
    Elephant
    Radiant
    Serendipity
    Serendipity
$uniq FIle2.txt
    Blossom
    blossom
    blooooooooooossom
    Elephant
    Radiant
    Serendipity
//}


=== オプション一覧


  

==== -c もしくは --count



出現回数を単語の行ごと先頭に明記する。



===== 実行例 


//list[][][fontsize=xx-small]{
  uniq -c File2.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
    1 Blossom
    1 blossom
    1 blooooooooooossom
    1 Elephant
    1 Radiant
    2 Serendipity
//}



==== -d もしくは --repeated



グループごとに1行ずつ、重複している部分を出力する。



===== 実行例 


//list[][][fontsize=xx-small]{
  uniq -d File2.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  Serendipity
//}



==== -D もしくは --all-repeated[=METHOD]



重複する行を全て出力する。

「--all-repeated=none」->重複行のグループに区切りをいれない。(デフォルト)

「--all-repeated=prepend」->重複行のグループの手前に区切りをいれる。

「separate」で、グループの間に区切りの空白行をいれる。



===== 実行例 


//list[][][fontsize=xx-small]{
  uniq -D File2.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  Serendipity
  Serendipity
//}



==== -f もしくは --skip-fields=N



行全体ではなく、スペースやタブ文字で区切られた項目で重複を判断する。指定する際は一番左の項目から0,1の順で指定する。



===== 実行例 


//list[][][fontsize=xx-small]{
  cat File1.txt
  uniq -f 2 File1.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  $cat File1.txt
    1 Blossom 95
    2 Blossom 20
    3 Harmony 90
    4 Radiant 21
    5 Sunshine 21
    6 Whisper 21
  
  $uniq -f 2 File1.txt
    1 Blossom 95
    2 Blossom 20
    3 Harmony 90
    4 Radiant 21
//}



==== --group[=METHOD]



すべての項目を表示し、グループを空行で区切る。METHODに関してはオプション-Dで記述したものと同様である。

しかし上記3つに加えて"both"が存在する。これは先頭と最後それぞれに空行を入れる。



===== 実行例 


//list[][][fontsize=xx-small]{
  cat File2.txt
  uniq --group File2.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  $cat File2.txt
    Blossom
    blossom
    blooooooooooossom
    Elephant
    Radiant
    Serendipity
    Serendipity
  $uniq --group File2.txt
    Blossom

    blossom

    blooooooooooossom

    Elephant

    Radiant

    Serendipity
    Serendipity
//}



==== -i もしくは --ignore-case



比較の際、大文字と小文字の違いは無視する。



===== 実行例 


//list[][][fontsize=xx-small]{
  uniq -i File2.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  Blossom
  blooooooooooossom
  Elephant
  Radiant
  Serendipity
//}



==== -s もしくは --skip-chars=N



文頭からN文字までを比較対称としない。



===== 実行例 


//list[][][fontsize=xx-small]{
  uniq -s 1 File2.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  Blossom (Blossomは頭文字以外同じため消えている)
  blooooooooooossom
  Elephant
  Radiant
  Serendipity
//}



==== -u もしくは --unique



重複していない行だけを出力する。



===== 実行例 


//list[][][fontsize=xx-small]{
  uniq -u  -i File2.txt (今回は小文字、大文字のの違いを無視する)
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  blooooooooooossom
  Elephant
  Radiant
//}



==== -z もしくは --zero-terminated



行の区切り記号は改行ではなくNULLであるゼロバイト文字にする。



===== 実行例 


//list[][][fontsize=xx-small]{
  uniq -z File2.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  最後に改行されない他に変化しないため記載しない。
//}



==== -w もしくは --check-chars=N



N文字までを比較する。



===== 実行例 


//list[][][fontsize=xx-small]{
  cat File2.txt
  uniq -w 3 File2.txt
  uniq -w 4 File2.txt
//}




===== 実行結果 


//list[][][fontsize=xx-small]{
  $cat File2.txt
    Blossom
    blossom
    blooooooooooossom
    Elephant
    Radiant
    Serendipity
    Serendipity
  $uniq -w 3 File2.txt
    Blossom
    blossom
    Elephant
    Radiant
    Serendipity
  $uniq -w 4 File2.txt
    Blossom
    blossom
    blooooooooooossom
    Elephant
    Radiant
    Serendipity
//}

