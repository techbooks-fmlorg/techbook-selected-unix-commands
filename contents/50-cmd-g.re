= 頭文字が g のコマンド

#@# 

== grub-mkrelpath

指定したパスを、システムが使用するルートディレクトリとする。 grub-mkconfigが使用する。

===== 実行結果は入力したパスがそのまま表示される。

grub-mkrelpath → make a system path relative to its root



===== 実行例 



//list[][][fontsize=xx-small]{
  grub-mkrelpath PATH
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  PATH
//}

#@# 

== gs

gs → ghostscript  
PostScriptおよびPDFファイルを表示および印刷するためのオープンソースのプログラム



===== 実行例 



//list[][][fontsize=xx-small]{
  gs -q -sPAPERSIZE=a4 -dBATCH -dNOPAUSE -sDEVICE=pdfwrite -sOutputFile=test.pdf
//}





===== 実行結果　

　

//list[][][fontsize=xx-small]{
  なし
//}


単一のページからなる無地のPDFファイルtest.pdfが作成される。


------



===== 実行例 



//list[][][fontsize=xx-small]{
  gs -sDEVICE=pngalpha -o test.png -r300 -dNOPAUSE -q test.pdf -c quit
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}


test.pdfをDPI300でtest.pngに変換する。


=== オプション一覧






==== -sDEVICE=\<device>




出力デバイスを指定する。


以下はdeviceに指定できる項目である。


- PDFデバイス:  

  - pdfwrite: PDFファイルを生成する。  

  - pdfmark: PDFマークファイルを生成する。  

  - pdfdraw: PDF描画オブジェクトを生成する。



- 画像デバイス:  

  - pngalpha: PNG形式で透明な背景を持つ画像を生成する。  

  - jpeg: JPEG形式の画像を生成する。  

  - tiffg4: TIFF形式の画像を生成する。


- プリンターデバイス:  

  - ljet4: HP LaserJet 4プリンターのエミュレーションを行う。  

  - cups: CUPS (Common UNIX Printing System) 用のデバイス。


- 表示デバイス:  

  - x11: X Window System上に画像を表示する。  

  - display: ディスプレイに表示する。


- SVGデバイス:  

  - svg: SVG (Scalable Vector Graphics) ファイルを生成する。


- PostScriptデバイス:  

  - ps2write: Level2のPostScriptファイルを生成する。  

  - psmono: モノクロのPostScriptファイルを生成する。


==== -sOutputFile=\<file> 


  

出力ファイルの名前を指定する。


==== -r\<res> 


  

解像度を指定する。



===== 実行例　



//list[][][fontsize=xx-small]{
  -r300
//}


300 DPIに設定


==== \<file> 


  

入力ファイルの名前を指定する。


==== -o \<file>



出力ファイルの名前をしていする。


==== -dBATCH 


  

PostScript コマンドを読み取る対話型ループに入るのではなく、コマンド ラインで指定されたすべてのファイルを処理した後に Ghostscript を終了するようになる。コマンドラインの最後に -c quit を入力するのと同じである。


==== -dNOPAUSE 


  

プロンプトを無効にし、各ページの終わりで一時停止します。通常ファイルに出力を生成する場合は-dBATCHと共に使用する必要がある。


==== -q もしくは -dQUIET 


  

標準出力上のルーチン情報コメントを抑制する。


==== -dFirstPage=\<n> 


  

変換する最初のページを指定する。


==== -dLastPage=\<n> 


  

変換する最後のページを指定する。


==== -sPAPERSIZE=\<size> 


  

用紙サイズを指定する。デフォルトはa4。


以下はsizeに指定できる項目である。


- a0~a6、b0~b6、c0~c6  

- letter、legal、ledger、tabloid、executive、comm10


==== -c \<command> 


  

PostScriptコマンドを実行する。



===== 実行例　



//list[][][fontsize=xx-small]{
  -c "showpage"
//}



==== -dPDFSETTINGS=\<value> 


  

PDF変換の品質を調整する。


以下がvalueに指定できる項目である。


- /screen:  

画面表示用の低品質設定。低い解像度で生成される。ファイルサイズは小さくなり、画質も低下する。


- /ebook:  

電子書籍用の中程度の品質設定。モノクロ画像は高品質、カラー画像は中程度の品質で生成される。


- /printer:  

プリンター用の高品質設定。高解像度で生成される。ファイルサイズは大きくなるが、印刷時に高品質な結果が得られる。


- /prepress:

印刷用の最高品質設定。非常に高い解像度で生成され、印刷物としての品質が求められる場合に適している。


- /default  

デフォルト設定。通常、中程度の品質とファイルサイズになる。


==== g\<width>x\<height> 



