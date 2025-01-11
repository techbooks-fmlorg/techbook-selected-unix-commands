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

