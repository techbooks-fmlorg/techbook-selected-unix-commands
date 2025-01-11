= 頭文字が d のコマンド

#@# 

== date


与えられたフォーマットで現在時刻を表示するか、システム日付を設定する。

長いオプションに必須の引数は、短いオプションにも必須である。





===== 実行例 



//list[][][fontsize=xx-small]{
  date
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023年 12月21日 木曜日 13:30:13 JST
//}



=== オプション一覧




==== -d もしくは --date=STRING




STRINGで指定された時刻、を表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  date -d "2023-09-10"
  date --date=tomorrow
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023年 9月 10日 日曜日 00:00:00 JST
  2023年　12月 22日 金曜日 13:32:22 JST
//}


==== --debug 


  

解析された日付に注釈を付け、疑わしい使い方については標準エラー出力に警告を出す。




===== 実行例　



//list[][][fontsize=xx-small]{
  date --debug
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023年 12月21日 木曜日 14:50:19 JST
//}


==== -f もしくは --file=DATEFILE 


  

"--date"と同様


DATEFILEの各行に対して1回ずつ




===== 実行例　



//list[][][fontsize=xx-small]{
  date -f time.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023年 12月 22日 金曜日 05:00:00 JST
//}


==== -I'FMT' もしくは --iso-8601=FMT 


  

ISO 8601 形式の日付/時刻を出力する


フォーマットは'date':日付のみ(デフォルト)、'hours':時、'minutes':分、'seconds':秒または'ns'ナノ秒で表す




===== 実行例　



//list[][][fontsize=xx-small]{
  date -I'date'
  date -I'ns' -d tomorrow
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023-12-21
  2023-12-22T15:14:26,204385695+09:00
//}


==== -R もしくは --rfc-email



 RFC 5322 形式の日付と時刻を出力する



===== 実行例 



//list[][][fontsize=xx-small]{
  date -R
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Fri, 22 Dec 2023 22:42:39 +0900
//}


==== -r もしくは --reference=FILE




FILEの最終更新時刻を表示



===== 実行例 



//list[][][fontsize=xx-small]{
  date -r time.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023年 12月 22日 金曜日 22:41:36 JST
//}


==== -s もしくは --set=STRING




STRINGで指定された時刻を設定する



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo date -s "2023-01-01"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023年 1月 1日 日曜日 00:00:00 JST
//}


==== -u もしくは --utc もしくは --universal




協定世界時(UTC)を表示または設定する



===== 実行例 



//list[][][fontsize=xx-small]{
  date -u
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023年 12月 22日 金曜日 13:49:10 UTC
//}

**フォーマットについて**



"+%"の形で書くことのできる表示形式のこと


==== %%




%を文字として表す



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%%"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  %
//}


==== %a




地域の短縮形の曜日名



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%%-%a"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  %-金
//}


==== %A




地域の完全な曜日名



===== 実行例 



//list[][][fontsize=xx-small]{
  date "%%-%a-%A"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  %-金-金曜日
//}


==== %b




地元の短縮形の月名



===== 実行例 



//list[][][fontsize=xx-small]{
  date "%b"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  12月
//}


==== %B




地域の完全な月名



===== 実行例 



//list[][][fontsize=xx-small]{
  date "%b-%B"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  12月-12月
//}


==== %c




地域の日付と時刻



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%c"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023年12月22日 22時57分50秒
//}


==== %C




世紀; 下2桁を省略する以外は%Yと同じ



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%C"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  20
//}


==== %d




日付



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%d"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  22
//}


==== %D




日付;%m/%d/%y



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%D"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  12/22/23
//}


==== %e




%dと同様



スペースパッドされた日

スペースパッドとは、文字列の周りにスペースや他の文字を追加して、特定のフォーマットや整列を実現するために使われる


スペースを使って余白を埋めることを指している



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%e"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  22
//}


==== %F




完全な日付を表示する


"%+4Y-%m-%d"と同様



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%F"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023-12-22
//}


==== %g




ISO 週番号の年の下二桁 



詳細は %G を参照



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%g"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  23
//}


==== %G




ISO 週番号の年


詳細は %V を参照



%V のみより使用頻度が高い



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%G"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023
//}


==== %h




%bと同じ



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%h"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  12月
//}


==== %H




時間(00..23)



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%H"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  23
//}


==== %I




時間(01..12)



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%I"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  11
//}


==== %j




日にち(001..366)



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%j"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  356
//}


==== %k




時間、スペース・パッド(0..23);%_Hと同じ



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%k"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  23
//}


==== %l




時間、スペース・パッド(0..23)



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%l"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  11
//}


==== %m




月(01..12)



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%m"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  12
//}


==== %M




分(00.59)



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%M"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  07
//}


==== %n




改行する



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%M%n%m"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  07
  12
//}


==== %N




ナノ秒(000000000. . 999999999)



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%N"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  407200293
//}


==== %p




地域のAMまたはPMに相当



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%p"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  午後
//}


==== %P




%pのようなものだが、小文字


日本語では変化なし



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%P"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  午後
//}


==== %q




年の四半期(1..4)



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%q"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4
//}


==== %r




地域の12時間時計の時刻



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%r"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  午後11時10分38秒
//}


==== %R




24時間制の時間と分



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%R"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  23:11
//}


==== %s




1970-01-01 00:00:00 UTCからの秒数



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%s"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1703254359
//}


==== %S




秒(00..60)



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%S"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  08
//}


==== %t




タブ



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%S%t%s"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  42    1703254422
//}


==== %T




時間

%H:%M:%sと同じ



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%T"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  23:14:19
//}


==== %u




曜日(1..7)


1は月曜日



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%u"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  5
//}


==== %U




週番号(00.53)


日曜日を週の最初の曜日とする



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%U"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  51
//}


==== %V




ISO週番号(01..53)


月曜日が週の初日


1は月曜日



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%V"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  51
//}


==== %w




曜日(0..6)


0は日曜日



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%w"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  5
//}


==== %W




年の週番号(00..53)


月曜日を週の最初の曜日とする



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%W"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  51
//}


==== %x




地域の日付表現



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%x"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023年12月22日
//}


==== %X




地域の時刻表限



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%X"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  23時18分20秒
//}


==== %y




年の下2桁(00..99)



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%y"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  23
//}


==== %Y




西暦の年



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%Y"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  2023
//}


==== %z




+hhmm数字タイムゾーン



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%z"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  +0900
//}


==== %:z




+hh:mm数値タイムゾーン



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%:z"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  +09:00
//}


==== %::z




+hh:mm:ss数値タイムゾーン



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%::z"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  +09:00:00
//}


==== %:::z




必要な精度の数値タイムゾーン



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%:::z"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  +09
//}


==== %Z




アルファベットによるタイムゾーンの省略形



===== 実行例 



//list[][][fontsize=xx-small]{
  date "+%Z"
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  JST
//}



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

#@# 

== dircolors

Linuxシステム上のディレクトリとファイルの表示色を設定する


=== オプション一覧




==== -b もしくは --sh もしくは --bourne-shell




Bourneシェル形式でLS_COLORSを出力する



===== 実行例 



//list[][][fontsize=xx-small]{
  dircolors -b
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  LS_COLORS='rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:';
  export LS_COLORS

//}


==== -c もしくは --csh もしくは --c-shell 


  