生成されるページの幅を指定する。入力する値はポイント（1/72インチ）単位で指定する。

#@# 

== gsbj

Ghostscriptを使用してBubbleJetプリンター向けにテキストをフォーマットおよび印刷する。  
ヘッダーやフッターの文字列内の% # はpage #で置き換えられる。
デフォルトのデバイス（-sDEVICE=）と解像度（-r）は次のとおりである。

gsbj  bj10e  180




===== 実行例 



//list[][][fontsize=xx-small]{
  gsbj test.pdf
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}


test.pdfを印刷する。


=== オプション一覧






==== -12BclqRr もしくは -b\<header> もしくは -f\<font> もしくは -F\<hfont> もしくは -L\<lines> もしくは -p\<outfile>




基本のフォーマットを設定する。


==== -T\<n> 


  

tabの幅を指定する。



==== --add-to-space \<units>




各スペースの幅に指定された1/72インチ単位の数を追加する（負の値も可能）。


==== --add-to-width \<units> 


  

各文字の幅に指定された1/72インチ単位の数を追加する（負の値も可能）。



==== --columns \<n>




<n>列で印刷する。


==== --detect 


  

ファイルが%!で始まる場合、PostScriptファイルとして扱う。


==== --first-page \<n>




ページ<n>から印刷を開始する。


==== --kern \<file.afm> 


  

指定された.AFMファイルの情報を使用してカーニングを行う。


==== --last-page \<n>




ページ<n>で印刷を停止する。


==== --(heading|footing)-(left|center|right) \<string> 


  

ヘッダー/フッターのフィールドを設定する。


==== --margin-(top|bottom|left|right) <inches> 


  

余白を設定する。


==== --no-eject-(file|formfeed) 


  

end-of-file（EOF）が検出された場合、新しい列は始まるが、新しいページは始まらなくなる。


==== --spacing <n> 


  

行間の幅を2倍（n=2）,3倍（n=3）などで指定する。    #@# 

== gsdj

Ghostscriptを使用してDeskJetプリンター向けにテキストをフォーマットおよび印刷する。  
ヘッダーやフッターの文字列内の% # はpage #で置き換えられる。
デフォルトのデバイス（-sDEVICE=）と解像度（-r）は次のとおりである。

gsdj  deskjet  300





===== 実行例 



//list[][][fontsize=xx-small]{
  gsdj test.pdf
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}


test.pdfを印刷する。


=== オプション一覧






==== -12BclqRr もしくは -b\<header> もしくは -f\<font> もしくは -F\<hfont> もしくは -L\<lines> もしくは -p\<outfile>




基本のフォーマットを設定する。


==== -T\<n> 


  

tabの幅を指定する。



==== --add-to-space \<units>




各スペースの幅に指定された1/72インチ単位の数を追加する（負の値も可能）。


==== --add-to-width \<units> 


  

各文字の幅に指定された1/72インチ単位の数を追加する（負の値も可能）。



==== --columns \<n>




<n>列で印刷する。


==== --detect 


  

ファイルが%!で始まる場合、PostScriptファイルとして扱う。


==== --first-page \<n>




ページ<n>から印刷を開始する。


==== --kern \<file.afm> 


  

指定された.AFMファイルの情報を使用してカーニングを行う。


==== --last-page \<n>




ページ<n>で印刷を停止する。


==== --(heading|footing)-(left|center|right) \<string> 


  

ヘッダー/フッターのフィールドを設定する。


==== --margin-(top|bottom|left|right) <inches> 


  

余白を設定する。


==== --no-eject-(file|formfeed) 


  

end-of-file（EOF）が検出された場合、新しい列は始まるが、新しいページは始まらなくなる。


==== --spacing <n> 


  

行間の幅を2倍（n=2）,3倍（n=3）などで指定する。    #@# 

== gsdj500

Ghostscriptを使用してDeskJet 500 BubbleJet向けにテキストをフォーマットおよび印刷する。  
ヘッダーやフッターの文字列内の% # はpage #で置き換えられる。
デフォルトのデバイス（-sDEVICE=）と解像度（-r）は次のとおりである。

gsdj500  djet500  300





===== 実行例 



//list[][][fontsize=xx-small]{
  gsdj500 test.pdf
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}


test.pdfを印刷する。


=== オプション一覧






==== -12BclqRr もしくは -b\<header> もしくは -f\<font> もしくは -F\<hfont> もしくは -L\<lines> もしくは -p\<outfile>




基本のフォーマットを設定する。


==== -T\<n> 


  

tabの幅を指定する。



==== --add-to-space \<units>




各スペースの幅に指定された1/72インチ単位の数を追加する（負の値も可能）。


==== --add-to-width \<units> 


  

