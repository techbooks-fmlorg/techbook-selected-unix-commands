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