Cシェル形式でLS＿COLORSを出力する




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}



==== -p もしくは --print-database 


  

デフォルト値を標準入力に表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}

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

#@# 

== dmesg

Linuxカーネルが起動時に出力したメッセージを表示するコマンド

システム起動時のトラブルシューティングやデバイスの接続情報の確認、デバッグ情報の収集に用いることができる

カーネルの操作のためルート権限が必要






===== 実行例 



//list[][][fontsize=xx-small]{
  sudo dmesg
//}





===== 実行結果（以下一部のみ）　



//list[][][fontsize=xx-small]{
  [0.000000] Command line: BOOT_IMAGE=/boot/vmlinuz-6.2.0-37-generic root=UUID=b784ca7c-8602-4f1c-8436-8089242f37f3 ro quiet splash
//}


=== オプション一覧




==== -l




表示レベルを指定する



「emerg(高)」「alert」「crit」「err」「warn」「notice」「info」「debug(低)」から選択、複数指定は","で区切る



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo dmesg -l warn
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [0.890430] acpi PNPOA03:00: fail to add MMCONFIG information, can't access extended configuration space under this bridge
  [2.420791] device-mapper: core: CONFIG_IMA_DISABLE_HTABLE is disabled. Duplicate IMA measurements will not be recorded in the IMA log.
  [2.420872] platform eisa.0: EISA: Cannot allocate resource for mainboard
  [2.420873] platform eisa.0: Cannot allocate resource for EISA slot 1
  [2.420874] platform eisa.0: Cannot allocate resource for EISA slot 2
  [2.420875] platform eisa.0: Cannot allocate resource for EISA slot 3
  [2.420876] platform eisa.0: Cannot allocate resource for EISA slot 4
  [2.420876] platform eisa.0: Cannot allocate resource for EISA slot 5
  [2.420877] platform eisa.0: Cannot allocate resource for EISA slot 6
  [2.420878] platform eisa. 0: Cannot allocate resource for EISA slot 7
  [2.420879] platform eisa.0: Cannot allocate resource for EISA slot 8
  [20.683554] kauditd_printk_skb: 8 callbacks suppressed
  [25.849810] kauditd_printk_skb: 8 callbacks suppressed
  [61.011374] kauditd_printk_skb: 4 callbacks suppressed
//}


==== -f 


  

表示対象を指定する

「kern(カーネル)(-kオプション)」「user(-uオプション)」「mail」「daemon」「auth」「syslog」「lpr」「news」から選択、複数指定は","で区切る


===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -f kern
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [0.000000] Linux version 6.2.0-37-generic (buildd@bos03-amd64-055) (x86_64-linux-gnu-gcc-11 (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0, GNU ld (GNU Binutils forUbuntu) 2.38) #38~22.04.1-Ubuntu SMP PREEMPT_DYNAMIC Thu Nov 2 18:01:13 UTC 2 (Ubuntu 6.2.0-37.38~22.04.1-generic 6.2.16)
  [0.000000] Command line: BOOT_IMAGE=/boot/vmlinuz-6.2.0-37-generic root=UUID=b784ca7c-8602-4f1c-8436-8089242f37f3 ro quiet splash
  [0.000000] KERNEL supported cpus:
  Intel GenuineIntel
  AMD AuthenticAMD
  Hygon HygonGenuine
  Centaur CentaurHaulszhaoxin
  [0.000000] BIOS-provided physical RAM map:
//}



==== -x 


  

表示レベルと表示対象を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -x
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  kern :notice: [0.000000] Linux version 6.2.0-37-generic (buildd@bos03-amd64-055) (x86_64-linux-gnu-gcc-11 (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0, GNU ld (GNU Binutils for Ubuntu) 2.38) #38~22.04.1-Ubuntu SMP PREEMPT_DYNAMIC Thu Nov 2 18:01:13 UTC 2 (Ubuntu 6.2.0-37.38~22.04.1-generic 6.2.16)
  kern :info : [0.000000] Command line: BOOT_IMAGE=/boot/vmlinuz-6.2.0-37-generic root=UUID=b784ca7c-8602-4f1c-8436-8089242f37f3 ro quiet splash
  kern:info : [0.000000] KERNEL supported cpus:
  kern:info : [0.000000]Intel GenuineIntel
  kern:info : [0.000000]AMD AuthenticAMD
  kern:info : [0.000000]Hygon HygonGenuine
  kern:info : [0.000000]Centaur CentaurHauls
  kern:info : [0.000000]zhaoxin  Shanghai
  kern:info : [0.000000] BIOS-provided physical RAM map:
//}


==== -d 


  

直前のメッセージからの経過時間を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -d
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [  86.241961 <0.000447>] audit: type=1400 audit(1702012655.625:77): apparmor="DENIED" operation="capable" class="cap" profile="/snap/snapd/19457/usr/lib/snapd/snap-confine" pid=1850 comm="snap-confine" capability=38 capname="perfmon"
//}



==== -e 


  

メッセージの表示時刻とメッセージ間の経過時間を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -e
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [+0.000447] audit: type=1400 audit(1702012655.625:77): apparmor="DENIED" operati
  on="capable" class="cap" profile="/snap/snapd/19457/usr/lib/snapd/snap-confine" pid=1850 comm="snap-confine" capability=38 capname="perfmon"
//}



==== -T 


  

メッセージが出力された時刻で表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -T
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [金 12月 8 14:17:35 2023] audit: type=1400 audit(1702012655.625:77): apparmor="DENIED" operation="capable" class="cap" profile="/snap/snapd/19457/usr/lib/snapd/snap-confine" pid=1850 comm="snap-confine" capability=38 capname="perfmon"
//}


==== -t 


  

時間を表示しない




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -t
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  audit: type=1400 audit(1702012655. 625:77): apparmor="DENIED" operation="capable" class="cap" profile="/snap/snapd/19457/usr/lib/snapd/snap-confine" pid=1850 comm="snap-confine" capability=38 capname="perfmon"
//}



==== -H 


  

読みやすいスタイルで表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -H
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [+0.000002] DMA [mem 0x0000000000001000-0x0000000000ffffff]
  [+0.000003] DMA32 [mem 0x0000000001000000-0x00000000ffffffff]
  [+0.000001] Normal
  [+0.000002] [mem 0x0000000100000000-0x000000011fffffff]
  [+0.000001] Movable zone start for each node
//}


==== -r 


  

メッセージを加工せずに表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -r
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  <5>[86.241961] audit: type=1400 audit(1702012655.625:77) : apparmor="DENIED" operation="capable" class="cap" profile="/snap/snapd/19457/usr/lib/snapd/snap-confine" pid=1850 comm="snap-confine" capability=38 capname="perfmon"
//}


==== -L 


  

色付きで表示する

出力に変化がないので割愛



==== -w 


  

新しいメッセージがカーネルから出力されるのを待つ






===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -w
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [ 2664.473779] audit: type=1326 audit(1702015233.848:78): auid=1000 uid=1000 gid=1000 ses=2 subj=snap.firefox.firefox pid=2429 comm="firefox" exe="/snap/firefox/2987/usr/lib/firefox/firefox" sig=0 arch=c000003e syscall=314 compat=0 ip=0x7f14f03e973d code=0x50000
//}


==== -F 


  

バッファーの代わりに指定したファイルを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -F file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [   0.000000] Hello
//}


==== -S 


  

syslogを使って表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -S
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  [86.241961] audit: type=1400 audit(1702012655.625:77): apparmor="DENIED" operation="capable" class="cap" profile="/snap/snapd/19457/usr/lib/snapd/snap-confine" pid=1850 comm="snap-confine" capability=38 capname="perfmon"
//}


==== -C 



バッファーをクリアする




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -C
  sudo dmesg
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  何も表示されなくなる
//}


==== -c 



リンクバッファーを出力してクリアする




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -c
  sudo dmesg 
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  sudo dmesg -c
  [ 3082.092138]audit:type=1326 audit(1702015651.467:79): auid=1000 uid=1000 gid=1000 ses=2 subj=snap.firefox.firefox pid=3081 comm="firefox" exe="/snap/firefox/2987/usr/lib/firefox/firefox" sig=0 arch=c000003e syscall=314 compat=0 ip=0x7efc049f373d code=0x50000
  sudo dmesg 
  何も表示されない
//}


==== -D 



コンソールへの出力を無効にする




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -D
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}


==== -E 



コンソールへの出力を有効にする




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -E
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}