各文字の幅に指定された1/72インチ単位の数を追加する（負の値も可能）。



==== --columns \<n>




<n>列で印刷する。


==== --detect 


  

ファイルが%!で始まる場合、PostScriptファイルとして扱う。


==== --first-page \<n>




ページ<n>から印刷を開始する。


==== --kern \<file.afm> 


  

指定された.AFMファイルの情報を使用してカーニングを行う。


==== --last-page \<n>




ページ<n>で印刷を停止する。


==== --(heading|footing)-(left|center|right) \<string> 


  

ヘッダー/フッターのフィールドを設定する。


==== --margin-(top|bottom|left|right) <inches> 


  

余白を設定する。


==== --no-eject-(file|formfeed) 


  

end-of-file（EOF）が検出された場合、新しい列は始まるが、新しいページは始まらなくなる。


==== --spacing <n> 


  

行間の幅を2倍（n=2）,3倍（n=3）などで指定する。    #@# 

== gslj

Ghostscriptを使用してLaserJetプリンター向けにテキストをフォーマットおよび印刷する。  
ヘッダーやフッターの文字列内の% # はpage #で置き換えられる。
デフォルトのデバイス（-sDEVICE=）と解像度（-r）は次のとおりである。

gslj  laserjet  300





===== 実行例 



//list[][][fontsize=xx-small]{
  gslj test.pdf
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}


test.pdfを印刷する。


=== オプション一覧






==== -12BclqRr もしくは -b\<header> もしくは -f\<font> もしくは -F\<hfont> もしくは -L\<lines> もしくは -p\<outfile>




基本のフォーマットを設定する。


==== -T\<n> 


  

tabの幅を指定する。



==== --add-to-space \<units>




各スペースの幅に指定された1/72インチ単位の数を追加する（負の値も可能）。


==== --add-to-width \<units> 


  

各文字の幅に指定された1/72インチ単位の数を追加する（負の値も可能）。



==== --columns \<n>




<n>列で印刷する。


==== --detect 


  

ファイルが%!で始まる場合、PostScriptファイルとして扱う。


==== --first-page \<n>




ページ<n>から印刷を開始する。


==== --kern \<file.afm> 


  

指定された.AFMファイルの情報を使用してカーニングを行う。


==== --last-page \<n>




ページ<n>で印刷を停止する。


==== --(heading|footing)-(left|center|right) \<string> 


  

ヘッダー/フッターのフィールドを設定する。


==== --margin-(top|bottom|left|right) <inches> 


  

余白を設定する。


==== --no-eject-(file|formfeed) 


  

end-of-file（EOF）が検出された場合、新しい列は始まるが、新しいページは始まらなくなる。


==== --spacing <n> 


  

行間の幅を2倍（n=2）,3倍（n=3）などで指定する。    #@# 

== gslp

Ghostscriptを使用してテキストをフォーマットおよび印刷する。  
ヘッダーやフッターの文字列内の% # はpage #で置き換えられる。
デフォルトのデバイス（-sDEVICE=）と解像度（-r）は次のとおりである。

gslp  epson  180





===== 実行例 



//list[][][fontsize=xx-small]{
  gslp test.pdf
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  なし
//}


test.pdfを印刷する。


=== オプション一覧






==== -12BclqRr もしくは -b\<header> もしくは -f\<font> もしくは -F\<hfont> もしくは -L\<lines> もしくは -p\<outfile>




基本のフォーマットを設定する。


==== -T\<n> 


  

tabの幅を指定する。



==== --add-to-space \<units>




各スペースの幅に指定された1/72インチ単位の数を追加する（負の値も可能）。


==== --add-to-width \<units> 


  

各文字の幅に指定された1/72インチ単位の数を追加する（負の値も可能）。



==== --columns \<n>




<n>列で印刷する。


==== --detect 


  

ファイルが%!で始まる場合、PostScriptファイルとして扱う。


==== --first-page \<n>




ページ<n>から印刷を開始する。


==== --kern \<file.afm> 


  

指定された.AFMファイルの情報を使用してカーニングを行う。


==== --last-page \<n>




ページ<n>で印刷を停止する。


==== --(heading|footing)-(left|center|right) \<string> 


  

ヘッダー/フッターのフィールドを設定する。


==== --margin-(top|bottom|left|right) <inches> 


  

余白を設定する。


==== --no-eject-(file|formfeed) 


  

end-of-file（EOF）が検出された場合、新しい列は始まるが、新しいページは始まらなくなる。


==== --spacing <n> 


  

行間の幅を2倍（n=2）,3倍（n=3）などで指定する。    #@# 

== gsnd

Ghostscript（PostScriptおよびPDFエンジン）を表示なしで実行する。
このコマンドは、gsを -NODISPLAY フラグ付きで呼び出している。


===== 実行例、オプション一覧はgsコマンド参照

#@# 

== gst-device-monitor-1.0

gst → GStreamer  
GStreamerは、マルチメディアデータの処理やストリーミングを行うためのフレームワークであり、様々なメディア関連のタスクに使用される。  
gst-device-monitor-1.0 は、GStreamer のデバイス監視機能を利用するためのコマンド。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-device-monitor-1.0
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Probing devices...

  Device found

      name  : Monitor of 内部オーディオ　アナログステレオ
      class : Audio/Source
      caps  : audio/x-raw, format={ (string)S16LE, (string)S16BE, (string)F32LE, (string)F32BE, (string)S32LE, (string)S32BE, (string)S24LE, (string)S24BE, (string)S24_32LE, (string)S124_32BE, (string)UB }, layout=interleaved, rate=[ 1, 384000 ], channels=[ 1, 32 ]

          audio/x-alaw, rate=[ 1, 384000 ], channels=[ 1, 32 ]
          audio/x-mulaw, rate=[ 1, 384000 ], channels=[ 1, 32 ]
      properties:
          device.description = "Monitor\ of\ \345\206\205\351\203\250\343\202\252\343\203\274\343\203\207\343\202\243\343\202\252\ \343\202\242\343\203\212\343\203\255\343\202\260\343\202\271\343\203\205\343\2-3\254\343\202\252"
          device/class = monitor
          alsa.card = 0
          alse.card_name = "Intel\ 82801AA-ICH"
  ~~~~以下省略~~~~
//}



=== オプション一覧






==== -f もしくは --follow




デバイス・リストを表示した後は終了せず、デバイスの追加と削除を待つ。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-device-monitor-1.0 -f
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  Probing devices...

  Monitoring devices, waiting for devices to be removed or new devices to be added

  ~~~~以下実行例と同様~~~~
//}


実行後はデバイスリストを現在のデバイスリストを表示後、待機する。



==== -i もしくは --include-hidden 


  

非表示のデバイスを含めて表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-device-monitor-1.0 -i
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}

#@# 

== gst-discoverer-1.0

gst → GStreamer  
GStreamerは、マルチメディアデータの処理やストリーミングを行うためのフレームワークであり、様々なメディア関連のタスクに使用される。  
指定したファイルやURIに関するメタデータやプロパティ、ストリームの構造などを取得する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-discoverer-1.0 video.mp4
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Analyzing file:///home/user/video/video.mp4
  Done discovering file:file:///home/user/video/video.mp4
  Missing plugins
   (gstreamer|1.0|gst-discoverer-1.0|H.264 (Main Profile) デコーダー|decoder-video/x=h264, level=(string)3.1, profile=(string)main)
   (gstreamer|1.0|gst-discoverer-1.0|MPEG-4 AAC デコーダー|decoder-audio/mpeg, mpegversion=(int)4, level=(string)2, base-profile=(string)lc, profile=(string)lc)
//}



=== オプション一覧






==== -v、--verbose




入手可能な情報を全て出力する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-discoverer-1.0 -v video.mp4
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}


==== -t もしくは --timeout=\<T> 


  

タイムアウトを秒単位で指定する。 (デフォルトは10 秒)

実行後指定した秒数でタイムアウトする。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-discoverer-1.0 -t 20 video.mp4
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}





==== -c もしくは --toc




可能な場合は目次 (章やチャプター) を出力する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-discoverer-1.0 -c video.mp4
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}


==== -a もしくは --async 


  

非同期コードパスを使用する。

プログラムが非同期的に動作するようになる。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-discoverer-1.0 -a video.mp4
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}

#@# 

== gst-inspect-1.0

gst → GStreamer  
GStreamerは、マルチメディアデータの処理やストリーミングを行うためのフレームワークであり、様々なメディア関連のタスクに使用される。  
GStreamerのプラグインに関する情報を取得するためのコマンド。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-inspect-1.0
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1394: dv1394src: Firewire (1394) DV video source
  1394: hdv1394src: Firewire (1394) HDV video source
  aasink: aasink: ASCII art video sink
  aasink: aatv: aaTV effect
  adder: adder: Adder
  alaw: alawdec: A Law audio decoder
  alaw: alawenc: A Law audio encoder
  alpha: alpha: Alpha filter
  alphacolor: alphacolor: Alphacolor filter
  ~~~~以下省略~~~~
//}



=== オプション一覧





==== \<PLUGIN|ELEMENT> 


  