==== -n 



コンソールに表示するレベルを指定する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dmesg -n alert
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}

#@# 

== dmidecode

ハードウェアの情報を表示するコマンド
DMIテーブルに格納されている情報を見やすい形に成型して表示する

ハードウェアの特定と確認、BIOSの情報確認、メモリの詳細な情報の取得、サーバー管理とトラブルシューティングに利用できる
詳細を見る場合はルート権限




===== 実行例 



//list[][][fontsize=xx-small]{
  sudo dmidecode
//}





===== 実行結果（一部）　



//list[][][fontsize=xx-small]{
  # dmidecode 3.3
Getting SMBIOS data from sysfs.
SMBIOS 2.5 present.
10 structures occupying 456 bytes.
Table at 0x000E1000.
//}




=== オプション一覧






==== -d




情報元のファイルを指定する

(デフォルトは/dev/main)



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo dmidecode -d /dev/main
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  上記と同様
//}


==== -q




文章説明



===== 実行例 



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  BIOS Information
     Vendor: innotek GmbH
     Version: VirtualBox
     Release Date: 12/01/2006
     Address: 0xE0000
     Runtime Size: 128 kB
     ROM Size: 128 kB
     Characteristics:
          ISA is supported
          PCI is supported
          Boot from CD is supported
          Selectable boot is supported
          8042 keyboard services are　supported (int 9h)
          CGA/mono video services are supported (int 10h)
          ACPI is supported
//}


==== -s




指定したキーワードの情報だけを表示する

指定できるキーワードの一覧は「dmidecode -s」で確認可能



===== 実行例 



//list[][][fontsize=xx-small]{
  dmidecode -s

  sudo dmidecode -s bios-vendor
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dmidecode: option requires an argument -- 's'
  String keyword expected
  Valid string keywords are:
  bios-vendor
  bios-version
  bios-release-date
  bios-revision
  firmware-revision
  system-manufacturer
  system-product-name
  system-version
  system-serial-number

  innotek GmbH
//}


==== -t




指定したタイプの情報だけを表示する

指定できるタイプの一覧は「dmidecode -t」で確認可能



===== 実行例 



//list[][][fontsize=xx-small]{
  dmidecode -t

  sudo dmidecode -t chassis
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dmidecode: option requires an argument -- 't'
  Type number or keyword expected
  Valid type keywords are:
  bios
  system
  baseboard
  chassis
  processor
  memогy
  cache
  connector
  slot


  # dmidecode 3.3
  Getting SMBIOS data from sysfs.
  SMBIOS 2.5 present.
  
  Handle 0x0003, DMI type 3, 13 bytes
  Chassis Information
  Manufacturer: Oracle Corporation
  Type: Other
  Lock: Not Present
  Version: Not Specified
  Serial Number: Not Specified
  Asset Tag: Not Specified
  Boot-up State: Safe
  Power Supply State: Safe
  Thermal State: Safe
  Security Status: None
//}


==== -H




指定したCLIハンドルの情報だけを表示する


===== 実行例 



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  # dmidecode 3.3Getting SMBIOS data from sysfs.
  SMBIOS 2.5 present.
  10 structures occupying 456 bytes.
  Table at 0x000E1000.
  Handle 0x0003, DMI type 3, 13 byte
  Chassis Information
  Manufacturer: Oracle Corporation
  Type: Other
  Lock: Not Present
  Version: Not Specified
  Serial Number: Not Specified
  Asset Tag: Not Specified
  Boot-up State: Safe
  Power Supply State: Safe
  Thermal State: Safe
  Security Status: None
//}


==== -u




情報をデコードせず16進数コードのまま表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo dmidecode -u
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  # dmidecode 3.3
  Getting SMBIOS data from sysfs.
  SMBIOS 2.5 present.
  10 structures occupying 456 bytes.
  Table at 0x000E1000.
  Handle 0x0000, DMI type 0, 20 bytes
  Header and Data:
  00 14 00 00 01 02 00 E0 03 01 90 80 01 48 00 00 00 00 01 00
  Strings:
  69 6E 6E 6F 74 65 6B 20 47 6D 62 48 00
  innotek GmbH
  56 69 72 74 75 61 6C 42 6F 78 00
  VirtualBox
  31 32 2F 30 31 2F 32 30 30 36 00 
  12/01/2006
//}

#@# 

== dnsdomainname

ドメイン名を表示する

システムの設定やネットワークにより静的に設定されるため使用頻度は低い



===== 実行例 



//list[][][fontsize=xx-small]{
  dnssomainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示されない
//}




=== オプション一覧



==== -a




ドメインネームの別名も表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  dnsdomainname -a
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示されない
//}


==== -A 


  

全てのホスト名をFQDN(ドメイン名を省略)で表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -A
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VirtualBox
//}


==== -b 


  

設定したホスト名を、ずっと有効にする




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -b
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示なし
//}


==== -d 


  

DNSのドメイン名を表示する

詳細表示しようとするとFQDNと誤解されるため使用頻度は低い




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -d
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示なし
//}


==== -f 


  

ホスト名をFQDNで表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -f
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VitualBox
//}


==== -F 


  

ホスト名をファイルから読み込む




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -F example.com
  dnsdomainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  example.com
//}


==== -i 


  

ホスト名に対応するIPアドレスを表示する

このオプションが使えない場合は代わりに「-I」オプションを使う




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  127.0.1.1
//}


==== -I 


  

設定されているすべてのホスト名に対応するIPアドレスを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -I
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  10.0.2.15
//}


==== -s 


  

短縮表現のホスト名を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  dnsdomainname -s
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VitualBox
//}


==== -y 


  

NISドメイン名(NISの仕組みで使われるドメイン名)を表示・設定する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dnsdomainname -y domainname
  domainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  domainname
//}

#@# 

== do-release-upgrade

新しいUbuntuがリリースされた際に最新のバージョンにアップグレードするために使用
今回はアップグレードしないためPromptを変更しない

Promptはアップグレード中に表示される質問や確認のことを示す

通常ルート権限で実行する



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo do-release-upgrade
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  新しい ubuntu のリリースをチェックしています
入手可能なLTSの開発版はありません。
最新の非LTS開発リリースにアップグレードする
/etc/update-manager/release-upgradesにPrompt=normalとセットしてください。
//}




=== オプション一覧






==== -d




サポートされている最新のリリースを使用している場合、開発版リリースにアップグレードする



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo do-release-upgrade -d
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  新しい ubuntu のリリースをチェックしています
  アップグレードの前に入手可能なすべてのアップデートをインストールしてください。
//}


==== -p 


  

アップグレードソフトウェアを使って$distro-proposedから最新のリリースへのアップグレードを試す




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo do-release-upgrade -p
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  新しい ubuntu のリリースをチェックしています
  入手可能なLTSの開発版はありません。
  最新の非LTS開発リリースにアップグレードする
  /etc/update-manager/release-upgradesにPrompt=normalとセットしてください。
//}


==== -m 


  

特別なアップグレードモードを実行する。現在、デスクトップシステムの標準的なアップグレードを行う

'desktop'または'server'オプションがある




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo do-release-upgrade -m desktop
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  新しい ubuntu のリリースをチェックしています
  入手可能なLTSの開発版はありません。
  最新の非LTS開発リリースにアップグレードする
  /etc/update-manager/release-upgradesにPrompt=normalとセットしてください。
//}


==== -f 


  

特定のフロントエンドで実行

非対話型のアップグレードになり、自動処理されるため、アップグレードがスムーズに進行される場合にのみ、このオプションを使用するべき




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo do-release-upgrade -f server
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  新しい ubuntu のリリースをチェックしています
  入手可能なLTSの開発版はありません。
  最新の非LTS開発リリースにアップグレードする
  /etc/update-manager/release-upgradesにPrompt=normalとセットしてください。
//}


==== -c 


  

新しいディストリビューション・リリースが利用可能かどうかチェックし、終了コードで結果を通知する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo do-release-upgrade -c
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  新しい ubuntu のリリースをチェックしています
  入手可能なLTSの開発版はありません。
  最新の非LTS開発リリースにアップグレードする
  /etc/update-manager/release-upgradesにPrompt=normalとセットしてください。
//}


==== --data-dir 


  

データファイルの含まれるディレクトリ




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo -do-release-upgrade --data-dir desktop
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  新しい ubuntu のリリースをチェックしています
  入手可能なLTSの開発版はありません。
  最新の非LTS開発リリースにアップグレードする
  /etc/update-manager/release-upgradesにPrompt=normalとセットしてください。
//}


==== --allow-third-party 


  

サードパーティのミラーとリポジトリをコメントアウトする代わりに有効にしてアップグレードを試す




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo do-release-upgrade --allow-third-party
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  新しい ubuntu のリリースをチェックしています
  入手可能なLTSの開発版はありません。
  最新の非LTS開発リリースにアップグレードする
  /etc/update-manager/release-upgradesにPrompt=normalとセットしてください。
//}


==== -q 


  

アップグレードプロセスの出力が最小限に抑えられ、進行状況や詳細な情報が表示されない




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo do-release-upgrade -q
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示されない
//}


==== -e 


  

アップグレードプロセスがエクスプレスモードで実行され、エクスプレスモードでは、ユーザの介入なしでアップグレードが進行し、デフォルトの設定がされる




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo do-release-upgrade -e desktop
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  新しい ubuntu のリリースをチェックしています
  入手可能なLTSの開発版はありません。
  最新の非LTS開発リリースにアップグレードする
  /etc/update-manager/release-upgradesにPrompt=normalとセットしてください。
//}

#@# 

== domainname

ネットワーキングやドメイン関連の設定を行う際に使用される

しかし、シンプルな構文と変更の即時変更の観点からhostnameコマンドが推奨される場合が多い
また、dnsdomainnameとも互換性がある



===== 実行例 



//list[][][fontsize=xx-small]{
  domainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  domainname
//}




=== オプション一覧






==== -a




ドメイン名の別名も表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  domainname -a
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示されない
//}


==== -A 


  

全てのホスト名をFQDN(ドメイン名を省略)で表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -A
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VirtualBox
//}


==== -b 


  

設定したホスト名を、ずっと有効にする




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -b
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  domainname
//}


==== -d 


  

DNSのドメイン名を表示する

詳細表示しようとするとFQDNと誤解されるため使用頻度は低い




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -d
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  domainname -d
//}


==== -f 


  

ホスト名をFQDNで表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -f
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VirtualBox
//}


==== -F 


  

ホスト名をファイルから読み込む




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo domainname -F file.txt
  domainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Hello
//}


==== -i 


  

ホスト名に対応するIPアドレスを表示する

このオプションが使えない場合は代わりに「-I」オプションを使う




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -i
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  127.0.1.1
//}


==== -I 


  

設定されているすべてのホスト名に対応するIPアドレスを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -I
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  10.0.2.15
//}


==== -s 


  

短縮表現のホスト名を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  domainname -s
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  ubuntu-VitualBox
//}


==== -y 


  

NISドメイン名(NISの仕組みで使われるドメイン名)を表示・設定する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo domainname -y domainname1
  domainname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  domainname1
//}

#@# 

== dosfsck

FATファイルシステムのシステムおよび修復を行うために使用される
ファイルシステムの破損やエラーが発生したときに使用され、予期せぬシステムクラッシュ、異常なシャットダウン、メディアの障害などが原因で損傷が生じた場合に利用される。
他のファイルシステムでは使用できない
オプションなしの実行は不可

dosfsckとは"DOS File System Check"でDOSとはディスクオペレーションシステムであり、コマンドラインインターフェースを提供する

FATとは"File Allocation Table"でストレージ内でファイルやディレクトリについての情報を記録する特殊なシステム領域と構築されるシステムのことである


=== オプション一覧



==== -a




自動的にファイルシステムを修復する



===== 実行例 



//list[][][fontsize=xx-small]{
  dosfsck -a file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -A 


  

AtariバリアントのFATファイルシステムを切り替える




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -A file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -b 


  

読み取り専用のブートセクタチェックを行う




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -b file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -c 


  

DOSコードページNを使用して短いファイル名をデコードする(デフォルト:850)




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}


==== -d 


  

PATHのファイルを削除する




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -d home/usrname
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}


==== -f 


  

未使用のチェーンをファイルに回収




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -f file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -F 


  

ファイルシステムアクセスに使用されるFATシステムバリアントを指定する

バリアントによってビット幅の異なるクラスターエントリを備えたファイルシステムを使用する



===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -F FAT32 /dev/sdb1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dosfsck 3.0.13, 30 Jun 2019, FAT32, LFN
  /dev/sdb1: 16 files, 1000/2000 clusters
//}


==== -l 


  

パス名をリストする




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -l file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -n 


  

変更せずに対話的にファイルシステムをチェックする




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -n file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -p 


  

他のfsckとの互換性のための"-a"と同じ

プレテンスモードでファイルシステムのチェックを行わずにチェックを実行する前の予備情報を表示するモードで実行する




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -p file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -r 


  

対話的にファイルシステムを修復する




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -r file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -S 


  

短いファイル名の途中にスペースを許可しない




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -S file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -t 


  

不良クラスタのテストを実行する




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -t file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -u 


  

復元可能なディレクトリでないファイルを復元する




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -u file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示なし
//}