指定したプラグインまたは要素の詳細を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-inspect-1.0 audiotestsrc
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Factory Details:
      Rank                     none (0)
      Long-name                Audio test source
      Klass                    Source/Audio
      Description              Creates audio test signals of given frequency and volume
      Author                   Stefan Kost <ensonic@users.sf.net>

  ~~~~以下省略~~~~
//}



==== -a もしくは --print-all




全てのプラグインと要素を全て出力する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-inspect-1.0 -a
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dv1394src: Factory Details:
  dv1394src:  Rank              none (0)
  dv1394src:  Long - name       Firewire (1394) DV video source
  dv1394srv:  Klass             Source/Video
  dv1394src:  Description       Source for DV video data from firewire port
  ~~~~以下省略~~~~
//}


==== -b もしくは --print-blacklist 


  

ブラックリストを表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-inspect-1.0 -b
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Blacklisted files:

  Total count: 0 blacklisted files
//}


==== --plugin




プラグインを表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-inspect-1.0 --plugin
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dv1394src: Factory Details:
  dv1394src:  Rank              none (0)
  dv1394src:  Long - name       Firewire (1394) DV video source
  dv1394srv:  Klass             Source/Video
  dv1394src:  Description       Source for DV video data from firewire port
  ~~~~以下省略~~~~
//}


==== --print-plugin-auto-install-info 


  

指定されたプラグインが提供する機能の機械が可読なリストを表示します。外部の自動プラグインインストールメカニズムと連携する際に役立つ。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-inspect-1.0 --print-plugin-auto-install-info
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  element-dv1394src
  urisource-dv
  element-hdv1394src
  urisource-hdv
  element-aasink
  element-aatv
  element-adder
  ~~~~以下省略~~~~
//}


==== -t もしくは --types




指定した文字列が含まれるプラグインや要素のみを表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-inspect-1.0　-t bin
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  camerabin:  camerabin: Camera Bin
  cluttergst3:  clutterautovideosink: Generic bin
  encoding:  encodebin: Encoder Bin
  encoding:  encodebin2: Encoder Bin
  multifile:  splitmuxsink: Split Muxing Bin
  multifile:  splitmuxsrc: Split File Demuxing Bin
  ~~~~以下省略~~~~
//}


==== -u もしくは --uri-handlers 


  

サポートされているURIスキームとそれを実装する要素を表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-inspect-1.0 -u
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  dv1394src (read, rank 0): dv
  hdv1394src (rad, rank 0): hdv
  appsink (write, rank 0): appsink
  appsrc (read, rank 0): appsrc
  cdparanoasrc (read, rank 128): cdda
  ~~~~以下省略~~~~
//}


==== --no-colors




結果を表示する際に単色で表示する。（デフォルトは要素ごとに色分け）



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-inspect-1.0 --no-colors
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  1394: dv1394src: Firewire (1394) DV video source
  1394: hdv1394src: Firewire (1394) HDV video source
  aasink: aasink: ASCII art video sink
  aasink: aatv: aaTV effect
  adder: adder: Adder
  alaw: alawdec: A Law audio decoder
  alaw: alawenc: A Law audio encoder
  alpha: alpha: Alpha filter
  alphacolor: alphacolor: Alphacolor filter
  ~~~~以下省略~~~~
//}



==== -C もしくは --color




表示される要素ごとに色をつけて表示する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-inspect-1.0 -C
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  1394: dv1394src: Firewire (1394) DV video source
  1394: hdv1394src: Firewire (1394) HDV video source
  aasink: aasink: ASCII art video sink
  aasink: aatv: aaTV effect
  adder: adder: Adder
  alaw: alawdec: A Law audio decoder
  alaw: alawenc: A Law audio encoder
  alpha: alpha: Alpha filter
  alphacolor: alphacolor: Alphacolor filter
  ~~~~以下省略~~~~
//}

#@# 

== gst-launch-1.0 

gst → GStreamer  
GStreamerは、マルチメディアデータの処理やストリーミングを行うためのフレームワークであり、様々なメディア関連のタスクに使用される。  
gst-launch-1.0は、コマンドラインからGStreamerパイプラインを簡単に構築および実行するためのコマンド。  
GStreamerでは Shell のパイプ "|" ではなく "!" を用いる。 



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-launch-1.0 audiotestsrc ! autoaudiosink
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  パイプラインを一時停止 (PAUSED) にしています...
  Pipeline is PREROLLING ...
  Pipeline is PREROLLED ...
  パイプラインを再生中 (PLAYING) にしています...
  New clock: GstPulseSinkClock
  Redistribute latency...
//}


テスト音源の440Hzが出力される。


=== オプション一覧






==== -t もしくは --tags