==== -U 


  

ボリュームとブートラベルに大文字のみを許可する




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -U file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -v 


  

詳細モードで実行する




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -v file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -V 


  

検証パスを実行する




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -V oaif
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Logical sector size (58930 bytes) is not a multiple of the physical sector size
//}


==== --variant 


  

ファイルシステムのバリアントTYPEを処理する




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck --variant=FAT32 /dev/sdb2
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dosfsck 3.0.13, 30 Jun 2019, FAT32, LFN
  /dev/sdb1: 16 files, 1000/2000 clusters
//}


==== -w 


  

変更を直ちにディスクに書き込む




===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -w file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}


==== -y 


  

他のfsckとの互換性のための-aと同じ

非対話モードで実行し、問題を検出すると自動的に修復が行われる


===== 実行例　



//list[][][fontsize=xx-small]{
  dosfsck -y file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  fsck.fat 4.2 (2021-01-31)
  Got 6 bytes instead of 512 at 0
//}

#@# 

== dosfslabel


FATファイルシステムのラベルを設定、表示する
ボリューム名を変更、確認する必要がある場合に使用されるため使用頻度はあまり高くない
ボリューム名はリムーバブルメディアを他のデバイスと区別するために使用されることがある



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo dosfslabel /dev/sda
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Logical sector size is zero.
//}




=== オプション一覧




==== -i




ラベルの代わりにシリアルナンバーを使い実行する



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo dosfslabel -i /dev/sda
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Logical sector size is zero.
//}


==== -r 


  

ラベルを取り除くかシリアルナンバーを新しく生成する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dosfslabel -r /dev/sda
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Logical sector size is zero.
//}


==== -c 


  

ラベルのエンコード/デコードにDOSコードページを使用する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dosfslabel -c 800 /dev/sda
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Cannot initialize conversion from codepage 800 to UTF-8: Invalid argument
  Cannot initialize conversion from UTF-8 to codepage 800: Invalid argument
//}

#@# 

== du

ディスク上のディレクトリやファイルのディスク使用量を表示するために使用する
システム管理者や開発者など、ディスク使用量の監視やトラブルシューティングを行うため高頻度で使用される
一般ユーザではディスク容量が不足している場合や特定のディレクトリやファイルのサイズを確認したい場合に使用されることがある

ディスク使用量を表示するため、大規模なディレクトリやファイルの場合では実行に時間がかかることがあり、正確な計算には適切なオプションが必要である

シンボリックリンクとはファイルシステムにおいて、特定のファイルシステムやディレクトリへの参照を作成するために使用される特殊なファイル
ファイルやディレクトリのパス名を指定し、そのパス名に対する参照を提供する



===== 実行例 



//list[][][fontsize=xx-small]{
  du file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4      file.txt
//}




=== オプション一覧




==== -0




各出力を改行ではなくNULLで終了させる



===== 実行例 



//list[][][fontsize=xx-small]{
  du -0
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4  ./.cache/tracker3/files/errors14244  . /.cache/mesa_shader_cache/388   . /. cacache/1e8   he/mesa_shader_cache/2512   ache/ce8  ache/6312   ·/ピクチャ4   he/tracker3/files14248   he/mesa_shader_cache/cf8  ache/1a8   he/mesa_shader_cache/138. /. cache/mesa_shader_cache/658 . /.cache/mesa_shader_cache/e28./. cac . /.cache/mesa_shader_cache/cc8 ./.cache/mesa_shader_  . cache/mesa_shader_cache/998 ./. cache/mesa_shader_cache/448 ./.cache/mesa_shader_cache/068  he/mesa_shader_cache/2e12 . /.cache/mesa_shader_cache/758   ·/ビデオ4  . /. cache/tracker38  . /.cache/mesa_shader_cache/a48 . /.cache/mesa_shader_c . /. cache/mesa_shader_cache/848 . /.cache/mesa_shader_cache/3f8  . /. cache/mesa_shader_cache/2912 . /. cache/mesa_shader_c  . /.cache/mesa_shader_cache/8d12 . /.cache/mesa_shader_c  . /. cache/mesa_shader_cache/d68 ./.cache/mesa_shader_cache/708   ./. cac   . /. cache/mesa_shader_cache/268 . /.cache/mesa_shader_c   ./.cache/mesa_shader_cache/3c8 ./.cac
//}


==== -a 


  

ディレクトリだけでなく、すべてのファイルのカウントを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  du -a
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4     . /.config/mozc/ibus_config. textproto
  424   ./.config/mozc
  0     . /.config/ibus-mozc-gnome-initial-setup-done
  4     . /.config/evolution/sources/system-proxy. source
  8     . /.config/evolution/sources
  12    . /.config/evolution
  580   ./. config
  97576 .
//}


==== --apparent-size 


  

ディスク使用量ではなく、表面のサイズを表示する

表面のサイズは通常は小さいが、ファイルのホール、内部の断片化、関節ブロックのために大きくなることがある




===== 実行例　



//list[][][fontsize=xx-small]{
  du --apparent-size
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  73     . /.config/pulse
  4      . /.config/update-notifier
  397    . /.config/mozc
  6      . /.config/evolution/sources
  10     . /.config/evolution
  515    . /.config
  97162  .
//}


==== -B 


  

SIZEの倍率として表示する

"-BM"は1,048,576バイト単位でサイズを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  du -BM /home/ubuntu/.config
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  1M  /home/ubuntu/.config/gtk-3.0
  1M  /home/ubuntu/.config/goa-1.0
  1M  /home/ubuntu/.config/ibus/bus
  1M  /home/ubuntu/.config/ibus
  1M  /home/ubuntu/.config/nautilus
  1M  /home/ubuntu/.config/dconf
  1M  /home/ubuntu/.config/pulse
//}


==== -c 


  

総合計量を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  du -c file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4     file.txt
  4     合計
//}


==== -D 


  

コマンドラインで指定されたシンボリックのみをたどる




===== 実行例　



//list[][][fontsize=xx-small]{
  du -D /home/ubuntu/.config/evolution/
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  8     /home/ubuntu/.config/evolution/sources
  12    /home/ubuntu/.config/evolution/
//}


==== -d 


  

コマンド実行場所から,N階層以内のディレクトリの合計を表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  du -d 4 /home/ubuntu/.config
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  8　　　/home/ubuntu/.config/gtk-3.0
  4　　　/home/ubuntu/.config/goa-1.0
  12　　 /home/ubuntu/.config/ibus/bus
  16     /home/ubuntu/.config/ibus
  4      /home/ubuntu/.config/nautilus
  8      /home/ubuntu/.config/dconf
  84     /home/ubuntu/.config/pulse
  4      /home/ubuntu/.config/update-notifier
  424    /home/ubuntu/.config/mozc
  8      /home/ubuntu/.config/evolution/sources
  12     /home/ubuntu/.config/evolution
  580    /home/ubuntu/.config
//}


==== -H 


  

シンボリックを解決し、リンク先のファイルやディレクトリを操作するオプションと同じもの




===== 実行例　



//list[][][fontsize=xx-small]{
  du -H /home/ubuntu/file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4      /home/ubuntu/file.txt
//}


==== -h 


  

人に読みやすい形でサイズを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  du -h /home/ubuntu/.config
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4.0K     /home/ubuntu/.config/nautilus
  8.0K     /home/ubuntu/.config/dconf
  84K      /home/ubuntu/.config/pulse
  4.0K     /home/ubuntu/.config/update-notifier
  424K     /home/ubuntu/. config/mozc
  8.0K     /home/ubuntu/.config/evolution/sources
  12K      /home/ubuntu/.config/evolution
  580K     /home/ubuntu/.config
//}


==== -k 


  

ブロックサイズを1K単位とした時と同じ




===== 実行例　



//list[][][fontsize=xx-small]{
  du -k /home/ubuntu/
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4.0K     /home/ubuntu/.config/nautilus
  8.0K     /home/ubuntu/.config/dconf
  84K      /home/ubuntu/.config/pulse
  4.0K     /home/ubuntu/.config/update-notifier
  424K     /home/ubuntu/. config/mozc
  8.0K     /home/ubuntu/.config/evolution/sources
  12K      /home/ubuntu/.config/evolution
  580K     /home/ubuntu/.config
//}


==== -L 


  

全てのシンボリックリンクをたどらない




===== 実行例　



//list[][][fontsize=xx-small]{
  du -L /home/ubuntu/.config
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4       /home/ubuntu/.config/nautilus
  8       /home/ubuntu/.config/dconf
  84      /home/ubuntu/.config/pulse
  4       /home/ubuntu/.config/update-notifier
  424     /home/ubuntu/. config/mozc
  8       /home/ubuntu/.config/evolution/sources
  12      /home/ubuntu/.config/evolution
  580     /home/ubuntu/.config
//}


==== -l 


  

ハードリンクされた場合その個数分サイズを数える




===== 実行例　



//list[][][fontsize=xx-small]{
  du -l /home/ubuntu/.config
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4       /home/ubuntu/.config/nautilus
  8       /home/ubuntu/.config/dconf
  84      /home/ubuntu/.config/pulse
  4       /home/ubuntu/.config/update-notifier
  424     /home/ubuntu/. config/mozc
  8       /home/ubuntu/.config/evolution/sources
  12      /home/ubuntu/.config/evolution
  580     /home/ubuntu/.config
//}


==== -m 


  

ブロックサイズを1M単位とした時と同じ




===== 実行例　



//list[][][fontsize=xx-small]{
  du -m /home/ubuntu/.config
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1       /home/ubuntu/.config/nautilus
  1       /home/ubuntu/.config/dconf
  1       /home/ubuntu/.config/pulse
  1       /home/ubuntu/.config/update-notifier
  1       /home/ubuntu/. config/mozc
  1       /home/ubuntu/.config/evolution/sources
  1       /home/ubuntu/.config/evolution
  1       /home/ubuntu/.config
//}


==== -P 


  

シンボリックリンクをたどらない




===== 実行例　



//list[][][fontsize=xx-small]{
  du -P /home/ubuntu/.config
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4       /home/ubuntu/.config/nautilus
  8       /home/ubuntu/.config/dconf
  84      /home/ubuntu/.config/pulse
  4       /home/ubuntu/.config/update-notifier
  424     /home/ubuntu/.config/mozc
  8       /home/ubuntu/.config/evolution/sources
  12      /home/ubuntu/.config/evolution
  580     /home/ubuntu/.config
//}


==== -S 


  

子ディレクトリのサイズを含めない




===== 実行例　



//list[][][fontsize=xx-small]{
  du -S /home/ubuntu/.config
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4       /home/ubuntu/.config/nautilus
  8       /home/ubuntu/.config/dconf
  84      /home/ubuntu/.config/pulse
  4       /home/ubuntu/.config/update-notifier
  424     /home/ubuntu/. config/mozc
  8       /home/ubuntu/.config/evolution/sources
  4       /home/ubuntu/.config/evolution
  16      /home/ubuntu/.config
//}


==== -s 


  

各引数の合計容量のみを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  du -s /home/ubuntu/.config
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  580   /home/ubuntu/.config
//}


==== -t 


  

SIZEを指定して、SIZEが正の場合はSIZEより小さいエントリを無視する

SIZEが負の場合はSIZEより大きなエントリを無視する




===== 実行例　



//list[][][fontsize=xx-small]{
  du -t 10M
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  10676  . /snap/firefox/common/.mozilla/firefox/3q93a0v8.default/storage/permanent
  10820  . /snap/firefox/common/.mozilla/firefox/3q93a0v8.default/storage
  28100  ./snap/firefox/common/.mozilla/firefox/3q93a0v8.default
  28124  . /snap/firefox/common/.mozilla/firefox
  28132  . /snap/firefox/common/.mozilla
  80288  ./snap/firefox/common
  80372  ./snap/firefox
  80564  . /snap
  97576  .
//}


==== --time 


  

ディレクトリとその子ディレクトリに含まれるすべてのファイルでの最終更新時間を表示する

"atime","access","use","ctime","status"で更新時間の代わりにその時間を表示できる




===== 実行例　



//list[][][fontsize=xx-small]{
  du --time=use file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4    2023-12-10 13:37    file.txt
//}


==== --time-style 


  

時間をSTYLEの形式で表示する


STYLEには"full-iso","long-iso","iso","+FORMAT(dateと同様)"を指定できる




===== 実行例　



//list[][][fontsize=xx-small]{
  du --time-style=full-iso file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4     file.txt
//}


==== -X 


  

FILE内のいずれかのパターンに一致するファイルを除外する




===== 実行例　



//list[][][fontsize=xx-small]{
  du -X file.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4     ./. config/nautilus
  8     ./. config/dconf
  84    ./. config/pulse
  4     ./. config/update-notifier
  424   ./. config/mozc
  8     ./. config/evolution/sources
  12    ./.config/evolution
  580   ./.config
  97576 .
//}


==== -x 


  

異なるファイルシステム上のディレクトリはスキップする




===== 実行例　



//list[][][fontsize=xx-small]{
  du -x /home/ubuntu/.config
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  4       /home/ubuntu/.config/nautilus
  8       /home/ubuntu/.config/dconf
  84      /home/ubuntu/.config/pulse
  4       /home/ubuntu/.config/update-notifier
  424     /home/ubuntu/.config/mozc
  8       /home/ubuntu/.config/evolution/sources
  12      /home/ubuntu/.config/evolution
  580     /home/ubuntu/.config
//}

#@# 

== dumpe2fs

dump ext2/ext3/ext4 file system infomation

ext2/ext3/ext4ファイルシステムのスーパーブロックの情報とブロックグループディスクリプタの内容を出力する

スーパーブロックにはファイルシステムの管理用情報が格納されている

オプションなしの実行は不可


=== オプション一覧



==== -b




ファイルシステム内で不良としてマークされたブロックを表示する



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo dumpe2fs -b /dev/sda1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dumpe2fs 1.46.5 (30-Dec-2021)
  dumpe2fs: Bad magic number in super-block while trying to open /dev/sda1
  Couldn't find valid filesystem superblock.
//}


==== -o 


  

ファイルシステムを調査する際に、ブロックサイズのバイト単位でブロックを使用する