タグ (メタデータ) を出力する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-launch-1.0 -t audiotestsrc ! autoaudiosink
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  パイプラインを一時停止 (PAUSED) にしています...
  Pipeline is PREROLLING ...
  FOUND TAG     : found by element "autoaudiosink0-actual-sink-pilse".
            詳細: audiotest wave
  Pipeline is PREROLLED ...
  パイプラインを再生中 (PLAYING) にしています...
  New clock: GstPulseSinkClock
  Redistribute latency...
//}


==== -c もしくは --toc 


  

可能な場合は目次 (章やチャプター) を出力する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-launch-1.0 -c audiotestsrc ! autoaudiosink
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}


==== -v もしくは --verbose 


  

ステータス情報とプロパティ通知を出力する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-launch-1.0 -v audiotestsrc ! autoaudiosink
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  パイプラインを一時停止 (PAUSED) にしています...
  Pipeline is PREROLLING ...
  /GstPipeline:pipeline0/GstAudioTestSrc:audiotestsrc0.GstPad:src: caps = audio/x-raw, format=(string)S16LE, layout=(string)interleaved, rate=(int)44100, channels=(int)1
  /GstPipeline:pipeline0/GstAutoAudioSink:autoaudiosink0.GstGhostPad:sink.GstProxyPad:proxypad0: caps = audio/x-raw, format=(string)S16LE, layout=(string)interleaved, rate=(int)44100, channels=(int)1
  Redistribute latency...
  ~~~~以下省略~~~~
//}


==== -q もしくは --quiet 


  

出力データの詳細などは表示せず、再生時間のみを表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-launch-1.0 -q audiotestsrc ! autoaudiosink
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  0:00:00.0 / 99:99:99.
//}


==== -m もしくは --messages 


  

パイプラインのバスに提示される出力メッセージを表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-launch-1.0 -q audiotestsrc ! autoaudiosink
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  パイプラインを一時停止 (PAUSED) にしています...
  Pipeline is PREROLLING ...
  Got message #9 from element "autoaudiosink0-actual-sink-pulse" (state-changed): GstMessageStateChanged, old-state=(GstState)null, new-state=(GstState)ready, pending-state=(GstState)void-pending;
  Got message #10 from element "autoaudiosink0" (state-changed): GstMessageStateChanged, old-state=(GstState)null, new-state=(GstState)ready, pending-state=(GstState)void-pending;
  ~~~~以下省略~~~~
//}

#@# 

== gst-play-1.0 

gst → GStreamer  
GStreamerは、マルチメディアデータの処理やストリーミングを行うためのフレームワークであり、様々なメディア関連のタスクに使用される。　
gst-play-1.0 を使用すると、コマンドラインから簡単にメディアファイルを再生することができる。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-play-1.0 music.mp3
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Press 'k' to see a list of keyboard shortcuts.
  Now playing /home/user/music.mp3
  Redistribute latency...
  Redistribute latency...

  Interactive mode - keyboard controls:

    space    : pause/unpause
    q or ESC : quit 
    > or n   : play next
    < or b   : play previous
    →        : seek forward
    ←        : seek backward
    ↑        : volume up
    ↓        : volume down
    m        : toggle audio mute on/off
    +        : increase playback rate
    -        : decrease playback rate
    d        : change playback direction
    t        : enable/disable trick modes
    a        : change audio track
    v        : change video track
    s        : change subtitle track
    0        : seek to beginning
    k        : show keyboard shortcuts
//}



=== オプション一覧






==== -v もしくは --verbose




ステータス情報とプロパティ通知を出力する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-play-1.0 -v music.mp3
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Press 'k' to see a list of keyboard shortcuts.
  Now playing /home/user/music.mp3
  /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin0: ring-buffer-max-size = 0
  /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin0: buffer-size = -1
  /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin0: buffer-duration = -1
  /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin0: force-sw-decoders = false
  /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin0: use-buffering = false
  /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin0: download = false
  /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin0: uri = file:///home/user/music.mp3
  /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin0: connection-speed = 0
  ~~~~以下省略~~~~
//}



==== --audiosink=\<SOMESINK> 


==== 

autoaudiosinkの代わりに指定したSOMESINKをオーディオ出力として使用する。  

- 具体的なオーディオ出力の例

  - autoaudiosink: システムのデフォルトのオーディオ出力

  - alsasink: ALSA (Advanced Linux Sound Architecture) を使用したオーディオ出力

  - pulsesink: PulseAudio を使用したオーディオ出力

  - osssink: OSS (Open Sound System) を使用したオーディオ出力

  - openslessink: OpenSL ES を使用したオーディオ出力




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-play-1.0 --audiosink=alsasink music.mp3
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Press 'k' to see a list of keyboard shortcuts.
  Now playing /home/user/music.mp3
  Redistribute latency...
  Redistribute latency...