非常に損傷したファイルシステムの残留物を調査するファイルシステムの専門家以外は必要ないコマンド




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpe2fs -o superblock=10 /dev/sda2
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dumpe2fs 1.46.5 (30-Dec-2021)
  dumpe2fs: Bad magic number in super-block while trying to open /dev/sda2
  Couldn't find valid filesystem superblock.
  /dev/sda2 contains a vfat file system
//}


==== -f 


  

dumpe2fsに一部のファイルシステム機能フラグが理解できない可能性がある場合でもファイルシステムを表示するように強制する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpe2fs -f -o blocksize=5 /dev/sda1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dumpe2fs 1.46.5 (30-Dec-2021)
  dumpe2fs: Bad magic number in super-block while trying to open /dev/sda1
  Couldn't find valid filesystem superblock.
//}


==== -g 


  

グループディスクリプタ情報を、機械可読なコロン区切りの値形式で表示する

グループ番号;グループ内の最初のブロック番号;スーパーブロックの位置;グループディスクリプタが使用するブロックの範囲;ブロックビットマップの位置;iノードビットマップの位置;およびiノードテーブルが使用するブロック

の形である




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpe2fs -g -o blocksize=5 /dev/sda3
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dumpe2fs 1.46.5 (30-Dec-2021)
  dumpe2fs: Filesystem has unexpected block size while trying to open /dev/sda3
  Couldn't find valid filesystem superblock.
//}


==== -h 


  

ブロックグループディスクリプタの詳細情報を表示せずに、スーパーブロック情報のみを表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpe2fs -h -o blocksize=5 /dev/sda3
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行結果
//}


==== -i 


  

e2imageが作成したイメージファイルからファイルシステムデータを表示し、パス名としてデバイスを使用する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpe2fs -i -o superblock=3 /dev/sda1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dempe2fs 1.46.5(30-Dec-2021)
  Couldn't find valid filesystem superblock.
  dumpe2fs: Wrong magic number for Ext2 Image Header while trying to open /dev/sda1 
//}


==== -m 


  

もしファイルシステムでmmp機能が有効になっている場合、デバイスが他のノードで使用されているかどうかを確認する



-iオプションと併用する場合、MMPブロックの情報のみが表示される




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpe2fs -m -i -o superblock=3 /dev/sda1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dempe2fs 1.46.5(30-Dec-2021)
  Couldn't find valid filesystem superblock.
  dumpe2fs: Bad magic number in super-block while trying to open /dev/sda1
//}


==== -x 


  

ブロックの詳細なグループ情報を16進数の形式で表示する




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpe2fs -x -o superblock=3 /dev/sda1
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dumpe2fs 1.46.5 (30-Dec-2021)
  dumpe2fs: Bad magic number in super-block while trying to open /dev/sda1
  Couldn't find valid filesystem superblock.
//}

#@# 

== dumpkeys

キーボードドライバの変換ケーブルの現在の内容を指定された形式で標準出力に書き込む。

オプションにより、出力形式の制御やカーネルやプログラムから他の情報を取得することも可能

カーネルから情報を取得しているので管理者権限が必要



===== 実行例 



//list[][][fontsize=xx-small]{
  sudo dumpkeys
//}





===== 実行結果(一部)　



//list[][][fontsize=xx-small]{
  keymaps 0-127
  keycode　1 = Escape
         alt    keycode 1 = Meta_Escape
         shift  alt    keycode  1 = Meta_Escape
         altgr  alt    keycode  1 = Meta_Escape
         shift  altgr  alt keycode  1 = Meta_Escape
         control alt    keycode  1 = Meta_Escape
         shift  control alt  keycode  1 = Meta_Escape
         altgr  control alt  keycode  1 = Meta_Escape
         shift  altgr   control alt  keycode  1 = Meta_Escape
//}



=== オプション一覧




==== -i もしくは --short-info




カーネルのキーボード・ドライバの特徴を表示する。


表示される項目



Keycode range supported by the kernel(カーネルがサポートするキーコードの範囲):キーコードの後にどのような値を使うことができるか指定する。

詳細はkeymaps(5)を参照


Number of actions bindable to a key(キーにバインドできるアクションの数):ひとつのキーがさまざまな修飾キーを使っていくつの異なるアクションを出力できるかを示す。例えばこの値が16であれば、修飾キーと組み合わせて1つのキーに最大16種類のアクションを定義することができる。値が16の場合、カーネルはほぼ4つの修飾キーを知っており、キーと異なる組み合わせで押すことで、割り当てられたすべてのアクションにアクセスできる。


Ranges of action codes supported by kernel(カーネルがサポートするアクションコードの範囲):16進数表記のアクションコード範囲のリストが含まれている。これらはキー定義の右側、行のvvで使用できる値



キーコード xx = VV VV VV VV

(キー定義行のフォーマットについての詳細は keymaps(5) を参照)。



dumpkeys(1) と loadkeys(1) はシンボリック表記をサポートしており、カーネルごとにアクションコードが異なる可能性がある一方で、シンボリック名は通常同じままであるため、数値表記よりもシンボリック表記を推奨している。アクションコードの範囲のリストは、カーネルが loadkeys(1) が知っているすべてのシンボルを実際にサポートしているかどうか、あるいは、loadkeys(1) プログラムではシンボル名を持たない、カーネルによってサポートされているいくつかのアクションがあるかどうかを決定するために使用することができる。これを見るには、この範囲リストとアクションシンボルリストを比較する。


Number of function keys supported by kernel(カーネルがサポートするファンクションキーの数):文字列の出力に使用できるアクションコードの数を示す。これらのアクションコードは伝統的にキーボードの様々なファンクションキーや編集キーにバインドされており、標準的なエスケープシーケンスを送信するように定義されている。しかし、一般的なコマンドラインや電子メールアドレスなど、好きなものを送信するようにこれらを再定義することができる。特に、この項目の数がキーボードのファンクションキーや編集キーの数より多い場合は、例えばAltGrと文字の組み合わせにバインドして、便利な文字列を送信できる「予備の」アクションコードがある可能性がある。

詳細は loadkeys(1) を参照


Function String(ファンクションの文字列):ファンクションキーの定義は次のコマンドで確認できる


dumpkeys --funcs-only





===== 実行例 



//list[][][fontsize=xx-small]{
  sudo dumpkeys -i
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  keycode range supported by kernel:        1 - 255
  max number of actions bindable to a key:      256
  number of keymaps in actual use:      128
  of which 121 dynamically allocated ranges of action codes supported by kernel:
        0x0000 - 0x00ff
        0x0100 - 0x01ff
        0x0200 - 0x0213
        0x0300 - 0x0313
        0x0400 - 0x041a
        0x0500 - 0x05ff
        0x0600 - 0x0603
        0x0700 - 0x0708
        0x0800 - 0x08ff
        0x0900 - 0x0919
        0x0a00 - 0x0a08
        0x0b00 - 0x0bff
        0x0c00 - 0x0c08
        0x0doo - 0x0dff
        0x0e00 - 0x0e0a
  number of function keys supported by kernel: 256
  max nr of compose definitions: 256
  nr of compose definitions in actual use: 68
//}


==== -l もしくは -s もしくは --long-info 


  

長い情報リストを表示するようdumpkeysに指示する。

出力は -- short-info の場合と同じで、 loadkeys(1) と dumpkeys(1) がサポ-トするアクションシンボルのリストと、 シンボルの数値が追加される。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpkeys -l
//}





===== 実行結果(一部)　



//list[][][fontsize=xx-small]{
  keycode range supported by kernel:        1 - 255
  max number of actions bindable to a key:      256
  number of keymaps in actual use:      128
  of which 121 dynamically allocated ranges of action codes supported by kernel:
        0x0000 - 0x00ff
        0x0100 - 0x01ff
        0x0200 - 0x0213
        0x0300 - 0x0313
        0x0400 - 0x041a
        0x0500 - 0x05ff
        0x0600 - 0x0603
        0x0700 - 0x0708
        0x0800 - 0x08ff
        0x0900 - 0x0919
        0x0a00 - 0x0a08
        0x0b00 - 0x0bff
        0x0c00 - 0x0c08
        0x0doo - 0x0dff
        0x0e00 - 0x0e0a
  number of function keys supported by kernel: 256
  max nr of compose definitions: 256
  nr of compose definitions in actual use: 68
  Symbols recognized by dumpkeys:
  (numeric value, symbol)
//}


==== -n もしくは --numeric 


  

dumpkeysはアクションコードの値をシンボル表記に変換するのをバイパスし、代わりに16進数で表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpkeys -n
//}





===== 実行結果(一部)　



//list[][][fontsize=xx-small]{
  keymaps 0-127
  keycode　1 = 0x001b
         alt    keycode 1 = 0x081b
         shift  alt    keycode  1 = 0x081b
         altgr  alt    keycode  1 = 0x081b
         shift  altgr  alt keycode  1 = 0x081b
         control alt    keycode  1 = 0x081b
         shift  control alt  keycode  1 = 0x081b
         altgr  control alt  keycode  1 = 0x081b
         shift  altgr   control alt  keycode  1 = 0x081b
//}


==== -f もしくは --full-table 


  
 dumpkeys はすべてのショートハンドによるヒューリスティック (keymaps(5) を参照) をスキップし、キーバインドを正規の形式で出力する。
 最初に、現在定義されている修飾子の組み合わせを記述した keymaps 行が出力される。
 次に、各キーに対して、それぞれの修飾子の組み合わせの列を持つ行が出力される。
 例えば、現在使用されているキーマップが7つの修飾子を使用している場合、すべての行は7つのアクションコードの列を持つことになる。
 このフォーマットは、例えばdumpkeysの出力を後処理するプログラムで有用




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpkeys -f
//}





===== 実行結果(一部)　



//list[][][fontsize=xx-small]{
  keymaps 0-127
  keycode　1 = Escape       Escape      Escape      Escape      Escape      Escape      Escape      Escape      Meta_Escape      Meta_Escape      Meta_Escape      Meta_Escape      Meta_Escape      Meta_Escape      Meta_Escape      Meta_Escape      Escape      Escape      Escape      Escape      Escape      Escape      Escape      Escape      Meta_Escape
//}


==== -S もしくは --shape 


  

コンソールのキーボードレイアウトに関連するキーボードとシンボルの対応が表示される。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpkeys -S=8
//}





===== 実行結果(一部)　



//list[][][fontsize=xx-small]{
  keymaps 0-127
  keycode　1 = Escape
         alt    keycode 1 = Meta_Escape
         shift  alt    keycode  1 = Meta_Escape
         altgr  alt    keycode  1 = Meta_Escape
         shift  altgr  alt keycode  1 = Meta_Escape
         control alt    keycode  1 = Meta_Escape
         shift  control alt  keycode  1 = Meta_Escape
         altgr  control alt  keycode  1 = Meta_Escape
         shift  altgr   control alt  keycode  1 = Meta_Escape
//}


==== -t もしくは --funcs-only 


  

dumpkeysはファンクションキーの文字列定義のみを表示する。


通常dumpkeysはキーバインディングと文字列定義の両方を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpkeys -t
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  表示なし
//}


==== -k もしくは --keys-only 


  

dumpkeysはキーバインドだけを表示する。


通常dumpkeysはキーバインディングと文字列定義の両方を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  実行例
//}





===== 実行結果(一部)　



//list[][][fontsize=xx-small]{
  keymaps 0-127
  keycode　1 = Escape
         alt    keycode 1 = Meta_Escape
         shift  alt    keycode  1 = Meta_Escape
         altgr  alt    keycode  1 = Meta_Escape
         shift  altgr  alt keycode  1 = Meta_Escape
         control alt    keycode  1 = Meta_Escape
         shift  control alt  keycode  1 = Meta_Escape
         altgr  control alt  keycode  1 = Meta_Escape
         shift  altgr   control alt  keycode  1 = Meta_Escape
//}


==== -d もしくは --compose-only 


  

dumpkeysはcomposeキーの組み合わせだけを表示する。


カーネルがコンポーズ・キーをサポートしている場合にのみ利用できる。


composeキーとは特殊なキーで、複数キーを連続して押すことで特殊な文字が入力できる方法。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpkeys -d
//}





===== 実行結果(一部)　



//list[][][fontsize=xx-small]{
  compose '`' 'A' to Agrave
  compose '`' 'a' to agrave
  compose '\' 'A' to Aacute
  compose '\' 'a' to aacute
  compose '^' 'A' to Acircumflex
  compose '^' 'a' to acircumflex
  compose '~' 'A' to Atilde
  compose '~' 'a' to atilde
  compose '"' 'A' to Adiaeresis
  compose '"' 'a' to adiaeresis
//}


==== -c もしくは --charset=charset 


  

指定された文字セットに従って文字コード値を解釈するようにdumpkeysに指示する。



文字コード値からシンボル名への変換にのみ影響する。



現在有効な文字コードの値は iso-8859-Xである。



charsetが指定されていない場合、iso-8859-1がデフォルトとして使用される。



このオプションは出力行`charset "iso-8859-x"'を生成し、loadkeysにキーマップの解釈方法を伝える。



(例えば、"division "はiso-8859-1ではoxf7だが、iso-8859-8ではoxba)。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpkeys -c iso-10646-18
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  charset "iso-10646-18"
  keymaps 0-127
  keycode　1 = Escape
         alt    keycode 1 = Meta_Escape
         shift  alt    keycode  1 = Meta_Escape
         altgr  alt    keycode  1 = Meta_Escape
         shift  altgr  alt keycode  1 = Meta_Escape
         control alt    keycode  1 = Meta_Escape
         shift  control alt  keycode  1 = Meta_Escape
         altgr  control alt  keycode  1 = Meta_Escape
         shift  altgr   control alt  keycode  1 = Meta_Escape
//}


==== -v もしくは --verbose 


  

dumpkeysがサポートしている総裁情報が表示される。


使用用途はキーボードの設定やキーマッピングに関する追加の詳細情報の確認である。




===== 実行例　



//list[][][fontsize=xx-small]{
  sudo dumpkeys -v
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  keymaps 0-127
  keycode　1 = Escape
         alt    keycode 1 = Meta_Escape
         shift  alt    keycode  1 = Meta_Escape
         altgr  alt    keycode  1 = Meta_Escape
         shift  altgr  alt keycode  1 = Meta_Escape
         control alt    keycode  1 = Meta_Escape
         shift  control alt  keycode  1 = Meta_Escape
         altgr  control alt  keycode  1 = Meta_Escape
         shift  altgr   control alt  keycode  1 = Meta_Escape
//}