//}



==== --volume=\<VOLUME> 


  

初期再生音量を指定する。  

1.0がデフォルト。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-play-1.0 --volume=0.7 music.mp3
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Volume: 70%
  Press 'k' to see a list of keyboard shortcuts.
  Now playing /home/user/music.mp3
  Redistribute latency...
  Redistribute latency...
//}



==== --shuffle




プレイリストからランダムに並び替えて再生する。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-play-1.0 --shuffle music.mp3
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  最初の実行例と同様のため省略
//}


==== --no-interactive 


  

ターミナルでのキーボード操作による制御を無効にする。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gst-play-1.0 --no-interactive music.mp3
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  Now playing /home/user/music.mp3
  Redistribute latency...
  Redistribute latency...
//}



==== --gapless




メディアファイル間の無音部分などを無くして、連続して再生する。  

このオプションを指定することで、異なるメディアファイルを連続して再生する際に、中断や無音の時間を最小限に抑えることができる。




===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-play-1.0 --gapless music1.mp3 music2.mp3
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}


1つ目の再生が終了後2つ目の再生が始まる

#@# 

== gst-typefind-1.0

gst → GStreamer  
GStreamerは、マルチメディアデータの処理やストリーミングを行うためのフレームワークであり、様々なメディア関連のタスクに使用される。  
gst-typefind-1.0 を実行すると、ファイルのメディアタイプを表示することができる。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gst-typefind-1.0 music.mp3
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  music.mp3 - application/x-id3
//}


#@# 

== gunzip

ファイルの伸張(解凍)を行うためのUNIXおよびLinuxコマンド。  
gunzipはgzipコマンドと同じプログラムの一部であり、通常、gzipで圧縮されたファイルを解凍するために用いられる。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gzip -v text.txt.gz
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text.txt.gz:     68.6% -- replaced with text.txt
//}



=== オプション一覧





**-f, --force** 


ファイルが複数のリンクを持っている場合や、対応するファイルが既に存在する場合、または圧縮データが端末から読み取られたり端末に書き込まれたりしている場合であっても、強制的に圧縮または解凍を行う。  

-fが指定されず、同じファイルが存在する場合、既存のファイルを上書きするかどうかを確認するためにプロンプトを表示する。



===== 実行例　


//list[][][fontsize=xx-small]{
  $ gzip -v -f text.txt
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  -fを指定した場合
  text.txt:     68.6% -- replaced with text.txt.gz
//}


//list[][][fontsize=xx-small]{
  -fを指定せず、同じファイルが存在する場合
  gzip: text.txt.gz already exists; do you wish to overwrite (y or n)? y
  text.txt:     68.6% -- replaced with text.txt.gz
//}

**-k, --keep** 


入力したファイルを消去しない。  

デフォルトは消去。



===== 実行例　


//list[][][fontsize=xx-small]{
  $ gzip -v -k text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text.txt:   68.6% -- created text.txt.gz
//}


**-l, --list** 


圧縮ファイルに対して実行することで以下の内容を表示する。  

- compressed size: 圧縮ファイルのサイズ  

- uncompressed size: 非圧縮ファイルのサイズ  

- ratio:  圧縮率 (不明な場合は0.0%)  

- uncompressed_name: 非圧縮ファイルの名前



===== 実行例　


//list[][][fontsize=xx-small]{
  $ gzip -l text.txt.gz
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  compressed        uncompressed  ratio  uncompressed_name
         242                 685  68.6%  text.txt
//}


**-n, --no-name** 


圧縮時には、元のファイル名とタイムスタンプを保存しない。  

解凍時には、元のファイル名を復元しない（圧縮されたファイル名から gzip の接尾辞だけを削除する）。また元のタイムスタンプも復元しない（圧縮されたファイルからコピーしない）。このオプションは、解凍時にデフォルトで適用される。



===== 実行例　


//list[][][fontsize=xx-small]{
  $ gzip -v -n text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}


**-N, --name** 


圧縮時には、常に元のファイル名とタイムスタンプを保存する。  

解凍時には、元のファイル名とタイムスタンプを復元する（それらが存在する場合）。このオプションは、ファイル名の長さに制限があるか、またはファイルの転送後にタイムスタンプが失われた場合に有用。



===== 実行例　


//list[][][fontsize=xx-small]{
  $ gzip -v -N text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}


**-q, --quiet** 


実行内容や警告文などを表示しない



===== 実行例　


//list[][][fontsize=xx-small]{
  $ gzip -q text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  無し
//}

**-r, --recursive** 


指定したディレクトリや複数のファイルを再帰的に処理する。
//list[][][fontsize=xx-small]{
  .
  ├─text
  │   ├─text0.txt
  │   ├─text1.txt
//}


上記のディレクトリ構造に対して実行する



===== 実行例　


//list[][][fontsize=xx-small]{
  $ gzip -r -v text
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text/text0.txt:     3.3% -- replaced with text/text0.txt.gz
  text/text1.txt:     5.0% -- replaced with text/text1.txt.gz
//}

**-v, --verbose** 


処理内容を出力する。



===== 実行例　


//list[][][fontsize=xx-small]{
  $ gzip -v text.txt
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  text.txt:     68.6% -- replaced with text.txt.gz
//}

#@# 

== gzip

ファイルの圧縮および伸張を行うためのUNIXおよびLinuxコマンド。  
gzipは、データの圧縮と解凍に広く使用されており、通常は.gzという拡張子がついたファイルに適用される。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gzip -v text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text.txt:     68.6% -- replaced with text.txt.gz
//}



=== オプション一覧






==== -d もしくは --decompress




指定したファイルを解凍する。  

圧縮ファイルにのみ実行可能。



===== 実行例 



//list[][][fontsize=xx-small]{
  $ gzip -v -d text.txt.gz
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text.txt.gz:     68.6% -- replaced with text.txt
//}


==== -f もしくは --force 


  

ファイルが複数のリンクを持っている場合や、対応するファイルが既に存在する場合、または圧縮データが端末から読み取られたり端末に書き込まれたりしている場合であっても、強制的に圧縮または解凍を行う。  

-fが指定されず、同じファイルが存在する場合、既存のファイルを上書きするかどうかを確認するためにプロンプトを表示する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v -f text.txt
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  -fを指定した場合
  text.txt:     68.6% -- replaced with text.txt.gz
//}


//list[][][fontsize=xx-small]{
  -fを指定せず、同じファイルが存在する場合
  gzip: text.txt.gz already exists; do you wish to overwrite (y or n)? y
  text.txt:     68.6% -- replaced with text.txt.gz
//}



==== -k もしくは --keep 


  

入力したファイルを消去しない。  

デフォルトは消去。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v -k text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text.txt:   68.6% -- created text.txt.gz
//}



==== -l もしくは --list 


  

圧縮ファイルに対して実行することで以下の内容を表示する。  

- compressed size: 圧縮ファイルのサイズ  

- uncompressed size: 非圧縮ファイルのサイズ  

- ratio:  圧縮率 (不明な場合は0.0%)  

- uncompressed_name: 非圧縮ファイルの名前



===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -l text.txt.gz
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  compressed        uncompressed  ratio  uncompressed_name
         242                 685  68.6%  text.txt
//}



==== -n もしくは --no-name 


  

圧縮時には、元のファイル名とタイムスタンプを保存しない。  

解凍時には、元のファイル名を復元しない（圧縮されたファイル名から gzip の接尾辞だけを削除する）。また元のタイムスタンプも復元しない（圧縮されたファイルからコピーしない）。このオプションは、解凍時にデフォルトで適用される。



===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v -n text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}



==== -N もしくは --name 


  

圧縮時には、常に元のファイル名とタイムスタンプを保存する。  

解凍時には、元のファイル名とタイムスタンプを復元する（それらが存在する場合）。このオプションは、ファイル名の長さに制限があるか、またはファイルの転送後にタイムスタンプが失われた場合に有用。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v -N text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}



==== -q もしくは --quiet 


  

実行内容や警告文などを表示しない




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -q text.txt
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  無し
//}


==== -r もしくは --recursive 


  

指定したディレクトリや複数のファイルを再帰的に処理する。
//list[][][fontsize=xx-small]{
  .
  ├─text
  │   ├─text0.txt
  │   ├─text1.txt
//}


上記のディレクトリ構造に対して実行する




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -r -v text
//}





===== 実行結果　



//list[][][fontsize=xx-small]{
  text/text0.txt:     3.3% -- replaced with text/text0.txt.gz
  text/text1.txt:     5.0% -- replaced with text/text1.txt.gz
//}


==== -v もしくは --verbose 


  

処理内容を出力する。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v text.txt
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  text.txt:     68.6% -- replaced with text.txt.gz
//}


==== -\<#> もしくは --fast もしくは --best 


  

指定された数字 # を使用して圧縮の速度を調整する。  

1または--fastは最速の圧縮メソッド（圧縮が少ない）を示し、-9または--bestは最遅の圧縮メソッド（最大の圧縮）を示す。デフォルトの圧縮レベルは-6。




===== 実行例　



//list[][][fontsize=xx-small]{
  $ gzip -v -9 text.txt
//}





===== 実行結果　


//list[][][fontsize=xx-small]{
  実行例と同様のため省略
//}



